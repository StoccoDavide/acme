/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       *)
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
#include "acme_entity.hh"
#include "acme_segment.hh"
#include "acme_point.hh"
#include "mex_utils.hh"

#define ASSERT(COND, MSG)                \
  if (!(COND))                           \
  {                                      \
    std::ostringstream ost;              \
    ost << "mex_point: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());     \
  }

#define MEX_ERROR_MESSAGE                                                      \
  "%======================================================================%\n" \
  "% mex_segment: Mex wrapper for ACME segment object.                    %\n" \
  "%                                                                      %\n" \
  "% CONSTRUCTOR:                                                         %\n" \
  "%   obj = mex_segment( 'new' );                                        %\n" \
  "%   obj = mex_segment( 'new', [X1, Y1, Z1], [X2, Y2, Z2] );            %\n" \
  "%                                                                      %\n" \
  "%======================================================================%\n" \
  "%                                                                      %\n" \
  "%    Davide Stocco                                                     %\n" \
  "%    Department of Industrial Engineering                              %\n" \
  "%    University of Trento                                              %\n" \
  "%    davide.stocco@unitn.it                                            %\n" \
  "%                                                                      %\n" \
  "%    Enrico Bertolazzi                                                 %\n" \
  "%    Department of Industrial Engineering                              %\n" \
  "%    University of Trento                                              %\n" \
  "%    enrico.bertolazzi@unitn.it                                        %\n" \
  "%                                                                      %\n" \
  "%======================================================================%\n"

using namespace std;

typedef double real_type;

static void
DATA_NEW(
    mxArray *&mx_id,
    acme::segment *ptr)
{
  mx_id = convertPtr2Mat<acme::segment>(ptr);
}

static inline acme::segment *
DATA_GET(
    mxArray const *&mx_id)
{
  return convertMat2Ptr<acme::segment>(mx_id);
}

static void
DATA_DELETE(
    mxArray const *&mx_id)
{
  destroyObject<acme::segment>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_new(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{

#define CMD "mex_segment( 'new', [, args] ): "
  MEX_ASSERT(nrhs == 1 || nrhs == 3, CMD "expected 1 or 4 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  MEX_ASSERT(
      mxIsChar(arg_in_0),
      CMD << "first argument must be a string, found ``" << mxGetClassName(arg_in_0) << "''\n");
  string tname = mxArrayToString(arg_in_0);

  real_type x1 = acme::NaN;
  real_type y1 = acme::NaN;
  real_type z1 = acme::NaN;
  real_type x2 = acme::NaN;
  real_type y2 = acme::NaN;
  real_type z2 = acme::NaN;
  if (nrhs == 2)
  {
    real_type const *matrix1_ptr;
    mwSize rows1, cols1;
    matrix1_ptr = getMatrixPointer(arg_in_1, rows1, cols1, CMD "Error in first input matrix");
    MEX_ASSERT(rows1 == 3 || cols1 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows1 << ", cols = " << cols1 << '\n');
    real_type const *matrix2_ptr;
    mwSize rows2, cols2;
    matrix2_ptr = getMatrixPointer(arg_in_2, rows2, cols2, CMD "Error in second input matrix");
    MEX_ASSERT(rows2 == 3 || cols2 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows2 << ", cols = " << cols2 << '\n');
    x1 = matrix1_ptr[0];
    y1 = matrix1_ptr[1];
    z1 = matrix1_ptr[2];
    x2 = matrix2_ptr[0];
    y2 = matrix2_ptr[1];
    z2 = matrix2_ptr[2];
  }

  acme::segment *ptr = new acme::segment(x1, y1, z1, x2, y2, z2);
  DATA_NEW(arg_out_0, ptr);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_delete(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{

#define CMD "mex_segment( 'delete', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  DATA_DELETE(arg_in_1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getVertex1(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{

#define CMD "mex_segment( 'do_getVertex1', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::segment *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->vertex(0));
  arg_out_0 = convertPtr2Mat<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getVertex2(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{

#define CMD "mex_segment( 'do_getVertex2', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::segment *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->vertex(1));
  arg_out_0 = convertPtr2Mat<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setVertex1(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{

#define CMD "mex_segment( 'setVertex1', OBJ, [,args] ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::segment *self = DATA_GET(arg_in_1);
  acme::point *obj = convertMat2Ptr<acme::point>(arg_in_2);
  self->vertex(0) = *obj;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setVertex2(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{

#define CMD "mex_segment( 'setVertex2', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 5, CMD "expected 5 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::segment *self = DATA_GET(arg_in_1);
  acme::point *obj = convertMat2Ptr<acme::point>(arg_in_2);
  self->vertex(0) = *obj;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_copy(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{

#define CMD "mex_segment( 'copy', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::segment *self = DATA_GET(arg_in_1);
  acme::segment *other = DATA_GET(arg_in_2);
  self->vertex(0) = other->vertex(0);
  self->vertex(1) = other->vertex(1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_translate(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_segment( 'translate', OBJ, [X, Y, Z] ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::segment *self = DATA_GET(arg_in_1);
  real_type const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = getMatrixPointer(arg_in_2, rows, cols, CMD "Error in first input matrix");
  MEX_ASSERT(rows == 3 || cols == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows << ", cols = " << cols << '\n');
  real_type x = matrix_ptr[0];
  real_type y = matrix_ptr[1];
  real_type z = matrix_ptr[2];
  self->translate(acme::vec3(x, y, z));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_transform(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{

#define CMD "mex_point( 'transform', OBJ, MATRIX ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::segment *self = DATA_GET(arg_in_1);
  real_type const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = getMatrixPointer(arg_in_2, rows, cols, CMD "Error in reading affine transformation matrix");
  acme::affine matrix;

  MEX_ASSERT(rows == 4 || cols == 4, CMD "expected rows = 4 and cols = 4 found, rows = " << rows << ", cols = " << cols << '\n');
  matrix.matrix() << matrix_ptr[0], matrix_ptr[1], matrix_ptr[2], matrix_ptr[3],
      matrix_ptr[4], matrix_ptr[5], matrix_ptr[6], matrix_ptr[7],
      matrix_ptr[8], matrix_ptr[9], matrix_ptr[10], matrix_ptr[1],
      matrix_ptr[12], matrix_ptr[13], matrix_ptr[14], matrix_ptr[15];
  acme::segment *out = new acme::segment((*self));
  out->transform(matrix);
  DATA_NEW(arg_out_0, out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef void (*DO_CMD)(int nlhs, mxArray *plhs[],
                       int nrhs, mxArray const *prhs[]);

static map<string, DO_CMD> cmd_to_fun = {
    {"new", do_new},
    {"delete", do_delete},
    {"getVertex1", do_getVertex1},
    {"getVertex2", do_getVertex2},
    {"setVertex1", do_setVertex1},
    {"setVertex2", do_setVertex2},
    {"copy", do_copy},
    {"translate", do_translate},
    {"transform", do_transform}};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

extern "C" void
mexFunction(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
  // the first argument must be a string
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
    mexErrMsgTxt((string("mex_segment Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("mex_segment failed\n");
  }
}
