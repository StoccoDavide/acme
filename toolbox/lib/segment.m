%>
%> Class storing and managin geometrical entities
%>
%>
%>
classdef segment < entity
  
  %properties (SetAccess = protected, Hidden = true)
  %  objectHandle; % Handle to the underlying C++ class instance
  %end

  methods
    function self = segment( varargin )
    % 
      self.objectHandle = mex_segment( 'new', varargin{:}  );
    end
    % --------------------------------------------------------------------
    %
    function delete( self )
      mex_segment( 'delete', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = getVertex1( self )
      P = point();
      P = mex_segment( 'getVertex1', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = getVertex2( self )
      P = point();
      P = mex_segment( 'getVertex2', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function setVertex1( self, other_obj )
      mex_segment( 'setVertex1', self.objectHandle, other_obj.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function setVertex2( self, other_obj )
      mex_segment( 'setVertex2', self.objectHandle, other_obj.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function translate( self, other_obj )
      mex_segment( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = transform( self, varargin )
      out_obj = segment();
      out_obj.objectHandle = mex_segment( 'transform', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
    %>
    function disp( self )
      v1 = self.getVertex1();
      %vertex2 = self.getVertex2();
      disp( v1.get() );
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
      P = 'segment';
    end
  end
end
