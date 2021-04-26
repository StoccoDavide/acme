/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project - Release Version 0.0.0                            *)
(*                                                                     *)
(* Copyright (c) 2020 Davide Stocco, All Rights Reserved.              *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 2-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 2-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
(*                                                                     *)
(*    Davide Stocco                                                    *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: davide.stocco@unitn.it                                   *)
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

  //! Segment class container
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
    isApprox(
        segment const &input //!< Input object
    ) const;

    //! Check if segment is degenerated to point
    bool
    isDegenerated(void) const;

    //! Get segment midpoint
    vec3
    pointMiddle(void) const;

    //! Get segment i-th point
    vec3 const &
    point(
        size_t i //!< Intput segment i-th point index
    ) const;

    //! Set segment i-th point
    vec3 &
    point(
        size_t i //!< Intput segment i-th point index
    );

    //! Convert segment to vector
    vec3
    toVector(void) const;

    //! Convert segment to normalized vector
    vec3
    toNormalizedVector(void) const;

    //! Translate segment by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Transform segment with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
    );

    //! Swap segment points
    void
    swap(void);

    //! Get minimum box containing the current segment object
    void
    clamp(
        box &input //!< Input box object
    ) const;

    //! Calculate segment length
    real_type
    length(void) const;

    // Check whether the point is inside the segment
    bool
    isInside(
        vec3 const &point //!< Query point
    ) const;

  }; // class segment

  static segment const NaN_segment = segment(acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number segment type
  static segment segment_goat = segment(NaN_segment);                         //!< Scapegoat segment type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_segment.hh
///