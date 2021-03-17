///
/// file: ddd_circle.hh
///

/*
(***********************************************************************)
(*                                                                     *)
(* The ddd computational geometry library                              *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The ddd computational geometry library and its components are       *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the ddd computational geometry library and its      *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

#ifndef INCLUDE_ACME_CIRCLE
#define INCLUDE_ACME_CIRCLE

#include "ddd_point.hh"

namespace ddd
{

  /*\
   |             _                   
   |   ___ _ __ | |__   ___ _ __ ___ 
   |  / __| '_ \| '_ \ / _ \ '__/ _ \
   |  \__ \ |_) | | | |  __/ | |  __/
   |  |___/ .__/|_| |_|\___|_|  \___|
   |      |_|                        
  \*/

  //! Sphere class container
  template <typename T = Float>
  class sphere
  {
    point<T> _center; //!< Sphere center
    T _radius;        //!< Sphere radius

  public:
    //! Copy constructor
    sphere(const sphere<T> &) = default;

    //! Class constructor
    sphere() : _center(point<T>()), _radius(T()) {}

    //! Return sphere point
    inline const point<T> &Center() const
    {
      return _center;
    }

    //! Return sphere radiuszz
    inline const T &Radius() const
    {
      return _radius;
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_circle.hh
///