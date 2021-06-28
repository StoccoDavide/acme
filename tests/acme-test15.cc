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

// TEST 14 - SEGMENT/SEGMENT INTERSECTION

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_segment.hh"
#include "acme_utils.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << "TEST 14 - SEGMENT/SEGMENT INTERSECTION" << std::endl;

  triangle t_1( point(0, -2.5, 0.0), point(0, 2.5, 0.01), point(0, -2.5, 0.01));
  circle   c_1(0.310556, point(2, 0.072, 0.26), vec3(0, 1, 0));

  segment segment_out;
  bool bool_segment = acme::intersection(t_1, c_1, segment_out, EPSILON_LOW);

  if (bool_segment)
  {
    std::cout << "Segment:\n"
              << segment_out;
  } else{
    std::cout << "Cannot intersect\n";
  }

  std::cout
      << std::endl
      << std::endl
      << "TEST 14: Completed" << std::endl;

  // Exit the program
  return 0;
}
