
.. _program_listing_file_acme_triangle.m:

Program Listing for File acme_triangle.m
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_acme_triangle.m>` (``acme_triangle.m``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: MATLAB

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
     %>
     %> Class container for ACME triangle object
     %>
     methods
       %> Create a new C++ pointer to triangle object instance
       function self = acme_triangle( varargin )
         self.objectHandle = mex_triangle( 'new', varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Create C++ pointer to triangle object instance
       function delete( self )
         mex_triangle( 'delete', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle vertex 1 as ACME point object
       function out = getVertex1( self )
         out = acme_point();
         out.copyByHandle( mex_triangle( 'getVertex1', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle vertex 2 as ACME point object
       function out = getVertex2( self )
         out = acme_point();
         out.copyByHandle( mex_triangle( 'getVertex2', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle vertex 3 as ACME point object
       function out = getVertex3( self )
         out = acme_point();
         out.copyByHandle( mex_triangle( 'getVertex3', self.objectHandle) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set triangle vertex 1 with an ACME point object
       function setVertex1( self, other_obj )
         mex_triangle( 'setVertex1', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set triangle vertex 2 with an ACME point object
       function setVertex2( self, other_obj )
         mex_triangle( 'setVertex2', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set triangle vertex 3 with an ACME point object
       function setVertex3( self, other_obj )
         mex_triangle( 'setVertex3', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy segment object from another segment
       function copy( self, other_obj )
         if (other_obj.type() == "triangle")
           mex_triangle( 'copy', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_triangle::copy(): other_obj must be an ACME triangle object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy triangle object from another triangle handle
       function copyByHandle( self, handle )
         mex_triangle( 'copy', self.objectHandle, handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Translate triangle by vector
       function translate( self, other_obj )
         mex_triangle( 'translate', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform triangle by 4x4 affine transformation matrix
       function transform( self, varargin )
         mex_triangle( 'transform', self.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ACME point is inside the triangle 
       function out = isInside( self, other_obj )
         if (other_obj.type() == "point")
           out = mex_triangle( 'isInside', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_triangle::isInside(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is degenerated
       function out = isDegenerated( self )
         out = mex_triangle( 'isDegenerated', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangles are approximatively equal
       function out = isApprox( self, other_obj )
         if (other_obj.type() == "triangle") 
           out = mex_triangle( 'isApprox', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_triangle::isApprox(): other_obj must be an ACME triangle object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle centroid as ACME point objecty instance
       function out = centroid( self )
         out = acme_point();
         out.copyByHandle( mex_triangle( 'centroid', self.objectHandle, other_obj.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle normal
       function out = normal( self )
         out = mex_triangle( 'normal', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle laying plane
       function out = layingPlane( self )
        out = acme_plane();
        out.copyByHandle( mex_triangle( 'layingPlane', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle i-th edge
       function out = edge( self, i )
         out = acme_segment();
         out.copyByHandle( mex_triangle( 'edge', self.objectHandle, i ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Swap triangle i-th and j-th vertex
       function swap( self, i, j )
         mex_triangle( 'swap', self.objectHandle, i, j );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle minimum and maximum points of object instance
       function [out1, out2] = clamp( self )
         [out1, out2] = mex_triangle( 'clamp', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle perimeter
       function out = perimeter( self )
         out = mex_triangle( 'perimeter', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle perimeter
       function out = area( self )
         out = mex_triangle( 'area', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Compute barycentric coordinates (u,v,w) for ACME point
       function out = barycentric( self, other_obj )
         if ( other_obj == "point" )
           out = mex_triangle( 'barycenter', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_triangle::barycentric(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is parallel to an ACME object
       function out = isParallel( self, other_obj )
         out = mex_triangle( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is orthogonal to an ACME object
       function out = isOrthogonal( self, other_obj )
         out = mex_triangle( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is collinear to an ACME object
       function out = isCollinear( self, other_obj )
         out = mex_triangle( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is coplanar to an ACME object 
       function out = isCoplanar( self, other_obj )
         out = mex_triangle( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Intersect triangle with an ACME object
       function out = intersection( self, other_obj )
         [handle, type] = mex_triangle( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
         out = eval( strcat( 'acme_', type, '()' ) );
         out.copyByHandle( handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Display object data
       function disp( self )
         disp( [self.getVertex1().get(), self.getVertex2().get(),  self.getVertex3().get()] );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Plot triangle object
       function plot( self, figure_name, color )
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
       %> Get object type as string
       function out = type( self )
         out = 'triangle';
       end
     end
   end
