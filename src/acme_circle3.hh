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

#include "acme.hh"
#include "acme_math.hh"

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

  //! Circle class container
  class circle3
  {
    real_type _radius; //!< Circle radius
    plane3 _plane;     //!< Circle plane (circle center + normal vector)

  public:
    //! Class deconstructor
    ~circle3() {}

    //! Class constructor
    circle3() {}

    //! Copy constructor
    circle3(const circle3 &) = default;

    //! Class constructor
    circle3(
        const real_type &radius, //!< Input
        const plane3 &plane      //!< Input
        ) : _radius(radius), _plane(plane)
    {
    }

    //! Class constructor
    circle3(
        const real_type &radius, //!< Input
        const vector3 &center,   //!< Input
        const vector3 &normal    //!< Input
        ) : _radius(radius), _plane(center, normal)
    {
    }

    //! Equality operator
    circle3 &operator=(
        const circle3 &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_radius = input._radius;
        this->_plane = input._plane;
        return *this;
      }
    }

    //! Check if objects are (almost) equal
    bool is_equal(
        const circle3 &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_radius, input._radius) &&
             acme::is_equal(this->_plane.origin(), input._plane.origin()) &&
             acme::is_equal(this->_plane.normal(), input._plane.normal());
    }

    //! Check if ray is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_equal(this->_radius, 0.0);
    }

    //! Get radius
    const real_type radius() const
    {
      return this->_radius;
    }

    //! Get center point
    const vector3 center() const
    {
      return this->_plane.origin();
    }

    //! Get normal vector
    const vector3 normal() const
    {
      return this->_plane.normal();
    }

    //! Set center point
    void radius(
        const real_type &input //!< Input
    )
    {
      this->_radius = input;
    }

    //! Set center point
    void center(
        const vector3 &input //!< Input object
    )
    {
      this->_plane.origin(input);
    }

    //! Set normal vector
    void normal(
        const vector3 &input //!< Input object
    )
    {
      this->_plane.normal(input);
    }

    //! Translate by vector
    void translate(
        const vector3 &input //!< Input object
    )
    {
      this->_origin + input;
    }

    //! Reverse direction
    void reverse(void) { this->_direction = -this->_direction; }
  };

} // namespace acme

#endif

///
/// eof: acme_circle.hh
///