///
/// file: acme_circle.hh
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

#ifndef INCLUDE_ACME_CIRCLE3
#define INCLUDE_ACME_CIRCLE3

#include "acme_point3.hh"

namespace acme
{

  /*\
   |        _          _      _____ 
   |    ___(_)_ __ ___| | ___|___ / 
   |   / __| | '__/ __| |/ _ \ |_ \ 
   |  | (__| | | | (__| |  __/___) |
   |   \___|_|_|  \___|_|\___|____/ 
   |                                
  \*/

  //! Sphere class container
  template <typename T = Float>
  class circle3
  {
    point3<T> _center; //!< Sphere center
    T _radius;        //!< Sphere radius

  public:
    //! Copy constructor
    circle3(const circle3<T> &) = default;

    //! Class constructor
    circle3() : _center(point3<T>()), _radius(T()) {}

    //! Return sphere point
    inline const point3<T> &center() const
    {
      return _center;
    }

    //! Return sphere radiuszz
    inline const T &radius() const
    {
      return _radius;
    }
  };

} // namespace acme

#endif

///
/// eof: acme_circle.hh
///