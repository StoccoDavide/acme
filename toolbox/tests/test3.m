% Clear workspace

clc;
clear all;
close all;

% Create disks

c1 = acme_disk(2, [0 0 0]', [0 1 0]')
c2 = acme_disk(1, [0 0 0]', [1 -1 0]')

% Intersect segments

s1 = c1.intersection(c2)

% Plot output

out = figure;
c1.plot(out, 'red')
c2.plot(out, 'blue')
s1.plot(out, 'green')
