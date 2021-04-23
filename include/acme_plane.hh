/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project - Release Version 0.0.0                            *)
(*                                                                     *)
(* Copyright (c) 2020 Davide Stocco, All Rights Reserved.              *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 2-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 2-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
(*                                                                     *)
(*    Davide Stocco                                                    *)
(*    University of Trento                                             *)
(*    Department of Industrial Engineering                             *)
(*    davide.stocco@unitn.it                                           *)
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
    isApprox(
        plane const &input //!< Input plane object
    ) const;

    //! Check if plane is degenerated (normal has zero norm)
    bool
    isDegenerated(void) const;

    //! Return plane origin point
    vec3 const &
    origin(void) const;

    //! Return plane normal vector
    vec3 const &
    normal(void) const;

    //! Normalize plane normal vector
    void
    normalize(void);

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

    //! Rotate plane by matrix
    void
    rotate(
        mat3 const &input //!< Input 3x3 rotation matrix
    );

    //! Transform plane from with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
    );

    //! Reverse plane normal vector
    void
    reverse(void);

    //! Return plane equation d value (ax + by + cz + d = 0)
    real_type
    d(void) const;

    //! Distance between point and plane
    real_type
    distance(
        vec3 const &input //!< Input
    ) const;

    //! Squared distance between point and plane
    real_type
    squaredDistance(
        vec3 const &input //!< Input
    ) const;

    //! Signed distance between point and plane
    real_type
    signedDistance(
        vec3 const &input //!< Input
    ) const;

    // Check whether a point lays on the plane
    bool
    isInside(
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