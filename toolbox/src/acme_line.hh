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
public:
    typedef std::shared_ptr<line const> ptr; //!< Shared pointer to line
    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to line objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to line objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to line objects

private:
    point _origin;   //!< Origin point
    vec3 _direction; //!< Direction vector

public:
    //! Line class destructor
    ~line() {}

    //! Line class constructor
    line() {}

    //! Line copy constructor
    line(line const &) = default;

    //! Line move constructor
    line(line &&) = default;

    //! Line class constructor for line
    line(
        real ox, //<! Input x value of line origin point
        real oy, //<! Input y value of line origin point
        real oz, //<! Input z value of line origin point
        real dx, //<! Input x value of line direction vector
        real dy, //<! Input y value of line direction vector
        real dz  //<! Input z value of line direction vector
        ) : _origin(point(ox, oy, oz)),
            _direction(vec3(dx, dy, dz))
    {
    }

    //! Line class constructor
    line(
        point const &origin,  //!< Input line origin point
        vec3 const &direction //!< Input line direction vector
        ) : _origin(origin),
            _direction(direction)
    {
    }

    //! Equality operator
    line &
    operator=(
        line const &input //!< Input line object
    );

    //! Check if objects are (almost) equal
    bool
    isApprox(
        line const &input //!< Input line object
    ) const;

    //! Return line origin point
    point const &
    origin(void) const;

    //! Return line direction vector
    vec3 const &
    direction(void) const;

    //! Set line origin point
    void
    origin(
        point const &input //!< input line origin point
    );

    //! Set line direction vector
    void
    direction(
        vec3 const &input //!< input line direction vector
    );

    //! Normalize line direction vector
    void
    normalize(void);

    //! Convert line to vector
    vec3
    toVector(void) const;

    //! Convert line to normalized vector
    vec3
    toNormalizedVector(void) const;

    //! Reverse line direction
    void
    reverse(void);

    //! Translate line by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
        ) override;

    //! Transform line with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
        ) override;

    // Check whether the point is inside the line
    bool
    isInside(
        point const &query_point //!< Query point
    ) const;

    //! Check if line is degenerated (direction vector has zero norm)
    bool
    isDegenerated(void) const override;

    //! Return object hierarchical degree
    integer degree(void) const override { return 3; }

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

    //! Check whether the object is a aabb
    bool isAabb(void) const override { return false; }

  }; // class line

  static line const NaN_line = line(acme::NaN_point, acme::NaN_vec3); //!< Not-a-Number line type
  static line line_goat = line(NaN_line);                             //!< Scapegoat line type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_line.hh
///