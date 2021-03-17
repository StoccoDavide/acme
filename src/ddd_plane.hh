///
/// file: ddd_plane.hh
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

#ifndef INCLUDE_DDD_PLANE
#define INCLUDE_DDD_PLANE

#include "ddd.hh"

namespace ddd
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
  3D plane defined by arbitrary point on the plane and a normal vector.
  */
  template <typename T = Float>
  class plane final
  {
  private:
    point<T> _origin;  //!< Origin point
    vector<T> _normal; //!< Normal vector

  public:
    //! Class destructor
    ~plane() {}

    //! Class constructor
    plane() {}

    //! Copy constructor
    plane(const plane<T> &) = default;

    //! Class constructor for plane
    plane(
        const T &ox, //<! Input x origin value
        const T &oy, //<! Input y origin value
        const T &oz, //<! Input z origin value
        const T &dx, //<! Input x normal value
        const T &dy, //<! Input y normal value
        const T &dz  //<! Input z normal value
        ) : _origin(point<T>(ox, oy, oz)), _normal(vector<T>(dx, dy, dz))
    {
    }

    //! Class constructor
    plane(
        const point<T> &origin, //!< Input origin point
        const vector<T> &normal //!< Input normal
        ) : _origin(origin), _normal(normal)
    {
    }

    //! Class constructor
    plane(
        const Eigen::Matrix<T, 3, 1> &origin, //!< Input origin point
        const Eigen::Matrix<T, 3, 1> &normal  //!< Input direction
        ) : _origin(origin), _normal(normal)
    {
    }

    //! Equality operator
    inline plane<T> &operator=(
        const plane<T> &input //!< Input object
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

    //! Check if two planes are (exactly) equal
    inline bool operator==(
        const plane<T> &input //!< Input object
    )
    {
      return this->_origin == input._origin && this->_normal == input._normal;
    }

    //! Check if two planes are (exactly) NOT equal
    inline bool operator!=(
        const plane<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two planes are (almost) equal
    inline bool is_equal(
        const plane<T> &input //!< Input object
    )
        const
    {
      return this->_origin.is_equal(input._origin) && this->_normal.is_equal(input._normal);
    }

    //! Check if plane is degenerated
    inline bool is_degenerated(void)
        const
    {
      return this->normal().is_degenerated();
    }

    //! Return origin
    inline const point<T> &origin() const
    {
      return this->_origin;
    }

    //! Return normal
    inline const vector<T> &normal() const
    {
      return this->_normal;
    }

    //! Set origin
    inline void origin(
        const point<T> &input //!< input point object
    )
    {
      this->_origin = input;
    }

    //! Set normal
    inline void normal(
        const vector<T> &input //!< input vector object
    )
    {
      this->_normal = input;
    }

    //! Translate line by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_origin.translate(input);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const vector<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const line<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const ray<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const plane<T> &input //!< Input object
    )
        const
    {
      return this->_normal.is_parallel(input.normal());
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const segment<T> &input //!< Input object
    )
        const
    {
      return this->_normal.is_orthogonal(input.toVector());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const line<T> &input //!< Input vector object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const ray<T> &input //!< Input vector object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const plane<T> &input //!< Input vector object
    )
        const
    {
      return this->_normal.is_orthogonal(input.normal());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const segment<T> &input //!< Input vector object
    )
        const
    {
      return this->_normal.is_parallel(input.toVector());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const vector<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const line<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const ray<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const plane<T> &input //!< Input object
    )
        const
    {
      return this->_normal.angle(input.normal());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const segment<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.toVector()) - PI / 2.0;
    }

    //! Reverse normal
    inline void reverse(void) { this->_normal = -this->_normal; }
  };

} // namespace ddd

#endif

///
/// eof: ddd_plane.hh
///