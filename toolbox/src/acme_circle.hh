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
#include "acme_aabb.hh"
#include "acme_plane.hh"
#include "acme_point.hh"

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
  private:
    real m_radius; //!< Circle radius
    plane m_plane; //!< Circle plane (circle center + normal vector)

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
        )
        : m_radius(radius),
          m_plane(plane)
    {
    }

    //! Circle class constructor
    circle(
        real radius,         //!< Input circle radius
        point const &center, //!< Input circle center
        vec3 const &normal   //!< Input circle normal to the laying plane
        )
        : m_radius(radius),
          m_plane(center, normal)
    {
    }

    //! Circle class constructor
    circle(
        real radius,   //!< Input circle radius
        real center_x, //!< Input circle center x value
        real center_y, //!< Input circle center y value
        real center_z, //!< Input circle center z value
        real normal_x, //!< Input circle normal x value to the laying plane
        real normal_y, //!< Input circle normal y value to the laying plane
        real normal_z  //!< Input circle normal z value to the laying plane
        )
        : m_radius(radius),
          m_plane(center_x, center_y, center_z,
                  normal_x, normal_y, normal_z)
    {
    }

    //! Equality operator
    circle &
    operator=(
        circle const &circle_in //!< Input circle object
    );

    //! Check if circles are (almost) equal
    bool
    isApprox(
        circle const &circle_in, //!< Input circle object
        real tolerance = EPSILON //!< Tolerance
    ) const;

    //! Get circle radius const reference
    real const &
    radius(void) const;

    //! Get circle radius reference
    real &
    radius(void);

    //! Get circle center point const reference
    point const &
    center(void) const;

    //! Get circle center point reference
    point &
    center(void);

    //! Get circle laying plane normal vector const reference
    vec3 const &
    normal(void) const;

    //! Get circle laying plane normal vector reference
    vec3 &
    normal(void);

    //! Get cicle laying plane const reference
    plane const &
    layingPlane(void) const;

    //! Get cicle laying plane reference
    plane &
    layingPlane(void);

    //! Normalize circle normal vector
    void
    normalize(void);

    //! Reverse circle normal vector
    void
    reverse(void);

    //! Get minumum cubic aabb containing the current circle object
    void
    clamp(
        aabb &aabb_in //!< Input aabb object
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
        vec3 const &vector_in //!< Input translation vector
        ) override;

    //! Transform circle with affine transformation matrix
    void
    transform(
        affine const &affine_in //!< 4x4 affine transformation matrix
        ) override;

    // Check whether the point is inside the circle
    bool
    isInside(
        point const &point_in,   //!< Query point
        real tolerance = EPSILON //!< Tolerance
    ) const;

    //! Check if circle is degenerated
    bool
    isDegenerated(
        real tolerance = EPSILON //!< Tolerance
    ) const override;

    //! Return object hierarchical level
    integer level(void) const override { return 8; }

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

    //! Check whether the object is a sphere
    bool isSphere(void) const override { return false; }

  }; // class circle

  static circle const NAN_CIRCLE = circle(QUIET_NAN, NAN_PLANE); //!< Not-a-Number static const circle object
  static circle THROWAWAY_CIRCLE = circle(NAN_CIRCLE);           //!< Throwaway static non-const circle object

} // namespace acme

#endif

///
/// eof: acme_circle.hh
///