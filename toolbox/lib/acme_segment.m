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

classdef acme_segment < acme_entity
  %
  % Class container for ACME segment object
  %
  methods
    function self = acme_segment( varargin )
      % Create a new C++ pointer to segment object instance
      self.objectHandle = mex_segment( 'new', varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function delete( self )
      % Delete C++ pointer to segment object instance
      mex_segment( 'delete', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = type( self )
      % Get object type as string
      P = 'segment';
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getVertex1( self )
      % Get segment vertex 1 as ACME point object
      P = acme_point();
      P.objectHandle = mex_segment( 'getVertex1', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = getVertex2( self )
      % Get segment vertex 2 as ACME point object
      P = acme_point();
      P.objectHandle = mex_segment( 'getVertex2', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setVertex1( self, other_obj )
      % Set segment vertex 1 with an ACME point object
      mex_segment( 'setVertex1', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function setVertex2( self, other_obj )
      % Set segment vertex 2 with an ACME point object
      mex_segment( 'setVertex2', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function copy( self, other_obj )
      % Copy segment object from another segment
      if (other_obj.type() == "segment")
        mex_segment( 'copy', self.objectHandle, other_obj.objectHandle );
      else
        error('mex_segment::copy(): other_obj must be an ACME segment object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function translate( self, other_obj )
     % Translate segment by vector
      mex_segment( 'translate', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function transform( self, varargin )
      % Transform segment by 4x4 affine transformation matrix
      mex_segment( 'transform', self.objectHandle, varargin{:} );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isInside( self, other_obj )
      % Check if ACME point is inside the segment 
      if (other_obj.type() == "point")
        P = mex_segment( 'isInside', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_segment::isInside(): other_obj must be an ACME point object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isDegenerated( self )
      % Check if segment is degenerated
      P = mex_segment( 'isDegenerated', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isApprox( self, other_obj )
      % Check if segments are approximatively equal
      if (other_obj.type() == "segment") 
        P = mex_segment( 'isApprox', self.objectHandle, other_obj.objectHandle );
      else
         error('mex_segment::isApprox(): other_obj must be an ACME segment object type.');
      end
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = centroid( self )
      % Get segment centroid as ACME point objecty instance
      P = point();
      P.objectHandle = mex_segment( 'centroid', self.objectHandle, other_obj.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = toVector( self )
       % Transform segment to vector
      P = mex_segment( 'toVector', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = toNormalizedVector( self )
      % Transform segment to normalized vector
      P = mex_segment( 'toNormalizedVector', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function swap( self )
      % Swap segment vertices
      mex_segment( 'swap', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = clamp( self )
      % Get segment minimum bounding box as ACME aabb object instance
      P = acme_aabb();
      P.objectHandle = mex_segment( 'clamp', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = length( self )
      % Get segment length
      P = mex_segment( 'length', self.objectHandle );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isParallel( self, other_obj )
      % Check if segment is parallel to an ACME object
      P = mex_segment( 'isParallel', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isOrthogonal( self, other_obj )
      % Check if segment is orthogonal to an ACME object
      P = mex_segment( 'isOrthogonal', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCollinear( self, other_obj )
      % Check if segment is collinear to an ACME object
      P = mex_segment( 'isCollinear', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = isCoplanar( self, other_obj )
      % Check if segment is coplanar to an ACME object 
      P = mex_segment( 'isCoplanar', self.objectHandle, other_obj.objectHandle, other_obj.type() );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function P = intersection( self, other_obj )
      % Intersect segment with an ACME object
      [Handle, type] = mex_segment( 'intersection', self.objectHandle, other_obj.objectHandle, other_obj.type() );
      P = eval( strcat( 'acme_', type, '()' ) );
      P.objectHandle = Handle;
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function disp( self )
      % Display object data
      disp( [self.getVertex1().get(), self.getVertex2().get()] );
    end
    %
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    %
    function plot( self, figure_name, color )
      % Plot segment object
      figure_name;
      hold on;
      Vertex1 = self.getVertex1().get();
      Vertex2 = self.getVertex2().get();
      scatter3(Vertex1(1), Vertex1(2), Vertex1(3), color, 'filled');
      scatter3(Vertex2(1), Vertex2(2), Vertex2(3), color, 'filled');
      X = [Vertex1(1), Vertex2(1)];
      Y = [Vertex1(2), Vertex2(2)];
      Z = [Vertex1(3), Vertex2(3)];
      plot3(X, Y, Z,'-', 'Color', color)
      hold off;
    end
  end
end
