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
/// file: mex_triangle.cc
///

#include "mex_utils.hh"
#include "acme.hh"

#define ASSERT(COND, MSG)                   \
  if (!(COND))                              \
  {                                         \
    std::ostringstream ost;                 \
    ost << "mex_triangle: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());        \
  }

#define MEX_ERROR_MESSAGE                                                     \
  "%=====================================================================%\n" \
  "% mex_triangle: Mex wrapper for ACME triangle object.                 %\n" \
  "%                                                                     %\n" \
  "% CONSTRUCTORS:                                                       %\n" \
  "%   OUT = mex_triangle( 'new' );                                      %\n" \
  "%   OUT = mex_triangle( 'new',                                        %\n" \
  "%                       [X; Y; Z], : Triangle vertex 1                %\n" \
  "%                       [X; Y; Z], : Triangle vertex 2                %\n" \
  "%                       [X; Y; Z]  : Triangle vertex 3                %\n" \
  "%                     );                                              %\n" \
  "%   obj = mex_triangle( 'new',                                        %\n" \
  "%                        V1X, : Triangle vertex 1 x value             %\n" \
  "%                        V1Y, : Triangle vertex 1 y value             %\n" \
  "%                        V1Z, : Triangle vertex 1 z value             %\n" \
  "%                        V2X, : Triangle vertex 2 x value             %\n" \
  "%                        V2Y, : Triangle vertex 2 y value             %\n" \
  "%                        V2Z, : Triangle vertex 2 z value             %\n" \
  "%                        V3X, : Triangle vertex 3 x value             %\n" \
  "%                        V3Y, : Triangle vertex 3 y value             %\n" \
  "%                        V3Z  : Triangle vertex 3 z value             %\n" \
  "%                     );                                              %\n" \
  "%                                                                     %\n" \
  "% DESTRUCTOR:                                                         %\n" \
  "%   mex_triangle( 'delete', OBJ );                                    %\n" \
  "%                                                                     %\n" \
  "% USAGE:                                                              %\n" \
  "%   OUT = mex_triangle( 'getVertex1', OBJ );                          %\n" \
  "%   OUT = mex_triangle( 'getVertex2', OBJ );                          %\n" \
  "%   OUT = mex_triangle( 'getVertex3', OBJ );                          %\n" \
  "%         mex_triangle( 'setVertex1', OBJ, OTHER_OBJ );               %\n" \
  "%         mex_triangle( 'setVertex2', OBJ, OTHER_OBJ );               %\n" \
  "%         mex_triangle( 'setVertex3', OBJ, OTHER_OBJ );               %\n" \
  "%         mex_triangle( 'translate', OBJ, VECTOR );                   %\n" \
  "%         mex_triangle( 'transform', OBJ, MATRIX );                   %\n" \
  "%         mex_triangle( 'copy', OBJ, OTHER_OBJ );                     %\n" \
  "%   OUT = mex_triangle( 'isInside', OBJ, OTHER_OBJ );                 %\n" \
  "%   OUT = mex_triangle( 'isDegenerated', OBJ );                       %\n" \
  "%   OUT = mex_triangle( 'isApprox', OBJ, OTHER_OBJ );                 %\n" \
  "%   OUT = mex_triangle( 'centroid', OBJ );                            %\n" \
  "%   OUT = mex_triangle( 'normal', OBJ );                              %\n" \
  "%   OUT = mex_triangle( 'layingPlane', OBJ );                         %\n" \
  "%   OUT = mex_triangle( 'edge', OBJ, I );                             %\n" \
  "%         mex_triangle( 'swap', OBJ, I, J );                          %\n" \
  "%   OUT = mex_triangle( 'clamp', OBJ );                               %\n" \
  "%   OUT = mex_triangle( 'perimeter', OBJ );                           %\n" \
  "%   OUT = mex_triangle( 'area', OBJ );                                %\n" \
  "%   OUT = mex_triangle( 'barycentric', OBJ, OTHER_OBJ );              %\n" \
  "%   OUT = mex_triangle( 'isParallel', OBJ, OTHER_OBJ );               %\n" \
  "%   OUT = mex_triangle( 'isOrthogonal', OBJ, OTHER_OBJ );             %\n" \
  "%   OUT = mex_triangle( 'isCollinear', OBJ, OTHER_OBJ );              %\n" \
  "%   OUT = mex_triangle( 'isCoplanar', OBJ, OTHER_OBJ );               %\n" \
  "%   OUT = mex_triangle( 'intersection', OBJ, OTHER_OBJ, TYPE );       %\n" \
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
    acme::triangle *ptr)
{
  mx_id = utils::mex_convert_ptr_to_mx<acme::triangle>(ptr);
}

