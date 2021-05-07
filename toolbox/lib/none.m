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

classdef none < entity

  methods
    function self = none( self )
    % 
      self.objectHandle = mex_none( 'new' );
    end
    % --------------------------------------------------------------------
    %
    function delete( self )
      % Destroy the C++ class instance
      mex_none( 'delete', self.objectHandle );
    end
    % --------------------------------------------------------------------
    %>
    function disp( self )
      disp('none');
    end
    % --------------------------------------------------------------------
    %>
    function plot( self, figure_name )
      figure_name;
      hold on;
      hold off;
    end
    % --------------------------------------------------------------------
    % OVERRIDE
    %--------------------------------------------------------------------
    %>
    function P = type( self )
      P = 'none';
    end
  end
end
