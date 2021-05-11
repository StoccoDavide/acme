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
/// file: acme_line.cc
///

#include "acme_line.hh"

namespace acme
{

  /*\
   |   _ _            
   |  | (_)_ __   ___ 
   |  | | | '_ \ / _ \
   |  | | | | | |  __/
   |  |_|_|_| |_|\___|
   |                  
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  line &
  line::operator=(
      line const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_origin = input._origin;
      this->_direction = input._direction;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::isApprox(
      line const &input)
      const
  {
    return this->_origin.isApprox(input._origin, acme::Epsilon) &&
           this->_direction.isApprox(input._direction, acme::Epsilon);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  point const &
  line::origin(void)
      const
  {
    return this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  line::direction(void)
      const
  {
    return this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::origin(
      point const &input)
  {
    this->_origin = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::direction(
      vec3 const &input)
  {
    this->_direction = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::normalize(void)
  {
    this->_direction.normalize();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  line::toVector(void)
      const
  {
    return this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  line::toNormalizedVector(void)
      const
  {
    return this->_direction.normalized();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::reverse(void)
  {
    this->_direction = -this->_direction;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::translate(
      vec3 const &input)
  {
    this->_origin = input + this->_origin;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  line::transform(
      affine const &matrix)
  {
    this->_origin.transform(matrix);
    acme::transform(this->_direction, matrix);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::isInside(
      point const &query_point)
      const
  {
    return acme::isApprox(((query_point - this->_origin).normalized().cross(this->_direction)).norm(),
                          real(0.0),
                          acme::Epsilon);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  line::isDegenerated(void)
      const
  {
    return acme::isApprox(this->_direction.norm(), real(0.0), acme::Epsilon);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_line.cc
///