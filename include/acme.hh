/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(* Release Version 0.0.0                                               *)
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

///
/// file: acme.hh
///

#ifndef INCLUDE_ACME
#define INCLUDE_ACME

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
  ACME_ERROR(MSG)
#endif

#include <memory>
#include <Eigen/Dense>
#include <cstddef>
#include <limits>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

//! Namepaces containing all objects classes and routines
namespace acme
{

  /*\
   |   _____                     _       __     
   |  |_   _|   _ _ __   ___  __| | ___ / _|___ 
   |    | || | | | '_ \ / _ \/ _` |/ _ \ |_/ __|
   |    | || |_| | |_) |  __/ (_| |  __/  _\__ \
   |    |_| \__, | .__/ \___|\__,_|\___|_| |___/
   |        |___/|_|                            
  \*/

  typedef double real_type;          //!< Real number type
  typedef int int_type;              //!< Integer number type
  typedef std::ostream ostream_type; //!< Output stream type

  typedef Eigen::Matrix<real_type, 2, 1> vec2; //!< Vector type 2x1 (column vector)
  typedef Eigen::Matrix<real_type, 2, 2> mat2; //!< Matrix type 2x2

  typedef Eigen::Matrix<real_type, 3, 1> vec3; //!< Vector type 3x1 (column vector)
  typedef Eigen::Matrix<real_type, 3, 3> mat3; //!< Matrix type 3x3

  typedef Eigen::Matrix<real_type, 4, 1> vec4; //!< Vector type 4x1 (column vector)
  typedef Eigen::Matrix<real_type, 4, 4> mat4; //!< Matrix type 4x4

  /*\
   |    ____                _              _       
   |   / ___|___  _ __  ___| |_ __ _ _ __ | |_ ___ 
   |  | |   / _ \| '_ \/ __| __/ _` | '_ \| __/ __|
   |  | |__| (_) | | | \__ \ || (_| | | | | |_\__ \
   |   \____\___/|_| |_|___/\__\__,_|_| |_|\__|___/
   |                                               
  \*/

  static real_type const Epsilon_Machine = std::numeric_limits<real_type>::epsilon(); //!< Machine espilon \f$ \varepsilon \f$
  static real_type const Epsilon_High = 1.0E-16;                                      //!< High precision epsilon constant
  static real_type const Epsilon_Medium = 1.0E-10;                                    //!< Medium precision epsilon constant
  static real_type const Epsilon_Low = 1.0E-07;                                       //!< Low precision epsilon constant
  static real_type const Epsilon = Epsilon_Medium;                                    //!< Standard precision epsilon constant
  static real_type const Infinity = std::numeric_limits<real_type>::infinity();       //!< Infinity constant
  static real_type const NaN = std::numeric_limits<real_type>::quiet_NaN();           //!< Not-a-Number type

  static real_type const PI = real_type(3.141592653589793238462643383279500);         //!< \f$ \pi \f$ input
  static real_type const PI2 = real_type(6.283185307179586476925286766559000);        //!< \f$ 2\pi \f$ input
  static real_type const PIDiv180 = real_type(0.017453292519943295769236907684886);   //!< \f$ \pi/180 \f$ input
  static real_type const _180DivPI = real_type(57.295779513082320876798154814105000); //!< \f$ 180/\pi \f$ input

  static vec2 const NaN_vec2 = vec2::Constant(NaN);    //!< Not-a-Number vec2 type
  static mat2 const NaN_mat2 = mat2::Constant(NaN);    //!< Not-a-Number mat2 type
  static vec2 const Zeros_vect2 = vec2::Constant(0.0); //!< Zeros vec2 type
  static mat2 const Zeros_mat2 = mat2::Constant(0.0);  //!< Zeros mat2 type
  static vec2 const Ones_vec2 = vec2::Constant(1.0);   //!< Ones vec2 type
  static mat2 const Ones_mat2 = mat2::Constant(1.0);   //!< Ones mat2 type

  static vec3 const NaN_vec3 = vec3::Constant(NaN);   //!< Not-a-Number vec3 type
  static mat3 const NaN_mat3 = mat3::Constant(NaN);   //!< Not-a-Number mat3 type
  static vec3 const Zeros_vec3 = vec3::Constant(0.0); //!< Zeros vec3 type
  static mat3 const Zeros_mat3 = mat3::Constant(0.0); //!< Zeros mat3 type
  static vec3 const Ones_vec3 = vec3::Constant(1.0);  //!< Ones vec3 type
  static mat3 const Ones_mat3 = mat3::Constant(1.0);  //!< Ones mat3 type

  static vec4 const NaN_vec4 = vec4::Constant(NaN);   //!< Not-a-Number vec4 type
  static mat4 const NaN_mat4 = mat4::Constant(NaN);   //!< Not-a-Number mat4 type
  static vec4 const Zeros_vec4 = vec4::Constant(0.0); //!< Zeros vec4 type
  static mat4 const Zeros_mat4 = mat4::Constant(0.0); //!< Zeros mat4 type
  static vec4 const Ones_vec4 = vec4::Constant(1.0);  //!< Ones vec4 type
  static mat4 const Ones_mat4 = mat4::Constant(1.0);  //!< Ones mat4 type

  static vec2 vec2_goat = vec2(NaN_vec2); //!< Scapegoat vec2 type (throwaway non-const object)
  static vec3 vec3_goat = vec3(NaN_vec3); //!< Scapegoat vec3 type (throwaway non-const object)
  static vec4 vec4_goat = vec4(NaN_vec4); //!< Scapegoat vec4 type (throwaway non-const object)
  static mat2 mat2_goat = mat2(NaN_mat2); //!< Scapegoat mat2 type (throwaway non-const object)
  static mat3 mat3_goat = mat3(NaN_mat3); //!< Scapegoat mat3 type (throwaway non-const object)
  static mat4 mat4_goat = mat4(NaN_mat4); //!< Scapegoat mat4 type (throwaway non-const object)

} // namespace acme

//!< Overload stream out operator for acme::vec2 object
std::ostream &operator<<(
    std::ostream &os,     //!< Output stream
    acme::vec2 const &obj //!< Vector object
);

//!< Overload stream out operator for acme::mat2 object
std::ostream &operator<<(
    std::ostream &os,     //!< Output stream
    acme::mat2 const &obj //!< Vector object
);

//!< Overload stream out operator for acme::vec3 object
std::ostream &operator<<(
    std::ostream &os,     //!< Output stream
    acme::vec3 const &obj //!< Vector object
);

//!< Overload stream out operator for acme::mat3 object
std::ostream &operator<<(
    std::ostream &os,     //!< Output stream
    acme::mat3 const &obj //!< Vector object
);

//!< Overload stream out operator for acme::vec4 object
std::ostream &operator<<(
    std::ostream &os,     //!< Output stream
    acme::vec4 const &obj //!< Vector object
);

//!< Overload stream out operator for acme::mat4 object
std::ostream &operator<<(
    std::ostream &os,     //!< Output stream
    acme::mat4 const &obj //!< Vector object
);

#endif

///
/// eof: acme.hh
///