static inline acme::triangle *
DATA_GET(
    mxArray const *&mx_id)
{
  return utils::mex_convert_mx_to_ptr<acme::triangle>(mx_id);
}

static void
DATA_DELETE(
    mxArray const *&mx_id)
{
  utils::mex_destroy_object<acme::triangle>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_new(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'new', [, args] ): "
  UTILS_MEX_ASSERT(nrhs == 1 || nrhs == 4 || nrhs == 10, CMD "expected 1, 4 or 10 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  UTILS_MEX_ASSERT(
      mxIsChar(arg_in_0),
      CMD "first argument must be a string, found " << mxGetClassName(arg_in_0) << "\n");

  real_mex x1 = acme::QUIET_NAN;
  real_mex y1 = acme::QUIET_NAN;
  real_mex z1 = acme::QUIET_NAN;
  real_mex x2 = acme::QUIET_NAN;
  real_mex y2 = acme::QUIET_NAN;
  real_mex z2 = acme::QUIET_NAN;
  real_mex x3 = acme::QUIET_NAN;
  real_mex y3 = acme::QUIET_NAN;
  real_mex z3 = acme::QUIET_NAN;

  if (nrhs == 4)
  {
    real_mex const *matrix1_ptr;
    mwSize rows1, cols1;
    matrix1_ptr = utils::mex_matrix_pointer(arg_in_1, rows1, cols1, CMD "Error in first input matrix");
    UTILS_MEX_ASSERT(rows1 == 3 || cols1 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows1 << ", cols = " << cols1 << "\n");
    x1 = matrix1_ptr[0];
    y1 = matrix1_ptr[1];
    z1 = matrix1_ptr[2];
    real_mex const *matrix2_ptr;
    mwSize rows2, cols2;
    matrix2_ptr = utils::mex_matrix_pointer(arg_in_2, rows2, cols2, CMD "Error in second input matrix");
    UTILS_MEX_ASSERT(rows2 == 3 || cols2 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows2 << ", cols = " << cols2 << "\n");
    x2 = matrix2_ptr[0];
    y2 = matrix2_ptr[1];
    z2 = matrix2_ptr[2];
    real_mex const *matrix3_ptr;
    mwSize rows3, cols3;
    matrix3_ptr = utils::mex_matrix_pointer(arg_in_3, rows3, cols3, CMD "Error in third input matrix");
    UTILS_MEX_ASSERT(rows3 == 3 || cols3 == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows3 << ", cols = " << cols3 << "\n");
    x3 = matrix3_ptr[0];
    y3 = matrix3_ptr[1];
    z3 = matrix3_ptr[2];
  }
  else if (nrhs == 10)
  {
    x1 = utils::mex_get_scalar_value(arg_in_1, CMD "Error in reading vertex 1 x value");
    y1 = utils::mex_get_scalar_value(arg_in_2, CMD "Error in reading vertex 1 y value");
    z1 = utils::mex_get_scalar_value(arg_in_3, CMD "Error in reading vertex 1 z value");
    x2 = utils::mex_get_scalar_value(arg_in_4, CMD "Error in reading vertex 2 x value");
    y2 = utils::mex_get_scalar_value(arg_in_5, CMD "Error in reading vertex 2 y value");
    z2 = utils::mex_get_scalar_value(arg_in_6, CMD "Error in reading vertex 2 z value");
    x3 = utils::mex_get_scalar_value(arg_in_7, CMD "Error in reading vertex 3 x value");
    y3 = utils::mex_get_scalar_value(arg_in_8, CMD "Error in reading vertex 3 y value");
    z3 = utils::mex_get_scalar_value(arg_in_9, CMD "Error in reading vertex 3 z value");
  }

  acme::triangle *ptr = new acme::triangle(x1, y1, z1, x2, y2, z2, x3, y3, z3);
  DATA_NEW(arg_out_0, ptr);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_delete(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'delete', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  DATA_DELETE(arg_in_1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getVertex1(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'getVertex1', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->vertex(0));
  arg_out_0 = utils::mex_convert_ptr_to_mx<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getVertex2(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'getVertex2', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->vertex(1));
  arg_out_0 = utils::mex_convert_ptr_to_mx<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getVertex3(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'getVertex3', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->vertex(2));
  arg_out_0 = utils::mex_convert_ptr_to_mx<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setVertex1(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'setVertex1', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::point *obj = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  self->vertex(0) = *obj;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setVertex2(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'setVertex2', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::point *obj = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  self->vertex(1) = *obj;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setVertex3(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'setVertex3', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::point *obj = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  self->vertex(2) = *obj;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_translate(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'translate', OBJ, VECTOR ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  real_mex const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = utils::mex_matrix_pointer(arg_in_2, rows, cols, CMD "Error in first input matrix");
  UTILS_MEX_ASSERT(rows == 3 || cols == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows << ", cols = " << cols << "\n");
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

#define CMD "mex_triangle( 'copy', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::triangle *other = DATA_GET(arg_in_2);
  *self = *other;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_transform(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'transform', OBJ, MATRIX ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  real_mex const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = utils::mex_matrix_pointer(arg_in_2, rows, cols, CMD "Error in reading affine transformation matrix");
  acme::affine matrix;
  UTILS_MEX_ASSERT(rows == 4 || cols == 4, CMD "expected rows = 4 and cols = 4 found, rows = " << rows << ", cols = " << cols << "\n");
  matrix.matrix() << matrix_ptr[0], matrix_ptr[4], matrix_ptr[8], matrix_ptr[12],
      matrix_ptr[1], matrix_ptr[5], matrix_ptr[9], matrix_ptr[13],
      matrix_ptr[2], matrix_ptr[6], matrix_ptr[10], matrix_ptr[14],
      matrix_ptr[3], matrix_ptr[7], matrix_ptr[11], matrix_ptr[15];
  self->transform(matrix);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isInside(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'isInside', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::point *other = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  utils::mex_set_scalar_bool(arg_out_0, self->isInside(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isDegenerated(int nlhs, mxArray *plhs[],
                 int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'isDegenerated', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  utils::mex_set_scalar_bool(arg_out_0, self->isDegenerated());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isApprox(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'isApprox', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::triangle *other = DATA_GET(arg_in_2);
  utils::mex_set_scalar_bool(arg_out_0, self->isApprox(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_centroid(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'centroid', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->centroid());
  arg_out_0 = utils::mex_convert_ptr_to_mx<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_normal(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'normal', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  real_mex *output = utils::mex_create_matrix_value(arg_out_0, 3, 1);
  acme::vec3 outvec(self->normal());
  output[0] = outvec.x();
  output[1] = outvec.y();
  output[2] = outvec.z();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_layingPlane(int nlhs, mxArray *plhs[],
               int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'layingPlane', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::plane *out = new acme::plane(self->layingPlane());
  arg_out_0 = utils::mex_convert_ptr_to_mx<acme::plane>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_edge(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'edge', OBJ, I ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  int i = utils::mex_get_int64(arg_in_2, CMD "Error in first input integer");
  acme::segment *out = new acme::segment(self->edge(i));
  arg_out_0 = utils::mex_convert_ptr_to_mx<acme::segment>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_swap(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'swap', OBJ, I, J ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  int i = utils::mex_get_int64(arg_in_2, CMD "Error in first input integer");
  int j = utils::mex_get_int64(arg_in_3, CMD "Error in second input integer");
  self->swap(i, j);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_clamp(int nlhs, mxArray *plhs[],
         int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'clamp', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 2, CMD "expected 2 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);

  acme::vec3 min(acme::NAN_VEC3);
  acme::vec3 max(acme::NAN_VEC3);
  self->clamp(min, max);

  real_mex *output_min = utils::mex_create_matrix_value(arg_out_0, 3, 1);
  output_min[0] = min.x();
  output_min[1] = min.y();
  output_min[2] = min.z();

  real_mex *output_max = utils::mex_create_matrix_value(arg_out_1, 3, 1);
  output_max[0] = max.x();
  output_max[1] = max.y();
  output_max[2] = max.z();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_perimeter(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'perimeter', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  utils::mex_set_scalar_value(arg_out_0, self->perimeter());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_area(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'area', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  utils::mex_set_scalar_value(arg_out_0, self->area());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_barycentric(int nlhs, mxArray *plhs[],
               int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'barycentric', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  acme::point *other = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  real_mex *output = utils::mex_create_matrix_value(arg_out_0, 3, 1);
  self->barycentric(*other, output[0], output[1], output[2]);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isParallel(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'isParallel', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);
  acme::entity *other = nullptr;

  if (type == "none")
    other = utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  utils::mex_set_scalar_bool(arg_out_0, acme::IsParallel(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isOrthogonal(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'isOrthogonal', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);
  acme::entity *other = nullptr;

  if (type == "none")
    other = utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  utils::mex_set_scalar_bool(arg_out_0, acme::IsOrthogonal(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isCollinear(int nlhs, mxArray *plhs[],
               int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'isCollinear', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);

  acme::entity *other = nullptr;

  if (type == "none")
    other = utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  utils::mex_set_scalar_bool(arg_out_0, acme::IsCollinear(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isCoplanar(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'isCoplanar', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);

  acme::entity *other = nullptr;

  if (type == "none")
    other = utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  utils::mex_set_scalar_bool(arg_out_0, acme::IsCoplanar(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_intersection(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_triangle( 'intersection', OBJ, OTHER_OBJ, TYPE ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 2, CMD "expected 2 output, nlhs = " << nlhs << "\n");

  acme::triangle *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);

  acme::entity *other = nullptr;

  if (type == "none")
    other = utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  acme::entity *out = acme::Intersection(self, other);
  string out_type = out->type();
  if (out_type == "none")
    arg_out_0 = utils::mex_convert_ptr_to_mx<acme::none>(dynamic_cast<acme::none *>(out));
  else if (out_type == "point")
    arg_out_0 = utils::mex_convert_ptr_to_mx<acme::point>(dynamic_cast<acme::point *>(out));
  else if (out_type == "line")
    arg_out_0 = utils::mex_convert_ptr_to_mx<acme::line>(dynamic_cast<acme::line *>(out));
  else if (out_type == "ray")
    arg_out_0 = utils::mex_convert_ptr_to_mx<acme::ray>(dynamic_cast<acme::ray *>(out));
  else if (out_type == "plane")
    arg_out_0 = utils::mex_convert_ptr_to_mx<acme::plane>(dynamic_cast<acme::plane *>(out));
  else if (out_type == "segment")
    arg_out_0 = utils::mex_convert_ptr_to_mx<acme::segment>(dynamic_cast<acme::segment *>(out));
  else if (out_type == "triangle")
    arg_out_0 = utils::mex_convert_ptr_to_mx<acme::triangle>(dynamic_cast<acme::triangle *>(out));
  else if (out_type == "disk")
    arg_out_0 = utils::mex_convert_ptr_to_mx<acme::disk>(dynamic_cast<acme::disk *>(out));
  else if (out_type == "ball")
    arg_out_0 = utils::mex_convert_ptr_to_mx<acme::ball>(dynamic_cast<acme::ball *>(out));

  arg_out_1 = mxCreateString(out_type.c_str());
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
    {"getVertex3", do_getVertex3},
    {"setVertex1", do_setVertex1},
    {"setVertex2", do_setVertex2},
    {"setVertex3", do_setVertex3},
    {"copy", do_copy},
    {"translate", do_translate},
    {"transform", do_transform},
    {"isInside", do_isInside},
    {"isDegenerated", do_isDegenerated},
    {"isApprox", do_isApprox},
    {"centroid", do_centroid},
    {"normal", do_normal},
    {"layingPlane", do_layingPlane},
    {"edge", do_edge},
    {"swap", do_swap},
    {"clamp", do_clamp},
    {"perimeter", do_perimeter},
    {"area", do_area},
    {"barycentric", do_barycentric},
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
    UTILS_MEX_ASSERT(mxIsChar(arg_in_0), "First argument must be a string");
    string cmd = mxArrayToString(arg_in_0);
    DO_CMD pfun = cmd_to_fun.at(cmd);
    pfun(nlhs, plhs, nrhs, prhs);
  }
  catch (exception const &e)
  {
    mexErrMsgTxt((string("mex_triangle Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("mex_triangle failed\n");
  }
}

///
/// eof: mex_triangle.cc
///
