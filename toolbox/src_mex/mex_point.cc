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
/// file: mex_point.cc
///

#include "mex_utils.hh"
#include "acme.hh"

#define ASSERT(COND, MSG)                \
  if (!(COND))                           \
  {                                      \
    std::ostringstream ost;              \
    ost << "mex_point: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());     \
  }

#define MEX_ERROR_MESSAGE                                                     \
  "%=====================================================================%\n" \
  "% mex_point: Mex wrapper for ACME point object.                       %\n" \
  "%                                                                     %\n" \
  "% CONSTRUCTORS                                                        %\n" \
  "%   obj = mex_point( 'new' );                                         %\n" \
  "%   obj = mex_point( 'new',                                           %\n" \
  "%                    X, Y, Z : Point data                             %\n" \
  "%                    );                                               %\n" \
  "%   obj = mex_point( 'new',                                           %\n" \
  "%                    [X; Y; Z] : Point data                           %\n" \
  "%                    );                                               %\n" \
  "%                                                                     %\n" \
  "% DESTRUCTOR:                                                         %\n" \
  "%   mex_point( 'delete', OBJ );                                       %\n" \
  "%                                                                     %\n" \
  "% USAGE:                                                              %\n" \
  "%   OUT = mex_point( 'getX', OBJ );                                   %\n" \
  "%   OUT = mex_point( 'getY', OBJ );                                   %\n" \
  "%   OUT = mex_point( 'getZ', OBJ );                                   %\n" \
  "%   OUT = mex_point( 'get', OBJ );                                    %\n" \
  "%         mex_point( 'setX', OBJ, OTHER_OBJ );                        %\n" \
  "%         mex_point( 'setY', OBJ, OTHER_OBJ );                        %\n" \
  "%         mex_point( 'setZ', OBJ, OTHER_OBJ );                        %\n" \
  "%         mex_point( 'set', OBJ, OTHER_OBJ );                         %\n" \
  "%         mex_point( 'translate', OBJ, VECTOR );                      %\n" \
  "%         mex_point( 'transform', OBJ, MATRIX );                      %\n" \
  "%         mex_point( 'copy', OBJ, OTHER_OBJ );                        %\n" \
  "%   OUT = mex_point( 'isParallel', OBJ, OTHER_OBJ );                  %\n" \
  "%   OUT = mex_point( 'isOrthogonal', OBJ, OTHER_OBJ );                %\n" \
  "%   OUT = mex_point( 'isCollinear', OBJ, OTHER_OBJ );                 %\n" \
  "%   OUT = mex_point( 'isCoplanar', OBJ, OTHER_OBJ );                  %\n" \
  "%   OUT = mex_point( 'intersection', OBJ, OTHER_OBJ, TYPE );          %\n" \
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
    acme::point *ptr)
{
  mx_id = utils::mex_convert_ptr_to_mx<acme::point>(ptr);
}

static inline acme::point *
DATA_GET(
    mxArray const *&mx_id)
{
  return utils::mex_convert_mx_to_ptr<acme::point>(mx_id);
}

