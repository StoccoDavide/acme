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

// TEST 11 - PLANE/TRIANGLE INTERSECTION ON TRIANGLE EDGE

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_aabb.hh"
#include "acme_intersection.hh"
#include "acme_math.hh"
#include "acme_triangle.hh"
#include "acme_utilities.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << "TEST 11 - PLANE/TRIANGLE INTERSECTION ON TRIANGLE EDGE" << std::endl;

  point V1[3];
  V1[0] = point(1.0, 0.0, 0.0);
  V1[1] = point(0.0, 1.0, 0.0);
  V1[2] = point(-1.0, 0.0, 0.0);

  // Initialize triangle
  triangle Triangle1(V1);

  // Initialize triangle
  plane Plane1(vec3(0.0, 0.0, 0.0),
               vec3(1.0, 0.0, 0.0));

  // Initialize intersection point
  segment IntersectionSeg;
  bool IntersectionSegBool;

  IntersectionSegBool = acme::intersection(Plane1, Triangle1, IntersectionSeg);

  // ERROR if no one of the two triangles is hit
  if (!IntersectionSegBool)
  {
    std::cout << "Check coplanarity!" << std::endl;
  }

  std::cout
      << std::endl
      << std::endl
      << IntersectionSeg << std::endl
      << "TEST 11: Completed" << std::endl;

  // Exit the program
  return 0;
}
