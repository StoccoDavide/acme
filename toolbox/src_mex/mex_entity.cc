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

#include "acme_entity.hh"
#include "mex_utils.hh"

#define ASSERT(COND, MSG)                 \
  if (!(COND))                            \
  {                                       \
    std::ostringstream ost;               \
    ost << "mex_entity: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());      \
  }

#define MEX_ERROR_MESSAGE                                                      \
  "%======================================================================%\n" \
  "% mex_entity: Mex wrapper for ACME entity object.                      %\n" \
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

static inline acme::entity *
DATA_GET(
    mxArray const *&mx_id)
{
  return convertMat2Ptr<acme::entity>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_isNone(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{

#define CMD "mex_entity( 'isNone', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  acme::entity *self = DATA_GET(arg_in_1);
  setScalarBool(arg_out_0, self->isNone());
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef void (*DO_CMD)(int nlhs, mxArray *plhs[],
                       int nrhs, mxArray const *prhs[]);

static map<string, DO_CMD> cmd_to_fun = {
    {"isNone", do_isNone}};

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
    mexErrMsgTxt((string("mex_entity Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("mex_entity failed\n");
  }
}
