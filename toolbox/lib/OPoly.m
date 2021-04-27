%>
%> Class storing and managin orthogonal polynomial
%>
%>
%>
classdef OPoly < handle

  properties (SetAccess = private, Hidden = true)
    objectHandle; % Handle to the underlying C++ class instance
  end

  methods

    function self = OPoly( varargin )
      % kind [, alpha, beta ]
      self.objectHandle = OPolyMexWrapper( 'new', varargin{:}  );
    end
    % --------------------------------------------------------------------
    %
    function delete(self)
      % Destroy the C++ class instance
      OPolyMexWrapper( 'delete', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    %> Evaluate the polynomial \f$ p_n(x) \f$ where  \f$ n \f$ is the
    %> degree of the polynomial. The value \f$ x \f$ can be a scalar
    %> a vector or a matrix. The result is of the same dimension of \f$ x \f$.
    %>
    function P = eval( self, n, x )
      P = OPolyMexWrapper( 'eval', self.objectHandle, n, x );
    end
    % --------------------------------------------------------------------
    %>
    %> Evaluate the polynomial \f$ p_n(x) \f$ and \f$ p'_n(x) \f$ 
    %> where \f$ n \f$ is the degree of the polynomial.
    %> Moreover a sign variation of the Sturm sequence associated
    %> to the recurrence is returned.
    %> The value \f$ x \f$ can be a scalar a vector or a matrix.
    %> The results are of the same dimension of \f$ x \f$.
    %>
    function [P,Dp,s] = eval2( self, n, x )
      [P,Dp,s] = OPolyMexWrapper( 'eval2', self.objectHandle, n, x );
    end
    % --------------------------------------------------------------------
    %>
    %> Evaluate the sequence \f$ p_0(x), p_1(x),\ldots, p_n(x) \f$.
    %> Moreover a sign variation of the Sturm sequence associated
    %> to the recurrence is returned.
    %> The value \f$ x \f$ can be a scalar a vector or a matrix.
    %> The results are of the same dimension of \f$ x \f$.
    %>
    %> If `x` is an `m x p` matrix then `PP` is an array of
    %> dimension `n x m x p`
    %>
    function [PP,s] = sequence( self, n, x )
      [PP,s] = OPolyMexWrapper( 'sequence', self.objectHandle, n, x );
    end
    % --------------------------------------------------------------------
    %>
    %> Evaluate all the zeros of the orthogonal polynomial \f$ p_n(x) \f$.
    %> 
    %> - `n` is the degree of the polynomial
    %> - `epsi` is the tolerance used in the computation of the zeros 
    %>
    function x = zeros( self, n, epsi )
      x = OPolyMexWrapper( 'zeros', self.objectHandle, n, epsi );
    end
    % --------------------------------------------------------------------
    %>
    %> Evaluate all nodes and weight of the Gauss-Legendre quadrature.
    %> The nodes are the zeros of the associated Legendre polynomial
    %> 
    %> - `n`    is the number of interpolation point
    %> - `epsi` is the tolerance used in the computation of
    %>   the zeros of the orthogonal polynomial 
    %>
    function [node,w] = gauss( self, n, epsi )
      [node,w] = OPolyMexWrapper( 'gauss', self.objectHandle, n, epsi );
    end
  end
end
