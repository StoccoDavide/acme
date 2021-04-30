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
/// file: acme_intersection.cc
///

#include "acme_intersection.hh"

namespace acme
{

  /*\
   |   ___       _                          _   _             
   |  |_ _|_ __ | |_ ___ _ __ ___  ___  ___| |_(_) ___  _ __  
   |   | || '_ \| __/ _ \ '__/ __|/ _ \/ __| __| |/ _ \| '_ \ 
   |   | || | | | ||  __/ |  \__ \  __/ (__| |_| | (_) | | | |
   |  |___|_| |_|\__\___|_|  |___/\___|\___|\__|_|\___/|_| |_|
   |                                                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  intersect(
      entity::ptr const &entity0,
      entity::ptr const &entity1,
      entity::ptr const &entity_out)
  {
    int_type slide = entity0->type() * 100 + entity1->type();
    if (
        acme::isCollinear(entity0, entity1))
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

      case 303:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<line>(entity_out));
        break;

      case 304:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<ray>(entity_out));
        break;

      case 306:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

      case 403:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<ray>(entity_out));
        break;

      case 404:
        if (
            acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                               *std::dynamic_pointer_cast<ray const>(entity1),
                               *std::dynamic_pointer_cast<ray>(entity_out)))
          return true;
        else if (acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                    *std::dynamic_pointer_cast<ray const>(entity1),
                                    *std::dynamic_pointer_cast<segment>(entity_out)))
          return true;
        else
          return false;
        break;

      case 406:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

      case 603:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 604:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 606:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

      default:
        ACME_ERROR("acme::intersection(entity, entity): exception not handled.")
        return false;
        break;
      }
    }
    else if (acme::isCoplanar(entity0, entity1))
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

      case 303:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 304:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 305:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<line>(entity_out));
        break;

      case 306:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 307:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 308:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

      case 403:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 404:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 405:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<ray>(entity_out));
        break;

      case 406:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 407:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 408:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

      case 503:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<line>(entity_out));
        break;

      case 504:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<ray>(entity_out));
        break;

      case 505:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<plane>(entity_out));
        break;

      case 506:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 507:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<triangle>(entity_out));
        break;

      case 508:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<circle>(entity_out));
        break;

        // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

      case 603:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 604:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 605:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 606:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 607:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 608:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

      case 703:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 704:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 705:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 706:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // case 707:
        //   return acme::intersection(*std::dynamic_pointer_cast<triangle const>(entity0),
        //                             *std::dynamic_pointer_cast<triangle const>(entity1),
        //                             *std::dynamic_pointer_cast<???????? *>(entity_out));
        //   break;

        // case 708:
        //   return acme::intersection(*std::dynamic_pointer_cast<triangle const>(entity0),
        //                             *std::dynamic_pointer_cast<circle const>(entity1),
        //                             *std::dynamic_pointer_cast<???????? *>(entity_out));
        //   break;

        // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

      case 803:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 804:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 805:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<circle>(entity_out));
        break;

      case 806:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // case 807:
        //   return acme::intersection(*std::dynamic_pointer_cast<triangle const>(entity1),
        //                             *std::dynamic_pointer_cast<circle const>(entity0),
        //                             *std::dynamic_pointer_cast<???????? *>(entity_out));
        //   break;

        // case 808:
        //   return acme::intersection(*std::dynamic_pointer_cast<circle const>(entity0),
        //                             *std::dynamic_pointer_cast<circle const>(entity1),
        //                             *std::dynamic_pointer_cast<<???????? *>(entity_out));
        //   break;

        // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

      default:
        ACME_ERROR("acme::intersection(entity, entity): exception not handled.")
        return false;
        break;
      }
    }
    else
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

      case 303:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 304:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 305:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 306:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 307:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 308:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

        // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

      case 403:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 404:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 405:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 406:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 407:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 408:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

        // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

      case 503:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 504:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 505:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<line>(entity_out));
        break;

      case 506:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 507:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 508:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

      case 603:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 604:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 605:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 606:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 607:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 608:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

        // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

      case 703:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 704:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 705:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 706:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 707:
        return acme::intersection(*std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 708:
        return acme::intersection(*std::dynamic_pointer_cast<triangle const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

      case 803:
        return acme::intersection(*std::dynamic_pointer_cast<line const>(entity1),
                                  *std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 804:
        return acme::intersection(*std::dynamic_pointer_cast<ray const>(entity1),
                                  *std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 805:
        return acme::intersection(*std::dynamic_pointer_cast<plane const>(entity1),
                                  *std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 806:
        return acme::intersection(*std::dynamic_pointer_cast<segment const>(entity1),
                                  *std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<vec3>(entity_out));
        break;

      case 807:
        return acme::intersection(*std::dynamic_pointer_cast<triangle const>(entity1),
                                  *std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

      case 808:
        return acme::intersection(*std::dynamic_pointer_cast<circle const>(entity0),
                                  *std::dynamic_pointer_cast<circle const>(entity1),
                                  *std::dynamic_pointer_cast<segment>(entity_out));
        break;

        // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

      default:
        ACME_ERROR("acme::intersection(entity, entity): exception not handled.")
        return false;
        break;
      }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /*\
   |    ____      _ _ _                       
   |   / ___|___ | | (_)_ __   ___  __ _ _ __ 
   |  | |   / _ \| | | | '_ \ / _ \/ _` | '__|
   |  | |__| (_) | | | | | | |  __/ (_| | |   
   |   \____\___/|_|_|_|_| |_|\___|\__,_|_|   
   |                                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line0,
      line const &line1,
      line &line_out)
  {
    if (acme::isCollinear(line0, line1))
    {
      line_out = line0;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray0,
      ray const &ray1,
      ray &ray_out)
  {
    if (acme::isCollinear(ray0, ray1) &&
        ray0.direction().dot(ray1.direction()) > 0)
    {
      if (ray0.isInside(ray1.origin()))
      {
        ray_out = ray1;
        return true;
      }
      else if (ray1.isInside(ray0.origin()))
      {
        ray_out = ray0;
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray0,
      ray const &ray1,
      segment &segment_out)
  {
    if (acme::isCollinear(ray0, ray1) &&
        ray0.direction().dot(ray1.direction()) < 0)
    {
      if (ray0.isInside(ray1.origin()) && ray1.isInside(ray0.origin()))
      {
        segment_out.point(0) = ray0.origin();
        segment_out.point(1) = ray1.origin();
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment0,
      segment const &segment1,
      segment &segment_out)
  {
    if (acme::isCollinear(segment0, segment1))
    {
      //
      //   p0       p1   p0       p1
      //   o---s0---o    o---s1---o
      //
      vec3 s0_p0(segment0.point(0));
      vec3 s0_p1(segment0.point(1));
      vec3 s1_p0(segment1.point(0));
      vec3 s1_p1(segment1.point(1));
      bool s1_p0_in_s0 = segment0.isInside(s1_p0);
      bool s1_p1_in_s0 = segment0.isInside(s1_p1);
      bool s0_p0_in_s1 = segment1.isInside(s0_p0);
      bool s0_p1_in_s1 = segment1.isInside(s0_p1);
      //
      //                    Segments coincides
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      1      |      1      |      1      |      1      |
      if (s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.point(0) = s0_p0;
        segment_out.point(1) = s0_p1;
        return true;
      }
      //                       An extrema coincides
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      0      |      1      |      1      |      1      |
      // |      1      |      0      |      1      |      1      |
      // |      1      |      1      |      0      |      1      |
      // |      1      |      1      |      1      |      0      |
      else if (!s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.point(0) = s1_p0;
        segment_out.point(1) = s1_p1;
        return true;
      }
      else if (s0_p0_in_s1 && !s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.point(0) = s1_p0;
        segment_out.point(1) = s1_p1;
        return true;
      }
      else if (s0_p0_in_s1 && s0_p1_in_s1 && !s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.point(0) = s0_p0;
        segment_out.point(1) = s0_p1;
        return true;
      }
      else if (s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && !s1_p1_in_s0)
      {
        segment_out.point(0) = s0_p0;
        segment_out.point(1) = s0_p1;
        return true;
      }
      //                      Partial overlap
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      0      |      1      |      0      |      1      |
      // |      0      |      1      |      1      |      0      |
      // |      1      |      0      |      0      |      1      |
      // |      1      |      0      |      1      |      0      |
      else if (!s0_p0_in_s1 && s0_p1_in_s1 && !s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.point(0) = s0_p1;
        segment_out.point(1) = s1_p1;
        return true;
      }
      else if (!s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && !s1_p1_in_s0)
      {
        segment_out.point(0) = s0_p1;
        segment_out.point(1) = s1_p0;
        return true;
      }
      else if (s0_p0_in_s1 && !s0_p1_in_s1 && !s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.point(0) = s0_p0;
        segment_out.point(1) = s1_p1;
        return true;
      }
      else if (s0_p0_in_s1 && !s0_p1_in_s1 && s1_p0_in_s0 && !s1_p1_in_s0)
      {
        segment_out.point(0) = s0_p0;
        segment_out.point(1) = s1_p0;
        return true;
      }
      //                 One segment is inside
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      1      |      1      |      0      |      0      |
      // |      0      |      0      |      1      |      1      |
      else if (s0_p0_in_s1 && s0_p1_in_s1 && !s1_p0_in_s0 && !s1_p1_in_s0)
      {
        segment_out.point(0) = s0_p0;
        segment_out.point(1) = s0_p1;
        return true;
      }
      else if (!s0_p0_in_s1 && !s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.point(0) = s1_p0;
        segment_out.point(1) = s1_p1;
        return true;
      }
      //                   No intersection case
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      0      |      0      |      0      |      0      |
      else if (!s0_p0_in_s1 && !s0_p1_in_s1 && !s1_p0_in_s0 && !s1_p1_in_s0)
      {
        return false;
      }
      //                  Exception not handled
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      0      |      0      |      0      |      1      |
      // |      0      |      0      |      1      |      0      |
      // |      0      |      1      |      0      |      0      |
      // |      1      |      0      |      0      |      0      |
      else
      {
        ACME_ERROR("acme::intersection(segment, segment, segment): exception not handled.")
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line,
      ray const &ray_in,
      ray &ray_out)
  {
    if (acme::isCollinear(line, ray_in))
    {
      ray_out = ray_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line,
      segment const &segment_in,
      segment &segment_out)
  {
    if (acme::isCollinear(line, segment_in))
    {
      segment_out = segment_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray,
      segment const &segment_in,
      segment &segment_out)
  {
    vec3 point_0(segment_in.point(0));
    vec3 point_1(segment_in.point(1));
    if (acme::isCollinear(ray, segment_in))
    {
      if (ray.isInside(point_0) && ray.isInside(point_1))
      {
        segment_out = segment_in;
        return true;
      }
      else if (ray.isInside(point_0) && !ray.isInside(point_1))
      {
        segment_out.point(0) = ray.origin();
        segment_out.point(1) = point_0;
        return true;
      }
      else if (!ray.isInside(point_0) && ray.isInside(point_1))
      {
        segment_out.point(0) = ray.origin();
        segment_out.point(1) = point_1;
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /*\
   |    ____                      _      
   |   / ___| ___ _ __   ___ _ __(_) ___ 
   |  | |  _ / _ \ '_ \ / _ \ '__| |/ __|
   |  | |_| |  __/ | | |  __/ |  | | (__ 
   |   \____|\___|_| |_|\___|_|  |_|\___|
   |                                     
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line0,
      line const &line1,
      vec3 &point)
  {
    // if v and u are parallel (v x u = 0), then no intersection
    // collinearity imply parallelism!
    if (!acme::isCollinear(line0, line1))
    {
      vec3 p(line0.origin());
      vec3 v(line0.direction());
      vec3 q(line1.origin());
      vec3 u(line1.direction());
      // find a = v x u
      vec3 a(v.cross(u));
      // find dot product = (v x u).(v x u)
      real_type dot = a.dot(a);
      // find b = (Q1-P1) x u
      vec3 b((q - p).cross(u));
      // find t = (b.a)/(a.a) = ((Q1-P1) x u).(v x u) / (v x u).(v x u)
      real_type t = b.dot(a) / dot;
      // find intersection point
      point = p + (t * v);
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray0,
      ray const &ray1,
      vec3 &point)
  {
    if (acme::intersection(line(ray0.origin(), ray0.direction()),
                           line(ray1.origin(), ray1.direction()),
                           point))
      return ray0.isInside(point) && ray1.isInside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment0,
      segment const &segment1,
      vec3 &point)
  {
    if (acme::intersection(line(segment0.point(0), segment0.toNormalizedVector()),
                           line(segment1.point(0), segment1.toNormalizedVector()),
                           point))
      return segment0.isInside(point) && segment1.isInside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      ray const &ray,
      vec3 &point)
  {
    if (acme::intersection(line_in,
                           line(ray.origin(), ray.direction()),
                           point))
      return ray.isInside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      segment const &segment,
      vec3 &point)
  {
    if (acme::intersection(line_in,
                           line(segment.point(0), segment.toNormalizedVector()),
                           point))
      return segment.isInside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray,
      segment const &segment,
      vec3 &point)
  {
    if (acme::intersection(line(ray.origin(), ray.direction()),
                           line(segment.point(0), segment.toNormalizedVector()),
                           point))
      return segment.isInside(point) && ray.isInside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /*\
   |    ____            _                        
   |   / ___|___  _ __ | | __ _ _ __   __ _ _ __ 
   |  | |   / _ \| '_ \| |/ _` | '_ \ / _` | '__|
   |  | |__| (_) | |_) | | (_| | | | | (_| | |   
   |   \____\___/| .__/|_|\__,_|_| |_|\__,_|_|   
   |             |_|                             
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane0,
      plane const &plane1,
      plane &plane_out)
  {
    if (acme::isCoplanar(plane0, plane1))
    {
      plane_out = plane0;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  // bool
  // intersection(
  //     triangle const &triangle,
  //     triangle const &triangle,
  //     ?????????
  // );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  // bool
  // intersection(
  //     circle const &circle,
  //     circle const &circle,
  //     ?????????
  // );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      plane const &plane,
      line &line_out)
  {
    if (acme::isCoplanar(line_in, plane))
    {
      line_out = line_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line,
      triangle const &triangle,
      segment &segment)
  {
    vec3 point0, point1, point2;
    bool bool0, bool1, bool2;
    bool0 = intersection(line, triangle.edge(0, 1), point0);
    bool1 = intersection(line, triangle.edge(1, 2), point1);
    bool2 = intersection(line, triangle.edge(2, 0), point2);

    if (bool0 && bool1 && !bool2)
    {
      segment.point(0) = point0;
      segment.point(1) = point1;
      return true;
    }
    else if (!bool0 && bool1 && bool2)
    {
      segment.point(0) = point1;
      segment.point(1) = point2;
      return true;
    }
    else if (bool0 && !bool1 && bool2)
    {
      segment.point(0) = point2;
      segment.point(1) = point0;
      return true;
    }
    else if (bool0 && bool1 && bool2)
    {
      if (point0.isApprox(point1, acme::Epsilon))
      {
        segment.point(0) = point1;
        segment.point(1) = point2;
        return true;
      }
      else if (point1.isApprox(point2, acme::Epsilon))
      {
        segment.point(0) = point0;
        segment.point(1) = point1;
        return true;
      }
      else if (point0.isApprox(point2, acme::Epsilon))
      {
        segment.point(0) = point0;
        segment.point(1) = point1;
        return true;
      }
      else
      {
        std::cout << "point0 = " << point0 << std::endl;
        std::cout << "point1 = " << point1 << std::endl;
        std::cout << "point2 = " << point2 << std::endl;
        ACME_ERROR("acme::intersection(plane, triangle, segment): exception not handled.")
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line,
      circle const &circle,
      segment &segment)
  {
    // Locate one or two points that are on the circle and line.
    // If the line is t&D+P, the circle center is C, and the circle radius is r, then
    // r^2 = |t&D+P-C|^2 = |D|^2&t^2 + 2&Dot(D,P-C)&t + |P-C|^2
    // This is a quadratic equation of the form
    // a2&t^2 + 2&a1&t + a0 = 0.
    real_type circle_radius = circle.radius();
    vec3 circle_center(circle.center());
    vec3 line_origin(line.origin());
    vec3 line_direction(line.direction());
    vec3 diff(line_origin - circle_center);

    real_type a2 = line_direction.dot(line_direction);
    real_type a1 = diff.dot(line_direction);
    real_type a0 = diff.dot(diff) - circle_radius * circle_radius;

    real_type discriminant = a1 * a1 - a0 * a2;
    // No real roots, the circle does not intersection the plane
    if (discriminant <= -acme::Epsilon)
      return false;

    real_type inv = 1 / a2;
    // One repeated root, the circle just touches the plane
    if (acme::abs(discriminant) < acme::Epsilon)
    {
      vec3 int_point(line_origin - (a1 * inv) * line_direction);
      segment.point(0) = int_point;
      segment.point(1) = int_point;
      return true;
    }

    // Two distinct, real-valued roots, the circle intersects the plane in two points
    real_type root = std::sqrt(discriminant);
    segment.point(0) = line_origin - ((a1 + root) * inv) * line_direction;
    segment.point(1) = line_origin - ((a1 - root) * inv) * line_direction;
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray_in,
      plane const &plane,
      ray &ray_out)
  {
    if (acme::isCoplanar(ray_in, plane))
    {
      ray_out = ray_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray,
      triangle const &triangle,
      segment &segment_out)
  {
    // Transform ray to line
    line tmp_line(ray.origin(), ray.direction());
    // Compute the intersection of resulting line with the circle
    segment tmp_segment;
    if (acme::intersection(tmp_line, triangle, tmp_segment))
      return acme::intersection(ray, tmp_segment, segment_out);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray,
      circle const &circle,
      segment &segment_out)
  {
    // Transform ray to line
    line tmp_line(ray.origin(), ray.direction());
    // Compute the intersection of resulting line with the circle
    segment tmp_segment;
    if (acme::intersection(tmp_line, circle, tmp_segment))
      return acme::intersection(ray, tmp_segment, segment_out);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane,
      segment const &segment_in,
      segment &segment_out)
  {
    if (acme::isCoplanar(plane, segment_in))
    {
      segment_out = segment_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane,
      triangle const &triangle_in,
      triangle &triangle_out)
  {
    if (acme::isCoplanar(plane, triangle_in))
    {
      triangle_out = triangle_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane,
      circle const &circle_in,
      circle &circle_out)
  {
    if (acme::isCoplanar(plane, circle_in))
    {
      circle_out = circle_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment_in,
      triangle const &triangle,
      segment &segment_out)
  {
    line tmp_line(segment_in.point(0), segment_in.toNormalizedVector());
    segment tmp_segment;
    if (acme::intersection(tmp_line, triangle, tmp_segment))
      return acme::intersection(segment_in, tmp_segment, segment_out);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment_in,
      circle const &circle,
      segment &segment_out)
  {
    line tmp_line(segment_in.point(0), segment_in.toNormalizedVector());
    segment tmp_segment;
    if (acme::intersection(tmp_line, circle, tmp_segment))
      return acme::intersection(segment_in, tmp_segment, segment_out);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  // bool
  // intersection(
  //     triangle const &triangle,
  //     circle const &circle,
  //     ?????????
  // );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /*\
   |   _   _              ____            _                        
   |  | \ | | ___  _ __  / ___|___  _ __ | | __ _ _ __   __ _ _ __ 
   |  |  \| |/ _ \| '_ \| |   / _ \| '_ \| |/ _` | '_ \ / _` | '__|
   |  | |\  | (_) | | | | |__| (_) | |_) | | (_| | | | | (_| | |   
   |  |_| \_|\___/|_| |_|\____\___/| .__/|_|\__,_|_| |_|\__,_|_|   
   |                               |_|                             
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane0,
      plane const &plane1,
      line &line)
  {
    vec3 normal0 = plane0.normal();
    vec3 normal1 = plane1.normal();

    vec3 line_d = normal0.cross(normal1);
    real_type det = line_d.norm() * line_d.norm();
    if (acme::isApprox(det, real_type(0.0), acme::Epsilon))
    {
      return false;
    }
    else
    {
      line.origin((line_d.cross(normal1) * plane0.d()) +
                  (normal0.cross(line_d) * plane1.d()) / det);
      line.direction(line_d);
      return true;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane0,
      plane const &plane1,
      plane const &plane2,
      vec3 &point)
  {
    vec3 const normal0(plane0.normal());
    vec3 const normal1(plane1.normal());
    vec3 const normal2(plane2.normal());

    mat3 Mat;
    Mat << normal0, normal1, normal2;
    real_type det = Mat.determinant();
    if (acme::isApprox(det, real_type(0.0), acme::Epsilon))
    {
      return false;
    }
    else
    {
      point = (normal1.cross(normal2) * -plane0.d() +
               normal2.cross(normal0) * -plane1.d() +
               normal0.cross(normal1) * -plane2.d()) /
              det;
      return true;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      triangle const &triangle0,
      triangle const &triangle1,
      segment &segment_out)
  {
    line tmp_line;
    if (acme::intersection(triangle0.layingPlane(), triangle1.layingPlane(), tmp_line))
    {
      segment tmp_segment0, tmp_segment1, tmp_segment_out0, tmp_segment_out1;
      acme::intersection(tmp_line, tmp_segment0, tmp_segment_out0);
      acme::intersection(tmp_line, tmp_segment1, tmp_segment_out1);
      return acme::intersection(tmp_segment_out0, tmp_segment_out1, segment_out);
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      circle const &circle0,
      circle const &circle1,
      segment &segment_out)
  {
    line tmp_line;
    if (acme::intersection(circle0.layingPlane(), circle1.layingPlane(), tmp_line))
    {
      segment tmp_segment0, tmp_segment1, tmp_segment_out0, tmp_segment_out1;
      acme::intersection(tmp_line, tmp_segment0, tmp_segment_out0);
      acme::intersection(tmp_line, tmp_segment1, tmp_segment_out1);
      return acme::intersection(tmp_segment_out0, tmp_segment_out1, segment_out);
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line,
      plane const &plane,
      vec3 &point)
  {
    real_type det = line.direction().dot(plane.normal());
    if (det > acme::Epsilon)
    {
      real_type t = -(line.origin() - plane.origin()).dot(plane.normal()) / det;
      point = line.origin() + line.direction() * t;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line,
      triangle const &triangle,
      vec3 &point)
  {
    vec3 vertex0 = triangle.vertex(0);
    vec3 vertex1 = triangle.vertex(1);
    vec3 vertex2 = triangle.vertex(2);
    vec3 edge1 = vertex1 - vertex0;
    vec3 edge2 = vertex2 - vertex0;

    vec3 origin = line.origin();
    vec3 direction = line.direction();

    vec3 h, s, q;
    real_type a, f, u, v;
    h = direction.cross(edge2);
    a = edge1.dot(h);
    if (a > -acme::Epsilon && a < acme::Epsilon)
      return false;
    f = 1.0 / a;
    s = origin - vertex0;
    u = f * s.dot(h);
    if (u < real_type(0.0) || u > real_type(1.0))
      return false;
    q = s.cross(edge1);
    v = f * direction.dot(q);
    if (v < real_type(0.0) || u + v > real_type(1.0))
      return false;
    float t = f * edge2.dot(q);
    point = origin + direction * t;
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line,
      circle const &circle,
      vec3 &point)
  {
    if (acme::intersection(line, circle.layingPlane(), point))
    {
      if ((circle.center() - point).norm() <= circle.radius())
        return true;
      else
        return false;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray,
      plane const &plane,
      vec3 &point)
  {
    real_type det = ray.direction().dot(plane.normal());
    if (det > acme::Epsilon)
    {
      real_type t = -(ray.origin() - plane.origin()).dot(plane.normal()) / det;
      if (t > acme::Epsilon)
      {
        point = ray.origin() + ray.direction() * t;
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray,
      triangle const &triangle,
      vec3 &point)
  {
    vec3 vertex0(triangle.vertex(0));
    vec3 vertex1(triangle.vertex(1));
    vec3 vertex2(triangle.vertex(2));
    vec3 edge1(vertex1 - vertex0);
    vec3 edge2(vertex2 - vertex0);

    vec3 origin(ray.origin());
    vec3 direction(ray.direction());

    vec3 h, s, q;
    real_type a, f, u, v;
    h = direction.cross(edge2);
    a = edge1.dot(h);
    if (a > -acme::Epsilon && a < acme::Epsilon)
      return false;
    f = 1.0 / a;
    s = origin - vertex0;
    u = f * s.dot(h);
    if (u < real_type(0.0) || u > real_type(1.0))
      return false;
    q = s.cross(edge1);
    v = f * direction.dot(q);
    if (v < real_type(0.0) || u + v > real_type(1.0))
      return false;
    float t = f * edge2.dot(q);
    if (t >= real_type(0.0))
    {
      point = origin + direction * t;
      return true;
    }
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray,
      circle const &circle,
      vec3 &point)
  {
    if (acme::intersection(line(ray.origin(), ray.direction()), circle.layingPlane(), point))
      return ray.isInside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane,
      segment const &segment,
      vec3 &point)
  {
    real_type d0 = plane.signedDistance(segment.point(0));
    real_type d1 = plane.signedDistance(segment.point(1));
    if (acme::isApprox(d0, real_type(0.0), acme::Epsilon))
    {
      point = segment.point(0);
      return true;
    }
    else if (acme::isApprox(d1, real_type(0.0), acme::Epsilon))
    {
      point = segment.point(1);
      return true;
    }
    else if (d0 * d1 < 0)
    {
      real_type t = d0 / (d0 - d1);
      point = segment.point(0) + t * (segment.point(1) - segment.point(0));
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane,
      triangle const &triangle,
      segment &segment)
  {
    line tmp_line;
    if (acme::intersection(plane,
                           triangle.layingPlane(),
                           tmp_line))
      return acme::intersection(tmp_line, triangle, segment);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane,
      circle const &circle,
      segment &segment)
  {
    line tmp_line;
    if (acme::intersection(plane,
                           circle.layingPlane(),
                           tmp_line))
      return acme::intersection(tmp_line, circle, segment);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment,
      triangle const &triangle,
      vec3 &point)
  {
    if (acme::intersection(line(segment.point(0), segment.toNormalizedVector()),
                           triangle.layingPlane(),
                           point))
      return segment.isInside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment,
      circle const &circle,
      vec3 &point)
  {
    if (acme::intersection(line(segment.point(0), segment.toNormalizedVector()),
                           circle.layingPlane(),
                           point))
      return segment.isInside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      triangle const &triangle,
      circle const &circle,
      segment &segment_out)
  {
    segment tmp_segment;
    if (acme::intersection(circle.layingPlane(), triangle, tmp_segment))
      return acme::intersection(tmp_segment, circle, segment_out);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /*\
   |   __  __ _              _ _                                  
   |  |  \/  (_)___  ___ ___| | | __ _ _ __   ___  ___  _   _ ___ 
   |  | |\/| | / __|/ __/ _ \ | |/ _` | '_ \ / _ \/ _ \| | | / __|
   |  | |  | | \__ \ (_|  __/ | | (_| | | | |  __/ (_) | |_| \__ \
   |  |_|  |_|_|___/\___\___|_|_|\__,_|_| |_|\___|\___/ \__,_|___/
   |                                                              
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      box const &box0,
      box const &box1,
      box &box)
  {
    if (!(box0.intersects(box1)))
      return false;

    for (int i = 0; i < 3; ++i)
    {
      if (box0.max(i) <= box1.max(i))
        box.max(i, box0.max(i));
      else
        box.max(i, box1.max(i));
      if (box0.min(i) <= box1.min(i))
        box.min(i, box1.min(i));
      else
        box.min(i, box0.min(i));
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_intersection.cc
///