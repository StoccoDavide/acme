
.. _program_listing_file_acme_disk.m:

Program Listing for File acme_disk.m
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_acme_disk.m>` (``acme_disk.m``)

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
   
   classdef acme_disk < acme_entity
     %>
     %> Class container for ACME disk object
     %>
     methods
       %> Create a new C++ pointer to disk object instance
       function self = acme_disk( varargin )
         self.objectHandle = mex_disk( 'new', varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Create C++ pointer to disk object instance
       function delete( self )
         mex_disk( 'delete', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get disk radius
       function out = getRadius( self )
         out = mex_disk( 'getRadius', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get disk center as ACME point object
       function out = getCenter( self )
         out = acme_point();
         out.copyByHandle( mex_disk( 'getCenter', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get disk normal
       function out = getNormal( self )
         out = mex_disk( 'getNormal', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set disk radius
       function setRadius( self, radius )
         mex_disk( 'setRadius', self.objectHandle, radius );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set disk center with an ACME point object
       function setCenter( self, other_obj )
         mex_disk( 'setCenter', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set disk normal
       function setNormal( self, other_obj )
         mex_disk( 'setNormal', self.objectHandle, other_obj );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy segment object from another segment
       function copy( self, other_obj )
         if (other_obj.type() == "disk")
           mex_disk( 'copy', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_disk::copy(): other_obj must be an ACME disk object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy disk object from another disk handle
       function copyByHandle( self, handle )
         mex_disk( 'copy', self.objectHandle, handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Translate disk by vector
       function translate( self, other_obj )
         mex_disk( 'translate', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform disk by 4x4 affine transformation matrix
       function transform( self, affine )
         mex_disk( 'transform', self.objectHandle, affine );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ACME point is inside the disk 
       function out = isInside( self, other_obj )
         if (other_obj.type() == "point")
           out = mex_disk( 'isInside', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_disk::isInside(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if disk is degenerated
       function out = isDegenerated( self )
         out = mex_disk( 'isDegenerated', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if disks are approximatively equal
       function out = isApprox( self, other_obj )
         if (other_obj.type() == "disk") 
           out = mex_disk( 'isApprox', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_disk::isApprox(): other_obj must be an ACME disk object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Normalize disk normal vector
       function normalize( self )
         mex_disk( 'normalize', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get disk laying plane
       function out = layingPlane( self )
        out = acme_plane();
        out.copyByHandle( mex_disk( 'layingPlane', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Reverse disk normal direction
       function reverse( self )
         mex_disk( 'reverse', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get disk minimum and maximum points of object instance
       function [out1, out2] = clamp( self )
         [out1, out2] = mex_disk( 'clamp', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get disk perimeter
       function out = perimeter( self )
         out = mex_disk( 'perimeter', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get disk perimeter
       function out = area( self )
         out = mex_disk( 'area', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if disk is parallel to an ACME object
       function out = isParallel( self, other_obj )
         out = mex_disk( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if disk is orthogonal to an ACME object
       function out = isOrthogonal( self, other_obj )
         out = mex_disk( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if disk is collinear to an ACME object
       function out = isCollinear( self, other_obj )
         out = mex_disk( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if disk is coplanar to an ACME object 
       function out = isCoplanar( self, other_obj )
         out = mex_disk( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Intersect disk with an ACME object
       function out = intersection( self, other_obj )
         [handle, type] = mex_disk( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
         out = eval( strcat( 'acme_', type, '()') );
         out.copyByHandle( handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Display object data
       function disp( self )
         disp( [ [self.getRadius(), NaN, NaN]', self.getCenter().get(),  self.getNormal()] ); %[self.getRadius() 0 0]',
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Plot disk object
       function plot( self, figure_name, color )
         radius = self.getRadius();
         center = self.getCenter().get();
         normal = self.getNormal();
         % Original points, original plane
         t = linspace(0,2*pi);
         x = cos(t)*radius;
         y = sin(t)*radius;
         z = 0.0*t;
         pnts = [x;y;z];
         % Unit normal for original plane
         n0 = [0 0 1]'; 
         n0 = n0/norm(n0);
         % Unit normal for plane to rotate into plane is orthogonal to n1...
         % given by equatio: n1(1)*x + n1(2)*y + n1(3)*z = 0
         n1 = normal;
         n1 = n1/norm(n1); 
         % Angle between normals
         c = dot(n0,n1) / ( norm(n0)*norm(n1) );   % cos(theta)
         s = sqrt(1-c*c);                          % sin(theta)
         u = cross(n0,n1) / ( norm(n0)*norm(n1) ); % rotation axis...
         u = u/max(1e-12,norm(u));                            % ...as unit vector
         C = 1-c;
         % Rotation matrix
         R = [ u(1)^2*C+c,         u(1)*u(2)*C-u(3)*s, u(1)*u(3)*C+u(2)*s
               u(2)*u(1)*C+u(3)*s, u(2)^2*C+c,         u(2)*u(3)*C-u(1)*s
               u(3)*u(1)*C-u(2)*s, u(3)*u(2)*C+u(1)*s, u(3)^2*C+c
             ];
         % Rotated points
         newPnts = R*pnts;
         % Visualize
         figure_name;
         hold on;
         patch( center(1)+newPnts(1,:)', ...
                center(2)+newPnts(2,:)', ...
                center(3)+newPnts(3,:)', ...
                color, 'FaceAlpha', 0.5)
         hold off;
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get object type as string
       function out = type( self )
         out = 'disk';
       end
     end
   end
