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

#define ASSERT(COND, MSG)                 \
  if (!(COND))                            \
  {                                       \
    std::ostringstream ost;               \
    ost << "mex_ball: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());      \
  }

#define MEX_ERROR_MESSAGE                                                     \
  "%=====================================================================%\n" \
  "% mex_ball: Mex wrapper for ACME ball object.                         %\n" \
  "%                                                                     %\n" \
  "% CONSTRUCTORS:                                                       %\n" \
  "%   obj = mex_ball( 'new' );                                          %\n" \
  "%   obj = mex_ball( 'new',                                            %\n" \
  "%                     RADIUS,   : Ball radius                         %\n" \
  "%                     [X; Y; Z] : Ball center                         %\n" \
  "%                   );                                                %\n" \
  "%   obj = mex_ball( 'new',                                            %\n"  \
  "%                    RADIUS, : Ball radius                            %\n" \
  "%                    CX,     : Ball center x value                    %\n" \
  "%                    CY,     : Ball center y value                    %\n" \
  "%                    CZ      : Ball center z value                    %\n" \
  "%                  );                                                 %\n" \
  "%                                                                     %\n" \
  "% DESTRUCTOR:                                                         %\n" \
  "%   mex_ball( 'delete', OBJ );                                        %\n" \
  "%                                                                     %\n" \
  "% USAGE:                                                              %\n" \
  "%   OUT = mex_ball( 'getRadius', OBJ );                               %\n" \
  "%   OUT = mex_ball( 'getCenter', OBJ );                               %\n" \
  "%         mex_ball( 'setRadius', OBJ, OTHER_OBJ );                    %\n" \
  "%         mex_ball( 'setCenter', OBJ, OTHER_OBJ );                    %\n" \
  "%         mex_ball( 'translate', OBJ, VECTOR );                       %\n" \
  "%         mex_ball( 'transform', OBJ, MATRIX );                       %\n" \
  "%         mex_ball( 'copy', OBJ, OTHER_OBJ );                         %\n" \
  "%   OUT = mex_ball( 'isInside', OBJ, OTHER_OBJ );                     %\n" \
  "%   OUT = mex_ball( 'isDegenerated', OBJ );                           %\n" \
  "%   OUT = mex_ball( 'isApprox', OBJ, OTHER_OBJ );                     %\n" \
  "%   OUT = mex_ball( 'clamp', OBJ );                                   %\n" \
  "%   OUT = mex_ball( 'area', OBJ );                                    %\n" \
  "%   OUT = mex_ball( 'volume', OBJ );                                  %\n" \
  "%   OUT = mex_ball( 'isParallel', OBJ, OTHER_OBJ );                   %\n" \
  "%   OUT = mex_ball( 'isOrthogonal', OBJ, OTHER_OBJ );                 %\n" \
  "%   OUT = mex_ball( 'isCollinear', OBJ, OTHER_OBJ );                  %\n" \
  "%   OUT = mex_ball( 'isCoplanar', OBJ, OTHER_OBJ );                   %\n" \
  "%   OUT = mex_ball( 'intersection', OBJ, OTHER_OBJ, TYPE );           %\n" \
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
    acme::ball *ptr)
{
  mx_id = convertPtr2Mat<acme::ball>(ptr);
}

static inline acme::ball *
DATA_GET(
    mxArray const *&mx_id)
{
  return convertMat2Ptr<acme::ball>(mx_id);
}

