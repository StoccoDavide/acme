General Features
================

For both C++ library and MATLAB mex interface, ACME geometrical entities are
organised in classes with the following structure:

- virtual class `entity`;
- class `none` < `entity`;
- class `point` < `Eigen::Matrix, entity`;
- class `line` < `entity`;
- class `ray` < `entity`;
- class `plane` < `entity`;
- class `segment` < `entity`;
- class `triangle` < `entity`;
- class `disk` < `entity`;
- class `ball` < `entity`;
- class `collection`;
- class `aabb`;
- class `AABBtree`;

where the symbol < indicates the public inheritance. Let us get a closer and detailed
look to each of these classes.

Class `entity`
--------------

The `entity` class is the most basic class. Its aim is to provide a common framework
from which to develop more specific geometric entities. For this reason it is a *pure
virtual* class with no members. The virtual methods aimed to check the nature of
the geometric entity itself are the following:

-  virtual method `type` which returns a `std::string` type;
-  virtual method `isEntity` which returns a `bool` type;
-  virtual method `isNone` which returns a `bool` type;
-  virtual method `isPoint` which returns a `bool` type;
-  virtual method `isLine` which returns a `bool` type;
-  virtual method `isRay` which returns a `bool` type;
-  virtual method `isPlane` which returns a `bool` type;
-  virtual method `isSegment` which returns a `bool` type;
-  virtual method `isTriangle` which returns a `bool` type;
-  virtual method `isDisk` which returns a `bool` type;
-  virtual method `isBall` which returns a `bool` type;
-  virtual method `isClampable` which returns a `bool` type;
-  virtual method `clamp` which returns maximum aminimum values alog the three axes.

Class `none`
------------

The `none` class is a publicly inherited class from `entity`. Its aim is to represent
nothing than nothing. If the C++ polymorphic behaviour is
exploited this class will represent the null intersection between objects. The `none`
class is a non-abstract class with no members. The implemented methods only override
the virtual ones defined in the base class `entity`.

Class `line`
------------

The `line` class publicly inherit from `entity` and it represents a line the 3D space.
It is built out of two members:

- an **origin** point, represented by a member of type `point`;
- a **direction** in the space, represented by a member of type `vec3`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if lines are (almost) equal;
- `isDegenerated`: check if line is degenerated (direction vector has zero norm);
- `origin`: return line origin point;
- `origin`: set line origin point;
- `direction`: return line direction vector;
- `direction`: set line direction vector;
- `normalize`: normalise line direction vector;
- `toVector`: convert line to vector;
- `toNormalizedVector`: convert line to normalised vector;
- `reverse`: reverse line direction;
- `translate`: translate line by vector;
- `transform`: transform line with affine transformation matrix;
- `isInside`: check whether the point is inside the line.

Class `ray`
-----------

The `ray` class publicly inherit from `entity` and it represents a ray the 3D space.
It is very similar to the `line` class and it built out of two members:

- an **origin** point, represented by a member of type `point`;
- a **direction** in the space, represented by a member of type `vec3`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if ray are (almost) equal;
- `isDegenerated`: check if ray is degenerated (direction vector has zero norm);
- `origin`: return ray origin point;
- `origin`: set ray origin point;
- `direction`: return ray direction vector;
- `direction`: set ray direction vector;
- `normalize`: normalise ray direction vector;
- `toVector`: convert ray to vector;
- `toNormalizedVector`: convert ray to normalised vector;
- `reverse`: reverse ray direction;
- `translate`: translate ray by vector;
- `transform`: transform ray with affine transformation matrix;
- `isInside`: check whether the point is inside the ray.

Class `plane`
-------------

The `plane` class publicly inherit from `entity` and it represents a generic
plane the 3D space. It is built out of two members:

- an **origin** point, represented by a member of type `point`;
- a **normal** vector in the space, represented by a member of type `vec3`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if plane are (almost) equal;
- `isDegenerated`: check if plane is degenerated (normal vector has zero norm);
- `origin`: return plane origin point;
- `origin`: set plane origin point;
- `normal`: return plane normal vector;
- `normal`: set plane normal vector;
- `normalize`: normalise plane direction vector;
- `toVector`: convert plane to vector;
- `toNormalizedVector`: convert plane to normalised vector;
- `reverse`: reverse plane direction;
- `translate`: translate plane by vector;
- `transform`: transform plane with affine transformation matrix;
- `isInside`: check whether the point is inside the plane;
- `d`: return plane equation *d* value (*ax + by + cz + d = 0*);
- `distance`: distance between point and plane;
- `squaredDistance`: squared distance between point and plane;
- `signedDistance`: signed distance between point and plane.

Class `segment`
---------------

The `segment` class publicly inherit from `entity` and represents a generic
segment the 3D space. It is built out of two vertices, represented by members
of type `point`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if segment are (almost) equal;
- `isDegenerated`: check if segment is degenerated (vertices coincide);
- `vertex`: return segment vertex point;
- `vertex`: set segment vertex point;
- `centroid`: return segment centroid;
- `toVector`: convert segment to vector;
- `toNormalizedVector`: convert segment to normalised vector;
- `swap`: swap segment vertices;
- `clamp`: resize minimum aabb containing the segment object
- `length`: calculate segment length;
- `translate`: translate segment by vector;
- `transform`: transform segment with affine transformation matrix;
- `isInside`: check whether the point is inside the segment.

Class `triangle`
----------------

