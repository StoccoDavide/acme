///
/// file: acme_math.hh
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

#ifndef INCLUDE_ACME_MATH
#define INCLUDE_ACME_MATH

// Print acme errors
#ifndef ACME_ERROR
#define ACME_ERROR(MSG)                  \
  {                                      \
    std::ostringstream ost;              \
    ost << MSG;                          \
    throw std::runtime_error(ost.str()); \
  }
#endif

// Check for acme errors
#ifndef ACME_ASSERT
#define ACME_ASSERT(COND, MSG) \
  if (!(COND))                 \
  acme_ERROR(MSG)
#endif

#include <cmath>
#include <limits>
#include <algorithm>

#include "acme.hh"

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

  //! Return infinity
  real_type infinity(void);

  //! Return epsilon
  real_type epsilon(void);

  //! Square
  real_type sqr(
      const real_type &input //!< Input
  );

  //! Cubic
  real_type cub(
      const real_type &input //!< Input
  );

  //! Square root
  real_type sqrt(
      const real_type &input //!< Input
  );

  //! Absolute value
  real_type abs(const real_type &input //!< Input
  );

  //! Maximum between inputs
  real_type max(
      const real_type &input0, //!< Input 0
      const real_type &input1  //!< Input 1
  );

  //! Minimum between inputs
  real_type min(
      const real_type &input0, //!< Input 0
      const real_type &input1  //!< Input 1

  );

  //! Maximum between three inputs
  real_type max(
      const real_type &input0, //!< Input 0
      const real_type &input1, //!< Input 1
      const real_type &input2  //!< Input 2
  );

  //! Minimum between three inputs
  real_type min(
      const real_type &input0, //!< Input 0
      const real_type &input1, //!< Input 1
      const real_type &input2  //!< Input 2
  );

  /*\
   |   _____     _                                        _              
   |  |_   _| __(_) __ _  ___  _ __   ___  _ __ ___   ___| |_ _ __ _   _ 
   |    | || '__| |/ _` |/ _ \| '_ \ / _ \| '_ ` _ \ / _ \ __| '__| | | |
   |    | || |  | | (_| | (_) | | | | (_) | | | | | |  __/ |_| |  | |_| |
   |    |_||_|  |_|\__, |\___/|_| |_|\___/|_| |_| |_|\___|\__|_|   \__, |
   |               |___/                                           |___/ 
  \*/

  //! Sine function [rad]
  real_type sin(
      const real_type &input //!< Input
  );

  //! Cosine function [rad]
  real_type cos(
      const real_type &input //!< Input
  );

  //! Tangent function [rad]
  real_type tan(const real_type &input //!< Input
  );

  //! Arcsine function [rad]
  real_type asin(
      const real_type &input //!< Input
  );

  //! Arccosine function [rad]
  real_type acos(
      const real_type &input //!< Input
  );

  //! Arctangent function [rad]
  real_type atan(
      const real_type &input //!< void
  );

  //! Arctangent function [rad]
  real_type atan2(
      const real_type &input0, //!< Input 0
      const real_type &input1  //!< Input 1
  );

  //! Returns the input input bounded between low and high inputs
  real_type clamp(
      const real_type &input, //!< Input
      const real_type &low,   //!< Low-end bound
      const real_type &high   //!< High-end bound
  );

  //! Checks if elements are almost equal
  bool is_equal(
      const real_type &input0,                  //!< Input 0
      const real_type &input1,                  //!< Input 1
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool is_equal(
      const vector2 &input0,                    //!< Input 0
      const vector2 &input1,                    //!< Input 1
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool is_equal(
      const vector3 &input0,                    //!< Input 0
      const vector3 &input1,                    //!< Input 1
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool is_equal(
      const vector4 &input0,                    //!< Input 0
      const vector4 &input1,                    //!< Input 1
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool is_equal(
      const matrix2 &input0,                    //!< Input 0
      const matrix2 &input1,                    //!< Input 1
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool is_equal(
      const matrix3 &input0,                    //!< Input 0
      const matrix3 &input1,                    //!< Input 1
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool is_equal(
      const matrix4 &input0,                    //!< Input 0
      const matrix4 &input1,                    //!< Input 1
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vector is degenerated
  bool is_degenerated(
      const vector2 &input,                     //!< Input
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vector is degenerated
  bool is_degenerated(
      const vector3 &input,                     //!< Input
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vector is degenerated
  bool is_degenerated(
      const vector4 &input,                     //!< Input
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vector is normalized
  bool is_normalized(
      const vector2 &input,                     //!< Input
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vector is normalized
  bool is_normalized(
      const vector3 &input,                     //!< Input
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vector is normalized
  bool is_normalized(
      const vector4 &input,                     //!< Input
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vectors are ortogonal
  bool is_ortogonal(
      const vector3 &input0,                    //!< Input 0
      const vector3 &input1,                    //!< Input 1
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vectors are parallel
  bool is_parallel(
      const vector3 &input0,                    //!< Input 0
      const vector3 &input1,                    //!< Input 1
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if rotation matrix is othonormal
  bool is_ortonormal(
      const matrix3 &input,                     //!< Input
      const real_type &tolerance = Epsilon_High //!< Tolerance
  );

  //! Returns rotation on x-axis
  matrix3 rotate_x(
      const real_type &input //!< Input angle [rad]
  );

  //! Returns rotation on y-axis
  matrix3 rotate_y(
      const real_type &input //!< Input angle [rad]
  );

  //! Returns rotation on z-axis
  matrix3 rotate_z(
      const real_type &input //!< Input angle [rad]
  );

  //! Angle between objects [rad]
  real_type angle_rad(
      const vector3 &input0, //!< Input 0
      const vector3 &input1  //!< Input 1
  );

  //! Angle between objects [deg]
  real_type angle_deg(
      const vector3 &input0, //!< Input 0
      const vector3 &input1  //!< Input 1
  );

} // namespace acme

#endif

///
/// eof: acme_math.hh
///
