clc;
clear all;
close all;

% Create circle

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