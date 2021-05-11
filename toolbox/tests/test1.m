clc;
clear all;
close all;

% Create points

p1 = acme_point([0  2 1]')
p2 = acme_point([0 -1 1]')
p3 = acme_point([0  1 1]')
p4 = acme_point([0 -2 1]')

% Create segments

s1 = acme_segment(p1.get(), p2.get())
s2 = acme_segment(p3.get(), p4.get())

% Intersect segments

s3 = s1.intersection(s2)

% Plot output

out = figure;
s1.plot(out, 'red')
s2.plot(out, 'blue')
s3.plot(out, 'green')