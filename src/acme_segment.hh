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

#ifndef INCLUDE_ACME_SEGMENT
#define INCLUDE_ACME_SEGMENT

#include "acme.hh"
#include "acme_math.hh"

namespace acme
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
  class segment
  {
  private:
    vector _point0; //!< Point 0
    vector _point1; //!< Point 1

  public:
    //! Class destructor
    ~segment() {}

    //! Copy constructor
    segment(const segment &) = default;

    //! Class constructor
    segment() {}

    //! Class constructor
    segment(
        const real_type &x0, //<! Input x value of first point
        const real_type &y0, //<! Input y value of first point
        const real_type &z0, //<! Input z value of first point
        const real_type &x1, //<! Input x value of second point
        const real_type &y1, //<! Input y value of second point
        const real_type &z1  //<! Input z value of second point
        ) : _point0(vector(x0, y0, z0)), _point1(vector(x1, y1, z1))
    {
    }

    //! Class constructor
    segment(
        const vector &point0, //!< Input object
        const vector &point1  //!< Input object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Equality operator
    segment &operator=(
        const segment &input //!< Input object
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
        const segment &input //!< Input object
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

    //! Get first vector
    const vector &point_0(void) const { return this->_point0; }

    //! Set first vector
    void point_0(
        const vector &input //!< Input object
    )
    {
      this->_point0 = input;
    }

    //! Get second vector
    const vector &point_1(void) const { return this->_point1; }

    //! Set second vector
    void point_1(
        const vector &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Set points
    void points(
        const vector &input0, //!< Input object 0
        const vector &input1  //!< Input object 1
    )
    {
      this->_point0 = input0;
      this->_point1 = input1;
    }

    //! Convert to vector
    vector toVector(void) const
    {
      return vector(this->_point1 - this->_point0);
    }

   //! Translate by vector
    void translate(
        const vector &input //!< Input
    )
    {
      this->_point0 = input + this->_point0;
      this->_point1 = input + this->_point1;
    }

    //! Rotate by matrix
    void rotate(
        const matrix &input //!< Input
    )
    {
      this->_point0 = input * this->_point0;
      this->_point1 = input * this->_point1;
    }

  };

} // namespace acme

#endif

///
/// eof: acme_segment.hh
///