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

classdef point < entity
  
  %properties (SetAccess = protected, Hidden = true)
  %  objectHandle; % Handle to the underlying C++ class instance
  %end

  methods
    function self = point( varargin )
    % 
      self.objectHandle = mex_point( 'new', varargin{:}  );
    end
    % --------------------------------------------------------------------
    %
    function delete( self )
      mex_point( 'delete', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = getX( self )
      P = mex_point( 'getX', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = getY( self )
      P = mex_point( 'getY', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = getZ( self )
      P = mex_point( 'getZ', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = get( self )
      P = mex_point( 'get', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function setX( self, varargin )
     mex_point( 'setX', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
        %>
    function setY( self, varargin )
     mex_point( 'setY', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
    %>
    function setZ( self, varargin )
     mex_point( 'setZ', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
    %>
    function set( self, varargin )
     mex_point( 'set', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
    %>
    function copy( self, other_obj )
      % Copy segment object from another segment
      if (other_obj.type() == "point")
        mex_point( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_point::copy(): other_obj must be an ACME point object type.');
      end
    end
    % --------------------------------------------------------------------
    %>
    function translate( self, other_obj )
      mex_point( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function P = transform( self, varargin )
      P = point();
      P.objectHandle = mex_point( 'transform', self.objectHandle, varargin{:} );
    end
    % --------------------------------------------------------------------
    %>
    function disp( self )
      disp( self.get() );
    end
    % --------------------------------------------------------------------
    %>
    function plot( self, figure_name, color )
      figure_name;
      hold on;
      scatter3(self.get(), color, 'filled');
      hold off;
    end
    % --------------------------------------------------------------------
    function P = type( self )
      P = 'point';
    end
  end
end
