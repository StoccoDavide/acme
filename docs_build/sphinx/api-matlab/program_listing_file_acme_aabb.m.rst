
.. _program_listing_file_acme_aabb.m:

Program Listing for File acme_aabb.m
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_acme_aabb.m>` (``acme_aabb.m``)

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
   
   classdef acme_aabb < acme_entity
     %>
     %> Class container for ACME disk object
     %>
     methods
       %> Create a new C++ pointer to disk object instance
       function self = acme_aabb( varargin )
         self.objectHandle = mex_aabb( 'new', varargin{:} );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Create C++ pointer to disk object instance
       function delete( self )
         mex_aabb( 'delete', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get minimum aabb as ACME point
       function out = getMin( self )
         out = acme_point();
         out.copyByHandle( mex_aabb( 'getMin', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get aabb minimum point X value
       function out = getMinX( self )
         out = mex_aabb( 'getMinX', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get aabb minimum point X value
       function out = getMinY( self )
         out = mex_aabb( 'getMinY', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get aabb minimum point Z value
       function out = getMinZ( self )
         out = mex_aabb( 'getMinZ', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get maximum aabb as ACME point
       function out = getMax( self )
         out = acme_point();
         out.copyByHandle( mex_aabb( 'getMax', self.objectHandle ) );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get aabb maximum point X value
       function out = getMaxX( self )
         out = mex_aabb( 'getMaxX', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get aabb maximum point X value
       function out = getMaxY( self )
         out = mex_aabb( 'getMaxY', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get aabb maximum point Z value
       function out = getMaxZ( self )
         out = mex_aabb( 'getMaxZ', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set minimum aabb as ACME point
       function setMin( self, other_obj )
         if (other_obj.type() == "point")
           mex_aabb( 'setMin', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_aabb::setMin(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set aabb minimum point X value
       function setMinX( self, value )
         mex_aabb( 'setMinX', self.objectHandle, value );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set aabb minimum point X value
       function setMinY( self, value )
         mex_aabb( 'setMinY', self.objectHandle, value );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set aabb minimum point Z value
       function setMinZ( self, value )
         mex_aabb( 'setMinZ', self.objectHandle, value );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set maximum aabb as ACME point
       function setMax( self, other_obj )
         if (other_obj.type() == "point")
           mex_aabb( 'setMax', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_aabb::setMax(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set aabb maximum point X value
       function setMaxX( self, value )
         mex_aabb( 'setMaxX', self.objectHandle, value );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set aabb maximum point X value
       function setMaxY( self, value )
         mex_aabb( 'setMaxY', self.objectHandle, value );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Set aabb maximum point Z value
       function setMaxZ( self )
         mex_aabb( 'setMaxZ', self.objectHandle, value );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy aabb object from another aabb
       function copy( self, other_obj )
         if (other_obj.type() == "aabb")
           mex_aabb( 'copy', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_aabb::copy(): other_obj must be an ACME aabb object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Copy aabb object from another aabb handle
       function copyByHandle( self, handle )
         mex_aabb( 'copy', self.objectHandle, handle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Translate aabb by vector
       function translate( self, other_obj )
         mex_aabb( 'translate', self.objectHandle, other_obj.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if ACME point is inside the aabb 
       function out = isInside( self, other_obj )
         if (other_obj.type() == "point")
           out = mex_aabb( 'isInside', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_aabb::isInside(): other_obj must be an ACME point object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if aabb is degenerated
       function out = isDegenerated( self )
         out = mex_aabb( 'isDegenerated', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if aabbs are approximatively equal
       function out = isApprox( self, other_obj )
         if (other_obj.type() == "aabb") 
           out = mex_aabb( 'isApprox', self.objectHandle, other_obj.objectHandle );
         else
            error('mex_aabb::isApprox(): other_obj must be an ACME aabb object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Return aabb id
       function out = id( self )
         out = mex_aabb( 'id', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Return aabb position
       function out = pos( self )
        out = mex_aabb( 'pos', self.objectHandle );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Perform intersection with another ACME entity and return intersection object
       function out = intersection( self, other_obj )
         if (other_obj.type() == "aabb") 
           out = mex_aabb( 'intersection', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_aabb::intersection(): other_obj must be an ACME aabb object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Check if aabb intersects with another ACME entity  and return boolean
       function out = intersects( self, other_obj )
         if (other_obj.type() == "aabb") 
           out = mex_aabb( 'intersects', self.objectHandle, other_obj.objectHandle );
         else
           error('mex_aabb::intersects(): other_obj must be an ACME aabb object type.');
         end
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Display object data
       function disp( self )
         disp( [ self.getMin().get(),  self.getMax().get() ] );
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Plot disk object
       function plot( self, figure_name, color )
         figure_name;
         hold on;
         min = self.getMin().get();
         max = self.getMax().get();
         plot3( [min(1), max(1)], ... % 01
                [min(2), min(2)], ...
                [min(3), min(3)], ...
                'Color', color)
         plot3( [min(1), min(1)], ... % 02
                [min(2), max(2)], ...
                [min(3), min(3)], ...
                'Color', color)
         plot3( [min(1), min(1)], ... % 03
                [min(2), min(2)], ...
                [min(3), max(3)], ...
                'Color', color)
         plot3( [max(1), min(1)], ... % 04
                [max(2), max(2)], ...
                [max(3), max(3)], ...
                'Color', color)
         plot3( [max(1), max(1)], ... % 05
                [max(2), min(2)], ...
                [max(3), max(3)], ...
                'Color', color)
         plot3( [max(1), max(1)], ... % 06
                [max(2), max(2)], ...
                [max(3), min(3)], ...
                'Color', color)
         plot3( [max(1), max(1)], ... % 07
                [min(2), max(2)], ...
                [min(3), min(3)], ...
                'Color', color)
         plot3( [min(1), min(1)], ... % 08
                [min(2), max(2)], ...
                [max(3), max(3)], ...
                'Color', color)
         plot3( [min(1), max(1)], ... % 09
                [min(2), min(2)], ...
                [max(3), max(3)], ...
                'Color', color)
         plot3( [min(1), min(1)], ... % 10
                [max(2), max(2)], ...
                [min(3), max(3)], ...
                'Color', color)
         plot3( [max(1), max(1)], ... % 11
                [min(2), min(2)], ...
                [min(3), max(3)], ...
                'Color', color)
         plot3( [min(1), max(1)], ... % 12
                [max(2), max(2)], ...
                [min(3), min(3)], ...
                'Color', color)
         % Cross lines on faces
         plot3( [min(1), max(1)], ... % 13
                [min(2), max(2)], ...
                [min(3), min(3)], ...
                'Color', color)
         plot3( [min(1), max(1)], ... % 14
                [min(2), max(2)], ...
                [max(3), max(3)], ...
                'Color', color)
         plot3( [min(1), min(1)], ... % 15
                [min(2), max(2)], ...
                [min(3), max(3)], ...
                'Color', color)
         plot3( [max(1), max(1)], ... % 16
                [min(2), max(2)], ...
                [min(3), max(3)], ...
                'Color', color)
         plot3( [min(1), max(1)], ... % 17
                [min(2), min(2)], ...
                [min(3), max(3)], ...
                'Color', color)
         plot3( [min(1), max(1)], ... % 18
                [max(2), max(2)], ...
                [min(3), max(3)], ...
                'Color', color)
         hold off;
       end
       %
       % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
       %
       %> Get object type as string
       function out = type( self )
         out = 'aabb';
       end
     end
   end
