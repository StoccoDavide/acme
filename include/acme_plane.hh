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
/// file: acme_plane.hh
///

#ifndef INCLUDE_ACME_PLANE
#define INCLUDE_ACME_PLANE

#include "acme.hh"
#include "acme_math.hh"
#include "acme_frame.hh"

namespace acme
{

  /*\
   |         _                  
   |   _ __ | | __ _ _ __   ___ 
   |  | '_ \| |/ _` | '_ \ / _ \
   |  | |_) | | (_| | | | |  __/
   |  | .__/|_|\__,_|_| |_|\___|
   |  |_|                       
  \*/

  //! Plane class container
  /**
   * 3D plane defined by the normal vector to plane and an arbitraty point laying on the plane.
   */
  class plane
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<plane const> ptr; //!< Shared pointer to plane object
#else
    typedef plane const *ptr; //!< Pointer to plane object
#endif

    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to plane objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to plane objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to plane objects

  private:
    vec3 _origin; //!< Plane origin vector
    vec3 _normal; //!< Plane normal vector

  public:
    //! Plane class destructor
    ~plane() {}

    //! Plane class constructor
    plane() {}

    //! Plane copy constructor
    plane(plane const &) = default;

    //! Plane class constructor for plane
    plane(
        real_type ox, //<! Input x value of plane origin point
        real_type oy, //<! Input y value of plane origin point
        real_type oz, //<! Input z value of plane origin point
        real_type dx, //<! Input x value of plane normal vector
        real_type dy, //<! Input y value of plane normal vector
        real_type dz  //<! Input z value of plane normal vector
        ) : _origin(vec3(ox, oy, oz)),
            _normal(vec3(dx, dy, dz))
    {
    }

    //! Plane class constructor
    plane(
        vec3 const &origin, //!< Input plane origin point
        vec3 const &normal  //!< Input plane normal vector
        ) : _origin(origin),
            _normal(normal)
    {
    }

    //! Equality operator
    plane &
    operator=(
        plane const &input //!< Input plane object
    );

    //! Check if objects are (almost) equal
    bool
    is_equal(
        plane const &input //!< Input plane object
    ) const;

    //! Check if plane is degenerated (normal has zero norm)
    bool
    is_degenerated(void) const;

    //! Return plane origin point
    vec3 const &
    origin(void) const;

    //! Return plane normal vector
    vec3 const &
    normal(void) const;

    //! Normalize plane normal vector
    void
    normalize_normal(void);

    //! Set plane origin point
    void
    origin(
        vec3 const &input //!< input plane origin point
    );

    //! Set plane normal
    void
    normal(
        vec3 const &input //!< input plane origin vector
    );

    //! Translate plane by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Get translated plane by vector
    plane
    translated(
        vec3 const &input //!< Input translation vector
    ) const;

    //! Rotate plane by matrix
    void
    rotate(
        mat3 const &input //!< Input 3x3 rotation matrix
    );

    //! Get rotated plane by matrix
    plane
    rotated(
        mat3 const &input //!< Input 3x3 rotation matrix
    ) const;

    //! Transform plane from two coordinate frames
    void
    transform(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    );

    //! Get transform plane from two coordinate frames
    plane
    transformed(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    ) const;

    //! Reverse plane normal vector
    void
    reverse(void);

    //! Get plane wirh reversed ray direction
    plane
    reversed(void) const;

    //! Return plane equation d value (ax + by + cz + d = 0)
    real_type
    d(void) const;

    //! Distance between point and plane
    real_type
    distance(
        vec3 const &input //!< Input
    ) const;

    // Check whether a point lays on the plane
    bool
    is_inside(
        vec3 const &point //!< Input
    ) const;

  }; // class plane

  static plane const NaN_plane = plane(acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number plane type
  static plane const plane_goat = plane(NaN_plane);                     //!< Scapegoat plane type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_plane.hh
///