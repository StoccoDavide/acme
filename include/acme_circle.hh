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

namespace acme
{

  class frame;

  /*\
   |        _          _      
   |    ___(_)_ __ ___| | ___ 
   |   / __| | '__/ __| |/ _ \
   |  | (__| | | | (__| |  __/
   |   \___|_|_|  \___|_|\___|
   |                          
  \*/

  //! Circle class container
  /**
   * Circle in 3D space and defined by a radius and a plane (circle center + normal vector).
  */
  class circle
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<circle const> ptr; //!< Shared pointer to circle
#else
    typedef circle const *ptr; //!< Pointer to circle
#endif

    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to circle objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to circle objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to circle objects

  private:
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
        real_type radius,  //!< Input circle radius
        plane const &plane //!< Input circle laying plane
        ) : _radius(radius),
            _plane(plane)
    {
    }

    //! Class constructor
    circle(
        real_type radius,   //!< Input circle radius
        vec3 const &center, //!< Input circle center
        vec3 const &normal  //!< Input circle normal to the laying plane
        ) : _radius(radius),
            _plane(center, normal)
    {
    }

    //! Equality operator
    circle &
    operator=(
        circle const &input //!< Input circle object
    );

    //! Check if circles are (almost) equal
    bool
    is_equal(
        circle const &input //!< Input circle object
    ) const;

    //! Check if circle is degenerated
    bool
    is_degenerated(void) const;

    //! Get circle radius
    real_type
    radius(void) const;

    //! Get circle center point
    vec3 const &
    center(void) const;

    //! Get circle laying plane normal vector
    vec3 const &
    normal(void) const;

    //! Get cicle laying plane
    plane const &
    laying_plane(void) const;

    //! Set circle radius
    void
    radius(
        real_type input //!< New circle radius
    );

    //! Set circle center point
    void
    center(
        vec3 const &input //!< New circle center point
    );

    //! Set circle laying plane normal vector
    void
    normal(
        vec3 const &input //!< New circle laying plane normal vector
    );

    //! Normalize circle normal vector
    void
    normalize_normal(void);

    //! Set circle laying plane
    void
    laying_plane(
        plane const &input //!< Input plane object
    );

    //! Translate by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Get translated circle by vector
    circle
    translated(
        vec3 const &input //!< Input translation vector
    ) const;

    //! Rotate by matrix
    void
    rotate(
        mat3 const &input //!< Input 3x3 rotation matrix
    );

    //! Get rotated circle by matrix
    circle
    rotated(
        mat3 const &input //!< Input 3x3 rotation matrix
    ) const;

    //! Transform circle from two coordinate frames
    void transform(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    );

    //! Get transformed circle from two coordinate frames
    circle transformed(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    ) const;

    //! Reverse direction
    void
    reverse(void);

    //! Get circle with reversed plane normal direction
    circle
    reversed(void) const;

    // Check whether the point is inside the circle
    bool
    is_inside(
        vec3 const &point //!< Query point
    ) const;

  }; // class circle

  //static circle const NaN_circle = circle(acme::NaN, acme::NaN_plane); //!< Not-a-Number triangle type
  //static circle circle_goat = circle(NaN_circle);                      //!< Scapegoat circle type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_circle.hh
///