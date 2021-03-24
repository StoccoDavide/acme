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
/// file: acme_intersect.hh
///

#ifndef INCLUDE_ACME_INTERSECT
#define INCLUDE_ACME_INTERSECT

#include "acme.hh"
#include "acme_math.hh"
#include "acme_plane.hh"
#include "acme_ray.hh"
#include "acme_line.hh"
#include "acme_triangle.hh"
#include "acme_circle.hh"

namespace acme
{

  /*\
   |   ___       _                          _   
   |  |_ _|_ __ | |_ ___ _ __ ___  ___  ___| |_ 
   |   | || '_ \| __/ _ \ '__/ __|/ _ \/ __| __|
   |   | || | | | ||  __/ |  \__ \  __/ (__| |_ 
   |  |___|_| |_|\__\___|_|  |___/\___|\___|\__|
   |                                            
  \*/

  //! Intersect between three planes
  bool intersect(
      plane const &plane0, //!< Input plane 0
      plane const &plane1, //!< Input plane 1
      plane const &plane2, //!< Input plane 1
      vec3 &point          //!< Output point
  );

  //! Intersect between two planes
  bool intersect(
      plane const &plane0, //!< Input plane 0
      plane const &plane1, //!< Input plane 1
      line &line           //!< Output line
  );

  //! Intersect ray with plane
  bool intersect(
      ray const &ray,     //!< Input ray
      plane const &plane, //!< Input plane
      vec3 &point         //!< Output point
  );

  //! Intersect line with plane
  bool intersect(
      line const &line,   //!< Input line
      plane const &plane, //!< Input plane
      vec3 &point         //!< Output point
  );

  //! Intersect triangle with ray (no precalculated normal)
  bool intersect(
      triangle const &triangle, //!< Input triangle
      ray const &ray,           //!< Input plane
      vec3 &point               //!< Output point
  );

  //! Intersect triangle with line (no precalculated normal)
  bool intersect(
      triangle const &triangle, //!< Input triangle
      line const &line,         //!< Input plane
      vec3 &point               //!< Output point
  );

  //! Intersect triangle with plane
  bool intersect(
      triangle const &triangle, //!< Input triangle
      plane const &plane,       //!< Input plane
      segment &segment          //!< Input plane
  );

  /*/! Intersect ray with plane
  bool intersect(
      circle const &circle, //!< Input circle
      plane const &plane,   //!< Input plane
      segment &segment      //!< Input plane
  )
  {
  }*/

} // namespace acme

#endif

///
/// eof: acme_intersect.hh
///