///
/// file: acme_plane.hh
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
  3D plane defined by arbitrary vector on the plane and a normal vector.
  */
  class plane
  {
  private:
    vector _origin; //!< Origin vector
    vector _normal; //!< Normal vector

  public:
    //! Class destructor
    ~plane() {}

    //! Class constructor
    plane() {}

    //! Copy constructor
    plane(const plane &) = default;

    //! Class constructor for plane
    plane(
        const real_type &ox, //<! Input x origin value
        const real_type &oy, //<! Input y origin value
        const real_type &oz, //<! Input z origin value
        const real_type &dx, //<! Input x normal value
        const real_type &dy, //<! Input y normal value
        const real_type &dz  //<! Input z normal value
        ) : _origin(vector(ox, oy, oz)), _normal(vector(dx, dy, dz))
    {
    }

    //! Class constructor
    plane(
        const vector &origin, //!< Input origin
        const vector &normal  //!< Input normal
        ) : _origin(origin), _normal(normal)
    {
    }

    //! Equality operator
    plane &operator=(
        const plane &input //!< Input object
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
        const plane &input //!< Input object
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
    const vector &origin() const
    {
      return this->_origin;
    }

    //! Return normal
    const vector &normal() const
    {
      return this->_normal;
    }

    //! Set origin
    void origin(
        const vector &input //!< input vector object
    )
    {
      this->_origin = input;
    }

    //! Set normal
    void normal(
        const vector &input //!< input vector object
    )
    {
      this->_normal = input;
    }

    //! Translate by vector
    void translate(
        const vector &input //!< Input
    )
    {
      this->_origin = input + this->_origin;
    }

    //! Rotate by matrix
    void rotate(
        const matrix &input //!< Input
    )
    {
      this->_origin = input * this->_origin;
      this->_normal = input * this->_normal;
    }

    //! Reverse normal
    void reverse(void) { this->_normal = -this->_normal; }

    //! Return d value
    real_type d(void) const { return -this->_origin.dot(this->_normal); }

    //! Distance between point and plane
    real_type distance(
        const vector &input //!< Input
    )
        const
    {
      return (input - this->_origin).dot(this->_normal);
    }
  };

} // namespace acme

#endif

///
/// eof: acme_plane.hh
///