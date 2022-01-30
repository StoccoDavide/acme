.. rst-class:: emphasize-children

.. rst-class:: html-toggle

Matlab Interface Manual
=======================

The interface is Object Oriented and you find the following
objects in the library:

- object ``none``;
- object ``point``;
- object ``line``;
- object ``ray``;
- object ``plane``;
- object ``segment``;
- object ``triangle``;
- object ``disk``;
- object ``ball``;
- object ``aabb``;


Installation mex/MATLAB interface
---------------------------------

In directory `src_mex` you find the C++ implementation of
the proposed algorithm with `mex` interface.
The easy way to build mex/MATLAB interface is to download
the compiled Toolbox at
`https://github.com/StoccoDavide/acme/releases <https://github.com/StoccoDavide/acme/releases>`__
and install it.
After installation in Matlab run the command ``CompileACMELib``.

If you want to compile the Toolbox by yourself

.. code-block:: bash

  cd toolbox
  ruby populate_toolbox.rb


run Matlab and from the comand windows of MATLAB:

.. code-block:: bash

  cd toolbox
  setup
  CompileACMELib
  open('../ACME.prj')


then compile toolbox and install.

Object `none`
-------------

The `none` class is represents nothing than nothing. If the polymorphic behaviour is
exploited this class will represent the null intersection between objects.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build an ACME none objects
  N1 = acme_none();
  N2 = acme_none();


Methods
^^^^^^^

.. code-block:: matlab

  % Copy none object from another none
  N1.copy( N2 );

  % Display object data
  N1.disp();

  % Get object type as string
  N1.type();


Object `point`
-------------

