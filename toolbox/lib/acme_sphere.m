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

classdef acme_sphere < acme_entity
  %
  % Class container for ACME sphere object
  %
  methods
    function self = acme_sphere( varargin )
      % Create a new C++ pointer to sphere object instance
      self.objectHandle = mex_sphere( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function delete( self )
      % Create C++ pointer to sphere object instance
      mex_sphere( 'delete', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getRadius( self )
      % Get sphere radius
      out = mex_sphere( 'getRadius', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getCenter( self )
      % Get sphere center as ACME point object
      out = acme_point();
      out.copyByHandle( mex_sphere( 'getCenter', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setRadius( self, radius )
      % Set sphere radius
      mex_sphere( 'setRadius', self.objectHandle, radius );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setCenter( self, other_obj )
      % Set sphere center with an ACME point object
      mex_sphere( 'setCenter', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copy( self, other_obj )
      % Copy segment object from another segment
      if (other_obj.type() == "sphere")
        mex_sphere( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_sphere::copy(): other_obj must be an ACME sphere object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copyByHandle( self, handle )
      % Copy sphere object from another sphere handle
      mex_sphere( 'copy', self.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function translate( self, other_obj )
     % Translate sphere by vector
      mex_sphere( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function transform( self, affine )
      % Transform sphere by 4x4 affine transformation matrix
      mex_sphere( 'transform', self.objectHandle, affine );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isInside( self, other_obj )
      % Check if ACME point is inside the sphere 
      if (other_obj.type() == "point")
        out = mex_sphere( 'isInside', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_sphere::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isDegenerated( self )
      % Check if sphere is degenerated
      out = mex_sphere( 'isDegenerated', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isApprox( self, other_obj )
      % Check if spheres are approximatively equal
      if (other_obj.type() == "sphere") 
        out = mex_sphere( 'isApprox', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_sphere::isApprox(): other_obj must be an ACME sphere object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = clamp( self )
      % Get sphere minimum bounding box as ACME aabb object instance
      out = acme_aabb();
      out.copyByHandle( mex_sphere( 'clamp', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = area( self )
      % Get sphere perimeter
      out = mex_sphere( 'area', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = volume( self )
      % Get sphere volume
      out = mex_sphere( 'volume', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isParallel( self, other_obj )
      % Check if sphere is parallel to an ACME object
      out = mex_sphere( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isOrthogonal( self, other_obj )
      % Check if sphere is orthogonal to an ACME object
      out = mex_sphere( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isCollinear( self, other_obj )
      % Check if sphere is collinear to an ACME object
      out = mex_sphere( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isCoplanar( self, other_obj )
      % Check if sphere is coplanar to an ACME object 
      out = mex_sphere( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = intersection( self, other_obj )
      % Intersect sphere with an ACME object
      [handle, type] = mex_sphere( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
      out = eval( strcat( 'acme_', type, '()') );
      out.copyByHandle( handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function disp( self )
      % Display object data
      disp( [ [self.getRadius(), NaN, NaN]', self.getCenter().get()] ); %[self.getRadius() 0 0]',
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function plot( self, figure_name, color )
      % Plot sphere object
      figure_name;
      hold on;
      radius = self.getRadius();
      center = self.getCenter().get();
      [X_u,Y_u,Z_u] = sphere;
      X = X_u * radius;
      Y = Y_u * radius;
      Z = Z_u * radius;
      surface = surf(X+center(1),Y+center(2),Z+center(3));
      surface.FaceColor = color;
      surface.EdgeColor = color;
      surface.FaceAlpha = 0.5;
      hold off;
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = type( self )
      % Get object type as string
      out = 'sphere';
    end
  end
end
