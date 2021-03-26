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
/// file: acme_segment.cc
///

#include "acme_segment.hh"

namespace acme
{

  /*\
   |                                       _   
   |   ___  ___  __ _ _ __ ___   ___ _ __ | |_ 
   |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __|
   |  \__ \  __/ (_| | | | | | |  __/ | | | |_ 
   |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|
   |            |___/                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment::segment(
      real_type const x0, real_type const y0, real_type const z0,
      real_type const x1, real_type const y1, real_type const z1)
  {
    this->_point[0] = vec3(x0, y0, z0);
    this->_point[1] = vec3(x1, y1, z1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment::segment(
      vec3 const &point0,
      vec3 const &point1)
  {
    this->_point[0] = point0;
    this->_point[1] = point1;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment &segment::operator=(
      segment const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_point[0] = input._point[0];
      this->_point[1] = input._point[1];
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool segment::is_equal(
      segment const &input)
      const
  {
    return acme::is_equal(this->_point[0], input._point[0]) &&
           acme::is_equal(this->_point[1], input._point[1]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool segment::is_degenerated(void)
      const
  {
    return acme::is_equal((this->_point[0] - this->_point[1]).norm(), real_type(0.0));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &segment::point_0(void) const { return this->_point[0]; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void segment::point_0(
      vec3 const &input)
  {
    this->_point[0] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &segment::point_1(void) const { return this->_point[1]; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void segment::point_1(
      vec3 const &input)
  {
    this->_point[1] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &segment::point(
      int_type const &i) const
  {
    return this->_point[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void segment::point(
      int_type const &i,
      vec3 const &input)
  {
    this->_point[i] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void segment::points(
      vec3 const &input0,
      vec3 const &input1)
  {
    this->_point[0] = input0;
    this->_point[1] = input1;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 segment::to_vector(void) const
  {
    return vec3(this->_point[1] - this->_point[0]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 segment::to_normalized_vector(void) const
  {
    return vec3((this->_point[1] - this->_point[0]).normalized());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void segment::translate(
      vec3 const &input)
  {
    this->_point[0] = input + this->_point[0];
    this->_point[1] = input + this->_point[1];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void segment::rotate(
      mat3 const &input)
  {
    this->_point[0] = input * this->_point[0];
    this->_point[1] = input * this->_point[1];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment segment::transform(
      frame const &frameA,
      frame const &frameB) const
  {
    return segment(acme::transform_point(this->_point[0], frameA, frameB),
                   acme::transform_point(this->_point[1], frameA, frameB));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void segment::swap(void)
  {
    vec3 tmp_point_0(this->_point[0]);
    vec3 tmp_point_1(this->_point[1]);
    this->_point[0] = tmp_point_1;
    this->_point[1] = tmp_point_0;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type segment::length(void) const
  {
    return (this->_point[0] - this->_point[1]).norm();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool segment::is_inside(
      vec3 const &point)
      const
  {
    real_type d0 = this->length();
    real_type d1 = (point - this->_point[0]).norm();
    real_type d2 = (point - this->_point[1]).norm();
    return acme::abs(d0 - d1 - d2) <= acme::Epsilon;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_segment.cc
///