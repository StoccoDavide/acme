%%-------------------------------------------------------------------------%%
%%                                                                         %%
%%  Copyright (C) 2020                                                     %%
%%                                                                         %%
%%         , __                 , __                                       %%
%%        /|/  \               /|/  \                                      %%
%%         | __/ _   ,_         | __/ _   ,_                               %%
%%         |   \|/  /  |  |   | |   \|/  /  |  |   |                       %%
%%         |(__/|__/   |_/ \_/|/|(__/|__/   |_/ \_/|/                      %%
%%                           /|                   /|                       %%
%%                           \|                   \|                       %%
%%                                                                         %%
%%      Enrico Bertolazzi                                                  %%
%%      Dipartimento di Ingegneria Industriale                             %%
%%      Universita` degli Studi di Trento                                  %%
%%      email: enrico.bertolazzi@unitn.it                                  %%
%%                                                                         %%
%%-------------------------------------------------------------------------%%
kind = 'chebyshev';
pp = OPoly(kind);

x = -1:0.00001:1;

subplot(2,2,1);
y = pp.eval( 2, x );
plot( x, y );
title(kind);

subplot(2,2,2);
y = pp.eval( 5, x );
plot( x, y );
title(kind);

subplot(2,2,3);
[y,~,s] = pp.eval2( 4, x );
plot( x, zeros(size(x)));
hold on
plot( x, y );
plot( x, s );
title(kind);

subplot(2,2,4);
n = 10;
[y,s] = pp.sequence( n, x );
hold on;
for k=1:n
  yy = reshape(y(k,1,:),1,[]);
  plot( x, yy );
end
title(kind);
