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

// TEST 4 - POINT ON SEGMENT

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_segment.hh"
#include "acme_utilities.hh"

using namespace acme;

// Main function
int main()
{
  // Initialize segment points
  segment Segment(point(0.0, 0.0, 0.5), point(1.0, 1.0, 0.5));

  // Query points and intersection bools
  point PointIn(0.5, 0.5, 0.5);
  point PointOut(-1.0, -1.0, 0.5);
  point PointBorder(1.0, 1.0, 0.5);

  // Calculate intersection
  bool PtInBool = Segment.isInside(PointIn);
  bool PtOutBool = Segment.isInside(PointOut);
  bool PtBordBool = Segment.isInside(PointBorder);

  std::cout
      << "TEST 4 - POINT ON SEGMENT" << std::endl
      << std::endl
      << "Segment Vertex 0 = " << Segment.vertex(0) << std::endl
      << "Segment Vertex 1 = " << Segment.vertex(1) << std::endl
      << std::endl;

  // Show results
  if (PtInBool && !PtOutBool && PtBordBool)
  {
    std::cout
        << "Point inside    = " << PointIn << " -> Bool = " << PtInBool << std::endl
        << "Point outside   = " << PointOut << " -> Bool = " << PtOutBool << std::endl
        << "Point on border = " << PointBorder << " -> Bool = " << PtBordBool << std::endl
        << std::endl;
  }
  else
  {
    std::cout << "TEST 4: Failed" << std::endl;
  }

  std::cout << "TEST 4: Completed" << std::endl;

  // Exit the program
  return 0;
}
