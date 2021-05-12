ACME general features
=====================

Geometrical entities in ACME are organised in classes with the following structure:

- virtual class `entity`;
- class `none` < `entity`;
- class `point` < `Eigen::Matrix, entity`;
- class `line` < `entity`;
- class `ray` < `entity`;
- class `plane` < `entity`;
- class `segment` < `entity`;
- class `triangle` < `entity`;
- class `circle` < `entity`;
- class `aabb` < `entity`;
- class `AABBtree`;

where the symbol < indicates the inheritance. Let us get a closer and detailed
look to each of these classes.

Class `entity`
--------------

The `entity` class is the most basic class. Its aim is to provide a common framework
from which to develop more specific geometric entities. For this reason it is a *pure
virtual* class with no members. The virtual methods aimed to check the nature of
the geometric entity itself are the following:

-  virtual method `type` which returns a `std::string` type;
-  virtual method `isNone` which returns a `bool` type;
-  virtual method `isPoint` which returns a `bool` type;
-  virtual method `isLine` which returns a `bool` type;
-  virtual method `isRay` which returns a `bool` type;
-  virtual method `isPlane` which returns a `bool` type;
-  virtual method `isSegment` which returns a `bool` type;
-  virtual method `isTriangle` which returns a `bool` type;
-  virtual method `isCircle` which returns a `bool` type;
-  virtual method `isAabb` which returns a `bool` type;

Class `none`
------------

The `none` class is a publicly inherited class from `entity`. Its aim is to represent
nothing than nothing. As will be later explained if we exploit the the polymorphism
this class will represent the null intersection between objects. The `none` class
is a non-abstract class with no members. The implemented methods only override the
virtual ones defined in the base class `entity`.

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

Class `circle`
--------------

The `circle` class publicly inherit from `entity` and represents a generic
circle the 3D space. It is built out of three members:

- an **radius**, represented by a member of type `real`;
- an **center** point, represented by a member of type `point`;
- an **normal** to the face, represented by a member of type `vec3`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if circle are (almost) equal;
- `isDegenerated`: check if radius is degenerated (radius is zero and normal vector has zero norm);
- `radius`: return circle radius;
- `radius`: set circle radius;
- `center`: return circle center point;
- `center`: set circle center point;
- `normal`: return circle normal vector;
- `normal`: set circle normal vector;
- `normalize`: get normalize circle normal vector;
- `layingPlane`: get circle laying plane;
- `reverse`: reverse circle normal vector;
- `clamp`: resize minimum aabb containing the circle object
- `perimeter`: calculate circle perimeter;
- `area`: calculate circle area;
- `translate`: translate circle by vector;
- `transform`: transform circle with affine transformation matrix;
- `isInside`: check whether the point is inside the circle.

Class `aabb`
------------

The `aabb` class publicly inherit from `entity` and represents a generic
axis-aligne bounding box in the 3D space. It is built out of two members:

- a **minimum** point, represented by a member of type `point`;
- a **maximum** point, represented by a member of type `point`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if circle are (almost) equal;
- `isDegenerated`: check if radius is degenerated (radius is zero and normal vector has zero norm);
- `radius`: return circle radius;
- `radius`: set circle radius;
- `center`: return circle center point;
- `center`: set circle center point;
- `normal`: return circle normal vector;
- `normal`: set circle normal vector;
- `normalize`: get normalize circle normal vector;
- `layingPlane`: get circle laying plane;
- `reverse`: reverse circle normal vector;
- `clamp`: resize minimum aabb containing the circle object
- `perimeter`: calculate circle perimeter;
- `area`: calculate circle area;
- `translate`: translate circle by vector;
- `transform`: transform circle with affine transformation matrix;
- `isInside`: check whether the point is inside the circle.

Even if `aabb` is considered to be a geometrical entity there are still no external functions
implemented for geometrical intersections with the other entities.

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

External functions
------------------

Objects defined by the previous classes can interact between them through external
functions defined in `acme` namespace. These functions are:

- `intersection`: it allows to *intersect* two elements or just check if two geometric
  entities *collide*;
- `isParallel`: check if two geometric entities are *parallel*;
- `isOrthogonal`: check if two geometric entities are *orthogonal*;
- `isCollinear`: check if two geometric entities are *collinear*;
- `isCoplanar`: check if two geometric entities are *coplanar*.

Each of these functions are overloaded and they can take objects or raw pointers
to `entity` as input.
