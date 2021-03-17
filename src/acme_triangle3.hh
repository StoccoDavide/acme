///
/// file: acme_triangle3.hh
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

#ifndef INCLUDE_ACME_TRIANGLE3
#define INCLUDE_ACME_TRIANGLE3

#include "acme_point3.hh"

namespace acme
{

  /*\
   |   _        _                   _      _____ 
   |  | |_ _ __(_) __ _ _ __   __ _| | ___|___ / 
   |  | __| '__| |/ _` | '_ \ / _` | |/ _ \ |_ \ 
   |  | |_| |  | | (_| | | | | (_| | |  __/___) |
   |   \__|_|  |_|\__,_|_| |_|\__, |_|\___|____/ 
   |                          |___/              
  \*/

  //! triangle3 class container
  template <typename T = Float>
  class triangle3
  {
  private:
  private:
    point3<T> _point0; //!< Point 0
    point3<T> _point1; //!< Point 1
    point3<T> _point2; //!< Point 2

  public:
    //! Class destructor
    ~triangle3() {}

    //! Copy constructor
    triangle3(const triangle3<T> &) = default;

    //! Class constructor
    triangle3() {}

    //! Class constructor
    triangle3(
        const T &x0, //<! Input x value of first point
        const T &y0, //<! Input y value of first point
        const T &z0, //<! Input z value of first point
        const T &x1, //<! Input x value of second point
        const T &y1, //<! Input y value of second point
        const T &z1, //<! Input z value of second point
        const T &x2, //<! Input x value of third point
        const T &y2, //<! Input y value of third point
        const T &z2  //<! Input z value of third point
        ) : _point0(point3<T>(x0, y0, z0)), _point1(point3<T>(x1, y1, z1)), _point2(point3<T>(x2, y2, z2))
    {
    }

    //! Class constructor
    triangle3(
        const point3<T> &point0, //!< Input object
        const point3<T> &point1, //!< Input object
        const point3<T> &point2  //!< Input object
        ) : _point0(point0), _point1(point1), _point2(point2)
    {
    }

    //! Class constructor
    triangle3(
        const Eigen::Matrix<T, 3, 1> &point0, //!< Input object
        const Eigen::Matrix<T, 3, 1> &point1, //!< Input object
        const Eigen::Matrix<T, 3, 1> &point2  //!< Input object
        ) : _point0(point0), _point1(point1), _point2(point2)
    {
    }

    //! Equality operator
    inline triangle3<T> &operator=(
        const triangle3<T> &input //!< Input object
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
        this->_point2 = input._point2;
        return *this;
      }
    }

    //! Check if objects are (exactly) equal
    inline bool operator==(
        const segment3<T> &input //!< Input object
    )
    {
      return this->_point0 == input._point0 && this->_point1 == input._point1 && this->_point2 == input._point2;
    }

    //! Check if objects are (exactly) NOT equal
    inline bool operator!=(
        const segment3<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if objects are (almost) equal
    inline bool is_equal(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return this->_point0.is_equal(input._point0) && this->_point1.is_equal(input._point1) && this->_point2.is_equal(input._point2);
    }

    //! Check if triangle is degenerated
    inline bool is_degenerated(void)
        const
    {
      return this->direction().is_degenerated();
    }

    //! Get first point
    inline point3<T> &point_1(void) const { return this->_point1; }

    //! Set first point
    inline void point_1(
        const point3<T> &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Get second point
    inline point3<T> &point_2(void) const { return this->_point2; }

    //! Set second point
    inline void point_2(
        const point3<T> &input //!< Input object
    )
    {
      this->_point2 = input;
    }

    //! Get third point
    inline point3<T> &point_3(void) const { return this->_point3; }

    //! Set third point
    inline void point_3(
        const point3<T> &input //!< Input object
    )
    {
      this->_point3 = input;
    }

    //! Get first edge
    inline segment3<T> &edge_1(void) const { return segment3<T>(this->_point0, this->_point1); }

    //! Get second edge
    inline segment3<T> &edge_2(void) const { return segment3<T>(this->_point1, this->_point2); }

    //! Get third edge
    inline segment3<T> &edge_3(void) const { return segment3<T>(this->_point2, this->_point0); }

    //! Get face normal
    inline vector3<T> &normal(void)
        const
    {
      return vector3<T>((this->_point1.data() - this->_point0.data()).cross(this->_point2.data() - this->_point0.data()));
    }

    //! Get face normal
    inline Eigen::Matrix<T, 3, 1> &normalEigen(void)
        const
    {
      return (this->_point1.data() - this->_point0.data()).cross(this->_point2.data() - this->_point0.data());
    }

    //! Translate by vector
    inline void translate(
        const vector3<T> &input //!< Input object
    )
    {
      this->_point0.translate(input);
      this->_point1.translate(input);
      this->_point2.translate(input);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const line3<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input.toVector());
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_parallel(input);
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const line3<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_parallel(input);
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_parallel(input);
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return(this->normal()).is_parallel(input);
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_parallel(input.toVector());
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
  };

} // namespace acme

#endif

///
/// eof: acme_triangle3.hh
///
