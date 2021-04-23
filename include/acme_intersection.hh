/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project - Release Version 0.0.0                            *)
(*                                                                     *)
(* Copyright (c) 2020 Davide Stocco, All Rights Reserved.              *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 2-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 2-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
(*                                                                     *)
(*    Davide Stocco                                                    *)
(*    University of Trento                                             *)
(*    Department of Industrial Engineering                             *)
(*    davide.stocco@unitn.it                                           *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_intersection.hh
///

#ifndef INCLUDE_ACME_INTERSECTION
#define INCLUDE_ACME_INTERSECTION

#include "acme.hh"
#include "acme_math.hh"
#include "acme_line.hh"
#include "acme_ray.hh"
#include "acme_plane.hh"
#include "acme_segment.hh"
#include "acme_triangle.hh"
#include "acme_box.hh"
#include "acme_circle.hh"

namespace acme
{

  /*\
   |   ___       _                          _   _             
   |  |_ _|_ __ | |_ ___ _ __ ___  ___  ___| |_(_) ___  _ __  
   |   | || '_ \| __/ _ \ '__/ __|/ _ \/ __| __| |/ _ \| '_ \ 
   |   | || | | | ||  __/ |  \__ \  __/ (__| |_| | (_) | | | |
   |  |___|_| |_|\__\___|_|  |___/\___|\___|\__|_|\___/|_| |_|
   |                                                          
  \*/

  //! Intersection between two lines \n
  //! WARNING: This function does not support parallel objects!
  bool
  intersection(
      line const &line0, //!< Input line 0
      line const &line1, //!< Input line 1
      vec3 &point        //!< Output point
  );

  //! Intersection between two rays \n
  //! WARNING: This function does not support parallel objects!
  bool
  intersection(
      ray const &ray0, //!< Input ray 0
      ray const &ray1, //!< Input ray 1
      vec3 &point      //!< Output point
  );

  //! Intersection between two segments \n
  //! WARNING: This function does not support parallel objects!
  bool
  intersection(
      segment const &segment0, //!< Input segment 0
      segment const &segment1, //!< Input segment 1
      vec3 &point              //!< Output point
  );

  //! Intersection between two boxes \n
  bool
  intersection(
      box const &box0, //!< Input box 0
      box const &box1, //!< Input box 1
      box &box         //!< Output box
  );

  //! Intersection between three planes \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane0, //!< Input plane 0
      plane const &plane1, //!< Input plane 1
      plane const &plane2, //!< Input plane 1
      vec3 &point          //!< Output point
  );

  //! Intersection between two planes \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane0, //!< Input plane 0
      plane const &plane1, //!< Input plane 1
      line &line           //!< Output line
  );

  //! Intersection ray with plane \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,     //!< Input ray
      plane const &plane, //!< Input plane
      vec3 &point         //!< Output point
  );

  //! Intersection line with plane \n
  //! WARNING: This function does not support coplanarity!
  bool intersection(
      line const &line,   //!< Input line
      plane const &plane, //!< Input plane
      vec3 &point         //!< Output point
  );

  //! Intersection segment with plane (no precalculated normal) \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      segment const &segment, //!< Input segment
      plane const &plane,     //!< Input plane
      vec3 &point             //!< Output point
  );

  //! Intersection ray with triangle (no precalculated normal) \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,           //!< Input ray
      triangle const &triangle, //!< Input triangle
      vec3 &point               //!< Output point
  );

  //! Intersection line with triangle (no precalculated normal) \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line,         //!< Input line
      triangle const &triangle, //!< Input triangle
      vec3 &point               //!< Output point
  );

  //! Intersection plane with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane,       //!< Input plane
      triangle const &triangle, //!< Input triangle
      segment &segment          //!< Ouput plane
  );

  //! Intersection line and circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line,     //!< Input line
      circle const &circle, //!< Input circle
      vec3 &point           //!< Ouput point
  );

  //! Intersection ray with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,       //!< Input ray
      circle const &circle, //!< Input circle
      vec3 &point           //!< Ouput point
  );

  //! Intersection segment with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      segment const &segment, //!< Input segment
      circle const &circle,   //!< Input circle
      vec3 &point             //!< Ouput point
  );

  //! Intersection between two segments \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      segment const &segment0, //!< Input segment 0
      segment const &segment1, //!< Input segment 1
      segment &segment         //!< Output segment
  );

  //! Intersection between line and segment \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      line const &line,          //!< Input line
      segment const &segment_in, //!< Input segment
      segment &segment_out       //!< Output segment
  );

  //! Intersection between ray and segment \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      ray const &ray,            //!< Input ray
      segment const &segment_in, //!< Input segment
      segment &segment_out       //!< Output segment
  );

  //! Intersection line with circle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      line const &line,     //!< Input line
      circle const &circle, //!< Input circle
      segment &segment      //!< Ouput segment
  );

  //! Intersection ray with circle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      ray const &ray,       //!< Input ray
      circle const &circle, //!< Input circle
      segment &segment      //!< Ouput segment
  );

  //! Intersection plane with circle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      plane const &plane,   //!< Input plane
      circle const &circle, //!< Input circle
      segment &segment      //!< Ouput segment
  );

  //! Intersection segment with circle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      segment const &segment_in, //!< Input segment
      circle const &circle,      //!< Input circle
      segment &segment_out       //!< Ouput segment
  );

  //! Intersection circle with triangle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      circle const &circle,     //!< Input circle
      triangle const &triangle, //!< Input triangle
      segment &segment          //!< Ouput segment
  );

} // namespace acme

#endif

///
/// eof: acme_intersection.hh
///