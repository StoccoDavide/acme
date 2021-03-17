///
/// file: acme_line3.hh
///

/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                              *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The acme computational geometry library and its components are       *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the acme computational geometry library and its      *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

#ifndef INCLUDE_ACME_LINE3
#define INCLUDE_ACME_LINE3

#include "acme.hh"

namespace acme
{

  /*\
   |   _ _            
   |  | (_)_ __   ___ 
   |  | | | '_ \ / _ \
   |  | | | | | |  __/
   |  |_|_|_| |_|\___|
   |                  
  \*/

  //! Line class container
  /*!
  Infinite line in 3D space and defined by any point3 lying on the line and a direction
  vector3.
  */
  template <typename T = Float>
  class line3 final
  {
  private:
    point3<T> _origin;     //!< Origin point3
    vector3<T> _direction; //!< Direction vector3

  public:
    //! Class destructor
    ~line3() {}

    //! Class constructor
    line3() {}

    //! Copy constructor
    line3(const line3<T> &) = default;

    //! Class constructor for line3
    line3(
        const T &ox, //<! Input x origin value
        const T &oy, //<! Input y origin value
        const T &oz, //<! Input z origin value
        const T &dx, //<! Input x direction value
        const T &dy, //<! Input y direction value
        const T &dz  //<! Input z direction value
        ) : _origin(point3<T>(ox, oy, oz)), _direction(vector3<T>(dx, dy, dz))
    {
    }

    //! Class constructor
    line3(
        const point3<T> &origin,    //!< Input origin point3
        const vector3<T> &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Class constructor
    line3(
        const Eigen::Matrix<T, 3, 1> &origin,   //!< Input origin point3
        const Eigen::Matrix<T, 3, 1> &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Equality operator
    inline line3<T> &operator=(
        const line3<T> &input //!< Input object
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

    //! Check if two line3s are (exactly) equal
    inline bool operator==(
        const line3<T> &input //!< Input object
    )
    {
      return this->_origin == input._origin && this->_direction == input._direction;
    }

    //! Check if two line3s are (exactly) NOT equal
    inline bool operator!=(
        const line3<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two line3s are (almost) equal
    inline bool is_equal(
        const line3<T> &input //!< Input object
    )
        const
    {
      return this->_origin.is_equal(input._origin) && this->_direction.is_equal(input._direction);
    }

    //! Check if line3 is degenerated
    inline bool is_degenerated(void)
        const
    {
      return this->direction().is_degenerated();
    }

    //! Return origin
    inline const point3<T> &origin() const
    {
      return this->_origin;
    }

    //! Return direction
    inline const vector3<T> &direction() const
    {
      return this->_direction;
    }

    //! Set origin
    inline void origin(
        const point3<T> &input //!< input point3 object
    )
    {
      this->_origin = input;
    }

    //! Set direction
    inline void direction(
        const vector3<T> &input //!< input vector3 object
    )
    {
      this->_direction = input;
    }

    //! Convert to ray3
    inline const ray3<T> &toRay(void) const
    {
      return ray3<T>(this);
    }

    //! Convert to plane3
    inline const plane3<T> &toPlane(void) const
    {
      return plane3<T>(this);
    }

    //! Translate line3 by vector3
    inline void translate(
        const vector3<T> &input //!< Input vector3 object
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
      return this->_direction.is_equal(input._direction);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_parallel(input.direction());
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_orthogonal(input.normal());
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_parallel(input.toVector());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const vector3<T> &input //!< Input vector3 object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const line3<T> &input //!< Input vector3 object
    )
        const
    {
      return this->_direction.is_orthogonal(input._direction);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const ray3<T> &input //!< Input vector3 object
    )
        const
    {
      return this->_direction.is_orthogonal(input.direction());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const plane3<T> &input //!< Input vector3 object
    )
        const
    {
      return this->_direction.is_parallel(input.normal());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const segment3<T> &input //!< Input vector3 object
    )
        const
    {
      return this->_direction.is_orthogonal(input.toVector());
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
      return (this->_direction).angle(input._direction);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.direction());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.normal()) - PI / 2.0;
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.toVector());
    }

    //! Reverse direction
    inline void reverse(void) { this->_direction = -this->_direction; }
  };

} // namespace acme

#endif

///
/// eof: acme_line3.hh
///