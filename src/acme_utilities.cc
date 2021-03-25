/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(* Release Version 0.0.0                                               *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The acme computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the acme computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_utilities.cc
///

#include "acme_utilities.hh"

namespace acme
{
  /*\
   |         _   _ _ _ _   _           
   |   _   _| |_(_) (_) |_(_) ___  ___ 
   |  | | | | __| | | | __| |/ _ \/ __|
   |  | |_| | |_| | | | |_| |  __/\__ \
   |   \__,_|\__|_|_|_|\__|_|\___||___/
   |                                   
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &operator<<(
      ostream_type &os,
      vec3 const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj[0] << "," << obj[1] << "," << obj[2] << ")";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &operator<<(
      ostream_type &os,
      line const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Origin    = " << obj.origin()
       << "Direction = " << obj.direction();
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &operator<<(
      ostream_type &os,
      ray const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Origin    = " << obj.origin()
       << "Direction = " << obj.direction();
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &operator<<(
      ostream_type &os,
      plane const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Origin = " << obj.origin().x()
       << "Normal = " << obj.normal();
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &operator<<(
      ostream_type &os,
      segment const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Point 0 = " << obj.point_0()
       << "Point 1 = " << obj.point_1();
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &operator<<(
      ostream_type &os,
      box const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Point min = " << obj.point_min()
       << "Point max = " << obj.point_max();
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &operator<<(
      ostream_type &os,
      triangle const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Point 0 = " << obj.vertex_0()
       << "Point 1 = " << obj.vertex_1()
       << "Point 2 = " << obj.vertex_2();
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &operator<<(
      ostream_type &os,
      circle const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(10)
       << "Center = " << obj.center()
       << "Normal = " << obj.normal()
       << "Radius = " << obj.radius();
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &operator<<(
      ostream_type &os,
      frame const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(10)
       << "Origin   = " << obj.origin()
       << "Rotation = " << obj.rotation();
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_utilities.cc
///