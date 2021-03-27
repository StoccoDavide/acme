/*
(***********************************************************************)
(*                                                                     *)
(* The ACME computational geometry library                             *)
(* Release Version 0.0.0                                               *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The ACME computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the ACME computational geometry library and its     *)
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
#include "acme_frame.hh"

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
        real_type x0, //<! Input x value of first point
        real_type y0, //<! Input y value of first point
        real_type z0, //<! Input z value of first point
        real_type x1, //<! Input x value of second point
        real_type y1, //<! Input y value of second point
        real_type z1  //<! Input z value of second point
    );

    //! Class constructor
    segment(
        vec3 const &point0, //!< Input object
        vec3 const &point1  //!< Input object
    );

    //! Class constructor
    segment(
        vec3 const point[2] //!< Input points
    );

    //! Equality operator
    segment &operator=(
        segment const &input //!< Input object
    );

    //! Check if rays are (almost) equal
    bool is_equal(
        segment const &input //!< Input object
    ) const;

    //! Check if segment is degenerated
    bool is_degenerated(void) const;

    //! Get first vector
    vec3 const &point_0(void) const;

    //! Set first vector
    void point_0(
        vec3 const &input //!< Input object
    );

    //! Get second vector
    vec3 const &point_1(void) const;

    //! Set second vector
    void point_1(
        vec3 const &input //!< Input object
    );

    //! Get i-th point
    vec3 const &point(
        int_type &i //!< Intput i-th vertex
    ) const;

    //! Set i-th point
    void point(
        int_type &i,      //!< Intput i-th vertex
        vec3 const &input //!< Input
    );

    //! Set points
    void points(
        vec3 const &input0, //!< Input object 0
        vec3 const &input1  //!< Input object 1
    );

    //! Convert to vector
    vec3 to_vector(void) const;

    //! Convert to normalized vector
    vec3 to_normalized_vector(void) const;

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    );

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    );

    //! Tranform segment from frameA to frameB
    segment transform(
        frame const &frameA, //!< Actual reference coordinate system
        frame const &frameB  //!< Future reference coordinate system
    ) const;

    //! Swap segment points
    void swap(void);

    //! Calculate segment length
    real_type length(void) const;

    // Check whether the point is inside the segment
    bool is_inside(
        vec3 const &point //!< Input
    ) const;

  }; // class segment

  static segment const NaN_segment = segment(acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number segment type
  static segment segment_goat = segment(NaN_segment);                         //!< Scapegoat segment type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_segment.hh
///