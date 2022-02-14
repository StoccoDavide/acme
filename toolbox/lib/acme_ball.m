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

classdef acme_ball < acme_entity
  %>
  %> Class container for ACME ball object
  %>
  methods
    %> Create a new C++ pointer to ball object instance
    function this = acme_ball( varargin )
      this.objectHandle = mex_ball( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Create C++ pointer to ball object instance
    function delete( this )
      mex_ball( 'delete', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get ball radius
    function out = getRadius( this )
      out = mex_ball( 'getRadius', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get ball center as ACME point object
    function out = getCenter( this )
      out = acme_point();
      out.copyByHandle( mex_ball( 'getCenter', this.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set ball radius
    function setRadius( this, radius )
      mex_ball( 'setRadius', this.objectHandle, radius );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set ball center with an ACME point object
    function setCenter( this, other_obj )
      mex_ball( 'setCenter', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy segment object from another segment
    function copy( this, other_obj )
      if (other_obj.type() == "ball")
        mex_ball( 'copy', this.objectHandle, other_obj.objectHandle );
      else
        error('mex_ball::copy(): other_obj must be an ACME ball object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy ball object from another ball handle
    function copyByHandle( this, handle )
      mex_ball( 'copy', this.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Translate ball by vector
    function translate( this, other_obj )
      mex_ball( 'translate', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform ball by 4x4 affine transformation matrix
    function transform( this, affine )
      mex_ball( 'transform', this.objectHandle, affine );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ACME point is inside the ball
    function out = isInside( this, other_obj )
      if (other_obj.type() == "point")
        out = mex_ball( 'isInside', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_ball::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ball is degenerated
    function out = isDegenerated( this )
      out = mex_ball( 'isDegenerated', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if balls are approximatively equal
    function out = isApprox( this, other_obj )
      if (other_obj.type() == "ball")
        out = mex_ball( 'isApprox', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_ball::isApprox(): other_obj must be an ACME ball object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get ball minimum and maximum points of object instance
    function [out1, out2] = clamp( this )
      [out1, out2] = mex_ball( 'clamp', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get ball perimeter
    function out = area( this )
      out = mex_ball( 'area', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get ball volume
    function out = volume( this )
      out = mex_ball( 'volume', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ball is parallel to an ACME object
    function out = isParallel( this, other_obj )
      out = mex_ball( 'isParallel', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ball is orthogonal to an ACME object
    function out = isOrthogonal( this, other_obj )
      out = mex_ball( 'isOrthogonal', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ball is collinear to an ACME object
    function out = isCollinear( this, other_obj )
      out = mex_ball( 'isCollinear', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ball is coplanar to an ACME object
    function out = isCoplanar( this, other_obj )
      out = mex_ball( 'isCoplanar', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Intersect ball with an ACME object
    function out = intersection( this, other_obj )
      [handle, type] = mex_ball( 'intersection', this.objectHandle, other_obj.objectHandle, other_obj.type() );
      out = eval( strcat( 'acme_', type, '()') );
      out.copyByHandle( handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Display object data
    function disp( this )
      disp( [ [this.getRadius(), NaN, NaN]', this.getCenter().get()] ); %[this.getRadius() 0 0]',
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Plot ball object
    function plot( this, figure_name, color )
      figure_name;
      hold on;
      radius = this.getRadius();
      center = this.getCenter().get();
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
    function out = type( this )
      out = 'ball';
    end
  end
end
