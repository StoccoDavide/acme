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
/// file: acme_aabb.cc
///

#include "acme_aabb.hh"

namespace acme
{

  /*\
   |               _     _     
   |    __ _  __ _| |__ | |_     
   |   / _` |/ _` | '_ \| '_ \ 
   |  | (_| | (_| | |_) | |_) |
   |   \__,_|\__,_|_.__/|_.__/ 
   |                           
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  aabb &
  aabb::operator=(
      aabb const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_min = input._min;
      this->_max = input._max;
      this->_id = input._id;
      this->_ipos = input._ipos;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::clear(
      void)
  {
    this->_min = NaN_point;
    this->_max = NaN_point;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  aabb::isApprox(
      aabb const &input,
      real tolerance)
      const
  {
    return this->_min.isApprox(input._min, tolerance) &&
           this->_max.isApprox(input._max, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  aabb::checkMaxMin(void)
      const
  {
    return this->_max.x() >= this->_min.x() &&
           this->_max.y() >= this->_min.y() &&
           this->_max.z() >= this->_min.z();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  aabb::updateMaxMin(void)
  {
    bool output = true;
    real point_max_tmp, point_min_tmp;
    for (integer i = 0; i < 3; ++i)
    {
      point_max_tmp = this->_max[i];
      point_min_tmp = this->_min[i];
      if (point_max_tmp < point_min_tmp)
      {
        this->_max[i] = point_min_tmp;
        this->_min[i] = point_max_tmp;
        output = false;
      }
    }
    return output;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point const &
  aabb::min(void)
      const
  {
    return this->_min;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::minX(void)
      const
  {
    return this->_min.x();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::minY(void)
      const
  {
    return this->_min.y();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::minZ(void)
      const
  {
    return this->_min.z();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::min(
      integer i)
      const
  {
    return this->_min[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::min(
      point const &input)
  {
    this->_min = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::min(
      real x,
      real y,
      real z)
  {
    this->_min.x() = x;
    this->_min.y() = y;
    this->_min.z() = z;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::minX(
      real input)
  {
    this->_min.x() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::minY(
      real input)
  {
    this->_min.y() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::minZ(
      real input)
  {
    this->_min.z() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::min(
      integer i,
      real input)
  {
    this->_min[i] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point const &
  aabb::max(void)
      const
  {
    return this->_max;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::maxX(void)
      const
  {
    return this->_max.x();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::maxY(void)
      const
  {
    return this->_max.y();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::maxZ(void)
      const
  {
    return this->_max.z();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::max(
      integer i)
      const
  {
    return this->_max[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::max(
      point const &input)
  {
    this->_max = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::max(
      real x,
      real y,
      real z)
  {
    this->_max.x() = x;
    this->_max.y() = y;
    this->_max.z() = z;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::maxX(
      real input)
  {
    this->_max.x() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::maxY(
      real input)
  {
    this->_max.y() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::maxZ(
      real input)
  {
    this->_max.z() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::max(
      integer i,
      real input)
  {
    this->_max[i] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  aabb::intersects(
      aabb const &input)
      const
  {
    return (this->_min.x() <= input._max.x() && this->_max.x() >= input._min.x()) &&
           (this->_min.y() <= input._max.y() && this->_max.y() >= input._min.y()) &&
           (this->_min.z() <= input._max.z() && this->_max.z() >= input._min.z());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::merged(
      std::vector<aabb::ptr> const &boxes)
  {
    if (boxes.empty())
    {
      this->_min = Zeros_point;
      this->_max = Zeros_point;
    }
    else
    {
      std::vector<aabb::ptr>::const_iterator it = boxes.begin();

      this->_min = (*it)->_min;
      this->_max = (*it)->_max;

      for (++it; it != boxes.end(); ++it)
      {
        aabb const &cur_box = **it;
        if (cur_box._min.x() < this->_min.x())
          this->_min.x() = cur_box._min.x();
        if (cur_box._min.y() < this->_min.y())
          this->_min.y() = cur_box._min.y();
        if (cur_box._min.z() < this->_min.z())
          this->_min.z() = cur_box._min.z();
        if (cur_box._max.x() > this->_max.x())
          this->_max.x() = cur_box._max.x();
        if (cur_box._max.y() > this->_max.y())
          this->_max.y() = cur_box._max.y();
        if (cur_box._max.z() > this->_max.z())
          this->_max.z() = cur_box._max.z();
      }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::centerDistance(
      point const &query_point)
      const
  {
    point center((this->_max + this->_min) / 2);
    point point_max_centered(this->_max - center);
    point point_centered(query_point - center);
    real x_scale = acme::abs(real(1.0) / point_max_centered.x());
    real y_scale = acme::abs(real(1.0) / point_max_centered.y());
    real z_scale = acme::abs(real(1.0) / point_max_centered.z());
    real dx = acme::max(real(0.0), acme::abs(point_centered.x()) * x_scale - real(1.0)) / x_scale;
    real dy = acme::max(real(0.0), acme::abs(point_centered.y()) * y_scale - real(1.0)) / y_scale;
    real dz = acme::max(real(0.0), acme::abs(point_centered.z()) * z_scale - real(1.0)) / z_scale;
    return acme::sqrt(dx * dx + dy * dy + dz * dz);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabb::exteriorDistance(
      point const &query_point)
      const
  {
    real dx = acme::max(acme::abs(query_point.x() - this->_min.x()), acme::abs(query_point.x() - this->_max.x()));
    real dy = acme::max(acme::abs(query_point.y() - this->_min.y()), acme::abs(query_point.y() - this->_max.y()));
    real dz = acme::max(acme::abs(query_point.z() - this->_min.z()), acme::abs(query_point.z() - this->_max.z()));
    return acme::sqrt(dx * dx + dy * dy + dz * dz);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::clamp(
      point const &point_0,
      point const &point_1,
      point const &point_2)
  {
    this->_min.x() = acme::min(point_0.x(), point_1.x(), point_2.x());
    this->_min.y() = acme::min(point_0.y(), point_1.y(), point_2.y());
    this->_min.z() = acme::min(point_0.z(), point_1.z(), point_2.z());
    this->_max.x() = acme::max(point_0.x(), point_1.x(), point_2.x());
    this->_max.y() = acme::max(point_0.y(), point_1.y(), point_2.y());
    this->_max.z() = acme::max(point_0.z(), point_1.z(), point_2.z());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::clamp(
      point const points[3])
  {
    this->_min.x() = acme::min(points[0].x(), points[1].x(), points[2].x());
    this->_min.y() = acme::min(points[0].y(), points[1].y(), points[2].y());
    this->_min.z() = acme::min(points[0].z(), points[1].z(), points[2].z());
    this->_max.x() = acme::max(points[0].x(), points[1].x(), points[2].x());
    this->_max.y() = acme::max(points[0].y(), points[1].y(), points[2].y());
    this->_max.z() = acme::max(points[0].z(), points[1].z(), points[2].z());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer const &
  aabb::id(void)
      const
  {
    return this->_id;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer const &
  aabb::pos(void)
      const
  {
    return this->_ipos;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::translate(
      vec3 const &input)
  {
    this->_min = input + this->_min;
    this->_max = input + this->_max;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabb::transform(
      affine const &matrix)
  {
    this->_min.transform(matrix);
    this->_max.transform(matrix);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  aabb::isInside(
      point const &query_point,
      real tolerance)
      const
  {
    return this->_min.x() <= query_point.x() &&
           this->_min.y() <= query_point.y() &&
           this->_min.z() <= query_point.z() &&
           this->_max.x() >= query_point.x() &&
           this->_max.y() >= query_point.y() &&
           this->_max.z() >= query_point.z();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  aabb::isDegenerated(
      real tolerance)
      const
  {
    return this->_min.isApprox(this->_max, tolerance) &&
           this->checkMaxMin();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_aabb.cc
///