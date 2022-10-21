% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%                                                                     %
% The ACME project                                                    %
%                                                                     %
% Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            %
%                                                                     %
% The ACME project and its components are supplied under the terms of %
% the open source BSD 2-Clause License. The contents of the ACME      %
% project and its components may not be copied or disclosed except in %
% accordance with the terms of the BSD 2-Clause License.              %
%                                                                     %
% URL: https://opensource.org/licenses/BSD-2-Clause                   %
%                                                                     %
%    Davide Stocco                                                    %
%    Department of Industrial Engineering                             %
%    University of Trento                                             %
%    e-mail: davide.stocco@unitn.it                                   %
%                                                                     %
%    Enrico Bertolazzi                                                %
%    Department of Industrial Engineering                             %
%    University of Trento                                             %
%    e-mail: enrico.bertolazzi@unitn.it                               %
%                                                                     %
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

clear all;
clear functions;
clear mex;
clc;

if ismac
  oldPath = getenv('PATH');
  newPath = strcat(oldPath, pathsep, '/usr/local/bin');
  setenv('PATH', newPath);
elseif isunix
elseif ispc
  oldPath = getenv('PATH');
  newPath = strcat(oldPath, pathsep, 'C:\Program Files\CMake\bin');
  setenv('PATH', newPath);
end

old_dir = cd(fileparts(which(mfilename)));
cd('..');
%system('rmdir /S build');
numcores = feature('numcores');

if isfolder('build')
  rmdir('build','s')
end
if false
  CMD1 = 'cmake -G "Ninja" -DCMAKE_BUILD_TYPE:STRING=Debug -Bbuild -S .';
  CMD2 = 'ninja -C build';
else
  CMD1 = 'cmake -G "Ninja" -DCMAKE_BUILD_TYPE:STRING=Release -Bbuild -S .';
  CMD2 = 'ninja -C build';
end

fprintf( '%s\n%s\n', CMD1, CMD2 );

system(CMD1);
system(CMD2);

cd(old_dir);