static void
DATA_DELETE(
    mxArray const *&mx_id)
{
  destroyObject<acme::ball>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_new(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'new', [, args] ): "
  MEX_ASSERT(nrhs == 1 || nrhs == 3 || nrhs == 5, CMD "expected 1, 3 or 5 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  MEX_ASSERT(
      mxIsChar(arg_in_0),
      CMD << "first argument must be a string, found ``" << mxGetClassName(arg_in_0) << "''\n");

  real_mex r = acme::QUIET_NAN;
  real_mex cx = acme::QUIET_NAN;
  real_mex cy = acme::QUIET_NAN;
  real_mex cz = acme::QUIET_NAN;

  if (nrhs == 3)
  {
    r = getScalarValue(arg_in_1, CMD "Error in reading radius value");
    real_mex const *matrix1_ptr;
    mwSize rows1, cols1;
    matrix1_ptr = getMatrixPointer(arg_in_2, rows1, cols1, CMD "Error in first input matrix");
    MEX_ASSERT(rows1 == 3 || cols1 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows1 << ", cols = " << cols1 << '\n');
    cx = matrix1_ptr[0];
    cy = matrix1_ptr[1];
    cz = matrix1_ptr[2];
  }
  else if (nrhs == 5)
  {
    r = getScalarValue(arg_in_1, CMD "Error in reading radius value");
    cx = getScalarValue(arg_in_2, CMD "Error in reading center x value");
    cy = getScalarValue(arg_in_3, CMD "Error in reading center y value");
    cz = getScalarValue(arg_in_4, CMD "Error in reading center z value");
  }

  acme::ball *ptr = new acme::ball(r, cx, cy, cz);
  DATA_NEW(arg_out_0, ptr);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_delete(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'delete', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  DATA_DELETE(arg_in_1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getRadius(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'getRadius', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->radius());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getCenter(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'getCenter', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->center());
  arg_out_0 = convertPtr2Mat<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setRadius(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'setRadius', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->radius());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setCenter(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'setCenter', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  acme::point *obj = convertMat2Ptr<acme::point>(arg_in_2);
  self->center() = *obj;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_translate(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'translate', OBJ, VECTOR ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
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
#define CMD "mex_ball( 'transform', OBJ, MATRIX ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
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
#define CMD "mex_ball( 'copy', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  acme::ball *other = DATA_GET(arg_in_2);
  *self = *other;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isInside(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'isInside', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  acme::point *other = convertMat2Ptr<acme::point>(arg_in_2);
  setBoolValue(arg_out_0, self->isInside(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isDegenerated(int nlhs, mxArray *plhs[],
                 int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'isDegenerated', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  setBoolValue(arg_out_0, self->isDegenerated());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isApprox(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'isApprox', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  acme::ball *other = DATA_GET(arg_in_2);
  setBoolValue(arg_out_0, self->isApprox(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_clamp(int nlhs, mxArray *plhs[],
         int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'clamp', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 2, CMD "expected 2 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);

  acme::vec3 min(acme::NAN_VEC3);
  acme::vec3 max(acme::NAN_VEC3);
  self->clamp(min, max);

  real_mex *output_min = createMatrixValue(arg_out_0, 3, 1);
  output_min[0] = min.x();
  output_min[1] = min.y();
  output_min[2] = min.z();

  real_mex *output_max = createMatrixValue(arg_out_1, 3, 1);
  output_max[0] = max.x();
  output_max[1] = max.y();
  output_max[2] = max.z();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_area(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'area', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->area());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_volume(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'volume', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->volume());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isParallel(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_ball( 'isParallel', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
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
#define CMD "mex_ball( 'isOrthogonal', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
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
#define CMD "mex_ball( 'isCollinear', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
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
#define CMD "mex_ball( 'isCoplanar', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
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
#define CMD "mex_ball( 'intersection', OBJ, OTHER_OBJ, TYPE ): "
  MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 2, CMD "expected 2 output, nlhs = " << nlhs << '\n');

  acme::ball *self = DATA_GET(arg_in_1);
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
    {"getRadius", do_getRadius},
    {"getCenter", do_getCenter},
    {"setRadius", do_setRadius},
    {"setCenter", do_setCenter},
    {"copy", do_copy},
    {"translate", do_translate},
    {"transform", do_transform},
    {"isInside", do_isInside},
    {"isDegenerated", do_isDegenerated},
    {"isApprox", do_isApprox},
    {"clamp", do_clamp},
    {"area", do_area},
    {"volume", do_volume},
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
    mexErrMsgTxt((string("mex_ball Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("mex_ball failed\n");
  }
}
