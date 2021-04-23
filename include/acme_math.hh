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
/// file: acme_math.hh
///

#ifndef INCLUDE_ACME_MATH
#define INCLUDE_ACME_MATH

#include "acme.hh"

#include <Eigen/Geometry>

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
  real_type
  infinity(void);

  //! Return epsilon
  real_type
  epsilon(void);

  //! Square
  real_type
  sqr(
      real_type input //!< Input
  );

  //! Cubic
  real_type
  cub(
      real_type input //!< Input
  );

  //! Square root
  real_type
  sqrt(
      real_type input //!< Input
  );

  //! Power
  real_type
  pow(
      real_type base,    //!< Input base
      real_type exponent //!< Input exponent
  );

  //! Absolute value
  real_type
  abs(
      real_type input //!< Input value
  );

  //! Maximum between inputs
  real_type
  max(
      real_type input0, //!< Input value 0
      real_type input1  //!< Input value 1
  );

  //! Minimum between inputs
  real_type
  min(
      real_type input0, //!< Input value 0
      real_type input1  //!< Input value 1

  );

  //! Maximum between three inputs
  real_type
  max(
      real_type input0, //!< Input value 0
      real_type input1, //!< Input value 1
      real_type input2  //!< Input value 2
  );

  //! Minimum between three inputs
  real_type
  min(
      real_type input0, //!< Input value 0
      real_type input1, //!< Input value 1
      real_type input2  //!< Input value 2
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
  real_type
  sin(
      real_type input //!< Input value
  );

  //! Cosine function [rad]
  real_type
  cos(
      real_type input //!< Input value
  );

  //! Tangent function [rad]
  real_type
  tan(
      real_type input //!< Input value
  );

  //! Arcsine function [rad]
  real_type
  asin(
      real_type input //!< Input value
  );

  //! Arccosine function [rad]
  real_type
  acos(
      real_type input //!< Input value
  );

  //! Arctangent function [rad]
  real_type
  atan(
      real_type input //!< Input value
  );

  //! Arctangent function [rad]
  real_type
  atan2(
      real_type input0, //!< Input value 0
      real_type input1  //!< Input value 1
  );

  //! Returns the input input bounded between low and high inputs
  real_type
  clamp(
      real_type input, //!< Input value
      real_type low,   //!< Low-end bound
      real_type high   //!< High-end bound
  );

  //! Checks if elements are almost equal
  bool
  isApprox(
      real_type input0,             //!< Input value 0
      real_type input1,             //!< Input value 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool
  isApprox(
      vec3 const &input0,           //!< Input value 0
      vec3 const &input1,           //!< Input value 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Checks if elements are almost equal
  bool
  isApprox(
      mat3 const &input0,           //!< Input value 0
      mat3 const &input1,           //!< Input value 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if vec3 is degenerated
  bool
  isDegenerated(
      vec3 const &input,            //!< Input vector
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if vectors are parallel
  bool
  isParallel(
      vec3 const &input0,           //!< Input vector 0
      vec3 const &input1,           //!< Input vector 1
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Check if 3x3 matrix is othonormal
  bool
  isOrthonormal(
      mat3 const &input,            //!< Input value
      real_type tolerance = Epsilon //!< Tolerance
  );

  //! Returns a rotation as a rotation angle around an arbitrary axis
  angleaxis
  rotate(
      real_type angle, //!< Input angle [rad]
      vec3 const &axis //!< Input axis

  );

  //! Returns a rotation as a rotation angle around an arbitrary axis
  angleaxis
  rotate(
      real_type angle,        //!< Input angle [rad]
      std::string const &axis //!< Input axis
  );

  //! Angle between vectors [rad]
  real_type
  angle(
      vec3 const &input0, //!< Input vector 0
      vec3 const &input1  //!< Input vector 1
  );

  //! Calculate Euler angles [rad]
  void
  eulerAngles(
      mat3 const &rotation, //!< 3x3 rotation matrix
      size_t i,             //!< Rotation index
      size_t j,             //!< Rotation index
      size_t k,             //!< Rotation index
      vec3 &angles          //!< Output euler angles [rad]
  );

  /*\
   |   _____                     __                      
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
   |                                                     
  \*/

  //! Transform VECTOR with affine transformation matrix
  void
  transformVector(
      vec3 &vector,        //!< Input vector
      affine const &matrix //!< 4x4 transformation matrix
  );

  //! Transform POINT with affine transformation matrix
  void
  transformPoint(
      vec3 &vector,        //!< Input point
      affine const &matrix //!< 4x4 transformation matrix
  );

} // namespace acme

#endif

///
/// eof: acme_math.hh
///
