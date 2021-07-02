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
/// file: acme_line.hh
///

#ifndef INCLUDE_ACME_LINE
#define INCLUDE_ACME_LINE

#include "acme.hh"
#include "acme_point.hh"

namespace acme
{

  /*\
   |   _ _            
   |  | (_)_ __   ___ 
   |  | | | '_ \ / _ \
   |  | | | | | |  __/
   |  |_|_|_| |_|\___|
   |                  
  \*/

  //! Line class container
  /**
   * Infinite line in 3D space and defined by any point lying on the line and a direction
   * vector.
   */
  class line : public entity
  {
  private:
    point m_origin;   //!< Origin point
    vec3 m_direction; //!< Direction vector

  public:
    //! Line class destructor
    ~line() {}

    //! Line class constructor
    line() {}

    //! Line copy constructor
    line(line const &) = default;

    //! Line move constructor
    line(line &&) = default;

    //! Line class constructor
    line(
        real ox, //!< Input x value of line origin point
        real oy, //!< Input y value of line origin point
        real oz, //!< Input z value of line origin point
        real dx, //!< Input x value of line direction vector
        real dy, //!< Input y value of line direction vector
        real dz  //!< Input z value of line direction vector
    );

    //! Line class constructor
    line(
        point const &origin,  //!< Input line origin point
        vec3 const &direction //!< Input line direction vector
    );

    //! Equality operator
    line &
    operator=(
        line const &line_in //!< Input line object
    );

    //! Check if objects are (almost) equal
    bool
    isApprox(
        line const &line_in,     //!< Input line object
        real tolerance = EPSILON //!< Tolerance
    ) const;

    //! Return line origin point const reference
    point const &
    origin(void) const;

    //! Return line origin point reference
    point &
    origin(void);

    //! Return line direction vector const reference
    vec3 const &
    direction(void) const;

    //! Return line direction vector reference
    vec3 &
    direction(void);

    //! Normalize line direction vector
    void
    normalize(void);

    //! Convert line to vector
    vec3
    toVector(void) const;

    //! Convert line to normalized vector
    vec3
    toUnitVector(void) const;

    //! Reverse line direction
    void
    reverse(void);

    //! Translate line by vector
    void
    translate(
        vec3 const &vector_in //!< Input translation vector
        ) override;

    //! Transform line with affine transformation matrix
    void
    transform(
        affine const &affine_in //!< 4x4 affine transformation matrix
        ) override;

    // Check whether the point is inside the line
    bool
    isInside(
        point const &point_in,   //!< Query point
        real tolerance = EPSILON //!< Tolerance
    ) const;

    //! Check if line is degenerated (direction vector has zero norm)
    bool
    isDegenerated(
        real tolerance = EPSILON //!< Tolerance
    ) const override;

    //! Return object hierarchical level
    integer level(void) const override { return 3; }

    //! Return object type as string
    std::string type(void) const override { return "line"; }

    //! Check whether the object is no entity
    bool isNone(void) const override { return false; }

    //! Check whether the object is a point
    bool isPoint(void) const override { return false; }

    //! Check whether the object is a line
    bool isLine(void) const override { return true; }

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
    bool isSphere(void) const override { return false; }

    //! Check whether in the line is clampable
    bool isClampable(void) const override { return false; }

    //! Check whether in the line is non-clampable
    bool isNonClampable(void) const override { return true; }

  }; // class line

  static line const NAN_LINE = line(NAN_POINT, NAN_VEC3); //!< Not-a-Number static const line object
  static line THROWAWAY_LINE = line(NAN_LINE);            //!< Throwaway static non-const line object

} // namespace acme

#endif

///
/// eof: acme_line.hh
///