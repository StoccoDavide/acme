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
/// file: acme_ray.hh
///

#ifndef INCLUDE_ACME_RAY
#define INCLUDE_ACME_RAY

#include "acme.hh"
#include "acme_eigen.hh"

namespace acme
{

  /*\
   |                   
   |   _ __ __ _ _   _ 
   |  | '__/ _` | | | |
   |  | | | (_| | |_| |
   |  |_|  \__,_|\__, |
   |             |___/ 
  \*/

  //! Ray class container
  /**
   * Infinite ray in 3D space and defined by any point lying on the line and a direction
   * vector.
  */
  class ray : public entity
  {
  public:
    typedef std::shared_ptr<ray const> ptr;  //!< Pointer to ray object
    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to ray objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to ray objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to ray objects

  private:
    vec3 _origin;    //!< Ray origin point
    vec3 _direction; //!< Ray direction vector

  public:
    //! Ray class destructor
    ~ray() {}

    //! Ray class constructor
    ray() {}

    //! Ray copy constructor
    ray(ray const &) = default;

    //! Ray move constructor
    ray(ray &&) = default;

    //! Ray class constructor
    ray(
        real_type ox, //<! Input x value of ray origin point
        real_type oy, //<! Input y value of ray origin point
        real_type oz, //<! Input z value of ray origin point
        real_type dx, //<! Input x value of ray direction
        real_type dy, //<! Input y value of ray direction
        real_type dz  //<! Input z value of ray direction
        ) : _origin(vec3(ox, oy, oz)),
            _direction(vec3(dx, dy, dz))
    {
    }

    //! Ray class constructor
    ray(
        vec3 const &origin,   //!< Input ray origin point
        vec3 const &direction //!< Input ray direction vector
        ) : _origin(origin),
            _direction(direction)
    {
    }

    //! Equality operator
    ray &
    operator=(
        ray const &input //!< Input ray object
    );

    //! Check if ray objects are (almost) equal
    bool
    isApprox(
        ray const &input //!< Input ray object
    ) const;

    //! Return ray origin point
    vec3 const &
    origin() const;

    //! Return ray direction vector
    vec3 const &
    direction() const;

    //! Set ray origin point
    void
    origin(
        vec3 const &input //!< input ray object
    );

    //! Set ray direction vector
    void
    direction(
        vec3 const &input //!< input ray object
    );

    //! Normalize ray direction vector
    void
    normalize(void);

    //! Convert ray to vector
    vec3
    toVector(void) const;

    //! Convert ray to normalized vector
    vec3
    toNormalizedVector(void) const;

    //! Reverse ray direction
    void
    reverse(void);

    //! Translate ray by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Transform ray with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
    );

    // Check whether the point is inside the ray
    bool
    isInside(
        vec3 const &point //!< Query point
    ) const;

    //! Check if ray is degenerated (null vector)
    bool
    isDegenerated(void) const;

    //! Return object hierarchical degree
    size_t degree(void) const override { return 4; }

    //! Return object type as string
    std::string whattype(void) const override { return "ray"; }

    //! Check whether the object is no entity
    bool isNone(void) const override { return false; }

    //! Check whether the object is a point
    bool isMatrix(void) const override { return false; }

    //! Check whether the object is a vector
    bool isVector(void) const override { return false; }

    //! Check whether the object is a line
    bool isLine(void) const override { return false; }

    //! Check whether the object is a ray
    bool isRay(void) const override { return true; }

    //! Check whether the object is a plane
    bool isPlane(void) const override { return false; }

    //! Check whether the object is a segment
    bool isSegment(void) const override { return false; }

    //! Check whether the object is a triangle
    bool isTriangle(void) const override { return false; }

    //! Check whether the object is a circle
    bool isCircle(void) const override { return false; }

    //! Check whether the object is a box
    bool isBox(void) const override { return false; }

  }; // class ray

  static ray const NaN_ray = ray(acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number ray type
  static ray ray_goat = ray(NaN_ray);                             //!< Scapegoat ray type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_ray.hh
///