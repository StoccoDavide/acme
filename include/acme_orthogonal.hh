/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *)
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
/// file: acme_orthogonal.hh
///

#ifndef INCLUDE_ACME_ORTHOGONAL
#define INCLUDE_ACME_ORTHOGONAL

#include "acme.hh"
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
   |    ___       _   _                                   _ 
   |   / _ \ _ __| |_| |__   ___   __ _  ___  _ __   __ _| |
   |  | | | | '__| __| '_ \ / _ \ / _` |/ _ \| '_ \ / _` | |
   |  | |_| | |  | |_| | | | (_) | (_| | (_) | | | | (_| | |
   |   \___/|_|   \__|_| |_|\___/ \__, |\___/|_| |_|\__,_|_|
   |                              |___/                     
  \*/

  //! Check if geometrical entities are orthogonal
  bool
  isOrthogonal(
      entity const *entity0,        //!< Input entity 0
      entity const *entity1,        //!< Input entity 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if vectors are orthogonal
  bool
  isOrthogonal(
      vec3 const &vector0,          //!< Input vector 0
      vec3 const &vector1,          //!< Input vector 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if lines are orthogonal
  bool
  isOrthogonal(
      line const &line0,            //!< Input line 0
      line const &line1,            //!< Input line 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if rays are orthogonal
  bool
  isOrthogonal(
      ray const &ray0,              //!< Input ray 0
      ray const &ray1,              //!< Input ray 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if planes are orthogonal
  bool
  isOrthogonal(
      plane const &plane0,          //!< Input plane 0
      plane const &plane1,          //!< Input plane 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if segments are orthogonal
  bool
  isOrthogonal(
      segment const &segment0,      //!< Input segment 0
      segment const &segment1,      //!< Input segment 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if triangles layng planes are are orthogonal
  bool
  isOrthogonal(
      triangle const &triangle0,    //!< Input triangle 0
      triangle const &triangle1,    //!< Input triangle 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if circles layng planes are orthogonal
  bool
  isOrthogonal(
      circle const &circle0,        //!< Input circle 0
      circle const &circle1,        //!< Input circle 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if vector and line are orthogonal
  bool
  isOrthogonal(
      vec3 const &vector,           //!< Input ray
      line const &line,             //!< Input vector
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if vector and ray are orthogonal
  bool
  isOrthogonal(
      vec3 const &vector,           //!< Input vector
      ray const &ray,               //!< Input ray
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if vector and plane are orthogonal
  bool
  isOrthogonal(
      vec3 const &vector,           //!< Input vector
      plane const &plane,           //!< Input plane
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if vector and segment are orthogonal
  bool
  isOrthogonal(
      vec3 const &vector,           //!< Input vector
      segment const &segment,       //!< Input segment
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if vector and triangle are orthogonal
  bool
  isOrthogonal(
      vec3 const &vector,           //!< Input vector
      triangle const &triangle,     //!< Input triangle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if vector and circle are orthogonal
  bool
  isOrthogonal(
      vec3 const &vector,           //!< Input vector
      circle const &circle,         //!< Input circle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and ray are orthogonal
  bool
  isOrthogonal(
      line const &line,             //!< Input line
      ray const &ray,               //!< Input ray
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and plane are orthogonal
  bool
  isOrthogonal(
      line const &line,             //!< Input line
      plane const &plane,           //!< Input plane
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and segment are orthogonal
  bool
  isOrthogonal(
      line const &line,             //!< Input line
      segment const &segment,       //!< Input segment
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and triangle are orthogonal
  bool
  isOrthogonal(
      line const &line,             //!< Input line
      triangle const &triangle,     //!< Input triangle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and circle are orthogonal
  bool
  isOrthogonal(
      line const &line,             //!< Input line
      circle const &circle,         //!< Input circle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if ray and plane are orthogonal
  bool
  isOrthogonal(
      ray const &ray,               //!< Input ray
      plane const &plane,           //!< Input plane
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if ray and segment are orthogonal
  bool
  isOrthogonal(
      ray const &ray,               //!< Input ray
      segment const &segment,       //!< Input segment
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if ray and triangle are orthogonal
  bool
  isOrthogonal(
      ray const &ray,               //!< Input ray
      triangle const &triangle,     //!< Input triangle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if ray and circle are orthogonal
  bool
  isOrthogonal(
      ray const &ray,               //!< Input ray
      circle const &circle,         //!< Input circle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if segment and plane are orthogonal
  bool
  isOrthogonal(
      plane const &plane,           //!< Input plane
      segment const &segment,       //!< Input segment
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if plane and triangle are orthogonal
  bool
  isOrthogonal(
      plane const &plane,           //!< Input plane
      triangle const &triangle,     //!< Input triangle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if plane and circle layng plane are orthogonal
  bool
  isOrthogonal(
      plane const &plane,           //!< Input plane
      circle const &circle,         //!< Input circle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if segment and triangle are orthogonal
  bool
  isOrthogonal(
      segment const &segment,       //!< Input segment
      triangle const &triangle,     //!< Input triangle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if segment and circle are orthogonal
  bool
  isOrthogonal(
      segment const &segment,       //!< Input segment
      circle const &circle,         //!< Input circle
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if triangle and circle are orthogonal
  bool
  isOrthogonal(
      triangle const &triangle,     //!< Input triangle
      circle const &circle,         //!< Input circle
      real_type tolerance = Epsilon //!< Tolerance
  );

} // namespace acme

#endif

///
/// eof: acme_orthogonal.hh
///