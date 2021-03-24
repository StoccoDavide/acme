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

///
/// file: acme_ray.hh
///


#ifndef INCLUDE_ACME_RAY
#define INCLUDE_ACME_RAY

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |                   
   |   _ __ __ _ _   _ 
   |  | '__/ _` | | | |
   |  | | | (_| | |_| |
   |  |_|  \__,_|\__, |
   |             |___/ 
  \*/

  //! Ray class container
  /*!
  Infinite ray in 3D space and defined by any point lying on the line and a direction
  vector.
  */
  class ray
  {
  private:
    vec3 _origin;    //!< Origin
    vec3 _direction; //!< Direction

  public:
    //! Class destructor
    ~ray() {}

    //! Class constructor
    ray() {}

    //! Copy constructor
    ray(ray const &) = default;

    //! Class constructor
    ray(
        real_type const ox, //<! Input x origin value
        real_type const oy, //<! Input y origin value
        real_type const oz, //<! Input z origin value
        real_type const dx, //<! Input x direction value
        real_type const dy, //<! Input y direction value
        real_type const dz  //<! Input z direction value
        ) : _origin(vec3(ox, oy, oz)), _direction(vec3(dx, dy, dz))
    {
    }

    //! Class constructor
    ray(
        vec3 const &origin,   //!< Input origin
        vec3 const &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Equality operator
    ray &operator=(
        ray const &input //!< Input object
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
        ray const &input //!< Input object
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
    vec3 const &origin() const
    {
      return this->_origin;
    }

    //! Return direction
    vec3 const &direction() const
    {
      return this->_direction;
    }

    //! Set origin
    void origin(
        vec3 const &input //!< input object
    )
    {
      this->_origin = input;
    }

    //! Set direction
    void direction(
        vec3 const &input //!< input object
    )
    {
      this->_direction = input;
    }

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    )
    {
      this->_origin = input + this->_origin;
    }

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    )
    {
      this->_origin = input * this->_origin;
      this->_direction = input * this->_direction;
    }

    //! Reverse direction
    void reverse(void) { this->_direction = -this->_direction; }

    //! Get reversed ray
    ray reversed(void) const
    {
      return ray(this->_origin, -this->_direction);
    }

  }; // class ray

} // namespace acme

#endif

///
/// eof: acme_ray.hh
///