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
/// file: acme_coplanar.hh
///

#ifndef INCLUDE_ACME_COPLANAR
#define INCLUDE_ACME_COPLANAR

#include "acme.hh"
#include "acme_aabb.hh"
#include "acme_circle.hh"
#include "acme_line.hh"
#include "acme_parallel.hh"
#include "acme_plane.hh"
#include "acme_ray.hh"
#include "acme_segment.hh"
#include "acme_triangle.hh"

namespace acme
{

  /*\
   |    ____            _                        
   |   / ___|___  _ __ | | __ _ _ __   __ _ _ __ 
   |  | |   / _ \| '_ \| |/ _` | '_ \ / _` | '__|
   |  | |__| (_) | |_) | | (_| | | | | (_| | |   
   |   \____\___/| .__/|_|\__,_|_| |_|\__,_|_|   
   |             |_|                             
  \*/

  //! Check if entitys are coplanar
  bool
  isCoplanar(
      entity const *entity0_in, //!< Input entity 0
      entity const *entity1_in, //!< Input entity 1
      real tolerance = EPSILON  //!< Tolerance
  );

  //! Check if lines are coplanar
  bool
  isCoplanar(
      line const &line0_in,    //!< Input line 0
      line const &line1_in,    //!< Input line 1
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if rays are coplanar
  bool
  isCoplanar(
      ray const &ray0_in,      //!< Input ray 0
      ray const &ray1_in,      //!< Input ray 1
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if planes are coplanar
  bool
  isCoplanar(
      plane const &plane0_in,  //!< Input plane 0
      plane const &plane1_in,  //!< Input plane 1
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if segments are coplanar
  bool
  isCoplanar(
      segment const &segment0_in, //!< Input segment 0
      segment const &segment1_in, //!< Input segment 1
      real tolerance = EPSILON    //!< Tolerance
  );

  //! Check if triangles layng planes are are coplanar
  bool
  isCoplanar(
      triangle const &triangle0_in, //!< Input triangle 0
      triangle const &triangle1_in, //!< Input triangle 1
      real tolerance = EPSILON      //!< Tolerance
  );

  //! Check if circles layng planes are coplanar
  bool
  isCoplanar(
      circle const &circle0_in, //!< Input circle 0
      circle const &circle1_in, //!< Input circle 1
      real tolerance = EPSILON  //!< Tolerance
  );

  //! Check if line and ray are coplanar
  bool
  isCoplanar(
      line const &line_in,     //!< Input line
      ray const &ray_in,       //!< Input ray
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if line and plane are coplanar
  bool
  isCoplanar(
      line const &line_in,     //!< Input line
      plane const &plane_in,   //!< Input plane
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if line and segment are coplanar
  bool
  isCoplanar(
      line const &line_in,       //!< Input line
      segment const &segment_in, //!< Input segment
      real tolerance = EPSILON   //!< Tolerance
  );

  //! Check if line and tringle laying plane are coplanar
  bool
  isCoplanar(
      line const &line_in,         //!< Input line
      triangle const &triangle_in, //!< Input triangle
      real tolerance = EPSILON     //!< Tolerance
  );

  //! Check if line and circle are coplanar
  bool
  isCoplanar(
      line const &line_in,     //!< Input line
      circle const &circle_in, //!< Input circle
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if ray and plane are coplanar
  bool
  isCoplanar(
      ray const &ray_in,       //!< Input ray
      plane const &plane_in,   //!< Input plane
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if ray and segment are coplanar
  bool
  isCoplanar(
      ray const &ray_in,         //!< Input ray
      segment const &segment_in, //!< Input segment
      real tolerance = EPSILON   //!< Tolerance
  );

  //! Check if ray and triangle are coplanar
  bool
  isCoplanar(
      ray const &ray_in,           //!< Input ray
      triangle const &triangle_in, //!< Input triangle
      real tolerance = EPSILON     //!< Tolerance
  );

  //! Check if ray and circle are coplanar
  bool
  isCoplanar(
      ray const &ray_in,       //!< Input ray
      circle const &circle_in, //!< Input circle
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if segment and plane are coplanar
  bool
  isCoplanar(
      plane const &plane_in,     //!< Input plane
      segment const &segment_in, //!< Input segment
      real tolerance = EPSILON   //!< Tolerance
  );

  //! Check if plane and triangle are coplanar
  bool
  isCoplanar(
      plane const &plane_in,       //!< Input plane
      triangle const &triangle_in, //!< Input triangle
      real tolerance = EPSILON     //!< Tolerance
  );

  //! Check if plane and circle layng plane are coplanar
  bool
  isCoplanar(
      plane const &plane_in,   //!< Input plane
      circle const &circle_in, //!< Input circle
      real tolerance = EPSILON //!< Tolerance
  );

  //! Check if segment and triangle are coplanar
  bool
  isCoplanar(
      segment const &segment_in,   //!< Input segment
      triangle const &triangle_in, //!< Input triangle
      real tolerance = EPSILON     //!< Tolerance
  );

  //! Check if segment and circle are coplanar
  bool
  isCoplanar(
      segment const &segment_in, //!< Input segment
      circle const &circle_in,   //!< Input circle
      real tolerance = EPSILON   //!< Tolerance
  );

  //! Check if triangle and circle are coplanar
  bool
  isCoplanar(
      triangle const &triangle_in, //!< Input triangle
      circle const &circle_in,     //!< Input circle
      real tolerance = EPSILON     //!< Tolerance
  );

} // namespace acme

#endif

///
/// eof: acme_coplanar.hh
///