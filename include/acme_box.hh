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
/// file: acme_box.hh
///

#ifndef INCLUDE_ACME_BOX
#define INCLUDE_ACME_BOX

#include "acme.hh"
#include "acme_math.hh"
#include "acme_frame.hh"

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

  /**
   * Box in 3D space and defined by a "maximum" and a "minimum" point.
  */
  class box
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<box const> ptr; //!< Shared pointer to box object
#else
    typedef box const *ptr; //!< Pointer to box object
#endif

    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to box objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to box objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to box objects

  private:
    vec3 _point_min; //!< Box maximum point
    vec3 _point_max; //!< Box minimum point
    int_type _id;    //!< Box id (may be used in external algorithms)
    int_type _ipos;  //!< Box rank (may be used in external algorithms)

  public:
    //! Box class destructor
    ~box() {}

    //! Box copy constructor
    box(const box &) = default;

    //! Box class constructor
    box() {}

    //! Box class constructor
    box(
        real_type x_min, //<! Input x value of box minimum point
        real_type y_min, //<! Input y value of box minimum point
        real_type z_min, //<! Input z value of box minimum point
        real_type x_max, //<! Input x value of box maximum point
        real_type y_max, //<! Input y value of box maximum point
        real_type z_max, //<! Input z value of box maximum point
        int_type id,     //<! Input id value
        int_type ipos    //<! Input rank value
        ) : _point_min(vec3(x_min, y_min, z_min)),
            _point_max(vec3(x_max, y_max, z_max)),
            _id(id),
            _ipos(ipos)
    {
    }

    //! Box class constructor
    box(
        vec3 const &point_min, //!< Input box minimum point
        vec3 const &point_max, //!< Input box maximum point
        int_type id,           //<! Input box id value
        int_type ipos          //<! Input box rank value
        ) : _point_min(point_min),
            _point_max(point_max),
            _id(id),
            _ipos(ipos)
    {
    }

    //! Box class constructor
    box(
        std::vector<box::ptr> const &boxes, //!< Input pointer to vector of boxes
        int_type id,                        //<! Input box id value
        int_type ipos                       //<! Input box rank value
        ) : _id(id),
            _ipos(ipos)
    {
      this->join(boxes);
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
    is_equal(
        box const &input //!< Input
    ) const;

    //! Check if box is degenerated
    bool
    is_degenerated(void) const;

    //! Check box max and min points
    bool
    check_max_min(void) const;

    //! Update and check box max and min points
    bool
    update_max_min(void);

    //! Get min point
    vec3 const &
    point_min(void) const;

    //! Get box minimum point x value
    real_type
    x_min(void) const;

    //! Get box minimum point y value
    real_type
    y_min(void) const;

    //! Get box minimum point z value
    real_type
    z_min(void) const;

    //! Get box minimum i-th point axis value
    real_type
    min(
        unsigned i //!< Input i-th value
    ) const;

    //! Set box minimum point
    void
    point_min(
        vec3 const &input //!< New box minimum point
    );

    //! Set box minimum point
    void
    point_min(
        real_type x, //!< Input x value of box minimum point
        real_type y, //!< Input y value of box minimum point
        real_type z  //!< Input z value of box minimum point
    );

    //! Set box minimum point x value
    void
    x_min(
        real_type input //!< Input x value of box minimum point
    );

    //! Set box minimum point y value
    void
    y_min(
        real_type input //!< Input y value of box minimum point
    );

    //! Set box minimum point z value
    void
    z_min(
        real_type input //!< Input z value of box minimum point
    );

    //! Set box minimum i-th point axis value
    void
    min(
        unsigned i,     //!< Input i-th value
        real_type input //!< Input value of box minimum point
    );

    //! Get box maximum point
    vec3 const &
    point_max(void) const;

    //! Get box maximum point x value
    real_type
    x_max(void) const;

    //! Get box maximum point y value
    real_type
    y_max(void) const;

    //! Get box maximum point z value
    real_type
    z_max(void) const;

    //! Get box maximum i-th point axis value
    real_type
    max(
        unsigned i //!< Input i-th value
    ) const;

    //! Set box maximum point
    void
    point_max(
        vec3 const &input //!< Input box maximum point
    );

    //! Set box maximum point
    void
    point_max(
        real_type x, //!< Input x value of box maximum point
        real_type y, //!< Input y value of box maximum point
        real_type z  //!< Input z value of box maximum point
    );

    //! Set box maximum point x value
    void
    x_max(
        real_type input //!<Input x value of box maximum point
    );

    //! Set box maximum point y value
    void
    y_max(
        real_type input //!<Input y value of box maximum point
    );

    //! Set box maximum point z value
    void
    z_max(
        real_type input //!<Input z value of box maximum point
    );

    //! Set box maximum i-th point axis value
    void
    max(
        unsigned i,     //!< Input i-th value
        real_type input //!< Input value of box maximum point
    );

    //! Translate box by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Get translated box by vector
    box
    translated(
        vec3 const &input //!< Input translation vector
    );

    //! Rotate box by matrix
    void
    rotate(
        mat3 const &input //!< Input 3x3 rotation matrix
    );

    //! Get rotated box by matrix
    box
    rotated(
        mat3 const &input //!< Input 3x3 rotation matrix
    );

    //! Transform box from two coordinate frames
    void
    transform(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    );

    //! Get transform box from two coordinate frames
    box
    transformed(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    ) const;

    //! Detect if boxes collide
    bool
    collision(
        box const &input //!< Input
    ) const;

    //! Build box with a vector of pointers to boxes
    void
    join(
        box::vecptr const &boxes //!< Input poiter to vector of boxes
    );

    //! Distance of a point to the box
    real_type
    distance(
        vec3 const &point //!< Query point
    ) const;

    //! Maximum distance of a point to the box
    real_type
    max_distance(
        vec3 const &point //!< Query point
    ) const;

    //! Resize the box as the minimum bounding box containing three input points
    void
    minimum_box(
        vec3 const &point0, //!< Input point 0
        vec3 const &point1, //!< Input point 1
        vec3 const &point2  //!< Input point 2
    );

    //! Resize the box as the minimum bounding box containing three input points
    void
    minimum_box(
        vec3 const points[3] //!< Input points
    );

    //!< Return box id
    int_type const &
    id(void) const;

    //!< Return box position
    int_type const &
    pos(void) const;

  }; //class box

  static box const NaN_box = box(acme::NaN_vec3, acme::NaN_vec3, 0, 0); //!< Not-a-Number box type
  static box box_goat = box(NaN_box);                                   //!< Scapegoat box type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_box.hh
///