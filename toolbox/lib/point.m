%>
%> Class storing and managin geometrical entities
%>
%>
%>
classdef point < entity
  
  %properties (SetAccess = protected, Hidden = true)
  %  objectHandle; % Handle to the underlying C++ class instance
  %end

  methods
    function self = point( varargin )
    % 
      self.objectHandle = mex_point( 'new', varargin{:}  );
    end
    % --------------------------------------------------------------------
    %
    function delete( self )
      mex_point( 'delete', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = getX( self )
      P = mex_point( 'getX', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = getY( self )
      P = mex_point( 'getY', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = getZ( self )
      P = mex_point( 'getZ', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = get( self )
      P = mex_point( 'get', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function setX( self, varargin )
     mex_point( 'setX', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
        %>
    function setY( self, varargin )
     mex_point( 'setY', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
    %>
    function setZ( self, varargin )
     mex_point( 'setZ', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
    %>
    function set( self, varargin )
     mex_point( 'set', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
    %>
    function copy( self, other_obj )
     mex_point( 'copy', self.objectHandle, other_obj.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function translate( self, other_obj )
      mex_point( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function out_obj = transform( self, varargin )
      out_obj = point();
      out_obj.objectHandle = mex_point( 'transform', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
    %>
    function disp( self )
      disp(self.get());
    end
    % --------------------------------------------------------------------
    %>
    function plot( self, figure_name )
      figure_name;
      hold on;
      scatter3(self.get(), 'filled');
      hold off;
    end
    % --------------------------------------------------------------------
    % OVERRIDE
    % --------------------------------------------------------------------
    %>
    function P = type( self )
      P = 'point';
    end
  end
end
