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
  %
  % Class container for ACME disk object
  %
  methods
    function self = acme_aabb( varargin )
      % Create a new C++ pointer to disk object instance
      self.objectHandle = mex_aabb( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function delete( self )
      % Create C++ pointer to disk object instance
      mex_aabb( 'delete', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getMin( self )
      % Get minimum aabb as ACME point
      out = acme_point();
      out.copyByHandle( mex_aabb( 'getMin', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getMinX( self )
      % Get aabb minimum point X value
      out = mex_aabb( 'getMinX', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getMinY( self )
      % Get aabb minimum point X value
      out = mex_aabb( 'getMinY', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getMinZ( self )
      % Get aabb minimum point Z value
      out = mex_aabb( 'getMinZ', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getMax( self )
      % Get maximum aabb as ACME point
      out = acme_point();
      out.copyByHandle( mex_aabb( 'getMax', self.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getMaxX( self )
      % Get aabb maximum point X value
      out = mex_aabb( 'getMaxX', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getMaxY( self )
      % Get aabb maximum point X value
      out = mex_aabb( 'getMaxY', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = getMaxZ( self )
      % Get aabb maximum point Z value
      out = mex_aabb( 'getMaxZ', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setMin( self, other_obj )
      % Set minimum aabb as ACME point
      if (other_obj.type() == "point")
        mex_aabb( 'setMin', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_aabb::setMin(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setMinX( self, value )
      % Set aabb minimum point X value
      mex_aabb( 'setMinX', self.objectHandle, value );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setMinY( self, value )
      % Set aabb minimum point X value
      mex_aabb( 'setMinY', self.objectHandle, value );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setMinZ( self, value )
      % Set aabb minimum point Z value
      mex_aabb( 'setMinZ', self.objectHandle, value );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setMax( self, other_obj )
      % Set maximum aabb as ACME point
      if (other_obj.type() == "point")
        mex_aabb( 'setMax', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_aabb::setMax(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setMaxX( self, value )
      % Set aabb maximum point X value
      mex_aabb( 'setMaxX', self.objectHandle, value );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setMaxY( self, value )
      % Set aabb maximum point X value
      mex_aabb( 'setMaxY', self.objectHandle, value );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setMaxZ( self )
      % Set aabb maximum point Z value
      mex_aabb( 'setMaxZ', self.objectHandle, value );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copy( self, other_obj )
      % Copy aabb object from another aabb
      if (other_obj.type() == "aabb")
        mex_aabb( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_aabb::copy(): other_obj must be an ACME aabb object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copyByHandle( self, handle )
      % Copy aabb object from another aabb handle
      mex_aabb( 'copy', self.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function translate( self, other_obj )
     % Translate aabb by vector
      mex_aabb( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isInside( self, other_obj )
      % Check if ACME point is inside the aabb 
      if (other_obj.type() == "point")
        out = mex_aabb( 'isInside', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_aabb::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isDegenerated( self )
      % Check if aabb is degenerated
      out = mex_aabb( 'isDegenerated', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = isApprox( self, other_obj )
      % Check if aabbs are approximatively equal
      if (other_obj.type() == "aabb") 
        out = mex_aabb( 'isApprox', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_aabb::isApprox(): other_obj must be an ACME aabb object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = id( self )
      % Return aabb id
      out = mex_aabb( 'id', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function out = pos( self )
     % Return aabb position
     out = mex_aabb( 'pos', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
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
    function disp( self )
      % Display object data
      disp( [ self.getMin().get(),  self.getMax().get() ] );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function plot( self, figure_name, color )
      % Plot disk object
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
    function out = type( self )
      % Get object type as string
      out = 'aabb';
    end
  end
end
