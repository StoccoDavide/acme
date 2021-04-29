/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *)
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
#include "acme_eigen.hh"

namespace acme
{

  /*\
   |   _               
   |  | |__   _____  _ 
   |  | '_ \ / _ \ \/ /
   |  | |_) | (_) >  < 
   |  |_.__/ \___/_/\_\
   |                   
  \*/

  //! Box class container
  /**
   * Box in 3D space and defined by a "maximum" and a "minimum" point.
  */
  class box : public entity
  {
  public:
    typedef std::shared_ptr<box const> ptr;  //!< Shared pointer to box object
    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to box objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to box objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to box objects

  private:
    vec3 _min;      //!< Box maximum point
    vec3 _max;      //!< Box minimum point
    int_type _id;   //!< Box id (may be used in external algorithms)
    int_type _ipos; //!< Box rank (may be used in external algorithms)

  public:
    //! Box class destructor
    ~box() {}

    //! Box copy constructor
    box(const box &) = default;

    //! Box move constructor
    box(box &&) = default;

    //! Box class constructor
    box()
        : _min(NaN_vec3),
          _max(NaN_vec3),
          _id(0),
          _ipos(0)
    {
    }

    //! Box class constructor
    box(
        real_type minX, //<! Input x value of box minimum point
        real_type minY, //<! Input y value of box minimum point
        real_type minZ, //<! Input z value of box minimum point
        real_type maxX, //<! Input x value of box maximum point
        real_type maxY, //<! Input y value of box maximum point
        real_type maxZ, //<! Input z value of box maximum point
        int_type id,    //<! Input id value
        int_type ipos   //<! Input rank value
        ) : _min(vec3(minX, minY, minZ)),
            _max(vec3(maxX, maxY, maxZ)),
            _id(id),
            _ipos(ipos)
    {
      this->updateMaxMin();
    }

    //!
    //! Box class constructor
    //!
    //! \param min  Input box minimum point
    //! \param max  Input box maximum point
    //! \param id   Input box id value
    //! \param ipos Input box rank value
    //!
    //!
    box(
        vec3 const &min,
        vec3 const &max,
        int_type id,
        int_type ipos)
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
    //! \param id    Input box id value
    //! \param ipos  Input box rank value
    //!
    //!
    box(
        std::vector<box::ptr> const &boxes,
        int_type id,
        int_type ipos)
        : _id(id),
          _ipos(ipos)
    {
      this->merged(boxes);
      this->updateMaxMin();
    }

    //! Equality operator
    box &operator=(
        box const &input //!< Input
    );

    //! Clear the box domain (set to Not-a-Number)
    void
    clear(void);

    //! Check if box objects are (almost) equal
    bool
    isApprox(
        box const &input //!< Input
    ) const;

    //! Check box max and min points
    bool
    checkMaxMin(void) const;

    //! Update and check box max and min points
    bool
    updateMaxMin(void);

    //! Get min point
    vec3 const &
    min(void) const;

    //! Get box minimum point x value
    real_type
    minX(void) const;

    //! Get box minimum point y value
    real_type
    minY(void) const;

    //! Get box minimum point z value
    real_type
    minZ(void) const;

    //! Get box minimum i-th point axis value
    real_type
    min(
        size_t i //!< Input i-th value
    ) const;

    //! Set box minimum point
    void
    min(
        vec3 const &input //!< New box minimum point
    );

    //! Set box minimum point
    void
    min(
        real_type x, //!< Input x value of box minimum point
        real_type y, //!< Input y value of box minimum point
        real_type z  //!< Input z value of box minimum point
    );

    //! Set box minimum point x value
    void
    minX(
        real_type input //!< Input x value of box minimum point
    );

    //! Set box minimum point y value
    void
    minY(
        real_type input //!< Input y value of box minimum point
    );

    //! Set box minimum point z value
    void
    minZ(
        real_type input //!< Input z value of box minimum point
    );

    //! Set box minimum i-th point axis value
    void
    min(
        size_t i,       //!< Input i-th value
        real_type input //!< Input value of box minimum point
    );

    //! Get box maximum point
    vec3 const &
    max(void) const;

    //! Get box maximum point x value
    real_type
    maxX(void) const;

    //! Get box maximum point y value
    real_type
    maxY(void) const;

    //! Get box maximum point z value
    real_type
    maxZ(void) const;

    //! Get box maximum i-th point axis value
    real_type
    max(
        size_t i //!< Input i-th value
    ) const;

    //! Set box maximum point
    void
    max(
        vec3 const &input //!< Input box maximum point
    );

    //! Set box maximum point
    void
    max(
        real_type x, //!< Input x value of box maximum point
        real_type y, //!< Input y value of box maximum point
        real_type z  //!< Input z value of box maximum point
    );

    //! Set box maximum point x value
    void
    maxX(
        real_type input //!<Input x value of box maximum point
    );

    //! Set box maximum point y value
    void
    maxY(
        real_type input //!<Input y value of box maximum point
    );

    //! Set box maximum point z value
    void
    maxZ(
        real_type input //!<Input z value of box maximum point
    );

    //! Set box maximum i-th point axis value
    void
    max(
        size_t i,       //!< Input i-th value
        real_type input //!< Input value of box maximum point
    );

    //! Detect if boxes collide
    bool
    intersects(
        box const &input //!< Input
    ) const;

    //! Build box with a vector of pointers to boxes
    void
    merged(
        box::vecptr const &boxes //!< Input poiter to vector of boxes
    );

    //! Distance of a point to the box
    real_type
    centerDistance(
        vec3 const &point //!< Query point
    ) const;

    //! Maximum distance of a point to the box
    real_type
    exteriorDistance(
        vec3 const &point //!< Query point
    ) const;

    //! Resize the box as the minimum bounding box containing three input points
    void
    clamp(
        vec3 const &point0, //!< Input point 0
        vec3 const &point1, //!< Input point 1
        vec3 const &point2  //!< Input point 2
    );

    //! Resize the box as the minimum bounding box containing three input points
    void
    clamp(
        vec3 const points[3] //!< Input points
    );

    //!< Return box id
    int_type const &
    id(void) const;

    //!< Return box position
    int_type const &
    pos(void) const;

    //! Translate box by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Transform box with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
    );

    // Check whether the point is inside the box
    bool
    isInside(
        vec3 const &point //!< Query point
    ) const;

    //! Check if box is degenerated
    bool
    isDegenerated(void) const;

    //! Return object type as string
    size_t type(void) const override { return 9; }

    //! Check whether the object is a point
    bool isMatrix(void) const override { return false; }

    //! Check whether the object is a vector
    bool isVector(void) const override { return false; }

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

    //! Check whether the object is a box
    bool isBox(void) const override { return true; }

  }; //class box

  static box const NaN_box = box(acme::NaN_vec3, acme::NaN_vec3, 0, 0); //!< Not-a-Number box type
  static box box_goat = box(NaN_box);                                   //!< Scapegoat box type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_box.hh
///