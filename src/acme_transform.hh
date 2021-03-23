///
/// file: acme_transform.hh
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

#ifndef INCLUDE_ACME_TRANSFORM
#define INCLUDE_ACME_TRANSFORM

#include "acme.hh"
#include "acme_math.hh"
#include "acme_frame.hh"

namespace acme
{

  /*\
   |   _____                     __                      
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
   |                                                     
  \*/

  //! Tranform VECTOR from frameA to frameB
  vector transform_vector(
      const vector &vector, //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return frameB.rotation().transpose() * (frameA.rotation() * vector);
  }

  //! Tranform point from frameA to frameB
  vector transform(
      const vector &point, //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return frameB.rotation().transpose() * (frameA.rotation() * point + frameA.origin() - frameB.origin());
  }

  //! Tranform ray from frameA to frameB
  ray transform(
      const ray &ray,      //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return ray(acme::transform(ray.origin(), frameA, frameB),
                acme::transform(ray.direction(), frameA, frameB));
  }

  //! Tranform line from frameA to frameB
  line transform(
      const line &line,    //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return line(acme::transform(line.origin(), frameA, frameB),
                 acme::transform(line.direction(), frameA, frameB));
  }

  //! Tranform plane from frameA to frameB
  plane transform(
      const plane &plane,  //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return plane(acme::transform(plane.origin(), frameA, frameB),
                  acme::transform(plane.normal(), frameA, frameB));
  }

  //! Tranform segment from frameA to frameB
  segment transform(
      const segment &segment, //!< Input
      const frame &frameA,    //!< Actual reference coordinate system
      const frame &frameB     //!< Future reference coordinate system
  )
  {
    return segment(acme::transform(segment.point_0(), frameA, frameB),
                    acme::transform(segment.point_1(), frameA, frameB));
  }

  //! Tranform box from frameA to frameB
  box transform(
      const box &box,      //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return box(acme::transform(box.point_0(), frameA, frameB),
                acme::transform(box.point_1(), frameA, frameB));
  }

  //! Tranform triangle from frameA to frameB
  triangle transform(
      const triangle &triangle, //!< Input
      const frame &frameA,      //!< Actual reference coordinate system
      const frame &frameB       //!< Future reference coordinate system
  )
  {
    return triangle(acme::transform(triangle.point_0(), frameA, frameB),
                     acme::transform(triangle.point_1(), frameA, frameB),
                     acme::transform(triangle.point_2(), frameA, frameB));
  }

} // namespace acme

#endif

///
/// eof: acme_transform.hh
///