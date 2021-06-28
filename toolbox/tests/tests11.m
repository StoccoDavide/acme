clc;
clear all;
close all;

% Create circle

%t_1 = acme_triangle( [0 -2.5 0.01]',  [2.5 2.5 0.01]',  [2.5 -2.5 0.01]');
t_1 = acme_triangle( [0 -2.5  0]',   [ 0 2.5 0.01]',   [ 0 -2.5  0.01]');

c_1 = acme_circle(0.310556, [0 0.072 0.26]', [0 1 0]');

s_1 = acme_line([0 0.072 0.005144]', [0 0.072 0.570556]');
s_1.normalize()

% Intersect

o_1 = t_1.intersection(c_1)

% Plot output

out = figure;
hold on;
axis equal;
t_1.plot(out, 'red')
c_1.plot(out, 'blue')
s_1.plot(out, 'blue')
o_1.plot(out, 'yellow')
%o_2.plot(out, 'black')