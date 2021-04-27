/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project - Release Version 0.0.0                            *)
(*                                                                     *)
(* Copyright (c) 2020 Davide Stocco, All Rights Reserved.              *)
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
      line const &line0,
      line const &line1,
      real_type tolerance)
  {
    return acme::isParallel(line0.origin() - line1.origin(), line0.direction(), tolerance) &&
           acme::isParallel(line0.direction(), line1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      ray const &ray0,
      ray const &ray1,
      real_type tolerance)
  {
    return acme::isParallel(ray0.origin() - ray1.origin(), ray0.direction(), tolerance) &&
           acme::isParallel(ray1.direction(), ray1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      segment const &segment0,
      segment const &segment1,
      real_type tolerance)
  {
    return acme::isParallel(segment0.point(0) - segment1.point(0), segment0.toNormalizedVector(), tolerance) &&
           acme::isParallel(segment0.toNormalizedVector(), segment1.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      line const &line,
      ray const &ray,
      real_type tolerance)
  {
    return acme::isParallel(line.origin() - ray.origin(), line.direction(), tolerance) &&
           acme::isParallel(line.direction(), ray.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      line const &line,
      segment const &segment,
      real_type tolerance)
  {
    return acme::isParallel(line.origin() - segment.point(0), line.direction(), tolerance) &&
           acme::isParallel(line.direction(), segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      ray const &ray,
      segment const &segment,
      real_type tolerance)
  {
    return acme::isParallel(ray.origin() - segment.point(0), ray.direction(), tolerance) &&
           acme::isParallel(ray.direction(), segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_collinear.cc
///