///
/// file: acme_triangle.hh
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

#ifndef INCLUDE_ACME_TRIANGLE
#define INCLUDE_ACME_TRIANGLE

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |   _        _                   _      
   |  | |_ _ __(_) __ _ _ __   __ _| | ___ 
   |  | __| '__| |/ _` | '_ \ / _` | |/ _ \
   |  | |_| |  | | (_| | | | | (_| | |  __/
   |   \__|_|  |_|\__,_|_| |_|\__, |_|\___|
   |                          |___/        
  \*/

  //! triangle class container
  class triangle
  {
  private:
  private:
    vector _point0; //!< Point 0
    vector _point1; //!< Point 1
    vector _point2; //!< Point 2

  public:
    //! Class destructor
    ~triangle() {}

    //! Copy constructor
    triangle(const triangle &) = default;

    //! Class constructor
    triangle() {}

    //! Class constructor
    triangle(
        const real_type &x0, //<! Input x value of first point
        const real_type &y0, //<! Input y value of first point
        const real_type &z0, //<! Input z value of first point
        const real_type &x1, //<! Input x value of second point
        const real_type &y1, //<! Input y value of second point
        const real_type &z1, //<! Input z value of second point
        const real_type &x2, //<! Input x value of third point
        const real_type &y2, //<! Input y value of third point
        const real_type &z2  //<! Input z value of third point
        ) : _point0(vector(x0, y0, z0)), _point1(vector(x1, y1, z1)), _point2(vector(x2, y2, z2))
    {
    }

    //! Class constructor
    triangle(
        const vector &point0, //!< Input object
        const vector &point1, //!< Input object
        const vector &point2  //!< Input object
        ) : _point0(point0), _point1(point1), _point2(point2)
    {
    }

    //! Equality operator
    triangle &operator=(
        const triangle &input //!< Input object
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
        const triangle &input //!< Input object
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
    const vector &point_0(void) const { return this->_point0; }

    //! Set first point
    void point_0(
        const vector &input //!< Input object
    )
    {
      this->_point0 = input;
    }

    //! Get second point
    const vector &point_1(void) const { return this->_point1; }

    //! Set second point
    void point_1(
        const vector &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Get third point
    const vector &point_2(void) const { return this->_point2; }

    //! Set third point
    void point_2(
        const vector &input //!< Input object
    )
    {
      this->_point2 = input;
    }

    //! Get first edge
    const segment edge_0(void) const { return segment(this->_point0, this->_point1); }

    //! Get second edge
    const segment edge_1(void) const { return segment(this->_point1, this->_point2); }

    //! Get third edge
    const segment edge_2(void) const { return segment(this->_point2, this->_point0); }

    //! Get face normal
    const vector normal(void)
        const
    {
      return (this->_point1 - this->_point0).cross(this->_point2 - this->_point0);
    }

    //! Translate by vector
    void translate(
        const vector &input //!< Input
    )
    {
      this->_point0 = input + this->_point0;
      this->_point1 = input + this->_point1;
      this->_point2 = input + this->_point2;
    }

    //! Rotate by matrix
    void rotate(
        const matrix &input //!< Input
    )
    {
      this->_point0 = input * this->_point0;
      this->_point1 = input * this->_point1;
      this->_point2 = input * this->_point2;
    }
  };

} // namespace acme

#endif

///
/// eof: acme_triangle.hh
///
