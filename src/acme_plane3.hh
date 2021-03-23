///
/// file: acme_plane3.hh
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

#ifndef INCLUDE_ACME_PLANE3
#define INCLUDE_ACME_PLANE3

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |         _                  _____ 
   |   _ __ | | __ _ _ __   ___|___ / 
   |  | '_ \| |/ _` | '_ \ / _ \ |_ \ 
   |  | |_) | | (_| | | | |  __/___) |
   |  | .__/|_|\__,_|_| |_|\___|____/ 
   |  |_|                             
  \*/

  //! Plane class container
  /*!
  3D plane3 defined by arbitrary vector3 on the plane3 and a normal vector3.
  */
  class plane3
  {
  private:
    vector3 _origin; //!< Origin vector3
    vector3 _normal; //!< Normal vector3

  public:
    //! Class destructor
    ~plane3() {}

    //! Class constructor
    plane3() {}

    //! Copy constructor
    plane3(const plane3 &) = default;

    //! Class constructor for plane3
    plane3(
        const real_type &ox, //<! Input x origin value
        const real_type &oy, //<! Input y origin value
        const real_type &oz, //<! Input z origin value
        const real_type &dx, //<! Input x normal value
        const real_type &dy, //<! Input y normal value
        const real_type &dz  //<! Input z normal value
        ) : _origin(vector3(ox, oy, oz)), _normal(vector3(dx, dy, dz))
    {
    }

    //! Class constructor
    plane3(
        const vector3 &origin, //!< Input origin
        const vector3 &normal  //!< Input normal
        ) : _origin(origin), _normal(normal)
    {
    }

    //! Equality operator
    plane3 &operator=(
        const plane3 &input //!< Input object
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
        const plane3 &input //!< Input object
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
    const vector3 &origin() const
    {
      return this->_origin;
    }

    //! Return normal
    const vector3 &normal() const
    {
      return this->_normal;
    }

    //! Set origin
    void origin(
        const vector3 &input //!< input vector3 object
    )
    {
      this->_origin = input;
    }

    //! Set normal
    void normal(
        const vector3 &input //!< input vector3 object
    )
    {
      this->_normal = input;
    }

    //! Translate line3 by vector3
    void translate(
        const vector3 &input //!< Input object
    )
    {
      this->_origin + input;
    }

    //! Reverse normal
    void reverse(void) { this->_normal = -this->_normal; }

    //! Return d value
    real_type d(void) const { return -this->_origin.dot(this->_normal); }

    //! Distance between point and plane
    real_type distance(
        const vector3 &input //!< Input
    )
        const
    {
      return (input - this->_origin).dot(this->_normal);
    }
  };

} // namespace acme

#endif

///
/// eof: acme_plane3.hh
///