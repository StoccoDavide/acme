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

% Create line/ray/segment
% obj_1 = acme_line([1 -1 1]', [-1 1 -1]');
% obj_1.normalize();
% obj_2 = acme_line([1 1 -1]', [-1 -1 1]');
% obj_2.normalize();
obj_1 = acme_ray([1 -1 1]', [-1 1 -1]');
obj_1.normalize();
obj_2 = acme_ray([1 1 -1]', [-3 -3 3]');
obj_2.normalize();
% obj_1 = acme_segment([1 -1 1]', [-1 1 -1]');
% obj_2 = acme_segment([1 1 -1]', [-1 -1 1]');

% Intersect
point = obj_1.intersection(obj_2);

% Plot output
out = figure;
hold on;
axis equal;
obj_1.plot(out, 'red', 15)
obj_2.plot(out, 'blue', 15)
point.plot(out, 'green')
