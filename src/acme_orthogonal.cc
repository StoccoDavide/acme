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
/// file: acme_orthogonal.cc
///

#include "acme_orthogonal.hh"

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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line0,
      line const &line1,
      real_type tolerance)
  {
    return acme::isOrthogonal(line0.direction(),
                              line1.direction(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray0,
      ray const &ray1,
      real_type tolerance)
  {
    return acme::isOrthogonal(ray0.direction(),
                              ray1.direction(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane0,
      plane const &plane1,
      real_type tolerance)
  {
    return acme::isOrthogonal(plane0.normal(),
                              plane1.normal(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      segment const &segment0,
      segment const &segment1,
      real_type tolerance)
  {
    return acme::isOrthogonal(segment0.toNormalizedVector(),
                              segment1.toNormalizedVector(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      triangle const &triangle0,
      triangle const &triangle1,
      real_type tolerance)
  {
    return acme::isOrthogonal(triangle0.normal(),
                              triangle1.normal(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      circle const &circle0,
      circle const &circle1,
      real_type tolerance)
  {
    return acme::isOrthogonal(circle0.normal(),
                              circle1.normal(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      ray const &ray,
      real_type tolerance)
  {
    return acme::isOrthogonal(line.direction(),
                              ray.direction(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      plane const &plane,
      real_type tolerance)
  {
    return acme::isParallel(line.direction(),
                            plane.normal(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      segment const &segment,
      real_type tolerance)
  {
    return acme::isOrthogonal(line.direction(),
                              segment.toNormalizedVector(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      triangle const &triangle,
      real_type tolerance)
  {
    return acme::isParallel(line.direction(),
                            triangle.normal(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      circle const &circle,
      real_type tolerance)
  {
    return acme::isParallel(line.direction(),
                            circle.normal(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray,
      plane const &plane,
      real_type tolerance)
  {
    return acme::isParallel(ray.direction(),
                            plane.normal(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray,
      segment const &segment,
      real_type tolerance)
  {
    return acme::isOrthogonal(ray.direction(),
                              segment.toNormalizedVector(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray,
      triangle const &triangle,
      real_type tolerance)
  {
    return acme::isParallel(ray.direction(),
                            triangle.normal(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray,
      circle const &circle,
      real_type tolerance)
  {
    return acme::isParallel(ray.direction(),
                            circle.normal(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane,
      segment const &segment,
      real_type tolerance)
  {
    return acme::isParallel(segment.toNormalizedVector(),
                            plane.normal(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane,
      triangle const &triangle,
      real_type tolerance)
  {
    return acme::isOrthogonal(plane.normal(),
                              triangle.normal(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane,
      circle const &circle,
      real_type tolerance)
  {
    return acme::isOrthogonal(plane.normal(),
                              circle.normal(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      segment const &segment,
      triangle const &triangle,
      real_type tolerance)
  {
    return acme::isParallel(segment.toNormalizedVector(),
                            triangle.normal(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      segment const &segment,
      circle const &circle,
      real_type tolerance)
  {
    return acme::isParallel(segment.toNormalizedVector(),
                            circle.normal(),
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      triangle const &triangle,   
      circle const &circle,       
      real_type tolerance) 
  {
    return acme::isOrthogonal(triangle.normal(),
                              circle.normal(),
                              tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_orthogonal.cc
///