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
  3D plane3 defined by arbitrary point3 on the plane3 and a normal vector3.
  */
  template <typename T = Float>
  class plane3 final
  {
  private:
    point3<T> _origin;  //!< Origin point3
    vector3<T> _normal; //!< Normal vector3

  public:
    //! Class destructor
    ~plane3() {}

    //! Class constructor
    plane3() {}

    //! Copy constructor
    plane3(const plane3<T> &) = default;

    //! Class constructor for plane3
    plane3(
        const T &ox, //<! Input x origin value
        const T &oy, //<! Input y origin value
        const T &oz, //<! Input z origin value
        const T &dx, //<! Input x normal value
        const T &dy, //<! Input y normal value
        const T &dz  //<! Input z normal value
        ) : _origin(point3<T>(ox, oy, oz)), _normal(vector3<T>(dx, dy, dz))
    {
    }

    //! Class constructor
    plane3(
        const point3<T> &origin, //!< Input origin
        const vector3<T> &normal //!< Input normal
        ) : _origin(origin), _normal(normal)
    {
    }

    //! Class constructor
    plane3(
        const Eigen::Matrix<T, 3, 1> &origin, //!< Input origin
        const Eigen::Matrix<T, 3, 1> &normal  //!< Input normal
        ) : _origin(origin), _normal(normal)
    {
    }

    //! Equality operator
    inline plane3<T> &operator=(
        const plane3<T> &input //!< Input object
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

    //! Check if two objects are (exactly) equal
    inline bool operator==(
        const plane3<T> &input //!< Input object
    )
    {
      return this->_origin == input._origin && this->_normal == input._normal;
    }

    //! Check if two objects are (exactly) NOT equal
    inline bool operator!=(
        const plane3<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two objects are (almost) equal
    inline bool is_equal(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return this->_origin.is_equal(input._origin) && this->_normal.is_equal(input._normal);
    }

    //! Check if plane3 is degenerated
    inline bool is_degenerated(void)
        const
    {
      return this->normal().is_degenerated();
    }

    //! Return origin
    inline const point3<T> &origin() const
    {
      return this->_origin;
    }

    //! Return normal
    inline const vector3<T> &normal() const
    {
      return this->_normal;
    }

    //! Set origin
    inline void origin(
        const point3<T> &input //!< input point3 object
    )
    {
      this->_origin = input;
    }

    //! Set normal
    inline void normal(
        const vector3<T> &input //!< input vector3 object
    )
    {
      this->_normal = input;
    }

    //! Translate line3 by vector3
    inline void translate(
        const vector3<T> &input //!< Input object
    )
    {
      this->_origin.translate(input);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const line3<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return this->_normal.is_parallel(input.normal());
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return this->_normal.is_orthogonal(input.toVector());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const line3<T> &input //!< Input object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return this->_normal.is_orthogonal(input.normal());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return this->_normal.is_parallel(input.toVector());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const line3<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return this->_normal.angle(input.normal());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.toVector()) - PI / 2.0;
    }

    //! Reverse normal
    inline void reverse(void) { this->_normal = -this->_normal; }
  };

} // namespace acme

#endif

///
/// eof: acme_plane3.hh
///