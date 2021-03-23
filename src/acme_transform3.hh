///
/// file: acme_transform3.hh
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

#ifndef INCLUDE_ACME_TRANSFORM3
#define INCLUDE_ACME_TRANSFORM3

#include "acme.hh"
#include "acme_math.hh"
#include "acme_frame3.hh"

namespace acme
{

  /*\
   |   _____                     __                      _____ 
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___ |___ / 
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \  |_ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |___) |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|____/ 
   |                                                           
  \*/

  //! Tranform VECTOR from frameA to frameB
  vector3 transform_vector(
      const vector3 &vector, //!< Input
      const frame3 &frameA, //!< Actual reference coordinate system
      const frame3 &frameB  //!< Future reference coordinate system
  )
  {
    return frameB.rotation().transpose() * (frameA.rotation() * vector);
  }

  //! Tranform point from frameA to frameB
  vector3 transform(
      const vector3 &point, //!< Input
      const frame3 &frameA, //!< Actual reference coordinate system
      const frame3 &frameB  //!< Future reference coordinate system
  )
  {
    return frameB.rotation().transpose() * (frameA.rotation() * point + frameA.origin() - frameB.origin());
  }

  //! Tranform ray from frameA to frameB
  ray3 transform(
      const ray3 &ray,      //!< Input
      const frame3 &frameA, //!< Actual reference coordinate system
      const frame3 &frameB  //!< Future reference coordinate system
  )
  {
    return ray3(acme::transform(ray.origin(), frameA, frameB),
                acme::transform(ray.direction(), frameA, frameB));
  }

  //! Tranform line from frameA to frameB
  line3 transform(
      const line3 &line,    //!< Input
      const frame3 &frameA, //!< Actual reference coordinate system
      const frame3 &frameB  //!< Future reference coordinate system
  )
  {
    return line3(acme::transform(line.origin(), frameA, frameB),
                 acme::transform(line.direction(), frameA, frameB));
  }

  //! Tranform plane from frameA to frameB
  plane3 transform(
      const plane3 &plane,  //!< Input
      const frame3 &frameA, //!< Actual reference coordinate system
      const frame3 &frameB  //!< Future reference coordinate system
  )
  {
    return plane3(acme::transform(plane.origin(), frameA, frameB),
                  acme::transform(plane.normal(), frameA, frameB));
  }

  //! Tranform segment from frameA to frameB
  segment3 transform(
      const segment3 &segment, //!< Input
      const frame3 &frameA,    //!< Actual reference coordinate system
      const frame3 &frameB     //!< Future reference coordinate system
  )
  {
    return segment3(acme::transform(segment.point_0(), frameA, frameB),
                    acme::transform(segment.point_1(), frameA, frameB));
  }

  //! Tranform box from frameA to frameB
  box3 transform(
      const box3 &box,      //!< Input
      const frame3 &frameA, //!< Actual reference coordinate system
      const frame3 &frameB  //!< Future reference coordinate system
  )
  {
    return box3(acme::transform(box.point_0(), frameA, frameB),
                acme::transform(box.point_1(), frameA, frameB));
  }

  //! Tranform triangle from frameA to frameB
  triangle3 transform(
      const triangle3 &triangle, //!< Input
      const frame3 &frameA,      //!< Actual reference coordinate system
      const frame3 &frameB       //!< Future reference coordinate system
  )
  {
    return triangle3(acme::transform(triangle.point_0(), frameA, frameB),
                     acme::transform(triangle.point_1(), frameA, frameB),
                     acme::transform(triangle.point_2(), frameA, frameB));
  }

} // namespace acme

#endif

///
/// eof: acme_transform3.hh
///