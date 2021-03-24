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

///
/// file: acme_segment.hh
///

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
  /*!
  Segment in 3D space. It is defined by two arbitrary points.
  */
  class segment
  {
  private:
    vec3 _point[2]; //!< Point

  public:
    //! Class destructor
    ~segment() {}

    //! Copy constructor
    segment(segment const &) = default;

    //! Class constructor
    segment() {}

    //! Class constructor
    segment(
        real_type const x0, //<! Input x value of first point
        real_type const y0, //<! Input y value of first point
        real_type const z0, //<! Input z value of first point
        real_type const x1, //<! Input x value of second point
        real_type const y1, //<! Input y value of second point
        real_type const z1  //<! Input z value of second point
    )
    {
      this->_point[0] = vec3(x0, y0, z0);
      this->_point[1] = vec3(x1, y1, z1);
    }

    //! Class constructor
    segment(
        vec3 const &point0, //!< Input object
        vec3 const &point1  //!< Input object
    )
    {
      this->_point[0] = point0;
      this->_point[1] = point1;
    }

    //! Equality operator
    segment &operator=(
        segment const &input //!< Input object
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
        segment const &input //!< Input object
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
    vec3 const &point_0(void) const { return this->_point[0]; }

    //! Set first vector
    void point_0(
        vec3 const &input //!< Input object
    )
    {
      this->_point[0] = input;
    }

    //! Get second vector
    vec3 const &point_1(void) const { return this->_point[1]; }

    //! Set second vector
    void point_1(
        vec3 const &input //!< Input object
    )
    {
      this->_point[1] = input;
    }

    //! Get i-th point
    vec3 const &point(
        int_type const &i //!< Intput i-th vertex
    ) const
    {
      return this->_point[i];
    }

    //! Set i-th point
    void point(
        int_type const &i, //!< Intput i-th vertex
        vec3 const &input  //!< Input
    )
    {
      this->_point[i] = input;
    }

    //! Set points
    void points(
        vec3 const &input0, //!< Input object 0
        vec3 const &input1  //!< Input object 1
    )
    {
      this->_point[0] = input0;
      this->_point[1] = input1;
    }

    //! Convert to vector
    vec3 to_vector(void) const
    {
      return vec3(this->_point[1] - this->_point[0]);
    }

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    )
    {
      this->_point[0] = input + this->_point[0];
      this->_point[1] = input + this->_point[1];
    }

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    )
    {
      this->_point[0] = input * this->_point[0];
      this->_point[1] = input * this->_point[1];
    }

    //! Swap segment points
    void swap(void)
    {
      vec3 tmp_point_0(this->_point[0]);
      vec3 tmp_point_1(this->_point[1]);
      this->_point[0] = tmp_point_1;
      this->_point[1] = tmp_point_0;
    }

    //! Calculate segment length
    real_type length(void) const
    {
      return (this->_point[0] - this->_point[1]).norm();
    }

    // checks whether a point is within a segment
    bool is_inside(
        vec3 const &point //!< Input
    )
        const
    {
      real_type d0 = this->length();
      real_type d1 = (this->_point - this->_point[0]).norm();
      real_type d2 = (this->_point - this->_point[1]).norm();
      return acme::abs(d0 - d1 - d2) <= acme::Epsilon;
    };

  }; // class segment

} // namespace acme

#endif

///
/// eof: acme_segment.hh
///