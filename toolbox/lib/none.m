%>
%> Class storing and managin geometrical entities
%>
%>
%>
classdef none < entity

  methods
    function self = none( self )
    % 
      self.objectHandle = mex_none( 'new' );
    end
    % --------------------------------------------------------------------
    %
    function delete( self )
      % Destroy the C++ class instance
      mex_none( 'delete', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function disp( self )
      disp('none');
    end
    % --------------------------------------------------------------------
    %>
    function plot( self, figure_name )
      figure_name;
      hold on;
      hold off;
    end
    % --------------------------------------------------------------------
    % OVERRIDE
    %--------------------------------------------------------------------
    %>
    function P = type( self )
      P = 'none';
    end
  end
end
