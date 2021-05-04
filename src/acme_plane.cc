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
/// file: acme_plane.cc
///

#include "acme_plane.hh"

namespace acme
{

  /*\
   |         _                  
   |   _ __ | | __ _ _ __   ___ 
   |  | '_ \| |/ _` | '_ \ / _ \
   |  | |_) | | (_| | | | |  __/
   |  | .__/|_|\__,_|_| |_|\___|
   |  |_|                       
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  plane &
  plane::operator=(
      plane const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_origin = input._origin;
      this->_normal = input._normal;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  plane::isApprox(
      plane const &input)
      const
  {
    return this->_origin.isApprox(input._origin, acme::Epsilon) &&
           this->_normal.isApprox(input._normal, acme::Epsilon);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point const &
  plane::origin() const
  {
    return this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vector const &
  plane::normal() const
  {
    return this->_normal;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  plane::origin(
      point const &input)
  {
    this->_origin = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  plane::normal(
      vector const &input)
  {
    this->_normal = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  plane::normalize(void)
  {
    this->_normal.normalize();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  plane::reverse(void)
  {
    this->_normal = -this->_normal;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  plane::d(void)
      const
  {
    return -this->_origin.dot(this->_normal);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  plane::distance(
      point const &query_point)
      const
  {
    return acme::abs(this->signedDistance(query_point));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  plane::squaredDistance(
      point const &query_point)
      const
  {
    return acme::sqr(this->signedDistance(query_point));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  plane::signedDistance(
      point const &query_point)
      const
  {
    return (query_point - this->_origin).dot(this->_normal);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  plane::translate(
      vector const &input)
  {
    this->_origin = input + this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  plane::transform(
      affine const &matrix)
  {
    acme::transformPoint(this->_origin, matrix);
    acme::transformVector(this->_normal, matrix);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  plane::isInside(
      point const &query_point)
      const
  {
    return this->signedDistance(query_point) < acme::Epsilon;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  plane::isDegenerated(void)
      const
  {
    return acme::isApprox(this->_normal.norm(), real(0.0), acme::Epsilon);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_plane.cc
///