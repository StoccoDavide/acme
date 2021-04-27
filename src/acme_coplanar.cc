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
/// file: acme_coplanar.cc
///

#include "acme_coplanar.hh"

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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line0,
      line const &line1,
      real_type tolerance)
  {
    return acme::isOrthogonal(line0.origin() - line1.origin(),
                              line0.direction().cross(line1.direction()),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      ray const &ray0,
      ray const &ray1,
      real_type tolerance)
  {
    return acme::isOrthogonal(ray0.origin() - ray1.origin(),
                              ray0.direction().cross(ray1.direction()),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      plane const &plane0,
      plane const &plane1,
      real_type tolerance)
  {
    return acme::isParallel(plane0.normal(), plane1.normal(), tolerance) &&
           acme::isOrthogonal(plane0.origin() - plane1.origin(), plane1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      segment const &segment0,
      segment const &segment1,
      real_type tolerance)
  {
    return acme::isOrthogonal(segment0.point(0) - segment1.point(0),
                              segment0.toNormalizedVector().cross(segment1.toNormalizedVector()),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      triangle const &triangle0,
      triangle const &triangle1,
      real_type tolerance)
  {
    return acme::isCoplanar(triangle0.layingPlane(),
                            triangle1.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      circle const &circle0,
      circle const &circle1,
      real_type tolerance)
  {
    return acme::isCoplanar(circle0.layingPlane(),
                            circle1.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line,
      ray const &ray,
      real_type tolerance)
  {
    return acme::isOrthogonal(line.origin() - ray.origin(),
                              line.direction().cross(ray.direction()),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line,
      plane const &plane,
      real_type tolerance)
  {
    return acme::isOrthogonal(line.direction(), plane.normal(), tolerance) &&
           acme::isOrthogonal(line.origin() - plane.origin(), plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line,
      segment const &segment,
      real_type tolerance)
  {
    return acme::isOrthogonal(line.origin() - segment.point(0),
                              line.direction().cross(segment.toNormalizedVector()),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line,
      triangle const &triangle,
      real_type tolerance)
  {
    return acme::isCoplanar(line,
                            triangle.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line,
      circle const &circle,
      real_type tolerance)
  {
    return acme::isCoplanar(line,
                            circle.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      ray const &ray,
      plane const &plane,
      real_type tolerance)
  {
    return acme::isOrthogonal(ray.direction(), plane.normal(), tolerance) &&
           acme::isOrthogonal(ray.origin() - plane.origin(), plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      ray const &ray,
      segment const &segment,
      real_type tolerance)
  {
    return acme::isOrthogonal(ray.origin() - segment.point(0),
                              ray.direction().cross(segment.toNormalizedVector()),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      ray const &ray,
      triangle const &triangle,
      real_type tolerance)
  {
    return acme::isCoplanar(ray,
                            triangle.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      ray const &ray,
      circle const &circle,
      real_type tolerance)
  {
    return acme::isCoplanar(ray,
                            circle.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      plane const &plane,
      segment const &segment,
      real_type tolerance)
  {
    return acme::isCoplanar(line(segment.point(0), segment.toNormalizedVector()),
                            plane,
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      plane const &plane,
      triangle const &triangle,
      real_type tolerance)
  {
    return acme::isCoplanar(plane,
                            triangle.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      plane const &plane,
      circle const &circle,
      real_type tolerance)
  {
    return acme::isCoplanar(plane,
                            circle.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      segment const &segment,
      triangle const &triangle,
      real_type tolerance)
  {
    return acme::isCoplanar(line(segment.point(0), segment.toNormalizedVector()),
                            triangle.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      segment const &segment,
      circle const &circle,
      real_type tolerance)
  {
    return acme::isCoplanar(line(segment.point(0), segment.toNormalizedVector()),
                            circle.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      triangle const &triangle,
      circle const &circle,
      real_type tolerance)
  {
    return acme::isCoplanar(triangle.layingPlane(),
                            circle.layingPlane(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_coplanar.cc
///