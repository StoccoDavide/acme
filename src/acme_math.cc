///
/// file: acme_math.cc
///

/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The acme computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the acme computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

#include "acme_math.hh"

namespace acme
{

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

  real_type sqr(const real_type input)
  {
    return input * input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type cub(const real_type input)
  {
    return input * input * input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type sqrt(const real_type input)
  {
    return std::sqrt(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type abs(const real_type input)
  {
    return std::abs(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type max(
      const real_type input0,
      const real_type input1)
  {
    return std::max<real_type>(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type min(
      const real_type input0,
      const real_type input1)
  {
    return std::min<real_type>(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type max(
      const real_type input0,
      const real_type input1,
      const real_type input2)
  {
    return max(input0, max(input1, input2));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type min(
      const real_type input0,
      const real_type input1,
      const real_type input2)
  {
    return min(input0, min(input1, input2));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type sin(const real_type input)
  {
    return std::sin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type cos(const real_type input)
  {
    return std::cos(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type tan(const real_type input)
  {
    return std::tan(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type asin(const real_type input)
  {
    return std::asin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type acos(const real_type input)
  {
    return std::acos(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type atan(const real_type input)
  {
    return std::atan(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type atan2(
      const real_type input0,
      const real_type input1)
  {
    return std::atan2(input0, input1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type clamp(
      const real_type input,
      const real_type low,
      const real_type high)
  {
    if (input < low)
    {
      return low;
    }
    else if (input > high)
    {
      return high;
    }
    else
    {
      return input;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_equal(
      const real_type input0,
      const real_type input1,
      const real_type tolerance)
  {
    if (abs(input0 - input1) < tolerance)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_equal(
      const vector &input0,
      const vector &input1,
      const real_type tolerance)
  {
    return acme::is_equal((input0 - input1).norm(), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_equal(
      const matrix &input0,
      const matrix &input1,
      const real_type tolerance)
  {
    return acme::is_equal((input0 - input1).norm(), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_degenerated(
      const vector &input,
      const real_type tolerance)
  {
    return acme::is_equal(input.norm(), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_normalized(
      const vector &input,
      const real_type tolerance)
  {
    return acme::is_equal(input.norm(), 1.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_ortogonal(
      const vector &input0,
      const vector &input1,
      const real_type tolerance)
  {
    return acme::is_equal(abs(input0.dot(input1)) / (input0.norm() * input1.norm()), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_parallel(
      const vector &input0,
      const vector &input1,
      const real_type tolerance)
  {
    return acme::is_equal(input0.cross(input1).norm(), 0.0, tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool is_ortonormal(
      const matrix &input,
      const real_type tolerance)
  {
    return acme::is_ortogonal(input.col(0), input.col(1), tolerance) &&
           acme::is_ortogonal(input.col(1), input.col(2), tolerance) &&
           acme::is_ortogonal(input.col(2), input.col(0), tolerance) &&
           acme::is_normalized(vector(input.col(0)), tolerance) &&
           acme::is_normalized(vector(input.col(1)), tolerance) &&
           acme::is_normalized(vector(input.col(2)), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  matrix rotation_x(
      const real_type input)
  {
    matrix rot;
    rot << 1.0, 0.0, 0.0,
        0.0, cos(input), -sin(input),
        0.0, sin(input), cos(input);
    return rot;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  matrix rotation_y(
      const real_type input)
  {
    matrix rot;
    rot << cos(input), 0.0, sin(input),
        0.0, 1.0, 0.0,
        -sin(input), 0.0, cos(input);
    return rot;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  matrix rotation_z(
      const real_type input)
  {
    matrix rot;
    rot << cos(input), -sin(input), 0.0,
        sin(input), cos(input), 0.0,
        0.0, 0.0, 1.0;
    return rot;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type angle_rad(
      const vector &input0,
      const vector &input1)
  {
    return acme::acos(input0.dot(input1) / (input0.norm() * input1.norm()));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type angle_deg(
      const vector &input0,
      const vector &input1)
  {
    return acme::angle_rad(input0, input1) * 1 / PIDiv180;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_math.cc
///