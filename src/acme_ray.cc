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
/// file: acme_ray.ccc
///

#include "acme_ray.hh"

namespace acme
{

  /*\
   |                   
   |   _ __ __ _ _   _ 
   |  | '__/ _` | | | |
   |  | | | (_| | |_| |
   |  |_|  \__,_|\__, |
   |             |___/ 
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ray &
  ray::operator=(
      ray const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_origin = input._origin;
      this->_direction = input._direction;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  ray::is_equal(
      ray const &input)
      const
  {
    return acme::is_equal(this->_origin, input._origin) &&
           acme::is_equal(this->_direction, input._direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  ray::is_degenerated(void)
      const
  {
    return acme::is_degenerated(this->_direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  ray::origin()
      const
  {
    return this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  ray::direction()
      const
  {
    return this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  ray::origin(
      vec3 const &input)
  {
    this->_origin = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  ray::direction(
      vec3 const &input)
  {
    this->_direction = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  ray::normalize_direction(void)
  {
    this->_direction.normalize();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  ray::to_vector(void)
      const
  {
    return this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  ray::to_normalized_vector(void)
      const
  {
    return this->_direction.normalized();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  ray::translate(
      vec3 const &input)
  {
    this->_origin = input + this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ray ray::translated(
      vec3 const &input)
      const
  {
    return ray(input + this->_origin,
               this->_direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  ray::rotate(
      mat3 const &input)
  {
    this->_origin = input * this->_origin;
    this->_direction = input * this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ray ray::rotated(
      mat3 const &input)
      const
  {
    return ray(input * this->_origin,
               input * this->_direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  ray::transform(
      frame const &from_frame,
      frame const &to_frame)
  {
    this->_origin = acme::transform_point(this->_origin, from_frame, to_frame);
    this->_direction = acme::transform_vector(this->_direction, from_frame, to_frame);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ray ray::transformed(
      frame const &from_frame,
      frame const &to_frame)
      const
  {
    return ray(acme::transform_point(this->_origin, from_frame, to_frame),
               acme::transform_vector(this->_direction, from_frame, to_frame));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  ray::reverse(void)
  {
    this->_direction = -this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ray ray::reversed(void)
      const
  {
    return ray(this->_origin, -this->_direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  ray::is_inside(
      vec3 const &point)
      const
  {
    return (point - this->_origin).normalized().cross(this->_direction).norm() <= acme::Epsilon;
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_ray.cc
///