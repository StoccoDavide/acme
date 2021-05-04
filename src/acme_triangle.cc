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
      real x0, real y0, real z0,
      real x1, real y1, real z1,
      real x2, real y2, real z2)
  {
    this->_vertex[0] = point(x0, y0, z0);
    this->_vertex[1] = point(x1, y1, z1);
    this->_vertex[2] = point(x2, y2, z2);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle::triangle(
      point const &point0,
      point const &point1,
      point const &point2)
  {
    this->_vertex[0] = point0;
    this->_vertex[1] = point1;
    this->_vertex[2] = point2;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  triangle::triangle(
      point const point[3])
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
    return this->_vertex[0].isApprox(input._vertex[0], acme::Epsilon) &&
           this->_vertex[1].isApprox(input._vertex[1], acme::Epsilon) &&
           this->_vertex[2].isApprox(input._vertex[2], acme::Epsilon);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point const &
  triangle::vertex(
      integer i)
      const
  {
    return this->_vertex[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point &
  triangle::vertex(
      integer i)
  {
    return this->_vertex[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::vertices(
      point const &vertex0,
      point const &vertex1,
      point const &vertex2)
  {
    this->_vertex[0] = vertex0;
    this->_vertex[1] = vertex1;
    this->_vertex[2] = vertex2;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::vertices(
      point const vertex[3])
  {
    this->_vertex[0] = vertex[0];
    this->_vertex[1] = vertex[1];
    this->_vertex[2] = vertex[2];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point
  triangle::centroid(void)
      const
  {
    return (this->_vertex[0] + this->_vertex[1] + this->_vertex[2]) / 3.0;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment
  triangle::edge(
      integer i,
      integer j)
      const
  {
    return segment(this->_vertex[i], this->_vertex[j]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vector
  triangle::normal(void)
      const
  {
    return (this->_vertex[1] - this->_vertex[0]).cross(this->_vertex[2] - this->_vertex[0]).normalized();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::swap(
      integer i,
      integer j)
  {
    point tmp_vertex_i(this->_vertex[i]);
    point tmp_vertex_j(this->_vertex[j]);
    this->_vertex[i] = tmp_vertex_j;
    this->_vertex[j] = tmp_vertex_i;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::clamp(
      aabb &input)
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

  real
  triangle::perimeter(void)
      const
  {
    return (this->_vertex[0] - this->_vertex[1]).norm() +
           (this->_vertex[1] - this->_vertex[2]).norm() +
           (this->_vertex[2] - this->_vertex[0]).norm();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  triangle::area(void)
      const
  {
    return 0.5 * ((this->_vertex[1] - this->_vertex[0]).cross(this->_vertex[2] - this->_vertex[0])).norm();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::barycentric(
      point const &query_point,
      real &u,
      real &v,
      real &w)
      const
  {
    point v0(this->_vertex[1] - this->_vertex[0]);
    point v1(this->_vertex[2] - this->_vertex[0]);
    point v2(query_point - this->_vertex[0]);
    real d00 = v0.dot(v0);
    real d01 = v0.dot(v1);
    real d11 = v1.dot(v1);
    real d20 = v2.dot(v0);
    real d21 = v2.dot(v1);
    real denom = d00 * d11 - d01 * d01;
    v = (d11 * d20 - d01 * d21) / denom;
    w = (d00 * d21 - d01 * d20) / denom;
    u = 1.0 - v - w;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  plane
  triangle::layingPlane(void)
      const
  {
    return plane(this->centroid(), this->normal());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  triangle::translate(
      vector const &input)
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

  bool
  triangle::isInside(
      point const &query_point)
      const
  {
    real u, v, w;
    this->barycentric(query_point, u, v, w);
    if ((u >= real(0.0) && u <= real(1.0)) &&
        (v >= real(0.0) && v <= real(1.0)) &&
        (w >= real(0.0) && w <= real(1.0)))
      return true;
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  triangle::isDegenerated(void)
      const
  {
    return acme::isApprox((this->_vertex[0] - this->_vertex[1]).norm(), real(0.0), acme::Epsilon) ||
           acme::isApprox((this->_vertex[1] - this->_vertex[2]).norm(), real(0.0), acme::Epsilon) ||
           acme::isApprox((this->_vertex[2] - this->_vertex[0]).norm(), real(0.0), acme::Epsilon);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_triangle.cc
///
