/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
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
/// file: acme_utilities.hh
///

#ifndef INCLUDE_ACME_UTILTIES
#define INCLUDE_ACME_UTILTIES

#include <iostream>
#include <iomanip>
#include <vector>

#include "acme.hh"

#include "acme_ray.hh"
#include "acme_line.hh"
#include "acme_plane.hh"
#include "acme_segment.hh"
#include "acme_box.hh"
#include "acme_triangle.hh"
#include "acme_circle.hh"

#include "acme_transform.hh"
#include "acme_intersect.hh"

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

  //!< Stream out operator for vec3 object
  std::ostream &operator<<(
      std::ostream &os, //!< Output stream
      vec3 const &obj   //!< Vector object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj[0] << "," << obj[1] << "," << obj[2] << ")";
    return os;
  }

  //!< Stream out operator for line object
  std::ostream &operator<<(
      std::ostream &os, //!< Output stream
      line const &obj   //!< Line object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Origin    = " << obj.origin()
       << "Direction = " << obj.direction();
    return os;
  }

  //!< Stream out operator for ray object
  std::ostream &operator<<(
      std::ostream &os, //!< Output stream
      ray const &obj    //!< Ray object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Origin    = " << obj.origin()
       << "Direction = " << obj.direction();
    return os;
  }

  //!< Stream out operator
  std::ostream &operator<<(
      std::ostream &os, //!< Output stream
      plane const &obj  //!< Plane object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Origin = " << obj.origin().x()
       << "Normal = " << obj.normal();
    return os;
  }

  //!< Stream out operator for segment object
  std::ostream &operator<<(
      std::ostream &os,  //!< Output stream
      segment const &obj //!< Segment object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Point 0 = " << obj.point_0()
       << "Point 1 = " << obj.point_1();
    return os;
  }

  //!< Stream out operator for box object
  std::ostream &operator<<(
      std::ostream &os, //!< Output stream
      box const &obj    //!< Box object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Point min = " << obj.point_min()
       << "Point max = " << obj.point_max();
    return os;
  }

  //!< Stream out operator for triangle object
  std::ostream &operator<<(
      std::ostream &os,   //!< Output stream
      triangle const &obj //!< Triangle object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Point 0 = " << obj.vertex_0()
       << "Point 1 = " << obj.vertex_1()
       << "Point 2 = " << obj.vertex_2();
    return os;
  }

  std::ostream &operator<<(
      std::ostream &os, //!< Output stream
      circle const &obj //!< Object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(10)
       << "Center = " << obj.center()
       << "Normal = " << obj.normal()
       << "Radius = " << obj.radius();
    return os;
  }

  std::ostream &operator<<(
      std::ostream &os, //!< Output stream
      frame const &obj  //!< Object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(10)
       << "Origin   = " << obj.origin()
       << "Rotation = " << obj.rotation();
    return os;
  }

} // namespace acme

#endif

///
/// eof: acme_utilities.hh
///