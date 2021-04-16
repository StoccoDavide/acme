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
(*                                                                     *)
(*  Source: G1 and G2 fitting with clothoids, spline of clothods,      *)
(*          circles arc and biarcs.                                    *)
(*  GitHub: https://github.com/ebertolazzi/Clothoids                   *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_AABBtree.hh
///

#include "acme.hh"
#include "acme_math.hh"
#include "acme_box.hh"

namespace acme
{

  /*\
   |      _        _    ____  ____  _
   |     / \      / \  | __ )| __ )| |_ _ __ ___  ___
   |    / _ \    / _ \ |  _ \|  _ \| __| '__/ _ \/ _ \
   |   / ___ \  / ___ \| |_) | |_) | |_| | |  __/  __/
   |  /_/   \_\/_/   \_\____/|____/ \__|_|  \___|\___|
  \*/

  /**
   * Axis-Aligned Bouding Box tree.
  */
  class AABBtree
  {
  public:
#ifdef ACME_USE_CXX11
    typedef shared_ptr<AABBtree> ptr; //!< Shared pointer to AABB tree object
#else
    typedef AABBtree *ptr; //!< Pointer to AABB tree object
#endif

  private:
    box::ptr ptrbox; //!< Pointer to AABB tree box
    std::vector<AABBtree::ptr> children;

    AABBtree(AABBtree const &tree);

  public:
    //! AABB tree class destructor
    ~AABBtree();

    //! AABB tree class constructor
    AABBtree();

    //! Clear AABB tree data
    void clear(void);

    //! Check if AABB tree is empty
    bool is_empty(void) const;

    //! Build AABB tree given a list of boxes
    void
    build(
        std::vector<box::ptr> const &boxes //!< List of boxes
    );

    //! Print AABB tree content
    void
    print(
        ostream_type &stream, //!< Output stream
        int level = 0         //!< Level to print
    ) const;

    //! Check if two AABB tree collide
    template <typename collision>
    bool
    collision(
        AABBtree const &tree,  //!< AABB tree used to check collision
        collision function,    //!< Function to check if the contents of two box collide
        bool swap_tree = false //!< If true exchange the tree in computation
    ) const
    {

      // check box with
      if (!tree.ptrbox->collision(*ptrbox))
        return false;

      int icase = (children.empty() ? 0 : 1) +
                  (tree.children.empty() ? 0 : 2);

      switch (icase)
      {
      case 0: // both leaf, use box intersection algorithm
        if (swap_tree)
          return function(tree.ptrbox, ptrbox);
        else
          return function(ptrbox, tree.ptrbox);
      case 1: // first is a tree, second is a leaf
      {
        typename std::vector<AABBtree::ptr>::const_iterator it;
        for (it = children.begin(); it != children.end(); ++it)
          if (tree.collision(**it, function, !swap_tree))
            return true;
      }
      break;
      case 2: // first leaf, second is a tree
      {
        typename std::vector<AABBtree::ptr>::const_iterator it;
        for (it = tree.children.begin();
             it != tree.children.end(); ++it)
          if (this->collision(**it, function, swap_tree))
            return true;
      }
      break;
      case 3: // first is a tree, second is a tree
      {
        typename std::vector<AABBtree::ptr>::const_iterator it1;
        typename std::vector<AABBtree::ptr>::const_iterator it2;
        for (it1 = children.begin(); it1 != children.end(); ++it1)
          for (it2 = tree.children.begin();
               it2 != tree.children.end(); ++it2)
            if ((*it1)->collision(**it2, function, swap_tree))
              return true;
      }
      break;
      }
      return false;
    }

    //! Compute all the intersection of AABB trees
    void
    intersect(
        AABBtree const &tree,              //!< AABB tree used to check collision
        box::vecpairptr &intersectionList, //!< List of pair box that overlaps
        bool swap_tree = false             //!< If true exchange the tree in computation
    ) const;

    //! Find the candidate at minimum distance from point
    void min_distance(
        vec3 const &point,         //!< Input point
        box::vecptr &candidateList //!< Output candidate list
    ) const;

  private:
    //! Compute the minimum of the maximum distance between a point
    static real_type
    min_maxdist(
        vec3 const &point,    //!< Input point
        AABBtree const &tree, //!< Input tree
        real_type distance    //!< Output distance
    );

    //! Select the candidate which box have distance less than distance
    static void
    min_maxdist_select(
        vec3 const &point,         //!< Input point
        real_type distance,        //!< Input distance
        AABBtree const &tree,      //!< Input tree
        box::vecptr &candidateList //!< Output candidate list
    );

  }; // class AABBtree

} // namespace acme

///
/// eof: acme_AABBtree.hh
///