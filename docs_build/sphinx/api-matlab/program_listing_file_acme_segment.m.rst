
.. _program_listing_file_acme_segment.m:

Program Listing for File acme_segment.m
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_acme_segment.m>` (``acme_segment.m``)

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
   
   classdef acme_segment < acme_entity
     %>
     %> Class container for ACME segment object
     %>
     methods
       %> Create a new C++ pointer to segment object instance
       function this = acme_segment( varargin )
         this.objectHandle = mex_segment( 'new', varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Delete C++ pointer to segment object instance
       function delete( this )
         mex_segment( 'delete', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get object type as string
       function out = type( this )
         out = 'segment';
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment vertex 1 as ACME point object
       function out = getVertex1( this )
         out = acme_point();
         out.copyByHandle( mex_segment( 'getVertex1', this.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment vertex 2 as ACME point object
       function out = getVertex2( this )
         out = acme_point();
         out.copyByHandle( mex_segment( 'getVertex2', this.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set segment vertex 1 with an ACME point object
       function setVertex1( this, other_obj )
         mex_segment( 'setVertex1', this.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set segment vertex 2 with an ACME point object
       function setVertex2( this, other_obj )
         mex_segment( 'setVertex2', this.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy segment object from another segment
       function copy( this, other_obj )
         if (other_obj.type() == "segment")
           mex_segment( 'copy', this.objectHandle, other_obj.objectHandle );
         else
           error('mex_segment::copy(): other_obj must be an ACME segment object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy segment object from another segment handle
       function copyByHandle( this, handle )
         mex_segment( 'copy', this.objectHandle, handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Translate segment by vector
       function translate( this, other_obj )
         mex_segment( 'translate', this.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform segment by 4x4 affine transformation matrix
       function transform( this, varargin )
         mex_segment( 'transform', this.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ACME point is inside the segment 
       function out = isInside( this, other_obj )
         if (other_obj.type() == "point")
           out = mex_segment( 'isInside', this.objectHandle, other_obj.objectHandle );
         else
            error('mex_segment::isInside(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is degenerated
       function out = isDegenerated( this )
         out = mex_segment( 'isDegenerated', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segments are approximatively equal
       function out = isApprox( this, other_obj )
         if (other_obj.type() == "segment") 
           out = mex_segment( 'isApprox', this.objectHandle, other_obj.objectHandle );
         else
            error('mex_segment::isApprox(): other_obj must be an ACME segment object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment centroid as ACME point objecty instance
       function out = centroid( this )
         out = acme_point();
         out.copyByHandle( mex_segment( 'centroid', this.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform segment to vector
       function out = toVector( this )
         out = mex_segment( 'toVector', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform segment to normalized vector
       function out = toNormalizedVector( this )
         out = mex_segment( 'toNormalizedVector', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Swap segment vertices
       function swap( this )
         mex_segment( 'swap', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment minimum and maximum points of object instance
       function [out1, out2] = clamp( this )
         [out1, out2] = mex_segment( 'clamp', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment length
       function out = length( this )
         out = mex_segment( 'length', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is parallel to an ACME object
       function out = isParallel( this, other_obj )
         out = mex_segment( 'isParallel', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is orthogonal to an ACME object
       function out = isOrthogonal( this, other_obj )
         out = mex_segment( 'isOrthogonal', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is collinear to an ACME object
       function out = isCollinear( this, other_obj )
         out = mex_segment( 'isCollinear', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is coplanar to an ACME object 
       function out = isCoplanar( this, other_obj )
         out = mex_segment( 'isCoplanar', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Intersect segment with an ACME object
       function out = intersection( this, other_obj )
         [handle, type] = mex_segment( 'intersection', this.objectHandle, other_obj.objectHandle, other_obj.type() );
         out = eval( strcat( 'acme_', type, '()' ) );
         out.copyByHandle( handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Display object data
       function disp( this )
         disp( [this.getVertex1().get(), this.getVertex2().get()] );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Plot segment object
       function plot( this, figure_name, color )
         figure_name;
         hold on;
         Vertex1 = this.getVertex1().get();
         Vertex2 = this.getVertex2().get();
         scatter3(Vertex1(1), Vertex1(2), Vertex1(3), color, 'filled');
         scatter3(Vertex2(1), Vertex2(2), Vertex2(3), color, 'filled');
         X = [Vertex1(1), Vertex2(1)];
         Y = [Vertex1(2), Vertex2(2)];
         Z = [Vertex1(3), Vertex2(3)];
         plot3(X, Y, Z,'-', 'Color', color)
         hold off;
       end
     end
   end
