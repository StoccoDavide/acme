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

#include "mex_utils.hh"
#include "acme_entity.hh"
#include "acme_none.hh"

#define ASSERT(COND, MSG)                     \
  if (!(COND))                                \
  {                                           \
    std::ostringstream ost;                   \
    ost << "mex_none: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());          \
  }

#define MEX_ERROR_MESSAGE                                                      \
  "%======================================================================%\n" \
  "% mex_point: MEx wrapper for ACME none object.                         %\n" \
  "%                                                                      %\n" \
  "% CONSTRUCTOR:                                                         %\n" \
  "%   obj = mex_none( 'new' );                                           %\n" \
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

static
void
DATA_NEW(
  mxArray * & mx_id,
  acme::none * ptr
) {
  mx_id = convertPtr2Mat<acme::none>(ptr);
}

static
inline
acme::none *
DATA_GET(
  mxArray const * & mx_id
) {
  return convertMat2Ptr<acme::none>(mx_id);
}

static
void
DATA_DELETE(
  mxArray const *&mx_id
) {
  destroyObject<acme::none>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static
void
do_new(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{

#define CMD "mex_none( 'new' ): "
  MEX_ASSERT(nrhs == 1, CMD "expected 1 input, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  MEX_ASSERT(
      mxIsChar(arg_in_0),
      CMD << "first argument must be a string, found ``" << mxGetClassName(arg_in_0) << "''\n");
  string tname = mxArrayToString(arg_in_0);

  acme::none *ptr = new acme::none();
  DATA_NEW(arg_out_0, ptr);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_delete(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{

#define CMD "mex_none( 'delete', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  DATA_DELETE(arg_in_1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef void (*DO_CMD)(int nlhs, mxArray *plhs[],
                       int nrhs, mxArray const *prhs[]);

static map<string, DO_CMD> cmd_to_fun = {
    {"new", do_new},
    {"delete", do_delete}
};

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
    mexErrMsgTxt((string("mex_none Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("mex_none failed\n");
  }
}
