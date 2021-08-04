
.. _program_listing_file_acme_ray.m:

Program Listing for File acme_ray.m
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_acme_ray.m>` (``acme_ray.m``)

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
   
   classdef acme_ray < acme_entity
     %>
     %> Class container for ACME ray object
     %>
     methods
       %> Create a new C++ pointer to ray object instance
       function self = acme_ray( varargin )
         self.objectHandle = mex_ray( 'new', varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Delete C++ pointer to ray object instance
       function delete( self )
         mex_ray( 'delete', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get ray origin as ACME point object
       function out = getOrigin( self )
         out = acme_point();
         out.copyByHandle( mex_ray( 'getOrigin', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get ray direction
       function out = getDirection( self )
         out = mex_ray( 'getDirection', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set ray origin with an ACME point object
       function setOrigin( self, other_obj )
         mex_ray( 'setOrigin', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set ray direction
       function setDirection( self, other_obj )
         mex_ray( 'setDirection', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy ray object from another ray
       function copy( self, other_obj )
         if (other_obj.type() == "ray")
           mex_ray( 'copy', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_ray::copy(): other_obj must be an ACME ray object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy ray object from another ray handle
       function copyByHandle( self, handle )
         mex_ray( 'copy', self.objectHandle, handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Translate ray by vector
       function translate( self, other_obj )
         mex_ray( 'translate', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform ray by 4x4 affine transformation matrix
       function transform( self, varargin )
         mex_ray( 'transform', self.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ACME point is inside the ray 
       function out = isInside( self, other_obj )
         if (other_obj.type() == "point")
           out = mex_ray( 'isInside', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_ray::isInside(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ray is degenerated
       function out = isDegenerated( self )
         out = mex_ray( 'isDegenerated', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if rays are approximatively equal
       function out = isApprox( self, other_obj )
         if (other_obj.type() == "ray") 
           out = mex_ray( 'isApprox', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_ray::isApprox(): other_obj must be an ACME ray object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Normalize direction vector
       function normalize( self )
         mex_ray( 'normalize', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform ray to vector
       function out = toVector( self )
         out = mex_ray( 'toVector', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform ray to normalized vector
       function out = toNormalizedVector( self )
         out = mex_ray( 'toNormalizedVector', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Swap ray vertices
       function reverse( self )
         mex_ray( 'reverse', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ray is parallel to an ACME object
       function out = isParallel( self, other_obj )
         out = mex_ray( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ray is orthogonal to an ACME object
       function out = isOrthogonal( self, other_obj )
         out = mex_ray( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ray is collinear to an ACME object
       function out = isCollinear( self, other_obj )
         out = mex_ray( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ray is coplanar to an ACME object 
       function out = isCoplanar( self, other_obj )
         out = mex_ray( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Intersect ray with an ACME object
       function out = intersection( self, other_obj )
         [handle, type] = mex_ray( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
         out = eval( strcat( 'acme_', type, '()' ) );
         out.objectHandle = handle;
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Display object data
       function disp( self )
         disp( [self.getOrigin().get(), self.getDirection()] );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Plot ray object
       function plot( self, figure_name, color, limit )
         figure_name;
         hold on;
         origin = self.getOrigin().get();
         direction = self.getDirection();
         xt = @(t) origin(1) + t*direction(1);
         yt = @(t) origin(2) + t*direction(2);
         zt = @(t) origin(3) + t*direction(3);
         fplot3(xt,yt,zt, [0 limit], color)
         hold off;
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get object type as string
       function out = type( self )
         out = 'ray';
       end
     end
   end
