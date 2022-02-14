/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *)
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

// TEST 12 - RAY/RAY INTERSECTION

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_ray.hh"
#include "acme_utils.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << "TEST 12 - RAY/RAY INTERSECTION" << std::endl;

  ray ray0(point(0.0, 0.0, 0.0), vec3(0.0, -1.0, 0.0));
  ray ray1(point(0.0, -1.0, 0.0), vec3(0.0, 1.0, 0.0));

  segment segment_out;
  ray ray_out;
  bool bool_segment = acme::intersection(ray0, ray1, segment_out, EPSILON);
  bool bool_ray = acme::intersection(ray0, ray1, ray_out, EPSILON);

  if (bool_segment)
  {
    std::cout << "Segment:\n"
              << segment_out;
  }
  else if (bool_ray)
  {
    std::cout << "Ray:\n"
              << ray_out;
  }

  std::cout
      << std::endl
      << std::endl
      << "TEST 12: Completed" << std::endl;

  // Exit the program
  return 0;
}
