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
/// file: acme_entity.hh
///

#ifndef INCLUDE_ACME_ENTITY
#define INCLUDE_ACME_ENTITY

#include "acme.hh"

namespace acme
{

  /*\
   |              _   _ _         
   |    ___ _ __ | |_(_) |_ _   _ 
   |   / _ \ '_ \| __| | __| | | |
   |  |  __/ | | | |_| | |_| |_| |
   |   \___|_| |_|\__|_|\__|\__, |
   |                        |___/ 
  \*/

  //! Geometrical entity class container
  /**
   * Geometrical entity in 3D space.
   */
  class entity
  {
  public:
    typedef std::shared_ptr<entity const> ptr; //!< Shared pointer to geometrical entity
    typedef std::pair<ptr, ptr> pairptr;       //!< Pair of pointers to geometrical entity objects
    typedef std::vector<ptr> vecptr;           //!< Vector of pointers to geometrical entity objects
    typedef std::vector<pairptr> vecpairptr;   //!< Vector of pairs of pointers to geometrical entity objects

  protected:
    // The problem that a virtual destructor is designed to avoid is this:
    // If you call the non.virtual destructor through a pointer or reference
    // to base class, only the base class destructor is called, even if the
    // object is of a derived class.
    // SOLUTION: virtual destructor must be protected!
    
  public:

    //! Entity class destructor
    virtual ~entity(){};
    //! Entity class destructor
    entity(){};

    //! Return object hierarchical degree
    virtual size_t degree(void) const = 0;

    //! Return object type as string
    virtual std::string whattype(void) const = 0;

    //! Check whether the object is no entity
    virtual bool isNone(void) const = 0;

    //! Check whether the object is a matrix
    virtual bool isMatrix(void) const = 0;

    //! Check whether the object is a vector
    virtual bool isVector(void) const = 0;

    //! Check whether the object is a line
    virtual bool isLine(void) const = 0;

    //! Check whether the object is a ray
    virtual bool isRay(void) const = 0;

    //! Check whether the object is a plane
    virtual bool isPlane(void) const = 0;

    //! Check whether the object is a segment
    virtual bool isSegment(void) const = 0;

    //! Check whether the object is a triangle
    virtual bool isTriangle(void) const = 0;

    //! Check whether the object is a circle
    virtual bool isCircle(void) const = 0;

    //! Check whether the object is a box
    virtual bool isBox(void) const = 0;

  }; // class entity

  static entity::ptr entity_goat = std::shared_ptr<entity>(); //!< Scapegoat entity type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_line.hh
///