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
/// file: acme_line.cc
///

#include "acme_line.hh"

namespace acme
{

  /*\
   |   _ _            
   |  | (_)_ __   ___ 
   |  | | | '_ \ / _ \
   |  | | | | | |  __/
   |  |_|_|_| |_|\___|
   |                  
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  line &
  line::operator=(
      line const &input)
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
  line::is_equal(
      line const &input)
      const
  {
    return acme::is_equal(this->_origin, input._origin) &&
           acme::is_equal(this->_direction, input._direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::is_degenerated(void)
      const
  {
    return acme::is_degenerated(this->_direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  line::origin(void)
      const
  {
    return this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  line::direction(void)
      const
  {
    return this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::origin(
      vec3 const &input)
  {
    this->_origin = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::direction(
      vec3 const &input)
  {
    this->_direction = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::normalize_direction(void)
  {
    this->_direction.normalize();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  line::to_vector(void)
      const
  {
    return this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  line::to_normalized_vector(void)
      const
  {
    return this->_direction.normalized();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::translate(
      vec3 const &input)
  {
    this->_origin = input + this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  line
  line::translated(
      vec3 const &input)
      const
  {
    return line(input + this->_origin,
                this->_direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::rotate(
      mat3 const &input)
  {
    this->_origin = input * this->_origin;
    this->_direction = input * this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  line
  line::rotated(
      mat3 const &input)
      const
  {
    return line(input * this->_origin,
                input * this->_direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::transform(
      frame const &from_frame,
      frame const &to_frame)
  {
    this->_origin = acme::transform_point(this->_origin, from_frame, to_frame);
    this->_direction = acme::transform_vector(this->_direction, from_frame, to_frame);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  line
  line::transformed(
      frame const &from_frame,
      frame const &to_frame)
      const
  {
    return line(acme::transform_point(this->_origin, from_frame, to_frame),
                acme::transform_vector(this->_direction, from_frame, to_frame));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::reverse(void)
  {
    this->_direction = -this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  line
  line::reversed(void)
      const
  {
    return line(this->_origin, -this->_direction);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::is_inside(
      vec3 const &point)
      const
  {
    return (point - this->_origin).normalized().cross(this->_direction).norm() <= acme::Epsilon;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::intersect(
      line const &line,
      vec3 &point)
      const
  {
    return acme::intersect(*this, line, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::intersect(
      plane const &plane,
      vec3 &point)
      const
  {
    return acme::intersect(*this, plane, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::intersect(
      triangle const &triangle,
      vec3 &point)
      const
  {
    return acme::intersect(*this, triangle, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::intersect(
      circle const &circle,
      vec3 &point)
      const
  {
    return acme::intersect(*this, circle, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::intersect(
      segment const &segment_in,
      segment &segment_out)
      const
  {
    return acme::intersect(*this, segment_in, segment_out);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::intersect(
      circle const &circle,
      segment &segment)
      const
  {
    return acme::intersect(*this, circle, segment);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_line.cc
///