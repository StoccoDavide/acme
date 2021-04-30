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


#include "acme_entity.hh"
#include "mex_utils.hh"

#define ASSERT(COND,MSG)                          \
  if ( !(COND) ) {                                \
    std::ostringstream ost;                       \
    ost << "ACMEmexWrapper: " << MSG << '\n';     \
    mexErrMsgTxt(ost.str().c_str());              \
  }

#define MEX_ERROR_MESSAGE \
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
"%         'line', 'ray', 'plane', 'segment', 'triangle', 'circle'      %\n" \
"%  args                                                                %\n" \
"%     ''         : NONE                                                %\n" \
"%     'line'     : origin, direction                                   %\n" \
"%     'ray'      : origin, direction                                   %\n" \
"%     'plane'    : origin, normal                                      %\n" \
"%     'segment'  : point 1, point 2                                    %\n" \
"%     'triangle' : point 1, point 2, point 3                           %\n" \
"%     'circle'   : radius, center, normal                              %\n" \
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
DATA_NEW( mxArray * & mx_id, opoly::poly<mwSize,double> * ptr ) {
  mx_id = convertPtr2Mat<opoly::poly<mwSize,double> >(ptr);
}

static
inline
opoly::poly<mwSize,double> *
DATA_GET( mxArray const * & mx_id ) {
  return convertMat2Ptr<opoly::poly<mwSize,double> >(mx_id);
}

static
void
DATA_DELETE( mxArray const * & mx_id ) {
  destroyObject<opoly::poly<mwSize,double> >(mx_id);
}


  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static
void
do_new( int nlhs, mxArray       *plhs[],
        int nrhs, mxArray const *prhs[] ) {

  #define CMD "ACMEmexWrapper( 'new', kind [,args] ): "
  MEX_ASSERT( nrhs >= 2, CMD "expected at least 2 inputs, nrhs = " << nrhs << '\n' );
  MEX_ASSERT( nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n' );

  MEX_ASSERT(
    mxIsChar(arg_in_1),
    CMD << "second argument must be a string, found ``" <<
    mxGetClassName(arg_in_1) << "''\n"
  );

  string tname = mxArrayToString(arg_in_1);

  opoly::poly<mwSize,double> * ptr = nullptr;

  if ( tname == "jacobi" ) {
    MEX_ASSERT( nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n' );
    real_type alpha = getScalarValue( arg_in_2, CMD "expected scalar for alpha");
    real_type beta  = getScalarValue( arg_in_3, CMD "expected scalar for beta");
    ptr = new opoly::Jacobi<mwSize,double>( alpha, beta );
  }
  else if ( tname == "legendre"  ) ptr = new opoly::Legendre<mwSize,double>();
  else if ( tname == "chebyshev" ) ptr = new opoly::Chebyshev<mwSize,double>();
  else if ( tname == "laguerre"  ) {
    MEX_ASSERT( nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n' );
    real_type alpha = getScalarValue( arg_in_2, CMD "expected scalar for alpha");
    ptr = new opoly::Laguerre<mwSize,double>( alpha );
  }
  else if ( tname == "hermite"   ) ptr = new opoly::Hermite<mwSize,double>();
  else {
    MEX_ASSERT(
      false,
      "Second argument must be one of the strings:\n"
      "'jacobi', 'legendre', 'chebyshev', 'laguerre', 'hermite'"
    );
  }

  DATA_NEW( arg_out_0, ptr );

  #undef CMD
}

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static
void
do_setup( int nlhs, mxArray       *plhs[],
          int nrhs, mxArray const *prhs[] ) {

  #define CMD "ACMEmexWrapper( 'setup', OBJ, kind [,args] ): "
  MEX_ASSERT( nrhs >= 3, CMD << "expected at least 3 inputs, nrhs = " << nrhs << '\n' );
  MEX_ASSERT( nlhs == 1, CMD << "expected 1 output, nlhs = " << nlhs << '\n' );

  MEX_ASSERT(
    mxIsChar(arg_in_1),
    CMD "second argument must be a string, found ``" <<
    mxGetClassName(arg_in_1) << "''\n"
  );

  string tname = mxArrayToString(arg_in_1);

  DATA_DELETE(arg_in_1);

  opoly::poly<mwSize,double> * ptr = nullptr;

  if ( tname == "jacobi" ) {
    MEX_ASSERT( nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n' );
    real_type alpha = getScalarValue( arg_in_2, CMD "expected scalar for alpha" );
    real_type beta  = getScalarValue( arg_in_3, CMD "expected scalar for beta" );
    ptr = new opoly::Jacobi<mwSize,double>( alpha, beta );
  }
  else if ( tname == "legendre"  ) ptr = new opoly::Legendre<mwSize,double>();
  else if ( tname == "chebyshev" ) ptr = new opoly::Chebyshev<mwSize,double>();
  else if ( tname == "laguerre"  ) {
    MEX_ASSERT( nrhs == 4, CMD "expected 4 inputs, nrhs = " << nrhs << '\n' );
    real_type alpha = getScalarValue( arg_in_2, CMD "expected scalar for alpha");
    ptr = new opoly::Laguerre<mwSize,double>( alpha );
  }
  else if ( tname == "hermite"   ) ptr = new opoly::Hermite<mwSize,double>();
  else {
    MEX_ASSERT(
      false,
      "Second argument must be one of the strings:\n"
      "'jacobi', 'legendre', 'chebyshev', 'laguerre', 'hermite'"
    );
  }

  DATA_NEW( arg_out_0, ptr );

  #undef CMD
}

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static
void
do_delete( int nlhs, mxArray       *plhs[],
           int nrhs, mxArray const *prhs[] ) {

  #define CMD "ACMEmexWrapper( 'delete', OBJ ): "
  MEX_ASSERT( nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n' );
  MEX_ASSERT( nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n' );

  // Destroy the C++ object
  DATA_DELETE(arg_in_1);
  #undef CMD
}

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef void (*DO_CMD)( int nlhs, mxArray *plhs[], int nrhs, mxArray const *prhs[] );

static map<string,DO_CMD> cmd_to_fun = {
  {"new",do_new},
  {"delete",do_delete},
  {"setup",do_setup},
  {"eval",do_eval},
  {"eval2",do_eval2},
  {"sequence",do_sequence},
  {"zeros",do_zeros},
  {"gauss",do_gauss}
};

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

extern "C"
void
mexFunction( int nlhs, mxArray       *plhs[],
             int nrhs, mxArray const *prhs[] ) {
  // the first argument must be a string
  if ( nrhs == 0 ) {
    mexErrMsgTxt(MEX_ERROR_MESSAGE);
    return;
  }

  try {
    MEX_ASSERT( mxIsChar(arg_in_0), "First argument must be a string" );
    string cmd = mxArrayToString(arg_in_0);
    DO_CMD pfun = cmd_to_fun.at(cmd);
    pfun( nlhs, plhs, nrhs, prhs );
  } catch ( exception const & e ) {
    mexErrMsgTxt( ( string("ACMEmexWrapper Error: ") + e.what() ).c_str() );
  } catch (...) {
    mexErrMsgTxt("ACMEmexWrapper failed\n");
  }

}
