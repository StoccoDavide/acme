% Clear workspace
clc;
clear all;
close all;

% Create disks
d1 = acme_disk(2,[0,0,0]',[0,1,0]');
d2 = acme_disk(1,[0,0,0]',[1,1,0]');

% Perform intersection
e1 = d1.intersection(d2);

% Check output entity type
disp(['Ouput entity is of type: ', e1.type()]);

% Plot output
f1 = figure;
d1.plot(f1,'red');
d2.plot(f1,'blue');
e1.plot(f1,'green');

xlabel('x');
ylabel('y');
zlabel('z');
grid on;
xlim([-2 2]);
ylim([-1 1.01]);
zlim([-2 2]);