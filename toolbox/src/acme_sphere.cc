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
/// file: acme_sphere.cc
///

#include "acme_sphere.hh"

namespace acme
{

  /*\
   |             _                   
   |   ___ _ __ | |__   ___ _ __ ___ 
   |  / __| '_ \| '_ \ / _ \ '__/ _ \
   |  \__ \ |_) | | | |  __/ | |  __/
   |  |___/ .__/|_| |_|\___|_|  \___|
   |      |_|                        
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  sphere::sphere(
      real radius,
      real center_x,
      real center_y,
      real center_z)
      : m_radius(radius),
        m_center(center_x, center_y, center_z)
  {
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  sphere::sphere(
      real radius,
      point const &center)
      : m_radius(radius),
        m_center(center)
  {
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  sphere &
  sphere::operator=(
      sphere const &sphere_in)
  {
    if (this == &sphere_in)
    {
      return *this;
    }
    else
    {
      this->m_radius = sphere_in.m_radius;
      this->m_center = sphere_in.m_center;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  sphere::isApprox(
      sphere const &sphere_in,
      real tolerance)
      const
  {
    return acme::isApprox(this->m_radius, sphere_in.m_radius, tolerance) &&
           this->m_center.isApprox(sphere_in.m_center, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real const &
  sphere::radius(void)
      const
  {
    return this->m_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point const &
  sphere::center(void)
      const
  {
    return this->m_center;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real &
  sphere::radius(void)
  {
    return this->m_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point &
  sphere::center(void)
  {
    return this->m_center;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  sphere::area(void)
      const
  {
    return 4 * PI * this->m_radius * this->m_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  sphere::volume(void)
      const
  {
    return 4.0 / 3.0 * PI * this->m_radius * this->m_radius * this->m_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  sphere::translate(
      vec3 const &vector_in)
  {
    this->m_center.translate(vector_in);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  sphere::transform(
      affine const &affine_in)
  {
    this->m_center.transform(affine_in);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  sphere::isInside(
      point const &point_in,
      real tolerance)
      const
  {
    return (this->m_center - point_in).norm() <= this->m_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  sphere::isDegenerated(
      real tolerance)
      const
  {
    return acme::isApprox(this->m_radius, 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  sphere::clamp(
      vec3 &min,
      vec3 &max)
      const
  {
    point center(this->m_center);
    min[0] = -this->m_radius + center[0];
    min[1] = -this->m_radius + center[1];
    min[2] = -this->m_radius + center[2];
    max[0] = this->m_radius + center[0];
    max[1] = this->m_radius + center[1];
    max[2] = this->m_radius + center[2];
    return this->isClampable();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  sphere::clamp(
      real &min_x,
      real &min_y,
      real &min_z,
      real &max_x,
      real &max_y,
      real &max_z)
      const
  {
    point center(this->m_center);
    min_x = -this->m_radius + center[0];
    min_y = -this->m_radius + center[1];
    min_z = -this->m_radius + center[2];
    max_x = this->m_radius + center[0];
    max_y = this->m_radius + center[1];
    max_z = this->m_radius + center[2];
    return this->isClampable();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_sphere.cc
///