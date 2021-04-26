% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%                                                                     %
% The ACME project - Release Version 0.0.0                            %
%                                                                     %
% Copyright (c) 2020 Davide Stocco, All Rights Reserved.              %
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
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

clc;
clear functions;

old_dir = cd(fileparts(which(mfilename)));

NAMES = { ...
  
};

LIB_NAMES = { ...
  
};

MROOT = matlabroot;

CMDBASE = 'mex -c -largeArrayDims -Isrc -Isrc/Utils ';
if isunix
  CMDBASE = [CMDBASE, 'CXXFLAGS="\$CXXFLAGS -Wall -O2 -g" '];
elseif ispc
end

%for k=1:length(NAMES)
%  N=NAMES{k};
%  disp('---------------------------------------------------------');
%  fprintf(1,'Compiling: %s\n',N)
%  CMD = [CMDBASE ' -c src_mex/mex_' N '.cc' ];
%  disp('---------------------------------------------------------');
%  disp(CMD);
%  eval(CMD);
%end

LIB_OBJS = '';
for k=1:length(LIB_NAMES)
  [filepath,bname,ext] = fileparts(LIB_NAMES{k});
  NAME = [' src/', filepath, '/', bname, ext ];
  if isunix
    LIB_OBJS = [ LIB_OBJS, bname, '.o ' ];
  elseif ispc
    LIB_OBJS = [ LIB_OBJS, bname, '.obj ' ];
  end
  CMD = [CMDBASE ' -c ' NAME];
  disp('---------------------------------------------------------');
  disp(CMD);
  eval(CMD);
end

for k=1:length(NAMES)
  N=NAMES{k};
  disp('---------------------------------------------------------');
  fprintf(1,'Compiling: %s\n',N);

  CMD = [ 'while mislocked(''' N '''); munlock(''' N '''); end;'];
  eval(CMD);

  CMD = [ 'mex -Isrc -output bin/', N ];
  CMD = [ CMD, ' -largeArrayDims src_mex/mex_', N ];
  CMD = [ CMD, '.cc ', LIB_OBJS ];

  if ismac
    CMD = [CMD, ' CXXFLAGS="\$CXXFLAGS -Wall -O2 -g"'];
  elseif isunix
    % Workaround for MATLAB 2020 that force dynamic link with old libstdc++
    % solution: link with static libstdc++
    % ARCH  = computer('arch');
    % PATH1 = [MROOT, '/bin/', ARCH];
    % PATH2 = [MROOT, '/extern/bin/', ARCH];
    CMD = [ CMD, ...
      ' CXXFLAGS="\$CXXFLAGS -Wall -O2 -g"' ...
      ' LDFLAGS="\$LDFLAGS -static-libgcc -static-libstdc++"' ...
      ' LINKLIBS="-ldl -L\$MATLABROOT/bin/\$ARCH -L\$MATLABROOT/extern/bin/\$ARCH -lMatlabDataArray -lmx -lmex -lmat -lm "' ...
    ];
  elseif ispc
  end

  disp(CMD);
  eval(CMD);
end

if isunix
  delete *.o
else
  delete *.obj
end

cd(old_dir);

disp('----------------------- DONE ----------------------------');