/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *)
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
      real_type x0, real_type y0, real_type z0,
      real_type x1, real_type y1, real_type z1)
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

  segment::segment(
      vec3 const point[2])
  {
    this->_point[0] = point[0];
    this->_point[1] = point[1];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment &
  segment::operator=(
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

  bool
  segment::isApprox(
      segment const &input)
      const
  {
    return this->_point[0].isApprox(input._point[0]) &&
           this->_point[1].isApprox(input._point[1]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  segment::centroid(void)
      const
  {
    return (this->_point[0] + this->_point[1]) / 2.0;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  segment::point(
      size_t i)
      const
  {
    return this->_point[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 &
  segment::point(
      size_t i)
  {
    return this->_point[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  segment::toVector(void) const
  {
    return vec3(this->_point[1] - this->_point[0]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  segment::toNormalizedVector(void) const
  {
    return (this->_point[1] - this->_point[0]).normalized();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::swap(void)
  {
    vec3 tmp_point(this->_point[0]);
    this->_point[0] = this->_point[1];
    this->_point[1] = tmp_point;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::clamp(
      box &input)
      const
  {
    input.minX(acme::min(this->_point[0].x(), this->_point[1].x()));
    input.minY(acme::min(this->_point[0].y(), this->_point[1].y()));
    input.minZ(acme::min(this->_point[0].z(), this->_point[1].z()));
    input.maxX(acme::max(this->_point[0].x(), this->_point[1].x()));
    input.maxY(acme::max(this->_point[0].y(), this->_point[1].y()));
    input.maxZ(acme::max(this->_point[0].z(), this->_point[1].z()));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  segment::length(void) const
  {
    return (this->_point[0] - this->_point[1]).norm();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::translate(
      vec3 const &input)
  {
    this->_point[0] = input + this->_point[0];
    this->_point[1] = input + this->_point[1];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::transform(
      affine const &matrix)
  {
    acme::transformPoint(this->_point[0], matrix);
    acme::transformPoint(this->_point[1], matrix);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::isInside(
      vec3 const &point)
      const
  {
    real_type d0 = this->length();
    real_type d1 = (point - this->_point[0]).norm();
    real_type d2 = (point - this->_point[1]).norm();
    return acme::abs(d0 - d1 - d2) <= acme::Epsilon;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::isDegenerated(void)
      const
  {
    return acme::isApprox((this->_point[0] - this->_point[1]).norm(), real_type(0.0));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_segment.cc
///