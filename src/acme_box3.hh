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

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |   _               _____ 
   |  | |__   _____  _|___ / 
   |  | '_ \ / _ \ \/ / |_ \ 
   |  | |_) | (_) >  < ___) |
   |  |_.__/ \___/_/\_\____/ 
   |                         
  \*/

  //! Box class container
  class box3
  {
  private:
    vector3 _point0; //!< Point 0
    vector3 _point1; //!< Point 1

  public:
    //! Class destructor
    ~box3() {}

    //! Copy constructor
    box3(const box3 &) = default;

    //! Class constructor
    box3() {}

    //! Class constructor
    box3(
        const real_type &x0, //<! Input x value of first point
        const real_type &y0, //<! Input y value of first point
        const real_type &z0, //<! Input z value of first point
        const real_type &x1, //<! Input x value of second point
        const real_type &y1, //<! Input y value of second point
        const real_type &z1  //<! Input z value of second point
        ) : _point0(vector3(x0, y0, z0)), _point1(vector3(x1, y1, z1))
    {
    }

    //! Class constructor
    box3(
        const vector3 &point0, //!< Input object
        const vector3 &point1  //!< Input object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Equality operator
    box3 &operator=(
        const box3 &input //!< Input object
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

    //! Check if objects are (almost) equal
    bool is_equal(
        const box3 &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_point0, input._point0) &&
             acme::is_equal(this->_point1, input._point1);
    }

    //! Check if box is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_equal((this->_point0 - this->_point1).norm(), real_type(0.0));
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

    //! Translate by vector
    void translate(
        const vector3 &input //!< Input object
    )
    {
      this->_point0 + input;
      this->_point1 + input;
    }

  };

} // namespace acme

#endif

///
/// eof: acme_box.hh
///