
.. _program_listing_file_acme_point.m:

Program Listing for File acme_point.m
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_acme_point.m>` (``acme_point.m``)

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
   
   classdef acme_point < acme_entity
     %>
     %> Class container for ACME point object
     %>
     methods
       %> Create C++ pointer to triangle object instance
       function this = acme_point( varargin )
         this.objectHandle = mex_point( 'new', varargin{:}  );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Delete C++ pointer to triangle object instance
       function delete( this )
         mex_point( 'delete', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get point X axis component
       function out = getX( this )
         out = mex_point( 'getX', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get point Y axis component
       function out = getY( this )
         out = mex_point( 'getY', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get point Z axis component
       function out = getZ( this )
         out = mex_point( 'getZ', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get point axes components
       function out = get( this )
         out = mex_point( 'get', this.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set point X axis component
       function setX( this, varargin )
         mex_point( 'setX', this.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set point Y axis component
       function setY( this, varargin )
         mex_point( 'setY', this.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set point Z axis component
       function setZ( this, varargin )
         mex_point( 'setZ', this.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set point axes components
       function set( this, varargin )
         mex_point( 'set', this.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy point object from another point
       function copy( this, other_obj )
         if (other_obj.type() == "point")
           mex_point( 'copy', this.objectHandle, other_obj.objectHandle );
         else
           error('mex_point::copy(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy point object from another point handle
       function copyByHandle( this, handle )
         mex_point( 'copy', this.objectHandle, handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Translate point by vector
       function translate( this, other_obj )
         mex_point( 'translate', this.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Transform point by 4x4 affine transformation matrix
       function transform( this, varargin )
         mex_point( 'transform', this.objectHandle, varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if point is parallel to an ACME object
       function out = isParallel( this, other_obj )
         out = mex_point( 'isParallel', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if point is orthogonal to an ACME object
       function out = isOrthogonal( this, other_obj )
         out = mex_point( 'isOrthogonal', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if point is collinear to an ACME object
       function out = isCollinear( this, other_obj )
         out = mex_point( 'isCollinear', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if point is coplanar to an ACME object 
       function out = isCoplanar( this, other_obj )
         out = mex_point( 'isCoplanar', this.objectHandle, other_obj.objectHandle, other_obj.type() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Intersect point with an ACME object
       function out = intersection( this, other_obj )
         [handle, type] = mex_point( 'intersection', this.objectHandle, other_obj.objectHandle, other_obj.type() );
         out = eval( strcat( 'acme_', type, '()' ) );
         out.copyByHandle( handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Display object data
       function disp( this )
         disp( this.get() );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Plot point object
       function plot( this, figure_name, color )
         figure_name;
         hold on;
         scatter3(this.getX(), this.getY(), this.getZ(), color, 'filled');
         hold off;
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get object type as string
       function out = type( this )
         out = 'point';
       end
     end
   end
