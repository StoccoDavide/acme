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

% Create planes
p1 = acme_plane([1.2 1 0]', 1/sqrt(1)*[0 0 1]');
p2 = acme_plane([1.2 2 0]', 1/sqrt(3)*[1 1 1]');
p3 = acme_plane([1.2 3 0]', 1/sqrt(3)*[-1 1 1]');

% Intersect segments
out1 = p1.intersection(p2);
out1.type();
out2 = p1.intersection(p3);
out2.type();
out3 = out1.intersection(out2);
out3.type();

% Plot output
out = figure;
axis('equal');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
p1.plot(out, 'red')
p2.plot(out, 'blue')
p3.plot(out, 'green')
out1.plot(out, 'yellow')
out2.plot(out, 'magenta')
out3.plot(out, 'cyan')
