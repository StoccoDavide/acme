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
      entity const *entity0,
      entity const *entity1,
      real tolerance)
  {
    integer slide = entity0->degree() * 100 + entity1->degree();
    switch (slide)
    {

      // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

    case 303:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<line const *>(entity1),
                              tolerance);
      break;

    case 304:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<ray const *>(entity1),
                              tolerance);
      break;

    case 305:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<plane const *>(entity1),
                              tolerance);
      break;

    case 306:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<segment const *>(entity1),
                              tolerance);
      break;

    case 307:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 308:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

    case 403:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<ray const *>(entity0),
                              tolerance);
      break;

    case 404:
      return acme::isCoplanar(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<ray const *>(entity1),
                              tolerance);
      break;

    case 405:
      return acme::isCoplanar(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<plane const *>(entity1),
                              tolerance);
      break;

    case 406:
      return acme::isCoplanar(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<segment const *>(entity1),
                              tolerance);
      break;

    case 407:
      return acme::isCoplanar(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 408:
      return acme::isCoplanar(*dynamic_cast<ray const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

    case 503:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<plane const *>(entity0),
                              tolerance);
      break;

    case 504:
      return acme::isCoplanar(*dynamic_cast<ray const *>(entity1),
                              *dynamic_cast<plane const *>(entity0),
                              tolerance);
      break;

    case 505:
      return acme::isCoplanar(*dynamic_cast<plane const *>(entity0),
                              *dynamic_cast<plane const *>(entity1),
                              tolerance);
      break;

    case 506:
      return acme::isCoplanar(*dynamic_cast<plane const *>(entity0),
                              *dynamic_cast<segment const *>(entity1),
                              tolerance);
      break;

    case 507:
      return acme::isCoplanar(*dynamic_cast<plane const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 508:
      return acme::isCoplanar(*dynamic_cast<plane const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

    case 603:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<segment const *>(entity0),
                              tolerance);
      break;

    case 604:
      return acme::isCoplanar(*dynamic_cast<ray const *>(entity1),
                              *dynamic_cast<segment const *>(entity0),
                              tolerance);
      break;

    case 605:
      return acme::isCoplanar(*dynamic_cast<plane const *>(entity1),
                              *dynamic_cast<segment const *>(entity0),
                              tolerance);
      break;

    case 606:
      return acme::isCoplanar(*dynamic_cast<segment const *>(entity0),
                              *dynamic_cast<segment const *>(entity1),
                              tolerance);
      break;

    case 607:
      return acme::isCoplanar(*dynamic_cast<segment const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 608:
      return acme::isCoplanar(*dynamic_cast<segment const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

    case 703:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<triangle const *>(entity0),
                              tolerance);
      break;

    case 704:
      return acme::isCoplanar(*dynamic_cast<ray const *>(entity1),
                              *dynamic_cast<triangle const *>(entity0),
                              tolerance);
      break;

    case 705:
      return acme::isCoplanar(*dynamic_cast<plane const *>(entity1),
                              *dynamic_cast<triangle const *>(entity0), tolerance);
      break;

    case 706:
      return acme::isCoplanar(*dynamic_cast<segment const *>(entity1),
                              *dynamic_cast<triangle const *>(entity0),
                              tolerance);
      break;

    case 707:
      return acme::isCoplanar(*dynamic_cast<triangle const *>(entity0),
                              *dynamic_cast<triangle const *>(entity1),
                              tolerance);
      break;

    case 708:
      return acme::isCoplanar(*dynamic_cast<triangle const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

    case 803:
      return acme::isCoplanar(*dynamic_cast<line const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 804:
      return acme::isCoplanar(*dynamic_cast<ray const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 805:
      return acme::isCoplanar(*dynamic_cast<plane const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 806:
      return acme::isCoplanar(*dynamic_cast<segment const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 807:
      return acme::isCoplanar(*dynamic_cast<triangle const *>(entity1),
                              *dynamic_cast<circle const *>(entity0),
                              tolerance);
      break;

    case 808:
      return acme::isCoplanar(*dynamic_cast<circle const *>(entity0),
                              *dynamic_cast<circle const *>(entity1),
                              tolerance);
      break;

      // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

    default:
      //ACME_ERROR("acme::isCoplanar(entity, entity): exception not handled.")
      return false;
      break;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line0,
      line const &line1,
      real tolerance)
  {
    return (line0.origin() - line1.origin()).isOrthogonal(line0.direction().cross(line1.direction()), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      ray const &ray0,
      ray const &ray1,
      real tolerance)
  {
    return (ray0.origin() - ray1.origin()).isOrthogonal(ray0.direction().cross(ray1.direction()), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      plane const &plane0,
      plane const &plane1,
      real tolerance)
  {
    return acme::isParallel(plane0.normal(), plane1.normal(), tolerance) &&
           acme::isApprox(plane0.signedDistance(plane1.origin()), real(0.0), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      segment const &segment0,
      segment const &segment1,
      real tolerance)
  {
    return (segment0.vertex(0) - segment1.vertex(0)).isOrthogonal(segment0.toNormalizedVector().cross(segment1.toNormalizedVector()), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      triangle const &triangle0,
      triangle const &triangle1,
      real tolerance)
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
      real tolerance)
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
      real tolerance)
  {
    return (line.origin() - ray.origin()).isOrthogonal(line.direction().cross(ray.direction()), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line,
      plane const &plane,
      real tolerance)
  {
    return line.direction().isOrthogonal(plane.normal(), tolerance) &&
           plane.normal().isOrthogonal(line.origin() - plane.origin(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line,
      segment const &segment,
      real tolerance)
  {
    return (line.origin() - segment.vertex(0)).isOrthogonal(line.direction().cross(segment.toNormalizedVector()), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      line const &line,
      triangle const &triangle,
      real tolerance)
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
      real tolerance)
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
      real tolerance)
  {
    return ray.direction().isOrthogonal(plane.normal(), tolerance) &&
           plane.normal().isOrthogonal(ray.origin() - plane.origin(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      ray const &ray,
      segment const &segment,
      real tolerance)
  {
    return (ray.origin() - segment.vertex(0)).isOrthogonal(ray.direction().cross(segment.toNormalizedVector()), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      ray const &ray,
      triangle const &triangle,
      real tolerance)
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
      real tolerance)
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
      real tolerance)
  {
    return segment.toNormalizedVector().isOrthogonal(plane.normal(), tolerance) &&
           plane.normal().isOrthogonal(segment.vertex(0) - plane.origin(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      plane const &plane,
      triangle const &triangle,
      real tolerance)
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
      real tolerance)
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
      real tolerance)
  {
    return acme::isCoplanar(triangle.layingPlane(),
                            segment,
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      segment const &segment,
      circle const &circle,
      real tolerance)
  {
    return acme::isCoplanar(circle.layingPlane(),
                            segment,
                            tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCoplanar(
      triangle const &triangle,
      circle const &circle,
      real tolerance)
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