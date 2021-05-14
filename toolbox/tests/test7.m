clc
clear all
close all

% Create points

p1 = acme_point([0 0 0]');
p2 = acme_point([3 0 0]');
p3 = acme_point([0 3 0]')

% Create triangle


t1 = acme_triangle(p1.get(), p2.get(), p3.get());
% 
% s1 = t1.edge(1, 2)
% 
 p4 = t1.getVertex3()
 
 p4.set([2, 3, 4]')
 p4
 t1