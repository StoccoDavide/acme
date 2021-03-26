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
/// file: acme_circle.cc
///

#include "acme_circle.hh"

namespace acme
{

  /*\
   |        _          _      
   |    ___(_)_ __ ___| | ___ 
   |   / __| | '__/ __| |/ _ \
   |  | (__| | | | (__| |  __/
   |   \___|_|_|  \___|_|\___|
   |                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  circle &circle::operator=(
      circle const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_radius = input._radius;
      this->_plane = input._plane;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool circle::is_equal(
      circle const &input)
      const
  {
    return acme::is_equal(this->_radius, input._radius) &&
           acme::is_equal(this->_plane.origin(), input._plane.origin()) &&
           acme::is_equal(this->_plane.normal(), input._plane.normal());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool circle::is_degenerated(void)
      const
  {
    return acme::is_equal(this->_radius, 0.0);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type circle::radius() const
  {
    return this->_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &circle::center() const
  {
    return this->_plane.origin();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &circle::normal() const
  {
    return this->_plane.normal();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  plane const &circle::laying_plane() const
  {
    return this->_plane;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void circle::radius(
      real_type const input)
  {
    this->_radius = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void circle::center(
      vec3 const &input)
  {
    this->_plane.origin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void circle::normal(
      vec3 const &input)
  {
    this->_plane.normal(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void circle::laying_plane(
      plane const &input)
  {
    this->_plane = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void circle::translate(
      vec3 const &input)
  {
    this->_plane.translate(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void circle::rotate(
      mat3 const &input)
  {
    this->_plane.rotate(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  circle circle::transform(
      frame const &frameA,
      frame const &frameB) const
  {
    return circle(this->_radius, this->_plane.transform(frameA, frameB));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void circle::reverse(void) { this->_plane.reverse(); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  circle circle::reversed(void) const
  {
    return circle(this->_radius, this->_plane.reversed());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool circle::is_inside(
      vec3 const &point)
      const
  {

    return this->_plane.is_inside(point) && (this->_plane.origin() - point).norm() <= this->_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_circle.cc
///