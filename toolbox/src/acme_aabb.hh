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
  class aabb : public entity
  {
public:
    typedef std::shared_ptr<aabb const> ptr; //!< Shared pointer to aabb object
    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to aabb objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to aabb objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to aabb objects

private:
    point _min;    //!< Box maximum point
    point _max;    //!< Box minimum point
    integer _id;   //!< Box id (may be used in external algorithms)
    integer _ipos; //!< Box rank (may be used in external algorithms)

public:
    //! Box class destructor
    ~aabb() {}

    //! Box copy constructor
    aabb(const aabb &) = default;

    //! Box move constructor
    aabb(aabb &&) = default;

    //! Box class constructor
    aabb()
        : _min(NaN_point),
          _max(NaN_point),
          _id(0),
          _ipos(0)
    {
    }

    //! Box class constructor
    aabb(
        real minX,   //<! Input x value of aabb minimum point
        real minY,   //<! Input y value of aabb minimum point
        real minZ,   //<! Input z value of aabb minimum point
        real maxX,   //<! Input x value of aabb maximum point
        real maxY,   //<! Input y value of aabb maximum point
        real maxZ,   //<! Input z value of aabb maximum point
        integer id,  //<! Input id value
        integer ipos //<! Input rank value
        ) : _min(point(minX, minY, minZ)),
            _max(point(maxX, maxY, maxZ)),
            _id(id),
            _ipos(ipos)
    {
      this->updateMaxMin();
    }

    //!
    //! Box class constructor
    //!
    //! \param min  Input aabb minimum point
    //! \param max  Input aabb maximum point
    //! \param id   Input aabb id value
    //! \param ipos Input aabb rank value
    //!
    //!
    aabb(
        point const &min,
        point const &max,
        integer id,
        integer ipos)
        : _min(min),
          _max(max),
          _id(id),
          _ipos(ipos)
    {
      this->updateMaxMin();
    }

    //!
    //! Box class constructor
    //!
    //! \param boxes Input reference to vector of boxes
    //! \param id    Input aabb id value
    //! \param ipos  Input aabb rank value
    //!
    //!
    aabb(
        std::vector<aabb::ptr> const &boxes,
        integer id,
        integer ipos)
        : _id(id),
          _ipos(ipos)
    {
      this->merged(boxes);
      this->updateMaxMin();
    }

    //! Equality operator
    aabb &operator=(
        aabb const &input //!< Input
    );

    //! Clear the aabb domain (set to Not-a-Number)
    void
    clear(void);

    //! Check if aabb objects are (almost) equal
    bool
    isApprox(
        aabb const &input //!< Input
    ) const;

    //! Check aabb max and min points
    bool
    checkMaxMin(void) const;

    //! Update and check aabb max and min points
    bool
    updateMaxMin(void);

    //! Get min point
    point const &
    min(void) const;

    //! Get aabb minimum point x value
    real
    minX(void) const;

    //! Get aabb minimum point y value
    real
    minY(void) const;

    //! Get aabb minimum point z value
    real
    minZ(void) const;

    //! Get aabb minimum i-th point axis value
    real
    min(
        integer i //!< Input i-th value
    ) const;

    //! Set aabb minimum point
    void
    min(
        point const &input //!< New aabb minimum point
    );

    //! Set aabb minimum point
    void
    min(
        real x, //!< Input x value of aabb minimum point
        real y, //!< Input y value of aabb minimum point
        real z  //!< Input z value of aabb minimum point
    );

    //! Set aabb minimum point x value
    void
    minX(
        real input //!< Input x value of aabb minimum point
    );

    //! Set aabb minimum point y value
    void
    minY(
        real input //!< Input y value of aabb minimum point
    );

    //! Set aabb minimum point z value
    void
    minZ(
        real input //!< Input z value of aabb minimum point
    );

    //! Set aabb minimum i-th point axis value
    void
    min(
        integer i, //!< Input i-th value
        real input //!< Input value of aabb minimum point
    );

    //! Get aabb maximum point
    point const &
    max(void) const;

    //! Get aabb maximum point x value
    real
    maxX(void) const;

    //! Get aabb maximum point y value
    real
    maxY(void) const;

    //! Get aabb maximum point z value
    real
    maxZ(void) const;

    //! Get aabb maximum i-th point axis value
    real
    max(
        integer i //!< Input i-th value
    ) const;

    //! Set aabb maximum point
    void
    max(
        point const &input //!< Input aabb maximum point
    );

    //! Set aabb maximum point
    void
    max(
        real x, //!< Input x value of aabb maximum point
        real y, //!< Input y value of aabb maximum point
        real z  //!< Input z value of aabb maximum point
    );

    //! Set aabb maximum point x value
    void
    maxX(
        real input //!<Input x value of aabb maximum point
    );

    //! Set aabb maximum point y value
    void
    maxY(
        real input //!<Input y value of aabb maximum point
    );

    //! Set aabb maximum point z value
    void
    maxZ(
        real input //!<Input z value of aabb maximum point
    );

    //! Set aabb maximum i-th point axis value
    void
    max(
        integer i, //!< Input i-th value
        real input //!< Input value of aabb maximum point
    );

    //! Detect if boxes collide
    bool
    intersects(
        aabb const &input //!< Input
    ) const;

    //! Build aabb with a vector of pointers to boxes
    void
    merged(
        aabb::vecptr const &boxes //!< Input poiter to vector of boxes
    );

    //! Distance of a point to the aabb
    real
    centerDistance(
        point const &query_point //!< Query point
    ) const;

    //! Maximum distance of a point to the aabb
    real
    exteriorDistance(
        point const &query_point //!< Query point
    ) const;

    //! Resize the aabb as the minimum bounding aabb containing three input points
    void
    clamp(
        point const &point0, //!< Input point 0
        point const &point1, //!< Input point 1
        point const &point2  //!< Input point 2
    );

    //! Resize the aabb as the minimum bounding aabb containing three input points
    void
    clamp(
        point const points[3] //!< Input points
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
        vec3 const &input //!< Input translation vector
        ) override;

    //! Transform aabb with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
        ) override;

    // Check whether the point is inside the aabb
    bool
    isInside(
        point const &query_point //!< Query point
    ) const;

    //! Check if aabb is degenerated
    bool
    isDegenerated(void) const override;

    //! Return object hierarchical degree
    integer degree(void) const override { return 9; }

    //! Return object type as string
    std::string type(void) const override { return "aabb"; }

    //! Check whether the object is no entity
    bool isNone(void) const override { return false; }

    //! Check whether the object is a point
    bool isPoint(void) const override { return false; }

    //! Check whether the object is a line
    bool isLine(void) const override { return false; }

    //! Check whether the object is a ray
    bool isRay(void) const override { return false; }

    //! Check whether the object is a plane
    bool isPlane(void) const override { return false; }

    //! Check whether the object is a segment
    bool isSegment(void) const override { return false; }

    //! Check whether the object is a triangle
    bool isTriangle(void) const override { return false; }

    //! Check whether the object is a circle
    bool isCircle(void) const override { return false; }

    //! Check whether the object is a aabb
    bool isBox(void) const override { return true; }

  }; //class aabb

  static aabb const NaN_box = aabb(acme::NaN_point, acme::NaN_point, 0, 0); //!< Not-a-Number aabb type
  static aabb box_goat = aabb(NaN_box);                                     //!< Scapegoat aabb type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_box.hh
///