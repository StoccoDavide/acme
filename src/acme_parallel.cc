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
      entity const *entity0,
      entity const *entity1,
      real tolerance)
  {
    integer slide = entity0->degree() * 100 + entity1->degree();
    switch (slide)
    {

      // - - - - - - - - - - - - - - VECTOR - - - - - - - - - - - - - -

    case 202:
      return acme::isParallel(*dynamic_cast<vector const *>(entity0),
                              *dynamic_cast<vector const *>(entity1),
                              tolerance);
      break;

    case 203:
      return acme::isParallel(*dynamic_cast<vector const *>(entity0),
                              *dynamic_cast<line const *>(entity1),
                              tolerance);
      break;

    case 204:
      return acme::isParallel(*dynamic_cast<vector const *>(entity0),
                              *dynamic_cast<ray const *>(entity1),
                              tolerance);
      break;

    case 205:
      return acme::isParallel(*dynamic_cast<vector const *>(entity0),
                              *dynamic_cast<plane const *>(entity1),
                              tolerance);
      break;

    case 206:
      return acme::isParallel(*dynamic_cast<vector const *>(entity0),
                              *dynamic_cast<segment const *>(entity1),
                              tolerance);
      break;

    case 207:
      return acme::isParallel(*dynamic_cast<vector const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 208:
      return acme::isParallel(*dynamic_cast<vector const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

    case 302:
      return acme::isParallel(*dynamic_cast<vector const *>(entity1),
                              *dynamic_cast<line const *>(entity0),
                              tolerance);
      break;

    case 303:
      return acme::isParallel(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<line const *>(entity1),
                              tolerance);
      break;

    case 304:
      return acme::isParallel(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<ray const *>(entity1),
                              tolerance);
      break;

    case 305:
      return acme::isParallel(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<plane const *>(entity1),
                              tolerance);
      break;

    case 306:
      return acme::isParallel(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<segment const *>(entity1),
                              tolerance);
      break;

    case 307:
      return acme::isParallel(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 308:
      return acme::isParallel(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

    case 402:
      return acme::isParallel(*dynamic_cast<vector const *>(entity0),
                              *dynamic_cast<line const *>(entity1),
                              tolerance);
      break;

    case 403:
      return acme::isParallel(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<ray const *>(entity0),
                              tolerance);
      break;

    case 404:
      return acme::isParallel(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<ray const *>(entity1),
                              tolerance);
      break;

    case 405:
      return acme::isParallel(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<plane const *>(entity1),
                              tolerance);
      break;

    case 406:
      return acme::isParallel(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<segment const *>(entity1),
                              tolerance);
      break;

    case 407:
      return acme::isParallel(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 408:
      return acme::isParallel(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

    case 502:
      return acme::isParallel(*dynamic_cast<vector const *>(entity0),
                              *dynamic_cast<line const *>(entity1),
                              tolerance);
      break;

    case 503:
      return acme::isParallel(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<plane const *>(entity0),
                              tolerance);
      break;

    case 504:
      return acme::isParallel(*dynamic_cast<ray const *>(entity1),
                              *dynamic_cast<plane const *>(entity0),
                              tolerance);
      break;

    case 505:
      return acme::isParallel(*dynamic_cast<plane const *>(entity0),
                              *dynamic_cast<plane const *>(entity1),
                              tolerance);
      break;

    case 506:
      return acme::isParallel(*dynamic_cast<plane const *>(entity0),
                              *dynamic_cast<segment const *>(entity1),
                              tolerance);
      break;

    case 507:
      return acme::isParallel(*dynamic_cast<plane const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 508:
      return acme::isParallel(*dynamic_cast<plane const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

    case 602:
      return acme::isParallel(*dynamic_cast<vector const *>(entity1),
                              *dynamic_cast<segment const *>(entity0),
                              tolerance);
      break;

    case 603:
      return acme::isParallel(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<segment const *>(entity0),
                              tolerance);
      break;

    case 604:
      return acme::isParallel(*dynamic_cast<ray const *>(entity1),
                              *dynamic_cast<segment const *>(entity0),
                              tolerance);
      break;

    case 605:
      return acme::isParallel(*dynamic_cast<plane const *>(entity1),
                              *dynamic_cast<segment const *>(entity0),
                              tolerance);
      break;

    case 606:
      return acme::isParallel(*dynamic_cast<segment const *>(entity0),
                              *dynamic_cast<segment const *>(entity1),
                              tolerance);
      break;

    case 607:
      return acme::isParallel(*dynamic_cast<segment const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 608:
      return acme::isParallel(*dynamic_cast<segment const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

    case 702:
      return acme::isParallel(*dynamic_cast<vector const *>(entity1),
                              *dynamic_cast<triangle const *>(entity0),
                              tolerance);
      break;

    case 703:
      return acme::isParallel(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<triangle const *>(entity0),
                              tolerance);
      break;

    case 704:
      return acme::isParallel(*dynamic_cast<ray const *>(entity1),
                              *dynamic_cast<triangle const *>(entity0),
                              tolerance);
      break;

    case 705:
      return acme::isParallel(*dynamic_cast<plane const *>(entity1),
                              *dynamic_cast<triangle const *>(entity0), tolerance);
      break;

    case 706:
      return acme::isParallel(*dynamic_cast<segment const *>(entity1),
                              *dynamic_cast<triangle const *>(entity0),
                              tolerance);
      break;

    case 707:
      return acme::isParallel(*dynamic_cast<triangle const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 708:
      return acme::isParallel(*dynamic_cast<triangle const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

    case 802:
      return acme::isParallel(*dynamic_cast<vector const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 803:
      return acme::isParallel(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 804:
      return acme::isParallel(*dynamic_cast<ray const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 805:
      return acme::isParallel(*dynamic_cast<plane const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 806:
      return acme::isParallel(*dynamic_cast<segment const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 807:
      return acme::isParallel(*dynamic_cast<triangle const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 808:
      return acme::isParallel(*dynamic_cast<circle const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
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
      vector const &vector0,
      vector const &vector1,
      real tolerance)
  {
    return acme::isApprox((vector0.cross(vector1)).dot(vector0), real(0.0), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vector const &vector,
      line const &line,
      real tolerance)
  {
    return acme::isParallel(vector, line.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vector const &vector,
      ray const &ray,
      real tolerance)
  {
    return acme::isParallel(vector, ray.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vector const &vector,
      plane const &plane,
      real tolerance)
  {
    return acme::isOrthogonal(vector, plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vector const &vector,
      segment const &segment,
      real tolerance)
  {
    return acme::isParallel(vector, segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vector const &vector,
      triangle const &triangle,
      real tolerance)
  {
    return acme::isOrthogonal(vector, triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vector const &vector,
      circle const &circle,
      real tolerance)
  {
    return acme::isOrthogonal(vector, circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line0,
      line const &line1,
      real tolerance)
  {
    return acme::isParallel(line0.direction(), line1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray0,
      ray const &ray1,
      real tolerance)
  {
    return acme::isParallel(ray0.direction(), ray1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane0,
      plane const &plane1,
      real tolerance)
  {
    return acme::isParallel(plane0.normal(), plane1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      segment const &segment0,
      segment const &segment1,
      real tolerance)
  {
    return acme::isParallel(segment0.toNormalizedVector(), segment1.toNormalizedVector(), tolerance);
  }
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      triangle const &triangle0,
      triangle const &triangle1,
      real tolerance)
  {
    return acme::isParallel(triangle0.normal(), triangle1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      circle const &circle0,
      circle const &circle1,
      real tolerance)
  {
    return acme::isParallel(circle0.normal(), circle1.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      ray const &ray,
      real tolerance)
  {
    return acme::isParallel(line.direction(), ray.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      plane const &plane,
      real tolerance)
  {
    return acme::isOrthogonal(line.direction(), plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      segment const &segment,
      real tolerance)
  {
    return acme::isParallel(line.direction(), segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      triangle const &triangle,
      real tolerance)
  {
    return acme::isOrthogonal(line.direction(), triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      line const &line,
      circle const &circle,
      real tolerance)
  {
    return acme::isOrthogonal(line.direction(), circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray,
      plane const &plane,
      real tolerance)
  {
    return acme::isOrthogonal(ray.direction(), plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray,
      segment const &segment,
      real tolerance)
  {
    return acme::isParallel(ray.direction(), segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray,
      triangle const &triangle,
      real tolerance)
  {
    return acme::isOrthogonal(ray.direction(), triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      ray const &ray,
      circle const &circle,
      real tolerance)
  {
    return acme::isOrthogonal(ray.direction(), circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane,
      segment const &segment,
      real tolerance)
  {
    return acme::isOrthogonal(segment.toNormalizedVector(), plane.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane,
      triangle const &triangle,
      real tolerance)
  {
    return acme::isParallel(plane.normal(), triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      plane const &plane,
      circle const &circle,
      real tolerance)
  {
    return acme::isParallel(plane.normal(), circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      segment const &segment,
      triangle const &triangle,
      real tolerance)
  {
    return acme::isOrthogonal(segment.toNormalizedVector(), triangle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      segment const &segment,
      circle const &circle,
      real tolerance)
  {
    return acme::isOrthogonal(segment.toNormalizedVector(), circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      triangle const &triangle,
      circle const &circle,
      real tolerance)
  {
    return acme::isParallel(triangle.normal(), circle.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_parallel.cc
///