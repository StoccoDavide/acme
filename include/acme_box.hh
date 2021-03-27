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

  //! Box class container
  /*!
  Box in 3D space and defined by a "maximum" and a "minimum" point.
  */
  class box
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<box const> boxPtr; //!< Shared pointer to box
#else
    typedef box const *boxPtr; //!< Pointer to box
#endif

  private:
    vec3 _point_min; //!< Point min
    vec3 _point_max; //!< Point max
    int_type _id;    //!< Id of the box
    int_type _ipos;  //!< Rank of the bounding box (used in external algorithms)

  public:
    //! Class destructor
    ~box() {}

    //! Copy constructor
    box(const box &) = default;

    //! Class constructor
    box() {}

    //! Class constructor
    box(
        real_type x_min,  //<! Input x value of minimum point
        real_type y_min,  //<! Input y value of minimum point
        real_type z_min,  //<! Input z value of minimum point
        real_type x_max,  //<! Input x value of maximum point
        real_type y_max,  //<! Input y value of maximum point
        real_type z_max,  //<! Input z value of maximum point
        int_type id = 0,  //<! Input id value
        int_type ipos = 0 //<! Input rank value
        ) : _point_min(vec3(x_min, y_min, z_min)), _point_max(vec3(x_max, y_max, z_max)), _id(id), _ipos(ipos)
    {
    }

    //! Class constructor
    box(
        vec3 const &point_min, //!< Input minimum point
        vec3 const &point_max, //!< Input maximum point
        int_type id = 0,       //<! Input id value
        int_type ipos = 0      //<! Input rank value
        ) : _point_min(point_min), _point_max(point_max), _id(id), _ipos(ipos)
    {
    }

    //! Class constructor
    box(
        std::vector<boxPtr> const &boxes, //!< Input poiter to vector of boxes
        int_type id = 0,                  //<! Input id value
        int_type ipos = 0                 //<! Input rank value
    )
    {
      this->_id = id;
      this->_ipos = ipos;
      this->join(boxes);
    }

    //! Equality operator
    box &operator=(
        box const &input //!< Input
    );

    //! Check if objects are (almost) equal
    bool is_equal(
        box const &input //!< Input
    ) const;

    //! Check if box is degenerated
    bool is_degenerated(void) const;

    //! Check box max and min points
    bool check_max_min(void) const;

    //! Update and check box max and min points
    bool update_max_min(void);

    //! Get min point
    vec3 const &point_min(void) const;

    //! Get min point x value
    real_type x_min(void) const;

    //! Get min point y value
    real_type y_min(void) const;

    //! Get min point z value
    real_type z_min(void) const;

    //! Get min i-th point axis value
    real_type min(
        const int_type i //!< Input i-th value
    ) const;

    //! Set min point
    void point_min(
        vec3 const &input //!< Input
    );
    //! Set min point x value
    void x_min(
        real_type input //!<Input
    );

    //! Set min point y value
    void y_min(
        real_type input //!<Input
    );

    //! Set min point z value
    void z_min(
        real_type input //!<Input
    );

    //! Set min i-th point axis value
    void min(
        int_type i,     //!< Input i-th value
        real_type input //!<Input
    );

    //! Get max point
    vec3 const &point_max(void) const;

    //! Get max point x value
    real_type x_max(void) const;

    //! Get max point y value
    real_type y_max(void) const;

    //! Get max point z value
    real_type z_max(void) const;

    //! Get max i-th point axis value
    real_type max(
        int_type i //!< Input i-th value
    ) const;

    //! Set max point
    void point_max(
        vec3 const &input //!< Input
    );

    //! Set max point x value
    void x_max(
        real_type input //!<Input
    );

    //! Set max point y value
    void y_max(
        real_type input //!<Input
    );

    //! Set max point z value
    void z_max(
        real_type input //!<Input
    );

    //! Set max i-th point axis value
    void max(
        int_type i,     //!< Input i-th value
        real_type input //!<Input
    );

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    );

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    );

    //! Tranform box from frameA to frameB
    box transform(
        frame const &frameA, //!< Actual reference coordinate system
        frame const &frameB  //!< Future reference coordinate system
    ) const;

    //! Detect if boxes collide
    bool collision(
        box const &input //!< Input
    ) const;

    //! Build box wirh a list of boxes
    void
    join(
        std::vector<boxPtr> const &boxes //!< Input poiter to vector of boxes
    );

    //! Distance of the point to the box
    real_type distance(
        vec3 const &point //!< Input
    ) const;

    //! Maximum distance of the point to the point of box
    real_type max_distance(
        vec3 const &point //!< Input
    ) const;

    //! Get the minimum bounding box containing three input points
    void minimum_box(
        vec3 const points[3] //!< Input
    );

    //!< return box id
    int_type const &id() const;

    //!< return box position
    int_type const &pos() const;

  }; //class box

  static box const NaN_box = box(acme::NaN_vec3, acme::NaN_vec3, 0, 0); //!< Not-a-Number box type
  static box box_goat = box(NaN_box);                                   //!< Scapegoat box type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_box.hh
///