% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%                                                                     %
% The ACME project                                                    %
%                                                                     %
% Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       %
%                                                                     %
% The ACME project and its components are supplied under the terms of %
% the open source BSD 2-Clause License. The contents of the ACME      %
% project and its components may not be copied or disclosed except in %
% accordance with the terms of the BSD 2-Clause License.              %
%                                                                     %
% URL: https://opensource.org/licenses/BSD-2-Clause                   %
%                                                                     %
%    Davide Stocco                                                    %
%    Department of Industrial Engineering                             %
%    University of Trento                                             %
%    e-mail: davide.stocco@unitn.it                                   %
%                                                                     %
%    Enrico Bertolazzi                                                %
%    Department of Industrial Engineering                             %
%    University of Trento                                             %
%    e-mail: enrico.bertolazzi@unitn.it                               %
%                                                                     %
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

classdef acme_point < acme_entity
  
  %properties (SetAccess = protected, Hidden = true)
  %  objectHandle; % Handle to the underlying C++ class instance
  %end

  methods
    function self = acme_point( varargin )
      % Create C++ pointer to triangle object instance
      self.objectHandle = mex_point( 'new', varargin{:}  );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function delete( self )
      % Delete C++ pointer to triangle object instance
      mex_point( 'delete', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getX( self )
      % Get point X axis component
      P = mex_point( 'getX', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getY( self )
      % Get point Y axis component
      P = mex_point( 'getY', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getZ( self )
      % Get point Z axis component
      P = mex_point( 'getZ', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = get( self )
      % Get point axes components
      P = mex_point( 'get', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setX( self, varargin )
     % Set point X axis component
     mex_point( 'setX', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setY( self, varargin )
     % Set point Y axis component
     mex_point( 'setY', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setZ( self, varargin )
     % Get point Z axis component
     mex_point( 'setZ', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function set( self, varargin )
     % Set point axes components
     mex_point( 'set', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copy( self, other_obj )
      % Copy point object from another point
      if (other_obj.type() == "point")
        mex_point( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_point::copy(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function translate( self, other_obj )
      % Translate point by vector
      mex_point( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function transform( self, varargin )
      % Transform point by 4x4 affine transformation matrix
      mex_point( 'transform', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isParallel( self, other_obj )
      % Check if point is parallel to an ACME object
      P = mex_point( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isOrthogonal( self, other_obj )
      % Check if point is orthogonal to an ACME object
      P = mex_point( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCollinear( self, other_obj )
      % Check if point is collinear to an ACME object
      P = mex_point( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCoplanar( self, other_obj )
      % Check if point is coplanar to an ACME object 
      P = mex_point( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = intersection( self, other_obj )
      % Intersect point with an ACME object
      [Handle, type] = mex_point( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
      P = eval( strcat( 'acme_', type, '()' ) );
      P.objectHandle = Handle;
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function disp( self )
      % Display object data
      disp( self.get() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function plot( self, figure_name, color )
      % Plot point object
      figure_name;
      hold on;
      scatter3(self.getX(), self.getY(), self.getZ(), color, 'filled');
      hold off;
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = type( self )
      % Get object type as string
      P = 'point';
    end
  end
end