static void
DATA_DELETE(
    mxArray const *&mx_id)
{
  utils::mex_destroy_object<acme::point>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_new(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'new', [, args] ): "
  UTILS_MEX_ASSERT(nrhs == 1 || nrhs == 2 || nrhs == 4, CMD "expected 1, 2 or 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  UTILS_MEX_ASSERT(
      mxIsChar(arg_in_0),
      CMD "first argument must be a string, found " << mxGetClassName(arg_in_1) << "\n");

  real_mex x = acme::QUIET_NAN;
  real_mex y = acme::QUIET_NAN;
  real_mex z = acme::QUIET_NAN;

  acme::point *self = nullptr;

  if (nrhs == 2)
  {
    real_mex const *matrix_ptr;
    mwSize rows, cols;
    matrix_ptr = utils::mex_matrix_pointer(arg_in_1, rows, cols, CMD "Error in input matrix");
    UTILS_MEX_ASSERT(rows == 3 || cols == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows << ", cols = " << cols << "\n");
    x = matrix_ptr[0];
    y = matrix_ptr[1];
    z = matrix_ptr[2];
  }
  else if (nrhs == 4)
  {
    x = utils::mex_get_scalar_value(arg_in_1, CMD "Error in reading x value");
    y = utils::mex_get_scalar_value(arg_in_2, CMD "Error in reading y value");
    z = utils::mex_get_scalar_value(arg_in_3, CMD "Error in reading z value");
  }

  self = new acme::point(x, y, z);
  DATA_NEW(arg_out_0, self);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_delete(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'delete', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  DATA_DELETE(arg_in_1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getX(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'getX', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
  utils::mex_set_scalar_value(arg_out_0, self->x());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getY(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'getY', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
  utils::mex_set_scalar_value(arg_out_0, self->y());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getZ(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'getZ', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
  utils::mex_set_scalar_value(arg_out_0, self->z());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_get(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'get', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
  real_mex *output = utils::mex_create_matrix_value(arg_out_0, 3, 1);
  output[0] = self->x();
  output[1] = self->y();
  output[2] = self->z();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setX(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'setX', OBJ, VALUE ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
  real_mex value = utils::mex_get_scalar_value(arg_in_2, CMD "Error in reading x value");
  self->x() = value;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setY(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'setX', OBJ, VALUE ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
  real_mex value = utils::mex_get_scalar_value(arg_in_2, CMD "Error in reading y value");
  self->y() = value;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setZ(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'setZ', OBJ, VALUE ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_0);
  real_mex value = utils::mex_get_scalar_value(arg_in_1, CMD "Error in reading z value");
  self->z() = value;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_set(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'set', OBJ, args ): "
  UTILS_MEX_ASSERT(nrhs == 3 || nrhs == 5, CMD "expected 3 or 5 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
  real_mex x = acme::QUIET_NAN;
  real_mex y = acme::QUIET_NAN;
  real_mex z = acme::QUIET_NAN;
  if (nrhs == 3)
  {
    real_mex const *matrix_ptr;
    mwSize rows, cols;
    matrix_ptr = utils::mex_matrix_pointer(arg_in_2, rows, cols, CMD "Error in reading input matrix");
    UTILS_MEX_ASSERT(rows == 3 || cols == 1, CMD "expected rows = 3 and cols = 1 found, rows = " << rows << ", cols = " << cols << "\n");
    x = matrix_ptr[0];
    y = matrix_ptr[1];
    z = matrix_ptr[2];
  }
  else if (nrhs == 5)
  {
    x = utils::mex_get_scalar_value(arg_in_2, CMD "Error in reading x value");
    y = utils::mex_get_scalar_value(arg_in_3, CMD "Error in reading y value");
    z = utils::mex_get_scalar_value(arg_in_4, CMD "Error in reading z value");
  }
  self->x() = x;
  self->y() = y;
  self->z() = z;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_copy(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'copy', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
  acme::point *other = DATA_GET(arg_in_2);
  *self = *other;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_translate(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'translate', OBJ, VECTOR ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
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
do_transform(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'transform', OBJ, MATRIX ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
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
do_isParallel(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_point( 'isParallel', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
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
#define CMD "mex_point( 'isOrthogonal', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
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
#define CMD "mex_point( 'isCollinear', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
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
#define CMD "mex_point( 'isCoplanar', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
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
#define CMD "mex_point( 'intersection', OBJ, OTHER_OBJ, TYPE ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << "\n");
  UTILS_MEX_ASSERT(nlhs == 2, CMD "expected 2 output, nlhs = " << nlhs << "\n");

  acme::point *self = DATA_GET(arg_in_1);
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
    {"getX", do_getX},
    {"getY", do_getY},
    {"getZ", do_getZ},
    {"get", do_get},
    {"setX", do_setX},
    {"setY", do_setY},
    {"setZ", do_setZ},
    {"set", do_set},
    {"copy", do_copy},
    {"translate", do_translate},
    {"transform", do_transform},
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
    mexErrMsgTxt((string("mex_point Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("mex_point failed\n");
  }
}

///
/// eof: mex_point.cc
///
