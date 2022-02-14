
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
   % Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            %
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
       function this = acme_triangle( varargin )
         this.objectHandle = mex_triangle( 'new', varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Create C++ pointer to triangle object instance
       function delete( this )
         mex_triangle( 'delete', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle vertex 1 as ACME point object
       function out = getVertex1( this )
         out = acme_point();
         out.copyByHandle( mex_triangle( 'getVertex1', this.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle vertex 2 as ACME point object
       function out = getVertex2( this )
         out = acme_point();
         out.copyByHandle( mex_triangle( 'getVertex2', this.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle vertex 3 as ACME point object
       function out = getVertex3( this )
         out = acme_point();
         out.copyByHandle( mex_triangle( 'getVertex3', this.objectHandle) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set triangle vertex 1 with an ACME point object
       function setVertex1( this, other_obj )
         mex_triangle( 'setVertex1', this.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set triangle vertex 2 with an ACME point object
       function setVertex2( this, other_obj )
         mex_triangle( 'setVertex2', this.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set triangle vertex 3 with an ACME point object
       function setVertex3( this, other_obj )
         mex_triangle( 'setVertex3', this.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy segment object from another segment
       function copy( this, other_obj )
         if (other_obj.type() == "triangle")
           mex_triangle( 'copy', this.objectHandle, other_obj.objectHandle );
         else
           error('mex_triangle::copy(): other_obj must be an ACME triangle object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy triangle object from another triangle handle
       function copyByHandle( this, handle )
         mex_triangle( 'copy', this.objectHandle, handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Translate triangle by vector
       function translate( this, other_obj )
         mex_triangle( 'translate', this.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform triangle by 4x4 affine transformation matrix
       function transform( this, varargin )
         mex_triangle( 'transform', this.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ACME point is inside the triangle 
       function out = isInside( this, other_obj )
         if (other_obj.type() == "point")
           out = mex_triangle( 'isInside', this.objectHandle, other_obj.objectHandle );
         else
            error('mex_triangle::isInside(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is degenerated
       function out = isDegenerated( this )
         out = mex_triangle( 'isDegenerated', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangles are approximatively equal
       function out = isApprox( this, other_obj )
         if (other_obj.type() == "triangle") 
           out = mex_triangle( 'isApprox', this.objectHandle, other_obj.objectHandle );
         else
            error('mex_triangle::isApprox(): other_obj must be an ACME triangle object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle centroid as ACME point objecty instance
       function out = centroid( this )
         out = acme_point();
         out.copyByHandle( mex_triangle( 'centroid', this.objectHandle, other_obj.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle normal
       function out = normal( this )
         out = mex_triangle( 'normal', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle laying plane
       function out = layingPlane( this )
        out = acme_plane();
        out.copyByHandle( mex_triangle( 'layingPlane', this.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle i-th edge
       function out = edge( this, i )
         out = acme_segment();
         out.copyByHandle( mex_triangle( 'edge', this.objectHandle, i ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Swap triangle i-th and j-th vertex
       function swap( this, i, j )
         mex_triangle( 'swap', this.objectHandle, i, j );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle minimum and maximum points of object instance
       function [out1, out2] = clamp( this )
         [out1, out2] = mex_triangle( 'clamp', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle perimeter
       function out = perimeter( this )
         out = mex_triangle( 'perimeter', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get triangle area
       function out = area( this )
         out = mex_triangle( 'area', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Compute barycentric coordinates (u,v,w) for ACME point
       function out = barycentric( this, other_obj )
         if ( other_obj == "point" )
           out = mex_triangle( 'barycenter', this.objectHandle, other_obj.objectHandle );
         else
           error('mex_triangle::barycentric(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is parallel to an ACME object
       function out = isParallel( this, other_obj )
         out = mex_triangle( 'isParallel', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is orthogonal to an ACME object
       function out = isOrthogonal( this, other_obj )
         out = mex_triangle( 'isOrthogonal', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is collinear to an ACME object
       function out = isCollinear( this, other_obj )
         out = mex_triangle( 'isCollinear', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if triangle is coplanar to an ACME object 
       function out = isCoplanar( this, other_obj )
         out = mex_triangle( 'isCoplanar', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Intersect triangle with an ACME object
       function out = intersection( this, other_obj )
         [handle, type] = mex_triangle( 'intersection', this.objectHandle, other_obj.objectHandle, other_obj.type() );
         out = eval( strcat( 'acme_', type, '()' ) );
         out.copyByHandle( handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Display object data
       function disp( this )
         disp( [this.getVertex1().get(), this.getVertex2().get(),  this.getVertex3().get()] );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Plot triangle object
       function plot( this, figure_name, color )
         figure_name;
         hold on;
         Vertex1 = this.getVertex1().get();
         Vertex2 = this.getVertex2().get();
         Vertex3 = this.getVertex3().get();
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
       function out = type( this )
         out = 'triangle';
       end
     end
   end
