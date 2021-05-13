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

classdef acme_line < acme_entity
  %
  % Class container for ACME line object
  %
  methods
    function self = acme_line( varargin )
      % Create a new C++ pointer to line object instance
      self.objectHandle = mex_line( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function delete( self )
      % Delete C++ pointer to line object instance
      mex_line( 'delete', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = type( self )
      % Get object type as string
      P = 'line';
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getOrigin( self )
      % Get line origin as ACME point object
      P = acme_point();
      P.objectHandle = mex_line( 'getOrigin', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getDirection( self )
      % Get line direction
      P = mex_line( 'getDirection', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setOrigin( self, other_obj )
      % Set line origin with an ACME point object
      mex_line( 'setOrigin', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setDirection( self, other_obj )
      % Set line direction
      mex_line( 'setDirection', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copy( self, other_obj )
      % Copy line object from another line
      if (other_obj.type() == "line")
        mex_line( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_line::copy(): other_obj must be an ACME line object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function translate( self, other_obj )
     % Translate line by vector
      mex_line( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function transform( self, varargin )
      % Transform line by 4x4 affine transformation matrix
      mex_line( 'transform', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isInside( self, other_obj )
      % Check if ACME point is inside the line 
      if (other_obj.type() == "point")
        P = mex_line( 'isInside', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_line::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isDegenerated( self )
      % Check if line is degenerated
      P = mex_line( 'isDegenerated', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isApprox( self, other_obj )
      % Check if lines are approximatively equal
      if (other_obj.type() == "line") 
        P = mex_line( 'isApprox', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_line::isApprox(): other_obj must be an ACME line object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function normalize( self )
      % 
      mex_line( 'normalize', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = toVector( self )
       % Transform line to vector
      P = mex_line( 'toVector', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = toNormalizedVector( self )
      % Transform line to normalized vector
      P = mex_line( 'toNormalizedVector', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function reverse( self )
      % Swap line vertices
      mex_line( 'reverse', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isParallel( self, other_obj )
      % Check if line is parallel to an ACME object
      P = mex_line( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isOrthogonal( self, other_obj )
      % Check if line is orthogonal to an ACME object
      P = mex_line( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCollinear( self, other_obj )
      % Check if line is collinear to an ACME object
      P = mex_line( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCoplanar( self, other_obj )
      % Check if line is coplanar to an ACME object 
      P = mex_line( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = intersection( self, other_obj )
      % Intersect line with an ACME object
      [Handle, type] = mex_line( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
      P = eval( strcat( 'acme_', type, '()' ) );
      P.objectHandle = Handle;
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function disp( self )
      % Display object data
      disp( [self.getOrigin().get(), self.getDirection()] );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function plot( self, figure_name, color )
      % Plot line object
      figure_name;
      hold on;
      origin = self.getOrigin().get();
      direction = self.getDirection();
      xt = @(t) origin(1) + t*direction(1);
      yt = @(t) origin(2) + t*direction(2);
      zt = @(t) origin(3) + t*direction(3);
      fplot3(xt,yt,zt, color)
      hold off;
    end
  end
end
