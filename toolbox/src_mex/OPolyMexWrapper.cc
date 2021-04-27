/****************************************************************************\
Copyright (c) 2021, Enrico Bertolazzi
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.
\****************************************************************************/

#include "opoly.hh"
#include "mex_utils.hh"

#define ASSERT(COND,MSG)                          \
  if ( !(COND) ) {                                \
    std::ostringstream ost;                       \
    ost << "OPolyMexWrapper: " << MSG << '\n';    \
    mexErrMsgTxt(ost.str().c_str());              \
  }

#define MEX_ERROR_MESSAGE \
"%======================================================================%\n" \
"% OPolyMexWrapper: Compute orthogonal polynomials                      %\n" \
"%                                                                      %\n" \
"% USAGE:                                                               %\n" \
"%   obj = OPolyMexWrapper( 'new', kind [,args] );                      %\n" \
"%   OPolyMexWrapper( 'delete', obj );                                  %\n" \
"%   OPolyMexWrapper( 'setup', obj, kind [,args] );                     %\n" \
"%   P           = OPolyMexWrapper( 'eval', obj, n, x );                %\n" \
"%   [P,Dp,sign] = OPolyMexWrapper( 'eval2', obj, n, x );               %\n" \
"%   [PP,sign]   = OPolyMexWrapper( 'sequence', obj, x );               %\n" \
"%                                                                      %\n" \
"% On input:                                                            %\n" \
"%                                                                      %\n" \
"%  kind = string with the kind of polynomial any of:                   %\n" \
"%         'jacobi', 'legendre', 'chebyshev', 'laguerre', 'hermite'     %\n" \
"%  args                                                                %\n" \
"%     'jacobi': alpha, beta                                            %\n" \
"%     'legendre', 'chebyshev', 'laguerre', 'hermite': NONE             %\n" \
"%                                                                      %\n" \
"%======================================================================%\n" \
"%                                                                      %\n" \
"%  Autor: Enrico Bertolazzi                                            %\n" \
"%         Department of Industrial Engineering                         %\n" \
"%         University of Trento                                         %\n" \
"%         enrico.bertolazzi@unitn.it                                   %\n" \
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


// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

