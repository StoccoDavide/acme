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
/// file: acme_point.cc
///

#include "acme_point.hh"

namespace acme
{

  /*\
   |               _       _   
   |   _ __   ___ (_)_ __ | |_ 
   |  | '_ \ / _ \| | '_ \| __|
   |  | |_) | (_) | | | | | |_ 
   |  | .__/ \___/|_|_| |_|\__|
   |  |_|                      
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  point::clamp(
      acme::vec3 &min,
      acme::vec3 &max)
      const
  {
    min = *this;
    max = *this;
    return this->isClampable();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  point::clamp(
      acme::real &min_x,
      acme::real &min_y,
      acme::real &min_z,
      acme::real &max_x,
      acme::real &max_y,
      acme::real &max_z)
      const
  {
    min_x = this->x();
    min_y = this->y();
    min_z = this->z();
    max_x = this->x();
    max_y = this->y();
    max_z = this->z();
    return this->isClampable();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_point.cc
///