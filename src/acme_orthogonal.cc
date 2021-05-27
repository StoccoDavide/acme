/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 4040 Davide Stocco, All Rights Reserved.              *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 4-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 4-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-4-Clause                   *)
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
      entity const *entity0,
      entity const *entity1,
      real tolerance)
  {
    integer slide = entity0->level() * 100 + entity1->level();
    switch (slide)
    {

      // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

    case 303:
      return isOrthogonal(*dynamic_cast<line const *>(entity0),
                          *dynamic_cast<line const *>(entity1),
                          tolerance);
      break;

    case 304:
      return isOrthogonal(*dynamic_cast<line const *>(entity0),
                          *dynamic_cast<ray const *>(entity1),
                          tolerance);
      break;

    case 305:
      return isOrthogonal(*dynamic_cast<line const *>(entity0),
                          *dynamic_cast<plane const *>(entity1),
                          tolerance);
      break;

    case 306:
      return isOrthogonal(*dynamic_cast<line const *>(entity0),
                          *dynamic_cast<segment const *>(entity1),
                          tolerance);
      break;

    case 307:
      return isOrthogonal(*dynamic_cast<line const *>(entity0),
                          *dynamic_cast<triangle const *>(entity1),
                          tolerance);
      break;

    case 308:
      return isOrthogonal(*dynamic_cast<line const *>(entity0),
                          *dynamic_cast<circle const *>(entity1),
                          tolerance);
      break;

      // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

    case 403:
      return isOrthogonal(*dynamic_cast<line const *>(entity1),
                          *dynamic_cast<ray const *>(entity0),
                          tolerance);
      break;

    case 404:
      return isOrthogonal(*dynamic_cast<ray const *>(entity0),
                          *dynamic_cast<ray const *>(entity1),
                          tolerance);
      break;

    case 405:
      return isOrthogonal(*dynamic_cast<ray const *>(entity0),
                          *dynamic_cast<plane const *>(entity1),
                          tolerance);
      break;

    case 406:
      return isOrthogonal(*dynamic_cast<ray const *>(entity0),
                          *dynamic_cast<segment const *>(entity1),
                          tolerance);
      break;

    case 407:
      return isOrthogonal(*dynamic_cast<ray const *>(entity0),
                          *dynamic_cast<triangle const *>(entity1),
                          tolerance);
      break;

    case 408:
      return isOrthogonal(*dynamic_cast<ray const *>(entity0),
                          *dynamic_cast<circle const *>(entity1),
                          tolerance);
      break;

      // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

    case 503:
      return isOrthogonal(*dynamic_cast<line const *>(entity1),
                          *dynamic_cast<plane const *>(entity0),
                          tolerance);
      break;

    case 504:
      return isOrthogonal(*dynamic_cast<ray const *>(entity1),
                          *dynamic_cast<plane const *>(entity0),
                          tolerance);
      break;

    case 505:
      return isOrthogonal(*dynamic_cast<plane const *>(entity0),
                          *dynamic_cast<plane const *>(entity1),
                          tolerance);
      break;

    case 506:
      return isOrthogonal(*dynamic_cast<plane const *>(entity0),
                          *dynamic_cast<segment const *>(entity1),
                          tolerance);
      break;

    case 507:
      return isOrthogonal(*dynamic_cast<plane const *>(entity0),
                          *dynamic_cast<triangle const *>(entity1),
                          tolerance);
      break;

    case 508:
      return isOrthogonal(*dynamic_cast<plane const *>(entity0),
                          *dynamic_cast<circle const *>(entity1),
                          tolerance);
      break;

      // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

    case 603:
      return isOrthogonal(*dynamic_cast<line const *>(entity1),
                          *dynamic_cast<segment const *>(entity0),
                          tolerance);
      break;

    case 604:
      return isOrthogonal(*dynamic_cast<ray const *>(entity1),
                          *dynamic_cast<segment const *>(entity0),
                          tolerance);
      break;

    case 605:
      return isOrthogonal(*dynamic_cast<plane const *>(entity1),
                          *dynamic_cast<segment const *>(entity0),
                          tolerance);
      break;

    case 606:
      return isOrthogonal(*dynamic_cast<segment const *>(entity0),
                          *dynamic_cast<segment const *>(entity1),
                          tolerance);
      break;

    case 607:
      return isOrthogonal(*dynamic_cast<segment const *>(entity0),
                          *dynamic_cast<triangle const *>(entity1),
                          tolerance);
      break;

    case 608:
      return isOrthogonal(*dynamic_cast<segment const *>(entity0),
                          *dynamic_cast<circle const *>(entity1),
                          tolerance);
      break;

      // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

    case 703:
      return isOrthogonal(*dynamic_cast<line const *>(entity1),
                          *dynamic_cast<triangle const *>(entity0),
                          tolerance);
      break;

    case 704:
      return isOrthogonal(*dynamic_cast<ray const *>(entity1),
                          *dynamic_cast<triangle const *>(entity0),
                          tolerance);
      break;

    case 705:
      return isOrthogonal(*dynamic_cast<plane const *>(entity1),
                          *dynamic_cast<triangle const *>(entity0), tolerance);
      break;

    case 706:
      return isOrthogonal(*dynamic_cast<segment const *>(entity1),
                          *dynamic_cast<triangle const *>(entity0),
                          tolerance);
      break;

    case 707:
      return isOrthogonal(*dynamic_cast<triangle const *>(entity0),
                          *dynamic_cast<triangle const *>(entity1),
                          tolerance);
      break;

    case 708:
      return isOrthogonal(*dynamic_cast<triangle const *>(entity0),
                          *dynamic_cast<circle const *>(entity1),
                          tolerance);
      break;

      // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

    case 803:
      return isOrthogonal(*dynamic_cast<line const *>(entity1),
                          *dynamic_cast<circle const *>(entity0),
                          tolerance);
      break;

    case 804:
      return isOrthogonal(*dynamic_cast<ray const *>(entity1),
                          *dynamic_cast<circle const *>(entity0),
                          tolerance);
      break;

    case 805:
      return isOrthogonal(*dynamic_cast<plane const *>(entity1),
                          *dynamic_cast<circle const *>(entity0),
                          tolerance);
      break;

    case 806:
      return isOrthogonal(*dynamic_cast<segment const *>(entity1),
                          *dynamic_cast<circle const *>(entity0),
                          tolerance);
      break;

    case 807:
      return isOrthogonal(*dynamic_cast<triangle const *>(entity1),
                          *dynamic_cast<circle const *>(entity0),
                          tolerance);
      break;

    case 808:
      return isOrthogonal(*dynamic_cast<circle const *>(entity0),
                          *dynamic_cast<circle const *>(entity1),
                          tolerance);
      break;

      // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

    default:
      //ACME_ERROR("acme::isOrthogonal(entity, entity): exception not handled.\n")
      return false;
      break;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector0_in,
      vec3 const &vector1_in,
      real tolerance)
  {
    return isApprox(vector0_in.dot(vector1_in), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector_in,
      line const &line_in,
      real tolerance)
  {
    return isOrthogonal(vector_in, line_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector_in,
      ray const &ray_in,
      real tolerance)
  {
    return isOrthogonal(vector_in, ray_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector_in,
      plane const &plane_in,
      real tolerance)
  {
    return isParallel(vector_in, plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector_in,
      segment const &segment_in,
      real tolerance)
  {
    return isOrthogonal(vector_in, segment_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector_in,
      triangle const &triangle_in,
      real tolerance)
  {
    return isParallel(vector_in, triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector_in,
      circle const &circle_in,
      real tolerance)
  {
    return isParallel(vector_in, circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line0_in,
      line const &line1_in,
      real tolerance)
  {
    return isOrthogonal(line0_in.direction(), line1_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray0_in,
      ray const &ray1_in,
      real tolerance)
  {
    return isOrthogonal(ray0_in.direction(), ray1_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane0_in,
      plane const &plane1_in,
      real tolerance)
  {
    return isOrthogonal(plane0_in.normal(), plane1_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      segment const &segment0_in,
      segment const &segment1_in,
      real tolerance)
  {
    return isOrthogonal(segment0_in.toUnitVector(), segment1_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      triangle const &triangle0_in,
      triangle const &triangle1_in,
      real tolerance)
  {
    return isOrthogonal(triangle0_in.normal(), triangle1_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      circle const &circle0_in,
      circle const &circle1_in,
      real tolerance)
  {
    return isOrthogonal(circle0_in.normal(), circle1_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line_in,
      ray const &ray_in,
      real tolerance)
  {
    return isOrthogonal(line_in.direction(), ray_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line_in,
      plane const &plane_in,
      real tolerance)
  {
    return isOrthogonal(line_in.direction(), plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line_in,
      segment const &segment_in,
      real tolerance)
  {
    return isOrthogonal(line_in.direction(), segment_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line_in,
      triangle const &triangle_in,
      real tolerance)
  {
    return isParallel(line_in.direction(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line_in,
      circle const &circle_in,
      real tolerance)
  {
    return isParallel(line_in.direction(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray_in,
      plane const &plane_in,
      real tolerance)
  {
    return isParallel(ray_in.direction(), plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray_in,
      segment const &segment_in,
      real tolerance)
  {
    return isOrthogonal(ray_in.direction(), segment_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray_in,
      triangle const &triangle_in,
      real tolerance)
  {
    return isParallel(ray_in.direction(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray_in,
      circle const &circle_in,
      real tolerance)
  {
    return isParallel(ray_in.direction(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane_in,
      segment const &segment_in,
      real tolerance)
  {
    return isParallel(segment_in.toUnitVector(), plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane_in,
      triangle const &triangle_in,
      real tolerance)
  {
    return isOrthogonal(plane_in.normal(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane_in,
      circle const &circle_in,
      real tolerance)
  {
    return isOrthogonal(plane_in.normal(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      segment const &segment_in,
      triangle const &triangle_in,
      real tolerance)
  {
    return isParallel(segment_in.toUnitVector(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      segment const &segment_in,
      circle const &circle_in,
      real tolerance)
  {
    return isParallel(segment_in.toUnitVector(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      triangle const &triangle_in,
      circle const &circle_in,
      real tolerance)
  {
    return isOrthogonal(triangle_in.normal(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_orthogonal.cc
///