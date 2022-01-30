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

