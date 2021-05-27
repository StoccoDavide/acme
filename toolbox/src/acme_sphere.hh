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
/// file: acme_sphere.hh
///

#ifndef INCLUDE_ACME_SPHERE
#define INCLUDE_ACME_SPHERE

#include "acme.hh"
#include "acme_aabb.hh"
#include "acme_point.hh"

namespace acme
{

  /*\
   |             _                   
   |   ___ _ __ | |__   ___ _ __ ___ 
   |  / __| '_ \| '_ \ / _ \ '__/ _ \
   |  \__ \ |_) | | | |  __/ | |  __/
   |  |___/ .__/|_| |_|\___|_|  \___|
   |      |_|                        
  \*/

  //! Sphere class container
  /**
   * Sphere in 3D space and defined by a radius and a plane (sphere center + normal vector).
  */
  class sphere : public entity
  {
  private:
    real m_radius;  //!< Sphere radius
    point m_center; //!< Sphere center point

  public:
    //! Sphere class deconstructor
    ~sphere() {}

    //! Sphere class constructor
    sphere() {}

    //! Sphere copy constructor
    sphere(sphere const &) = default;

    //! Sphere move constructor
    sphere(sphere &&) = default;

    //! Sphere class constructor
    sphere(
        real radius,   //!< Input sphere radius
        real center_x, //!< Input sphere center x value
        real center_y, //!< Input sphere center y value
        real center_z  //!< Input sphere center z value
        )
        : m_radius(radius),
          m_center(center_x, center_y, center_z)
    {
    }

    //! Sphere class constructor
    sphere(
        real radius,        //!< Input sphere radius
        point const &center //!< Input sphere center
        )
        : m_radius(radius),
          m_center(center)
    {
    }

    //! Equality operator
    sphere &
    operator=(
        sphere const &sphere_in //!< Input sphere object
    );

    //! Check if circles are (almost) equal
    bool
    isApprox(
        sphere const &sphere_in, //!< Input sphere object
        real tolerance = EPSILON //!< Tolerance
    ) const;

    //! Get sphere radius const reference
    real const &
    radius(void) const;

    //! Get sphere radius reference
    real &
    radius(void);

    //! Get sphere center point const reference
    point const &
    center(void) const;

    //! Get sphere center point reference
    point &
    center(void);

    //! Get minumum cubic aabb containing the current sphere object
    void
    clamp(
        aabb &aabb_in //!< Input aabb object
    ) const;

    //! Calculate sphere area
    real
    area(void) const;

    //! Calculate sphere volume
    real
    volume(void) const;

    //! Translate by vector
    void
    translate(
        vec3 const &vector_in //!< Input translation vector
        ) override;

    //! Transform sphere with affine transformation matrix
    void
    transform(
        affine const &affine_in //!< 4x4 affine transformation matrix
        ) override;

    // Check whether the point is inside the sphere
    bool
    isInside(
        point const &point_in,   //!< Query point
        real tolerance = EPSILON //!< Tolerance
    ) const;

    //! Check if sphere is degenerated
    bool
    isDegenerated(
        real tolerance = EPSILON //!< Tolerance
    ) const override;

    //! Return object hierarchical level
    integer level(void) const override { return 9; }

    //! Return object type as string
    std::string type(void) const override { return "sphere"; }

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

    //! Check whether the object is a sphere
    bool isSphere(void) const override { return true; }

  }; // class sphere

  static sphere const NAN_SPHERE = sphere(QUIET_NAN, NAN_POINT); //!< Not-a-Number static const sphere object
  static sphere THROWAWAY_SPHERE = sphere(NAN_SPHERE);           //!< Throwaway static non-const sphere object

} // namespace acme

#endif

///
/// eof: acme_circle.hh
///