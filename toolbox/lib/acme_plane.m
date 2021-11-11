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
    function this = acme_plane( varargin )
      this.objectHandle = mex_plane( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Delete C++ pointer to plane object instance
    function delete( this )
      mex_plane( 'delete', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get object type as string
    function out = type( this )
      out = 'plane';
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get plane origin as ACME point object
    function out = getOrigin( this )
      out = acme_point();
      out.copyByHandle( mex_plane( 'getOrigin', this.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get plane normal
    function out = getNormal( this )
      out = mex_plane( 'getNormal', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set plane origin with an ACME point object
    function setOrigin( this, other_obj )
      mex_plane( 'setOrigin', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set plane normal
    function setNormal( this, other_obj )
      mex_plane( 'setNormal', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy plane object from another plane
    function copy( this, other_obj )
      if (other_obj.type() == "plane")
        mex_plane( 'copy', this.objectHandle, other_obj.objectHandle );
      else
        error('mex_plane::copy(): other_obj must be an ACME plane object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy plane object from another plane handle
    function copyByHandle( this, handle )
      mex_plane( 'copy', this.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Translate plane by vector
    function translate( this, other_obj )
      mex_plane( 'translate', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform plane by 4x4 affine transformation matrix
    function transform( this, varargin )
      mex_plane( 'transform', this.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ACME point is inside the plane 
    function out = isInside( this, other_obj )
      if (other_obj.type() == "point")
        out = mex_plane( 'isInside', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is degenerated
    function out = isDegenerated( this )
      out = mex_plane( 'isDegenerated', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if planes are approximatively equal
    function out = isApprox( this, other_obj )
      if (other_obj.type() == "plane") 
        out = mex_plane( 'isApprox', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::isApprox(): other_obj must be an ACME plane object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Normalize normal vectoe
    function normalize( this )
      mex_plane( 'normalize', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Distance between an ACME point and plane
    function out = distance( this, other_obj )
      if (other_obj.type() == "point") 
        out = mex_plane( 'distance', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::distance(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Squared distance between an ACME point and plane
    function out = squaredDistance( this, other_obj )
      if (other_obj.type() == "point") 
        out = mex_plane( 'squaredDistance', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::squaredDistance(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Signed distance between an ACME point and plane
    function out = signedDistance( this, other_obj )
      if (other_obj.type() == "point") 
        out = mex_plane( 'signedDistance', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_plane::signedDistance(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform plane to normalized vector
    function out = toNormalizedVector( this )
      out = mex_plane( 'toNormalizedVector', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Swap plane vertices
    function reverse( this )
      mex_plane( 'reverse', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is parallel to an ACME object
    function out = isParallel( this, other_obj )
      out = mex_plane( 'isParallel', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is orthogonal to an ACME object
    function out = isOrthogonal( this, other_obj )
      out = mex_plane( 'isOrthogonal', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is colplanear to an ACME object
    function out = isColplanear( this, other_obj )
      out = mex_plane( 'isColplanear', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if plane is coplanar to an ACME object 
    function out = isCoplanar( this, other_obj )
      out = mex_plane( 'isCoplanar', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Intersect plane with an ACME object
    function out = intersection( this, other_obj )
      [handle, type] = mex_plane( 'intersection', this.objectHandle, other_obj.objectHandle, other_obj.type() );
      out = eval( strcat( 'acme_', type, '()' ) );
      out.copyByHandle( handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Display object data
    function disp( this )
      disp( [this.getOrigin().get(), this.getNormal()] );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Plot plane object
    function plot( this, figure_name, color )
      figure_name;
      hold on;
      origin = this.getOrigin().get();
      normal = this.getNormal();
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
