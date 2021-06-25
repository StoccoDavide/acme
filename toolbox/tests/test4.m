clc;
clear all;
close all;

% Create circle

s1 = acme_segment([1.49675 -142.294 0.236235]', [1.64152 -142.294 0.236235]');
l1 = acme_line([0 -140.54 0.236235]', [1 0 0]');

% Intersect

p1 = s1.isCollinear(l1)

% Plot output

out = figure;
hold on;
axis equal;
s1.plot(out, 'red')
l1.plot(out, 'blue')
s1.plot(out, 'black')

