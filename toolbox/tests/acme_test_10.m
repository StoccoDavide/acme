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

% Create segments and disk
c_1 = acme_disk(0.3, [0 0 0.4]', [0 1 0]');
p_1 = acme_plane([0 0 0]', [0 0 1]');
p_2 = acme_plane([0 0 0.4]', [0 1 0]');

% Intersect
o_1 = p_1.intersection(p_2)
o_2 = o_1.intersection(c_1)

% Plot output
out = figure;
hold on;
axis equal;
p_1.plot(out, 'black')
c_1.plot(out, 'red')
o_1.plot(out, 'green')
