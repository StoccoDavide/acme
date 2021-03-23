///
/// file: acme_utilities.hh
///

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

#ifndef INCLUDE_ACME_UTILTIES
#define INCLUDE_ACME_UTILTIES

#include <iostream>
#include <iomanip>
#include <vector>

#include "acme.hh"

#include "acme_ray3.hh"
#include "acme_line3.hh"
#include "acme_plane3.hh"
#include "acme_segment3.hh"
#include "acme_box3.hh"
#include "acme_triangle3.hh"
#include "acme_circle3.hh"

#include "acme_transform3.hh"
#include "acme_intersect3.hh"

namespace acme
{
  /*\
   |   _____ ____          _   _ _ _ _   _           
   |  |___ /|  _ \   _   _| |_(_) (_) |_(_) ___  ___ 
   |    |_ \| | | | | | | | __| | | | __| |/ _ \/ __|
   |   ___) | |_| | | |_| | |_| | | | |_| |  __/\__ \
   |  |____/|____/   \__,_|\__|_|_|_|\__|_|\___||___/
   |                                                 
  \*/

  //!< Stream out operator for vector3 object
  std::ostream &operator<<(
      std::ostream &os,  //!< Output stream
      const vector3 &obj //!< Vector object
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
      const line3 &obj  //!< Line object
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
      const ray3 &obj   //!< Ray object
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
      const plane3 &obj //!< Plane object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Origin = " << obj.origin()
       << "Normal = " << obj.normal();
    return os;
  }

  //!< Stream out operator for segment object
  std::ostream &operator<<(
      std::ostream &os,   //!< Output stream
      const segment3 &obj //!< Segment object
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
      const box3 &obj   //!< Box object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Point 0 = " << obj.point_0()
       << "Point 1 = " << obj.point_1();
    return os;
  }

  //!< Stream out operator for triangle object
  std::ostream &operator<<(
      std::ostream &os,    //!< Output stream
      const triangle3 &obj //!< Triangle object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "Point 0 = " << obj.point_0()
       << "Point 1 = " << obj.point_1()
       << "Point 2 = " << obj.point_2();
    return os;
  }

  std::ostream &operator<<(
      std::ostream &os,  //!< Output stream
      const circle3 &obj //!< Object
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
      const frame3 &obj //!< Object
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