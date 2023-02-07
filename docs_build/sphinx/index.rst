.. rst-class:: emphasize-children

.. rst-class:: html-toggle

***************************
A Small 3D Geometry Library
***************************

.. image:: https://img.shields.io/badge/Github-acme-0072BD.svg
  :target: https://github.com/stoccodavide/acme

.. image:: https://img.shields.io/badge/Version-4.0.0-0072BD.svg
  :target: https://github.com/stoccodavide/acme

.. image:: https://img.shields.io/badge/Release-4.0.0-0072BD.svg
  :target: https://github.com/stoccodavide/acme

.. image:: https://img.shields.io/badge/License-BSD2-0072BD.svg
  :target: https://opensource.org/licenses/BSD-2-Clause


The ACME library is a small 3D geometry library written in C++11. It is designed
to be a simple and easy to use library for 3D computational geometry. The main
goal of the library is to provide a minimal and robust to use interface for
geometry computations.

Installation
------------

C++
~~~

Download the library using git:

.. code:: sh

   git clone git@github.com:StoccoDavide/acme.git

To compile the library you can use ``cmake``:

.. code:: sh

   mkdir build
   cd build
   cmake ..
   make

or ``rake``:

.. code:: sh

   rake build_submodules
   rake build # or simply 'rake'

The compiled library and headers are stores as follows:

.. code:: text

   `-- lib
       |-- include
       |   |-- acme.hh
       |   `-- acme
       |       |-- aabb.hxx
       |       |-- AABBtree.hxx
       |       |-- ball.hxx
       |       |-- collection.hxx
       |       |-- collinear.hxx
       |       |-- coplanar.hxx
       |       |-- disk.hxx
       |       |-- entity.hxx
       |       |-- intersection.hxx
       |       |-- line.hxx
       |       |-- math.hxx
       |       |-- none.hxx
       |       |-- orthogonal.hxx
       |       |-- parallel.hxx
       |       |-- plane.hxx
       |       |-- point.hxx
       |       |-- ray.hxx
       |       |-- segment.hxx
       |       |-- triangle.hxx
       |       `-- utilities.hxx
       |-- lib
       |   `-- libacme_OSTYPE_static.a
       `-- dll
           `-- libacme_OSTYPE.dylib

where OSTYPE can be ``linux``, ``osx``, ``mingw_x64``, ``win_x64`` depending on
your OS.

MATLAB MEX
~~~~~~~~~~

Download the toolbox and install the toobox as usual. Run ``CompileACMElib`` on
MATLAB Command Window to compile the MATLAB MEX library.

Index
-----

.. toctree::
   :maxdepth: 2

   Manual_Readme.rst
   Manual_Features.rst
   Manual_MATLAB_Toolbox.rst
   api-matlab/root.rst
   api-cpp/root.rst

Authors
-------

| **Davide Stocco**
| Department of Industrial Engineering
| University of Trento
| davide.stocco@unitn.it

| **Enrico Bertolazzi**
| Department of Industrial Engineering
| University of Trento
| enrico.bertolazzi@unitn.it

License
-------

.. literalinclude:: ../LICENSE.txt
   :language: none
