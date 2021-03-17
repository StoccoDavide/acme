///
/// file: acme_box.hh
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

#ifndef INCLUDE_ACME_BOX3
#define INCLUDE_ACME_BOX3

#include "acme_point3.hh"

namespace acme
{

  /*\
   |   _               
   |  | |__   _____  __
   |  | '_ \ / _ \ \/ /
   |  | |_) | (_) >  < 
   |  |_.__/ \___/_/\_\
   |                   
  \*/

  //! Box class container
  template <typename T = Float>
  class box3
  {
  private:
    point3<T> _point0; //!< Point 0
    point3<T> _point1; //!< Point 1

  public:
    //! Class destructor
    ~box3() {}

    //! Copy constructor
    box3(const box3<T> &) = default;

    //! Class constructor
    box3() {}

    //! Class constructor
    box3(
        const T &x0, //<! Input x value of first point3
        const T &y0, //<! Input y value of first point3
        const T &z0, //<! Input z value of first point3
        const T &x1, //<! Input x value of second point3
        const T &y1, //<! Input y value of second point3
        const T &z1  //<! Input z value of second point3
        ) : _point0(point3<T>(x0, y0, z0)), _point1(point3<T>(x1, y1, z1))
    {
    }

    //! Class constructor
    box3(
        const point3<T> &point0, //!< Input point3 object
        const point3<T> &point1  //!< Input point3 object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Class constructor
    box3(
        const Eigen::Matrix<T, 3, 1> &point0, //!< Input point3 object
        const Eigen::Matrix<T, 3, 1> &point1  //!< Input point3 object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Equality operator
    inline box3<T> &operator=(
        const box3<T> &input //!< Input object
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

    //! Check if two objects are (exactly) equal
    inline bool operator==(
        const box3<T> &input //!< Input object
    )
    {
      return this->_point0 == input._point0 && this->_point1 == input._point1;
    }

    //! Check if two objects are (exactly) NOT equal
    inline bool operator!=(
        const box3<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two objects are (almost) equal
    inline bool is_equal(
        const box3<T> &input //!< Input object
    )
        const
    {
      return this->_point0.is_equal(input._point0) && this->_point1.is_equal(input._point1);
    }

    //! Check if box3 is degenerated
    inline bool is_degenerated(void)
        const
    {
      return acme::is_equal(_point0.distance(_point1), T(0.0));
    }

    //! Get first point3
    inline point3<T> &point_1(void) const { return this->_point1; }

    //! Set first point3
    inline void point_1(
        const point3<T> &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Get second point3
    inline point3<T> &point_2(void) const { return this->_point2; }

    //! Set second point3
    inline void point_2(
        const point3<T> &input //!< Input object
    )
    {
      this->_point2 = input;
    }

    //! Translate line by vector3
    inline void translate(
        const vector3<T> &input //!< Input vector3 object
    )
    {
      this->_point0.translate(input);
      this->_point1.translate(input);
    }

  };

} // namespace acme

#endif

///
/// eof: acme_box.hh
///