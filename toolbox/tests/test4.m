clc;
clear all;
close all;

% Create circle

s1 = acme_sphere(2, [0.5 1.0 1.5]');
p1 = acme_plane([0 1.5 0]', [2 0 0]');
l1 = acme_line([0 0.5 0]', [0 2 0]');

% Intersect

c1 = s1.intersection(p1)
s2 = s1.intersection(l1)

% Plot output

out = figure;
hold on;
axis equal;
s1.plot(out, 'red')
p1.plot(out, 'green')
l1.plot(out, 'blue')
c1.plot(out, 'yellow')
s2.plot(out, 'black')

