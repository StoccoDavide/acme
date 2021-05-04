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

// TEST 8 - POINT/VECTOR TRANSFORMATION

#include <fstream>
#include <iostream>
#include <string>

#include <Eigen/Geometry>

#include "acme.hh"
#include "acme_aabb.hh"
#include "acme_intersection.hh"
#include "acme_triangle.hh"
#include "acme_utilities.hh"

using namespace acme;

// Main function
int main()
{
  // Initialize point and vector
  point point_tmp(0.0, 0.0, 1.0);
  vector vector_tmp(0.0, 0.0, 1.0);

  // Initialize rotation matrix
  affine transformation = translate(0.0, 0.0, -1.0) * rotate(PI / 4, "X");

  // Transform objects
  point mov_point(point_tmp);
  vector mov_vector(vector_tmp);
  acme::transformPoint(mov_point, transformation);
  acme::transformVector(mov_vector, transformation);

  // Transform objects back
  point ground_point(mov_point);
  vector ground_vector(mov_vector);
  acme::transformPoint(ground_point, transformation.inverse());
  acme::transformVector(ground_vector, transformation.inverse());

  // Display results
  std::cout
      << std::endl
      << "TEST 8 - POINT/VECTOR TRANSFORMATION" << std::endl
      << std::endl
      << "Point  (ground) = " << point_tmp << std::endl
      << "Vector (ground) = " << vector_tmp << std::endl
      << std::endl
      << "Point  (moving frame) = " << mov_point << std::endl
      << "Vector (moving frame) = " << mov_vector << std::endl
      << std::endl
      << "Point  (back to ground) = " << ground_point << std::endl
      << "Vector (back to ground) = " << ground_vector << std::endl
      << std::endl
      << "TEST 8: Completed" << std::endl;

  // Exit the program
  return 0;
}
