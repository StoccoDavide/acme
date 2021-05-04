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
/// file: acme_math.hh
///

#ifndef INCLUDE_ACME_MATH
#define INCLUDE_ACME_MATH

#include <cmath>

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
  real
  infinity(void);

  //! Return epsilon
  real
  epsilon(void);

  //! Square
  real
  sqr(
      real input //!< Input
  );

  //! Cubic
  real
  cub(
      real input //!< Input
  );

  //! Square root
  real
  sqrt(
      real input //!< Input
  );

  //! Power
  real
  pow(
      real base,    //!< Input base
      real exponent //!< Input exponent
  );

  //! Absolute value
  real
  abs(
      real input //!< Input value
  );

  //! Maximum between inputs
  real
  max(
      real input0, //!< Input value 0
      real input1  //!< Input value 1
  );

  //! Minimum between inputs
  real
  min(
      real input0, //!< Input value 0
      real input1  //!< Input value 1
  );

  //! Maximum between three inputs
  real
  max(
      real input0, //!< Input value 0
      real input1, //!< Input value 1
      real input2  //!< Input value 2
  );

  //! Minimum between three inputs
  real
  min(
      real input0, //!< Input value 0
      real input1, //!< Input value 1
      real input2  //!< Input value 2
  );

  //! Sine function [rad]
  real
  sin(
      real input //!< Input value
  );

  //! Cosine function [rad]
  real
  cos(
      real input //!< Input value
  );

  //! Tangent function [rad]
  real
  tan(
      real input //!< Input value
  );

  //! Arcsine function [rad]
  real
  asin(
      real input //!< Input value
  );

  //! Arccosine function [rad]
  real
  acos(
      real input //!< Input value
  );

  //! Arctangent function [rad]
  real
  atan(
      real input //!< Input value
  );

  //! Arctangent function [rad]
  real
  atan2(
      real input0, //!< Input value 0
      real input1  //!< Input value 1
  );

  //! Returns the input input bounded between low and high inputs
  real
  clamp(
      real input, //!< Input value
      real low,   //!< Low-end bound
      real high   //!< High-end bound
  );

  //! Checks if elements are almost equal
  bool
  isApprox(
      real input0,             //!< Input value 0
      real input1,             //!< Input value 1
      real tolerance = Epsilon //!< Tolerance
  );

  //! Returns a rotation as a rotation angle around an arbitrary axis
  angleaxis
  rotate(
      real angle,      //!< Input angle [rad]
      vec3 const &axis //!< Input axis
  );

  //! Returns a rotation as a rotation angle around an arbitrary axis
  angleaxis
  rotate(
      real angle,             //!< Input angle [rad]
      std::string const &axis //!< Input axis
  );

  //! Angle between vectors [rad]
  real
  angle(
      vec3 const &input0, //!< Input vector 0
      vec3 const &input1  //!< Input vector 1
  );

  //! Calculate Euler angles [rad]
  void
  eulerAngles(
      mat3 const &rotation, //!< 3x3 rotation matrix
      integer i,            //!< Rotation index
      integer j,            //!< Rotation index
      integer k,            //!< Rotation index
      vec3 &angles          //!< Output euler angles [rad]
  );

} // namespace acme

#endif

///
/// eof: acme_math.hh
///
