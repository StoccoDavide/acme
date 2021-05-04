/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 2-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 2-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
(*                                                                     *)
(*    Davide Stocco                                                    *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: davide.stocco@unitn.it                                   *)
(*                                                                     *)
(*    Enrico Bertolazzi                                                *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: enrico.bertolazzi@unitn.it                               *)
(*                                                                     *)
(***********************************************************************)
*/

// TEST 1 - RAY/TRIANGLE INTERSECTION ON TRIANGLE EDGE

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_point_vector.hh"
#include "acme_intersection.hh"
#include "acme_math.hh"
#include "acme_triangle.hh"
#include "acme_aabb.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << "TEST 1 - RAY/TRIANGLE INTERSECTION ON TRIANGLE EDGE" << std::endl
      << "Angle\tIntersections" << std::endl;

  point V1[3];
  V1[0] = point(1.0, 0.0, 0.0);
  V1[1] = point(0.0, 1.0, 0.0);
  V1[2] = point(-1.0, 0.0, 0.0);

  point V2[3];
  V2[0] = point(-1.0, 0.0, 0.0);
  V2[1] = point(0.0, -1.0, 0.0);
  V2[2] = point(1.0, 0.0, 0.0);

  // Initialize triangle
  triangle Triangle1(V1);
  triangle Triangle2(V2);
  triangle tmp_Triangle1(V1);
  triangle tmp_Triangle2(V2);

  // Initialize rotation matrix
  affine tmp_affine;
  tmp_affine = translate(0.0, 0.0, 0.0);

  // Initialize intersection point
  point IntersectionPointTri1, IntersectionPointTri2;
  bool IntersectionBoolTri1, IntersectionBoolTri2;

  // Initialize Ray
  point RayOrigin = point(0.0, 0.0, 1.0);
  vector RayDirection = vector(0.0, 0.0, -1.0);
  ray Ray(RayOrigin, RayDirection);

  real_type step = PI / 360.0;
  // Perform intersection at 0.5° step
  for (real_type angle = 0;
       angle < PI;
       angle += step)
  {

    tmp_affine = rotate(angle, "X");
    angle += step;

    // Initialize vertices
    point VerticesTri1[3], VerticesTri2[3];

    tmp_Triangle1 = Triangle1;
    tmp_Triangle2 = Triangle2;
    tmp_Triangle1.transform(tmp_affine);
    tmp_Triangle2.transform(tmp_affine);

    IntersectionBoolTri1 = intersection(Ray, tmp_Triangle1, IntersectionPointTri1);
    IntersectionBoolTri2 = intersection(Ray, tmp_Triangle2, IntersectionPointTri2);

    std::cout
        << angle * _180divPI << "°\t"
        << "T1 -> " << IntersectionBoolTri1 << ","
        << "T2 -> " << IntersectionBoolTri2 << std::endl;

    // ERROR if no one of the two triangles is hit
    if (!IntersectionBoolTri1 && !IntersectionBoolTri2)
    {
      std::cout << "Check coplanarity!" << std::endl;
    }
  }

  // Print triangle normal vector
  vec3 N1 = Triangle1.normal();
  vec3 N2 = Triangle2.normal();
  std::cout
      << std::endl
      << "Triangle 1 face normal = " << N1 << std::endl
      << "Triangle 2 face normal = " << N2 << std::endl
      << "Pow = " << acme::pow(2.0, 2.0) << std::endl
      << std::endl
      << std::endl
      << "TEST 1: Completed" << std::endl;

  // Exit the program
  return 0;
}
