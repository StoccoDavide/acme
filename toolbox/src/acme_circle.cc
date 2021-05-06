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
/// file: acme_circle.cc
///

#include "acme_circle.hh"

namespace acme
{

  /*\
   |        _          _      
   |    ___(_)_ __ ___| | ___ 
   |   / __| | '__/ __| |/ _ \
   |  | (__| | | | (__| |  __/
   |   \___|_|_|  \___|_|\___|
   |                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  circle &
  circle::operator=(
      circle const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_radius = input._radius;
      this->_plane = input._plane;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::isApprox(
      circle const &input)
      const
  {
    return acme::isApprox(this->_radius, input._radius, acme::Epsilon) &&
           this->_plane.origin().isApprox(input._plane.origin(), acme::Epsilon) &&
           this->_plane.normal().isApprox(input._plane.normal(), acme::Epsilon);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  circle::radius(void)
      const
  {
    return this->_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point const &
  circle::center(void)
      const
  {
    return this->_plane.origin();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  circle::normal(void)
      const
  {
    return this->_plane.normal();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  plane const &
  circle::layingPlane(void)
      const
  {
    return this->_plane;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::radius(
      real input)
  {
    this->_radius = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::center(
      point const &input)
  {
    this->_plane.origin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::normal(
      vec3 const &input)
  {
    this->_plane.normal(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::normalize(void)
  {
    this->_plane.normalize();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  void
  circle::layingPlane(
      plane const &input)
  {
    this->_plane = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::reverse(void)
  {
    this->_plane.reverse();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::translate(
      vec3 const &input)
  {
    this->_plane.translate(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::transform(
      affine const &matrix)
  {
    this->_plane.transform(matrix);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::isInside(
      point const &query_point)
      const
  {
    return this->_plane.isInside(query_point) &&
           (this->_plane.origin() - query_point).norm() <= this->_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::isDegenerated(void)
      const
  {
    return acme::isApprox(this->_radius, real(0.0), acme::Epsilon) &&
           this->_plane.isDegenerated();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -˚

} // namespace acme

///
/// eof: acme_circle.cc
///