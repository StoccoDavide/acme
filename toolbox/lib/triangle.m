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

classdef triangle < entity
  %
  % Class container for ACME triangle object
  %
  methods
    function self = triangle( varargin )
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
    function P = type( self )
      % Get object type as string
      P = 'triangle';
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getVertex1( self )
      % Get triangle vertex 1 as ACME point object
      P = point();
      P.objectHandle = mex_triangle( 'getVertex1', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getVertex2( self )
      % Get triangle vertex 2 as ACME point object
      P = point();
      P.objectHandle = mex_triangle( 'getVertex2', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getVertex3( self )
      % Get triangle vertex 3 as ACME point object
      P = point();
      P.objectHandle = mex_triangle( 'getVertex3', self.objectHandle );
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
    function translate( self, other_obj )
     % Translate triangle by vector
      mex_triangle( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = transform( self, varargin )
      % Transform triangle by 4x4 affine transformation matrix
      P = triangle();
      P.objectHandle = mex_triangle( 'transform', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isInside( self, other_obj )
      % Check if ACME point is inside the triangle 
      if (other_obj.type() == "point")
        P = mex_triangle( 'isInside', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_triangle::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isDegenerated( self )
      % Check if triangle is degenerated
      P = mex_triangle( 'isDegenerated', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isApprox( self, other_obj )
      % Check if triangles are approximatively equal
      if (other_obj.type() == "triangle") 
        P = mex_triangle( 'isApprox', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_triangle::isApprox(): other_obj must be an ACME triangle object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = centroid( self )
      % Get triangle centroid as ACME point objecty instance
      P = point();
      P.objectHandle = mex_triangle( 'centroid', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = normal( self )
      % Get triangle normal
      P = mex_triangle( 'normal', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = layingPlane( self )
     % Get triangle laying plane
     P = plane();
     P.objectHandle = mex_triangle( 'layingPlane', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = edge( self, i, j )
      % Get triangle edge between i-th and j-th vertex
      P = segment();
      P.objectHandle = mex_triangle( 'edge', self.objectHandle, i, j );
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
    function P = clamp( self )
      % Get triangle minimum bounding box as ACME aabb object instance
      P = aabb();
      P.objectHandle = mex_triangle( 'clamp', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = perimeter( self )
      % Get triangle perimeter
      P = mex_triangle( 'perimeter', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = area( self )
      % Get triangle perimeter
      P = mex_triangle( 'area', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = barycentric( self, other_obj )
      % Compute barycentric coordinates (u,v,w) for ACME point
      if ( other_obj == "point" )
        P = mex_triangle( 'barycenter', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_triangle::barycentric(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isParallel( self, other_obj )
      % Check if triangle is parallel to an ACME object
      P = mex_triangle( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isOrthogonal( self, other_obj )
      % Check if triangle is orthogonal to an ACME object
      P = mex_triangle( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCollinear( self, other_obj )
      % Check if triangle is collinear to an ACME object
      P = mex_triangle( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCoplanar( self, other_obj )
      % Check if triangle is coplanar to an ACME object 
      P = mex_triangle( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = intersection( self, other_obj )
      % Intersect triangle with an ACME object
      [Handle, type] = mex_triangle( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
      P = eval( strcat( type, '()') );
      P.objectHandle = Handle;
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
      scatter3(Vertex1(1), Vertex1(2), Vertex1(3), color, 'filled');
      scatter3(Vertex2(1), Vertex2(2), Vertex2(3), color, 'filled');
      scatter3(Vertex3(1), Vertex3(2), Vertex3(3), color, 'filled');
      X = [Vertex1(1), Vertex2(1), Vertex3(1)];
      Y = [Vertex1(2), Vertex2(2), Vertex3(2)];
      Z = [Vertex1(3), Vertex2(3), Vertex3(3)];
      patch(X, Y, Z, color)
      hold off;
    end
  end
end
