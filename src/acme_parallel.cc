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
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: davide.stocco@unitn.it                                   *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_parallel.cc
///

#include "acme_parallel.hh"

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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line0,
      line const &line1,
      real_type tolerance)
  {
    return line0.direction().isParallel(line1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray0,
      ray const &ray1,
      real_type tolerance)
  {
    return ray0.direction().isParallel(ray1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane0,
      plane const &plane1,
      real_type tolerance)
  {
    return plane0.normal().isParallel(plane1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      segment const &segment0,
      segment const &segment1,
      real_type tolerance)
  {
    return segment0.toNormalizedVector().isParallel(segment1.toNormalizedVector(), tolerance);
  }
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      triangle const &triangle0,
      triangle const &triangle1,
      real_type tolerance)
  {
    return triangle0.normal().isParallel(triangle1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      circle const &circle0,
      circle const &circle1,
      real_type tolerance)
  {
    return circle0.normal().isParallel(circle1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      ray const &ray,
      real_type tolerance)
  {
    return line.direction().isParallel(ray.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      plane const &plane,
      real_type tolerance)
  {
    return line.direction().isOrthogonal(plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      segment const &segment,
      real_type tolerance)
  {
    return line.direction().isParallel(segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      triangle const &triangle,
      real_type tolerance)
  {
    return line.direction().isOrthogonal(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      circle const &circle,
      real_type tolerance)
  {
    return line.direction().isOrthogonal(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray,
      plane const &plane,
      real_type tolerance)
  {
    return ray.direction().isOrthogonal(plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray,
      segment const &segment,
      real_type tolerance)
  {
    return ray.direction().isParallel(segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray,
      triangle const &triangle,
      real_type tolerance)
  {
    return ray.direction().isOrthogonal(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray,
      circle const &circle,
      real_type tolerance)
  {
    return ray.direction().isOrthogonal(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane,
      segment const &segment,
      real_type tolerance)
  {
    return segment.toNormalizedVector().isOrthogonal(plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane,
      triangle const &triangle,
      real_type tolerance)
  {
    return plane.normal().isParallel(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane,
      circle const &circle,
      real_type tolerance)
  {
    return plane.normal().isParallel(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      segment const &segment,
      triangle const &triangle,
      real_type tolerance)
  {
    return segment.toNormalizedVector().isOrthogonal(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      segment const &segment,
      circle const &circle,
      real_type tolerance)
  {
    return segment.toNormalizedVector().isOrthogonal(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      triangle const &triangle,
      circle const &circle,
      real_type tolerance)
  {
    return triangle.normal().isParallel(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_parallel.cc
///