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

classdef acme_ray < acme_entity
  %
  % Class container for ACME ray object
  %
  methods
    function self = acme_ray( varargin )
      % Create a new C++ pointer to ray object instance
      self.objectHandle = mex_ray( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function delete( self )
      % Delete C++ pointer to ray object instance
      mex_ray( 'delete', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getOrigin( self )
      % Get ray origin as ACME point object
      P = acme_point();
      P.objectHandle = mex_ray( 'getOrigin', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getDirection( self )
      % Get ray direction
      P = mex_ray( 'getDirection', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setOrigin( self, other_obj )
      % Set ray origin with an ACME point object
      mex_ray( 'setOrigin', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setDirection( self, other_obj )
      % Set ray direction
      mex_ray( 'setDirection', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copy( self, other_obj )
      % Copy ray object from another ray
      if (other_obj.type() == "ray")
        mex_ray( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_ray::copy(): other_obj must be an ACME ray object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function translate( self, other_obj )
     % Translate ray by vector
      mex_ray( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = transform( self, varargin )
      % Transform ray by 4x4 affine transformation matrix
      P = ray();
      P.objectHandle = mex_ray( 'transform', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isInside( self, other_obj )
      % Check if ACME point is inside the ray 
      if (other_obj.type() == "point")
        P = mex_ray( 'isInside', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_ray::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isDegenerated( self )
      % Check if ray is degenerated
      P = mex_ray( 'isDegenerated', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isApprox( self, other_obj )
      % Check if rays are approximatively equal
      if (other_obj.type() == "ray") 
        P = mex_ray( 'isApprox', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_ray::isApprox(): other_obj must be an ACME ray object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function normalize( self )
      % 
      mex_ray( 'normalize', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = toVector( self )
       % Transform ray to vector
      P = mex_ray( 'toVector', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = toNormalizedVector( self )
      % Transform ray to normalized vector
      P = mex_ray( 'toNormalizedVector', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function reverse( self )
      % Swap ray vertices
      mex_ray( 'reverse', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isParallel( self, other_obj )
      % Check if ray is parallel to an ACME object
      P = mex_ray( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isOrthogonal( self, other_obj )
      % Check if ray is orthogonal to an ACME object
      P = mex_ray( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCollinear( self, other_obj )
      % Check if ray is collinear to an ACME object
      P = mex_ray( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCoplanar( self, other_obj )
      % Check if ray is coplanar to an ACME object 
      P = mex_ray( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = intersection( self, other_obj )
      % Intersect ray with an ACME object
      [Handle, type] = mex_ray( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
      P = eval( strcat( 'acme_', type, '()' ) );
      P.objectHandle = Handle;
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function disp( self )
      % Display object data
      disp( [self.getOrigin().get(), self.getDirection()] );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function plot( self, figure_name, color )
      % Plot ray object
      figure_name;
      hold on;
      origin = self.getOrigin().get();
      direction = self.getDirection();
      xt = @(t) origin(1) + t*direction(1);
      yt = @(t) origin(2) + t*direction(2);
      zt = @(t) origin(3) + t*direction(3);
      fplot3(xt,yt,zt, [0 ~], color)
      hold off;
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = type( self )
      % Get object type as string
      P = 'ray';
    end
  end
end
