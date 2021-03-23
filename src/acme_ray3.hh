///
/// file: acme_ray3.hh
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

#ifndef INCLUDE_ACME_RAY3
#define INCLUDE_ACME_RAY3

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |                   _____ 
   |   _ __ __ _ _   _|___ / 
   |  | '__/ _` | | | | |_ \ 
   |  | | | (_| | |_| |___) |
   |  |_|  \__,_|\__, |____/ 
   |             |___/       
  \*/

  //! Ray class container
  class ray3
  {
  private:
    vector3 _origin;    //!< Origin
    vector3 _direction; //!< Direction

  public:
    //! Class destructor
    ~ray3() {}

    //! Class constructor
    ray3() {}

    //! Copy constructor
    ray3(const ray3 &) = default;

    //! Class constructor
    ray3(
        const real_type &ox, //<! Input x origin value
        const real_type &oy, //<! Input y origin value
        const real_type &oz, //<! Input z origin value
        const real_type &dx, //<! Input x direction value
        const real_type &dy, //<! Input y direction value
        const real_type &dz  //<! Input z direction value
        ) : _origin(vector3(ox, oy, oz)), _direction(vector3(dx, dy, dz))
    {
    }

    //! Class constructor
    ray3(
        const vector3 &origin,   //!< Input origin
        const vector3 &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Equality operator
    ray3 &operator=(
        const ray3 &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_origin = input._origin;
        this->_direction = input._direction;
        return *this;
      }
    }

    //! Check if objects are (almost) equal
    bool is_equal(
        const ray3 &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_origin, input._origin) &&
             acme::is_equal(this->_direction, input._direction);
    }

    //! Check if ray is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_degenerated(this->_direction);
    }

    //! Return origin
    const vector3 &origin() const
    {
      return this->_origin;
    }

    //! Return direction
    const vector3 &direction() const
    {
      return this->_direction;
    }

    //! Set origin
    void origin(
        const vector3 &input //!< input object
    )
    {
      this->_origin = input;
    }

    //! Set direction
    void direction(
        const vector3 &input //!< input object
    )
    {
      this->_direction = input;
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
/// eof: acme_ray3.hh
///