The `triangle` class publicly inherit from `entity` and represents a generic
triangle the 3D space. It is built out of three vertices, represented by members
of type `point`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if triangle are (almost) equal;
- `isDegenerated`: check if triangle is degenerated (two or more vertices coincide);
- `vertex`: return triangle vertex point;
- `vertex`: set triangle vertex point;
- `vertices`: return triangle vertices points;
- `vertices`: set triangle vertices points;
- `centroid`: return triangle centroid;
- `normal`: get triangle face normal (normalized vector);
- `edge`: return triangle edge created by *i*-th and *j*-th vertices;
- `swap`: swap triangle *i*-th and *j*-th vertices;
- `clamp`: resize minimum aabb containing the triangle object
- `perimeter`: calculate triangle perimeter;
- `area`: calculate triangle area;
- `barycentric`: calculate barycentric coordinates (u,v,w) for a given point;
- `layingPlane`: get triangle laying plane;
- `translate`: translate triangle by vector;
- `transform`: transform triangle with affine transformation matrix;
- `isInside`: check whether the point is inside the triangle.

Class `disk`
--------------

The `disk` class publicly inherit from `entity` and represents a generic
disk the 3D space. It is built out of three members:

- a **radius**, represented by a member of type `real`;
- a **center** point, represented by a member of type `point`;
- a **normal** to the face, represented by a member of type `vec3`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if disk are (almost) equal;
- `isDegenerated`: check if radius is degenerated (radius is zero and normal vector has zero norm);
- `radius`: return disk radius;
- `radius`: set disk radius;
- `center`: return disk center point;
- `center`: set disk center point;
- `normal`: return disk normal vector;
- `normal`: set disk normal vector;
- `normalize`: get normalize disk normal vector;
- `layingPlane`: get disk laying plane;
- `reverse`: reverse disk normal vector;
- `clamp`: resize minimum aabb containing the disk object
- `perimeter`: calculate disk perimeter;
- `area`: calculate disk area;
- `translate`: translate disk by vector;
- `transform`: transform disk with affine transformation matrix;
- `isInside`: check whether the point is inside the disk.

Class `ball`
--------------

The `ball` class publicly inherit from `entity` and represents a generic
ball the 3D space. It is built out of three members:

- a **radius**, represented by a member of type `real`;
- a **center** point, represented by a member of type `point`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if ball are (almost) equal;
- `isDegenerated`: check if radius is degenerated (radius is zero and normal vector has zero norm);
- `radius`: return ball radius;
- `radius`: set ball radius;
- `center`: return ball center point;
- `center`: set ball center point;
- `clamp`: resize minimum aabb containing the ball object
- `area`: calculate ball external surface area;
- `volume`: calculate ball volume;
- `translate`: translate ball by vector;
- `transform`: transform ball with affine transformation matrix;
- `isInside`: check whether the point is inside the ball.

Class `collection`
------------------

The class `collection` represents a generic set of geometrical entites.
It is built out of two members:

- a **vector of shared pointers** to entity objects of the type `std::vector<std::shared_ptr<entity>>`.
- a **bounding volume hierarcy tree** of the type `AABBtree` of the type `std::shared_ptr<AABBtree>`.

The implemented methods are specifically designed to intersect a large number
numer of eninties with only few commands. thus, it is very useful with large sets
of heteregeneous objects. Moreover, implemented methods also include sorting,
counting and removal of specific ojects types. Additional objects can be pushed
back or subtituted with already exixting ones.

Class `aabb`
------------

The class `aabb` represents a generic axis-aligned bounding box in the 3D space.
It is built out of two members:

- a **minimum** point, represented by a member of type `point`;
- a **maximum** point, represented by a member of type `point`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if aabb are (almost) equal;
- `isDegenerated`: check if radius is degenerated (radius is zero and normal vector has zero norm);
- `max`: return aabb maximum point;
- `max`: set aabb maximum point;
- `min`: return aabb minimum point;
- `min`: set aabb minimum point;
- `centerDistance`: return aabb center distance from point;
- `exteriorDistance`: return aabb exterior distance from point;
- `merged`: return aabb merged with another aabb;
- `center`: set aabb center point;
- `normal`: return aabb normal vector;
- `normal`: set aabb normal vector;
- `id`: return aabb identfication number;
- `id`: set aabb identfication number;
- `pos`: return aabb position number;
- `pos`: set aabb position number;
- `intersects`: check if two aabbs intersects.

Notice that `aabb` is bot considered to be a geometrical entity and thus there are
no external functions implemented for intersections with the other geometrical entities.

Class `AABBtree`
----------------

The `AABBtree` represents a generic axis-aligned bouding box tree class container.
It is built out of two members:

- a **pointer** to the tree itself, represented by a member of type `aabb::ptr`;
- a **vector of pointers** to the tree sub-structure, represented by a member of type `std::vector<AABBtree::ptr>`.

The implemented methods are:

- `clear`: clear AABB tree data;
- `isEmpty`: check if AABB tree is empty;
- `build`: build AABB tree given a list of boxes;
- `print`: print AABB tree data;
- `collision`: template function to check if two AABB tree collide;
- `intersection`: compute all the intersection leafs of AABB trees.

Functions
---------

Objects defined by the previous classes can interact between them through external
functions defined in `acme` namespace. These functions are:

- `Intersection`: it allows to *intersect* two elements or just check if two geometric
  entities *collide*;
- `IsParallel`: check if two geometric entities are *parallel*;
- `IsOrthogonal`: check if two geometric entities are *orthogonal*;
- `IsCollinear`: check if two geometric entities are *collinear*;
- `IsCoplanar`: check if two geometric entities are *coplanar*.

Each of these functions are overloaded and they can take objects or raw pointers
to `entity` as input.
