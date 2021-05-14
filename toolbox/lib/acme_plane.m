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

classdef acme_plane < acme_entity
  %
  % Class container for ACME plane object
  %
  methods
    function self = acme_plane( varargin )
      % Create a new C++ pointer to plane object instance
      self.objectHandle = mex_plane( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function delete( self )
      % Delete C++ pointer to plane object instance
      mex_plane( 'delete', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = type( self )
      % Get object type as string
      out = 'plane';
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getOrigin( self )
      % Get plane origin as ACME point object
      out = acme_point();
      out.copyByHandle( mex_plane( 'getOrigin', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getNormal( self )
      % Get plane normal
      out = mex_plane( 'getNormal', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setOrigin( self, other_obj )
      % Set plane origin with an ACME point object
      mex_plane( 'setOrigin', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setNormal( self, other_obj )
      % Set plane normal
      mex_plane( 'setNormal', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copy( self, other_obj )
      % Copy plane object from another plane
      if (other_obj.type() == "plane")
        mex_plane( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_plane::copy(): other_obj must be an ACME plane object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copyByHandle( self, handle )
      % Copy plane object from another plane handle
      mex_plane( 'copy', self.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function translate( self, other_obj )
     % Translate plane by vector
      mex_plane( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function transform( self, varargin )
      % Transform plane by 4x4 affine transformation matrix
      mex_plane( 'transform', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isInside( self, other_obj )
      % Check if ACME point is inside the plane 
      if (other_obj.type() == "point")
        out = mex_plane( 'isInside', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isDegenerated( self )
      % Check if plane is degenerated
      out = mex_plane( 'isDegenerated', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isApprox( self, other_obj )
      % Check if planes are approximatively equal
      if (other_obj.type() == "plane") 
        out = mex_plane( 'isApprox', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::isApprox(): other_obj must be an ACME plane object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function normalize( self )
      % 
      mex_plane( 'normalize', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = distance( self, other_obj )
      % Distance between an ACME point and plane
      if (other_obj.type() == "point") 
        out = mex_plane( 'distance', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::distance(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = squaredDistance( self, other_obj )
      % Squared distance between an ACME point and plane
      if (other_obj.type() == "point") 
        out = mex_plane( 'squaredDistance', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::squaredDistance(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = signedDistance( self, other_obj )
      % Signed distance between an ACME point and plane
      if (other_obj.type() == "point") 
        out = mex_plane( 'signedDistance', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::signedDistance(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = toNormalizedVector( self )
      % Transform plane to normalized vector
      out = mex_plane( 'toNormalizedVector', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function reverse( self )
      % Swap plane vertices
      mex_plane( 'reverse', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isParallel( self, other_obj )
      % Check if plane is parallel to an ACME object
      out = mex_plane( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isOrthogonal( self, other_obj )
      % Check if plane is orthogonal to an ACME object
      out = mex_plane( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isColplanear( self, other_obj )
      % Check if plane is colplanear to an ACME object
      out = mex_plane( 'isColplanear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isCoplanar( self, other_obj )
      % Check if plane is coplanar to an ACME object 
      out = mex_plane( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = intersection( self, other_obj )
      % Intersect plane with an ACME object
      [handle, type] = mex_plane( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
      out = eval( strcat( 'acme_', type, '()' ) );
      out.copyByHandle( handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function disp( self )
      % Display object data
      disp( [self.getOrigin().get(), self.getNormal()] );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function plot( self, figure_name, color )
      % Plot plane object
      figure_name;
      hold on;
      origin = self.getOrigin().get();
      normal = self.getNormal();
      % Find two orthonormal vectors orthogonal to plane normal
      w = null(normal');
      limit = 4;
      [P,Q] = meshgrid(-limit:2*limit:limit);
      X = origin(1) + w(1,1)*P + w(1,2)*Q;
      Y = origin(2) + w(2,1)*P + w(2,2)*Q;
      Z = origin(3) + w(3,1)*P + w(3,2)*Q;
      s = surf( X, Y, Z, 'FaceAlpha', 0.5);
      s.FaceColor = color;
      s.EdgeColor = 'none';
      hold off;
    end
  end
end
