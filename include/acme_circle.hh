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
/// file: acme_circle.hh
///

#ifndef INCLUDE_ACME_CIRCLE
#define INCLUDE_ACME_CIRCLE

#include "acme.hh"
#include "acme_plane.hh"
#include "acme_point.hh"
#include "acme_aabb.hh"

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
    real _radius; //!< Circle radius
    plane _plane; //!< Circle plane (circle center + normal vector)

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
        real radius,       //!< Input circle radius
        plane const &plane //!< Input circle laying plane
        ) : _radius(radius),
            _plane(plane)
    {
    }

    //! Circle class constructor
    circle(
        real radius,         //!< Input circle radius
        point const &center, //!< Input circle center
        vec3 const &normal   //!< Input circle normal to the laying plane
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
    real
    radius(void) const;

    //! Get circle center point
    point const &
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
        real input //!< New circle radius
    );

    //! Set circle center point
    void
    center(
        point const &input //!< New circle center point
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

    //! Reverse circle normal vector
    void
    reverse(void);

    //! Get minumum cubic aabb containing the current circle object
    void
    clamp(
        aabb &input //!< Input aabb object
    ) const;

    //! Calculate circle circumference length
    real
    perimeter(void)
        const;

    //! Calculate circle area
    real
    area(void) const;

    //! Translate by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
        ) override;

    //! Transform circle with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
        ) override;

    // Check whether the point is inside the circle
    bool
    isInside(
        point const &query_point //!< Query point
    ) const;

    //! Check if circle is degenerated
    bool
    isDegenerated(void) const override;

    //! Return object hierarchical degree
    integer degree(void) const override { return 8; }

    //! Return object type as string
    std::string type(void) const override { return "circle"; }

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
    bool isCircle(void) const override { return true; }

    //! Check whether the object is a aabb
    bool isBox(void) const override { return false; }

  }; // class circle

  static circle const NaN_circle = circle(acme::NaN, acme::NaN_plane); //!< Not-a-Number circle type
  static circle circle_goat = circle(NaN_circle);                      //!< Scapegoat circle type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_circle.hh
///