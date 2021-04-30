%>
%> Class storing and managin geometrical entities
%>
%>
%>
classdef acme < handle

  properties (SetAccess = private, Hidden = true)
    objectHandle; % Handle to the underlying C++ class instance
  end

  methods

    function self = acme( varargin )
      % 
      self.objectHandle = ACMEmexWrapper( 'new', varargin{:}  );
    end
    % --------------------------------------------------------------------
    %
    function delete(self)
      % Destroy the C++ class instance
      ACMEmexWrapper( 'delete', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = isVector( self )
      P = ACMEmexWrapper( 'isVector', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = isLine( self )
      P = ACMEmexWrapper( 'isLine', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = isRay( self )
      P = ACMEmexWrapper( 'isRay', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = isPlane( self, other_obj )
      P = ACMEmexWrapper( 'isPlane', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = isSegment( self )
      P = ACMEmexWrapper( 'isSegment', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = isTriangle( self )
      P = ACMEmexWrapper( 'isTriangle', self.objectHandle );
    end
    % --------------------------------------------------------------------   
    %>
    function P = isCircle( self )
      P = ACMEmexWrapper( 'isCircle', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = whatType( self )
      P = ACMEmexWrapper( 'whatType', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = isParallel( self, other_obj )
      P = ACMEmexWrapper( 'isParallel', self.objectHandle, other_obj );
    end
    % --------------------------------------------------------------------
    %>
    function P = isOrthogonal( self, other_obj )
      P = ACMEmexWrapper( 'isOrthogonal', self.objectHandle, other_obj );
    end
    % --------------------------------------------------------------------
    %>
    function P = isCollinear( self, other_obj )
      P = ACMEmexWrapper( 'isCollinear', self.objectHandle, other_obj );
    end
    % --------------------------------------------------------------------
    %>
    function P = isCoplanar( self, other_obj )
      P = ACMEmexWrapper( 'isCoplanar', self.objectHandle, other_obj );
    end
    % --------------------------------------------------------------------
    %>
    function P = intersection( self, other_obj, resulting_obj )
      P = ACMEmexWrapper( 'intersection', self.objectHandle, resulting_obj );
    end
    % --------------------------------------------------------------------
    %>
    function P = collision( self, other_obj )
      P = ACMEmexWrapper( 'collision', self.objectHandle, other_obj );
    end
    % --------------------------------------------------------------------
    %>
    function translate( self, translation )
      ACMEmexWrapper( 'collision', self.objectHandle, translation );
    end
    % --------------------------------------------------------------------
    %>
    function transform( self, affine )
      ACMEmexWrapper( 'collision', self.objectHandle, affine );
    end
    % --------------------------------------------------------------------
    %>

  end
end
