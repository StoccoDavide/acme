///
/// file: acme_segment.hh
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

#ifndef INCLUDE_ACME_SEGMENT3
#define INCLUDE_ACME_SEGMENT3

#include "acme_point3.hh"

namespace acme
{

  /*\
   |                                       _   _____ 
   |   ___  ___  __ _ _ __ ___   ___ _ __ | |_|___ / 
   |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __| |_ \ 
   |  \__ \  __/ (_| | | | | | |  __/ | | | |_ ___) |
   |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|____/ 
   |            |___/                                
  \*/

  //! Segment class container
  template <typename T = Float>
  class segment3 final
  {
  private:
    point3<T> _point0; //!< Point 0
    point3<T> _point1; //!< Point 1

  public:
    //! Class destructor
    ~segment3() {}

    //! Copy constructor
    segment3(const segment3<T> &) = default;

    //! Class constructor
    segment3() {}

    //! Class constructor
    segment3(
        const T &x0, //<! Input x value of first point
        const T &y0, //<! Input y value of first point
        const T &z0, //<! Input z value of first point
        const T &x1, //<! Input x value of second point
        const T &y1, //<! Input y value of second point
        const T &z1  //<! Input z value of second point
        ) : _point0(point3<T>(x0, y0, z0)), _point1(point3<T>(x1, y1, z1))
    {
    }

    //! Class constructor
    segment3(
        const point3<T> &point0, //!< Input object
        const point3<T> &point1  //!< Input object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Class constructor
    segment3(
        const Eigen::Matrix<T, 3, 1> &point0, //!< Input object
        const Eigen::Matrix<T, 3, 1> &point1  //!< Input object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Equality operator
    inline segment3<T> &operator=(
        const segment3<T> &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_point0 = input._point0;
        this->_point1 = input._point1;
        return *this;
      }
    }

    //! Check if rays are (exactly) equal
    inline bool operator==(
        const segment3<T> &input //!< Input object
    )
    {
      return this->_point0 == input._point0 && this->_point1 == input._point1;
    }

    //! Check if rays are (exactly) NOT equal
    inline bool operator!=(
        const segment3<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if rays are (almost) equal
    inline bool is_equal(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return this->_point0.is_equal(input._point0) && this->_point1.is_equal(input._point1);
    }

    //! Check if segment is degenerated
    inline bool is_degenerated(void)
        const
    {
      return acme::is_equal(_point0.distance(_point1), T(0.0));
    }

    //! Get first point3
    inline point3<T> &point_0(void) const { return this->_point0; }

    //! Set first point3
    inline void point_0(
        const point3<T> &input //!< Input object
    )
    {
      this->_point0 = input;
    }

    //! Get second point3
    inline point3<T> &point_1(void) const { return this->_point1; }

    //! Set second point3
    inline void point_1(
        const point3<T> &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Set points
    inline void points(
        const point3<T> &input0, //!< Input object 0
        const point3<T> &input1  //!< Input object 1
    )
    {
      this->_point0 = input0;
      this->_point1 = input1;
    }

    //! Convert to vector3
    inline const vector3<T> &toVector(void) const
    {
      return vector3<T>(this->_point0, this->_point1);
    }

    //! Convert to ray3
    inline const ray3<T> &toRay(void) const
    {
      return ray3<T>(point3<T>(this->_point0), vector3<T>(this->_point0, this->_point1));
    }

    //! Convert to line3
    inline const line3<T> &toLine(void) const
    {
      return line3<T>(point3<T>(this->_point0), vector3<T>(this->_point0, this->_point1));
    }

    //! Translate line3 by vector3
    inline void translate(
        const vector3<T> &input //!< Input object
    )
    {
      this->_point0.translate(input);
      this->_point1.translate(input);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const line3<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return (this->toVector()).is_parallel(input.toVector());
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const line3<T> &input //!< Input object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return (this->toVector()).is_orthogonal(input.toVector());
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
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return (this->toVector()).angle(input.toVector());
    }

    //! Tranform segment from frameA to frameB
    inline const segment3<T> transform(
        const frame3<T> &frameA, //!< Actual reference coordinate system
        const frame3<T> &frameB  //!< Future reference coordinate system
    )
        const
    {
      return segment3<T>(this->_point0.transform(frameA, frameB),
                         this->_point1.transform(frameA, frameB));
    }
  };

} // namespace acme

#endif

///
/// eof: acme_segment.hh
///