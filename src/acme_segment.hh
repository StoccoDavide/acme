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
    vector _point[2]; //!< Point

  public:
    //! Class destructor
    ~segment() {}

    //! Copy constructor
    segment(const segment &) = default;

    //! Class constructor
    segment() {}

    //! Class constructor
    segment(
        const real_type x0, //<! Input x value of first point
        const real_type y0, //<! Input y value of first point
        const real_type z0, //<! Input z value of first point
        const real_type x1, //<! Input x value of second point
        const real_type y1, //<! Input y value of second point
        const real_type z1  //<! Input z value of second point
    )
    {
      this->_point[0] = vector(x0, y0, z0);
      this->_point[1] = vector(x1, y1, z1);
    }

    //! Class constructor
    segment(
        const vector &point0, //!< Input object
        const vector &point1  //!< Input object
    )
    {
      this->_point[0] = point0;
      this->_point[1] = point1;
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
        this->_point[0] = input._point[0];
        this->_point[1] = input._point[1];
        return *this;
      }
    }

    //! Check if rays are (almost) equal
    bool is_equal(
        const segment &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_point[0], input._point[0]) &&
             acme::is_equal(this->_point[1], input._point[1]);
    }

    //! Check if segment is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_equal((this->_point[0] - this->_point[1]).norm(), real_type(0.0));
    }

    //! Get first vector
    const vector &point_0(void) const { return this->_point[0]; }

    //! Set first vector
    void point_0(
        const vector &input //!< Input object
    )
    {
      this->_point[0] = input;
    }

    //! Get second vector
    const vector &point_1(void) const { return this->_point[1]; }

    //! Set second vector
    void point_1(
        const vector &input //!< Input object
    )
    {
      this->_point[1] = input;
    }

    //! Get i-th point
    const vector &point(
        const int_type &i //!< Intput i-th vertex
    ) const
    {
      return this->_point[i];
    }

    //! Set i-th point
    void point(
        const int_type &i,  //!< Intput i-th vertex
        const vector &input //!< Input
    )
    {
      this->_point[i] = input;
    }

    //! Set points
    void points(
        const vector &input0, //!< Input object 0
        const vector &input1  //!< Input object 1
    )
    {
      this->_point[0] = input0;
      this->_point[1] = input1;
    }

    //! Convert to vector
    vector to_vector(void) const
    {
      return vector(this->_point[1] - this->_point[0]);
    }

    //! Translate by vector
    void translate(
        const vector &input //!< Input
    )
    {
      this->_point[0] = input + this->_point[0];
      this->_point[1] = input + this->_point[1];
    }

    //! Rotate by matrix
    void rotate(
        const matrix &input //!< Input
    )
    {
      this->_point[0] = input * this->_point[0];
      this->_point[1] = input * this->_point[1];
    }

    //! Swap segment points
    void swap(void)
    {
      vector tmp_point_0(this->_point[0]);
      vector tmp_point_1(this->_point[1]);
      this->_point[0] = tmp_point_1;
      this->_point[1] = tmp_point_0;
    }

    //! Calculate segment length
    real_type length(void) const
    {
      return (this->_point[0] - this->_point[1]).norm();
    }
  };

} // namespace acme

#endif

///
/// eof: acme_segment.hh
///