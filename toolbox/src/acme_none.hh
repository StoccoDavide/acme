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
/// file: acme_none.hh
///

#ifndef INCLUDE_ACME_NONE
#define INCLUDE_ACME_NONE

#include "acme.hh"
#include "acme_point.hh"

namespace acme
{

  /*\
   |                          
   |   _ __   ___  _ __   ___ 
   |  | '_ \ / _ \| '_ \ / _ \
   |  | | | | (_) | | | |  __/
   |  |_| |_|\___/|_| |_|\___|
   |                          
  \*/

  //! None class container
  /**
   * This cass represent a empty geometrical entity.
  */
  class none : public entity
  {
public:
    typedef std::shared_ptr<none const> ptr; //!< Shared pointer to none
    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to circle objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to circle objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to circle objects

    //! None class deconstructor
    ~none() {}

    //! None class constructor
    none() {}

    //! Translate entity by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
        ) override{};

    //! Transform entity with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
        ) override{};

    //! Check if entity is degenerated
    bool isDegenerated(void) const override { return true; };

    //! Return object hierarchical degree
    integer degree(void) const override { return 1; }

    //! Return object type as string
    std::string type(void) const override { return "none"; }

    //! Check whether the object is no entity
    bool isNone(void) const override { return true; }

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

    //! Check whether the object is a aabb
    bool isAabb(void) const override { return false; }

  }; // class none

  static none none_goat = none(); //!< Scapegoat one type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_none.hh
///