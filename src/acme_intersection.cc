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

  entity *
  intersection(
      entity const *entity0_in,
      entity const *entity1_in,
      real tolerance)
  {
    integer slide = entity0_in->level() * 100 + entity1_in->level();
    bool collide = false;
    entity *entity_out = nullptr;
    if (entity0_in->isPoint() || entity1_in->isPoint())
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - POINT - - - - - - - - - - - - - -

      case 202:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity0_in),
                               *dynamic_cast<point const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 203:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity0_in),
                               *dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 204:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity0_in),
                               *dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 205:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity0_in),
                               *dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 206:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 207:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 208:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 302:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity1_in),
                               *dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 402:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity1_in),
                               *dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 502:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity1_in),
                               *dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 602:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity1_in),
                               *dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 702:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity1_in),
                               *dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 802:
        entity_out = new point();
        collide = intersection(*dynamic_cast<point const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      default:
        ACME_ERROR("acme::intersection(entity, entity): exception not handled (punctual).\n")
        collide = false;
        break;
      }
    }
    else if (isCollinear(entity0_in, entity1_in))
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

      case 303:
        entity_out = new line();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<line *>(entity_out),
                               tolerance);
        break;

      case 304:
        entity_out = new ray();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<ray *>(entity_out),
                               tolerance);
        break;

      case 306:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

      case 403:
        entity_out = new ray();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<ray *>(entity_out),
                               tolerance);

        break;

      case 404:
        entity_out = new ray();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<ray *>(entity_out),
                               tolerance);
        if (!collide)
          delete entity_out;
        else
          break;

        entity_out = new segment();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        if (!collide)
          delete entity_out;
        else
          break;

        ACME_ERROR("acme::intersection(ray, ray): Exception not handled");
        break;

      case 406:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

      case 603:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 604:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 606:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

      default:
        ACME_ERROR("acme::intersection(entity, entity): exception not handled (colliear).\n")
        collide = false;
        entity_out = new none();
        break;
      }
    }
    else if (isCoplanar(entity0_in, entity1_in))
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

      case 303:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 304:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 305:
        entity_out = new line();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<line *>(entity_out),
                               tolerance);
        break;

      case 306:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 307:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 308:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

      case 403:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 404:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 405:
        entity_out = new ray();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<ray *>(entity_out),
                               tolerance);
        break;

      case 406:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 407:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 408:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

      case 503:
        entity_out = new line();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<line *>(entity_out),
                               tolerance);
        break;

      case 504:
        entity_out = new ray();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<ray *>(entity_out),
                               tolerance);
        break;

      case 505:
        entity_out = new plane();
        collide = intersection(*dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<plane *>(entity_out),
                               tolerance);
        break;

      case 506:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 507:
        entity_out = new triangle();
        collide = intersection(*dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<triangle *>(entity_out),
                               tolerance);
        break;

      case 508:
        entity_out = new circle();
        collide = intersection(*dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<circle *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

      case 603:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 604:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 605:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 606:
        entity_out = new point();
        collide = intersection(*dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 607:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 608:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

      case 703:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 704:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 705:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 706:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // case 707:
        //   entity_out = new ??????();
        //   collide = intersection(*dynamic_cast<triangle const *>(entity0_in),
        //                             *dynamic_cast<triangle const *>(entity1_in),
        //                             *dynamic_cast<?????? *>(entity_out),
        //                             tolerance);
        //   break;

        // case 708:
        //   entity_out = new ??????();
        //   collide = intersection(*dynamic_cast<triangle const *>(entity0_in),
        //                             *dynamic_cast<circle const *>(entity1_in),
        //                             *dynamic_cast<?????? *>(entity_out),
        //                             tolerance);
        //   break;

        // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

      case 803:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 804:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 805:
        entity_out = new circle();
        collide = intersection(*dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<circle *>(entity_out),
                               tolerance);
        break;

      case 806:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // case 807:
        //   entity_out = new ????????();
        //   collide = intersection(*dynamic_cast<triangle const *>(entity1_in),
        //                          *dynamic_cast<circle const *>(entity0_in),
        //                          *dynamic_cast<???????? *>(entity_out),
        //                          tolerance);
        //   break;

        // case 808:
        //   entity_out = new ????????();
        //   collide = intersection(*dynamic_cast<circle const *>(entity0_in),
        //                          *dynamic_cast<circle const *>(entity1_in),
        //                          *dynamic_cast<<???????? *>(entity_out),
        //                          tolerance);
        //   break;

        // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

      default:
        ACME_ERROR("acme::intersection(entity, entity): exception not handled (coplanar).\n")
        collide = false;
        entity_out = new none();
        break;
      }
    }
    else
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

      case 303:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 304:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 305:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 306:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 307:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 308:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 309:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<line const *>(entity0_in),
                               *dynamic_cast<sphere const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

      case 403:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 404:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 405:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 406:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 407:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 408:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 409:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<ray const *>(entity0_in),
                               *dynamic_cast<sphere const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

      case 503:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 504:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 505:
        entity_out = new line();
        collide = intersection(*dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<line *>(entity_out),
                               tolerance);
        break;

      case 506:
        entity_out = new point();
        collide = intersection(*dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 507:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 508:
        collide = intersection(*dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 509:
        entity_out = new circle();
        collide = intersection(*dynamic_cast<plane const *>(entity0_in),
                               *dynamic_cast<sphere const *>(entity1_in),
                               *dynamic_cast<circle *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

      case 603:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 604:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 605:
        entity_out = new point();
        collide = intersection(*dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 606:
        entity_out = new point();
        collide = intersection(*dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 607:
        entity_out = new point();
        collide = intersection(*dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 608:
        entity_out = new point();
        collide = intersection(*dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 609:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<segment const *>(entity0_in),
                               *dynamic_cast<sphere const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

      case 703:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 704:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 705:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 706:
        entity_out = new point();
        collide = intersection(*dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 707:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 708:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<triangle const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // case 709:
        //   entity_out = ??????();
        //   collide = intersection(*dynamic_cast<triangle const *>(entity0_in),
        //                          *dynamic_cast<sphere const *>(entity1_in),
        //                          ??????
        //                          tolerance);
        //   break;

        // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

      case 803:
        entity_out = new point();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 804:
        entity_out = new point();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 805:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 806:
        entity_out = new point();
        collide = intersection(*dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<point *>(entity_out),
                               tolerance);
        break;

      case 807:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<triangle const *>(entity1_in),
                               *dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 808:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<circle const *>(entity0_in),
                               *dynamic_cast<circle const *>(entity1_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // case 809:
        //   entity_out = ??????();
        //   collide = intersection(*dynamic_cast<circle const *>(entity0_in),
        //                          *dynamic_cast<sphere const *>(entity1_in),
        //                          ??????
        //                          tolerance);
        //   break;

        // - - - - - - - - - - - - - - SPHERE - - - - - - - - - - - - - -

      case 903:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<line const *>(entity1_in),
                               *dynamic_cast<sphere const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 904:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<ray const *>(entity1_in),
                               *dynamic_cast<sphere const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

      case 905:
        entity_out = new circle();
        collide = intersection(*dynamic_cast<plane const *>(entity1_in),
                               *dynamic_cast<sphere const *>(entity0_in),
                               *dynamic_cast<circle *>(entity_out),
                               tolerance);
        break;

      case 906:
        entity_out = new segment();
        collide = intersection(*dynamic_cast<segment const *>(entity1_in),
                               *dynamic_cast<sphere const *>(entity0_in),
                               *dynamic_cast<segment *>(entity_out),
                               tolerance);
        break;

        // case 907:
        //   entity_out = ??????();
        //   collide = intersection(*dynamic_cast<triangle const *>(entity1_in),
        //                          *dynamic_cast<sphere const *>(entity0_in),
        //                          ??????
        //                          tolerance);
        //   break;

        // case 908:
        //   entity_out = ??????();;
        //   collide = intersection(*dynamic_cast<circle const *>(entity1_in),
        //                          *dynamic_cast<sphere const *>(entity0_in),
        //                          ??????
        //                          tolerance);
        //   break;

        // case 909:
        //   entity_out = ??????();
        //   collide = intersection(*dynamic_cast<sphere const *>(entity0_in),
        //                          *dynamic_cast<sphere const *>(entity1_in),
        //                          ??????
        //                          tolerance);
        //   break;

        // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

      default:
        ACME_ERROR("acme::intersection(entity, entity): exception not handled (general).\n")
        collide = false;
        break;
      }
    }
    if (collide)
    {
      return entity_out;
    }
    else if (!collide)
    {
      entity_out = new none();
      return entity_out;
    }
    else
    {
      ACME_ERROR("acme::intersection(entity, entity): return exception not handled.\n")
      entity_out = new none();
      return entity_out;
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
      line const &line0_in,
      line const &line1_in,
      line &line_out,
      real tolerance)
  {
    if (isCollinear(line0_in, line1_in, tolerance))
    {
      line_out = line0_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray0_in,
      ray const &ray1_in,
      ray &ray_out,
      real tolerance)
  {
    if (isCollinear(ray0_in, ray1_in, tolerance) &&
        ray0_in.direction().dot(ray1_in.direction()) > 0.0)
    {
      if (ray0_in.isInside(ray1_in.origin(), tolerance))
      {
        ray_out = ray1_in;
        return true;
      }
      else if (ray1_in.isInside(ray0_in.origin(), tolerance))
      {
        ray_out = ray0_in;
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
      ray const &ray0_in,
      ray const &ray1_in,
      segment &segment_out,
      real tolerance)
  {
    if (isCollinear(ray0_in, ray1_in, tolerance) &&
        ray0_in.direction().dot(ray1_in.direction()) < 0.0)
    {
      if (ray0_in.isInside(ray1_in.origin(), tolerance) &&
          ray1_in.isInside(ray0_in.origin(), tolerance))
      {
        segment_out.vertex(0) = ray0_in.origin();
        segment_out.vertex(1) = ray1_in.origin();
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
      segment const &segment0_in,
      segment const &segment1_in,
      segment &segment_out,
      real tolerance)
  {
    if (isCollinear(segment0_in, segment1_in, tolerance))
    {
      //
      //   p0       p1   p0       p1
      //   o---s0---o    o---s1---o
      //
      point s0_p0(segment0_in.vertex(0));
      point s0_p1(segment0_in.vertex(1));
      point s1_p0(segment1_in.vertex(0));
      point s1_p1(segment1_in.vertex(1));
      int sx_px_in_sx =
          int(segment0_in.isInside(s1_p1, tolerance)) +
          int(segment0_in.isInside(s1_p0, tolerance)) * 10 +
          int(segment1_in.isInside(s0_p1, tolerance)) * 100 +
          int(segment1_in.isInside(s0_p0, tolerance)) * 1000;

      switch (sx_px_in_sx)
      {
      //
      //                    Segments coincides
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      1      |      1      |      1      |      1      |
      case 1111: // 1111
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s0_p1;
        return true;

      //                       An extrema coincides
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      0      |      1      |      1      |      1      |
      // |      1      |      0      |      1      |      1      |
      // |      1      |      1      |      0      |      1      |
      // |      1      |      1      |      1      |      0      |
      case 111: // 0111
        segment_out.vertex(0) = s1_p0;
        segment_out.vertex(1) = s1_p1;
        return true;

      case 1011: // 1011
        segment_out.vertex(0) = s1_p0;
        segment_out.vertex(1) = s1_p1;
        return true;

      case 1101: // 1101
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s0_p1;
        return true;

      case 1110: // 1110
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s0_p1;
        return true;

      //                      Partial overlap
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      0      |      1      |      0      |      1      |
      // |      0      |      1      |      1      |      0      |
      // |      1      |      0      |      0      |      1      |
      // |      1      |      0      |      1      |      0      |
      case 101: // 0101
        segment_out.vertex(0) = s0_p1;
        segment_out.vertex(1) = s1_p1;
        return true;

      case 110: // 0110
        segment_out.vertex(0) = s0_p1;
        segment_out.vertex(1) = s1_p0;
        return true;

      case 1001: // 1001
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s1_p1;
        return true;

      case 1010: // 1010
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s1_p0;
        return true;

      //                 One segment is inside
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      1      |      1      |      0      |      0      |
      // |      0      |      0      |      1      |      1      |
      case 1100: // 1100
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s0_p1;
        return true;

      case 11: // 0011
        segment_out.vertex(0) = s1_p0;
        segment_out.vertex(1) = s1_p1;
        return true;

      //                   No intersection case
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      0      |      0      |      0      |      0      |
      case 0: // 0000
        return false;

      //                  Exception not handled
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      0      |      0      |      0      |      1      |
      // |      0      |      0      |      1      |      0      |
      // |      0      |      1      |      0      |      0      |
      // |      1      |      0      |      0      |      0      |
      default:
        ACME_ERROR("acme::intersection(segment, segment, segment): exception not handled.\n")
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
      line const &line_in,
      ray const &ray_in,
      ray &ray_out,
      real tolerance)
  {
    if (isCollinear(line_in, ray_in, tolerance))
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
      line const &line_in,
      segment const &segment_in,
      segment &segment_out,
      real tolerance)
  {
    if (isCollinear(line_in, segment_in, tolerance))
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
      ray const &ray_in,
      segment const &segment_in,
      segment &segment_out,
      real tolerance)
  {
    point point_0(segment_in.vertex(0));
    point point_1(segment_in.vertex(1));
    if (isCollinear(ray_in, segment_in, tolerance))
    {
      if (ray_in.isInside(point_0, tolerance) &&
          ray_in.isInside(point_1, tolerance))
      {
        segment_out = segment_in;
        return true;
      }
      else if (ray_in.isInside(point_0, tolerance) &&
               !ray_in.isInside(point_1, tolerance))
      {
        segment_out.vertex(0) = ray_in.origin();
        segment_out.vertex(1) = point_0;
        return true;
      }
      else if (!ray_in.isInside(point_0, tolerance) &&
               ray_in.isInside(point_1, tolerance))
      {
        segment_out.vertex(0) = ray_in.origin();
        segment_out.vertex(1) = point_1;
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
   |   ____                   _               _ 
   |  |  _ \ _   _ _ __   ___| |_ _   _  __ _| |
   |  | |_) | | | | '_ \ / __| __| | | |/ _` | |
   |  |  __/| |_| | | | | (__| |_| |_| | (_| | |
   |  |_|    \__,_|_| |_|\___|\__|\__,_|\__,_|_| 
   |                                            
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      point const &point0_in,
      point const &point1_in,
      point &point_out,
      real tolerance)
  {
    if (point0_in.isApprox(point1_in, tolerance))
    {
      point_out = point0_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      point const &point_in,
      line const &line_in,
      point &point_out,
      real tolerance)
  {
    if (line_in.isInside(point_in, tolerance))
    {
      point_out = point_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      point const &point_in,
      ray const &ray_in,
      point &point_out,
      real tolerance)
  {
    if (ray_in.isInside(point_in, tolerance))
    {
      point_out = point_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      point const &point_in,
      plane const &plane_in,
      point &point_out,
      real tolerance)
  {
    if (plane_in.isInside(point_in, tolerance))
    {
      point_out = point_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      point const &point_in,
      segment const &segment_in,
      point &point_out,
      real tolerance)
  {
    if (segment_in.isInside(point_in, tolerance))
    {
      point_out = point_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      point const &point_in,
      triangle const &triangle_in,
      point &point_out,
      real tolerance)
  {
    if (triangle_in.isInside(point_in, tolerance))
    {
      point_out = point_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      point const &point_in,
      circle const &circle_in,
      point &point_out,
      real tolerance)
  {
    if (circle_in.isInside(point_in, tolerance))
    {
      point_out = point_in;
      return true;
    }
    else
    {
      return false;
    }
  }

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
      line const &line0_in,
      line const &line1_in,
      point &point_out,
      real tolerance)
  {
    // if v and u are parallel (v x u = 0), then no intersection
    // collinearity imply parallelism!
    if (!isCollinear(line0_in, line1_in, tolerance))
    {
      point p(line0_in.origin());
      vec3 v(line0_in.direction());
      point q(line1_in.origin());
      vec3 u(line1_in.direction());
      // find a = v x u
      vec3 a(v.cross(u));
      // find dot product = (v x u).(v x u)
      real dot = a.dot(a);
      // find b = (Q1-P1) x u
      vec3 b((q - p).cross(u));
      // find t = (b.a)/(a.a) = ((Q1-P1) x u).(v x u) / (v x u).(v x u)
      real t = b.dot(a) / dot;
      // find intersection point
      point_out = p + (t * v);
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray0_in,
      ray const &ray1_in,
      point &point_out,
      real tolerance)
  {
    if (intersection(line(ray0_in.origin(), ray0_in.direction()),
                     line(ray1_in.origin(), ray1_in.direction()),
                     point_out,
                     tolerance))
      return ray0_in.isInside(point_out, tolerance) &&
             ray1_in.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment0_in,
      segment const &segment1_in,
      point &point_out,
      real tolerance)
  {
    if (intersection(line(segment0_in.vertex(0), segment0_in.toUnitVector()),
                     line(segment1_in.vertex(0), segment1_in.toUnitVector()),
                     point_out,
                     tolerance))
      return segment0_in.isInside(point_out, tolerance) &&
             segment1_in.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      ray const &ray_in,
      point &point_out,
      real tolerance)
  {
    if (intersection(line_in,
                     line(ray_in.origin(), ray_in.direction()),
                     point_out,
                     tolerance))
      return ray_in.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      segment const &segment_in,
      point &point_out,
      real tolerance)
  {
    if (intersection(line_in,
                     line(segment_in.vertex(0), segment_in.toUnitVector()),
                     point_out,
                     tolerance))
      return segment_in.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray_in,
      segment const &segment_in,
      point &point_out,
      real tolerance)
  {
    if (intersection(line(ray_in.origin(), ray_in.direction()),
                     line(segment_in.vertex(0), segment_in.toUnitVector()),
                     point_out,
                     tolerance))
      return segment_in.isInside(point_out, tolerance) &&
             ray_in.isInside(point_out, tolerance);
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
      plane const &plane0_in,
      plane const &plane1_in,
      plane &plane_out,
      real tolerance)
  {
    if (isCoplanar(plane0_in, plane1_in, tolerance))
    {
      plane_out = plane0_in;
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
  //     triangle const &triangle_in,
  //     triangle const &triangle_in,
  //     ??????
  //     real tolerance
  // );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  // bool
  // intersection(
  //     circle const &circle_in,
  //     circle const &circle_in,
  //     ??????
  //     real tolerance
  // );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      plane const &plane_in,
      line &line_out,
      real tolerance)
  {
    if (isCoplanar(line_in, plane_in, tolerance))
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
      line const &line_in,
      triangle const &triangle_in,
      segment &segment_out,
      real tolerance)
  {
    point point0, point1, point2;
    bool bool0, bool1, bool2;
    bool0 = intersection(line_in, triangle_in.edge(0), point0, tolerance);
    bool1 = intersection(line_in, triangle_in.edge(1), point1, tolerance);
    bool2 = intersection(line_in, triangle_in.edge(2), point2, tolerance);

    if (bool0 && bool1 && !bool2)
    {
      segment_out.vertex(0) = point0;
      segment_out.vertex(1) = point1;
      return true;
    }
    else if (!bool0 && bool1 && bool2)
    {
      segment_out.vertex(0) = point1;
      segment_out.vertex(1) = point2;
      return true;
    }
    else if (bool0 && !bool1 && bool2)
    {
      segment_out.vertex(0) = point2;
      segment_out.vertex(1) = point0;
      return true;
    }
    else if (bool0 && bool1 && bool2)
    {
      if (point0.isApprox(point1, tolerance))
      {
        segment_out.vertex(0) = point1;
        segment_out.vertex(1) = point2;
        return true;
      }
      else if (point1.isApprox(point2, tolerance))
      {
        segment_out.vertex(0) = point0;
        segment_out.vertex(1) = point1;
        return true;
      }
      else if (point0.isApprox(point2, tolerance))
      {
        segment_out.vertex(0) = point0;
        segment_out.vertex(1) = point1;
        return true;
      }
      else
      {
        ACME_ERROR("acme::ntersection(line, triangle, segment): exception not handled.\n")
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
      line const &line_in,
      circle const &circle_in,
      segment &segment_out,
      real tolerance)
  {
    // Locate one or two points that are on the circle and line.
    // If the line is t&D+P, the circle center is C, and the circle radius is r, then
    // r^2 = |t&D+P-C|^2 = |D|^2&t^2 + 2&Dot(D,P-C)&t + |P-C|^2
    // This is a quadratic equation of the form
    // a2&t^2 + 2&a1&t + a0 = 0.
    real circle_radius = circle_in.radius();
    point circle_center(circle_in.center());
    point line_origin(line_in.origin());
    vec3 line_direction(line_in.direction());
    vec3 diff(line_origin - circle_center);

    real a2 = line_direction.dot(line_direction);
    real a1 = diff.dot(line_direction);
    real a0 = diff.dot(diff) - circle_radius * circle_radius;

    real discriminant = a1 * a1 - a0 * a2;
    // No real roots, the circle does not intersection the plane
    if (discriminant <= -tolerance)
      return false;

    real inv = 1 / a2;
    // One repeated root, the circle just touches the plane
    if (std::abs(discriminant) < tolerance)
    {
      point int_point(line_origin - (a1 * inv) * line_direction);
      segment_out.vertex(0) = int_point;
      segment_out.vertex(1) = int_point;
      return true;
    }

    // Two distinct, real-valued roots, the circle intersects the plane in two points
    real root = std::sqrt(discriminant);
    segment_out.vertex(0) = line_origin - ((a1 + root) * inv) * line_direction;
    segment_out.vertex(1) = line_origin - ((a1 - root) * inv) * line_direction;
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      sphere const &sphere_in,
      segment &segment_out,
      real tolerance)
  {
    // The sphere is (X-C)^T*(X-C)-1 = 0 and the line is X = P+t*D.
    // Substitute the line equation into the sphere equation to
    // obtain a quadratic equation Q(t) = t^2 + 2*a1*t + a0 = 0, where
    // a1 = D^T*(P-C) and a0 = (P-C)^T*(P-C)-1
    vec3 diff(line_in.origin() - sphere_in.center());
    real a0 = diff.dot(diff) - sphere_in.radius() * sphere_in.radius();
    real a1 = line_in.direction().dot(diff);

    // Intersection occurs when Q(t) has real roots
    real discr = a1 * a1 - a0;
    if (discr > tolerance)
    {
      // The line intersects the sphere in 2 distinct points
      real root = std::sqrt(discr);
      segment_out.vertex(0) = line_in.origin() + (-a1 - root) * line_in.direction();
      segment_out.vertex(1) = line_in.origin() + (-a1 + root) * line_in.direction();
      return true;
    }
    else
    {
      // The line does not intersect the sphere
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray_in,
      plane const &plane_in,
      ray &ray_out,
      real tolerance)
  {
    if (isCoplanar(ray_in, plane_in, tolerance))
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
      ray const &ray_in,
      triangle const &triangle_in,
      segment &segment_out,
      real tolerance)
  {
    // Compute the intersection of resulting line with the circle
    segment tmp_segment;
    if (intersection(line(ray_in.origin(), ray_in.direction()),
                     triangle_in,
                     tmp_segment,
                     tolerance))
      return intersection(ray_in, tmp_segment, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray_in,
      circle const &circle_in,
      segment &segment_out,
      real tolerance)
  {
    // Compute the intersection of resulting line with the circle
    segment tmp_segment;
    if (intersection(line(ray_in.origin(), ray_in.direction()),
                     circle_in,
                     tmp_segment,
                     tolerance))
      return intersection(ray_in, tmp_segment, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray_in,
      sphere const &sphere_in,
      segment &segment_out,
      real tolerance)
  {
    segment tmp_segment;
    if (intersection(line(ray_in.origin(), ray_in.direction()),
                     sphere_in,
                     tmp_segment,
                     tolerance))
      return intersection(ray_in, tmp_segment, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane_in,
      segment const &segment_in,
      segment &segment_out,
      real tolerance)
  {
    if (isCoplanar(plane_in, segment_in, tolerance))
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
      plane const &plane_in,
      triangle const &triangle_in,
      triangle &triangle_out,
      real tolerance)
  {
    if (isCoplanar(plane_in, triangle_in, tolerance))
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
      plane const &plane_in,
      circle const &circle_in,
      circle &circle_out,
      real tolerance)
  {
    if (isCoplanar(plane_in, circle_in, tolerance))
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
      plane const &plane_in,
      sphere const &sphere_in,
      circle &circle_out,
      real tolerance)
  {
    real signed_distance = plane_in.signedDistance(sphere_in.center());
    real distance = std::abs(signed_distance);
    if (distance <= sphere_in.radius())
    {
      circle_out.radius() = std::sqrt((sphere_in.radius() + distance) * (sphere_in.radius() - distance));
      circle_out.center() = sphere_in.center() - signed_distance * plane_in.normal();
      circle_out.normal() = plane_in.normal();
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
      triangle const &triangle_in,
      segment &segment_out,
      real tolerance)
  {
    line tmp_line(segment_in.vertex(0), segment_in.toUnitVector());
    segment tmp_segment;
    if (intersection(tmp_line, triangle_in, tmp_segment, tolerance))
      return intersection(segment_in, tmp_segment, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment_in,
      circle const &circle_in,
      segment &segment_out,
      real tolerance)
  {
    segment tmp_segment;
    if (intersection(line(segment_in.vertex(0), segment_in.toUnitVector()),
                     circle_in,
                     tmp_segment,
                     tolerance))
      return intersection(segment_in, tmp_segment, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment_in,
      sphere const &sphere_in,
      segment &segment_out,
      real tolerance)
  {
    segment tmp_segment;
    if (intersection(line(segment_in.vertex(0), segment_in.toUnitVector()),
                     sphere_in,
                     tmp_segment,
                     tolerance))
      return intersection(segment_in, tmp_segment, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  // bool
  // intersection(
  //     triangle const &triangle_in,
  //     circle const &circle_in,
  //     ??????
  //     real tolerance
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
      plane const &plane0_in,
      plane const &plane1_in,
      line &line,
      real tolerance)
  {
    vec3 normal0(plane0_in.normal().normalized());
    vec3 normal1(plane1_in.normal().normalized());
    real d0 = -plane0_in.d();
    real d1 = -plane1_in.d();

    vec3 direction = normal0.cross(normal1);
    real dot = normal0.dot(normal1);
    real norm = direction.norm();
    if (isApprox(norm * norm, 0.0, tolerance))
    {
      return false;
    }
    else
    {
      real invDet = 1.0 / (1.0 - dot * dot);
      real c0 = (d0 - dot * d1) * invDet;
      real c1 = (d1 - dot * d0) * invDet;
      line.origin() = c0 * normal0 + c1 * normal1;
      line.direction() = direction;
      return true;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane0_in,
      plane const &plane1_in,
      plane const &plane2_in,
      point &point_out,
      real tolerance)
  {
    vec3 const normal0(plane0_in.normal());
    vec3 const normal1(plane1_in.normal());
    vec3 const normal2(plane2_in.normal());

    mat3 Mat;
    Mat << normal0, normal1, normal2;
    real det = Mat.determinant();
    if (isApprox(det, 0.0, tolerance))
    {
      return false;
    }
    else
    {
      point_out = (normal1.cross(normal2) * -plane0_in.d() +
                   normal2.cross(normal0) * -plane1_in.d() +
                   normal0.cross(normal1) * -plane2_in.d()) /
                  det;
      return true;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      triangle const &triangle0_in,
      triangle const &triangle1_in,
      segment &segment_out,
      real tolerance)
  {
    line tmp_line;
    if (intersection(triangle0_in.layingPlane(),
                     triangle1_in.layingPlane(),
                     tmp_line,
                     tolerance))
    {
      segment tmp_segment0, tmp_segment1;
      intersection(tmp_line, triangle0_in, tmp_segment0, tolerance);
      intersection(tmp_line, triangle1_in, tmp_segment1, tolerance);
      return intersection(tmp_segment0, tmp_segment1, segment_out, tolerance);
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      circle const &circle0_in,
      circle const &circle1_in,
      segment &segment_out,
      real tolerance)
  {
    line tmp_line;
    if (intersection(circle0_in.layingPlane(),
                     circle1_in.layingPlane(),
                     tmp_line,
                     tolerance))
    {
      segment tmp_segment0, tmp_segment1;
      intersection(tmp_line, circle0_in, tmp_segment0, tolerance);
      intersection(tmp_line, circle1_in, tmp_segment1, tolerance);
      return intersection(tmp_segment0, tmp_segment1, segment_out, tolerance);
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      plane const &plane_in,
      point &point_out,
      real tolerance)
  {
    real det = line_in.direction().dot(plane_in.normal());
    if (det > tolerance)
    {
      real t = -(line_in.origin() - plane_in.origin()).dot(plane_in.normal()) / det;
      point_out = line_in.origin() + line_in.direction() * t;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      triangle const &triangle_in,
      point &point_out,
      real tolerance)
  {
    point vertex0 = triangle_in.vertex(0);
    point vertex1 = triangle_in.vertex(1);
    point vertex2 = triangle_in.vertex(2);
    vec3 edge1 = vertex1 - vertex0;
    vec3 edge2 = vertex2 - vertex0;

    point origin = line_in.origin();
    vec3 direction = line_in.direction();

    vec3 h, s, q;
    real a, f, u, v;
    h = direction.cross(edge2);
    a = edge1.dot(h);
    if (a > -tolerance && a < tolerance)
      return false;
    f = 1.0 / a;
    s = origin - vertex0;
    u = f * s.dot(h);
    if (u < real(0.0) || u > real(1.0))
      return false;
    q = s.cross(edge1);
    v = f * direction.dot(q);
    if (v < real(0.0) || u + v > real(1.0))
      return false;
    float t = f * edge2.dot(q);
    point_out = origin + direction * t;
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      circle const &circle_in,
      point &point_out,
      real tolerance)
  {
    if (intersection(line_in,
                     circle_in.layingPlane(),
                     point_out,
                     tolerance))
    {
      if ((circle_in.center() - point_out).norm() <= circle_in.radius())
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
      ray const &ray_in,
      plane const &plane_in,
      point &point_out,
      real tolerance)
  {
    real det = ray_in.direction().dot(plane_in.normal());
    if (det > tolerance)
    {
      real t = -(ray_in.origin() - plane_in.origin()).dot(plane_in.normal()) / det;
      if (t > tolerance)
      {
        point_out = ray_in.origin() + ray_in.direction() * t;
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
      ray const &ray_in,
      triangle const &triangle_in,
      point &point_out,
      real tolerance)
  {
    point vertex0(triangle_in.vertex(0));
    point vertex1(triangle_in.vertex(1));
    point vertex2(triangle_in.vertex(2));
    vec3 edge1(vertex1 - vertex0);
    vec3 edge2(vertex2 - vertex0);

    point origin(ray_in.origin());
    vec3 direction(ray_in.direction());

    vec3 h, s, q;
    real a, f, u, v;
    h = direction.cross(edge2);
    a = edge1.dot(h);
    if (a > -tolerance && a < tolerance)
      return false;
    f = 1.0 / a;
    s = origin - vertex0;
    u = f * s.dot(h);
    if (u < real(0.0) || u > real(1.0))
      return false;
    q = s.cross(edge1);
    v = f * direction.dot(q);
    if (v < real(0.0) || u + v > real(1.0))
      return false;
    float t = f * edge2.dot(q);
    if (t >= real(0.0))
    {
      point_out = origin + direction * t;
      return true;
    }
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray_in,
      circle const &circle_in,
      point &point_out,
      real tolerance)
  {
    if (intersection(line(ray_in.origin(), ray_in.direction()),
                     circle_in.layingPlane(),
                     point_out,
                     tolerance))
      return ray_in.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane_in,
      segment const &segment_in,
      point &point_out,
      real tolerance)
  {
    real d0 = plane_in.signedDistance(segment_in.vertex(0));
    real d1 = plane_in.signedDistance(segment_in.vertex(1));
    if (isApprox(d0, 0.0, tolerance))
    {
      point_out = segment_in.vertex(0);
      return true;
    }
    else if (isApprox(d1, 0.0, tolerance))
    {
      point_out = segment_in.vertex(1);
      return true;
    }
    else if (d0 * d1 < 0)
    {
      real t = d0 / (d0 - d1);
      point_out = segment_in.vertex(0) + t * (segment_in.vertex(1) - segment_in.vertex(0));
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane_in,
      triangle const &triangle_in,
      segment &segment_out,
      real tolerance)
  {
    line tmp_line;
    if (intersection(plane_in,
                     triangle_in.layingPlane(),
                     tmp_line,
                     tolerance))
      return intersection(tmp_line, triangle_in, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane_in,
      circle const &circle_in,
      segment &segment_out,
      real tolerance)
  {
    line tmp_line;
    if (intersection(plane_in,
                     circle_in.layingPlane(),
                     tmp_line,
                     tolerance))
      return intersection(tmp_line, circle_in, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment_in,
      triangle const &triangle_in,
      point &point_out,
      real tolerance)
  {
    if (intersection(line(segment_in.vertex(0), segment_in.toUnitVector()),
                     triangle_in,
                     point_out,
                     tolerance))
      return segment_in.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment_in,
      circle const &circle_in,
      point &point_out,
      real tolerance)
  {
    if (intersection(line(segment_in.vertex(0), segment_in.toUnitVector()),
                     circle_in,
                     point_out,
                     tolerance))
      return segment_in.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      triangle const &triangle_in,
      circle const &circle_in,
      segment &segment_out,
      real tolerance)
  {
    segment tmp_segment;
    if (intersection(circle_in.layingPlane(),
                     triangle_in,
                     tmp_segment,
                     tolerance))
      return intersection(tmp_segment, circle_in, segment_out, tolerance);
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
      aabb const &aabb0_in,
      aabb const &aabb1_in,
      aabb &aabb_out,
      real tolerance)
  {
    if (!(aabb0_in.intersects(aabb1_in)))
      return false;

    for (size_t i = 0; i < 3; ++i)
    {
      if (aabb0_in.max(i) <= aabb1_in.max(i))
        aabb_out.max(i) = aabb0_in.max(i);
      else
        aabb_out.max(i) = aabb1_in.max(i);
      if (aabb0_in.min(i) <= aabb1_in.min(i))
        aabb_out.min(i) = aabb1_in.min(i);
      else
        aabb_out.min(i) = aabb0_in.min(i);
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_intersection.cc
///