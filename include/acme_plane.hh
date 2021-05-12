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
/// file: acme_plane.hh
///

#ifndef INCLUDE_ACME_PLANE
#define INCLUDE_ACME_PLANE

#include "acme.hh"
#include "acme_point.hh"

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
  class plane : public entity
  {
  public:
    typedef std::shared_ptr<plane const> ptr; //!< Shared pointer to plane object
    typedef std::pair<ptr, ptr> pairptr;      //!< Pair of pointers to plane objects
    typedef std::vector<ptr> vecptr;          //!< Vector of pointers to plane objects
    typedef std::vector<pairptr> vecpairptr;  //!< Vector of pairs of pointers to plane objects

  private:
    point _origin; //!< Plane origin point
    vec3 _normal;  //!< Plane normal vector

  public:
    //! Plane class destructor
    ~plane() {}

    //! Plane class constructor
    plane() {}

    //! Plane copy constructor
    plane(plane const &) = default;

    //! Plane move constructor
    plane(plane &&) = default;

    //! Plane class constructor for plane
    plane(
        real ox, //<! Input x value of plane origin point
        real oy, //<! Input y value of plane origin point
        real oz, //<! Input z value of plane origin point
        real dx, //<! Input x value of plane normal vector
        real dy, //<! Input y value of plane normal vector
        real dz  //<! Input z value of plane normal vector
        ) : _origin(point(ox, oy, oz)),
            _normal(vec3(dx, dy, dz))
    {
    }

    //! Plane class constructor
    plane(
        point const &origin, //!< Input plane origin point
        vec3 const &normal   //!< Input plane normal vector
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
        plane const &input,      //!< Input plane object
        real tolerance = Epsilon //!< Tolerance
    ) const;

    //! Return plane origin point
    point const &
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
        point const &input //!< input plane origin point
    );

    //! Set plane normal
    void
    normal(
        vec3 const &input //!< input plane origin vector
    );

    //! Return plane equation d value (ax + by + cz + d = 0)
    real
    d(void) const;

    //! Distance between point and plane
    real
    distance(
        point const &input //!< Input
    ) const;

    //! Squared distance between point and plane
    real
    squaredDistance(
        point const &input //!< Input
    ) const;

    //! Signed distance between point and plane
    real
    signedDistance(
        point const &input //!< Input
    ) const;

    //! Reverse plane normal vector
    void
    reverse(void);

    //! Translate plane by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
        ) override;

    //! Transform plane from with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
        ) override;

    // Check whether a point lays on the plane
    bool
    isInside(
        point const &query_point, //!< Query point
        real tolerance = Epsilon  //!< Tolerance
    ) const;

    //! Check if plane is degenerated (normal has zero norm)
    bool
    isDegenerated(
        real tolerance = Epsilon //!< Tolerance
    ) const override;

    //! Return object hierarchical degree
    integer degree(void) const override { return 5; }

    //! Return object type as string
    std::string type(void) const override { return "plane"; }

    //! Check whether the object is no entity
    bool isNone(void) const override { return false; }

    //! Check whether the object is a point
    bool isPoint(void) const override { return false; }

    //! Check whether the object is a line
    bool isLine(void) const override { return false; }

    //! Check whether the object is a ray
    bool isRay(void) const override { return false; }

    //! Check whether the object is a plane
    bool isPlane(void) const override { return true; }

    //! Check whether the object is a segment
    bool isSegment(void) const override { return false; }

    //! Check whether the object is a triangle
    bool isTriangle(void) const override { return false; }

    //! Check whether the object is a circle
    bool isCircle(void) const override { return false; }

    //! Check whether the object is a aabb
    bool isBox(void) const override { return false; }

  }; // class plane

  static plane const NaN_plane = plane(acme::NaN_point, acme::NaN_vec3); //!< Not-a-Number plane type
  static plane plane_goat = plane(NaN_plane);                            //!< Scapegoat plane type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_plane.hh
///