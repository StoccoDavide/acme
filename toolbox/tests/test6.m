clc
clear all
close all

% Create points

p1a = acme_point([0 0 0]');
p2a = acme_point([3 0 0]');
p3a = acme_point([0 3 0]');
p1b = acme_point([1 0 1]');
p2b = acme_point([3 0 -1]');
p3b = acme_point([0 2 -1]');

p4 = acme_point([1 1  1]');
p5 = acme_point([1 1.2 -1]');

% Create triangle and segment

s1 = acme_segment(p4.get(), p5.get());
t1 = acme_triangle(p1a.get(), p2a.get(), p3a.get());
t2 = acme_triangle(p1b.get(), p2b.get(), p3b.get());
p1 = acme_plane([1.2 1.5 0]', 1/sqrt(3)*[-1 1 1]')
p2 = acme_plane([1.2 1.5 0]', 1/sqrt(3)*[1 1 1]')

% Intersect segments

out1 = t1.intersection(t2);
out1.type();
out2 = t1.intersection(s1);
out2.type();
out3 = t2.intersection(s1);
out3.type();
out4 = p1.intersection(s1);
out4.type();
out5 = p1.intersection(t1);
out5.type();
out6 = p1.intersection(t2);
out6.type();

% Plot output

out = figure;
axis('equal');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
s1.plot(out, 'red')
t1.plot(out, 'blue')
t2.plot(out, 'green')
p1.plot(out, 'yellow')
out1.plot(out, 'red')
out2.plot(out, 'magenta')
out3.plot(out, 'cyan')
out4.plot(out, 'blue')
out5.plot(out, 'red')
out6.plot(out, 'magenta')