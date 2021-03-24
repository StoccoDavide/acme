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
      const frame &frameA,  //!< Actual reference coordinate system
      const frame &frameB   //!< Future reference coordinate system
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
      const ray &input,    //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return ray(acme::transform(input.origin(), frameA, frameB),
               acme::transform(input.direction(), frameA, frameB));
  }

  //! Tranform line from frameA to frameB
  line transform(
      const line &input,   //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return line(acme::transform(input.origin(), frameA, frameB),
                acme::transform(input.direction(), frameA, frameB));
  }

  //! Tranform plane from frameA to frameB
  plane transform(
      const plane &input,  //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return plane(acme::transform(input.origin(), frameA, frameB),
                 acme::transform(input.normal(), frameA, frameB));
  }

  //! Tranform segment from frameA to frameB
  segment transform(
      const segment &input, //!< Input
      const frame &frameA,  //!< Actual reference coordinate system
      const frame &frameB   //!< Future reference coordinate system
  )
  {
    return segment(acme::transform(input.point_0(), frameA, frameB),
                   acme::transform(input.point_1(), frameA, frameB));
  }

  //! Tranform box from frameA to frameB
  box transform(
      const box &input,    //!< Input
      const frame &frameA, //!< Actual reference coordinate system
      const frame &frameB  //!< Future reference coordinate system
  )
  {
    return box(acme::transform(input.point_min(), frameA, frameB),
               acme::transform(input.point_max(), frameA, frameB));
  }

  //! Tranform triangle from frameA to frameB
  triangle transform(
      const triangle &input, //!< Input
      const frame &frameA,      //!< Actual reference coordinate system
      const frame &frameB       //!< Future reference coordinate system
  )
  {
    return triangle(acme::transform(input.vertex_0(), frameA, frameB),
                    acme::transform(input.vertex_1(), frameA, frameB),
                    acme::transform(input.vertex_2(), frameA, frameB));
  }

} // namespace acme

#endif

///
/// eof: acme_transform.hh
///