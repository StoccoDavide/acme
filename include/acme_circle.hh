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
/// file: acme_circle.hh
///

#ifndef INCLUDE_ACME_CIRCLE
#define INCLUDE_ACME_CIRCLE

#include "acme.hh"
#include "acme_eigen.hh"
#include "acme_plane.hh"

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
  /**
   * Circle in 3D space and defined by a radius and a plane (circle center + normal vector).
  */
  class circle : public entity
  {
  public:
    typedef std::shared_ptr<circle const> ptr; //!< Shared pointer to circle
    typedef std::pair<ptr, ptr> pairptr;       //!< Pair of pointers to circle objects
    typedef std::vector<ptr> vecptr;           //!< Vector of pointers to circle objects
    typedef std::vector<pairptr> vecpairptr;   //!< Vector of pairs of pointers to circle objects

  private:
    real_type _radius; //!< Circle radius
    plane _plane;      //!< Circle plane (circle center + normal vector)

  public:
    //! Circle class deconstructor
    ~circle() {}

    //! Circle class constructor
    circle() {}

    //! Circle copy constructor
    circle(circle const &) = default;

    //! Circle move constructor
    circle(circle &&) = default;

    //! Circle class constructor
    circle(
        real_type radius,  //!< Input circle radius
        plane const &plane //!< Input circle laying plane
        ) : _radius(radius),
            _plane(plane)
    {
    }

    //! Circle class constructor
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
    isApprox(
        circle const &input //!< Input circle object
    ) const;

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
    layingPlane(void) const;

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
    normalize(void);

    //! Set circle laying plane
    void
    layingPlane(
        plane const &input //!< Input plane object
    );

    //! Reverse direction
    void
    reverse(void);

    //! Translate by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Transform circle with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
    );

    // Check whether the point is inside the circle
    bool
    isInside(
        vec3 const &point //!< Query point
    ) const;

    //! Check if circle is degenerated
    bool
    isDegenerated(void) const;

    //! Return object type as string
    size_t type(void) const override { return 8; }

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
    bool isCircle(void) const override { return true; }

    //! Check whether the object is a box
    bool isBox(void) const override { return false; }

  }; // class circle

  static circle const NaN_circle = circle(acme::NaN, acme::NaN_plane); //!< Not-a-Number circle type
  static circle circle_goat = circle(NaN_circle);                             //!< Scapegoat circle type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_circle.hh
///