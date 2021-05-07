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
      entity const *entity0,   //!< Input entity 0
      entity const *entity1,   //!< Input entity 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if lines are parallel
  bool
  isParallel(
      line const &line0,       //!< Input line 0
      line const &line1,       //!< Input line 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if rays are parallel
  bool
  isParallel(
      ray const &ray0,         //!< Input ray 0
      ray const &ray1,         //!< Input ray 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if planes are parallel
  bool
  isParallel(
      plane const &plane0,     //!< Input plane 0
      plane const &plane1,     //!< Input plane 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if segments are parallel
  bool
  isParallel(
      segment const &segment0, //!< Input segment 0
      segment const &segment1, //!< Input segment 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if triangles layng planes are are parallel
  bool
  isParallel(
      triangle const &triangle0, //!< Input triangle 0
      triangle const &triangle1, //!< Input triangle 1
      real tolerance = Epsilon   //!< Tolerance
  );

  //! Check if circles layng planes are parallel
  bool
  isParallel(
      circle const &circle0,   //!< Input circle 0
      circle const &circle1,   //!< Input circle 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and ray are parallel
  bool
  isParallel(
      line const &line,        //!< Input line
      ray const &ray,          //!< Input ray
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and plane are parallel
  bool
  isParallel(
      line const &line,        //!< Input line
      plane const &plane,      //!< Input plane
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and segment are parallel
  bool
  isParallel(
      line const &line,        //!< Input line
      segment const &segment,  //!< Input segment
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and triangle are parallel
  bool
  isParallel(
      line const &line,         //!< Input line
      triangle const &triangle, //!< Input triangle
      real tolerance = Epsilon  //!< Tolerance
  );

  //! Check if line and circle are parallel
  bool
  isParallel(
      line const &line,        //!< Input line
      circle const &circle,    //!< Input circle
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if ray and plane are parallel
  bool
  isParallel(
      ray const &ray,          //!< Input ray
      plane const &plane,      //!< Input plane
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if ray and segment are parallel
  bool
  isParallel(
      ray const &ray,          //!< Input ray
      segment const &segment,  //!< Input segment
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if ray and triangle are parallel
  bool
  isParallel(
      ray const &ray,           //!< Input ray
      triangle const &triangle, //!< Input triangle
      real tolerance = Epsilon  //!< Tolerance
  );

  //! Check if ray and circle are parallel
  bool
  isParallel(
      ray const &ray,          //!< Input ray
      circle const &circle,    //!< Input circle
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if segment and plane are parallel
  bool
  isParallel(
      plane const &plane,      //!< Input plane
      segment const &segment,  //!< Input segment
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if plane and triangle are parallel
  bool
  isParallel(
      plane const &plane,       //!< Input plane
      triangle const &triangle, //!< Input triangle
      real tolerance = Epsilon  //!< Tolerance
  );

  //! Check if plane and circle layng plane are parallel
  bool
  isParallel(
      plane const &plane,      //!< Input plane
      circle const &circle,    //!< Input circle
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if segment and triangle are parallel
  bool
  isParallel(
      segment const &segment,   //!< Input segmentz
      triangle const &triangle, //!< Input triangle
      real tolerance = Epsilon  //!< Tolerance
  );

  //! Check if segment and circle are parallel
  bool
  isParallel(
      segment const &segment,  //!< Input segment
      circle const &triangle,  //!< Input circle
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if triangle and circle are parallel
  bool
  isParallel(
      triangle const &triangle, //!< Input triangle
      circle const &circle,     //!< Input circle
      real tolerance = Epsilon  //!< Tolerance
  );

} // namespace acme

#endif

///
/// eof: acme_parallel.hh
///