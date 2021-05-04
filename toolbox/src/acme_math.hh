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

} // namespace acme

#endif

///
/// eof: acme_math.hh
///
