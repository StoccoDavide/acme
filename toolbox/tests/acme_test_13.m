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

% Create segments, disk and plane
s_1 = acme_segment([ 0.0 1 1.6]', [1 0 -1]');
s_2 = acme_segment([-2 0 0.5]', [-1.1 0 0.5]');

c_1 = acme_disk(1, [0 0 0.5]', [0 0 1]');
p_1 = acme_plane([0 0 0.5]', [0 0 1]');

% Intersect
o_1 = s_1.intersection(c_1)
o_2 = s_2.intersection(c_1)
o_3 = s_1.intersection(p_1)
o_4 = s_2.intersection(p_1)

% Plot output
out = figure;
hold on;
axis equal;
p_1.plot(out, 'black')
s_1.plot(out, 'red')
s_2.plot(out, 'blue')
o_1.plot(out, 'green')
o_2.plot(out, 'yellow')
o_3.plot(out, 'yellow')
o_4.plot(out, 'green')
