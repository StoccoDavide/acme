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
/// file: acme_collinear.hh
///

#ifndef INCLUDE_ACME_COLLINEAR
#define INCLUDE_ACME_COLLINEAR

#include "acme.hh"
#include "acme_line.hh"
#include "acme_parallel.hh"
#include "acme_ray.hh"
#include "acme_segment.hh"

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

  //! Check if entitys are collinear
  bool
  isCollinear(
      entity const *entity0,   //!< Input entity 0
      entity const *entity1,   //!< Input entity 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if lines are collinear
  bool
  isCollinear(
      line const &line0,       //!< Input line 0
      line const &line1,       //!< Input line 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if rays are collinear
  bool
  isCollinear(
      ray const &ray0,         //!< Input ray 0
      ray const &ray1,         //!< Input ray 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if segments are collinear
  bool
  isCollinear(
      segment const &segment0, //!< Input segment 0
      segment const &segment1, //!< Input segment 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and ray are collinear
  bool
  isCollinear(
      line const &line,        //!< Input line
      ray const &ray,          //!< Input ray
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if line and segment are collinear
  bool
  isCollinear(
      line const &line,        //!< Input line
      segment const &segment,  //!< Input segment
      real tolerance = Epsilon //!< Tolerance
  );

  //! Check if ray and segment are collinear
  bool
  isCollinear(
      ray const &ray,          //!< Input ray
      segment const &segment,  //!< Input segment
      real tolerance = Epsilon //!< Tolerance
  );

} // namespace acme

#endif

///
/// eof: acme_collinear.hh
///