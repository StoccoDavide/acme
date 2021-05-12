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
      entity const *entity0,
      entity const *entity1,
      real tolerance)
  {
    integer slide = entity0->degree() * 100 + entity1->degree();
    bool check = false;
    bool collide = false;
    entity *entity_out = new none();
    bool collide_ray = false;
    bool collide_seg = false;
    entity *entity_out_ray = new ray();
    entity *entity_out_seg = new segment();
    if (entity0->isPoint() || entity1->isPoint())
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - POINT - - - - - - - - - - - - - -

      case 202:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity0),
                                     *dynamic_cast<point const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 203:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity0),
                                     *dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 204:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity0),
                                     *dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 205:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity0),
                                     *dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 206:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 207:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 208:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 302:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity1),
                                     *dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 402:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity1),
                                     *dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 502:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity1),
                                     *dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 602:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity1),
                                     *dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 702:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity1),
                                     *dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 802:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<point const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      default:
        delete entity_out_ray;
        delete entity_out_seg;
        ACME_ERROR("acme::intersection(entity, entity): exception not handled (punctual).")
        entity_out = new none();
        return entity_out;
        break;
      }
    }
    else if (acme::isCollinear(entity0, entity1))
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

      case 303:
        entity_out = new line();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<line *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 304:
        entity_out = new ray();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<ray *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 306:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

      case 403:
        entity_out = new ray();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<ray *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 404:
        collide_ray = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                         *dynamic_cast<ray const *>(entity1),
                                         *dynamic_cast<ray *>(entity_out_ray));

        collide_seg = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                         *dynamic_cast<ray const *>(entity1),
                                         *dynamic_cast<segment *>(entity_out_seg));
        check = true;
        if (collide_ray)
        {
          collide = true;
          delete entity_out_seg;
          entity_out = entity_out_ray;
          return entity_out;
        }
        else if (collide_seg)
        {
          collide = true;
          delete entity_out_ray;
          entity_out = entity_out_seg;
          return entity_out;
        }

        break;

      case 406:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

      case 603:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 604:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 606:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

      default:
        delete entity_out_ray;
        delete entity_out_seg;
        ACME_ERROR("acme::intersection(entity, entity): exception not handled (colliear).")
        entity_out = new none();
        return entity_out;
        break;
      }
    }
    else if (acme::isCoplanar(entity0, entity1))
    {
      switch (slide)
      {

        // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

      case 303:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 304:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 305:
        entity_out = new line();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<line *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 306:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 307:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 308:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

      case 403:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 404:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 405:
        entity_out = new ray();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<ray *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 406:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 407:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 408:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

      case 503:
        entity_out = new line();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<line *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 504:
        entity_out = new ray();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<ray *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 505:
        entity_out = new plane();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<plane *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 506:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 507:
        entity_out = new triangle();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<triangle *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 508:
        entity_out = new circle();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<circle *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

      case 603:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 604:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 605:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 606:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 607:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 608:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

      case 703:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 704:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 705:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 706:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // case 707:
        //   collide = acme::intersection(*dynamic_cast<triangle const *>(entity0),
        //                             *dynamic_cast<triangle const *>(entity1),
        //                             *dynamic_cast<???????? *>(entity_out),
        //                             tolerance);
        //   check = true;
        //   break;

        // case 708:
        //   collide = acme::intersection(*dynamic_cast<triangle const *>(entity0),
        //                             *dynamic_cast<circle const *>(entity1),
        //                             *dynamic_cast<???????? *>(entity_out),
        //                             tolerance);
        //   check = true;
        //   break;

        // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

      case 803:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 804:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 805:
        entity_out = new circle();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<circle *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 806:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // case 807:
        //   collide = acme::intersection(*dynamic_cast<triangle const *>(entity1),
        //                             *dynamic_cast<circle const *>(entity0),
        //                             *dynamic_cast<???????? *>(entity_out),
        //   check = true;
        //   break;

        // case 808:
        //   collide = acme::intersection(*dynamic_cast<circle const *>(entity0),
        //                             *dynamic_cast<circle const *>(entity1),
        //                             *dynamic_cast<<???????? *>(entity_out),
        //   check = true;
        //   break;

        // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

      default:
        delete entity_out_ray;
        delete entity_out_seg;
        ACME_ERROR("acme::intersection(entity, entity): exception not handled (coplanar).")
        entity_out = new none();
        return entity_out;
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
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 304:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 305:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 306:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 307:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 308:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

      case 403:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 404:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 405:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 406:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 407:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 408:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

      case 503:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 504:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 505:
        entity_out = new line();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<line *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 506:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 507:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 508:
        collide = acme::intersection(*dynamic_cast<plane const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

      case 603:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 604:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 605:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 606:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 607:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 608:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

      case 703:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 704:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 705:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 706:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 707:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 708:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<triangle const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - CIRCLE - - - - - - - - - - - - - -

      case 803:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<line const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 804:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<ray const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 805:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<plane const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 806:
        entity_out = new point();
        collide = acme::intersection(*dynamic_cast<segment const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<point *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 807:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<triangle const *>(entity1),
                                     *dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

      case 808:
        entity_out = new segment();
        collide = acme::intersection(*dynamic_cast<circle const *>(entity0),
                                     *dynamic_cast<circle const *>(entity1),
                                     *dynamic_cast<segment *>(entity_out),
                                     tolerance);
        check = true;
        break;

        // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

      default:
        delete entity_out_ray;
        delete entity_out_seg;
        ACME_ERROR("acme::intersection(entity, entity): exception not handled (general).")
        entity_out = new none();
        return entity_out;
        break;
      }
    }
    if (check && collide)
    {
      delete entity_out_ray;
      delete entity_out_seg;
      return entity_out;
    }
    else if (check && !collide)
    {
      delete entity_out_ray;
      delete entity_out_seg;
      entity_out = new none();
      return entity_out;
    }
    else
    {
      ACME_ERROR("acme::intersection(entity, entity): return exception not handled.")
      delete entity_out_ray;
      delete entity_out_seg;
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
      line const &line0,
      line const &line1,
      line &line_out,
      real tolerance)
  {
    if (acme::isCollinear(line0, line1, tolerance))
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
      ray &ray_out,
      real tolerance)
  {
    if (acme::isCollinear(ray0, ray1, tolerance) &&
        ray0.direction().dot(ray1.direction()) > 0)
    {
      if (ray0.isInside(ray1.origin(), tolerance))
      {
        ray_out = ray1;
        return true;
      }
      else if (ray1.isInside(ray0.origin(), tolerance))
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
      segment &segment_out,
      real tolerance)
  {
    if (acme::isCollinear(ray0, ray1, tolerance) &&
        ray0.direction().dot(ray1.direction()) < 0)
    {
      if (ray0.isInside(ray1.origin(), tolerance) &&
          ray1.isInside(ray0.origin(), tolerance))
      {
        segment_out.vertex(0) = ray0.origin();
        segment_out.vertex(1) = ray1.origin();
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
      segment &segment_out,
      real tolerance)
  {
    if (acme::isCollinear(segment0, segment1, tolerance))
    {
      //
      //   p0       p1   p0       p1
      //   o---s0---o    o---s1---o
      //
      point s0_p0(segment0.vertex(0));
      point s0_p1(segment0.vertex(1));
      point s1_p0(segment1.vertex(0));
      point s1_p1(segment1.vertex(1));
      bool s1_p0_in_s0 = segment0.isInside(s1_p0, tolerance);
      bool s1_p1_in_s0 = segment0.isInside(s1_p1, tolerance);
      bool s0_p0_in_s1 = segment1.isInside(s0_p0, tolerance);
      bool s0_p1_in_s1 = segment1.isInside(s0_p1, tolerance);
      //
      //                    Segments coincides
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      1      |      1      |      1      |      1      |
      if (s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s0_p1;
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
        segment_out.vertex(0) = s1_p0;
        segment_out.vertex(1) = s1_p1;
        return true;
      }
      else if (s0_p0_in_s1 && !s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.vertex(0) = s1_p0;
        segment_out.vertex(1) = s1_p1;
        return true;
      }
      else if (s0_p0_in_s1 && s0_p1_in_s1 && !s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s0_p1;
        return true;
      }
      else if (s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && !s1_p1_in_s0)
      {
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s0_p1;
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
        segment_out.vertex(0) = s0_p1;
        segment_out.vertex(1) = s1_p1;
        return true;
      }
      else if (!s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && !s1_p1_in_s0)
      {
        segment_out.vertex(0) = s0_p1;
        segment_out.vertex(1) = s1_p0;
        return true;
      }
      else if (s0_p0_in_s1 && !s0_p1_in_s1 && !s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s1_p1;
        return true;
      }
      else if (s0_p0_in_s1 && !s0_p1_in_s1 && s1_p0_in_s0 && !s1_p1_in_s0)
      {
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s1_p0;
        return true;
      }
      //                 One segment is inside
      // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
      // |      1      |      1      |      0      |      0      |
      // |      0      |      0      |      1      |      1      |
      else if (s0_p0_in_s1 && s0_p1_in_s1 && !s1_p0_in_s0 && !s1_p1_in_s0)
      {
        segment_out.vertex(0) = s0_p0;
        segment_out.vertex(1) = s0_p1;
        return true;
      }
      else if (!s0_p0_in_s1 && !s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
      {
        segment_out.vertex(0) = s1_p0;
        segment_out.vertex(1) = s1_p1;
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
      ray &ray_out,
      real tolerance)
  {
    if (acme::isCollinear(line, ray_in, tolerance))
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
      segment &segment_out,
      real tolerance)
  {
    if (acme::isCollinear(line, segment_in, tolerance))
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
      segment &segment_out,
      real tolerance)
  {
    point point_0(segment_in.vertex(0));
    point point_1(segment_in.vertex(1));
    if (acme::isCollinear(ray, segment_in, tolerance))
    {
      if (ray.isInside(point_0, tolerance) &&
          ray.isInside(point_1, tolerance))
      {
        segment_out = segment_in;
        return true;
      }
      else if (ray.isInside(point_0, tolerance) &&
               !ray.isInside(point_1, tolerance))
      {
        segment_out.vertex(0) = ray.origin();
        segment_out.vertex(1) = point_0;
        return true;
      }
      else if (!ray.isInside(point_0, tolerance) &&
               ray.isInside(point_1, tolerance))
      {
        segment_out.vertex(0) = ray.origin();
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

  bool
  intersection(
      point const &point0,
      point const &point1,
      point &point_out,
      real tolerance)
  {
    if (point0.isApprox(point1, tolerance))
    {
      point_out = point0;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  intersection(
      point const &point_in,
      line const &line,
      point &point_out,
      real tolerance)
  {
    if (line.isInside(point_in, tolerance))
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

  bool
  intersection(
      point const &point_in,
      ray const &ray,
      point &point_out,
      real tolerance)
  {
    if (ray.isInside(point_in, tolerance))
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

  bool
  intersection(
      point const &point_in,
      plane const &plane,
      point &point_out,
      real tolerance)
  {
    if (plane.isInside(point_in, tolerance))
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

  bool
  intersection(
      point const &point_in,
      segment const &segment,
      point &point_out,
      real tolerance)
  {
    if (segment.isInside(point_in, tolerance))
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

  bool
  intersection(
      point const &point_in,
      triangle const &triangle,
      point &point_out,
      real tolerance)
  {
    if (triangle.isInside(point_in, tolerance))
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

  bool
  intersection(
      point const &point_in,
      circle const &circle,
      point &point_out,
      real tolerance)
  {
    if (circle.isInside(point_in, tolerance))
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
      line const &line0,
      line const &line1,
      point &point_out,
      real tolerance)
  {
    // if v and u are parallel (v x u = 0), then no intersection
    // collinearity imply parallelism!
    if (!acme::isCollinear(line0, line1, tolerance))
    {
      point p(line0.origin());
      vec3 v(line0.direction());
      point q(line1.origin());
      vec3 u(line1.direction());
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
      ray const &ray0,
      ray const &ray1,
      point &point_out,
      real tolerance)
  {
    if (acme::intersection(line(ray0.origin(), ray0.direction()),
                           line(ray1.origin(), ray1.direction()),
                           point_out,
                           tolerance))
      return ray0.isInside(point_out, tolerance) &&
             ray1.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment0,
      segment const &segment1,
      point &point_out,
      real tolerance)
  {
    if (acme::intersection(line(segment0.vertex(0), segment0.toNormalizedVector()),
                           line(segment1.vertex(0), segment1.toNormalizedVector()),
                           point_out,
                           tolerance))
      return segment0.isInside(point_out, tolerance) &&
             segment1.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      ray const &ray,
      point &point_out,
      real tolerance)
  {
    if (acme::intersection(line_in,
                           line(ray.origin(), ray.direction()),
                           point_out,
                           tolerance))
      return ray.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      line const &line_in,
      segment const &segment,
      point &point_out,
      real tolerance)
  {
    if (acme::intersection(line_in,
                           line(segment.vertex(0), segment.toNormalizedVector()),
                           point_out,
                           tolerance))
      return segment.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray,
      segment const &segment,
      point &point_out,
      real tolerance)
  {
    if (acme::intersection(line(ray.origin(), ray.direction()),
                           line(segment.vertex(0), segment.toNormalizedVector()),
                           point_out,
                           tolerance))
      return segment.isInside(point_out, tolerance) &&
             ray.isInside(point_out, tolerance);
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
      plane &plane_out,
      real tolerance)
  {
    if (acme::isCoplanar(plane0, plane1, tolerance))
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
      line &line_out,
      real tolerance)
  {
    if (acme::isCoplanar(line_in, plane, tolerance))
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
      segment &segment,
      real tolerance)
  {
    point point0, point1, point2;
    bool bool0, bool1, bool2;
    bool0 = intersection(line, triangle.edge(0, 1), point0, tolerance);
    bool1 = intersection(line, triangle.edge(1, 2), point1, tolerance);
    bool2 = intersection(line, triangle.edge(2, 0), point2, tolerance);

    if (bool0 && bool1 && !bool2)
    {
      segment.vertex(0) = point0;
      segment.vertex(1) = point1;
      return true;
    }
    else if (!bool0 && bool1 && bool2)
    {
      segment.vertex(0) = point1;
      segment.vertex(1) = point2;
      return true;
    }
    else if (bool0 && !bool1 && bool2)
    {
      segment.vertex(0) = point2;
      segment.vertex(1) = point0;
      return true;
    }
    else if (bool0 && bool1 && bool2)
    {
      if (point0.isApprox(point1, tolerance))
      {
        segment.vertex(0) = point1;
        segment.vertex(1) = point2;
        return true;
      }
      else if (point1.isApprox(point2, tolerance))
      {
        segment.vertex(0) = point0;
        segment.vertex(1) = point1;
        return true;
      }
      else if (point0.isApprox(point2, tolerance))
      {
        segment.vertex(0) = point0;
        segment.vertex(1) = point1;
        return true;
      }
      else
      {
        std::cout << "point0 = " << point0 << std::endl;
        std::cout << "point1 = " << point1 << std::endl;
        std::cout << "point2 = " << point2 << std::endl;
        ACME_ERROR("acme::intersection(line, triangle, segment): exception not handled.")
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
      segment &segment,
      real tolerance)
  {
    // Locate one or two points that are on the circle and line.
    // If the line is t&D+P, the circle center is C, and the circle radius is r, then
    // r^2 = |t&D+P-C|^2 = |D|^2&t^2 + 2&Dot(D,P-C)&t + |P-C|^2
    // This is a quadratic equation of the form
    // a2&t^2 + 2&a1&t + a0 = 0.
    real circle_radius = circle.radius();
    point circle_center(circle.center());
    point line_origin(line.origin());
    vec3 line_direction(line.direction());
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
    if (acme::abs(discriminant) < tolerance)
    {
      point int_point(line_origin - (a1 * inv) * line_direction);
      segment.vertex(0) = int_point;
      segment.vertex(1) = int_point;
      return true;
    }

    // Two distinct, real-valued roots, the circle intersects the plane in two points
    real root = std::sqrt(discriminant);
    segment.vertex(0) = line_origin - ((a1 + root) * inv) * line_direction;
    segment.vertex(1) = line_origin - ((a1 - root) * inv) * line_direction;
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray_in,
      plane const &plane,
      ray &ray_out,
      real tolerance)
  {
    if (acme::isCoplanar(ray_in, plane, tolerance))
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
      segment &segment_out,
      real tolerance)
  {
    // Transform ray to line
    line tmp_line(ray.origin(), ray.direction());
    // Compute the intersection of resulting line with the circle
    segment tmp_segment;
    if (acme::intersection(tmp_line, triangle, tmp_segment, tolerance))
      return acme::intersection(ray, tmp_segment, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      ray const &ray,
      circle const &circle,
      segment &segment_out,
      real tolerance)
  {
    // Transform ray to line
    line tmp_line(ray.origin(), ray.direction());
    // Compute the intersection of resulting line with the circle
    segment tmp_segment;
    if (acme::intersection(tmp_line, circle, tmp_segment, tolerance))
      return acme::intersection(ray, tmp_segment, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane,
      segment const &segment_in,
      segment &segment_out,
      real tolerance)
  {
    if (acme::isCoplanar(plane, segment_in, tolerance))
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
      triangle &triangle_out,
      real tolerance)
  {
    if (acme::isCoplanar(plane, triangle_in, tolerance))
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
      circle &circle_out,
      real tolerance)
  {
    if (acme::isCoplanar(plane, circle_in, tolerance))
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
      segment &segment_out,
      real tolerance)
  {
    line tmp_line(segment_in.vertex(0), segment_in.toNormalizedVector());
    segment tmp_segment;
    if (acme::intersection(tmp_line, triangle, tmp_segment, tolerance))
      return acme::intersection(segment_in, tmp_segment, segment_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment_in,
      circle const &circle,
      segment &segment_out,
      real tolerance)
  {
    line tmp_line(segment_in.vertex(0), segment_in.toNormalizedVector());
    segment tmp_segment;
    if (acme::intersection(tmp_line, circle, tmp_segment, tolerance))
      return acme::intersection(segment_in, tmp_segment, segment_out, tolerance);
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
      line &line,
      real tolerance)
  {
    vec3 normal0(plane0.normal().normalized());
    vec3 normal1(plane1.normal().normalized());
    real d0 = -plane0.d();
    real d1 = -plane1.d();

    vec3 direction = normal0.cross(normal1);
    real dot = normal0.dot(normal1);
    if (acme::isApprox(acme::sqr(direction.norm()), real(0.0), tolerance))
    {
      return false;
    }
    else
    {
      real invDet = 1.0 / (1.0 - dot * dot);
      real c0 = (d0 - dot * d1) * invDet;
      real c1 = (d1 - dot * d0) * invDet;
      line.origin(c0 * normal0 + c1 * normal1);
      line.direction(direction);
      return true;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane0,
      plane const &plane1,
      plane const &plane2,
      point &point_out,
      real tolerance)
  {
    vec3 const normal0(plane0.normal());
    vec3 const normal1(plane1.normal());
    vec3 const normal2(plane2.normal());

    mat3 Mat;
    Mat << normal0, normal1, normal2;
    real det = Mat.determinant();
    if (acme::isApprox(det, real(0.0), tolerance))
    {
      return false;
    }
    else
    {
      point_out = (normal1.cross(normal2) * -plane0.d() +
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
      segment &segment_out,
      real tolerance)
  {
    line tmp_line;
    if (acme::intersection(triangle0.layingPlane(), triangle1.layingPlane(), tmp_line, tolerance))
    {
      segment tmp_segment0, tmp_segment1;
      acme::intersection(tmp_line, triangle0, tmp_segment0, tolerance);
      acme::intersection(tmp_line, triangle1, tmp_segment1, tolerance);
      return acme::intersection(tmp_segment0, tmp_segment1, segment_out, tolerance);
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
      segment &segment_out,
      real tolerance)
  {
    line tmp_line;
    if (acme::intersection(circle0.layingPlane(), circle1.layingPlane(), tmp_line, tolerance))
    {
      segment tmp_segment0, tmp_segment1;
      acme::intersection(tmp_line, circle0, tmp_segment0, tolerance);
      acme::intersection(tmp_line, circle1, tmp_segment1, tolerance);
      return acme::intersection(tmp_segment0, tmp_segment1, segment_out, tolerance);
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
      point &point_out,
      real tolerance)
  {
    real det = line.direction().dot(plane.normal());
    if (det > tolerance)
    {
      real t = -(line.origin() - plane.origin()).dot(plane.normal()) / det;
      point_out = line.origin() + line.direction() * t;
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
      point &point_out,
      real tolerance)
  {
    point vertex0 = triangle.vertex(0);
    point vertex1 = triangle.vertex(1);
    point vertex2 = triangle.vertex(2);
    vec3 edge1 = vertex1 - vertex0;
    vec3 edge2 = vertex2 - vertex0;

    point origin = line.origin();
    vec3 direction = line.direction();

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
      line const &line,
      circle const &circle,
      point &point_out,
      real tolerance)
  {
    if (acme::intersection(line, circle.layingPlane(), point_out, tolerance))
    {
      if ((circle.center() - point_out).norm() <= circle.radius())
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
      point &point_out,
      real tolerance)
  {
    real det = ray.direction().dot(plane.normal());
    if (det > tolerance)
    {
      real t = -(ray.origin() - plane.origin()).dot(plane.normal()) / det;
      if (t > tolerance)
      {
        point_out = ray.origin() + ray.direction() * t;
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
      point &point_out,
      real tolerance)
  {
    point vertex0(triangle.vertex(0));
    point vertex1(triangle.vertex(1));
    point vertex2(triangle.vertex(2));
    vec3 edge1(vertex1 - vertex0);
    vec3 edge2(vertex2 - vertex0);

    point origin(ray.origin());
    vec3 direction(ray.direction());

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
      ray const &ray,
      circle const &circle,
      point &point_out,
      real tolerance)
  {
    if (acme::intersection(line(ray.origin(), ray.direction()), circle.layingPlane(), point_out, tolerance))
      return ray.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane,
      segment const &segment,
      point &point_out,
      real tolerance)
  {
    real d0 = plane.signedDistance(segment.vertex(0));
    real d1 = plane.signedDistance(segment.vertex(1));
    if (acme::isApprox(d0, real(0.0), tolerance))
    {
      point_out = segment.vertex(0);
      return true;
    }
    else if (acme::isApprox(d1, real(0.0), tolerance))
    {
      point_out = segment.vertex(1);
      return true;
    }
    else if (d0 * d1 < 0)
    {
      real t = d0 / (d0 - d1);
      point_out = segment.vertex(0) + t * (segment.vertex(1) - segment.vertex(0));
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
      segment &segment,
      real tolerance)
  {
    line tmp_line;
    if (acme::intersection(plane, triangle.layingPlane(), tmp_line, tolerance))
      return acme::intersection(tmp_line, triangle, segment, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      plane const &plane,
      circle const &circle,
      segment &segment,
      real tolerance)
  {
    line tmp_line;
    if (acme::intersection(plane, circle.layingPlane(), tmp_line, tolerance))
      return acme::intersection(tmp_line, circle, segment, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment,
      triangle const &triangle,
      point &point_out,
      real tolerance)
  {
    if (acme::intersection(line(segment.vertex(0), segment.toNormalizedVector()), triangle, point_out, tolerance))
      return segment.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      segment const &segment,
      circle const &circle,
      point &point_out,
      real tolerance)
  {
    if (acme::intersection(line(segment.vertex(0), segment.toNormalizedVector()), circle, point_out, tolerance))
      return segment.isInside(point_out, tolerance);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersection(
      triangle const &triangle,
      circle const &circle,
      segment &segment_out,
      real tolerance)
  {
    segment tmp_segment;
    if (acme::intersection(circle.layingPlane(), triangle, tmp_segment, tolerance))
      return acme::intersection(tmp_segment, circle, segment_out, tolerance);
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
      aabb const &box0,
      aabb const &box1,
      aabb &aabb,
      real tolerance)
  {
    if (!(box0.intersects(box1)))
      return false;

    for (integer i = 0; i < 3; ++i)
    {
      if (box0.max(i) <= box1.max(i))
        aabb.max(i, box0.max(i));
      else
        aabb.max(i, box1.max(i));
      if (box0.min(i) <= box1.min(i))
        aabb.min(i, box1.min(i));
      else
        aabb.min(i, box0.min(i));
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_intersection.cc
///