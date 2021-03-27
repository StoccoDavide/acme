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
/// file: acme_circle.hh
///

#ifndef INCLUDE_ACME_CIRCLE
#define INCLUDE_ACME_CIRCLE

#include "acme.hh"
#include "acme_math.hh"
#include "acme_plane.hh"
#include "acme_frame.hh"

namespace acme
{

  /*\
   |        _          _      
   |    ___(_)_ __ ___| | ___ 
   |   / __| | '__/ __| |/ _ \
   |  | (__| | | | (__| |  __/
   |   \___|_|_|  \___|_|\___|
   |                          
  \*/

  //! Circle class container
  /*!
  Circle in 3D space and defined by a radius and a plane (circle center + normal vector).
  */
  class circle
  {
    real_type _radius; //!< Circle radius
    plane _plane;      //!< Circle plane (circle center + normal vector)

  public:
    //! Class deconstructor
    ~circle() {}

    //! Class constructor
    circle() {}

    //! Copy constructor
    circle(circle const &) = default;

    //! Class constructor
    circle(
        real_type radius,  //!< Input
        plane const &plane //!< Input
        ) : _radius(radius), _plane(plane)
    {
    }

    //! Class constructor
    circle(
        real_type radius,   //!< Input
        vec3 const &center, //!< Input
        vec3 const &normal  //!< Input
        ) : _radius(radius), _plane(center, normal)
    {
    }

    //! Equality operator
    circle &operator=(
        circle const &input //!< Input
    );

    //! Check if objects are (almost) equal
    bool is_equal(
        circle const &input //!< Input
    ) const;

    //! Check if ray is degenerated
    bool is_degenerated(void) const;

    //! Get radius
    real_type radius() const;

    //! Get center point
    vec3 const &center() const;

    //! Get normal vector
    vec3 const &normal() const;

    //! Get plane
    plane const &laying_plane() const;

    //! Set center point
    void radius(
        real_type input //!< Input
    );

    //! Set center point
    void center(
        vec3 const &input //!< Input
    );

    //! Set normal vector
    void normal(
        vec3 const &input //!< Input
    );

    //! Set plane
    void laying_plane(
        plane const &input //!< Input
    );

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    );

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    );

    //! Tranform circle from frameA to frameB
    circle transform(
        frame const &frameA, //!< Actual reference coordinate system
        frame const &frameB  //!< Future reference coordinate system
    ) const;

    //! Reverse direction
    void reverse(void);

    //! Get reversed circle
    circle reversed(void) const;

    // Check whether the point is inside the circle
    bool is_inside(
        vec3 const &point //!< Input
    ) const;

  }; // class circle

  static circle const NaN_circle = circle(acme::NaN, acme::NaN_plane); //!< Not-a-Number triangle type
  static circle circle_goat = circle(NaN_circle);                      //!< Scapegoat circle type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_circle.hh
///