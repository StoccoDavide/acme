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
/// file: mex_disk.cc
///

#include "Utils_mex.hh"
#include "acme.hh"

#define ASSERT(COND, MSG)               \
  if (!(COND))                          \
  {                                     \
    std::ostringstream ost;             \
    ost << "mex_disk: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());    \
  }

#define MEX_ERROR_MESSAGE                                                     \
  "%=====================================================================%\n" \
  "% mex_disk: Mex wrapper for ACME disk object.                         %\n" \
  "%                                                                     %\n" \
  "% CONSTRUCTORS:                                                       %\n" \
  "%   obj = mex_disk( 'new' );                                          %\n" \
  "%   obj = mex_disk( 'new',                                            %\n" \
  "%                     RADIUS,    : Disk radius                        %\n" \
  "%                     [X; Y; Z], : Disk center                        %\n" \
  "%                     [X; Y; Z]  : Disk face normal                   %\n" \
  "%   obj = mex_disk( 'new',                                            %\n" \
  "%                     RADIUS, : Disk radius                           %\n" \
  "%                     CX,     : Disk center x value                   %\n" \
  "%                     CY,     : Disk center y value                   %\n" \
  "%                     CZ,     : Disk center z value                   %\n" \
  "%                     NX,     : Disk face normal x value              %\n" \
  "%                     NY,     : Disk face normal y value              %\n" \
  "%                     NZ      : Disk face normal z value              %\n" \
  "%                   );                                                %\n" \
  "%                                                                     %\n" \
  "% DESTRUCTOR:                                                         %\n" \
  "%   mex_disk( 'delete', OBJ );                                        %\n" \
  "%                                                                     %\n" \
  "% USAGE:                                                              %\n" \
  "%   OUT = mex_disk( 'getRadius', OBJ );                               %\n" \
  "%   OUT = mex_disk( 'getCenter', OBJ );                               %\n" \
  "%   OUT = mex_disk( 'getNormal', OBJ );                               %\n" \
  "%         mex_disk( 'setRadius', OBJ, OTHER_OBJ );                    %\n" \
  "%         mex_disk( 'setCenter', OBJ, OTHER_OBJ );                    %\n" \
  "%         mex_disk( 'setNormal', OBJ, OTHER_OBJ );                    %\n" \
  "%         mex_disk( 'translate', OBJ, VECTOR );                       %\n" \
  "%         mex_disk( 'transform', OBJ, MATRIX );                       %\n" \
  "%         mex_disk( 'copy', OBJ, OTHER_OBJ );                         %\n" \
  "%   OUT = mex_disk( 'isInside', OBJ, OTHER_OBJ );                     %\n" \
  "%   OUT = mex_disk( 'isDegenerated', OBJ );                           %\n" \
  "%   OUT = mex_disk( 'isApprox', OBJ, OTHER_OBJ );                     %\n" \
  "%         mex_disk( 'normalize', OBJ );                               %\n" \
  "%   OUT = mex_disk( 'layingPlane', OBJ );                             %\n" \
  "%         mex_disk( 'reverse', OBJ );                                 %\n" \
  "%   OUT = mex_disk( 'clamp', OBJ );                                   %\n" \
  "%   OUT = mex_disk( 'perimeter', OBJ );                               %\n" \
  "%   OUT = mex_disk( 'area', OBJ );                                    %\n" \
  "%   OUT = mex_disk( 'isParallel', OBJ, OTHER_OBJ );                   %\n" \
  "%   OUT = mex_disk( 'isOrthogonal', OBJ, OTHER_OBJ );                 %\n" \
  "%   OUT = mex_disk( 'isCollinear', OBJ, OTHER_OBJ );                  %\n" \
  "%   OUT = mex_disk( 'isCoplanar', OBJ, OTHER_OBJ );                   %\n" \
  "%   OUT = mex_disk( 'intersection', OBJ, OTHER_OBJ, TYPE );           %\n" \
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
    acme::disk *ptr)
{
  mx_id = Utils::mex_convert_ptr_to_mx<acme::disk>(ptr);
}

