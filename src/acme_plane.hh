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
/// file: acme_plane.hh
///

#ifndef INCLUDE_ACME_PLANE
#define INCLUDE_ACME_PLANE

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |         _                  
   |   _ __ | | __ _ _ __   ___ 
   |  | '_ \| |/ _` | '_ \ / _ \
   |  | |_) | | (_| | | | |  __/
   |  | .__/|_|\__,_|_| |_|\___|
   |  |_|                       
  \*/

  //! Plane class container
  /*!
  3D plane defined by the normal vector to plane and an arbitraty point laying on the plane.
  */
  class plane
  {
  private:
    vec3 _origin; //!< Origin vector
    vec3 _normal; //!< Normal vector

  public:
    //! Class destructor
    ~plane() {}

    //! Class constructor
    plane() {}

    //! Copy constructor
    plane(plane const &) = default;

    //! Class constructor for plane
    plane(
        real_type const ox, //<! Input x origin value
        real_type const oy, //<! Input y origin value
        real_type const oz, //<! Input z origin value
        real_type const dx, //<! Input x normal value
        real_type const dy, //<! Input y normal value
        real_type const dz  //<! Input z normal value
        ) : _origin(vec3(ox, oy, oz)), _normal(vec3(dx, dy, dz))
    {
    }

    //! Class constructor
    plane(
        vec3 const &origin, //!< Input origin
        vec3 const &normal  //!< Input normal
        ) : _origin(origin), _normal(normal)
    {
    }

    //! Equality operator
    plane &operator=(
        plane const &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_origin = input._origin;
        this->_normal = input._normal;
        return *this;
      }
    }

    //! Check if objects are (almost) equal
    bool is_equal(
        plane const &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_origin, input._origin) &&
             acme::is_equal(this->_normal, input._normal);
    }

    //! Check if plane is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_degenerated(this->_normal);
    }

    //! Return origin
    vec3 const &origin() const
    {
      return this->_origin;
    }

    //! Return normal
    vec3 const &normal() const
    {
      return this->_normal;
    }

    //! Set origin
    void origin(
        vec3 const &input //!< input vec3 object
    )
    {
      this->_origin = input;
    }

    //! Set normal
    void normal(
        vec3 const &input //!< input vec3 object
    )
    {
      this->_normal = input;
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
      this->_normal = input * this->_normal;
    }

    //! Reverse normal
    void reverse(void) { this->_normal = -this->_normal; }

    //! Get reversed ray
    plane reversed(void) const
    {
      return plane(this->_origin, -this->_normal);
    }

    //! Return d value
    real_type d(void) const { return -this->_origin.dot(this->_normal); }

    //! Distance between point and plane
    real_type distance(
        vec3 const &input //!< Input
    )
        const
    {
      return (input - this->_origin).dot(this->_normal);
    }

  }; // class plane

} // namespace acme

#endif

///
/// eof: acme_plane.hh
///