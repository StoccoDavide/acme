///
/// file: ddd_segment.hh
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

#ifndef INCLUDE_DDD_SEGMENT
#define INCLUDE_DDD_SEGMENT

#include "ddd_point.hh"

namespace ddd
{

  /*\
   |                                       _   
   |   ___  ___  __ _ _ __ ___   ___ _ __ | |_ 
   |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __|
   |  \__ \  __/ (_| | | | | | |  __/ | | | |_ 
   |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|
   |            |___/                          
  \*/

  //! Segment class container
  template <typename T = Float>
  class segment final
  {
  private:
    point<T> _point0; //!< Point 0
    point<T> _point1; //!< Point 1

  public:
    //! Class destructor
    ~segment() {}

    //! Copy constructor
    segment(const segment<T> &) = default;

    //! Class constructor
    segment() {}

    //! Class constructor
    segment(
        const T &x0, //<! Input x value of first point
        const T &y0, //<! Input y value of first point
        const T &z0, //<! Input z value of first point
        const T &x1, //<! Input x value of second point
        const T &y1, //<! Input y value of second point
        const T &z1  //<! Input z value of second point
        ) : _point0(point<T>(x0, y0, z0)), _point1(point<T>(x1, y1, z1))
    {
    }

    //! Class constructor
    segment(
        const point<T> &point0, //!< Input point object
        const point<T> &point1  //!< Input point object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Class constructor
    segment(
        const Eigen::Matrix<T, 3, 1> &point0, //!< Input point object
        const Eigen::Matrix<T, 3, 1> &point1  //!< Input point object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Equality operator
    inline segment<T> &operator=(
        const segment<T> &input //!< Input segment object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_point0(input._point0);
        this->_point1(input._point1);
        return *this;
      }
    }

    //! Check if two rays are (exactly) equal
    inline bool operator==(
        const segment<T> &input //!< Input object
    )
    {
      return this->_point0 == input._point0 && this->_point1 == input._point1;
    }

    //! Check if two rays are (exactly) NOT equal
    inline bool operator!=(
        const segment<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two rays are (almost) equal
    inline bool is_equal(
        const segment<T> &input //!< Input object
    )
        const
    {
      return this->_point0.is_equal(input._point0) && this->_point1.is_equal(input._point1);
    }

    //! Check if line is degenerated
    inline bool is_degenerated(void)
        const
    {
      return ddd::is_equal(_point0.distance(_point1), T(0.0));
    }

    //! Get first point
    inline point<T> &point_1(void) const { return this->_point1; }

    //! Set first point
    inline void point_1(
        const point<T> &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Get second point
    inline point<T> &point_2(void) const { return this->_point2; }

    //! Set second point
    inline void point_2(
        const point<T> &input //!< Input object
    )
    {
      this->_point2 = input;
    }

    //! Convert to vector
    inline const vector<T> &toVector(void) const
    {
      return vector<T>(this->_point0, this->_point1);
    }

    //! Convert to ray
    inline const ray<T> &toRay(void) const
    {
      return ray<T>(point<T>(this->_point0), vector<T>(this->_point0, this->_point1));
    }

    //! Convert to line
    inline const line<T> &toLine(void) const
    {
      return line<T>(point<T>(this->_point0), vector<T>(this->_point0, this->_point1));
    }

    //! Translate line by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_point0.translate(input);
      this->_point1.translate(input);
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
      return input.is_parallel(this);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const segment<T> &input //!< Input object
    )
        const
    {
      return (this->toVector()).is_parallel(input.toVector());
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
      return input.is_orthogonal(this);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const segment<T> &input //!< Input vector object
    )
        const
    {
      return (this->toVector()).is_orthogonal(input.toVector());
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
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const segment<T> &input //!< Input object
    )
        const
    {
      return (this->toVector()).angle(input.toVector());
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_segment.hh
///