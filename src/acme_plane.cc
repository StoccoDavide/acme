/*
(***********************************************************************)
(*                                                                     *)
(* The ACME computational geometry library                             *)
(* Release Version 0.0.0                                               *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The ACME computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the ACME computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_plane.cc
///

#include "acme_plane.hh"

namespace acme
{

  /*\
   |         _                  
   |   _ __ | | __ _ _ __   ___ 
   |  | '_ \| |/ _` | '_ \ / _ \
   |  | |_) | | (_| | | | |  __/
   |  | .__/|_|\__,_|_| |_|\___|
   |  |_|                       
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  plane &plane::operator=(
      plane const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_origin = input._origin;
      this->_normal = input._normal;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool plane::is_equal(
      plane const &input)
      const
  {
    return acme::is_equal(this->_origin, input._origin) &&
           acme::is_equal(this->_normal, input._normal);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool plane::is_degenerated(void)
      const
  {
    return acme::is_degenerated(this->_normal);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &plane::origin() const
  {
    return this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &plane::normal() const
  {
    return this->_normal;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void plane::origin(
      vec3 const &input)
  {
    this->_origin = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void plane::normal(
      vec3 const &input)
  {
    this->_normal = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void plane::translate(
      vec3 const &input)
  {
    this->_origin = input + this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void plane::rotate(
      mat3 const &input)
  {
    this->_origin = input * this->_origin;
    this->_normal = input * this->_normal;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  plane plane::transform(
      frame const &frameA,
      frame const &frameB) const
  {
    return plane(acme::transform_point(this->_origin, frameA, frameB),
                 acme::transform_vector(this->_normal, frameA, frameB));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void plane::reverse(void) { this->_normal = -this->_normal; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  plane plane::reversed(void) const
  {
    return plane(this->_origin, -this->_normal);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type plane::d(void) const { return -this->_origin.dot(this->_normal); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type plane::distance(
      vec3 const &input)
      const
  {
    return (input - this->_origin).dot(this->_normal);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool plane::is_inside(
      vec3 const &point)
      const
  {
    return this->distance(point) < acme::Epsilon;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_plane.cc
///