
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
   
   classdef acme_segment < acme_entity
     %>
     %> Class container for ACME segment object
     %>
     methods
       %> Create a new C++ pointer to segment object instance
       function self = acme_segment( varargin )
         self.objectHandle = mex_segment( 'new', varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Delete C++ pointer to segment object instance
       function delete( self )
         mex_segment( 'delete', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get object type as string
       function out = type( self )
         out = 'segment';
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment vertex 1 as ACME point object
       function out = getVertex1( self )
         out = acme_point();
         out.copyByHandle( mex_segment( 'getVertex1', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment vertex 2 as ACME point object
       function out = getVertex2( self )
         out = acme_point();
         out.copyByHandle( mex_segment( 'getVertex2', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set segment vertex 1 with an ACME point object
       function setVertex1( self, other_obj )
         mex_segment( 'setVertex1', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set segment vertex 2 with an ACME point object
       function setVertex2( self, other_obj )
         mex_segment( 'setVertex2', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy segment object from another segment
       function copy( self, other_obj )
         if (other_obj.type() == "segment")
           mex_segment( 'copy', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_segment::copy(): other_obj must be an ACME segment object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy segment object from another segment handle
       function copyByHandle( self, handle )
         mex_segment( 'copy', self.objectHandle, handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Translate segment by vector
       function translate( self, other_obj )
         mex_segment( 'translate', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform segment by 4x4 affine transformation matrix
       function transform( self, varargin )
         mex_segment( 'transform', self.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ACME point is inside the segment 
       function out = isInside( self, other_obj )
         if (other_obj.type() == "point")
           out = mex_segment( 'isInside', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_segment::isInside(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is degenerated
       function out = isDegenerated( self )
         out = mex_segment( 'isDegenerated', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segments are approximatively equal
       function out = isApprox( self, other_obj )
         if (other_obj.type() == "segment") 
           out = mex_segment( 'isApprox', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_segment::isApprox(): other_obj must be an ACME segment object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment centroid as ACME point objecty instance
       function out = centroid( self )
         out = acme_point();
         out.copyByHandle( mex_segment( 'centroid', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform segment to vector
       function out = toVector( self )
         out = mex_segment( 'toVector', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform segment to normalized vector
       function out = toNormalizedVector( self )
         out = mex_segment( 'toNormalizedVector', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Swap segment vertices
       function swap( self )
         mex_segment( 'swap', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment minimum and maximum points of object instance
       function [out1, out2] = clamp( self )
         [out1, out2] = mex_segment( 'clamp', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get segment length
       function out = length( self )
         out = mex_segment( 'length', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is parallel to an ACME object
       function out = isParallel( self, other_obj )
         out = mex_segment( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is orthogonal to an ACME object
       function out = isOrthogonal( self, other_obj )
         out = mex_segment( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is collinear to an ACME object
       function out = isCollinear( self, other_obj )
         out = mex_segment( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if segment is coplanar to an ACME object 
       function out = isCoplanar( self, other_obj )
         out = mex_segment( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Intersect segment with an ACME object
       function out = intersection( self, other_obj )
         [handle, type] = mex_segment( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
         out = eval( strcat( 'acme_', type, '()' ) );
         out.copyByHandle( handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Display object data
       function disp( self )
         disp( [self.getVertex1().get(), self.getVertex2().get()] );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Plot segment object
       function plot( self, figure_name, color )
         figure_name;
         hold on;
         Vertex1 = self.getVertex1().get();
         Vertex2 = self.getVertex2().get();
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
