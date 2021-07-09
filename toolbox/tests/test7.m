% Clear workspace

clc;
clear all;
close all;

% Create sphere

i1 = acme_sphere(3, [1 2 3]');

% Create line, ray, plane and segment

l1 = acme_line([0 0 0]', [1 1 1]');
r1 = acme_ray([0 0 0]', [3 3 3]');
p1 = acme_plane([1 2 1]', [-1 -1 1]');
s1 = acme_line([0 0 0]', [1 3 3]');

out1 = i1.intersection(l1);
out2 = i1.intersection(r1);
out3 = i1.intersection(p1);
out4 = i1.intersection(s1);

% Plot output

out = figure;
axis('equal');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
i1.plot(out, 'red')
l1.plot(out, 'blue')
r1.plot(out, 'green', 1)
p1.plot(out, 'yellow')
s1.plot(out, 'cyan')
out1.plot(out, 'red')
out2.plot(out, 'magenta')
out3.plot(out, 'cyan')
out4.plot(out, 'blue')