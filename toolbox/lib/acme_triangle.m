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

classdef acme_triangle < acme_entity
  %
  % Class container for ACME triangle object
  %
  methods
    function self = acme_triangle( varargin )
      % Create a new C++ pointer to triangle object instance
      self.objectHandle = mex_triangle( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function delete( self )
      % Create C++ pointer to triangle object instance
      mex_triangle( 'delete', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getVertex1( self )
      % Get triangle vertex 1 as ACME point object
      out = acme_point();
      out.copyByHandle( mex_triangle( 'getVertex1', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getVertex2( self )
      % Get triangle vertex 2 as ACME point object
      out = acme_point();
      out.copyByHandle( mex_triangle( 'getVertex2', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getVertex3( self )
      % Get triangle vertex 3 as ACME point object
      out = acme_point();
      out.copyByHandle( mex_triangle( 'getVertex3', self.objectHandle) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setVertex1( self, other_obj )
      % Set triangle vertex 1 with an ACME point object
      mex_triangle( 'setVertex1', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setVertex2( self, other_obj )
      % Set triangle vertex 2 with an ACME point object
      mex_triangle( 'setVertex2', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setVertex3( self, other_obj )
      % Set triangle vertex 3 with an ACME point object
      mex_triangle( 'setVertex3', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copy( self, other_obj )
      % Copy segment object from another segment
      if (other_obj.type() == "triangle")
        mex_triangle( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_triangle::copy(): other_obj must be an ACME triangle object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copyByHandle( self, handle )
      % Copy triangle object from another triangle handle
      mex_triangle( 'copy', self.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function translate( self, other_obj )
     % Translate triangle by vector
      mex_triangle( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function transform( self, varargin )
      % Transform triangle by 4x4 affine transformation matrix
      mex_triangle( 'transform', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isInside( self, other_obj )
      % Check if ACME point is inside the triangle 
      if (other_obj.type() == "point")
        out = mex_triangle( 'isInside', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_triangle::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isDegenerated( self )
      % Check if triangle is degenerated
      out = mex_triangle( 'isDegenerated', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isApprox( self, other_obj )
      % Check if triangles are approximatively equal
      if (other_obj.type() == "triangle") 
        out = mex_triangle( 'isApprox', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_triangle::isApprox(): other_obj must be an ACME triangle object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = centroid( self )
      % Get triangle centroid as ACME point objecty instance
      out = acme_point();
      out.copyByHandle( mex_triangle( 'centroid', self.objectHandle, other_obj.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = normal( self )
      % Get triangle normal
      out = mex_triangle( 'normal', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = layingPlane( self )
     % Get triangle laying plane
     out = acme_plane();
     out.copyByHandle( mex_triangle( 'layingPlane', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = edge( self, i )
      % Get triangle i-th edge
      out = acme_segment();
      out.copyByHandle( mex_triangle( 'edge', self.objectHandle, i ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function swap( self, i, j )
      % Swap triangle i-th and j-th vertex
      mex_triangle( 'swap', self.objectHandle, i, j );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = clamp( self )
      % Get triangle minimum bounding box as ACME aabb object instance
      out = acme_aabb();
      out.copyByHandle( mex_triangle( 'clamp', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = perimeter( self )
      % Get triangle perimeter
      out = mex_triangle( 'perimeter', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = area( self )
      % Get triangle perimeter
      out = mex_triangle( 'area', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = barycentric( self, other_obj )
      % Compute barycentric coordinates (u,v,w) for ACME point
      if ( other_obj == "point" )
        out = mex_triangle( 'barycenter', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_triangle::barycentric(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isParallel( self, other_obj )
      % Check if triangle is parallel to an ACME object
      out = mex_triangle( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isOrthogonal( self, other_obj )
      % Check if triangle is orthogonal to an ACME object
      out = mex_triangle( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isCollinear( self, other_obj )
      % Check if triangle is collinear to an ACME object
      out = mex_triangle( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isCoplanar( self, other_obj )
      % Check if triangle is coplanar to an ACME object 
      out = mex_triangle( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = intersection( self, other_obj )
      % Intersect triangle with an ACME object
      [handle, type] = mex_triangle( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
      out = eval( strcat( 'acme_', type, '()' ) );
      out.copyByHandle( handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function disp( self )
      % Display object data
      disp( [self.getVertex1().get(), self.getVertex2().get(),  self.getVertex3().get()] );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function plot( self, figure_name, color )
      % Plot triangle object
      figure_name;
      hold on;
      Vertex1 = self.getVertex1().get();
      Vertex2 = self.getVertex2().get();
      Vertex3 = self.getVertex3().get();
      X = [Vertex1(1), Vertex2(1), Vertex3(1)];
      Y = [Vertex1(2), Vertex2(2), Vertex3(2)];
      Z = [Vertex1(3), Vertex2(3), Vertex3(3)];
      patch(X, Y, Z, color, 'FaceAlpha', 0.5)
      hold off;
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = type( self )
      % Get object type as string
      out = 'triangle';
    end
  end
end
