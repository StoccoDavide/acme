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

Future developments
-------------------

In a next future we would like to develop methods and support also for the following
geometrical entities:

- sphere;
- circular arc;
- convex quadrilateral.

Online documentation
--------------------

Available at: `https://stoccodavide.github.io/acme <https://stoccodavide.github.io/acme>`__

Maintenance and compatibility
-----------------------------

Library is being tested on Linux and MacOS, it will be soon tested also on Windows.
If you have questions regarding the library or you want to report a bug,
please open an `issue <https://github.com/StoccoDavide/acme/issues/new>`__
at GitHub. If your request would contain confidential information, please send
us an email.

About the authors
-----------------

| **Davide Stocco**
| Department of Industrial Engineering
| University of Trento
| davide.stocco@unitn.it

| **Enrico Bertolazzi**
| Department of Industrial Engineering
| University of Trento
| enrico.bertolazzi@unitn.it

References
----------

1.  *D. Stocco*,
    **Real-Time Computation of Tire/Road Contact using Tailored Algorithms**,
    2020, Master Thesis (*in Italian*),
    `PDF <https://github.com/StoccoDavide/MasterThesis/blob/master/thesis.pdf>`__.
