clc
clear all
close all

% Create points

p1 = acme_point([0 0 0]')
p2 = acme_point([3 0 0]')
p3 = acme_point([0 3 0]')

p4 = acme_point([1 1  1]')
p5 = acme_point([1 1.2 -1]')

% Create triangle and segment

s1 = acme_segment(p4.get(), p5.get())
t1 = acme_triangle(p1.get(), p2.get(), p3.get())

% Intersect segments

p6 = t1.intersection(s1)

% Plot output

out = figure;
s1.plot(out, 'red')
t1.plot(out, 'blue')
p6.plot(out, 'green')