/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                     *
 * The ACME project                                                    *
 *                                                                     *
 * Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *
 *                                                                     *
 * The ACME project and its components are supplied under the terms of *
 * the open source BSD 2-Clause License. The contents of the ACME      *
 * project and its components may not be copied or disclosed except in *
 * accordance with the terms of the BSD 2-Clause License.              *
 *                                                                     *
 * URL: https://opensource.org/licenses/BSD-2-Clause                   *
 *                                                                     *
 *    Davide Stocco                                                    *
 *    Department of Industrial Engineering                             *
 *    University of Trento                                             *
 *    e-mail: davide.stocco@unitn.it                                   *
 *                                                                     *
 *    Enrico Bertolazzi                                                *
 *    Department of Industrial Engineering                             *
 *    University of Trento                                             *
 *    e-mail: enrico.bertolazzi@unitn.it                               *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

///
/// file: mex_aabb.cc
///

#include "Utils_mex.hh"
#include "acme.hh"

#define ASSERT(COND, MSG)               \
  if (!(COND))                          \
  {                                     \
    std::ostringstream ost;             \
    ost << "mex_aabb: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());    \
  }

#define MEX_ERROR_MESSAGE                                                     \
  "%=====================================================================%\n" \
  "% mex_aabb: Mex wrapper for ACME axis-aligned bounding box object.    %\n" \
  "%                                                                     %\n" \
  "% CONSTRUCTORS:                                                       %\n" \
  "%   obj = mex_aabb( 'new' );                                          %\n" \
  "%   obj = mex_aabb( 'new',                                            %\n" \
  "%                   [X; Y; Z], : Minimum aabb point                   %\n" \
  "%                   [X; Y; Z]  : Maximum aabb point                   %\n" \
  "%                 );                                                  %\n" \
  "%   obj = mex_aabb( 'new',                                            %\n" \
  "%                    MINX, : Minimum aabb point x value               %\n" \
  "%                    MINY, : Minimum aabb point y value               %\n" \
  "%                    MINZ, : Minimum aabb point z value               %\n" \
  "%                    MAXX, : Maximum aabb point x value               %\n" \
  "%                    MAXY, : Maximum aabb point y value               %\n" \
  "%                    MAXZ  : Maximum aabb point z value               %\n" \
  "%                  );                                                 %\n" \
  "%                                                                     %\n" \
  "% DESTRUCTOR:                                                         %\n" \
  "%   mex_aabb( 'delete', OBJ );                                        %\n" \
  "%                                                                     %\n" \
  "% USAGE:                                                              %\n" \
  "%   OUT = mex_aabb( 'getMin', OBJ );                                  %\n" \
  "%   OUT = mex_aabb( 'getMinX', OBJ );                                 %\n" \
  "%   OUT = mex_aabb( 'getMinY', OBJ );                                 %\n" \
  "%   OUT = mex_aabb( 'getMinZ', OBJ );                                 %\n" \
  "%   OUT = mex_aabb( 'getMax', OBJ );                                  %\n" \
  "%   OUT = mex_aabb( 'getMaxX', OBJ );                                 %\n" \
  "%   OUT = mex_aabb( 'getMaxY', OBJ );                                 %\n" \
  "%   OUT = mex_aabb( 'getMaxZ', OBJ );                                 %\n" \
  "%         mex_aabb( 'setMin', OBJ );                                  %\n" \
  "%         mex_aabb( 'setMinX', OBJ );                                 %\n" \
  "%         mex_aabb( 'setMinY', OBJ );                                 %\n" \
  "%         mex_aabb( 'setMinZ', OBJ );                                 %\n" \
  "%         mex_aabb( 'setMax', OBJ );                                  %\n" \
  "%         mex_aabb( 'setMaxX', OBJ );                                 %\n" \
  "%         mex_aabb( 'setMaxY', OBJ );                                 %\n" \
  "%         mex_aabb( 'setMaxZ', OBJ );                                 %\n" \
  "%         mex_aabb( 'translate', OBJ, VECTOR );                       %\n" \
  "%         mex_aabb( 'transform', OBJ, MATRIX );                       %\n" \
  "%         mex_aabb( 'copy', OBJ, OTHER_OBJ );                         %\n" \
  "%   OUT = mex_aabb( 'isInside', OBJ, OTHER_OBJ );                     %\n" \
  "%   OUT = mex_aabb( 'isDegenerated', OBJ );                           %\n" \
  "%   OUT = mex_aabb( 'isApprox', OBJ, OTHER_OBJ );                     %\n" \
  "%   OUT = mex_aabb( 'id', OBJ );                                      %\n" \
  "%   OUT = mex_aabb( 'pos', OBJ );                                     %\n" \
  "%   OUT = mex_aabb( 'intersects', OBJ, OTHER_OBJ );                   %\n" \
  "%   OUT = mex_aabb( 'intersection', OBJ, OTHER_OBJ, TYPE );           %\n" \
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
    acme::aabb *ptr)
{
  mx_id = convertPtr2Mat<acme::aabb>(ptr);
}