static
void
do_new( int nlhs, mxArray       *plhs[],
        int nrhs, mxArray const *prhs[] ) {

  #define CMD "OPolyMexWrapper( 'new', kind [,args] ): "
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

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

static
void
do_setup( int nlhs, mxArray       *plhs[],
          int nrhs, mxArray const *prhs[] ) {

  #define CMD "OPolyMexWrapper( 'setup', OBJ, kind [,args] ): "
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

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

static
void
do_delete( int nlhs, mxArray       *plhs[],
           int nrhs, mxArray const *prhs[] ) {

  #define CMD "OPolyMexWrapper( 'delete', OBJ ): "
  MEX_ASSERT( nrhs == 2, CMD "expected 2 inputs, nrhs = " << nrhs << '\n' );
  MEX_ASSERT( nlhs == 0, CMD "expected 0 output, nlhs = " << nlhs << '\n' );

  // Destroy the C++ object
  DATA_DELETE(arg_in_1);
  #undef CMD
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

static
void
do_eval( int nlhs, mxArray       *plhs[],
         int nrhs, mxArray const *prhs[] ) {

  #define CMD "OPolyMexWrapper('eval',OBJ,n,x): "

  MEX_ASSERT( nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n' );
  MEX_ASSERT( nrhs == 4, CMD "expected 4 input, nrhs = " << nrhs << '\n' );

  opoly::poly<mwSize,double> * ptr = DATA_GET( arg_in_1 );

  mwSize n = mwSize( getInt( arg_in_2, CMD "expected scalar int for n" ) );

  mwSize nx, mx;
  real_type const * x = getMatrixPointer(
    arg_in_3, nx, mx, CMD "error in reading `x`"
  );
  real_type * p = createMatrixValue( arg_out_0, nx, mx );
  for ( mwSize j = 0; j < mx*nx; ++j )
    *p++ = (*ptr)( n, *x++ );

  #undef CMD
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

static
void
do_eval2( int nlhs, mxArray       *plhs[],
          int nrhs, mxArray const *prhs[] ) {

  #define CMD "OPolyMexWrapper('eval',OBJ,n,x): "

  MEX_ASSERT( nlhs == 3, CMD "expected 3 output, nlhs = " << nlhs << '\n' );
  MEX_ASSERT( nrhs == 4, CMD "expected 4 input, nrhs = " << nrhs << '\n' );

  opoly::poly<mwSize,double> * ptr = DATA_GET( arg_in_1 );

  mwSize n = mwSize( getInt( arg_in_2, CMD "expected scalar int for n" ) );

  mwSize nx, mx;
  real_type const * x = getMatrixPointer(
    arg_in_3, nx, mx, CMD "error in reading `x`"
  );
  real_type * p  = createMatrixValue( arg_out_0, nx, mx );
  real_type * dp = createMatrixValue( arg_out_1, nx, mx );
  real_type * s  = createMatrixValue( arg_out_2, nx, mx );
  for ( mwSize j = 0; j < mx*nx; ++j )
    *s++ = real_type( ptr->eval( n, *x++, *p++, *dp++ ) );

  #undef CMD
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

static
void
do_sequence( int nlhs, mxArray       *plhs[],
             int nrhs, mxArray const *prhs[] ) {

  #define CMD "OPolyMexWrapper('sequence',OBJ,n,x): "

  MEX_ASSERT( nlhs == 2, CMD "expected 2 output, nlhs = " << nlhs << '\n' );
  MEX_ASSERT( nrhs == 4, CMD "expected 4 input, nrhs = " << nrhs << '\n' );

  opoly::poly<mwSize,double> * ptr = DATA_GET( arg_in_1 );

  mwSize n = mwSize( getInt( arg_in_2, CMD "expected scalar int for n" ) );

  mwSize nx, mx;
  real_type const * x = getMatrixPointer(
    arg_in_3, nx, mx, CMD "error in reading `x`"
  );
  mwSize dims[3] = { n+1, nx, mx };
  real_type * p = createArray( arg_out_0, 3, dims );
  real_type * s = createMatrixValue( arg_out_1, nx, mx );
  for ( mwSize j = 0; j < mx*nx; ++j ) {
    *s++ = real_type( ptr->sequence( n, *x++, p ) );
    p += n+1;
  }

  #undef CMD
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

static
void
do_zeros( int nlhs, mxArray       *plhs[],
          int nrhs, mxArray const *prhs[] ) {

  #define CMD "OPolyMexWrapper('zeros',OBJ,n,epsi): "

  MEX_ASSERT( nlhs == 1, CMD "expected 1 output, nlhs = " << nlhs << '\n' );
  MEX_ASSERT( nrhs == 4, CMD "expected 4 input, nrhs = " << nrhs << '\n' );

  opoly::poly<mwSize,double> * ptr = DATA_GET( arg_in_1 );

  mwSize    n    = mwSize( getInt( arg_in_2, CMD "expected scalar int for n" ) );
  real_type epsi = getScalarValue( arg_in_3, CMD "expected scalar for epsi" );

  opoly::zeros<mwSize,double> Zeros( *ptr );

  real_type * x = createMatrixValue( arg_out_0, 1, n );

  Zeros.eval( n, epsi, x );

  #undef CMD
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

static
void
do_gauss( int nlhs, mxArray       *plhs[],
          int nrhs, mxArray const *prhs[] ) {

  #define CMD "OPolyMexWrapper('gauss',OBJ,n,epsi): "

  MEX_ASSERT( nlhs == 2, CMD "expected 2 output, nlhs = " << nlhs << '\n' );
  MEX_ASSERT( nrhs == 4, CMD "expected 4 input, nrhs = " << nrhs << '\n' );

  mwSize    n    = mwSize( getInt( arg_in_2, CMD "expected scalar int for n" ) );
  real_type epsi = getScalarValue( arg_in_3, CMD "expected scalar for epsi" );

  opoly::Gauss_quadrature<mwSize,double> Gauss;

  real_type * x = createMatrixValue( arg_out_0, 1, n );
  real_type * w = createMatrixValue( arg_out_1, 1, n );

  Gauss.eval( n, epsi, x, w );

  #undef CMD
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

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

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

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
    mexErrMsgTxt( ( string("OPolyMexWrapper Error: ") + e.what() ).c_str() );
  } catch (...) {
    mexErrMsgTxt("OPolyMexWrapper failed\n");
  }

}
