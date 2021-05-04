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
/// file: acme_box.cc
///

#include "acme_box.hh"

namespace acme
{

  /*\
   |   _               
   |  | |__   _____  _ 
   |  | '_ \ / _ \ \/ /
   |  | |_) | (_) >  < 
   |  |_.__/ \___/_/\_\
   |                   
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  box &
  box::operator=(
      box const &input)
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
  box::clear(
      void)
  {
    this->_min = NaN_vec3;
    this->_max = NaN_vec3;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  box::isApprox(
      box const &input)
      const
  {
    return this->_min.isApprox(input._min) &&
           this->_max.isApprox(input._max);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  box::checkMaxMin(void)
      const
  {
    return this->_max.x() >= this->_min.x() &&
           this->_max.y() >= this->_min.y() &&
           this->_max.z() >= this->_min.z();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  box::updateMaxMin(void)
  {
    bool output = true;
    real_type point_max_tmp, point_min_tmp;
    for (size_t i = 0; i < 3; ++i)
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

  vec3 const &
  box::min(void)
      const
  {
    return this->_min;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  box::minX(void)
      const
  {
    return this->_min.x();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  box::minY(void)
      const
  {
    return this->_min.y();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  box::minZ(void)
      const
  {
    return this->_min.z();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  box::min(
      size_t i)
      const
  {
    return this->_min[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::min(
      vec3 const &input)
  {
    this->_min = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::min(
      real_type x,
      real_type y,
      real_type z)
  {
    this->_min.x() = x;
    this->_min.y() = y;
    this->_min.z() = z;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::minX(
      real_type input)
  {
    this->_min.x() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::minY(
      real_type input)
  {
    this->_min.y() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::minZ(
      real_type input)
  {
    this->_min.z() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::min(
      size_t i,
      real_type input)
  {
    this->_min[i] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  box::max(void)
      const
  {
    return this->_max;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  box::maxX(void)
      const
  {
    return this->_max.x();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  box::maxY(void)
      const
  {
    return this->_max.y();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  box::maxZ(void)
      const
  {
    return this->_max.z();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  box::max(
      size_t i)
      const
  {
    return this->_max[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::max(
      vec3 const &input)
  {
    this->_max = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::max(
      real_type x,
      real_type y,
      real_type z)
  {
    this->_max.x() = x;
    this->_max.y() = y;
    this->_max.z() = z;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::maxX(
      real_type input)
  {
    this->_max.x() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::maxY(
      real_type input)
  {
    this->_max.y() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::maxZ(
      real_type input)
  {
    this->_max.z() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::max(
      size_t i,
      real_type input)
  {
    this->_max[i] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  box::intersects(
      box const &input)
      const
  {
    return (this->_min.x() <= input._max.x() && this->_max.x() >= input._min.x()) &&
           (this->_min.y() <= input._max.y() && this->_max.y() >= input._min.y()) &&
           (this->_min.z() <= input._max.z() && this->_max.z() >= input._min.z());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::merged(
      std::vector<box::ptr> const &boxes)
  {
    if (boxes.empty())
    {
      this->_min = Zeros_vec3;
      this->_max = Zeros_vec3;
    }
    else
    {
      std::vector<box::ptr>::const_iterator it = boxes.begin();

      this->_min = (*it)->_min;
      this->_max = (*it)->_max;

      for (++it; it != boxes.end(); ++it)
      {
        box const &cur_box = **it;
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

  real_type
  box::centerDistance(
      vec3 const &point)
      const
  {
    vec3 center((this->_max + this->_min) / 2);
    vec3 point_max_centered(this->_max - center);
    vec3 point_centered(point - center);
    real_type x_scale = acme::abs(real_type(1.0) / point_max_centered.x());
    real_type y_scale = acme::abs(real_type(1.0) / point_max_centered.y());
    real_type z_scale = acme::abs(real_type(1.0) / point_max_centered.z());
    real_type dx = acme::max(real_type(0.0), acme::abs(point_centered.x()) * x_scale - real_type(1.0)) / x_scale;
    real_type dy = acme::max(real_type(0.0), acme::abs(point_centered.y()) * y_scale - real_type(1.0)) / y_scale;
    real_type dz = acme::max(real_type(0.0), acme::abs(point_centered.z()) * z_scale - real_type(1.0)) / z_scale;
    return acme::sqrt(dx * dx + dy * dy + dz * dz);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  box::exteriorDistance(
      vec3 const &point)
      const
  {
    real_type dx = acme::max(acme::abs(point.x() - this->_min.x()), acme::abs(point.x() - this->_max.x()));
    real_type dy = acme::max(acme::abs(point.y() - this->_min.y()), acme::abs(point.y() - this->_max.y()));
    real_type dz = acme::max(acme::abs(point.z() - this->_min.z()), acme::abs(point.z() - this->_max.z()));
    return acme::sqrt(dx * dx + dy * dy + dz * dz);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::clamp(
      vec3 const &point_0,
      vec3 const &point_1,
      vec3 const &point_2)
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
  box::clamp(
      vec3 const points[3])
  {
    this->_min.x() = acme::min(points[0].x(), points[1].x(), points[2].x());
    this->_min.y() = acme::min(points[0].y(), points[1].y(), points[2].y());
    this->_min.z() = acme::min(points[0].z(), points[1].z(), points[2].z());
    this->_max.x() = acme::max(points[0].x(), points[1].x(), points[2].x());
    this->_max.y() = acme::max(points[0].y(), points[1].y(), points[2].y());
    this->_max.z() = acme::max(points[0].z(), points[1].z(), points[2].z());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  int_type const &
  box::id(void)
      const
  {
    return this->_id;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  int_type const &
  box::pos(void)
      const
  {
    return this->_ipos;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::translate(
      vec3 const &input)
  {
    this->_min = input + this->_min;
    this->_max = input + this->_max;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  box::transform(
      affine const &matrix)
  {
    acme::transformPoint(this->_min, matrix);
    acme::transformPoint(this->_max, matrix);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  box::isInside(
      vec3 const &point)
      const
  {
    return this->_min.x() < point.x() && this->_min.y() < point.y() && this->_min.z() < point.z() &&
           this->_max.x() > point.x() && this->_max.y() > point.y() && this->_max.z() > point.z();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  box::isDegenerated(void)
      const
  {
    return this->_min.isApprox(this->_max) &&
           this->checkMaxMin();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_box.cc
///