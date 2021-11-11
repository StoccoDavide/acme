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
    function this = acme_disk( varargin )
      this.objectHandle = mex_disk( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Create C++ pointer to disk object instance
    function delete( this )
      mex_disk( 'delete', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get disk radius
    function out = getRadius( this )
      out = mex_disk( 'getRadius', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get disk center as ACME point object
    function out = getCenter( this )
      out = acme_point();
      out.copyByHandle( mex_disk( 'getCenter', this.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get disk normal
    function out = getNormal( this )
      out = mex_disk( 'getNormal', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set disk radius
    function setRadius( this, radius )
      mex_disk( 'setRadius', this.objectHandle, radius );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set disk center with an ACME point object
    function setCenter( this, other_obj )
      mex_disk( 'setCenter', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Set disk normal
    function setNormal( this, other_obj )
      mex_disk( 'setNormal', this.objectHandle, other_obj );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy segment object from another segment
    function copy( this, other_obj )
      if (other_obj.type() == "disk")
        mex_disk( 'copy', this.objectHandle, other_obj.objectHandle );
      else
        error('mex_disk::copy(): other_obj must be an ACME disk object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Copy disk object from another disk handle
    function copyByHandle( this, handle )
      mex_disk( 'copy', this.objectHandle, handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Translate disk by vector
    function translate( this, other_obj )
      mex_disk( 'translate', this.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Transform disk by 4x4 affine transformation matrix
    function transform( this, affine )
      mex_disk( 'transform', this.objectHandle, affine );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if ACME point is inside the disk 
    function out = isInside( this, other_obj )
      if (other_obj.type() == "point")
        out = mex_disk( 'isInside', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_disk::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if disk is degenerated
    function out = isDegenerated( this )
      out = mex_disk( 'isDegenerated', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if disks are approximatively equal
    function out = isApprox( this, other_obj )
      if (other_obj.type() == "disk") 
        out = mex_disk( 'isApprox', this.objectHandle, other_obj.objectHandle );
      else
         error('mex_disk::isApprox(): other_obj must be an ACME disk object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Normalize disk normal vector
    function normalize( this )
      mex_disk( 'normalize', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get disk laying plane
    function out = layingPlane( this )
     out = acme_plane();
     out.copyByHandle( mex_disk( 'layingPlane', this.objectHandle ) );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Reverse disk normal direction
    function reverse( this )
      mex_disk( 'reverse', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get disk minimum and maximum points of object instance
    function [out1, out2] = clamp( this )
      [out1, out2] = mex_disk( 'clamp', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get disk perimeter
    function out = perimeter( this )
      out = mex_disk( 'perimeter', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Get disk perimeter
    function out = area( this )
      out = mex_disk( 'area', this.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if disk is parallel to an ACME object
    function out = isParallel( this, other_obj )
      out = mex_disk( 'isParallel', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if disk is orthogonal to an ACME object
    function out = isOrthogonal( this, other_obj )
      out = mex_disk( 'isOrthogonal', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if disk is collinear to an ACME object
    function out = isCollinear( this, other_obj )
      out = mex_disk( 'isCollinear', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Check if disk is coplanar to an ACME object 
    function out = isCoplanar( this, other_obj )
      out = mex_disk( 'isCoplanar', this.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Intersect disk with an ACME object
    function out = intersection( this, other_obj )
      [handle, type] = mex_disk( 'intersection', this.objectHandle, other_obj.objectHandle, other_obj.type() );
      out = eval( strcat( 'acme_', type, '()') );
      out.copyByHandle( handle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Display object data
    function disp( this )
      disp( [ [this.getRadius(), NaN, NaN]', this.getCenter().get(),  this.getNormal()] ); %[this.getRadius() 0 0]',
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    %> Plot disk object
    function plot( this, figure_name, color )
      radius = this.getRadius();
      center = this.getCenter().get();
      normal = this.getNormal();
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
    function out = type( this )
      out = 'disk';
    end
  end
end