static inline acme::aabb *
DATA_GET(
    mxArray const *&mx_id)
{
  return convertMat2Ptr<acme::aabb>(mx_id);
}

static void
DATA_DELETE(
    mxArray const *&mx_id)
{
  destroyObject<acme::aabb>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_new(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'new', [, args] ): "
  MEX_ASSERT(nrhs == 1 || nrhs == 3 || nrhs == 7, CMD "expected 1, 3 or 7 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  MEX_ASSERT(
      mxIsChar(arg_in_0),
      CMD << "first argument must be a string, found ``" << mxGetClassName(arg_in_0) << "''\n");

  real_mex min_x = acme::QUIET_NAN;
  real_mex min_y = acme::QUIET_NAN;
  real_mex min_z = acme::QUIET_NAN;
  real_mex max_x = acme::QUIET_NAN;
  real_mex max_y = acme::QUIET_NAN;
  real_mex max_z = acme::QUIET_NAN;

  if (nrhs == 3)
  {
    real_mex const *matrix1_ptr;
    mwSize rows1, cols1;
    matrix1_ptr = getMatrixPointer(arg_in_1, rows1, cols1, CMD "Error in first input matrix");
    MEX_ASSERT(rows1 == 3 || cols1 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows1 << ", cols = " << cols1 << '\n');
    real_mex const *matrix2_ptr;
    min_x = matrix1_ptr[0];
    min_y = matrix1_ptr[1];
    min_z = matrix1_ptr[2];
    mwSize rows2, cols2;
    matrix2_ptr = getMatrixPointer(arg_in_2, rows2, cols2, CMD "Error in second input matrix");
    MEX_ASSERT(rows2 == 3 || cols2 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows2 << ", cols = " << cols2 << '\n');
    max_x = matrix2_ptr[0];
    max_y = matrix2_ptr[1];
    max_z = matrix2_ptr[2];
  }
  else if (nrhs == 7)
  {
    min_x = getScalarValue(arg_in_1, CMD "Error in reading minimum x value");
    min_y = getScalarValue(arg_in_2, CMD "Error in reading minimum y value");
    min_z = getScalarValue(arg_in_3, CMD "Error in reading minimum z value");
    max_x = getScalarValue(arg_in_4, CMD "Error in reading maximum x value");
    max_y = getScalarValue(arg_in_5, CMD "Error in reading maximum y value");
    max_z = getScalarValue(arg_in_6, CMD "Error in reading maximum z value");
  }

  acme::aabb *ptr = new acme::aabb(min_x, min_y, min_z, max_x, max_y, max_z, 0, 0);
  DATA_NEW(arg_out_0, ptr);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_delete(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'delete', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  DATA_DELETE(arg_in_1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getMin(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'getMin', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->min());
  arg_out_0 = convertPtr2Mat<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getMinX(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'getMinX', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->min(0));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getMinY(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'getMinY', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->min(1));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getMinZ(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'getMinZ', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->min(2));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getMax(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'getMax', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->max());
  arg_out_0 = convertPtr2Mat<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getMaxX(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'getMaxX', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->max(0));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getMaxY(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'getMaxY', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->max(1));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getMaxZ(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'getMaxZ', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->max(2));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setMin(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'setMin', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  acme::point *other = convertMat2Ptr<acme::point>(arg_in_2);
  self->min() = *other;
  self->updateMaxMin();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setMinX(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'setMinX', OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  real_mex other = getScalarValue(arg_in_2, CMD "Error in reading input value");
  self->min(0) = other;
  self->updateMaxMin();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setMinY(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'setMinY', OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  real_mex other = getScalarValue(arg_in_2, CMD "Error in reading input value");
  self->min(1) = other;
  self->updateMaxMin();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setMinZ(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'setMinZ', OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  real_mex other = getScalarValue(arg_in_2, CMD "Error in reading input value");
  self->min(2) = other;
  self->updateMaxMin();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setMax(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'setMax', OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  acme::point *other = convertMat2Ptr<acme::point>(arg_in_2);
  self->max() = *other;
  self->updateMaxMin();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setMaxX(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'setMaxX', OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  real_mex other = getScalarValue(arg_in_2, CMD "Error in reading input value");
  self->max(0) = other;
  self->updateMaxMin();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setMaxY(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'setMaxY', OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  real_mex other = getScalarValue(arg_in_2, CMD "Error in reading input value");
  self->max(1) = other;
  self->updateMaxMin();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setMaxZ(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'setMaxZ', OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  real_mex other = getScalarValue(arg_in_2, CMD "Error in reading input value");
  self->max(2) = other;
  self->updateMaxMin();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_translate(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'translate', OBJ, VECTOR ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
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
do_copy(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{

#define CMD "mex_aabb( 'copy', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  acme::aabb *other = DATA_GET(arg_in_2);
  *self = *other;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isInside(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'isInside', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  acme::point *other = convertMat2Ptr<acme::point>(arg_in_2);
  setBoolValue(arg_out_0, self->isInside(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isDegenerated(int nlhs, mxArray *plhs[],
                 int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'isDegenerated', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  setBoolValue(arg_out_0, self->isDegenerated());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isApprox(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'isApprox', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  acme::aabb *other = DATA_GET(arg_in_2);
  setBoolValue(arg_out_0, self->isApprox(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_id(int nlhs, mxArray *plhs[],
      int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'id', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->id());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_pos(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'pos', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  setScalarValue(arg_out_0, self->pos());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_intersects(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'intersects', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  acme::aabb *other = DATA_GET(arg_in_2);
  setBoolValue(arg_out_0, self->intersects(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_intersection(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_aabb( 'intersection', OBJ, OTHER_OBJ ): "
  MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::aabb *self = DATA_GET(arg_in_1);
  acme::aabb *other = DATA_GET(arg_in_2);
  acme::aabb *output = new acme::aabb();
  acme::Intersection(*self, *other, *output);
  DATA_NEW(arg_out_0, output);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef void (*DO_CMD)(int nlhs, mxArray *plhs[],
                       int nrhs, mxArray const *prhs[]);

static map<string, DO_CMD> cmd_to_fun = {
    {"new", do_new},
    {"delete", do_delete},
    {"getMin", do_getMin},
    {"getMinX", do_getMinX},
    {"getMinY", do_getMinY},
    {"getMinZ", do_getMinZ},
    {"getMax", do_getMax},
    {"getMaxX", do_getMaxX},
    {"getMaxY", do_getMaxY},
    {"getMaxZ", do_getMaxZ},
    {"setMin", do_setMin},
    {"setMinX", do_setMinX},
    {"setMinY", do_setMinY},
    {"setMinZ", do_setMinZ},
    {"setMax", do_setMax},
    {"setMaxX", do_setMaxX},
    {"setMaxY", do_setMaxY},
    {"setMaxZ", do_setMaxZ},
    {"translate", do_translate},
    {"copy", do_copy},
    {"isInside", do_isInside},
    {"isDegenerated", do_isDegenerated},
    {"isApprox", do_isApprox},
    {"id", do_id},
    {"pos", do_pos},
    {"intersects", do_intersects},
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
    mexErrMsgTxt((string("mex_aabb Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("mex_aabb failed\n");
  }
}

///
/// eof: mex_aabb.cc
///
