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

// TEST 3 - POINT INSIDE CIRCLE

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_aabb.hh"
#include "acme_intersection.hh"
#include "acme_triangle.hh"
#include "acme_utils.hh"

using namespace acme;

// Main function
int main()
{
  // Initialize disk
  circle Circle(1.0, point(0.0, 0.0, 0.5), vec3(0.0, 0.0, 1.0));

  // Query points and intersection bools
  point PointIn(0.0, 0.0, 0.5);
  point PointOut(2.0, 0.0, 0.5);
  point PointBorder(1.0, 0.0, 0.5);

  bool PtInBool, PtOutBool, PtBordBool;

  // Calculate intersection
  PtInBool = Circle.isInside(PointIn);
  PtOutBool = Circle.isInside(PointOut);
  PtBordBool = Circle.isInside(PointBorder);

  std::cout
      << "TEST 3 - POINT INSIDE DISK" << std::endl
      << std::endl
      << "Radius = " << Circle.radius() << std::endl
      << "Center = " << Circle.center() << std::endl
      << "Normal = " << Circle.normal() << std::endl
      << std::endl;

  // Show results
  if (PtInBool && !PtOutBool && PtBordBool)
  {
    std::cout
        << "Point inside    = " << PointIn << " -> Bool = " << PtInBool << std::endl
        << "Point outside   = " << PointOut << " -> Bool = " << PtOutBool << std::endl
        << "Point on border = " << PointBorder << " -> Bool = " << PtBordBool << std::endl
        << std::endl
        << "Check the results..." << std::endl
        << std::endl;
  }
  else
  {
    std::cout
        << "TEST 3: Failed" << std::endl;
  }

  std::cout
      << "TEST 3: Completed" << std::endl;

  // Exit the program
  return 0;
}
