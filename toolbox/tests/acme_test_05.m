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

% Create points
p1 = acme_point([0 0 3]')
p2 = acme_point([3 0 0]')
p3 = acme_point([0 3 0]')
p4 = acme_point([0 1  1]')
p5 = acme_point([1 2 -1]')

% Create triangle and segment
s1 = acme_segment(p4.get(), p5.get())
t1 = acme_triangle(p1.get(), p2.get(), p3.get())

% Create aabbs
[b1_min, b1_max] = s1.clamp();
[b2_min, b2_max] = t1.clamp();
b1 = acme_aabb(b1_min, b1_max)
b2 = acme_aabb(b2_min, b2_max)

% Plot output
out = figure;
s1.plot(out, 'red')
t1.plot(out, 'blue')
b1.plot(out, 'black')
b2.plot(out, 'black')
