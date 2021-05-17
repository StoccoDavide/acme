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
/// file: acme_math.cc
///

#include "acme_math.hh"

namespace acme
{

  /*\
   |   __  __       _   _     
   |  |  \/  | __ _| |_| |__  
   |  | |\/| |/ _` | __| '_ \ 
   |  | |  | | (_| | |_| | | |
   |  |_|  |_|\__,_|\__|_| |_|
   |                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  infinity(void)
  {
    return std::numeric_limits<real>::infinity();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  epsilon(void)
  {
    return Epsilon;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  sqr(real input)
  {
    return input * input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  cub(real input)
  {
    return input * input * input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  sqrt(real input)
  {
    return std::sqrt(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  pow(
      real base,
      real exponent)
  {
    return std::pow(base, exponent);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  abs(real input)
  {
    return std::abs(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  max(
      real input0,
      real input1)
  {
    return std::max<real>(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  min(
      real input0,
      real input1)
  {
    return std::min<real>(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  max(
      real input0,
      real input1,
      real input2)
  {
    return acme::max(input0, acme::max(input1, input2));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  min(
      real input0,
      real input1,
      real input2)
  {
    return acme::min(input0, acme::min(input1, input2));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  sin(real input)
  {
    return std::sin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  cos(real input)
  {
    return std::cos(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  tan(real input)
  {
    return std::tan(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  asin(real input)
  {
    return std::asin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  acos(real input)
  {
    return std::acos(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  atan(real input)
  {
    return std::atan(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  atan2(
      real input0,
      real input1)
  {
    return std::atan2(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  clamp(
      real input,
      real low,
      real high)
  {
    if (input < low)
      return low;
    else if (input > high)
      return high;
    else
      return input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isApprox(
      real input0,
      real input1,
      real tolerance)
  {
    return std::abs(input0 - input1) < tolerance;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  angleaxis
  rotate(
      real angle,
      vec3 const &axis)
  {
    return Eigen::AngleAxis<real>(angle, axis);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  angleaxis
  rotate(
      real angle,
      std::string const &axis)
  {
    if (axis == "X")
      return Eigen::AngleAxis<real>(angle, UnitX_vec3);
    else if (axis == "Y")
      return Eigen::AngleAxis<real>(angle, UnitY_vec3);
    else if (axis == "Z")
      return Eigen::AngleAxis<real>(angle, UnitZ_vec3);
    else
      ACME_ERROR("acme::rotate(): invalid axis string.\n")
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  angle(
      vec3 const &input0,
      vec3 const &input1)
  {
    return acme::acos(input0.dot(input1) / (input0.norm() * input1.norm()));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  eulerAngles(
      mat3 const &rotation,
      integer i,
      integer j,
      integer k,
      vec3 &angles)
  {
    vec3 angles_tmp(rotation.eulerAngles(i, j, k));
    angles[i] = angles_tmp[0];
    angles[j] = angles_tmp[1];
    angles[k] = angles_tmp[2];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_math.cc
///