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
#include "acme_box.hh"

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

  //! Intersect between two lines \n
  //! ATTENTION: This function does not support parallel objects!
  bool intersect(
      line const &line0,      //!< Input line 0
      line const &line1,      //!< Input line 1
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersect between two rays \n
  //! ATTENTION: This function does not support parallel objects!
  bool intersect(
      ray const &ray0,        //!< Input ray 0
      ray const &ray1,        //!< Input ray 1
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersect between two segments \n
  //! ATTENTION: This function does not support parallel objects!
  bool
  intersect(
      segment const &segment0, //!< Input segment 0
      segment const &segment1, //!< Input segment 1
      vec3 &point = vec3_goat  //!< Output point
  );

  //! Intersect between two boxes \n
  bool intersect(
      box const &box0,    //!< Input box 0
      box const &box1,    //!< Input box 1
      box &box = box_goat //!< Output box
  );

  //! Intersect between three planes \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      plane const &plane0,    //!< Input plane 0
      plane const &plane1,    //!< Input plane 1
      plane const &plane2,    //!< Input plane 1
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersect between two planes \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      plane const &plane0,   //!< Input plane 0
      plane const &plane1,   //!< Input plane 1
      line &line = line_goat //!< Output line
  );

  //! Intersect ray with plane \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      ray const &ray,         //!< Input ray
      plane const &plane,     //!< Input plane
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersect line with plane \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      line const &line,       //!< Input line
      plane const &plane,     //!< Input plane
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersect segment with plane (no precalculated normal) \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      segment const &segment, //!< Input segment
      plane const &plane,     //!< Input plane
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersect ray with triangle (no precalculated normal) \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      ray const &ray,           //!< Input ray
      triangle const &triangle, //!< Input triangle
      vec3 &point = vec3_goat   //!< Output point
  );

  //! Intersect line with triangle (no precalculated normal) \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      line const &line,         //!< Input line
      triangle const &triangle, //!< Input triangle
      vec3 &point = vec3_goat   //!< Output point
  );

  //! Intersect plane with triangle \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      plane const &plane,             //!< Input plane
      triangle const &triangle,       //!< Input triangle
      segment &segment = segment_goat //!< Ouput plane
  );

  //! Intersect line and circle \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      line const &line,       //!< Input line
      circle const &circle,   //!< Input circle
      vec3 &point = vec3_goat //!< Ouput point
  );

  //! Intersect ray with circle \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      ray const &ray,         //!< Input ray
      circle const &circle,   //!< Input circle
      vec3 &point = vec3_goat //!< Ouput point
  );

  //! Intersect segment with circle \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      segment const &segment, //!< Input segment
      circle const &circle,   //!< Input circle
      vec3 &point = vec3_goat //!< Ouput point
  );

  //! Intersection between two segments \n
  //! ATTENTION: This function does not support coplanarity!
  bool intersect(
      segment const &segment0,        //!< Input segment 0
      segment const &segment1,        //!< Input segment 1
      segment &segment = segment_goat //!< Output segment
  );

  //! Intersect line with circle \n
  //! ATTENTION: This function only support coplanar objects!
  bool intersect(
      line const &line,               //!< Input line
      circle const &circle,           //!< Input circle
      segment &segment = segment_goat //!< Ouput segment
  );

  //! Intersect plane with circle \n
  //! ATTENTION: This function only support coplanar objects!
  bool intersect(
      plane const &plane,             //!< Input plane
      circle const &circle,           //!< Input circle
      segment &segment = segment_goat //!< Ouput segment
  );

  //! Intersect segment with circle \n
  //! ATTENTION: This function only support coplanar objects!
  bool intersect(
      segment const &segment_in,          //!< Input segment
      circle const &circle,               //!< Input circle
      segment &segment_out = segment_goat //!< Ouput segment
  );

  //! Intersect circle with triangle \n
  //! ATTENTION: This function only support coplanar objects!
  bool intersect(
      circle const &circle,           //!< Input circle
      triangle const &triangle,       //!< Input triangle
      segment &segment = segment_goat //!< Ouput segment
  );

} // namespace acme

#endif

///
/// eof: acme_intersect.hh
///

/*

*/