///
/// file: acme.hh
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

#ifndef INCLUDE_ACME
#define INCLUDE_ACME

#include <Eigen/Dense>
#include <cstddef>
#include <limits>
#include <algorithm>
#include <iterator>
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

  typedef double real_type; //!< Real number type
  typedef int int_type;     //!< Integer number type

  /*\
   |  ____                _              _       
   | / ___|___  _ __  ___| |_ __ _ _ __ | |_ ___ 
   || |   / _ \| '_ \/ __| __/ _` | '_ \| __/ __|
   || |__| (_) | | | \__ \ || (_| | | | | |_\__ \
   | \____\___/|_| |_|___/\__\__,_|_| |_|\__|___/
   |                                             
  \*/

  static const real_type Epsilon_Machine = std::numeric_limits<real_type>::epsilon(); //!< Machine espilon \f$ \varepsilon \f$
  static const real_type Epsilon_High = 1.0E-16;                                      //!< High precision epsilon constant
  static const real_type Epsilon_Medium = 1.0E-10;                                    //!< Medium precision epsilon constant
  static const real_type Epsilon_Low = 1.0E-07;                                       //!< Low precision epsilon constant
  static const real_type Epsilon = Epsilon_Medium;                                    //!< Standard precision epsilon constant
  static const real_type Infinity = std::numeric_limits<real_type>::infinity();       //!< Infinity constant

  static const real_type PI = real_type(3.141592653589793238462643383279500);         //!< \f$ \pi \f$ input
  static const real_type PI2 = real_type(6.283185307179586476925286766559000);        //!< \f$ 2\pi \f$ input
  static const real_type PIDiv180 = real_type(0.017453292519943295769236907684886);   //!< \f$ \pi/180 \f$ input
  static const real_type _180DivPI = real_type(57.295779513082320876798154814105000); //!< \f$ 180/\pi \f$ input

  /*\
   |   _____                     _       __     
   |  |_   _|   _ _ __   ___  __| | ___ / _|___ 
   |    | || | | | '_ \ / _ \/ _` |/ _ \ |_/ __|
   |    | || |_| | |_) |  __/ (_| |  __/  _\__ \
   |    |_| \__, | .__/ \___|\__,_|\___|_| |___/
   |        |___/|_|                            
  \*/

  typedef Eigen::Matrix<real_type, 2, 1> vector2; //!< Vector type 2x1 (column vector)
  typedef Eigen::Matrix<real_type, 2, 2> matrix2; //!< Matrix type 2x2

  typedef Eigen::Matrix<real_type, 3, 1> vector3; //!< Vector type 3x1 (column vector)
  typedef Eigen::Matrix<real_type, 3, 3> matrix3; //!< Matrix type 3x3

  typedef Eigen::Matrix<real_type, 4, 1> vector4; //!< Vector type 4x1 (column vector)
  typedef Eigen::Matrix<real_type, 4, 4> matrix4; //!< Matrix type 4x4

  /*\
   |  ____                _              _       
   | / ___|___  _ __  ___| |_ __ _ _ __ | |_ ___ 
   || |   / _ \| '_ \/ __| __/ _` | '_ \| __/ __|
   || |__| (_) | | | \__ \ || (_| | | | | |_\__ \
   | \____\___/|_| |_|___/\__\__,_|_| |_|\__|___/
   |                                             
  \*/

  static const vector2 zeros2 = vector2::Zero();       //!< Infinity constant

} // namespace acme

#endif

///
/// eof: acme.hh
///
