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

#include "acme.hh"
#include "acme_math.hh"

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
  class triangle3
  {
  private:
  private:
    vector3 _point0; //!< Point 0
    vector3 _point1; //!< Point 1
    vector3 _point2; //!< Point 2

  public:
    //! Class destructor
    ~triangle3() {}

    //! Copy constructor
    triangle3(const triangle3 &) = default;

    //! Class constructor
    triangle3() {}

    //! Class constructor
    triangle3(
        const real_type &x0, //<! Input x value of first point
        const real_type &y0, //<! Input y value of first point
        const real_type &z0, //<! Input z value of first point
        const real_type &x1, //<! Input x value of second point
        const real_type &y1, //<! Input y value of second point
        const real_type &z1, //<! Input z value of second point
        const real_type &x2, //<! Input x value of third point
        const real_type &y2, //<! Input y value of third point
        const real_type &z2  //<! Input z value of third point
        ) : _point0(vector3(x0, y0, z0)), _point1(vector3(x1, y1, z1)), _point2(vector3(x2, y2, z2))
    {
    }

    //! Class constructor
    triangle3(
        const vector3 &point0, //!< Input object
        const vector3 &point1, //!< Input object
        const vector3 &point2  //!< Input object
        ) : _point0(point0), _point1(point1), _point2(point2)
    {
    }

    //! Equality operator
    triangle3 &operator=(
        const triangle3 &input //!< Input object
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

    //! Check if objects are (almost) equal
    bool is_equal(
        const triangle3 &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_point0, input._point0) &&
             acme::is_equal(this->_point1, input._point1) &&
             acme::is_equal(this->_point2, input._point2);
    }

    //! Check if triangle is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_equal((this->_point0 - this->_point1).norm(), 0.0) ||
             acme::is_equal((this->_point1 - this->_point2).norm(), 0.0) ||
             acme::is_equal((this->_point2 - this->_point0).norm(), 0.0);
    }

    //! Get first point
    const vector3 &point_0(void) const { return this->_point0; }

    //! Set first point
    void point_0(
        const vector3 &input //!< Input object
    )
    {
      this->_point0 = input;
    }

    //! Get second point
    const vector3 &point_1(void) const { return this->_point1; }

    //! Set second point
    void point_1(
        const vector3 &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Get third point
    const vector3 &point_2(void) const { return this->_point2; }

    //! Set third point
    void point_2(
        const vector3 &input //!< Input object
    )
    {
      this->_point2 = input;
    }

    //! Get first edge
    const segment3 edge_0(void) const { return segment3(this->_point0, this->_point1); }

    //! Get second edge
    const segment3 edge_1(void) const { return segment3(this->_point1, this->_point2); }

    //! Get third edge
    const segment3 edge_2(void) const { return segment3(this->_point2, this->_point0); }

    //! Get face normal
    const vector3 normal(void)
        const
    {
      return (this->_point1 - this->_point0).cross(this->_point2 - this->_point0);
    }

    //! Translate by vector
    void translate(
        const vector3 &input //!< Input object
    )
    {
      this->_point0 + input;
      this->_point1 + input;
      this->_point2 + input;
    }

  };

} // namespace acme

#endif

///
/// eof: acme_triangle3.hh
///
