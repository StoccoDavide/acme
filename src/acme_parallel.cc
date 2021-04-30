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
      entity::ptr const &entity0,
      entity::ptr const &entity1,
      real_type tolerance)
  {
    int_type slide = entity0->type() * 100 + entity1->type();
    switch (slide)
    {

      // - - - - - - - - - - - - - - VECTOR - - - - - - - - - - - - - -

    case 202:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity0),
                              *std::dynamic_pointer_cast<vec3 const>(entity1),
                              tolerance);
      break;

    case 203:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity0),
                              *std::dynamic_pointer_cast<line const>(entity1),
                              tolerance);
      break;

    case 204:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity0),
                              *std::dynamic_pointer_cast<ray const>(entity1),
                              tolerance);
      break;

    case 205:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity0),
                              *std::dynamic_pointer_cast<plane const>(entity1),
                              tolerance);
      break;

    case 206:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity0),
                              *std::dynamic_pointer_cast<segment const>(entity1),
                              tolerance);
      break;

    case 207:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity0),
                              *std::dynamic_pointer_cast<triangle const>(entity1),
                              tolerance);
      break;

    case 208:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity0),
                              *std::dynamic_pointer_cast<circle const>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

    case 302:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity1),
                              *std::dynamic_pointer_cast<line const>(entity0),
                              tolerance);
      break;

    case 303:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity0),
                              *std::dynamic_pointer_cast<line const>(entity1),
                              tolerance);
      break;

    case 304:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity0),
                              *std::dynamic_pointer_cast<ray const>(entity1),
                              tolerance);
      break;

    case 305:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity0),
                              *std::dynamic_pointer_cast<plane const>(entity1),
                              tolerance);
      break;

    case 306:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity0),
                              *std::dynamic_pointer_cast<segment const>(entity1),
                              tolerance);
      break;

    case 307:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity0),
                              *std::dynamic_pointer_cast<triangle const>(entity1),
                              tolerance);
      break;

    case 308:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity0),
                              *std::dynamic_pointer_cast<circle const>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

    case 402:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity0),
                              *std::dynamic_pointer_cast<line const>(entity1),
                              tolerance);
      break;

    case 403:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity1),
                              *std::dynamic_pointer_cast<ray const>(entity0),
                              tolerance);
      break;

    case 404:
      return acme::isParallel(*std::dynamic_pointer_cast<ray const>(entity0),
                              *std::dynamic_pointer_cast<ray const>(entity1),
                              tolerance);
      break;

    case 405:
      return acme::isParallel(*std::dynamic_pointer_cast<ray const>(entity0),
                              *std::dynamic_pointer_cast<plane const>(entity1),
                              tolerance);
      break;

    case 406:
      return acme::isParallel(*std::dynamic_pointer_cast<ray const>(entity0),
                              *std::dynamic_pointer_cast<segment const>(entity1),
                              tolerance);
      break;

    case 407:
      return acme::isParallel(*std::dynamic_pointer_cast<ray const>(entity0),
                              *std::dynamic_pointer_cast<triangle const>(entity1),
                              tolerance);
      break;

    case 408:
      return acme::isParallel(*std::dynamic_pointer_cast<ray const>(entity0),
                              *std::dynamic_pointer_cast<circle const>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

    case 502:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity0),
                              *std::dynamic_pointer_cast<line const>(entity1),
                              tolerance);
      break;

    case 503:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity1),
                              *std::dynamic_pointer_cast<plane const>(entity0),
                              tolerance);
      break;

    case 504:
      return acme::isParallel(*std::dynamic_pointer_cast<ray const>(entity1),
                              *std::dynamic_pointer_cast<plane const>(entity0),
                              tolerance);
      break;

    case 505:
      return acme::isParallel(*std::dynamic_pointer_cast<plane const>(entity0),
                              *std::dynamic_pointer_cast<plane const>(entity1),
                              tolerance);
      break;

    case 506:
      return acme::isParallel(*std::dynamic_pointer_cast<plane const>(entity0),
                              *std::dynamic_pointer_cast<segment const>(entity1),
                              tolerance);
      break;

    case 507:
      return acme::isParallel(*std::dynamic_pointer_cast<plane const>(entity0),
                              *std::dynamic_pointer_cast<triangle const>(entity1),
                              tolerance);
      break;

    case 508:
      return acme::isParallel(*std::dynamic_pointer_cast<plane const>(entity0),
                              *std::dynamic_pointer_cast<circle const>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

    case 602:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity1),
                              *std::dynamic_pointer_cast<segment const>(entity0),
                              tolerance);
      break;

    case 603:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity1),
                              *std::dynamic_pointer_cast<segment const>(entity0),
                              tolerance);
      break;

    case 604:
      return acme::isParallel(*std::dynamic_pointer_cast<ray const>(entity1),
                              *std::dynamic_pointer_cast<segment const>(entity0),
                              tolerance);
      break;

    case 605:
      return acme::isParallel(*std::dynamic_pointer_cast<plane const>(entity1),
                              *std::dynamic_pointer_cast<segment const>(entity0),
                              tolerance);
      break;

    case 606:
      return acme::isParallel(*std::dynamic_pointer_cast<segment const>(entity0),
                              *std::dynamic_pointer_cast<segment const>(entity1),
                              tolerance);
      break;

    case 607:
      return acme::isParallel(*std::dynamic_pointer_cast<segment const>(entity0),
                              *std::dynamic_pointer_cast<triangle const>(entity1),
                              tolerance);
      break;

    case 608:
      return acme::isParallel(*std::dynamic_pointer_cast<segment const>(entity0),
                              *std::dynamic_pointer_cast<circle const>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

    case 702:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity1),
                              *std::dynamic_pointer_cast<triangle const>(entity0),
                              tolerance);
      break;

    case 703:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity1),
                              *std::dynamic_pointer_cast<triangle const>(entity0),
                              tolerance);
      break;

    case 704:
      return acme::isParallel(*std::dynamic_pointer_cast<ray const>(entity1),
                              *std::dynamic_pointer_cast<triangle const>(entity0),
                              tolerance);
      break;

    case 705:
      return acme::isParallel(*std::dynamic_pointer_cast<plane const>(entity1),
                              *std::dynamic_pointer_cast<triangle const>(entity0), tolerance);
      break;

    case 706:
      return acme::isParallel(*std::dynamic_pointer_cast<segment const>(entity1),
                              *std::dynamic_pointer_cast<triangle const>(entity0),
                              tolerance);
      break;

    case 707:
      return acme::isParallel(*std::dynamic_pointer_cast<triangle const>(entity0),
                              *std::dynamic_pointer_cast<triangle const>(entity1),
                              tolerance);
      break;

    case 708:
      return acme::isParallel(*std::dynamic_pointer_cast<triangle const>(entity0),
                              *std::dynamic_pointer_cast<circle const>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

    case 802:
      return acme::isParallel(*std::dynamic_pointer_cast<vec3 const>(entity1),
                              *std::dynamic_pointer_cast<circle const>(entity0),
                              tolerance);
      break;

    case 803:
      return acme::isParallel(*std::dynamic_pointer_cast<line const>(entity1),
                              *std::dynamic_pointer_cast<circle const>(entity0),
                              tolerance);
      break;

    case 804:
      return acme::isParallel(*std::dynamic_pointer_cast<ray const>(entity1),
                              *std::dynamic_pointer_cast<circle const>(entity0),
                              tolerance);
      break;

    case 805:
      return acme::isParallel(*std::dynamic_pointer_cast<plane const>(entity1),
                              *std::dynamic_pointer_cast<circle const>(entity0),
                              tolerance);
      break;

    case 806:
      return acme::isParallel(*std::dynamic_pointer_cast<segment const>(entity1),
                              *std::dynamic_pointer_cast<circle const>(entity0),
                              tolerance);
      break;

    case 807:
      return acme::isParallel(*std::dynamic_pointer_cast<triangle const>(entity1),
                              *std::dynamic_pointer_cast<circle const>(entity0),
                              tolerance);
      break;

    case 808:
      return acme::isParallel(*std::dynamic_pointer_cast<circle const>(entity0),
                              *std::dynamic_pointer_cast<circle const>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

    default:
      //ACME_ERROR("acme::isParallel(entity, entity): exception not handled.")
      return false;
      break;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector0,
      vec3 const &vector1,
      real_type tolerance)
  {
    return vector0.isParallel(vector1, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      line const &line,
      real_type tolerance)
  {
    return vector.isParallel(line.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      ray const &ray,
      real_type tolerance)
  {
    return vector.isParallel(ray.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      plane const &plane,
      real_type tolerance)
  {
    return vector.isOrthogonal(plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      segment const &segment,
      real_type tolerance)
  {
    return vector.isParallel(segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      triangle const &triangle,
      real_type tolerance)
  {
    return vector.isOrthogonal(triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &vector,
      circle const &circle,
      real_type tolerance)
  {
    return vector.isOrthogonal(circle.normal(), tolerance);
  }

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