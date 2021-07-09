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

// TEST 11 - SEGMENT/PLANE INTERSECTION

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_plane.hh"
#include "acme_segment.hh"
#include "acme_utils.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << "TEST 16 - SEGMENT/PLANE INTERSECTION" << std::endl;

  // Initialize triangle
  segment Segment(point(0.0, 1.0, 1.6), vec3(1.0, 0.0, 0));

  // Initialize triangle
  plane Plane(vec3(0.0, 0.0, 0.5), vec3(0.0, 0.0, 1.0));

  // Initialize intersection point
  point IntersectionPt;
  bool IntersectionPtBool;

  IntersectionPtBool = acme::intersection(Plane, Segment, IntersectionPt);

  // ERROR if no one of the two triangles is hit
  if (!IntersectionPtBool)
  {
    std::cout << "Check coplanarity!" << std::endl;
  }

  std::cout
      << std::endl
      << std::endl
      << "Intersection point: "
      << IntersectionPt << std::endl
      << "TEST 16: Completed" << std::endl;

  // Exit the program
  return 0;
}
