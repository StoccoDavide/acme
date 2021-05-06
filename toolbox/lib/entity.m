%>
%> Class storing and managin geometrical entities
%>
%>
%>
classdef entity < handle
  
  properties (SetAccess = protected, Hidden = true)
    objectHandle; % Handle to the underlying C++ class instance
  end
 
  methods
    function self = entity( )
    end
  end
  
  methods (Access = protected)
    function copyHandle( self, other_obj )
       self.objectHandle = other_obj.objectHandle;
    end
  end

  methods (Abstract)
    % --------------------------------------------------------------------
    %>
    type( self )
  end
end