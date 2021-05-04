/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       *)
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
(*    Enrico Bertolazzi                                                *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: enrico.bertolazzi@unitn.it                               *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_segment.hh
///

#ifndef INCLUDE_ACME_SEGMENT
#define INCLUDE_ACME_SEGMENT

#include "acme.hh"
#include "acme_aabb.hh"
#include "acme_vector_point.hh"

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
  class segment : public entity
  {
public:
    typedef std::shared_ptr<segment const> ptr; //!< Shared pointer to segment object
    typedef std::pair<ptr, ptr> pairptr;        //!< Pair of pointers to segment objects
    typedef std::vector<ptr> vecptr;            //!< Vector of pointers to segment objects
    typedef std::vector<pairptr> vecpairptr;    //!< Vector of pairs of pointers to segment objects

private:
    point _point[2]; //!< Segment extrema points

public:
    //! Segment class destructor
    ~segment() {}

    //! Segment copy constructor
    segment(segment const &) = default;

    //! Segment move constructor
    segment(segment &&) = default;

    //! Segment class constructor
    segment() {}

    //! Segment class constructor
    segment(
        real x0, //<! Input x value of first segment point
        real y0, //<! Input y value of first segment point
        real z0, //<! Input z value of first segment point
        real x1, //<! Input x value of second segment point
        real y1, //<! Input y value of second segment point
        real z1  //<! Input z value of second segment point
    );

    //! Segment class constructor
    segment(
        point const &point0, //!< Input first segment point
        point const &point1  //!< Input second segment point
    );

    //! Segment class constructor
    segment(
        point const point[2] //!< Input segment points
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

    //! Get segment centroid
    point
    centroid(void) const;

    //! Get segment i-th vertex
    point const &
    vertex(
        integer i //!< Intput segment i-th vertex index
    ) const;

    //! Set segment i-th vertex
    point &
    vertex(
        integer i //!< Intput segment i-th vertex index
    );

    //! Convert segment to vector
    vector
    toVector(void) const;

    //! Convert segment to normalized vector
    vector
    toNormalizedVector(void) const;

    //! Swap segment points
    void
    swap(void);

    //! Get minimum aabb containing the current segment object
    void
    clamp(
        aabb &input //!< Input aabb object
    ) const;

    //! Calculate segment length
    real
    length(void) const;

    //! Translate segment by vector
    void
    translate(
        point const &input //!< Input translation vector
    );

    //! Transform segment with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
    );

    // Check whether the point is inside the segment
    bool
    isInside(
        point const &query_point //!< Query point
    ) const;

    //! Check if segment is degenerated to point˚
    bool
    isDegenerated(void) const;

    //! Return object hierarchical degree
    integer degree(void) const override { return 6; }

    //! Return object type as string
    std::string type(void) const override { return "segment"; }

    //! Check whether the object is no entity
    bool isNone(void) const override { return false; }

    //! Check whether the object is a vector
    bool isPoint(void) const override { return false; }

    //! Check whether the object is a line
    bool isLine(void) const override { return false; }

    //! Check whether the object is a ray
    bool isRay(void) const override { return false; }

    //! Check whether the object is a plane
    bool isPlane(void) const override { return false; }

    //! Check whether the object is a segment
    bool isSegment(void) const override { return true; }

    //! Check whether the object is a triangle
    bool isTriangle(void) const override { return false; }

    //! Check whether the object is a circle
    bool isCircle(void) const override { return false; }

    //! Check whether the object is a aabb
    bool isBox(void) const override { return false; }

  }; // class segment

  static segment const NaN_segment = segment(acme::NaN_point, acme::NaN_point); //!< Not-a-Number segment type
  static segment segment_goat = segment(NaN_segment);                           //!< Scapegoat segment type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_segment.hh
///