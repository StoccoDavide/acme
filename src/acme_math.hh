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

namespace acme
{

  /*\
   |   ____            _                            _              _       
   |  | __ )  __ _ ___(_) ___    ___ ___  _ __  ___| |_ __ _ _ __ | |_ ___ 
   |  |  _ \ / _` / __| |/ __|  / __/ _ \| '_ \/ __| __/ _` | '_ \| __/ __|
   |  | |_) | (_| \__ \ | (__  | (_| (_) | | | \__ \ || (_| | | | | |_\__ \
   |  |____/ \__,_|___/_|\___|  \___\___/|_| |_|___/\__\__,_|_| |_|\__|___/
   |                                                                       
  \*/

  typedef double Float; //!< Real number type
  typedef int Int;      //!< Integer number type

  static const Float Epsilon_Machine = std::numeric_limits<Float>::epsilon(); //!< Machine espilon \f$ \varepsilon \f$
  static const Float Epsilon_High = 1.0E-16;                                  //!< High precision epsilon constant
  static const Float Epsilon_Medium = 1.0E-10;                                //!< Medium precision epsilon constant
  static const Float Epsilon_Low = 1.0E-07;                                   //!< Low precision epsilon constant
  static const Float Epsilon = Epsilon_Medium;                                //!< Standard precision epsilon constant
  static const Float Infinity = std::numeric_limits<Float>::infinity();       //!< Infinity constant

  static const Float PI = Float(3.141592653589793238462643383279500);         //!< \f$ \pi \f$ value
  static const Float PI2 = Float(6.283185307179586476925286766559000);        //!< \f$ 2\pi \f$ value
  static const Float PIDiv180 = Float(0.017453292519943295769236907684886);   //!< \f$ \pi/180 \f$ value
  static const Float _180DivPI = Float(57.295779513082320876798154814105000); //!< \f$ 180/\pi \f$ value

  /*\
   |   __  __       _   _     
   |  |  \/  | __ _| |_| |__  
   |  | |\/| |/ _` | __| '_ \ 
   |  | |  | | (_| | |_| | | |
   |  |_|  |_|\__,_|\__|_| |_|
   |                          
  \*/

  //! Return infinity value
  template <typename T>
  inline T infinity();

  //! Return epsilon value
  template <typename T>
  inline T epsilon();

  //! Return specific double-type epsilon value
  template <>
  inline double epsilon<double>();

  template <>
  //! Return specific float-type epsilon value
  inline float epsilon<float>();

  //! Square function
  template <typename T>
  inline T sqr(
      const T &value //!< Input value
  );

  //! Cubic function
  template <typename T>
  inline T cub(
      const T &value //!< Input value
  );

  //! Square root function
  template <typename T>
  inline T sqrt(
      const T &value //!< Input value
  );

  //! Absolute value function
  template <typename T>
  inline T abs(const T &value //!< Input value
  );

  //! Maximum between values function
  template <typename T>
  inline T max(
      const T &value0, //!< Input value 0
      const T &value1  //!< Input value 1
  );

  //! Minimum between values function
  template <typename T>
  inline T min(
      const T &value0, //!< Input value 0
      const T &value1  //!< Input value 1

  );

  //! Maximum between three values function
  template <typename T>
  inline T max(
      const T &value0, //!< Input value 0
      const T &value1, //!< Input value 1
      const T &value2  //!< Input value 2
  );

  //! Minimum between three values function
  template <typename T>
  inline T min(
      const T &value0, //!< Input value 0
      const T &value1, //!< Input value 1
      const T &value2  //!< Input value 2
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
  template <typename T>
  inline T sin(
      const T &value //!< Input value
  );

  //! Cosine function [rad]
  template <typename T>
  inline T cos(
      const T &value //!< Input value
  );

  //! Tangent function [rad]
  template <typename T>
  inline T tan(const T &value //!< Input value
  );

  //! Arcsine function [rad]
  template <typename T>
  inline T asin(
      const T &value //!< Input value
  );

  //! Arccosine function [rad]
  template <typename T>
  inline T acos(
      const T &value //!< Input value
  );

  //! Arctangent function [rad]
  template <typename T>
  inline T atan(
      const T &value //!< Input value
  );

  //! Arctangent function [rad]
  template <typename T>
  inline T atan2(
      const T &value0, //!< Input value 0
      const T &value1  //!< Input value 1
  );

  //! Clamp function (returns the input value bounded between low and high values)
  template <typename T>
  inline T clamp(
      const T &value, //!< Input value
      const T &low,   //!< Low end bound
      const T &high   //!< High end bound
  );

  //! Check if elements are almost equal
  template <typename T>
  inline T is_equal(
      const T &value0,                  //!< Input value 0
      const T &value1,                  //!< Input value 1
      const T &tolerance = Epsilon_High //!< High end bound
  );

  //! Get rotation on x-axis
  template <typename T>
  inline Eigen::Matrix<T, 3, 3> rotate_x(
      const T &input //!< Input angle [rad]
  );

  //! Get rotation on y-axis
  template <typename T>
  inline Eigen::Matrix<T, 3, 3> rotate_y(
      const T &input //!< Input angle [rad]
  );

  //! Get rotation on z-axis
  template <typename T>
  inline Eigen::Matrix<T, 3, 3> rotate_z(
      const T &input //!< Input angle [rad]
  );

} // namespace acme

#include "acme_math.inl"

#endif

///
/// eof: acme_math.hh
///
