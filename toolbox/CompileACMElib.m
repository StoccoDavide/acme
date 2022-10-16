clc;
clear functions;
[~,mexLoaded] = inmem('-completenames');

old_dir = cd(fileparts(which(mfilename)));

NAMES = {
  'mex_none',     ...
  'mex_point',    ...
  'mex_line',     ...
  'mex_ray',      ...
  'mex_plane',    ...
  'mex_segment',  ...
  'mex_triangle', ...
  'mex_disk',     ...
  'mex_ball',   ...
  'mex_aabb',     ...
};

lst_cc = dir('./src/*.cc');

LIB_SRCS = '';
LIB_OBJS = '';
MEX_CMD  = 'mex -largeArrayDims -I./src -I./src/Utils -I./src/acme ';

CMD = [ MEX_CMD ' -c '];
if isunix
  CMD = [CMD, 'CXXFLAGS="\$CXXFLAGS -Wall -O2 -g" '];
elseif ispc
end
CMD = [ CMD, LIB_SRCS ];

for kk=1:length(lst_cc)
  name     = lst_cc(kk).name(1:end-3);
  LIB_SRCS = [ LIB_SRCS, ' ../src/', name, '.cc' ];
  if isunix
    LIB_OBJS = [ LIB_OBJS, name, '.o ' ];
  elseif ispc
    LIB_OBJS = [ LIB_OBJS, name, '.obj ' ];
  end
  CMD1 = [ CMD ' ./src/', name, '.cc' ];
  disp('---------------------------------------------------------');
  fprintf(1,'Compiling: %s.cc\n',name);
  eval(CMD1);
end

MROOT = matlabroot;

for k=1:length(NAMES)
  N=NAMES{k};
  disp('=========================================================');
  fprintf(1,'Compiling: %s.cc\n',N);

  CMD = [ 'while mislocked(''' N '''); munlock(''' N '''); end;'];
  eval(CMD);

  CMD = [ MEX_CMD, ' -output ./bin/', N ];
  CMD = [ CMD, ' -largeArrayDims ./src_mex/', N, '.cc ', LIB_OBJS ];
  if ismac
    CMD = [CMD, ' CXXFLAGS="\$CXXFLAGS -Wall -O2 -g"'];
  elseif isunix
    % Workaround for MATLAB 2020 that force dynamic link with old libstdc++
    % solution: link with static libstdc++
    ARCH  = computer('arch');
    PATH1 = [MROOT, '/bin/', ARCH];
    PATH2 = [MROOT, '/extern/bin/', ARCH];
    CMD   = [ CMD, ...
      ' CXXFLAGS="\$CXXFLAGS -Wall -O2 -g"' ...
      ' LDFLAGS="\$LDFLAGS -static-libgcc -static-libstdc++"' ...
      ' LINKLIBS="-L' PATH1 ' -L' PATH2 ' -lMatlabDataArray -lmx -lmex -lmat -lm "' ...
    ];
  elseif ispc
  end
  disp(CMD);
  eval(CMD);
end

for kk=1:length(lst_cc)
  name = lst_cc(kk).name(1:end-3);
  if isunix
    delete([ name, '.o' ]);
  elseif ispc
    delete([ name, '.obj' ]);
  end
end

cd(old_dir);

disp('----------------------- DONE ----------------------------');
