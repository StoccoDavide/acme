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
/// file: acme_line.hh
///

#ifndef INCLUDE_ACME_LINE
#define INCLUDE_ACME_LINE

#include "acme.hh"
#include "acme_math.hh"
#include "acme_plane.hh"
#include "acme_intersect.hh"

namespace acme
{

  class ray;
  class plane;
  class segment;
  class triangle;
  class box;
  class circle;
  class frame;

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
  class line
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<line const> ptr; //!< Shared pointer to line
#else
    typedef line const *ptr; //!< Pointer to line
#endif

    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to line objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to line objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to line objects

  private:
    vec3 _origin;    //!< Origin (point)
    vec3 _direction; //!< Direction (vector)

  public:
    //! Line class destructor
    ~line() {}

    //! Line class constructor
    line() {}

    //! Line copy constructor
    line(line const &) = default;

    //! Line class constructor for line
    line(
        real_type ox, //<! Input x value of line origin point
        real_type oy, //<! Input y value of line origin point
        real_type oz, //<! Input z value of line origin point
        real_type dx, //<! Input x value of line direction vector
        real_type dy, //<! Input y value of line direction vector
        real_type dz  //<! Input z value of line direction vector
        ) : _origin(vec3(ox, oy, oz)),
            _direction(vec3(dx, dy, dz))
    {
    }

    //! Line class constructor
    line(
        vec3 const &origin,   //!< Input line origin point
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
    is_equal(
        line const &input //!< Input line object
    ) const;

    //! Check if line is degenerated (direction vector has zero norm)
    bool
    is_degenerated(void) const;

    //! Return line origin point
    vec3 const &
    origin(void) const;

    //! Return line direction vector
    vec3 const &
    direction(void) const;

    //! Set line origin point
    void
    origin(
        vec3 const &input //!< input line origin point
    );

    //! Set line direction vector
    void
    direction(
        vec3 const &input //!< input line direction vector
    );

    //! Normalize line direction vector
    void
    normalize_direction(void);

    //! Convert line to vector
    vec3
    to_vector(void) const;

    //! Convert line to normalized vector
    vec3
    to_normalized_vector(void) const;

    //! Translate line by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Get translated line by vector
    line
    translated(
        vec3 const &input //!< Input translation vector
    ) const;

    //! Get rotated line by matrix
    void
    rotate(
        mat3 const &input //!< Input 3x3 rotation vector
    );

    //! Rotate line by matrix
    line
    rotated(
        mat3 const &input //!< Input 3x3 rotation vector
    ) const;

    //! Transform line from two coordinate frames
    void
    transform(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    );

    //! Get transformed line from two coordinate frames
    line
    transformed(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    ) const;

    //! Reverse line direction
    void
    reverse(void);

    //! Get ray with reversed direction
    line
    reversed(void) const;

    // Check whether the point is inside the line
    bool
    is_inside(
        vec3 const &point //!< Query point
    ) const;

    //! Intersect between two lines \n
    //! WARNING: This function does not support parallel objects!
    bool
    intersect(
        line const &line, //!< Input line
        vec3 &point       //!< Output point
    ) const;

    //! Intersect line with plane \n
    //! WARNING: This function does not support coplanarity!
    bool intersect(
        plane const &plane, //!< Input plane
        vec3 &point         //!< Output point
    ) const;

    //! Intersect line with triangle (no precalculated normal) \n
    //! WARNING: This function does not support coplanarity!
    bool
    intersect(
        triangle const &triangle, //!< Input triangle
        vec3 &point               //!< Output point
    ) const;

    //! Intersect line and circle \n
    //! WARNING: This function does not support coplanarity!
    bool
    intersect(
        circle const &circle, //!< Input circle
        vec3 &point           //!< Ouput point
    ) const;

    //! Intersection between line and segment \n
    //! WARNING: This function only support coplanar objects!
    bool
    intersect(
        segment const &segment_in, //!< Input segment
        segment &segment_out       //!< Output segment
    ) const;

    //! Intersect line with circle \n
    //! WARNING: This function only support coplanar objects!
    bool
    intersect(
        circle const &circle, //!< Input circle
        segment &segment      //!< Ouput segment
    ) const;

  }; // class line

  static line const NaN_line = line(acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number line type
  static line line_goat = line(NaN_line);                            //!< Scapegoat line type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_line.hh
///