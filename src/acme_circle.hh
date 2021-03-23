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

#ifndef INCLUDE_ACME_CIRCLE
#define INCLUDE_ACME_CIRCLE

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |        _          _      
   |    ___(_)_ __ ___| | ___ 
   |   / __| | '__/ __| |/ _ \
   |  | (__| | | | (__| |  __/
   |   \___|_|_|  \___|_|\___|
   |                          
  \*/

  //! Circle class container
  class circle
  {
    real_type _radius; //!< Circle radius
    plane _plane;     //!< Circle plane (circle center + normal vector)

  public:
    //! Class deconstructor
    ~circle() {}

    //! Class constructor
    circle() {}

    //! Copy constructor
    circle(const circle &) = default;

    //! Class constructor
    circle(
        const real_type &radius, //!< Input
        const plane &plane      //!< Input
        ) : _radius(radius), _plane(plane)
    {
    }

    //! Class constructor
    circle(
        const real_type &radius, //!< Input
        const vector &center,   //!< Input
        const vector &normal    //!< Input
        ) : _radius(radius), _plane(center, normal)
    {
    }

    //! Equality operator
    circle &operator=(
        const circle &input //!< Input object
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
        const circle &input //!< Input object
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
    const vector center() const
    {
      return this->_plane.origin();
    }

    //! Get normal vector
    const vector normal() const
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
        const vector &input //!< Input object
    )
    {
      this->_plane.origin(input);
    }

    //! Set normal vector
    void normal(
        const vector &input //!< Input object
    )
    {
      this->_plane.normal(input);
    }

    //! Translate by vector
    void translate(
        const vector &input //!< Input
    )
    {
      this->_origin = input + this->_origin;
      this->_plane.translate(input);
    }

    //! Rotate by matrix
    void rotate(
        const matrix &input //!< Input
    )
    {
      this->_origin = input * this->_origin;
      this->_plane.rotate(input);
    }

    //! Reverse direction
    void reverse(void) { this->_direction = -this->_direction; }
  };

} // namespace acme

#endif

///
/// eof: acme_circle.hh
///