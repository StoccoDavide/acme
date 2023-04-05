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

classdef acme_ray < acme_entity
  %>
  %> Class container for ACME ray object
  %>
  methods
    %> Create a new C++ pointer to ray object instance
    function this = acme_ray( varargin )
      this.objectHandle = mex_ray( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Delete C++ pointer to ray object instance
    function delete( this )
      mex_ray( 'delete', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get ray origin as ACME point object
    function out = getOrigin( this )
      out = acme_point();
      out.copyByHandle( mex_ray( 'getOrigin', this.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get ray direction
    function out = getDirection( this )
      out = mex_ray( 'getDirection', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set ray origin with an ACME point object
    function setOrigin( this, other_obj )
      mex_ray( 'setOrigin', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set ray direction
    function setDirection( this, other_obj )
      mex_ray( 'setDirection', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy ray object from another ray
    function copy( this, other_obj )
      if (other_obj.type() == "ray")
        mex_ray( 'copy', this.objectHandle, other_obj.objectHandle );
      else
        error('mex_ray::copy(): other_obj must be an ACME ray object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy ray object from another ray handle
    function copyByHandle( this, handle )
      mex_ray( 'copy', this.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Translate ray by vector
    function translate( this, other_obj )
      mex_ray( 'translate', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform ray by 4x4 affine transformation matrix
    function transform( this, varargin )
      mex_ray( 'transform', this.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ACME point is inside the ray 
    function out = isInside( this, other_obj )
      if (other_obj.type() == "point")
        out = mex_ray( 'isInside', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_ray::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ray is degenerated
    function out = isDegenerated( this )
      out = mex_ray( 'isDegenerated', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if rays are approximatively equal
    function out = isApprox( this, other_obj )
      if (other_obj.type() == "ray") 
        out = mex_ray( 'isApprox', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_ray::isApprox(): other_obj must be an ACME ray object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Normalize direction vector
    function normalize( this )
      mex_ray( 'normalize', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform ray to vector
    function out = toVector( this )
      out = mex_ray( 'toVector', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform ray to normalized vector
    function out = toNormalizedVector( this )
      out = mex_ray( 'toNormalizedVector', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Swap ray vertices
    function reverse( this )
      mex_ray( 'reverse', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ray is parallel to an ACME object
    function out = isParallel( this, other_obj )
      out = mex_ray( 'isParallel', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ray is orthogonal to an ACME object
    function out = isOrthogonal( this, other_obj )
      out = mex_ray( 'isOrthogonal', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ray is collinear to an ACME object
    function out = isCollinear( this, other_obj )
      out = mex_ray( 'isCollinear', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ray is coplanar to an ACME object 
    function out = isCoplanar( this, other_obj )
      out = mex_ray( 'isCoplanar', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Intersect ray with an ACME object
    function out = intersection( this, other_obj )
      [handle, type] = mex_ray( 'intersection', this.objectHandle, other_obj.objectHandle, other_obj.type() );
      out = eval( strcat( 'acme_', type, '()' ) );
      out.objectHandle = handle;
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
    %> Plot ray object
    function plot( this, figure_name, alpha color, limit )
      figure_name;
      hold on;
      origin = this.getOrigin().get();
      direction = this.getDirection();
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
    function out = type( this )
      out = 'ray';
    end
  end
end
