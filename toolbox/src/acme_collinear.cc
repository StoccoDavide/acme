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
(***********************************************************************)
*/

///
/// file: acme_collinear.cc
///

#include "acme_collinear.hh"

namespace acme
{

  /*\
   |    ____      _ _ _                       
   |   / ___|___ | | (_)_ __   ___  __ _ _ __ 
   |  | |   / _ \| | | | '_ \ / _ \/ _` | '__|
   |  | |__| (_) | | | | | | |  __/ (_| | |   
   |   \____\___/|_|_|_|_| |_|\___|\__,_|_|   
   |                                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      entity const *entity0,
      entity const *entity1,
      real tolerance)
  {
    integer slide = entity0->degree() * 100 + entity1->degree();
    switch (slide)
    {

      // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

    case 303:
      return acme::isCollinear(*dynamic_cast<line const *>(entity0),
                               *dynamic_cast<line const *>(entity1),
                               tolerance);
      break;

    case 304:
      return acme::isCollinear(*dynamic_cast<line const *>(entity0),
                               *dynamic_cast<ray const *>(entity1),
                               tolerance);
      break;

    case 306:
      return acme::isCollinear(*dynamic_cast<line const *>(entity0),
                               *dynamic_cast<segment const *>(entity1),
                               tolerance);
      break;

      // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

    case 403:
      return acme::isCollinear(*dynamic_cast<line const *>(entity1),
                               *dynamic_cast<ray const *>(entity0),
                               tolerance);
      break;

    case 404:
      return acme::isCollinear(*dynamic_cast<ray const *>(entity0),
                               *dynamic_cast<ray const *>(entity1),
                               tolerance);
      break;

    case 406:
      return acme::isCollinear(*dynamic_cast<ray const *>(entity0),
                               *dynamic_cast<segment const *>(entity1),
                               tolerance);
      break;

      // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

    case 603:
      return acme::isCollinear(*dynamic_cast<line const *>(entity1),
                               *dynamic_cast<segment const *>(entity0),
                               tolerance);
      break;

    case 604:
      return acme::isCollinear(*dynamic_cast<ray const *>(entity1),
                               *dynamic_cast<segment const *>(entity0),
                               tolerance);
      break;

    case 606:
      return acme::isCollinear(*dynamic_cast<segment const *>(entity0),
                               *dynamic_cast<segment const *>(entity1),
                               tolerance);
      break;

      // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

    default:
      //ACME_ERROR("acme::isCollinear(entity, entity): exception not handled.")
      return false;
      break;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      line const &line0,
      line const &line1,
      real tolerance)
  {
    return acme::isParallel(line0.direction(), line0.origin() - line1.origin(), tolerance) &&
           acme::isParallel(line0.direction(), line1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      ray const &ray0,
      ray const &ray1,
      real tolerance)
  {
    return acme::isParallel(ray0.direction(), ray0.origin() - ray1.origin(), tolerance) &&
           acme::isParallel(ray1.direction(), ray1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      segment const &segment0,
      segment const &segment1,
      real tolerance)
  {
    return acme::isParallel(segment0.toNormalizedVector(), segment0.vertex(0) - segment1.vertex(0), tolerance) &&
           acme::isParallel(segment0.toNormalizedVector(), segment1.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      line const &line,
      ray const &ray,
      real tolerance)
  {
    return acme::isParallel(line.direction(), line.origin() - ray.origin(), tolerance) &&
           acme::isParallel(line.direction(), ray.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      line const &line,
      segment const &segment,
      real tolerance)
  {
    return acme::isParallel(line.direction(), line.origin() - segment.vertex(0), tolerance) &&
           acme::isParallel(line.direction(), segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      ray const &ray,
      segment const &segment,
      real tolerance)
  {
    return acme::isParallel(ray.direction(), ray.origin() - segment.vertex(0), tolerance) &&
           acme::isParallel(ray.direction(), segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_collinear.cc
///