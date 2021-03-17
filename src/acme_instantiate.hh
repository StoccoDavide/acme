///
/// file: acme_instantiate.hh
///

/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                              *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The acme computational geometry library and its components are       *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the acme computational geometry library and its      *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

#ifndef INCLUDE_ACME_INSTANTIATE
#define INCLUDE_ACME_INSTANTIATE

namespace acme
{

  // Eigen row vector3 (3 by 1 matrix) base classes
  // Point/vector3 base classes
  template <typename T>
  class point3;
  template <typename T>
  class vector3;

  // Eigen 3 by 3 matrix base classes
  // Rotation matrix class
  template <typename T>
  class rotation3;

  // Coordinate frame class
  template <typename T>
  class frame3;

  // Infinite objects classes (point/vector3 description)
  template <typename T>
  class line3;
  template <typename T>
  class ray3;
  template <typename T>
  class plane3;

  // Finite objects classes (2 points)
  template <typename T>
  class segment3;
  template <typename T>
  class box3;

  // Finite objects classes (3 points)
  template <typename T>
  class triangle3;

  // Finite objects classes (1 real + 1 plane (center + normal))
  template <typename T>
  class circle3;

} // namespace acme

#endif

///
/// eof: acme_instantiate.hh
///
