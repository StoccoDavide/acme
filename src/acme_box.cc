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

  box &box::operator=(
      box const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_point_min = input._point_min;
      this->_point_max = input._point_max;
      this->_id = input._id;
      this->_ipos = input._ipos;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool box::is_equal(
      box const &input)
      const
  {
    return acme::is_equal(this->_point_min, input._point_min) &&
           acme::is_equal(this->_point_max, input._point_max);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool box::is_degenerated(void)
      const
  {
    return acme::is_equal((this->_point_min - this->_point_max).norm(), real_type(0.0));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool box::check_max_min(void)
      const
  {
    return this->_point_max.x() >= this->_point_min.x() &&
           this->_point_max.y() >= this->_point_min.y() &&
           this->_point_max.z() >= this->_point_min.z();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool box::update_max_min(void)
  {
    bool output = true;
    real_type point_max_tmp, point_min_tmp;
    for (size_t i = 0; i < 3; ++i)
    {
      point_max_tmp = this->_point_max[i];
      point_min_tmp = this->_point_min[i];
      if (point_max_tmp < point_min_tmp)
      {
        this->_point_max[i] = point_min_tmp;
        this->_point_min[i] = point_max_tmp;
        output = false;
      }
    }
    return output;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &box::point_min(void) const { return this->_point_min; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::x_min(void) const { return this->_point_min.x(); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::y_min(void) const { return this->_point_min.y(); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::z_min(void) const { return this->_point_min.z(); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::min(
      const int_type i)
      const
  {
    return this->_point_min[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::point_min(
      vec3 const &input)
  {
    this->_point_min = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::x_min(
      real_type input)
  {
    this->_point_min.x() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::y_min(
      real_type input)
  {
    this->_point_min.y() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::z_min(
      real_type input)
  {
    this->_point_min.z() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::min(
      int_type i,
      real_type input)
  {
    this->_point_min[i] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &box::point_max(void) const { return this->_point_max; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::x_max(void) const { return this->_point_max.x(); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::y_max(void) const { return this->_point_max.y(); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::z_max(void) const { return this->_point_max.z(); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::max(
      int_type i)
      const
  {
    return this->_point_max[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::point_max(
      vec3 const &input)
  {
    this->_point_max = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::x_max(
      real_type input)
  {
    this->_point_max.x() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::y_max(
      real_type input)
  {
    this->_point_max.y() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::z_max(
      real_type input)
  {
    this->_point_max.z() = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::max(
      int_type i,
      real_type input)
  {
    this->_point_max[i] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::translate(
      vec3 const &input)
  {
    this->_point_min = input + this->_point_min;
    this->_point_max = input + this->_point_max;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::rotate(
      mat3 const &input)
  {
    this->_point_min = input * this->_point_min;
    this->_point_max = input * this->_point_max;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  box box::transform(
      frame const &frameA,
      frame const &frameB) const
  {
    return box(acme::transform_point(this->_point_min, frameA, frameB),
               acme::transform_point(this->_point_max, frameA, frameB));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool box::collision(
      box const &input)
      const
  {
    return (this->_point_min.x() <= input._point_max.x() && this->_point_max.x() >= input._point_min.x()) &&
           (this->_point_min.y() <= input._point_max.y() && this->_point_max.y() >= input._point_min.y()) &&
           (this->_point_min.z() <= input._point_max.z() && this->_point_max.z() >= input._point_min.z());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void box::join(
      std::vector<boxPtr> const &boxes)
  {
    if (boxes.empty())
    {
      this->_point_min = Zeros_vec3;
      this->_point_max = Zeros_vec3;
    }
    else
    {
      std::vector<boxPtr>::const_iterator it = boxes.begin();

      this->_point_min = (*it)->_point_min;
      this->_point_max = (*it)->_point_max;

      for (++it; it != boxes.end(); ++it)
      {
        box const &curBox = **it;
        if (curBox._point_min.x() < this->_point_min.x())
          this->_point_min.x() = curBox._point_min.x();
        if (curBox._point_min.y() < this->_point_min.y())
          this->_point_min.y() = curBox._point_min.y();
        if (curBox._point_min.z() < this->_point_min.z())
          this->_point_min.z() = curBox._point_min.z();
        if (curBox._point_max.x() > this->_point_max.x())
          this->_point_max.x() = curBox._point_max.x();
        if (curBox._point_max.y() > this->_point_max.y())
          this->_point_max.y() = curBox._point_max.y();
        if (curBox._point_max.z() > this->_point_max.z())
          this->_point_max.z() = curBox._point_max.z();
      }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::distance(
      vec3 const &point)
      const
  {
    vec3 center((this->_point_max + this->_point_min) / 2);
    vec3 point_max_centered(this->_point_max - center);
    vec3 point_centered(point - center);

    real_type x_scale = acme::abs(1.0 / point_max_centered.x());
    real_type y_scale = acme::abs(1.0 / point_max_centered.y());
    real_type z_scale = acme::abs(1.0 / point_max_centered.z());

    real_type dx = acme::max(0.0, acme::abs(point_centered.x()) * x_scale - 1.0) / x_scale;
    real_type dy = acme::max(0.0, acme::abs(point_centered.y()) * y_scale - 1.0) / y_scale;
    real_type dz = acme::max(0.0, acme::abs(point_centered.z()) * z_scale - 1.0) / z_scale;

    return acme::sqrt(dx * dx + dy * dy + dz * dz);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type box::max_distance(
      vec3 const &point) const
  {
    real_type dx = acme::max(acme::abs(point.x() - this->_point_min.x()), acme::abs(point.x() - this->_point_max.x()));
    real_type dy = acme::max(acme::abs(point.y() - this->_point_min.y()), acme::abs(point.y() - this->_point_max.y()));
    real_type dz = acme::max(acme::abs(point.z() - this->_point_min.z()), acme::abs(point.z() - this->_point_max.z()));
    return sqrt(dx * dx + dy * dy + dz * dz);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  box box::minimum_box(
      vec3 const points[3])
      const
  {
    acme::minmax3(Vertices[0].x(), Vertices[1].x(), Vertices[2].x(), Xmin, Xmax);
    acme::minmax3(Vertices[0].y(), Vertices[1].y(), Vertices[2].y(), Ymin, Ymax);
  }

} // namespace acme

///
/// eof: acme_box.cc
///