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
  %>
  %> Class container for ACME plane object
  %>
  methods
    %> Create a new C++ pointer to plane object instance
    function self = acme_plane( varargin )
      self.objectHandle = mex_plane( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Delete C++ pointer to plane object instance
    function delete( self )
      mex_plane( 'delete', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get object type as string
    function out = type( self )
      out = 'plane';
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get plane origin as ACME point object
    function out = getOrigin( self )
      out = acme_point();
      out.copyByHandle( mex_plane( 'getOrigin', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get plane normal
    function out = getNormal( self )
      out = mex_plane( 'getNormal', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set plane origin with an ACME point object
    function setOrigin( self, other_obj )
      mex_plane( 'setOrigin', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set plane normal
    function setNormal( self, other_obj )
      mex_plane( 'setNormal', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy plane object from another plane
    function copy( self, other_obj )
      if (other_obj.type() == "plane")
        mex_plane( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_plane::copy(): other_obj must be an ACME plane object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy plane object from another plane handle
    function copyByHandle( self, handle )
      mex_plane( 'copy', self.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Translate plane by vector
    function translate( self, other_obj )
      mex_plane( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform plane by 4x4 affine transformation matrix
    function transform( self, varargin )
      mex_plane( 'transform', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ACME point is inside the plane 
    function out = isInside( self, other_obj )
      if (other_obj.type() == "point")
        out = mex_plane( 'isInside', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is degenerated
    function out = isDegenerated( self )
      out = mex_plane( 'isDegenerated', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if planes are approximatively equal
    function out = isApprox( self, other_obj )
      if (other_obj.type() == "plane") 
        out = mex_plane( 'isApprox', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::isApprox(): other_obj must be an ACME plane object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Normalize normal vectoe
    function normalize( self )
      mex_plane( 'normalize', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Distance between an ACME point and plane
    function out = distance( self, other_obj )
      if (other_obj.type() == "point") 
        out = mex_plane( 'distance', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::distance(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Squared distance between an ACME point and plane
    function out = squaredDistance( self, other_obj )
      if (other_obj.type() == "point") 
        out = mex_plane( 'squaredDistance', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::squaredDistance(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Signed distance between an ACME point and plane
    function out = signedDistance( self, other_obj )
      if (other_obj.type() == "point") 
        out = mex_plane( 'signedDistance', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::signedDistance(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform plane to normalized vector
    function out = toNormalizedVector( self )
      out = mex_plane( 'toNormalizedVector', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Swap plane vertices
    function reverse( self )
      mex_plane( 'reverse', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is parallel to an ACME object
    function out = isParallel( self, other_obj )
      out = mex_plane( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is orthogonal to an ACME object
    function out = isOrthogonal( self, other_obj )
      out = mex_plane( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is colplanear to an ACME object
    function out = isColplanear( self, other_obj )
      out = mex_plane( 'isColplanear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is coplanar to an ACME object 
    function out = isCoplanar( self, other_obj )
      out = mex_plane( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Intersect plane with an ACME object
    function out = intersection( self, other_obj )
      [handle, type] = mex_plane( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
      out = eval( strcat( 'acme_', type, '()' ) );
      out.copyByHandle( handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Display object data
    function disp( self )
      disp( [self.getOrigin().get(), self.getNormal()] );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Plot plane object
    function plot( self, figure_name, color )
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
