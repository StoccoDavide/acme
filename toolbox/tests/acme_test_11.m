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

% Clear workspace
clc;
clear all;
close all;

% Create disk
t_1 = acme_triangle( [0 -2.5 0.01]',  [2.5 2.5 0.01]',  [2.5 -2.5 0.01]');
c_1 = acme_disk(0.310556, [0 0.072 0.26]', [0 1 0]');
l_1 = acme_line([0 0.072 0.005144]', [0 0.072 0.570556]');
l_1.normalize()

% Intersect
o_1 = t_1.intersection(c_1)

% Plot output
out = figure;
hold on;
axis equal;
t_1.plot(out, 'red')
c_1.plot(out, 'blue')
l_1.plot(out, 'blue')
o_1.plot(out, 'yellow')
