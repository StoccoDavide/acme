/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 2-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 2-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
(*                                                                     *)
(*    Davide Stocco                                                    *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: davide.stocco@unitn.it                                   *)
(*                                                                     *)
(*    Enrico Bertolazzi                                                *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: enrico.bertolazzi@unitn.it                               *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_parallel.hh
///

#ifndef INCLUDE_ACME_PARALLEL
#define INCLUDE_ACME_PARALLEL

#include "acme.hh"
#include "acme_aabb.hh"
#include "acme_circle.hh"
#include "acme_line.hh"
#include "acme_orthogonal.hh"
#include "acme_plane.hh"
#include "acme_ray.hh"
#include "acme_segment.hh"
#include "acme_triangle.hh"

namespace acme
{

  /*\
   |   ____                 _ _      _ 
   |  |  _ \ __ _ _ __ __ _| | | ___| |
   |  | |_) / _` | '__/ _` | | |/ _ \ |
   |  |  __/ (_| | | | (_| | | |  __/ |
   |  |_|   \__,_|_|  \__,_|_|_|\___|_|
   |                                   
  \*/

  //! Check if geometrical entities are parallel
  bool
  isParallel(
      entity const *entity0_in, //!< Input entity 0
      entity const *entity1_in, //!< Input entity 1
      real tolerance = EPSILON  //!< Tolerance
  );

  //! Check if vectors are parallel
  bool
  isParallel(
      vec3 const &vector0_in,  //!< Input vector 0
      vec3 const &vector1_in,  //!< Input vector 1
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if vector and line are parallel
  bool
  isParallel(
      vec3 const &vector_in,   //!< Input ray
      line const &line_in,     //!< Input vector
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if vector and ray are parallel
  bool
  isParallel(
      vec3 const &vector_in,   //!< Input vector
      ray const &ray_in,       //!< Input ray
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if vector and plane are parallel
  bool
  isParallel(
      vec3 const &vector_in,   //!< Input vector
      plane const &plane_in,   //!< Input plane
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if vector and segment are parallel
  bool
  isParallel(
      vec3 const &vector_in,     //!< Input vector
      segment const &segment_in, //!< Input segment
      real tolerance = EPSILON   //!< Tolerance
  );

  //! Check if vector and triangle are parallel
  bool
  isParallel(
      vec3 const &vector_in,       //!< Input vector
      triangle const &triangle_in, //!< Input triangle
      real tolerance = EPSILON     //!< Tolerance
  );

  //! Check if vector and circle are parallel
  bool
  isParallel(
      vec3 const &vector_in,   //!< Input vector
      circle const &circle_in, //!< Input circle
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if lines are parallel
  bool
  isParallel(
      line const &line0_in,    //!< Input line 0
      line const &line1_in,    //!< Input line 1
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if rays are parallel
  bool
  isParallel(
      ray const &ray0_in,      //!< Input ray 0
      ray const &ray1_in,      //!< Input ray 1
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if planes are parallel
  bool
  isParallel(
      plane const &plane0_in,  //!< Input plane 0
      plane const &plane1_in,  //!< Input plane 1
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if segments are parallel
  bool
  isParallel(
      segment const &segment0_in, //!< Input segment 0
      segment const &segment1_in, //!< Input segment 1
      real tolerance = EPSILON    //!< Tolerance
  );

  //! Check if triangles layng planes are are parallel
  bool
  isParallel(
      triangle const &triangle0_in, //!< Input triangle 0
      triangle const &triangle1_in, //!< Input triangle 1
      real tolerance = EPSILON      //!< Tolerance
  );

  //! Check if circles layng planes are parallel
  bool
  isParallel(
      circle const &circle0_in, //!< Input circle 0
      circle const &circle1_in, //!< Input circle 1
      real tolerance = EPSILON  //!< Tolerance
  );

  //! Check if line and ray are parallel
  bool
  isParallel(
      line const &line_in,     //!< Input line
      ray const &ray_in,       //!< Input ray
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if line and plane are parallel
  bool
  isParallel(
      line const &line_in,     //!< Input line
      plane const &plane_in,   //!< Input plane
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if line and segment are parallel
  bool
  isParallel(
      line const &line_in,       //!< Input line
      segment const &segment_in, //!< Input segment
      real tolerance = EPSILON   //!< Tolerance
  );

  //! Check if line and triangle are parallel
  bool
  isParallel(
      line const &line_in,         //!< Input line
      triangle const &triangle_in, //!< Input triangle
      real tolerance = EPSILON     //!< Tolerance
  );

  //! Check if line and circle are parallel
  bool
  isParallel(
      line const &line_in,     //!< Input line
      circle const &circle_in, //!< Input circle
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if ray and plane are parallel
  bool
  isParallel(
      ray const &ray_in,       //!< Input ray
      plane const &plane_in,   //!< Input plane
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if ray and segment are parallel
  bool
  isParallel(
      ray const &ray_in,         //!< Input ray
      segment const &segment_in, //!< Input segment
      real tolerance = EPSILON   //!< Tolerance
  );

  //! Check if ray and triangle are parallel
  bool
  isParallel(
      ray const &ray_in,           //!< Input ray
      triangle const &triangle_in, //!< Input triangle
      real tolerance = EPSILON     //!< Tolerance
  );

  //! Check if ray and circle are parallel
  bool
  isParallel(
      ray const &ray_in,       //!< Input ray
      circle const &circle_in, //!< Input circle
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if segment and plane are parallel
  bool
  isParallel(
      plane const &plane_in,     //!< Input plane
      segment const &segment_in, //!< Input segment
      real tolerance = EPSILON   //!< Tolerance
  );

  //! Check if plane and triangle are parallel
  bool
  isParallel(
      plane const &plane_in,       //!< Input plane
      triangle const &triangle_in, //!< Input triangle
      real tolerance = EPSILON     //!< Tolerance
  );

  //! Check if plane and circle layng plane are parallel
  bool
  isParallel(
      plane const &plane_in,   //!< Input plane
      circle const &circle_in, //!< Input circle
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if segment and triangle are parallel
  bool
  isParallel(
      segment const &segment_in,   //!< Input segmentz
      triangle const &triangle_in, //!< Input triangle
      real tolerance = EPSILON     //!< Tolerance
  );

  //! Check if segment and circle are parallel
  bool
  isParallel(
      segment const &segment_in, //!< Input segment
      circle const &triangle_in, //!< Input circle
      real tolerance = EPSILON   //!< Tolerance
  );

  //! Check if triangle and circle are parallel
  bool
  isParallel(
      triangle const &triangle_in, //!< Input triangle
      circle const &circle_in,     //!< Input circle
      real tolerance = EPSILON     //!< Tolerance
  );

} // namespace acme

#endif

///
/// eof: acme_parallel.hh
///