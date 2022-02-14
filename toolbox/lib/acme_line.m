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

classdef acme_line < acme_entity
  %>
  %> Class container for ACME line object
  %>
  methods
    %> Create a new C++ pointer to line object instance
    function this = acme_line( varargin )
      this.objectHandle = mex_line( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Delete C++ pointer to line object instance
    function delete( this )
      mex_line( 'delete', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get object type as string
    function out = type( this )
      out = 'line';
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get line origin as ACME point object
    function out = getOrigin( this )
      out = acme_point();
      out.copyByHandle( mex_line( 'getOrigin', this.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get line direction
    function out = getDirection( this )
      out = mex_line( 'getDirection', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set line origin with an ACME point object
    function setOrigin( this, other_obj )
      mex_line( 'setOrigin', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set line direction
    function setDirection( this, other_obj )
      mex_line( 'setDirection', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy line object from another line
    function copy( this, other_obj )
      if (other_obj.type() == "line")
        mex_line( 'copy', this.objectHandle, other_obj.objectHandle );
      else
        error('mex_line::copy(): other_obj must be an ACME line object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy line object from another line handle
    function copyByHandle( this, handle )
      mex_line( 'copy', this.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Translate line by vector
    function translate( this, other_obj )
      mex_line( 'translate', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform line by 4x4 affine transformation matrix
    function transform( this, varargin )
      mex_line( 'transform', this.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ACME point is inside the line 
    function out = isInside( this, other_obj )
      if (other_obj.type() == "point")
        out = mex_line( 'isInside', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_line::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if line is degenerated
    function out = isDegenerated( this )
      out = mex_line( 'isDegenerated', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if lines are approximatively equal
    function out = isApprox( this, other_obj )
      if (other_obj.type() == "line") 
        out = mex_line( 'isApprox', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_line::isApprox(): other_obj must be an ACME line object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Normalize direction vector 
    function normalize( this )
      mex_line( 'normalize', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform line to vector
    function out = toVector( this )
      out = mex_line( 'toVector', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform line to normalized vector
    function out = toNormalizedVector( this )
      out = mex_line( 'toNormalizedVector', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Swap line direction
    function reverse( this )
      mex_line( 'reverse', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if line is parallel to an ACME object
    function out = isParallel( this, other_obj )
      out = mex_line( 'isParallel', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if line is orthogonal to an ACME object
    function out = isOrthogonal( this, other_obj )
      out = mex_line( 'isOrthogonal', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if line is collinear to an ACME object
    function out = isCollinear( this, other_obj )
      out = mex_line( 'isCollinear', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if line is coplanar to an ACME object 
    function out = isCoplanar( this, other_obj )
      out = mex_line( 'isCoplanar', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Intersect line with an ACME object
    function out = intersection( this, other_obj )
      [handle, type] = mex_line( 'intersection', this.objectHandle, other_obj.objectHandle, other_obj.type() );
      out = eval( strcat( 'acme_', type, '()' ) );
      out.copyByHandle( handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Display object data
    function disp( this )
      disp( [this.getOrigin().get(), this.getDirection()] );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Plot line object
    function plot( this, figure_name, color )
      figure_name;
      hold on;
      origin = this.getOrigin().get();
      direction = this.getDirection();
      xt = @(t) origin(1) + t*direction(1);
      yt = @(t) origin(2) + t*direction(2);
      zt = @(t) origin(3) + t*direction(3);
      fplot3(xt,yt,zt, color)
      hold off;
    end
  end
end
