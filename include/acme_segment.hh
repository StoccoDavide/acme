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
#include "acme_box.hh"

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

  /**
  * Segment in 3D space. The segment is defined by two arbitrary points.
  */
  class segment
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<segment const> ptr; //!< Shared pointer to segment object
#else
    typedef segment const *ptr; //!< Pointer to segment object
#endif

    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to segment objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to segment objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to segment objects

  private:
    vec3 _point[2]; //!< Segment extrema points

  public:
    //! Segment class destructor
    ~segment() {}

    //! Segment copy constructor
    segment(segment const &) = default;

    //! Segment class constructor
    segment() {}

    //! Segment class constructor
    segment(
        real_type x0, //<! Input x value of first segment point
        real_type y0, //<! Input y value of first segment point
        real_type z0, //<! Input z value of first segment point
        real_type x1, //<! Input x value of second segment point
        real_type y1, //<! Input y value of second segment point
        real_type z1  //<! Input z value of second segment point
    );

    //! Segment class constructor
    segment(
        vec3 const &point0, //!< Input first segment point
        vec3 const &point1  //!< Input second segment point
    );

    //! Segment class constructor
    segment(
        vec3 const point[2] //!< Input segment points
    );

    //! Equality operator
    segment &
    operator=(
        segment const &input //!< Input segment object
    );

    //! Check if segments are (almost) equal
    bool
    is_equal(
        segment const &input //!< Input object
    ) const;

    //! Check if segment is degenerated to point
    bool
    is_degenerated(void) const;

    //! Get first segment point
    vec3 const &
    point_0(void) const;

    //! Set first segment point
    void
    point_0(
        vec3 const &input //!< New segment point
    );

    //! Get second segment point
    vec3 const &
    point_1(void) const;

    //! Set second segment point
    void
    point_1(
        vec3 const &input //!< New segment point
    );

    //! Get segment midpoint
    vec3
    midpoint(void) const;

    //! Get segment i-th point
    vec3 const &
    point(
        unsigned i //!< Intput segment i-th point index
    ) const;

    //! Set segment i-th point
    void
    point(
        unsigned i,       //!< Intput segment i-th point index
        vec3 const &input //!< New segment point
    );

    //! Set segment points
    void
    points(
        vec3 const &input0, //!< New first segment point
        vec3 const &input1  //!< New second segment point
    );

    //! Convert segment to vector
    vec3
    to_vector(void) const;

    //! Convert segment to normalized vector
    vec3
    to_normalized_vector(void) const;

    //! Translate segment by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Get translated segment by vector
    segment
    translated(
        vec3 const &input //!< Input translation vector
    ) const;

    //! Rotate by matrix
    void
    rotate(
        mat3 const &input //!< Input 3x3 rotation matrix
    );

    //! Get rotated by matrix
    segment
    rotated(
        mat3 const &input //!< Input 3x3 rotation matrix
    ) const;

    //! Transform segment from two coordinate frames
    void
    transform(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    );

    //! Get transformed segment from two coordinate frames
    segment
    transformed(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    ) const;

    //! Swap segment points
    void
    swap(void);

    //! Get minimum box containing the current segment object
    void
    minimum_box(
        box &input //!< Input box object
    ) const;

    //! Calculate segment length
    real_type
    length(void) const;

    // Check whether the point is inside the segment
    bool
    is_inside(
        vec3 const &point //!< Query point
    ) const;

  }; // class segment

  } // namespace acme

#endif

///
/// eof: acme_segment.hh
///