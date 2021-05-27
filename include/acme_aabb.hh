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
/// file: acme_box.hh
///

#ifndef INCLUDE_ACME_BOX
#define INCLUDE_ACME_BOX

#include "acme.hh"
#include "acme_point.hh"

namespace acme
{

  /*\
   |               _     _     
   |    __ _  __ _| |__ | |_   
   |   / _` |/ _` | '_ \| '_ \ 
   |  | (_| | (_| | |_) | |_) |
   |   \__,_|\__,_|_.__/|_.__/ 
   |                           
  \*/

  //! Axis-aligebd bounding box class container
  /**
   * Axis-aligebd bounding box in 3D space and defined by a "maximum" and a "minimum" point.
  */
  class aabb
  {
  public:
    typedef std::shared_ptr<aabb const> ptr; //!< Shared pointer to const aabb object used in AABBtree routines
    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to const aabb objects used in AABBtree routines
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to const aabb objects used in AABBtree routines
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to const aabb objects used in AABBtree routines

  private:
    point m_min;   //!< Box maximum point
    point m_max;   //!< Box minimum point
    integer m_id;  //!< Box id (may be used in external algorithms)
    integer m_pos; //!< Box rank (may be used in external algorithms)

  public:
    //! Box class destructor
    ~aabb() {}

    //! Box copy constructor
    aabb(const aabb &) = default;

    //! Box move constructor
    aabb(aabb &&) = default;

    //! Box class constructor
    aabb()
        : m_min(NAN_POINT),
          m_max(NAN_POINT),
          m_id(0),
          m_pos(0)
    {
    }

    //! Box class constructor
    aabb(
        real min_x,  //<! Input x value of aabb minimum point
        real min_y,  //<! Input y value of aabb minimum point
        real min_z,  //<! Input z value of aabb minimum point
        real max_x,  //<! Input x value of aabb maximum point
        real max_y,  //<! Input y value of aabb maximum point
        real max_z,  //<! Input z value of aabb maximum point
        integer id,  //<! Input id value
        integer ipos //<! Input rank value
        )
        : m_min(min_x, min_y, min_z),
          m_max(max_x, max_y, max_z),
          m_id(id),
          m_pos(ipos)
    {
      this->updateMaxMin();
    }

    //! Box class constructor
    aabb(
        point const &min, //!< Input aabb minimum point
        point const &max, //!< Input aabb maximum point
        integer id,       //!< Input aabb id value
        integer ipos      //!< Input aabb rank value
        )
        : m_min(min),
          m_max(max),
          m_id(id),
          m_pos(ipos)
    {
      this->updateMaxMin();
    }

    //! Box class constructor
    aabb(
        std::vector<aabb::ptr> const &boxes, //!< Input reference to vector of boxes
        integer id,                          //!< Input aabb id value
        integer ipos                         //!< Input aabb rank value
        )
        : m_id(id),
          m_pos(ipos)
    {
      this->merged(boxes);
      this->updateMaxMin();
    }

    //! Equality operator
    aabb &operator=(
        aabb const &aabb_in //!< Input
    );

    //! Clear the aabb domain (set to Not-a-Number)
    void
    clear(void);

    //! Check if aabb objects are (almost) equal
    bool
    isApprox(
        aabb const &aabb_in,     //!< Input
        real tolerance = EPSILON //!< Tolerance
    ) const;

    //! Check aabb max and min points
    bool
    checkMaxMin(void) const;

    //! Update and check aabb max and min points
    bool
    updateMaxMin(void);

    //! Get minimum point const reference
    point const &
    min(void) const;

    //! Get minimum point reference
    point &
    min(void);

    //! Get aabb minimum i-th axis value const reference
    real const &
    min(
        size_t i //!< Input i-th value
    ) const;

    //! Get aabb minimum i-th axis value reference
    real &
    min(
        size_t i //!< Input i-th value
    );

    //! Set aabb minimum point
    void
    min(
        real x, //!< Input x value of aabb minimum point
        real y, //!< Input y value of aabb minimum point
        real z  //!< Input z value of aabb minimum point
    );

    //! Get aabb maximum point const reference
    point const &
    max(void) const;

    //! Get aabb maximum point reference
    point &
    max(void);

    //! Get aabb maximum i-th point axis value const reference
    real const &
    max(
        size_t i //!< Input i-th value
    ) const;

    //! Get aabb maximum i-th point axis value
    real &
    max(
        size_t i //!< Input i-th value
    );

    //! Set aabb maximum point
    void
    max(
        real x, //!< Input x value of aabb maximum point
        real y, //!< Input y value of aabb maximum point
        real z  //!< Input z value of aabb maximum point
    );

    //! Detect if boxes collide
    bool
    intersects(
        aabb const &aabb_in //!< Input
    ) const;

    //! Build aabb with a vector of pointers to boxes
    void
    merged(
        aabb::vecptr const &boxes //!< Input poiter to vector of boxes
    );

    //! Distance of a point to the aabb
    real
    centerDistance(
        point const &point_in //!< Query point
    ) const;

    //! Maximum distance of a point to the aabb
    real
    exteriorDistance(
        point const &point_in //!< Query point
    ) const;

    //! Resize the aabb as the minimum bounding aabb containing three input points
    void
    clamp(
        point const &point0_in, //!< Input point 0
        point const &point1_in, //!< Input point 1
        point const &point2_in  //!< Input point 2
    );

    //! Resize the aabb as the minimum bounding aabb containing three input points
    void
    clamp(
        point const point_in[3] //!< Input points
    );

    //!< Return aabb id
    integer const &
    id(void) const;

    //!< Return aabb position
    integer const &
    pos(void) const;

    //! Translate aabb by vector
    void
    translate(
        vec3 const &vector_in //!< Input translation vector
    );

    // Check whether the point is inside the aabb
    bool
    isInside(
        point const &point_in,   //!< Query point
        real tolerance = EPSILON //!< Tolerance
    ) const;

    //! Check if aabb is degenerated
    bool
    isDegenerated(
        real tolerance = EPSILON //!< Tolerance
    ) const;

  }; //class aabb

  static aabb const NAN_AABB = aabb(NAN_POINT, NAN_POINT, 0, 0); //!< Not-a-Number static const aabb object
  static aabb THROWAWAY_AABB = aabb(NAN_AABB);                   //!< Throwaway static non-const aabb object

} // namespace acme

#endif

///
/// eof: acme_box.hh
///