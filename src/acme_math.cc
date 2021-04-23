/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project - Release Version 0.0.0                            *)
(*                                                                     *)
(* Copyright (c) 2020 Davide Stocco, All Rights Reserved.              *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 2-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 2-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
(*                                                                     *)
(*    Davide Stocco                                                    *)
(*    University of Trento                                             *)
(*    Department of Industrial Engineering                             *)
(*    davide.stocco@unitn.it                                           *)
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

  real_type
  infinity(void)
  {
    return std::numeric_limits<real_type>::infinity();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  epsilon(void)
  {
    return Epsilon;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  sqr(real_type input)
  {
    return input * input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  cub(real_type input)
  {
    return input * input * input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  sqrt(real_type input)
  {
    return std::sqrt(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  pow(
      real_type base,
      real_type exponent)
  {
    return std::pow(base, exponent);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  abs(real_type input)
  {
    return std::abs(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  max(
      real_type input0,
      real_type input1)
  {
    return std::max<real_type>(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  min(
      real_type input0,
      real_type input1)
  {
    return std::min<real_type>(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  max(
      real_type input0,
      real_type input1,
      real_type input2)
  {
    return acme::max(input0, acme::max(input1, input2));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  min(
      real_type input0,
      real_type input1,
      real_type input2)
  {
    return acme::min(input0, acme::min(input1, input2));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /*\
   |   _____     _                                        _              
   |  |_   _| __(_) __ _  ___  _ __   ___  _ __ ___   ___| |_ _ __ _   _ 
   |    | || '__| |/ _` |/ _ \| '_ \ / _ \| '_ ` _ \ / _ \ __| '__| | | |
   |    | || |  | | (_| | (_) | | | | (_) | | | | | |  __/ |_| |  | |_| |
   |    |_||_|  |_|\__, |\___/|_| |_|\___/|_| |_| |_|\___|\__|_|   \__, |
   |               |___/                                           |___/ 
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  sin(real_type input)
  {
    return std::sin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  cos(real_type input)
  {
    return std::cos(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  tan(real_type input)
  {
    return std::tan(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  asin(real_type input)
  {
    return std::asin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  acos(real_type input)
  {
    return std::acos(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  atan(real_type input)
  {
    return std::atan(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  atan2(
      real_type input0,
      real_type input1)
  {
    return std::atan2(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  clamp(
      real_type input,
      real_type low,
      real_type high)
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
      real_type input0,
      real_type input1,
      real_type tolerance)
  {
    return std::abs(input0 - input1) < tolerance;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isApprox(
      vec3 const &input0,
      vec3 const &input1,
      real_type tolerance)
  {
    return acme::isApprox((input0 - input1).norm(),
                          real_type(0.0),
                          tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isApprox(
      mat3 const &input0,
      mat3 const &input1,
      real_type tolerance)
  {
    return acme::isApprox((input0 - input1).norm(),
                          real_type(0.0),
                          tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isDegenerated(
      vec3 const &input,
      real_type tolerance)
  {
    return acme::isApprox(input.norm(),
                          real_type(0.0),
                          tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isParallel(
      vec3 const &input0,
      vec3 const &input1,
      real_type tolerance)
  {
    return acme::isApprox(input0.cross(input1).norm(),
                          real_type(0.0),
                          tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  isOrthonormal(
      mat3 const &input,
      real_type tolerance)
  {
    return input.col(0).isOrthogonal(input.col(1), tolerance) &&
           input.col(1).isOrthogonal(input.col(2), tolerance) &&
           input.col(2).isOrthogonal(input.col(0), tolerance) &&
           input.col(0).isUnitary(tolerance) &&
           input.col(1).isUnitary(tolerance) &&
           input.col(2).isUnitary(tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  angleaxis
  rotate(
      real_type angle,
      vec3 const &axis)
  {
    return Eigen::AngleAxis<real_type>(angle, axis);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  angleaxis
  rotate(
      real_type angle,
      std::string const &axis)
  {
    if (axis == "X")
      return Eigen::AngleAxis<real_type>(angle, UnitX_vec3);
    else if (axis == "Y")
      return Eigen::AngleAxis<real_type>(angle, UnitY_vec3);
    else if (axis == "Z")
      return Eigen::AngleAxis<real_type>(angle, UnitZ_vec3);
    else
      ACME_ERROR("acme::rotate(): invalid axis string.")
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
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
      size_t i,
      size_t j,
      size_t k,
      vec3 &angles)
  {
    vec3 angles_tmp(rotation.eulerAngles(i, j, k));
    angles[i] = angles_tmp[0];
    angles[j] = angles_tmp[1];
    angles[k] = angles_tmp[2];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /*\
   |   _____                     __                      
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
   |                                                     
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  transformVector(
      vec3 &vector,
      affine const &matrix)
  {
    vector = matrix.linear() * vector;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  transformPoint(
      vec3 &point,
      affine const &matrix)
  {
    point = matrix * point;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_math.cc
///