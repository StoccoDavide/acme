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
    return line0.direction().isParallel(line0.origin() - line1.origin(), tolerance) &&
           line0.direction().isParallel(line1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      ray const &ray0,
      ray const &ray1,
      real_type tolerance)
  {
    return ray0.direction().isParallel(ray0.origin() - ray1.origin(), tolerance) &&
           ray1.direction().isParallel(ray1.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      segment const &segment0,
      segment const &segment1,
      real_type tolerance)
  {
    return segment0.toNormalizedVector().isParallel(segment0.point(0) - segment1.point(0), tolerance) &&
           segment0.toNormalizedVector().isParallel(segment1.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      line const &line,
      ray const &ray,
      real_type tolerance)
  {
    return line.direction().isParallel(line.origin() - ray.origin(), tolerance) &&
           line.direction().isParallel(ray.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      line const &line,
      segment const &segment,
      real_type tolerance)
  {
    return line.direction().isParallel(line.origin() - segment.point(0), tolerance) &&
           line.direction().isParallel(segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isCollinear(
      ray const &ray,
      segment const &segment,
      real_type tolerance)
  {
    return ray.direction().isParallel(ray.origin() - segment.point(0), tolerance) &&
           ray.direction().isParallel(segment.toNormalizedVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_collinear.cc
///