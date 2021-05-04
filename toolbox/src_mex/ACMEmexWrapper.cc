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

#define ASSERT(COND, MSG)                     \
  if (!(COND))                                \
  {                                           \
    std::ostringstream ost;                   \
    ost << "ACMEmexWrapper: " << MSG << '\n'; \
    mexErrMsgTxt(ost.str().c_str());          \
  }

#define MEX_ERROR_MESSAGE                                                      \
  "%======================================================================%\n" \
  "% ACMEmexWrapper: A small 3D computational geometry library.           %\n" \
  "%                                                                      %\n" \
  "% USAGE:                                                               %\n" \
  "%   obj = ACMEmexWrapper( 'new', kind [,args] );                       %\n" \
  "%   ACMEmexWrapper( 'delete', obj );                                   %\n" \
  "%   ACMEmexWrapper( 'setup', obj, kind [,args] );                      %\n" \
  "%   P           = ACMEmexWrapper( 'eval', obj, n, x );                 %\n" \
  "%   [P,Dp,sign] = ACMEmexWrapper( 'eval2', obj, n, x );                %\n" \
  "%   [PP,sign]   = ACMEmexWrapper( 'sequence', obj, x );                %\n" \
  "%                                                                      %\n" \
  "% On input:                                                            %\n" \
  "%                                                                      %\n" \
  "%  kind = string with the kind of polynomial any of:                   %\n" \
  "%         'line', 'ray', 'plane', 'segment', 'triangle', 'circle',     %\n" \
  "%         'box'                                                        %\n" \
  "%                                                                      %\n" \
  "%  args                                                                %\n" \
  "%     ''         : NONE                                                %\n" \
  "%     'line'     : origin (3D vector), direction (3D vector)           %\n" \
  "%     'ray'      : origin (3D vector), direction (3D vector)           %\n" \
  "%     'plane'    : origin (3D vector), normal (3D vector)              %\n" \
  "%     'segment'  : point (3D vector), point (3D vector)                %\n" \
  "%     'triangle' : point (3D vector), point (3D vector),               %\n" \
  "%                  point 3 (3D vector)                                 %\n" \
  "%     'circle'   : radius, center (3D vector), normal (3D vector)      %\n" \
  "%     'box'      : point (3D vector), point (3D vector)                %\n" \
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
  mxArray * & mx_id
) {
  acme::entity * ptr = new acme::entity();
  mx_id = convertPtr2Mat<acme::entity>(ptr);
}

static
inline
RubiksCube *
DATA_GET(
  mxArray const * & mx_id
) {
  return convertMat2Ptr<acme::entity>(mx_id);
}

static
void
DATA_DELETE(
  mxArray const *&mx_id
) {
  destroyObject<acme::entity>(mx_id);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static
void
do_new(int nlhs, mxArray *plhs[],
       int nrhs, mxArray const *prhs[])
{

#define CMD "ACMEmexWrapper( 'new', kind [, args] ): "
  MEX_ASSERT(nrhs >= 2, CMD "expected at least 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n');

  MEX_ASSERT(
      mxIsChar(arg_in_1),
      CMD << "second argument must be a string, found ``" << mxGetClassName(arg_in_1) << "''\n");

  string tname = mxArrayToString(arg_in_1);

  acme::entity *ptr = nullptr;

  if (tname == "none")
  {
    MEX_ASSERT(
        nrhs == 2,
        CMD "expected 2 inputs for none entity, nrhs = " << nrhs << '\n');
    ptr = new acme::none();
  }
  else if (tname == "line")
  {
    if (nrhs == 2)
    {
      ptr = new acme::line();
    }
    else if (nrhs == 4)
    {

      ptr = new acme::line();
    }
    else
    {
      MEX_ASSERT(
          false,
          CMD "expected 2 or 4 inputs for line entity, nrhs = " << nrhs << '\n');
    }
  }
  else if (tname == "ray")
  {
    ptr = new acme::ray();
  }
  else if (tname == "plane")
  {
    ptr = new acme::plane();
  }
  else if (tname == "segment")
  {
    ptr = new acme::segment();
  }
  else if (tname == "triangle")
  {
    ptr = new acme::triangle();
  }
  else if (tname == "circle")
  {
    ptr = new acme::circle();
  }
  else if (tname == "box")
  {
    ptr = new acme::box();
  }
  else
  {
    MEX_ASSERT(
        false,
        "Second argument must be one of the strings:\n"
        "'line', 'ray', 'plane', 'segment', 'triangle', 'circle', 'box'.");
  }

  DATA_NEW(arg_out_0, ptr);

#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static void
do_delete(int nlhs, mxArray *plhs[],
          int nrhs, mxArray const *prhs[])
{

#define CMD "ACMEmexWrapper( 'delete', OBJ ): "
  MEX_ASSERT(nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n');
  MEX_ASSERT(nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n');

  // Destroy the C++ object
  DATA_DELETE(arg_in_1);
#undef CMD
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef void (*DO_CMD)(int nlhs, mxArray *plhs[],
                       int nrhs, mxArray const *prhs[]);

static map<string, DO_CMD> cmd_to_fun = {
    {"new", do_new},
    {"delete", do_delete},
    {"isVector", do_isVector},
    {"isNone", do_isNone},
    {"isLine", do_isLine},
    {"isRay", do_isRay},
    {"isPlane", do_isPlane},
    {"isSegment", do_isSegment},
    {"isTriangle", do_isTriangle},
    {"isCircle", do_isCircle},
    {"degree", do_degree},
    {"whattype", do_whattype},
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
    mexErrMsgTxt((string("ACMEmexWrapper Error: ") + e.what()).c_str());
  }
  catch (...)
  {
    mexErrMsgTxt("ACMEmexWrapper failed\n");
  }
}
