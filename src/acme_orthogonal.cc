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
      real_type tolerance)
  {
    int_type slide = entity0->type() * 100 + entity1->type();
    switch (slide)
    {

      // - - - - - - - - - - - - - - VECTOR - - - - - - - - - - - - - -

    case 202:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity0),
                                *dynamic_cast<vec3 const *>(entity1),
                                tolerance);
      break;

    case 203:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity0),
                                *dynamic_cast<line const *>(entity1),
                                tolerance);
      break;

    case 204:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity0),
                                *dynamic_cast<ray const *>(entity1),
                                tolerance);
      break;

    case 205:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity0),
                                *dynamic_cast<plane const *>(entity1),
                                tolerance);
      break;

    case 206:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity0),
                                *dynamic_cast<segment const *>(entity1),
                                tolerance);
      break;

    case 207:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity0),
                                *dynamic_cast<triangle const *>(entity1),
                                tolerance);
      break;

    case 208:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity0),
                                *dynamic_cast<circle const>(entity1),
                                tolerance);
      break;

      // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

    case 302:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity1),
                                *dynamic_cast<line const *>(entity0),
                                tolerance);
      break;

    case 303:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity0),
                                *dynamic_cast<line const *>(entity1),
                                tolerance);
      break;

    case 304:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity0),
                                *dynamic_cast<ray const *>(entity1),
                                tolerance);
      break;

    case 305:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity0),
                                *dynamic_cast<plane const *>(entity1),
                                tolerance);
      break;

    case 306:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity0),
                                *dynamic_cast<segment const *>(entity1),
                                tolerance);
      break;

    case 307:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity0),
                                *dynamic_cast<triangle const *>(entity1),
                                tolerance);
      break;

    case 308:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity0),
                                *dynamic_cast<circle const>(entity1),
                                tolerance);
      break;

      // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

    case 402:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity0),
                                *dynamic_cast<line const *>(entity1),
                                tolerance);
      break;

    case 403:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity1),
                                *dynamic_cast<ray const *>(entity0),
                                tolerance);
      break;

    case 404:
      return acme::isOrthogonal(*dynamic_cast<ray const *>(entity0),
                                *dynamic_cast<ray const *>(entity1),
                                tolerance);
      break;

    case 405:
      return acme::isOrthogonal(*dynamic_cast<ray const *>(entity0),
                                *dynamic_cast<plane const *>(entity1),
                                tolerance);
      break;

    case 406:
      return acme::isOrthogonal(*dynamic_cast<ray const *>(entity0),
                                *dynamic_cast<segment const *>(entity1),
                                tolerance);
      break;

    case 407:
      return acme::isOrthogonal(*dynamic_cast<ray const *>(entity0),
                                *dynamic_cast<triangle const *>(entity1),
                                tolerance);
      break;

    case 408:
      return acme::isOrthogonal(*dynamic_cast<ray const *>(entity0),
                                *dynamic_cast<circle const>(entity1),
                                tolerance);
      break;

      // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

    case 502:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity0),
                                *dynamic_cast<line const *>(entity1),
                                tolerance);
      break;

    case 503:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity1),
                                *dynamic_cast<plane const *>(entity0),
                                tolerance);
      break;

    case 504:
      return acme::isOrthogonal(*dynamic_cast<ray const *>(entity1),
                                *dynamic_cast<plane const *>(entity0),
                                tolerance);
      break;

    case 505:
      return acme::isOrthogonal(*dynamic_cast<plane const *>(entity0),
                                *dynamic_cast<plane const *>(entity1),
                                tolerance);
      break;

    case 506:
      return acme::isOrthogonal(*dynamic_cast<plane const *>(entity0),
                                *dynamic_cast<segment const *>(entity1),
                                tolerance);
      break;

    case 507:
      return acme::isOrthogonal(*dynamic_cast<plane const *>(entity0),
                                *dynamic_cast<triangle const *>(entity1),
                                tolerance);
      break;

    case 508:
      return acme::isOrthogonal(*dynamic_cast<plane const *>(entity0),
                                *dynamic_cast<circle const>(entity1),
                                tolerance);
      break;

      // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

    case 602:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity1),
                                *dynamic_cast<segment const *>(entity0),
                                tolerance);
      break;

    case 603:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity1),
                                *dynamic_cast<segment const *>(entity0),
                                tolerance);
      break;

    case 604:
      return acme::isOrthogonal(*dynamic_cast<ray const *>(entity1),
                                *dynamic_cast<segment const *>(entity0),
                                tolerance);
      break;

    case 605:
      return acme::isOrthogonal(*dynamic_cast<plane const *>(entity1),
                                *dynamic_cast<segment const *>(entity0),
                                tolerance);
      break;

    case 606:
      return acme::isOrthogonal(*dynamic_cast<segment const *>(entity0),
                                *dynamic_cast<segment const *>(entity1),
                                tolerance);
      break;

    case 607:
      return acme::isOrthogonal(*dynamic_cast<segment const *>(entity0),
                                *dynamic_cast<triangle const *>(entity1),
                                tolerance);
      break;

    case 608:
      return acme::isOrthogonal(*dynamic_cast<segment const *>(entity0),
                                *dynamic_cast<circle const>(entity1),
                                tolerance);
      break;

      // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

    case 702:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity1),
                                *dynamic_cast<triangle const *>(entity0),
                                tolerance);
      break;

    case 703:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity1),
                                *dynamic_cast<triangle const *>(entity0),
                                tolerance);
      break;

    case 704:
      return acme::isOrthogonal(*dynamic_cast<ray const *>(entity1),
                                *dynamic_cast<triangle const *>(entity0),
                                tolerance);
      break;

    case 705:
      return acme::isOrthogonal(*dynamic_cast<plane const *>(entity1),
                                *dynamic_cast<triangle const *>(entity0), tolerance);
      break;

    case 706:
      return acme::isOrthogonal(*dynamic_cast<segment const *>(entity1),
                                *dynamic_cast<triangle const *>(entity0),
                                tolerance);
      break;

    case 707:
      return acme::isOrthogonal(*dynamic_cast<triangle const *>(entity0),
                                *dynamic_cast<triangle const *>(entity1),
                                tolerance);
      break;

    case 708:
      return acme::isOrthogonal(*dynamic_cast<triangle const *>(entity0),
                                *dynamic_cast<circle const>(entity1),
                                tolerance);
      break;

    // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -
    case 802:
      return acme::isOrthogonal(*dynamic_cast<vec3 const *>(entity1),
                                *dynamic_cast<circle const>(entity0),
                                tolerance);
      break;

    case 803:
      return acme::isOrthogonal(*dynamic_cast<line const *>(entity1),
                                *dynamic_cast<circle const>(entity0),
                                tolerance);
      break;

    case 804:
      return acme::isOrthogonal(*dynamic_cast<ray const *>(entity1),
                                *dynamic_cast<circle const>(entity0),
                                tolerance);
      break;

    case 805:
      return acme::isOrthogonal(*dynamic_cast<plane const *>(entity1),
                                *dynamic_cast<circle const>(entity0),
                                tolerance);
      break;

    case 806:
      return acme::isOrthogonal(*dynamic_cast<segment const *>(entity1),
                                *dynamic_cast<circle const>(entity0),
                                tolerance);
      break;

    case 807:
      return acme::isOrthogonal(*dynamic_cast<triangle const *>(entity1),
                                *dynamic_cast<circle const>(entity0),
                                tolerance);
      break;

    case 808:
      return acme::isOrthogonal(*dynamic_cast<circle const>(entity0),
                                *dynamic_cast<circle const>(entity1),
                                tolerance);
      break;

      // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

    default:
      //ACME_ERROR("acme::isOrthogonal(entity, entity): exception not handled.")
      return false;
      break;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector0,
      vec3 const &vector1,
      real_type tolerance)
  {
    return vector0.isOrthogonal(vector1, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector,
      line const &line,
      real_type tolerance)
  {
    return vector.isOrthogonal(line.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector,
      ray const &ray,
      real_type tolerance)
  {
    return vector.isOrthogonal(ray.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector,
      plane const &plane,
      real_type tolerance)
  {
    return vector.isParallel(plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector,
      segment const &segment,
      real_type tolerance)
  {
    return vector.isOrthogonal(segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector,
      triangle const &triangle,
      real_type tolerance)
  {
    return vector.isParallel(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      vec3 const &vector,
      circle const &circle,
      real_type tolerance)
  {
    return vector.isParallel(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line0,
      line const &line1,
      real_type tolerance)
  {
    return line0.direction().isOrthogonal(line1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray0,
      ray const &ray1,
      real_type tolerance)
  {
    return ray0.direction().isOrthogonal(ray1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane0,
      plane const &plane1,
      real_type tolerance)
  {
    return plane0.normal().isOrthogonal(plane1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      segment const &segment0,
      segment const &segment1,
      real_type tolerance)
  {
    return segment0.toNormalizedVector().isOrthogonal(segment1.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      triangle const &triangle0,
      triangle const &triangle1,
      real_type tolerance)
  {
    return triangle0.normal().isOrthogonal(triangle1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      circle const &circle0,
      circle const &circle1,
      real_type tolerance)
  {
    return circle0.normal().isOrthogonal(circle1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      ray const &ray,
      real_type tolerance)
  {
    return line.direction().isOrthogonal(ray.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      plane const &plane,
      real_type tolerance)
  {
    return line.direction().isOrthogonal(plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      segment const &segment,
      real_type tolerance)
  {
    return line.direction().isOrthogonal(segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      triangle const &triangle,
      real_type tolerance)
  {
    return line.direction().isParallel(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      line const &line,
      circle const &circle,
      real_type tolerance)
  {
    return line.direction().isParallel(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray,
      plane const &plane,
      real_type tolerance)
  {
    return ray.direction().isParallel(plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray,
      segment const &segment,
      real_type tolerance)
  {
    return ray.direction().isOrthogonal(segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray,
      triangle const &triangle,
      real_type tolerance)
  {
    return ray.direction().isParallel(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      ray const &ray,
      circle const &circle,
      real_type tolerance)
  {
    return ray.direction().isParallel(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane,
      segment const &segment,
      real_type tolerance)
  {
    return segment.toNormalizedVector().isParallel(plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane,
      triangle const &triangle,
      real_type tolerance)
  {
    return plane.normal().isOrthogonal(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      plane const &plane,
      circle const &circle,
      real_type tolerance)
  {
    return plane.normal().isOrthogonal(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      segment const &segment,
      triangle const &triangle,
      real_type tolerance)
  {
    return segment.toNormalizedVector().isParallel(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      segment const &segment,
      circle const &circle,
      real_type tolerance)
  {
    return segment.toNormalizedVector().isParallel(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthogonal(
      triangle const &triangle,
      circle const &circle,
      real_type tolerance)
  {
    return triangle.normal().isOrthogonal(circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_orthogonal.cc
///