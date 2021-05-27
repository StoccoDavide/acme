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

  void
  sphere::clamp(
      aabb &aabb_in)
      const
  {
    aabb_in.min(0) = -this->m_radius;
    aabb_in.min(1) = -this->m_radius;
    aabb_in.min(2) = -this->m_radius;
    aabb_in.max(0) = this->m_radius;
    aabb_in.max(1) = this->m_radius;
    aabb_in.max(2) = this->m_radius;
    aabb_in.translate(this->m_center);
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -˚

} // namespace acme

///
/// eof: acme_sphere.cc
///