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

// TEST 12 - ENTITIES INTERSECTION

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_vector_point.hh"
#include "acme_line.hh"
#include "acme_orthogonal.hh"
#include "acme_parallel.hh"
#include "acme_intersection.hh"
#include "acme_utilities.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << "TEST 12 - ENTITIES INTERSECTION" << std::endl;


  Eigen::Vector3d a(1.0, 1.0, 1.0);
  acme::vec3 p(1.0, 1.0, 1.0);
  std::cout << "point = " << acme::isParallel(a, p) << "\n";

  entity *line0 = new ray(point(0.0, 0.0, 0.0), vector(0.0, -1.0, 0.0));
  entity *line1 = new ray(point(0.0, -1.0, 0.0), vector(0.0, 1.0, 0.0));
  entity *entity_out = acme::intersection(line0, line1);
  if (segment *segment_ptr = dynamic_cast<segment *>(entity_out)) // IF!!!!!
  {
    std::cout << "Lines intersection point 0 = " << segment_ptr->vertex(0) << "\n";
    std::cout << "Lines intersection point 1 = " << segment_ptr->vertex(1) << "\n";
  }

  delete entity_out;
  //delete segment_ptr;

      std::cout
      << std::endl
      << std::endl
      << "TEST 12: Completed" << std::endl;

  // Exit the program
  return 0;
}
