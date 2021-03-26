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
/// file: acme_math.hh
///

#ifndef INCLUDE_ACME_MATH
#define INCLUDE_ACME_MATH

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
      real_type const input //!< Input
  );

  //! Cubic
  real_type cub(
      real_type const input //!< Input
  );

  //! Square root
  real_type sqrt(
      real_type const input //!< Input
  );

  //! Absolute value
  real_type abs(real_type const input //!< Input
  );

  //! Maximum between inputs
  real_type max(
      real_type const input0, //!< Input 0
      real_type const input1  //!< Input 1
  );

  //! Minimum between inputs
  real_type min(
      real_type const input0, //!< Input 0
      real_type const input1  //!< Input 1

  );

  //! Maximum between three inputs
  real_type max(
      real_type const input0, //!< Input 0
      real_type const input1, //!< Input 1
      real_type const input2  //!< Input 2
  );

  //! Minimum between three inputs
  real_type min(
      real_type const input0, //!< Input 0
      real_type const input1, //!< Input 1
      real_type const input2  //!< Input 2
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
      real_type const input //!< Input
  );

  //! Cosine function [rad]
  real_type cos(
      real_type const input //!< Input
  );

  //! Tangent function [rad]
  real_type tan(real_type const input //!< Input
  );

  //! Arcsine function [rad]
  real_type asin(
      real_type const input //!< Input
  );

  //! Arccosine function [rad]
  real_type acos(
      real_type const input //!< Input
  );

  //! Arctangent function [rad]
  real_type atan(
      real_type const input //!< void
  );

  //! Arctangent function [rad]
  real_type atan2(
      real_type const input0, //!< Input 0
      real_type const input1  //!< Input 1
  );

  //! Returns the input input bounded between low and high inputs
  real_type clamp(
      real_type const input, //!< Input
      real_type const low,   //!< Low-end bound
      real_type const high   //!< High-end bound
  );

  //! Checks if elements are almost equal
  bool is_equal(
      real_type const input0,                  //!< Input 0
      real_type const input1,                  //!< Input 1
      real_type const tolerance = Epsilon_High //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool is_equal(
      vec3 const &input0,                      //!< Input 0
      vec3 const &input1,                      //!< Input 1
      real_type const tolerance = Epsilon_High //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool is_equal(
      mat3 const &input0,                      //!< Input 0
      mat3 const &input1,                      //!< Input 1
      real_type const tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vec3 is degenerated
  bool is_degenerated(
      vec3 const &input,                       //!< Input
      real_type const tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vec3 is normalized
  bool is_normalized(
      vec3 const &input,                       //!< Input
      real_type const tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vectors are ortogonal
  bool is_ortogonal(
      vec3 const &input0,                      //!< Input 0
      vec3 const &input1,                      //!< Input 1
      real_type const tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if vectors are parallel
  bool is_parallel(
      vec3 const &input0,                      //!< Input 0
      vec3 const &input1,                      //!< Input 1
      real_type const tolerance = Epsilon_High //!< Tolerance
  );

  //! Check if rotation mat3 is othonormal
  bool is_ortonormal(
      mat3 const &input,                       //!< Input
      real_type const tolerance = Epsilon_High //!< Tolerance
  );

  //! Returns rotation on x-axis
  mat3 rotation_x(
      real_type const input //!< Input angle [rad]
  );

  //! Returns rotation on y-axis
  mat3 rotation_y(
      real_type const input //!< Input angle [rad]
  );

  //! Returns rotation on z-axis
  mat3 rotation_z(
      real_type const input //!< Input angle [rad]
  );

  //! Angle between objects [rad]
  real_type angle_rad(
      vec3 const &input0, //!< Input 0
      vec3 const &input1  //!< Input 1
  );

  //! Angle between objects [deg]
  real_type angle_deg(
      vec3 const &input0, //!< Input 0
      vec3 const &input1  //!< Input 1
  );

} // namespace acme

#endif

///
/// eof: acme_math.hh
///
