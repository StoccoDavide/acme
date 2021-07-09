% Clear workspace

clc;
clear all;
close all;

% Create points

c1 = acme_disk(2, [1 2 3]', [1 2 3]');
l1 = acme_ray([0 0 0]', 3*[1.2 1.5 1]');

% Intersect segments

out1 = c1.intersection(l1);
out1.type()

% Plot output

out = figure;
axis('equal');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
c1.plot(out, 'blue')
l1.plot(out, 'red', 3)
out1.plot(out, 'red')
