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
      entity const *entity0_in,
      entity const *entity1_in,
      real tolerance)
  {
    integer slide = entity0_in->level() * 100 + entity1_in->level();
    switch (slide)
    {

      // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

    case 303:
      return isParallel(*dynamic_cast<line const *>(entity0_in),
                        *dynamic_cast<line const *>(entity1_in),
                        tolerance);
      break;

    case 304:
      return isParallel(*dynamic_cast<line const *>(entity0_in),
                        *dynamic_cast<ray const *>(entity1_in),
                        tolerance);
      break;

    case 305:
      return isParallel(*dynamic_cast<line const *>(entity0_in),
                        *dynamic_cast<plane const *>(entity1_in),
                        tolerance);
      break;

    case 306:
      return isParallel(*dynamic_cast<line const *>(entity0_in),
                        *dynamic_cast<segment const *>(entity1_in),
                        tolerance);
      break;

    case 307:
      return isParallel(*dynamic_cast<line const *>(entity0_in),
                        *dynamic_cast<triangle const *>(entity1_in),
                        tolerance);
      break;

    case 308:
      return isParallel(*dynamic_cast<line const *>(entity0_in),
                        *dynamic_cast<circle const *>(entity1_in),
                        tolerance);
      break;

      // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

    case 403:
      return isParallel(*dynamic_cast<line const *>(entity1_in),
                        *dynamic_cast<ray const *>(entity0_in),
                        tolerance);
      break;

    case 404:
      return isParallel(*dynamic_cast<ray const *>(entity0_in),
                        *dynamic_cast<ray const *>(entity1_in),
                        tolerance);
      break;

    case 405:
      return isParallel(*dynamic_cast<ray const *>(entity0_in),
                        *dynamic_cast<plane const *>(entity1_in),
                        tolerance);
      break;

    case 406:
      return isParallel(*dynamic_cast<ray const *>(entity0_in),
                        *dynamic_cast<segment const *>(entity1_in),
                        tolerance);
      break;

    case 407:
      return isParallel(*dynamic_cast<ray const *>(entity0_in),
                        *dynamic_cast<triangle const *>(entity1_in),
                        tolerance);
      break;

    case 408:
      return isParallel(*dynamic_cast<ray const *>(entity0_in),
                        *dynamic_cast<circle const *>(entity1_in),
                        tolerance);
      break;

      // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

    case 503:
      return isParallel(*dynamic_cast<line const *>(entity1_in),
                        *dynamic_cast<plane const *>(entity0_in),
                        tolerance);
      break;

    case 504:
      return isParallel(*dynamic_cast<ray const *>(entity1_in),
                        *dynamic_cast<plane const *>(entity0_in),
                        tolerance);
      break;

    case 505:
      return isParallel(*dynamic_cast<plane const *>(entity0_in),
                        *dynamic_cast<plane const *>(entity1_in),
                        tolerance);
      break;

    case 506:
      return isParallel(*dynamic_cast<plane const *>(entity0_in),
                        *dynamic_cast<segment const *>(entity1_in),
                        tolerance);
      break;

    case 507:
      return isParallel(*dynamic_cast<plane const *>(entity0_in),
                        *dynamic_cast<triangle const *>(entity1_in),
                        tolerance);
      break;

    case 508:
      return isParallel(*dynamic_cast<plane const *>(entity0_in),
                        *dynamic_cast<circle const *>(entity1_in),
                        tolerance);
      break;

      // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

    case 603:
      return isParallel(*dynamic_cast<line const *>(entity1_in),
                        *dynamic_cast<segment const *>(entity0_in),
                        tolerance);
      break;

    case 604:
      return isParallel(*dynamic_cast<ray const *>(entity1_in),
                        *dynamic_cast<segment const *>(entity0_in),
                        tolerance);
      break;

    case 605:
      return isParallel(*dynamic_cast<plane const *>(entity1_in),
                        *dynamic_cast<segment const *>(entity0_in),
                        tolerance);
      break;

    case 606:
      return isParallel(*dynamic_cast<segment const *>(entity0_in),
                        *dynamic_cast<segment const *>(entity1_in),
                        tolerance);
      break;

    case 607:
      return isParallel(*dynamic_cast<segment const *>(entity0_in),
                        *dynamic_cast<triangle const *>(entity1_in),
                        tolerance);
      break;

    case 608:
      return isParallel(*dynamic_cast<segment const *>(entity0_in),
                        *dynamic_cast<circle const *>(entity1_in),
                        tolerance);
      break;

      // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

    case 703:
      return isParallel(*dynamic_cast<line const *>(entity1_in),
                        *dynamic_cast<triangle const *>(entity0_in),
                        tolerance);
      break;

    case 704:
      return isParallel(*dynamic_cast<ray const *>(entity1_in),
                        *dynamic_cast<triangle const *>(entity0_in),
                        tolerance);
      break;

    case 705:
      return isParallel(*dynamic_cast<plane const *>(entity1_in),
                        *dynamic_cast<triangle const *>(entity0_in), tolerance);
      break;

    case 706:
      return isParallel(*dynamic_cast<segment const *>(entity1_in),
                        *dynamic_cast<triangle const *>(entity0_in),
                        tolerance);
      break;

    case 707:
      return isParallel(*dynamic_cast<triangle const *>(entity0_in),
                        *dynamic_cast<triangle const *>(entity1_in),
                        tolerance);
      break;

    case 708:
      return isParallel(*dynamic_cast<triangle const *>(entity0_in),
                        *dynamic_cast<circle const *>(entity1_in),
                        tolerance);
      break;

      // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

    case 803:
      return isParallel(*dynamic_cast<line const *>(entity1_in),
                        *dynamic_cast<circle const *>(entity0_in),
                        tolerance);
      break;

    case 804:
      return isParallel(*dynamic_cast<ray const *>(entity1_in),
                        *dynamic_cast<circle const *>(entity0_in),
                        tolerance);
      break;

    case 805:
      return isParallel(*dynamic_cast<plane const *>(entity1_in),
                        *dynamic_cast<circle const *>(entity0_in),
                        tolerance);
      break;

    case 806:
      return isParallel(*dynamic_cast<segment const *>(entity1_in),
                        *dynamic_cast<circle const *>(entity0_in),
                        tolerance);
      break;

    case 807:
      return isParallel(*dynamic_cast<triangle const *>(entity1_in),
                        *dynamic_cast<circle const *>(entity0_in),
                        tolerance);
      break;

    case 808:
      return isParallel(*dynamic_cast<circle const *>(entity0_in),
                        *dynamic_cast<circle const *>(entity1_in),
                        tolerance);
      break;

      // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

    default:
      // ACME_ERROR("acme::isParallel(entity, entity): exception not handled.\n")
      return false;
      break;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector0_in,
      vec3 const &vector1_in,
      real tolerance)
  {
    return isApprox(vector0_in.cross(vector1_in).norm(), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      line const &line_in,
      real tolerance)
  {
    return isParallel(vector, line_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      ray const &ray_in,
      real tolerance)
  {
    return isParallel(vector, ray_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      plane const &plane_in,
      real tolerance)
  {
    return isOrthogonal(vector, plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      segment const &segment_in,
      real tolerance)
  {
    return isParallel(vector, segment_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      triangle const &triangle_in,
      real tolerance)
  {
    return isOrthogonal(vector, triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      circle const &circle_in,
      real tolerance)
  {
    return isOrthogonal(vector, circle_in.normal(), tolerance);
  }

  bool
  isParallel(
      line const &line0,
      line const &line1,
      real tolerance)
  {
    return isParallel(line0.direction(), line1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray0,
      ray const &ray1,
      real tolerance)
  {
    return isParallel(ray0.direction(), ray1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane0,
      plane const &plane1,
      real tolerance)
  {
    return isParallel(plane0.normal(), plane1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      segment const &segment0,
      segment const &segment1,
      real tolerance)
  {
    return isParallel(segment0.toUnitVector(), segment1.toUnitVector(), tolerance);
  }
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      triangle const &triangle0,
      triangle const &triangle1,
      real tolerance)
  {
    return isParallel(triangle0.normal(), triangle1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      circle const &circle0,
      circle const &circle1,
      real tolerance)
  {
    return isParallel(circle0.normal(), circle1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line_in,
      ray const &ray_in,
      real tolerance)
  {
    return isParallel(line_in.direction(), ray_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line_in,
      plane const &plane_in,
      real tolerance)
  {
    return isOrthogonal(line_in.direction(), plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line_in,
      segment const &segment_in,
      real tolerance)
  {
    return isParallel(line_in.direction(), segment_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line_in,
      triangle const &triangle_in,
      real tolerance)
  {
    return isOrthogonal(line_in.direction(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line_in,
      circle const &circle_in,
      real tolerance)
  {
    return isOrthogonal(line_in.direction(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray_in,
      plane const &plane_in,
      real tolerance)
  {
    return isOrthogonal(ray_in.direction(), plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray_in,
      segment const &segment_in,
      real tolerance)
  {
    return isParallel(ray_in.direction(), segment_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray_in,
      triangle const &triangle_in,
      real tolerance)
  {
    return isOrthogonal(ray_in.direction(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray_in,
      circle const &circle_in,
      real tolerance)
  {
    return isOrthogonal(ray_in.direction(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane_in,
      segment const &segment_in,
      real tolerance)
  {
    return isOrthogonal(segment_in.toUnitVector(), plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane_in,
      triangle const &triangle_in,
      real tolerance)
  {
    return isParallel(plane_in.normal(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane_in,
      circle const &circle_in,
      real tolerance)
  {
    return isParallel(plane_in.normal(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      segment const &segment_in,
      triangle const &triangle_in,
      real tolerance)
  {
    return isOrthogonal(segment_in.toUnitVector(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      segment const &segment_in,
      circle const &circle_in,
      real tolerance)
  {
    return isOrthogonal(segment_in.toUnitVector(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      triangle const &triangle_in,
      circle const &circle_in,
      real tolerance)
  {
    return isParallel(triangle_in.normal(), circle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_parallel.cc
///