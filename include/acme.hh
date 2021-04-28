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
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: davide.stocco@unitn.it                                   *)
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

// Standard libraries
#include <memory>
#include <cstddef>
#include <limits>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

//!  Namespace containing all acme typedefs, classes and routines
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
  typedef std::ostream ostream_type; //!< Output stream type¯

  /*\
   |    ____                _              _       
   |   / ___|___  _ __  ___| |_ __ _ _ __ | |_ ___ 
   |  | |   / _ \| '_ \/ __| __/ _` | '_ \| __/ __|¯
   |  | |__| (_) | | | \__ \ || (_| | | | | |_\__ \
   |   \____\___/|_| |_|___/\__\__,_|_| |_|\__|___/
   |                                               
  \*/

  static real_type const Epsilon_Machine = std::numeric_limits<real_type>::epsilon(); //!< Machine epsilon \f$ \varepsilon \f$
  static real_type const Epsilon_High = 1.0E-16;                                      //!< High precision epsilon
  static real_type const Epsilon_Medium = 1.0E-10;                                    //!< Medium precision epsilon
  static real_type const Epsilon_Low = 1.0E-07;                                       //!< Low precision epsilon
  static real_type const Epsilon = Epsilon_Medium;                                    //!< Standard precision epsilon
  static real_type const Infinity = std::numeric_limits<real_type>::infinity();       //!< Infinity
  static real_type const NaN = std::numeric_limits<real_type>::quiet_NaN();           //!< Not-a-Number type

  static real_type const PI = real_type(3.141592653589793238462643383279500);         //!< \f$ \pi \f$ input
  static real_type const PI2 = real_type(6.283185307179586476925286766559000);        //!< \f$ 2\pi \f$ input
  static real_type const PIdiv180 = real_type(0.017453292519943295769236907684886);   //!< \f$ \pi/180 \f$ input
  static real_type const _180divPI = real_type(57.295779513082320876798154814105000); //!< \f$ 180/\pi \f$ input

} // namespace acme

#endif

///
/// eof: acme.hh
///
