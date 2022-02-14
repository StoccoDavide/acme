/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 2-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 2-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
(*                                                                     *)
(*    Davide Stocco                                                    *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: davide.stocco@unitn.it                                   *)
(*                                                                     *)
(*    Enrico Bertolazzi                                                *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: enrico.bertolazzi@unitn.it                               *)
(*                                                                     *)
(***********************************************************************)
*/

#include "acme.hh"
#include "acme_aabb.hh"
#include "acme_collinear.hh"
#include "acme_coplanar.hh"
#include "acme_disk.hh"
#include "acme_entity.hh"
#include "acme_intersection.hh"
#include "acme_line.hh"
#include "acme_none.hh"
#include "acme_orthogonal.hh"
#include "acme_parallel.hh"
#include "acme_plane.hh"
#include "acme_point.hh"
#include "acme_ray.hh"
#include "acme_segment.hh"
#include "acme_ball.hh"
#include "acme_triangle.hh"
#include "mex_utils.hh"

#define ASSERT(COND, MSG)               \
  if (!(COND))                          \
  {                                     \
    std::ostringstream ost;             \
    ost << "mex_line: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());    \
  }

#define MEX_ERROR_MESSAGE                                                     \
  "%=====================================================================%\n" \
  "% mex_line: Mex wrapper for ACME line object.                         %\n" \
  "%                                                                     %\n" \
  "% CONSTRUCTORS:                                                       %\n" \
  "%   obj = mex_line( 'new' );                                          %\n" \
  "%   obj = mex_line( 'new',                                            %\n" \
  "%                   [X; Y; Z], : Line origin                          %\n" \
  "%                   [X; Y; Z]  : Line direction                       %\n" \
  "%                 );                                                  %\n" \
  "%   obj = mex_line( 'new',                                            %\n" \
  "%                    OX,   : Line origin x value                      %\n" \
  "%                    OY,   : Line origin y value                      %\n" \
  "%                    OZ,   : Line origin z value                      %\n" \
  "%                    DX,   : Line directon x value                    %\n" \
  "%                    DY,   : Line directon y value                    %\n" \
  "%                    DZ    : Line directon z value                    %\n" \
  "%                  );                                                 %\n" \
  "%                                                                     %\n" \
  "% DESTRUCTOR:                                                         %\n" \
  "%   mex_line( 'delete', OBJ );                                        %\n" \
  "%                                                                     %\n" \
  "% USAGE:                                                              %\n" \
  "%   OUT = mex_line( 'getOrigin', OBJ );                               %\n" \
  "%   OUT = mex_line( 'getDirection', OBJ );                            %\n" \
  "%         mex_line( 'setOrigin', OBJ, OTHER_OBJ );                    %\n" \
  "%         mex_line( 'setDirection', OBJ, OTHER_OBJ );                 %\n" \
  "%         mex_line( 'translate', OBJ, VECTOR );                       %\n" \
  "%         mex_line( 'transform', OBJ, MATRIX );                       %\n" \
  "%         mex_line( 'copy', OBJ, OTHER_OBJ );                         %\n" \
  "%   OUT = mex_line( 'isInside', OBJ, OTHER_OBJ );                     %\n" \
  "%   OUT = mex_line( 'isDegenerated', OBJ );                           %\n" \
  "%   OUT = mex_line( 'isApprox', OBJ, OTHER_OBJ );                     %\n" \
  "%         mex_line( 'normalize', OBJ );                               %\n" \
  "%   OUT = mex_line( 'toVector', OBJ );                                %\n" \
  "%   OUT = mex_line( 'toUnitVector', OBJ );                            %\n" \
  "%         mex_line( 'reverse', OBJ );                                 %\n" \
  "%   OUT = mex_line( 'isParallel', OBJ, OTHER_OBJ );                   %\n" \
  "%   OUT = mex_line( 'isOrthogonal', OBJ, OTHER_OBJ );                 %\n" \
  "%   OUT = mex_line( 'isCollinear', OBJ, OTHER_OBJ );                  %\n" \
  "%   OUT = mex_line( 'isCoplanar', OBJ, OTHER_OBJ );                   %\n" \
  "%   OUT = mex_line( 'intersection', OBJ, OTHER_OBJ, TYPE );           %\n" \
  "%                                                                     %\n" \
  "%=====================================================================%\n" \
  "%                                                                     %\n" \
  "%    Davide Stocco                                                    %\n" \
  "%    Department of Industrial Engineering                             %\n" \
  "%    University of Trento                                             %\n" \
  "%    davide.stocco@unitn.it                                           %\n" \
  "%                                                                     %\n" \
  "%    Enrico Bertolazzi                                                %\n" \
  "%    Department of Industrial Engineering                             %\n" \
  "%    University of Trento                                             %\n" \
  "%    enrico.bertolazzi@unitn.it                                       %\n" \
  "%                                                                     %\n" \
  "%=====================================================================%\n"

using namespace std;

typedef double real_mex;

static void
DATA_NEW(
    mxArray *&mx_id,
    acme::line *ptr)
{
  mx_id = convertPtr2Mat<acme::line>(ptr);
}

static inline acme::line *
DATA_GET(
    mxArray const *&mx_id)
{
  return convertMat2Ptr<acme::line>(mx_id);
}

static void
DATA_DELETE(
    mxArray const *&mx_id)
{
  destroyObject<acme::line>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_new(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{

#define CMD "mex_line( 'new', [, args] ): "
  MEX_ASSERT(nrhs == 1 || nrhs == 3 || nrhs == 7, CMD "expected 1, 3 or 7 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  MEX_ASSERT(
      mxIsChar(arg_in_0),
      CMD << "first argument must be a string, found ``" << mxGetClassName(arg_in_0) << "''\n");

  real_mex ox = acme::QUIET_NAN;
  real_mex oy = acme::QUIET_NAN;
  real_mex oz = acme::QUIET_NAN;
  real_mex dx = acme::QUIET_NAN;
  real_mex dy = acme::QUIET_NAN;
  real_mex dz = acme::QUIET_NAN;

  if (nrhs == 3)
  {
    real_mex const *matrix1_ptr;
    mwSize rows1, cols1;
    matrix1_ptr = getMatrixPointer(arg_in_1, rows1, cols1, CMD "Error in first input matrix");
    MEX_ASSERT(rows1 == 3 || cols1 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows1 << ", cols = " << cols1 << '\n');
    ox = matrix1_ptr[0];
    oy = matrix1_ptr[1];
    oz = matrix1_ptr[2];
    real_mex const *matrix2_ptr;
    mwSize rows2, cols2;
    matrix2_ptr = getMatrixPointer(arg_in_2, rows2, cols2, CMD "Error in second input matrix");
    MEX_ASSERT(rows2 == 3 || cols2 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows2 << ", cols = " << cols2 << '\n');
    dx = matrix2_ptr[0];
    dy = matrix2_ptr[1];
    dz = matrix2_ptr[2];
  }
  else if (nrhs == 7)
  {
    ox = getScalarValue(arg_in_1, CMD "Error in reading origin x value");
    oy = getScalarValue(arg_in_2, CMD "Error in reading origin y value");
    oz = getScalarValue(arg_in_3, CMD "Error in reading origin z value");
    dx = getScalarValue(arg_in_4, CMD "Error in reading direction x value");
    dy = getScalarValue(arg_in_5, CMD "Error in reading direction y value");
    dz = getScalarValue(arg_in_6, CMD "Error in reading direction z value");
  }

  acme::line *ptr = new acme::line(ox, oy, oz, dx, dy, dz);
  DATA_NEW(arg_out_0, ptr);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_delete(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'delete', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  DATA_DELETE(arg_in_1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getOrigin(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'getOrigin', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->origin());
  arg_out_0 = convertPtr2Mat<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getDirection(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'getDirection', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  real_mex *output = createMatrixValue(arg_out_0, 3, 1);
  acme::vec3 outvec(self->direction());
  output[0] = outvec.x();
  output[1] = outvec.y();
  output[2] = outvec.z();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setOrigin(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'setOrigin', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  acme::point *obj = convertMat2Ptr<acme::point>(arg_in_2);
  self->origin() = *obj;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setDirection(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'setDirection', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  real_mex const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = getMatrixPointer(arg_in_2, rows, cols, CMD "Error in first input matrix");
  MEX_ASSERT(rows == 3 || cols == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows << ", cols = " << cols << '\n');
  real_mex x = matrix_ptr[0];
  real_mex y = matrix_ptr[1];
  real_mex z = matrix_ptr[2];
  self->direction() = acme::vec3(x, y, z);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_translate(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'translate', OBJ, VECTOR ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  real_mex const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = getMatrixPointer(arg_in_2, rows, cols, CMD "Error in first input matrix");
  MEX_ASSERT(rows == 3 || cols == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows << ", cols = " << cols << '\n');
  real_mex x = matrix_ptr[0];
  real_mex y = matrix_ptr[1];
  real_mex z = matrix_ptr[2];
  self->translate(acme::vec3(x, y, z));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_transform(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'transform', OBJ, MATRIX ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  real_mex const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = getMatrixPointer(arg_in_2, rows, cols, CMD "Error in reading affine transformation matrix");
  acme::affine matrix;
  MEX_ASSERT(rows == 4 || cols == 4, CMD "expected rows = 4 and cols = 4 found, rows = " << rows << ", cols = " << cols << '\n');
  matrix.matrix() << matrix_ptr[0], matrix_ptr[4], matrix_ptr[8], matrix_ptr[12],
      matrix_ptr[1], matrix_ptr[5], matrix_ptr[9], matrix_ptr[13],
      matrix_ptr[2], matrix_ptr[6], matrix_ptr[10], matrix_ptr[14],
      matrix_ptr[3], matrix_ptr[7], matrix_ptr[11], matrix_ptr[15];
  self->transform(matrix);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_copy(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'copy', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  acme::line *other = DATA_GET(arg_in_2);
  *self = *other;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isInside(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'isInside', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  acme::point *other = convertMat2Ptr<acme::point>(arg_in_2);
  setBoolValue(arg_out_0, self->isInside(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isDegenerated(int nlhs, mxArray *plhs[],
                 int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'isDegenerated', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  setBoolValue(arg_out_0, self->isDegenerated());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isApprox(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'isApprox', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  acme::line *other = DATA_GET(arg_in_2);
  setBoolValue(arg_out_0, self->isApprox(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_normalize(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'normalize', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  self->normalize();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_toVector(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'toVector', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  real_mex *output = createMatrixValue(arg_out_0, 3, 1);
  acme::vec3 outvec(self->toVector());
  output[0] = outvec.x();
  output[1] = outvec.y();
  output[2] = outvec.z();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_toUnitVector(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'toUnitVector', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  real_mex *output = createMatrixValue(arg_out_0, 3, 1);
  acme::vec3 outvec(self->toUnitVector());
  output[0] = outvec.x();
  output[1] = outvec.y();
  output[2] = outvec.z();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_reverse(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'reverse', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  self->reverse();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isParallel(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'isParallel', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);
  acme::entity *other = nullptr;

  if (type == "none")
    other = convertMat2Ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = convertMat2Ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = convertMat2Ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = convertMat2Ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = convertMat2Ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = convertMat2Ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = convertMat2Ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = convertMat2Ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = convertMat2Ptr<acme::ball>(arg_in_2);

  setBoolValue(arg_out_0, acme::isParallel(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isOrthogonal(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'isOrthogonal', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);
  acme::entity *other = nullptr;

  if (type == "none")
    other = convertMat2Ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = convertMat2Ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = convertMat2Ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = convertMat2Ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = convertMat2Ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = convertMat2Ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = convertMat2Ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = convertMat2Ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = convertMat2Ptr<acme::ball>(arg_in_2);

  setBoolValue(arg_out_0, acme::isOrthogonal(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isCollinear(int nlhs, mxArray *plhs[],
               int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'isCollinear', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);

  acme::entity *other = nullptr;

  if (type == "none")
    other = convertMat2Ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = convertMat2Ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = convertMat2Ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = convertMat2Ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = convertMat2Ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = convertMat2Ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = convertMat2Ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = convertMat2Ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = convertMat2Ptr<acme::ball>(arg_in_2);

  setBoolValue(arg_out_0, acme::isCollinear(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isCoplanar(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'isCoplanar', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);

  acme::entity *other = nullptr;

  if (type == "none")
    other = convertMat2Ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = convertMat2Ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = convertMat2Ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = convertMat2Ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = convertMat2Ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = convertMat2Ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = convertMat2Ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = convertMat2Ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = convertMat2Ptr<acme::ball>(arg_in_2);

  setBoolValue(arg_out_0, acme::isCoplanar(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_intersection(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_line( 'intersection', OBJ, OTHER_OBJ, TYPE ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 2, CMD "expected 2 output, nlhs = " << nlhs << '\n');

  acme::line *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);

  acme::entity *other = nullptr;

  if (type == "none")
    other = convertMat2Ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = convertMat2Ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = convertMat2Ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = convertMat2Ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = convertMat2Ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = convertMat2Ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = convertMat2Ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = convertMat2Ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = convertMat2Ptr<acme::ball>(arg_in_2);

  acme::entity *out = acme::intersection(self, other);
  string out_type = out->type();
  if (out_type == "none")
    arg_out_0 = convertPtr2Mat<acme::none>(dynamic_cast<acme::none *>(out));
  else if (out_type == "point")
    arg_out_0 = convertPtr2Mat<acme::point>(dynamic_cast<acme::point *>(out));
  else if (out_type == "line")
    arg_out_0 = convertPtr2Mat<acme::line>(dynamic_cast<acme::line *>(out));
  else if (out_type == "ray")
    arg_out_0 = convertPtr2Mat<acme::ray>(dynamic_cast<acme::ray *>(out));
  else if (out_type == "plane")
    arg_out_0 = convertPtr2Mat<acme::plane>(dynamic_cast<acme::plane *>(out));
  else if (out_type == "segment")
    arg_out_0 = convertPtr2Mat<acme::segment>(dynamic_cast<acme::segment *>(out));
  else if (out_type == "triangle")
    arg_out_0 = convertPtr2Mat<acme::triangle>(dynamic_cast<acme::triangle *>(out));
  else if (out_type == "disk")
    arg_out_0 = convertPtr2Mat<acme::disk>(dynamic_cast<acme::disk *>(out));
  else if (out_type == "ball")
    arg_out_0 = convertPtr2Mat<acme::ball>(dynamic_cast<acme::ball *>(out));

  arg_out_1 = mxCreateString(out_type.c_str());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef void (*DO_CMD)(int nlhs, mxArray *plhs[],
                       int nrhs, mxArray const *prhs[]);

static map<string, DO_CMD> cmd_to_fun = {
    {"new", do_new},
    {"delete", do_delete},
    {"getOrigin", do_getOrigin},
    {"getDirection", do_getDirection},
    {"setOrigin", do_setOrigin},
    {"setDirection", do_setDirection},
    {"copy", do_copy},
    {"translate", do_translate},
    {"transform", do_transform},
    {"isInside", do_isInside},
    {"isDegenerated", do_isDegenerated},
    {"isApprox", do_isApprox},
    {"normalize", do_normalize},
    {"toVector", do_toVector},
    {"toUnitVector", do_toUnitVector},
    {"reverse", do_reverse},
    {"isParallel", do_isParallel},
    {"isOrthogonal", do_isOrthogonal},
    {"isCollinear", do_isCollinear},
    {"isCoplanar", do_isCoplanar},
    {"intersection", do_intersection}};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

extern "C" void
mexFunction(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
  // First argument must be a string
  if (nrhs == 0)
  {
    mexErrMsgTxt(MEX_ERROR_MESSAGE);
    return;
  }

  try
  {
    MEX_ASSERT(mxIsChar(arg_in_0), "First argument must be a string");
    string cmd = mxArrayToString(arg_in_0);
    DO_CMD pfun = cmd_to_fun.at(cmd);
    pfun(nlhs, plhs, nrhs, prhs);
  }
  catch (exception const &e)
  {
    mexErrMsgTxt((string("mex_line Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("mex_line failed\n");
  }
}
