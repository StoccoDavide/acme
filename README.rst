The ACME library
================

Given the amount of material out there one could certainly wonder
why develop a new geometric library that will surely have fewer
features than other libraries that represent the standard in the field.
During my master thesis part of this code was developed [1]. The aim was to
develop a small, hard real-time capable and easy to maintain geometric kernel
that computes some geometrical parameters of a custom tire model in contact
with the road. Moreover we wanted a geometric library that was written using
`Eigen <https://eigen.tuxfamily.org/index.php?title=Main_Page>`__ template
linear algebra library.
The desire to extend the previous thesis work has made it necessary
to better formalize and produce a more effective code that we collected
on a independent library. The newly born library has been ironically
named ACME (A Code Making Everything).

ACME is small 3D computational geometry library which is currently
still being developed. The library is built to be efficient,
readable and easy-to-use. Users must remember thereference coordinate
system of each geometrical object. The objects have not the possibility
to store the coordinate system in which they are defined. For this reason,
all transformations must be carried out by the user whenever necessary.

Since our goals are the speed and robustness, we decided to embed
the `Eigen <https://eigen.tuxfamily.org/index.php?title=Main_Page>`__ template
linear algebra library. More specifically, dense matrix and array manipulation,
space transformations are carried out by respecively using
`Eigen Matrix <https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html>`__
class and `Eigen Geometry <https://eigen.tuxfamily.org/dox/group__Geometry__chapter.html>`__
module.

ACME is currently the foundation of a terrain server sofware running
on a hard real-time DIL driving simulator. It resolves the geometrical
intersection problems with a real-time factor (RTF) of 50.

*Davide Stocco - Spring 2021*

General features
================

Geometrical entities in ACME are organised in classes with the following structure
(`C++` notation):

- `virtual class entity`;
- `class none : public entity`;
- `class point : public Eigen::Matrix, public entity`;
- `class line : public entity`;
- `class ray : public entity`;
- `class plane : public entity`;
- `class segment : public entity`;
- `class triangle : public entity`;
- `class circle : public entity`;
- `class box : public entity`;

where the symbol `:` indicates the inheritance. Let us get a closer and detailed
look to each of these classes.

Class `entity`
--------------

The `entity` class is the most basic class. Its aim is to provide a common framework
from which to develop more specific geometric entities. For this reason it is a *pure
virtual* class with no members. The virtual methods are aimed to check the nature of
the geometric entity itself:

-  `virtual bool isNone(void) const = 0`;
-  `virtual bool isPoint(void) const = 0`;
-  `virtual bool isLine(void) const = 0`;
-  `virtual bool isRay(void) const = 0`;
-  `virtual bool isPlane(void) const = 0`;
-  `virtual bool isSegment(void) const = 0`;
-  `virtual bool isTriangle(void) const = 0`;
-  `virtual bool isCircle(void) const = 0`;
-  `virtual bool isBox(void) const = 0`.

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
- `isInside`: check whether the point is inside the line;

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
- `isInside`: check whether the point is inside the ray;

Class `plane`
-------------

The `plane` class publicly inherit from `entity` and it represents a generic
plane the 3D space.It is built out of two members:

- an **origin** point, represented by a member of type `point`;
- a **normal** vector in the space, represented by a member of type `vec3`.

The implemented methods are:

- `operator=`: equality operator;
- `isApprox`: check if plane are (almost) equal;
- `isDegenerated`: check if ray is degenerated (direction vector has zero norm);
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


Class `triangle`
----------------


Class `circle`
--------------

Class `box`
-----------


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

Future developments
===================





Online documentation
====================

Available at: `https://stoccodavide.github.io/acme <https://stoccodavide.github.io/acme>`__

Maintenance and compatibility
=============================

Library is being tested on Linux and MacOS, it will be soon tested also on Windows.
If you have questions regarding the library or you want to report a bug,
please open an `issue <https://github.com/StoccoDavide/acme/issues/new>`__
at GitHub. If your request would contain confidential information, please send
us an email.

About the authors
=================

| **Davide Stocco**
| Department of Industrial Engineering
| University of Trento
| davide.stocco@unitn.it

| **Enrico Bertolazzi**
| Department of Industrial Engineering
| University of Trento
| enrico.bertolazzi@unitn.it

References
==========

1 *D. Stocco*,
  **Real-Time Computation of Tire/Road Contact using Tailored Algorithms**,
  2020, Master Thesis (*in Italian*),
  `PDF <https://github.com/StoccoDavide/MasterThesis/blob/master/thesis.pdf>`__.