static inline acme::disk *
DATA_GET(
    mxArray const *&mx_id)
{
  return Utils::mex_convert_mx_to_ptr<acme::disk>(mx_id);
}

static void
DATA_DELETE(
    mxArray const *&mx_id)
{
  Utils::mex_destroy_object<acme::disk>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_new(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'new', [, args] ): "
  UTILS_MEX_ASSERT(nrhs == 1 || nrhs == 4 || nrhs == 8, CMD "expected 1, 4 or 8 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  UTILS_MEX_ASSERT(
      mxIsChar(arg_in_0),
      CMD "first argument must be a string, found ``{}''\n", mxGetClassName(arg_in_0));

  real_mex r = acme::QUIET_NAN;
  real_mex cx = acme::QUIET_NAN;
  real_mex cy = acme::QUIET_NAN;
  real_mex cz = acme::QUIET_NAN;
  real_mex nx = acme::QUIET_NAN;
  real_mex ny = acme::QUIET_NAN;
  real_mex nz = acme::QUIET_NAN;

  if (nrhs == 4)
  {
    r = Utils::mex_get_scalar_value(arg_in_1, CMD "Error in reading radius value");
    real_mex const *matrix1_ptr;
    mwSize rows1, cols1;
    matrix1_ptr = Utils::mex_matrix_pointer(arg_in_2, rows1, cols1, CMD "Error in first input matrix");
    UTILS_MEX_ASSERT(rows1 == 3 || cols1 == 1, CMD "expected rows = 3 and cols = 1 found, rows = {}, cols = {}\n", rows1, cols1);
    real_mex const *matrix2_ptr;
    cx = matrix1_ptr[0];
    cy = matrix1_ptr[1];
    cz = matrix1_ptr[2];
    mwSize rows2, cols2;
    matrix2_ptr = Utils::mex_matrix_pointer(arg_in_3, rows2, cols2, CMD "Error in second input matrix");
    UTILS_MEX_ASSERT(rows2 == 3 || cols2 == 1, CMD "expected rows = 3 and cols = 1 found, rows = {}, cols = {}\n", rows2, cols2);
    nx = matrix2_ptr[0];
    ny = matrix2_ptr[1];
    nz = matrix2_ptr[2];
  }
  else if (nrhs == 8)
  {
    r = Utils::mex_get_scalar_value(arg_in_1, CMD "Error in reading radius value");
    cx = Utils::mex_get_scalar_value(arg_in_2, CMD "Error in reading center x value");
    cy = Utils::mex_get_scalar_value(arg_in_3, CMD "Error in reading center y value");
    cz = Utils::mex_get_scalar_value(arg_in_4, CMD "Error in reading center z value");
    nx = Utils::mex_get_scalar_value(arg_in_5, CMD "Error in reading normal x value");
    ny = Utils::mex_get_scalar_value(arg_in_6, CMD "Error in reading normal y value");
    nz = Utils::mex_get_scalar_value(arg_in_7, CMD "Error in reading normal z value");
  }

  acme::disk *ptr = new acme::disk(r, cx, cy, cz, nx, ny, nz);
  DATA_NEW(arg_out_0, ptr);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_delete(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'delete', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = {}\n", nlhs);

  DATA_DELETE(arg_in_1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getRadius(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'getRadius', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  Utils::mex_set_scalar_value(arg_out_0, self->radius());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getCenter(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'getCenter', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  acme::point *out = new acme::point(self->center());
  arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::point>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_getNormal(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'getNormal', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  real_mex *output = Utils::mex_create_matrix_value(arg_out_0, 3, 1);
  acme::vec3 outvec(self->normal());
  output[0] = outvec.x();
  output[1] = outvec.y();
  output[2] = outvec.z();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setRadius(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'setRadius', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  Utils::mex_set_scalar_value(arg_out_0, self->radius());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setCenter(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'setCenter', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  acme::point *obj = Utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  self->center() = *obj;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_setNormal(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{

#define CMD "mex_disk( 'setNormal', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  real_mex const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = Utils::mex_matrix_pointer(arg_in_2, rows, cols, CMD "Error in first input matrix");
  UTILS_MEX_ASSERT(rows == 3 || cols == 1, CMD "expected rows = 3 and cols = 1 found, rows = {}, cols = {}\n", rows, cols);
  real_mex x = matrix_ptr[0];
  real_mex y = matrix_ptr[1];
  real_mex z = matrix_ptr[2];
  self->normal() = acme::vec3(x, y, z);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_translate(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'translate', OBJ, VECTOR ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  real_mex const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = Utils::mex_matrix_pointer(arg_in_2, rows, cols, CMD "Error in first input matrix");
  UTILS_MEX_ASSERT(rows == 3 || cols == 1, CMD "expected rows = 3 and cols = 1 found, rows = {}, cols = {}\n", rows, cols);
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
#define CMD "mex_disk( 'transform', OBJ, MATRIX ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  real_mex const *matrix_ptr;
  mwSize rows, cols;
  matrix_ptr = Utils::mex_matrix_pointer(arg_in_2, rows, cols, CMD "Error in reading affine transformation matrix");
  acme::affine matrix;
  UTILS_MEX_ASSERT(rows == 4 || cols == 4, CMD "expected rows = 4 and cols = 4 found, rows = {}, cols = {}\n", rows, cols);
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
#define CMD "mex_disk( 'copy', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  acme::disk *other = DATA_GET(arg_in_2);
  *self = *other;
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isInside(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'isInside', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  acme::point *other = Utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  Utils::mex_set_scalar_bool(arg_out_0, self->isInside(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isDegenerated(int nlhs, mxArray *plhs[],
                 int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'isDegenerated', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  Utils::mex_set_scalar_bool(arg_out_0, self->isDegenerated());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isApprox(int nlhs, mxArray *plhs[],
            int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'isApprox', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 3, CMD "expected 3 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  acme::disk *other = DATA_GET(arg_in_2);
  Utils::mex_set_scalar_bool(arg_out_0, self->isApprox(*other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_normalize(int nlhs, mxArray *plhs[],
             int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'normalize', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  self->normalize();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_layingPlane(int nlhs, mxArray *plhs[],
               int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'layingPlane', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  acme::plane *out = new acme::plane(self->layingPlane());
  arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::plane>(out);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_reverse(int nlhs, mxArray *plhs[],
           int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'reverse', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  self->reverse();
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_clamp(int nlhs, mxArray *plhs[],
         int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'clamp', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 2, CMD "expected 2 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);

  acme::vec3 min(acme::NAN_VEC3);
  acme::vec3 max(acme::NAN_VEC3);
  self->clamp(min, max);

  real_mex *output_min = Utils::mex_create_matrix_value(arg_out_0, 3, 1);
  output_min[0] = min.x();
  output_min[1] = min.y();
  output_min[2] = min.z();

  real_mex *output_max = Utils::mex_create_matrix_value(arg_out_1, 3, 1);
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
#define CMD "mex_disk( 'perimeter', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  Utils::mex_set_scalar_value(arg_out_0, self->perimeter());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_area(int nlhs, mxArray *plhs[],
        int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'area', OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  Utils::mex_set_scalar_value(arg_out_0, self->area());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isParallel(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'isParallel', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);
  acme::entity *other = nullptr;

  if (type == "none")
    other = Utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = Utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = Utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = Utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = Utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = Utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = Utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = Utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = Utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  Utils::mex_set_scalar_bool(arg_out_0, acme::IsParallel(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isOrthogonal(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'isOrthogonal', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);
  acme::entity *other = nullptr;

  if (type == "none")
    other = Utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = Utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = Utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = Utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = Utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = Utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = Utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = Utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = Utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  Utils::mex_set_scalar_bool(arg_out_0, acme::IsOrthogonal(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isCollinear(int nlhs, mxArray *plhs[],
               int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'isCollinear', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);

  acme::entity *other = nullptr;

  if (type == "none")
    other = Utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = Utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = Utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = Utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = Utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = Utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = Utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = Utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = Utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  Utils::mex_set_scalar_bool(arg_out_0, acme::IsCollinear(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isCoplanar(int nlhs, mxArray *plhs[],
              int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'isCoplanar', OBJ, OTHER_OBJ ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);

  acme::entity *other = nullptr;

  if (type == "none")
    other = Utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = Utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = Utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = Utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = Utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = Utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = Utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = Utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = Utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  Utils::mex_set_scalar_bool(arg_out_0, acme::IsCoplanar(self, other));
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_intersection(int nlhs, mxArray *plhs[],
                int nrhs, mxArray const *prhs[])
{
#define CMD "mex_disk( 'intersection', OBJ, OTHER_OBJ, TYPE ): "
  UTILS_MEX_ASSERT(nrhs == 4, CMD "expected 4 inputs, nrhs = {}\n", nrhs);
  UTILS_MEX_ASSERT(nlhs == 2, CMD "expected 2 output, nlhs = {}\n", nlhs);

  acme::disk *self = DATA_GET(arg_in_1);
  string type = mxArrayToString(arg_in_3);

  acme::entity *other = nullptr;

  if (type == "none")
    other = Utils::mex_convert_mx_to_ptr<acme::none>(arg_in_2);
  else if (type == "point")
    other = Utils::mex_convert_mx_to_ptr<acme::point>(arg_in_2);
  else if (type == "line")
    other = Utils::mex_convert_mx_to_ptr<acme::line>(arg_in_2);
  else if (type == "ray")
    other = Utils::mex_convert_mx_to_ptr<acme::ray>(arg_in_2);
  else if (type == "plane")
    other = Utils::mex_convert_mx_to_ptr<acme::plane>(arg_in_2);
  else if (type == "segment")
    other = Utils::mex_convert_mx_to_ptr<acme::segment>(arg_in_2);
  else if (type == "triangle")
    other = Utils::mex_convert_mx_to_ptr<acme::triangle>(arg_in_2);
  else if (type == "disk")
    other = Utils::mex_convert_mx_to_ptr<acme::disk>(arg_in_2);
  else if (type == "ball")
    other = Utils::mex_convert_mx_to_ptr<acme::ball>(arg_in_2);

  acme::entity *out = acme::Intersection(self, other);
  string out_type = out->type();
  if (out_type == "none")
    arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::none>(dynamic_cast<acme::none *>(out));
  else if (out_type == "point")
    arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::point>(dynamic_cast<acme::point *>(out));
  else if (out_type == "line")
    arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::line>(dynamic_cast<acme::line *>(out));
  else if (out_type == "ray")
    arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::ray>(dynamic_cast<acme::ray *>(out));
  else if (out_type == "plane")
    arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::plane>(dynamic_cast<acme::plane *>(out));
  else if (out_type == "segment")
    arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::segment>(dynamic_cast<acme::segment *>(out));
  else if (out_type == "triangle")
    arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::triangle>(dynamic_cast<acme::triangle *>(out));
  else if (out_type == "disk")
    arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::disk>(dynamic_cast<acme::disk *>(out));
  else if (out_type == "ball")
    arg_out_0 = Utils::mex_convert_ptr_to_mx<acme::ball>(dynamic_cast<acme::ball *>(out));

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
    {"getNormal", do_getNormal},
    {"setRadius", do_setRadius},
    {"setCenter", do_setCenter},
    {"setNormal", do_setNormal},
    {"copy", do_copy},
    {"translate", do_translate},
    {"transform", do_transform},
    {"isInside", do_isInside},
    {"isDegenerated", do_isDegenerated},
    {"isApprox", do_isApprox},
    {"normalize", do_normalize},
    {"layingPlane", do_layingPlane},
    {"reverse", do_reverse},
    {"clamp", do_clamp},
    {"perimeter", do_perimeter},
    {"area", do_area},
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
    UTILS_MEX_ASSERT0(mxIsChar(arg_in_0), "First argument must be a string");
    string cmd = mxArrayToString(arg_in_0);
    DO_CMD pfun = cmd_to_fun.at(cmd);
    pfun(nlhs, plhs, nrhs, prhs);
  }
  catch (exception const &e)
  {
    mexErrMsgTxt((string("mex_disk Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("mex_disk failed\n");
  }
}

///
/// eof: mex_disk.cc
///
