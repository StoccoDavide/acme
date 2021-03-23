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

#include "acme.hh"
#include "acme_math.hh"

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
  class segment3
  {
  private:
    vector3 _point0; //!< Point 0
    vector3 _point1; //!< Point 1

  public:
    //! Class destructor
    ~segment3() {}

    //! Copy constructor
    segment3(const segment3 &) = default;

    //! Class constructor
    segment3() {}

    //! Class constructor
    segment3(
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
    segment3(
        const vector3 &point0, //!< Input object
        const vector3 &point1  //!< Input object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Equality operator
    segment3 &operator=(
        const segment3 &input //!< Input object
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

    //! Check if rays are (almost) equal
    bool is_equal(
        const segment3 &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_point0, input._point0) &&
             acme::is_equal(this->_point1, input._point1);
    }

    //! Check if segment is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_equal((this->_point0 - this->_point1).norm(), real_type(0.0));
    }

    //! Get first vector3
    const vector3 &point_0(void) const { return this->_point0; }

    //! Set first vector3
    void point_0(
        const vector3 &input //!< Input object
    )
    {
      this->_point0 = input;
    }

    //! Get second vector3
    const vector3 &point_1(void) const { return this->_point1; }

    //! Set second vector3
    void point_1(
        const vector3 &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Set points
    void points(
        const vector3 &input0, //!< Input object 0
        const vector3 &input1  //!< Input object 1
    )
    {
      this->_point0 = input0;
      this->_point1 = input1;
    }

    //! Convert to vector3
    vector3 toVector(void) const
    {
      return vector3(this->_point1 - this->_point0);
    }

    //! Translate line3 by vector3
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
/// eof: acme_segment.hh
///