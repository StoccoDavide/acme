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

// TEST 13 - ENTITIES INTERSECTION

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_line.hh"
#include "acme_orthogonal.hh"
#include "acme_parallel.hh"
#include "acme_point.hh"
#include "acme_utils.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << "TEST 13 - ENTITIES INTERSECTION" << std::endl;

  ray *ray0 = new ray(point(0.0, 0.0, 0.0), vec3(0.0, -1.0, 0.0));
  ray *ray1 = new ray(point(0.0, -1.0, 0.0), vec3(0.0, 1.0, 0.0));

  entity *entity_out0 = acme::intersection(ray0, ray1);
  std::cout << "Exit type: "
            << entity_out0->type() << "\n";

  if (dynamic_cast<segment *>(entity_out0)) // IF!!!!!
  {
    segment *segment_ptr0 = dynamic_cast<segment *>(entity_out0);
    std::cout << "Segment:\n"
              << *segment_ptr0;
  }

  disk *disk0 = new disk(2.0, point(0.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0));
  disk *disk1 = new disk(2.0, point(0.0, 0.0, 0.1), vec3(1.0, -1.0, 0.0));

  entity *entity_out1 = acme::intersection(disk0, disk1);
  std::cout << "Exit type: "
            << entity_out1->type() << "\n";

  if (dynamic_cast<segment *>(entity_out1)) // IF!!!!!
  {
    segment *segment_ptr1 = dynamic_cast<segment *>(entity_out1);
    std::cout << "Segment:\n"
              << *segment_ptr1;
  }

  delete entity_out0;
  delete entity_out1;

  std::cout
      << std::endl
      << std::endl
      << "TEST 13: Completed" << std::endl;

  // Exit the program
  return 0;
}
