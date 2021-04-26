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
      real_type x0, real_type y0, real_type z0,
      real_type x1, real_type y1, real_type z1,
      real_type x2, real_type y2, real_type z2)
  {
    this->_vertex[0] = vec3(x0, y0, z0);
    this->_vertex[1] = vec3(x1, y1, z1);
    this->_vertex[2] = vec3(x2, y2, z2);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle::triangle(
      vec3 const &point0,
      vec3 const &point1,
      vec3 const &point2)
  {
    this->_vertex[0] = point0;
    this->_vertex[1] = point1;
    this->_vertex[2] = point2;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle::triangle(
      vec3 const point[3])
  {
    this->_vertex[0] = point[0];
    this->_vertex[1] = point[1];
    this->_vertex[2] = point[2];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle &
  triangle::operator=(
      triangle const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_vertex[0] = input._vertex[0];
      this->_vertex[1] = input._vertex[1];
      this->_vertex[2] = input._vertex[2];
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  triangle::isApprox(
      triangle const &input)
      const
  {
    return this->_vertex[0].isApprox(input._vertex[0]) &&
           this->_vertex[1].isApprox(input._vertex[1]) &&
           this->_vertex[2].isApprox(input._vertex[2]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  triangle::isDegenerated(void)
      const
  {
    return acme::isApprox((this->_vertex[0] - this->_vertex[1]).norm(), real_type(0.0)) ||
           acme::isApprox((this->_vertex[1] - this->_vertex[2]).norm(), real_type(0.0)) ||
           acme::isApprox((this->_vertex[2] - this->_vertex[0]).norm(), real_type(0.0));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  triangle::vertex(
      size_t i)
      const
  {
    return this->_vertex[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 &
  triangle::vertex(
      size_t i)
  {
    return this->_vertex[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::vertices(
      vec3 const &vertex0,
      vec3 const &vertex1,
      vec3 const &vertex2)
  {
    this->_vertex[0] = vertex0;
    this->_vertex[1] = vertex1;
    this->_vertex[2] = vertex2;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::vertices(
      vec3 const vertex[3])
  {
    this->_vertex[0] = vertex[0];
    this->_vertex[1] = vertex[1];
    this->_vertex[2] = vertex[2];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment
  triangle::edge(
      size_t i,
      size_t j)
      const
  {
    return segment(this->_vertex[i], this->_vertex[j]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  triangle::normal(void)
      const
  {
    return (this->_vertex[1] - this->_vertex[0]).cross(this->_vertex[2] - this->_vertex[0]).normalized();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::translate(
      vec3 const &input)
  {
    this->_vertex[0] = input + this->_vertex[0];
    this->_vertex[1] = input + this->_vertex[1];
    this->_vertex[2] = input + this->_vertex[2];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::transform(
      affine const &matrix)
  {
    acme::transformPoint(this->_vertex[0], matrix);
    acme::transformPoint(this->_vertex[1], matrix);
    acme::transformPoint(this->_vertex[2], matrix);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::swap(
      size_t i,
      size_t j)
  {
    vec3 tmp_vertex_i(this->_vertex[i]);
    vec3 tmp_vertex_j(this->_vertex[j]);
    this->_vertex[i] = tmp_vertex_j;
    this->_vertex[j] = tmp_vertex_i;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::clamp(
      box &input)
      const
  {
    input.minX(acme::min(this->_vertex[0].x(), this->_vertex[1].x(), this->_vertex[2].x()));
    input.minY(acme::min(this->_vertex[0].y(), this->_vertex[1].y(), this->_vertex[2].y()));
    input.minZ(acme::min(this->_vertex[0].z(), this->_vertex[1].z(), this->_vertex[2].z()));
    input.maxX(acme::max(this->_vertex[0].x(), this->_vertex[1].x(), this->_vertex[2].x()));
    input.maxY(acme::max(this->_vertex[0].y(), this->_vertex[1].y(), this->_vertex[2].y()));
    input.maxZ(acme::max(this->_vertex[0].z(), this->_vertex[1].z(), this->_vertex[2].z()));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  triangle::perimeter(void)
      const
  {
    return (this->_vertex[0] - this->_vertex[1]).norm() +
           (this->_vertex[1] - this->_vertex[2]).norm() +
           (this->_vertex[2] - this->_vertex[0]).norm();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  triangle::area(void)
      const
  {
    return 0.5 * ((this->_vertex[1] - this->_vertex[0]).cross(this->_vertex[2] - this->_vertex[0])).norm();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  triangle::isInside(
      vec3 const &point)
      const
  {
    real_type u, v, w;
    this->barycentric(point, u, v, w);
    if ((u >= real_type(0.0) && u <= real_type(1.0)) &&
        (v >= real_type(0.0) && v <= real_type(1.0)) &&
        (w >= real_type(0.0) && w <= real_type(1.0)))
      return true;
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::barycentric(
      vec3 const &point,
      real_type &u,
      real_type &v,
      real_type &w)
      const
  {
    vec3 v0(this->_vertex[1] - this->_vertex[0]);
    vec3 v1(this->_vertex[2] - this->_vertex[0]);
    vec3 v2(point - this->_vertex[0]);
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
