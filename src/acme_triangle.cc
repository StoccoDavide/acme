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
/// file: acme_triangle.cc
///

#include "acme_triangle.hh"

namespace acme
{

  /*\
   |   _        _                   _      
   |  | |_ _ __(_) __ _ _ __   __ _| | ___ 
   |  | __| '__| |/ _` | '_ \ / _` | |/ _ \
   |  | |_| |  | | (_| | | | | (_| | |  __/
   |   \__|_|  |_|\__,_|_| |_|\__, |_|\___|
   |                          |___/        
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle::triangle(
      real_type const x0, real_type const y0, real_type const z0,
      real_type const x1, real_type const y1, real_type const z1,
      real_type const x2, real_type const y2, real_type const z2)
  {
    this->_point[0] = vec3(x0, y0, z0);
    this->_point[1] = vec3(x1, y1, z1);
    this->_point[2] = vec3(x2, y2, z2);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle::triangle(
      vec3 const &point0,
      vec3 const &point1,
      vec3 const &point2)
  {
    this->_point[0] = point0;
    this->_point[1] = point1;
    this->_point[2] = point2;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle::triangle(
      vec3 const point[3])
  {
    this->_point[0] = point[0];
    this->_point[1] = point[1];
    this->_point[2] = point[2];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle &triangle::operator=(
      triangle const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_point[0] = input._point[0];
      this->_point[1] = input._point[1];
      this->_point[2] = input._point[2];
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool triangle::is_equal(
      triangle const &input)
      const
  {
    return acme::is_equal(this->_point[0], input._point[0]) &&
           acme::is_equal(this->_point[1], input._point[1]) &&
           acme::is_equal(this->_point[2], input._point[2]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool triangle::is_degenerated(void)
      const
  {
    return acme::is_equal((this->_point[0] - this->_point[1]).norm(), 0.0) ||
           acme::is_equal((this->_point[1] - this->_point[2]).norm(), 0.0) ||
           acme::is_equal((this->_point[2] - this->_point[0]).norm(), 0.0);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &triangle::vertex_0(void) const { return this->_point[0]; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::vertex_0(
      vec3 const &input)
  {
    this->_point[0] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &triangle::vertex_1(void) const { return this->_point[1]; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::vertex_1(
      vec3 const &input)
  {
    this->_point[1] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &triangle::vertex_2(void) const { return this->_point[2]; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::vertex_2(
      vec3 const &input)
  {
    this->_point[2] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &triangle::vertex(
      int_type const &i) const
  {
    return this->_point[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::vertex(
      int_type const &i,
      vec3 const &input)
  {
    this->_point[i] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::vertices(
      vec3 const &input0,
      vec3 const &input1,
      vec3 const &input2)
  {
    this->_point[0] = input0;
    this->_point[1] = input1;
    this->_point[2] = input2;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment const triangle::edge_0(void)
      const
  {
    return segment(this->_point[0], this->_point[1]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment const triangle::edge_1(void)
      const
  {
    return segment(this->_point[1], this->_point[2]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment const triangle::edge_2(void)
      const
  {
    return segment(this->_point[2], this->_point[0]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const triangle::normal(void)
      const
  {
    return (this->_point[1] - this->_point[0]).cross(this->_point[2] - this->_point[0]).normalized();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::translate(
      vec3 const &input)
  {
    this->_point[0] = input + this->_point[0];
    this->_point[1] = input + this->_point[1];
    this->_point[2] = input + this->_point[2];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::rotate(
      mat3 const &input)
  {
    this->_point[0] = input * this->_point[0];
    this->_point[1] = input * this->_point[1];
    this->_point[2] = input * this->_point[2];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle triangle::transform(
      frame const &frameA,
      frame const &frameB) const
  {
    return triangle(acme::transform_point(this->_point[0], frameA, frameB),
                    acme::transform_point(this->_point[1], frameA, frameB),
                    acme::transform_point(this->_point[2], frameA, frameB));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::swap(
      int_type const i,
      int_type const j)
  {
    vec3 tmp_point_i(this->_point[i]);
    vec3 tmp_point_j(this->_point[j]);
    this->_point[i] = tmp_point_j;
    this->_point[j] = tmp_point_i;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::min_box(
      box &input)
      const
  {
    input.x_min(acme::min(this->_point[0].x(), this->_point[1].x(), this->_point[2].x()));
    input.y_min(acme::min(this->_point[0].y(), this->_point[1].y(), this->_point[2].y()));
    input.z_min(acme::min(this->_point[0].z(), this->_point[1].z(), this->_point[2].z()));
    input.x_max(acme::max(this->_point[0].x(), this->_point[1].x(), this->_point[2].x()));
    input.y_max(acme::max(this->_point[0].y(), this->_point[1].y(), this->_point[2].y()));
    input.z_max(acme::max(this->_point[0].z(), this->_point[1].z(), this->_point[2].z()));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type triangle::perimeter(void) const
  {
    return (this->_point[0] - this->_point[1]).norm() +
           (this->_point[1] - this->_point[2]).norm() +
           (this->_point[2] - this->_point[0]).norm();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type triangle::area(void) const
  {
    return 0.5 * ((this->_point[1] - this->_point[0]).cross(this->_point[2] - this->_point[0])).norm();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool triangle::is_inside(
      vec3 const &point)
      const
  {
    real_type u, v, w;
    this->barycentric(point, u, v, w);
    if ((u >= 0.0 && u <= 1.0) &&
        (v >= 0.0 && v <= 1.0) &&
        (w >= 0.0 && w <= 1.0))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void triangle::barycentric(
      vec3 const &point,
      real_type &u,
      real_type &v,
      real_type &w)
      const
  {
    vec3 v0(this->_point[1] - this->_point[0]);
    vec3 v1(this->_point[2] - this->_point[0]);
    vec3 v2(point - this->_point[0]);
    real_type d00 = v0.dot(v0);
    real_type d01 = v0.dot(v1);
    real_type d11 = v1.dot(v1);
    real_type d20 = v2.dot(v0);
    real_type d21 = v2.dot(v1);
    real_type denom = d00 * d11 - d01 * d01;
    v = (d11 * d20 - d01 * d21) / denom;
    w = (d00 * d21 - d01 * d20) / denom;
    u = 1.0 - v - w;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_triangle.cc
///
