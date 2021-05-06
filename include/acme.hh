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
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <vector>

// Eigen libraries
#include <Eigen/Dense>

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

  typedef double real; //!< Real number type
  typedef int integer; //!< Integer number type

  typedef std::ostream out_stream; //!< Output stream type

  static real const Epsilon_Machine = std::numeric_limits<real>::epsilon(); //!< Machine epsilon \f$ \varepsilon \f$
  static real const Epsilon_High = 1.0E-16;                                 //!< High precision epsilon
  static real const Epsilon_Medium = 1.0E-10;                               //!< Medium precision epsilon
  static real const Epsilon_Low = 1.0E-07;                                  //!< Low precision epsilon
  static real const Epsilon = Epsilon_Medium;                               //!< Standard precision epsilon
  static real const Infinity = std::numeric_limits<real>::infinity();       //!< Infinity
  static real const NaN = std::numeric_limits<real>::quiet_NaN();           //!< Not-a-Number type

  static real const PI = real(3.141592653589793238462643383279500);         //!< \f$ \pi \f$ input
  static real const PI2 = real(6.283185307179586476925286766559000);        //!< \f$ 2\pi \f$ input
  static real const PIdiv180 = real(0.017453292519943295769236907684886);   //!< \f$ \pi/180 \f$ input
  static real const _180divPI = real(57.295779513082320876798154814105000); //!< \f$ 180/\pi \f$ input

  /*\
   |   _____ _                  
   |  | ____(_) __ _  ___ _ __  
   |  |  _| | |/ _` |/ _ \ '_ \ 
   |  | |___| | (_| |  __/ | | |
   |  |_____|_|\__, |\___|_| |_|
   |           |___/            
  \*/

  typedef Eigen::Matrix<real, Eigen::Dynamic, 1> vecN;              //!< Nx1 vector of real number type (column vector)
  typedef Eigen::Matrix<real, Eigen::Dynamic, Eigen::Dynamic> matN; //!< NxN matrix of real number type

  typedef Eigen::Matrix<real, 2, 1> vec2;                               //!< 2x1 vector type (column vector)
  typedef Eigen::Matrix<real, 2, 2> mat2;                               //!< 2x2 matrix type
  typedef Eigen::Matrix<vec2, Eigen::Dynamic, 1> vec_vec2;              //!< Nx1 vector of 2x1 vector type (column vector)
  typedef Eigen::Matrix<mat2, Eigen::Dynamic, 1> vec_mat2;              //!< Nx1 vector of 2x2 matrix type
  typedef Eigen::Matrix<vec2, Eigen::Dynamic, Eigen::Dynamic> mat_vec2; //!< NxN matrix of 2x1 vector type (column vector)
  typedef Eigen::Matrix<mat2, Eigen::Dynamic, Eigen::Dynamic> mat_mat2; //!< NxN matrix of 2x2 matrix type

  typedef Eigen::Matrix<real, 3, 1> vec3;                               //!< 3x1 vector type (column vector)
  typedef Eigen::Matrix<real, 3, 3> mat3;                               //!< 3x3 matrix type
  typedef Eigen::Matrix<vec3, Eigen::Dynamic, 1> vec_vec3;              //!< Nx1 vector of 3x1 vector type (column vector)
  typedef Eigen::Matrix<mat3, Eigen::Dynamic, 1> vec_mat3;              //!< Nx1 vector of 3x3 matrix type
  typedef Eigen::Matrix<vec3, Eigen::Dynamic, Eigen::Dynamic> mat_vec3; //!< NxN matrix of 3x1 vector type (column vector)
  typedef Eigen::Matrix<mat3, Eigen::Dynamic, Eigen::Dynamic> mat_mat3; //!< NxN matrix of 3x3 matrix type

  typedef Eigen::Matrix<real, 4, 1> vec4;                               //!< 4x1 vector type (column vector)
  typedef Eigen::Matrix<real, 4, 4> mat4;                               //!< 4x4 matrix type
  typedef Eigen::Matrix<vec4, Eigen::Dynamic, 1> vec_vec4;              //!< Nx1 vector of 4x1 vector type (column vector)
  typedef Eigen::Matrix<mat4, Eigen::Dynamic, 1> vec_mat4;              //!< Nx1 vector of 4x4 matrix type
  typedef Eigen::Matrix<vec4, Eigen::Dynamic, Eigen::Dynamic> mat_vec4; //!< NxN matrix of 4x1 vector type (column vector)
  typedef Eigen::Matrix<mat4, Eigen::Dynamic, Eigen::Dynamic> mat_mat4; //!< NxN matrix of 4x4 matrix type

  typedef Eigen::DiagonalMatrix<real, 3> scale;                      //!< 3D scaling transformation type
  typedef Eigen::Translation<real, 3> translate;                     //!< 3D translation transformation type
  typedef Eigen::AngleAxis<real> angleaxis;                          //!< 3D rotation transformation type
  typedef Eigen::Transform<real, 3, Eigen::Affine> affine;           //!< 3D affine transformation type
  typedef Eigen::Matrix<scale, Eigen::Dynamic, 1> vec_scale;         //!< Nx1 vector of 3D scaling transformation type
  typedef Eigen::Matrix<translate, Eigen::Dynamic, 1> vec_translate; //!< Nx1 vector of 3D translation transformation type
  typedef Eigen::Matrix<angleaxis, Eigen::Dynamic, 1> vec_angleaxis; //!< Nx1 vector of 3D rotation transformation type
  typedef Eigen::Matrix<affine, Eigen::Dynamic, 1> vec_affine;       //!< Nx1 vector of 3D affine transformation type

  /*\
   |    ____                _              _       
   |   / ___|___  _ __  ___| |_ __ _ _ __ | |_ ___ 
   |  | |   / _ \| '_ \/ __| __/ _` | '_ \| __/ __|
   |  | |__| (_) | | | \__ \ || (_| | | | | |_\__ \
   |   \____\___/|_| |_|___/\__\__,_|_| |_|\__|___/
   |                                               
  \*/

  static vec2 const UnitX_vec2 = vec2::UnitX();       //!< X axis unit vec2 type
  static vec2 const UnitY_vec2 = vec2::UnitY();       //!< Y axis unit vec2 type
  static vec2 const NaN_vec2 = vec2::Constant(NaN);   //!< Not-a-Number vec2 type
  static mat2 const NaN_mat2 = mat2::Constant(NaN);   //!< Not-a-Number mat2 type
  static vec2 const Zeros_vect2 = vec2::Zero();       //!< Zeros vec2 type
  static mat2 const Zeros_mat2 = mat2::Zero();        //!< Zeros mat2 type
  static vec2 const Ones_vec2 = vec2::Constant(1.0);  //!< Ones vec2 type
  static mat2 const Ones_mat2 = mat2::Constant(1.0);  //!< Ones mat2 type
  static mat2 const Identity_mat2 = mat2::Identity(); //!< Identity mat2 type

  static vec3 const UnitX_vec3 = vec3::UnitX();       //!< X axis unit vec3 type
  static vec3 const UnitY_vec3 = vec3::UnitY();       //!< Y axis unit vec3 type
  static vec3 const UnitZ_vec3 = vec3::UnitZ();       //!< Z axis unit vec3 type
  static vec3 const NaN_vec3 = vec3::Constant(NaN);   //!< Not-a-Number vec3 type
  static mat3 const NaN_mat3 = mat3::Constant(NaN);   //!< Not-a-Number mat3 type
  static vec3 const Zeros_vec3 = vec3::Zero();        //!< Zeros vec3 type
  static mat3 const Zeros_mat3 = mat3::Zero();        //!< Zeros mat3 type
  static vec3 const Ones_vec3 = vec3::Constant(1.0);  //!< Ones vec3 type
  static mat3 const Ones_mat3 = mat3::Constant(1.0);  //!< Ones mat3 type
  static mat3 const Identity_mat3 = mat3::Identity(); //!< Identity mat3 type

  static vec4 const UnitX_vec4 = vec4::UnitX();       //!< X axis unit vec4 type
  static vec4 const UnitY_vec4 = vec4::UnitY();       //!< Y axis unit vec4 type
  static vec4 const UnitZ_vec4 = vec4::UnitZ();       //!< Z axis unit vec4 type
  static vec4 const UnitW_vec4 = vec4::UnitW();       //!< W axis unit vec4 type
  static vec4 const NaN_vec4 = vec4::Constant(NaN);   //!< Not-a-Number vec4 type
  static mat4 const NaN_mat4 = mat4::Constant(NaN);   //!< Not-a-Number mat4 type
  static vec4 const Zeros_vec4 = vec4::Zero();        //!< Zeros vec4 type
  static mat4 const Zeros_mat4 = mat4::Zero();        //!< Zeros mat4 type
  static vec4 const Ones_vec4 = vec4::Constant(1.0);  //!< Ones vec4 type
  static mat4 const Ones_mat4 = mat4::Constant(1.0);  //!< Ones mat4 type
  static mat4 const Identity_mat4 = mat4::Identity(); //!< Identity mat4 type

  static vec2 vec2_goat = vec2(NaN_vec2); //!< Scapegoat vec2 type (throwaway non-const object)
  static vec3 vec3_goat = vec3(NaN_vec3); //!< Scapegoat vec3 type (throwaway non-const object)
  static vec4 vec4_goat = vec4(NaN_vec4); //!< Scapegoat vec4 type (throwaway non-const object)
  static mat2 mat2_goat = mat2(NaN_mat2); //!< Scapegoat mat2 type (throwaway non-const object)
  static mat3 mat3_goat = mat3(NaN_mat3); //!< Scapegoat mat3 type (throwaway non-const object)
  static mat4 mat4_goat = mat4(NaN_mat4); //!< Scapegoat mat4 type (throwaway non-const object)

  /*\
   |   _____                     __                      
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
   |                                                     
  \*/

  //! Transform ve3 with affine transformation matrix
  void
  transform(
      vec3 &vector,        //!< Input ve3
      affine const &matrix //!< 4x4 transformation matrix
  );

} // namespace acme

#endif

///
/// eof: acme.hh
///
