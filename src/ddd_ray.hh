///
/// file: ddd_ray.hh
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

#ifndef INCLUDE_DDD_RAY
#define INCLUDE_DDD_RAY

#include "ddd.hh"

namespace ddd
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
  template <typename T = Float>
  class ray final
  {
  private:
    point<T> _origin;     //!< Origin point
    vector<T> _direction; //!< Direction vector

  public:
    //! Class destructor
    ~ray() {}

    //! Class constructor
    ray() {}

    //! Copy constructor
    ray(const ray<T> &) = default;

    //! Class constructor for ray
    ray(
        const T &ox, //<! Input x origin value
        const T &oy, //<! Input y origin value
        const T &oz, //<! Input z origin value
        const T &dx, //<! Input x direction value
        const T &dy, //<! Input y direction value
        const T &dz  //<! Input z direction value
        ) : _origin(point<T>(ox, oy, oz)), _direction(vector<T>(dx, dy, dz))
    {
    }

    //! Class constructor
    ray(
        const point<T> &origin,    //!< Input origin point
        const vector<T> &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Class constructor
    ray(
        const Eigen::Matrix<T, 3, 1> &origin,   //!< Input origin point
        const Eigen::Matrix<T, 3, 1> &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Equality operator
    inline ray<T> &operator=(
        const ray<T> &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->origin(input.origin());
        this->direction(input.direction());
        return *this;
      }
    }

    //! Check if two rays are (exactly) equal
    inline bool operator==(
        const ray<T> &input //!< Input object
    )
    {
      return this->origin() == input.origin() && this->direction() == input.direction();
    }

    //! Check if two rays are (exactly) NOT equal
    inline bool operator!=(
        const ray<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two rays are (almost) equal
    inline bool is_equal(
        const ray<T> &input //!< Input object
    )
        const
    {
      return (this->origin().is_equal(input.origin()) && this->direction().is_equal(input.direction()));
    }

    //! Check if ray is degenerated
    inline bool is_degenerated(void)
        const
    {
      return this->direction().is_degenerated();
    }

    //! Return origin
    inline const point<T> &origin() const
    {
      return this->_origin;
    }

    //! Return direction
    inline const vector<T> &direction() const
    {
      return this->_direction;
    }

    //! Set origin
    inline void origin(
        const point<T> &input //!< input point object
    )
    {
      this->_origin = input;
    }

    //! Set direction
    inline void direction(
        const vector<T> &input //!< input vector object
    )
    {
      this->_direction = input;
    }

    //! Convert to line
    inline const line<T> &toLine(void) const
    {
      return line<T>(this);
    }

    //! Convert to plane
    inline const plane<T> &toPlane(void) const
    {
      return plane<T>(this);
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
      return this->_direction.is_parallel(input._direction);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const plane<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_orthognal(input.normal());
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const segment<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_parallel(input.toVector());
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
      return this->_direction.is_orthogonal(input._direction);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const plane<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_parallel(input.normal());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const segment<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_orthogonal(input.toVector());
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
      return this->_direction.angle(input._direction);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const plane<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.normal()) - PI / 2.0;
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const segment<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.toVector());
    }

    //! Reverse direction
    inline void reverse(void) { this->_direction = -this->_direction; }
  };

} // namespace ddd

#endif

///
/// eof: ddd_ray.hh
///