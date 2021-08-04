
.. _program_listing_file_acme_ball.m:

Program Listing for File acme_ball.m
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_acme_ball.m>` (``acme_ball.m``)

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
   
   classdef acme_ball < acme_entity
     %>
     %> Class container for ACME ball object
     %>
     methods
       %> Create a new C++ pointer to ball object instance
       function self = acme_ball( varargin )
         self.objectHandle = mex_ball( 'new', varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Create C++ pointer to ball object instance
       function delete( self )
         mex_ball( 'delete', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get ball radius
       function out = getRadius( self )
         out = mex_ball( 'getRadius', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get ball center as ACME point object
       function out = getCenter( self )
         out = acme_point();
         out.copyByHandle( mex_ball( 'getCenter', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set ball radius
       function setRadius( self, radius )
         mex_ball( 'setRadius', self.objectHandle, radius );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set ball center with an ACME point object
       function setCenter( self, other_obj )
         mex_ball( 'setCenter', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy segment object from another segment
       function copy( self, other_obj )
         if (other_obj.type() == "ball")
           mex_ball( 'copy', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_ball::copy(): other_obj must be an ACME ball object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy ball object from another ball handle
       function copyByHandle( self, handle )
         mex_ball( 'copy', self.objectHandle, handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Translate ball by vector
       function translate( self, other_obj )
         mex_ball( 'translate', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform ball by 4x4 affine transformation matrix
       function transform( self, affine )
         mex_ball( 'transform', self.objectHandle, affine );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ACME point is inside the ball
       function out = isInside( self, other_obj )
         if (other_obj.type() == "point")
           out = mex_ball( 'isInside', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_ball::isInside(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ball is degenerated
       function out = isDegenerated( self )
         out = mex_ball( 'isDegenerated', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if balls are approximatively equal
       function out = isApprox( self, other_obj )
         if (other_obj.type() == "ball")
           out = mex_ball( 'isApprox', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_ball::isApprox(): other_obj must be an ACME ball object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get ball minimum and maximum points of object instance
       function [out1, out2] = clamp( self )
         [out1, out2] = mex_ball( 'clamp', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get ball perimeter
       function out = area( self )
         out = mex_ball( 'area', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get ball volume
       function out = volume( self )
         out = mex_ball( 'volume', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ball is parallel to an ACME object
       function out = isParallel( self, other_obj )
         out = mex_ball( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ball is orthogonal to an ACME object
       function out = isOrthogonal( self, other_obj )
         out = mex_ball( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ball is collinear to an ACME object
       function out = isCollinear( self, other_obj )
         out = mex_ball( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ball is coplanar to an ACME object
       function out = isCoplanar( self, other_obj )
         out = mex_ball( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Intersect ball with an ACME object
       function out = intersection( self, other_obj )
         [handle, type] = mex_ball( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
         out = eval( strcat( 'acme_', type, '()') );
         out.copyByHandle( handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Display object data
       function disp( self )
         disp( [ [self.getRadius(), NaN, NaN]', self.getCenter().get()] ); %[self.getRadius() 0 0]',
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Plot ball object
       function plot( self, figure_name, color )
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
       %> Get object type as string
       function out = type( self )
         out = 'ball';
       end
     end
   end
