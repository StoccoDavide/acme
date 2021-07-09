% Clear workspace

clc;
clear all;
close all;

% Create points

p1 = acme_point([0 0 3]')
p2 = acme_point([3 0 0]')
p3 = acme_point([0 3 0]')

p4 = acme_point([0 1  1]')
p5 = acme_point([1 2 -1]')

% Create triangle and segment

s1 = acme_segment(p4.get(), p5.get())
t1 = acme_triangle(p1.get(), p2.get(), p3.get())

% Create aabbs

b1 = s1.clamp()
b2 = t1.clamp()

% Plot output

out = figure;
s1.plot(out, 'red')
t1.plot(out, 'blue')
b1.plot(out, 'black')
b2.plot(out, 'black')

