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

  real_type infinity(void)
  {
    return std::numeric_limits<real_type>::infinity();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type epsilon(void)
  {
    return Epsilon;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type sqr(real_type input)
  {
    return input * input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type cub(real_type input)
  {
    return input * input * input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type sqrt(real_type input)
  {
    return std::sqrt(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type pow(
      real_type base,
      real_type exponent)
  {
    return std::pow(base, exponent);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type abs(real_type input)
  {
    return std::abs(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type max(
      real_type input0,
      real_type input1)
  {
    return std::max<real_type>(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type min(
      real_type input0,
      real_type input1)
  {
    return std::min<real_type>(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type max(
      real_type input0,
      real_type input1,
      real_type input2)
  {
    return max(input0, max(input1, input2));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type min(
      real_type input0,
      real_type input1,
      real_type input2)
  {
    return min(input0, min(input1, input2));
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

  real_type sin(real_type input)
  {
    return std::sin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type cos(real_type input)
  {
    return std::cos(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type tan(real_type input)
  {
    return std::tan(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type asin(real_type input)
  {
    return std::asin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type acos(real_type input)
  {
    return std::acos(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type atan(real_type input)
  {
    return std::atan(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type atan2(
      real_type input0,
      real_type input1)
  {
    return std::atan2(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type clamp(
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

  bool is_equal(
      real_type input0,
      real_type input1,
      real_type tolerance)
  {
    return abs(input0 - input1) < tolerance;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_equal(
      vec3 const &input0,
      vec3 const &input1,
      real_type tolerance)
  {
    return acme::is_equal((input0 - input1).norm(), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_equal(
      mat3 const &input0,
      mat3 const &input1,
      real_type tolerance)
  {
    return acme::is_equal((input0 - input1).norm(), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_degenerated(
      vec3 const &input,
      real_type tolerance)
  {
    return acme::is_equal(input.norm(), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_normalized(
      vec3 const &input,
      real_type tolerance)
  {
    return acme::is_equal(input.norm(), 1.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_ortogonal(
      vec3 const &input0,
      vec3 const &input1,
      real_type tolerance)
  {
    return acme::is_equal(abs(input0.dot(input1)) / (input0.norm() * input1.norm()), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_parallel(
      vec3 const &input0,
      vec3 const &input1,
      real_type tolerance)
  {
    return acme::is_equal(input0.cross(input1).norm(), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_ortonormal(
      mat3 const &input,
      real_type tolerance)
  {
    return acme::is_ortogonal(input.col(0), input.col(1), tolerance) &&
           acme::is_ortogonal(input.col(1), input.col(2), tolerance) &&
           acme::is_ortogonal(input.col(2), input.col(0), tolerance) &&
           acme::is_normalized(vec3(input.col(0)), tolerance) &&
           acme::is_normalized(vec3(input.col(1)), tolerance) &&
           acme::is_normalized(vec3(input.col(2)), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  mat3 const rotation_x(
      real_type input)
  {
    mat3 rot;
    rot << 1.0, 0.0, 0.0,
        0.0, cos(input), -sin(input),
        0.0, sin(input), cos(input);
    return rot;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  mat3 const rotation_y(
      real_type input)
  {
    mat3 rot;
    rot << cos(input), 0.0, sin(input),
        0.0, 1.0, 0.0,
        -sin(input), 0.0, cos(input);
    return rot;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  mat3 const rotation_z(
      real_type input)
  {
    mat3 rot;
    rot << cos(input), -sin(input), 0.0,
        sin(input), cos(input), 0.0,
        0.0, 0.0, 1.0;
    return rot;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type angle_rad(
      vec3 const &input0,
      vec3 const &input1)
  {
    return acme::acos(input0.dot(input1) / (input0.norm() * input1.norm()));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type angle_deg(
      vec3 const &input0,
      vec3 const &input1)
  {
    return acme::angle_rad(input0, input1) * 1 / PIdiv180;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_math.cc
///