The `point` object represents a point the 3D space.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build an ACME point objects in the position `[x,y,z]`
  P1 = acme_point( [x, y, z]' );
  P2 = acme_point( x, y, z );


Methods
^^^^^^^

.. code-block:: matlab

  % Copy none object from another none
  P1.copy( P2 );

  % Display object data
  P1.disp();

  % Get object type as string
  P1.type();

  % Get point X axis component
  x = P1.getX();

  % Get point Y axis component
  y = P1.getY();

  % Get point Z axis component
  z = P1.getZ();

  % Get point axes components
  V1 = P1.get();

  % Set point X axis component
  P1.setX( x );

  % Set point Y axis component
  P1.setY( y );

  % Set point Z axis component
  P1.setZ( z );

  % Set point axes components `[x,y,z]`
  P1.set( [x, y, z]' );
  P1.set( x, y, z );

  % Translate point by vector `[x,y,z]`
  P1.translate( [x, y, z]' );

  % Transform point by 4x4 affine transformation matrix
  P1.transform( matrix );

  % Check if point is parallel to an ACME object
  B1 = P1.isParallel( P2 );

  % Check if point is orthogonal to an ACME object
  B1 = P1.isOrthogonal( P2 );

  % Check if point is colrayar to an ACME object
  B1 = P1.isColrayar( P2 );

  % Check if point is coplanar to an ACME object 
  B1 = P1.isCoplanar( P2 );

  % Intersect point with an ACME object
  P1 = P2.intersection( P2 );


Object `line`
-------------

The `line` object represents a line the 3D space.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build ACME line objects given origin `[ox,oy,oz]` and direction `[dx,dy,dz]`
  L1 = acme_line( [ox, oy, oz]', [dx, dy, dz]' );
  L2 = acme_line( ox, oy, oz, dx, dy, dz );


Methods
^^^^^^^

.. code-block:: matlab

  % Copy none object from another none
  L1.copy( L2 );

  % Display object data
  L1.disp();

  % Get object type as string
  L1.type();

  % Get line origin as ACME point object
  P1 = L1.getOrigin();

  % Get line direction
  V1 = L1.getDirection();

  % Set line origin with an ACME point object
  L1.setOrigin( P )

  % Set line direction as `[x, y, z]`
  L1.setDirection( [x, y, z]' )

  % Translate line by vector `[x, y, z]`
  L1.translate( [x, y, z]' );

  % Transform line by 4x4 affine transformation matrix
  L1.transform( matrix );

  % Check if ACME point is inside the line 
  B1 = L1.isInside( P );

  % Check if line is degenerated
  B1 = L1.isDegenerated();

  % Check if lines are approximatively equal
  B1 = L1.isApprox( L2 );

  % Normalize direction vector 
  L1.normalize();

  % Transform line to vector
  v1 = L1.toVector();

  % Transform line to normalized vector
  v1 = L1.toNormalizedVector();

  % Swap line direction
  L1.reverse();

  % Check if line is parallel to an ACME object
  B1 = L1.isParallel( L2 );

  % Check if line is orthogonal to an ACME object
  B1 = L1.isOrthogonal( L2 );

  % Check if line is collinear to an ACME object
  B1 = L1.isCollinear( L2 );

  % Check if line is coplanar to an ACME object 
  B1 = L1.isCoplanar( L2 );

  % Intersect line with an ACME object
  P1 = L2.intersection( L2 );


Object `ray`
------------

The `ray` object represents a ray the 3D space.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build ACME ray objects given origin `[ox,oy,oz]` and direction `[dx,dy,dz]`
  R1 = acme_ray( [ox, oy, oz]', [dx, dy, dz]' );
  R2 = acme_ray( ox, oy, oz, dx, dy, dz );


Methods
^^^^^^^

.. code-block:: matlab

  % Copy ray object from another ray
  R1.copy( R2 );

  % Display object data
  R1.disp();

  % Get object type as string
  R1.type();

  % Get ray origin as ACME point object
  P1 = R1.getOrigin();

  % Get ray direction
  V1 = R1.getDirection();

  % Set ray origin with an ACME point object
  R1.setOrigin( P )

  % Set ray direction as `[x, y, z]`
  R1.setDirection( [x, y, z]' )

  % Translate ray by vector `[x, y, z]`
  R1.translate( [x, y, z]' );

  % Transform ray by 4x4 affine transformation matrix
  R1.transform( matrix );

  % Check if ACME point is inside the ray 
  B1 = R1.isInside( P );

  % Check if ray is degenerated
  B1 = R1.isDegenerated();

  % Check if rays are approximatively equal
  B1 = R1.isApprox( R2 );

  % Normalize direction vector 
  R1.normalize();

  % Transform ray to vector
  v1 = R1.toVector();

  % Transform ray to normalized vector
  v1 = R1.toNormalizedVector();

  % Swap ray direction
  R1.reverse();

  % Check if ray is parallel to an ACME object
  B1 = R1.isParallel( R2 );

  % Check if ray is orthogonal to an ACME object
  B1 = R1.isOrthogonal( R2 );

  % Check if ray is colrayar to an ACME object
  B1 = R1.isColrayar( R2 );

  % Check if ray is coplanar to an ACME object 
  B1 = R1.isCoplanar( R2 );

  % Intersect ray with an ACME object
  P1 = R2.intersection( R2 );


Object `plane`
--------------

The `plane` object represents a plane the 3D space.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build ACME plane objects given origin `[ox,oy,oz]` and normal `[nx,ny,nz]`
  R1 = acme_plane( [ox, oy, oz]', [nx, ny, nz]' );
  R2 = acme_plane( ox, oy, oz, nx, ny, nz );


Methods
^^^^^^^

.. code-block:: matlab

  % Copy plane object from another plane
  P1.copy( P2 );

  % Display object data
  P1.disp();

  % Get object type as string
  P1.type();

  % Get plane origin as ACME point object
  P1 = P1.getOrigin();

  % Get plane normal
  V1 = L1.getNormal();

  % Set plane origin with an ACME point object
  P1.setOrigin( P )

  % Set plane normal as `[x, y, z]`
  P1.setNormal( [x, y, z]' )

  % Translate plane by vector `[x, y, z]`
  P1.translate( [x, y, z]' );

  % Transform plane by 4x4 affine transformation matrix
  P1.transform( matrix );

  % Check if ACME point is inside the plane 
  B1 = P1.isInside( P );

  % Check if plane is degenerated
  B1 = P1.isDegenerated();

  % Check if planes are approximatively equal
  B1 = P1.isApprox( P2 );

  % Normalize direction vector 
  P1.normalize();

  % Distance between an ACME point and plane
  d = P1.distance( self, other_obj )

  % Squared distance between an ACME point and plane
  d = P1.squaredDistance( self, other_obj )

  % Signed distance between an ACME point and plane
  d = P1.signedDistance( self, other_obj )

  % Transform line to normalized vector
  v1 = P1.toNormalizedVector();

  % Swap line direction
  P1.reverse();

  % Check if line is parallel to an ACME object
  B1 = P1.isParallel( P2 );

  % Check if line is orthogonal to an ACME object
  B1 = P1.isOrthogonal( P2 );

  % Check if line is collinear to an ACME object
  B1 = P1.isCollinear( P2 );

  % Check if line is coplanar to an ACME object 
  B1 = P1.isCoplanar( P2 );

  % Intersect line with an ACME object
  L1 = P1.intersection( P2 );


Object `segment`
----------------

The `segment` object represents a segment the 3D space.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build ACME segment objects given pointd `[px,py,pz]` and `[dx,dy,dz]`
  R1 = acme_segment( [px, py, pz]', [dx, dy, dz]' );
  R2 = acme_segment( px, py, pz, dx, dy, dz );


Methods
^^^^^^^

.. code-block:: matlab

  % Copy segment object from another segment
  S1.copy( P2 );

  % Display object data
  S1.disp();

  % Get object type as string
  S1.type();

  % Get segment vertex 1 as ACME point object
  P = S1.getVertex1();

  % Get segment vertex 2 as ACME point object
  P = S1.getVertex2();

  % Set segment vertex 1 with an ACME point object
  S1.setVertex1( P );

  % Set segment vertex 2 with an ACME point object
  S1.setVertex2( P );

  % Translate segment by vector `[x, y, z]`
  S1.translate( [x, y, z]' );

  % Transform segment by 4x4 affine transformation matrix
  S1.transform( matrix );

  % Check if ACME point is inside the segment 
  B1 = S1.isInside( P );

  % Check if segment is degenerated
  B1 = S1.isDegenerated();

  % Get segment centroid as ACME point objecty instance
  P = S1.centroid();

  % Check if segments are approximatively equal
  B1 = S1.isApprox( S2 );

  % Transform segment to normalized vector
  V1 = S1.toNormalizedVector();

  % Swap segment vertices
  S1.swap();

  % Get segment minimum and maximum points of object instance
  [out1, out2] = S1.clamp();

  % Get segment length
  L = S1.length();

  % Check if segment is parallel to an ACME object
  B1 = S1.isParallel( S2 );

  % Check if segment is orthogonal to an ACME object
  B1 = S1.isOrthogonal( S2 );

  % Check if segment is collinear to an ACME object
  B1 = S1.isCollinear( S2 );

  % Check if segment is coplanar to an ACME object 
  B1 = S1.isCoplanar( S2 );

  % Intersect segment with an ACME object
  P1 = S1.intersection( S2 );

Object `triangle`
----------------

The `triangle` object represents a triangle the 3D space.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build ACME triangle objects given pointd `[px,py,pz]` and `[dx,dy,dz]`
  T1 = acme_triangle( [px, py, pz]', [dx, dy, dz]' );
  T2 = acme_triangle( px, py, pz, dx, dy, dz );


Methods
^^^^^^^

.. code-block:: matlab

  % Copy triangle object from another triangle
  T1.copy( T2 );

  % Display object data
  T1.disp();

  % Get object type as string
  T1.type();

  % Get triangle vertex 1 as ACME point object
  P = T1.getVertex1();

  % Get triangle vertex 2 as ACME point object
  P = T1.getVertex2();

  % Get triangle vertex 3 as ACME point object
  P = T1.getVertex3();

  % Set triangle vertex 1 with an ACME point object
  T1.setVertex1( P );

  % Set triangle vertex 2 with an ACME point object
  T1.setVertex2( P );

  % Set triangle vertex 3 with an ACME point object
  T1.setVertex3( P );

  % Translate triangle by vector `[x, y, z]`
  T1.translate( [x, y, z]' );

  % Transform triangle by 4x4 affine transformation matrix
  T1.transform( matrix );

  % Check if ACME point is inside the triangle 
  B1 = T1.isInside( P );

  % Check if triangle is degenerated
  B1 = T1.isDegenerated();

  % Get triangle centroid as ACME point objecty instance
  P = T1.centroid();

  % Check if triangles are approximatively equal
  B1 = T1.isApprox( T2 );

  % Get triangle normal
  N = T1.normal();

  % Get triangle laying plane
  P1 = T1.layingPlane();

  % SGet triangle i-th edge
  T1.edge(i);

  % Swap triangle i-th and j-th vertex
  T1.swap(i,j);

  % Get triangle minimum and maximum points of object instance
  [out1, out2] = T1.clamp();

  % Get triangle perimeter
  P = T1.perimeter();

  % Get triangle area
  A = T1.area();

  % Check if triangle is parallel to an ACME object
  B1 = T1.isParallel( T2 );

  % Check if triangle is orthogonal to an ACME object
  B1 = T1.isOrthogonal( T2 );

  % Check if triangle is collinear to an ACME object
  B1 = T1.isCollinear( T2 );

  % Check if triangle is coplanar to an ACME object 
  B1 = T1.isCoplanar( T2 );

  % Intersect triangle with an ACME object
  L1 = T1.intersection( T2 );


Object `disk`
-------------

The `disk` object represents a disk the 3D space.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build ACME disk objects given radius `r`, center `[ox,oy,oz]` and normal `[nx,ny,nz]`
  D1 = acme_disk( r, [ox, oy, oz]', [nx, ny, nz]' );
  D2 = acme_disk( r, ox, oy, oz, nx, ny, nz );


Methods
^^^^^^^

.. code-block:: matlab

  % Copy disk object from another disk
  D1.copy( D2 );

  % Display object data
  D1.disp();

  % Get object type as string
  D1.type();

  %> Get disk radius
  R = D1.getRadius();

  %> Get disk center as ACME point object
  C = D1.getCenter();

  %> Get disk normal
  N = D1.getNormal();

  % Set disk radius
  D1.setRadius( R );

  % Set disk center with an ACME point object
  D1.setCenter( P );

  % Set disk normal as `[x, y, z]`
  D1.setNormal( `[x, y, z]` );

  % Translate disk by vector `[x, y, z]`
  D1.translate( [x, y, z]' );

  % Transform disk by 4x4 affine transformation matrix
  D1.transform( matrix );

  % Check if ACME point is inside the disk 
  B1 = D1.isInside( P );

  % Check if disk is degenerated
  B1 = D1.isDegenerated();

  % Check if disks are approximatively equal
  B1 = D1.isApprox( T2 );

  % Normalize disk normal vector
  D1.normalize();

  % Get disk laying plane
  P1 = D1.layingPlane();

  % Reverse disk normal direction
  D1.reverse();

  % Get disk minimum and maximum points of object instance
  [out1, out2] = D1.clamp();

  % Get disk perimeter
  P = D1.perimeter();

  % Get disk area
  A = D1.area();

  % Check if disk is parallel to an ACME object
  B1 = D1.isParallel( D2 );

  % Check if disk is orthogonal to an ACME object
  B1 = D1.isOrthogonal( D2 );

  % Check if disk is collinear to an ACME object
  B1 = D1.isCollinear( D2 );

  % Check if disk is coplanar to an ACME object 
  B1 = D1.isCoplanar( D2 );

  % Intersect disk with an ACME object
  S1 = D1.intersection( D2 );


Object `ball`
-------------

The `ball` object represents a ball the 3D space.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build ACME ball objects given radius `r` and center `[ox,oy,oz]`
  B1 = acme_ball( r, [ox, oy, oz]' );
  B2 = acme_ball( r, ox, oy, oz );


Methods
^^^^^^^

.. code-block:: matlab

  % Copy ball object from another ball
  B1.copy( B2 );

  % Display object data
  B1.disp();

  % Get object type as string
  B1.type();

  %> Get ball radius
  R = B1.getRadius();

  %> Get ball center as ACME point object
  C = B1.getCenter();

  %> Get ball normal
  N = B1.getNormal();

  % Set ball radius
  B1.setRadius( R );

  % Set ball center with an ACME point object
  B1.setCenter( P );

  % Set ball normal as `[x, y, z]`
  B1.setNormal( `[x, y, z]` );

  % Translate ball by vector `[x, y, z]`
  B1.translate( [x, y, z]' );

  % Transform ball by 4x4 affine transformation matrix
  B1.transform( matrix );

  % Check if ACME point is inside the ball 
  B1 = B1.isInside( P );

  % Check if ball is degenerated
  B1 = B1.isDegenerated();

  % Check if balls are approximatively equal
  B1 = B1.isApprox( T2 );

  % Normalize ball normal vector
  B1.normalize();

  % Get ball laying plane
  P1 = B1.layingPlane();

  % Reverse ball normal direction
  B1.reverse();

  % Get ball minimum and maximum points of object instance
  [out1, out2] = B1.clamp();

  % Get ball perimeter
  P = B1.perimeter();

  % Get ball area
  A = B1.area();

  % Check if ball is parallel to an ACME object
  B1 = B1.isParallel( B2 );

  % Check if ball is orthogonal to an ACME object
  B1 = B1.isOrthogonal( B2 );

  % Check if ball is collinear to an ACME object
  B1 = B1.isCollinear( B2 );

  % Check if ball is coplanar to an ACME object 
  B1 = B1.isCoplanar( B2 );

  % Intersect ball with an ACME object
  S1 = B1.intersection( B2 );


Object `aabb`
-------------

The `aabb` object represents a aabb the 3D space.

Constructors
^^^^^^^^^^^^

.. code-block:: matlab

  % Build ACME aabb objects given maximum `[Mx,My,Mz]` point and minimum point `[mx,my,mz]`
  B1 = acme_aabb( [Mx, My, Mz]', [mx, my, mz]' );
  B2 = acme_aabb( Mx, My, Mz, mx, my, mz );


Methods
^^^^^^^

.. code-block:: matlab

  % Copy aabb object from another aabb
  B1.copy( B2 );

  % Display object data
  B1.disp();

  % Get object type as string
  B1.type();

  % Check if ACME point is inside the aabb 
  B1 = B1.isInside( P );

  % Check if aabb is degenerated
  B1 = B1.isDegenerated();

  % Check if aabbs are approximatively equal
  B1 = B1.isApprox( T2 );

  % Return aabb id
  ID = B1.id();

  % Return aabb position
  POS = B1.pos();

  % Perform intersection with another ACME entity and return intersection object
  B3 = B1.intersection( B2 );

  % PCheck if aabb intersects with another ACME entity and return boolean
  B3 = B1.intersects( B2 );


.. include:: authors.rst