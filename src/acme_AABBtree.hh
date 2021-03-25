/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(* Release Version 0.0.0                                               *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The acme computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the acme computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
(*  Source: G1 and G2 fitting with clothoids, spline of clothods,      *)
(*          circles arc and biarcs.                                    *)
(*  GitHub: https://github.com/ebertolazzi/Clothoids                   *)
(*                                                                     *)
(*  Copyright (C) 2017-2021                                            *)
(*                                                                     *)
(*         , __                 , __                                   *)
(*        /|/  \               /|/  \                                  *)
(*         | __/ _   ,_         | __/ _   ,_                           *) 
(*         |   \|/  /  |  |   | |   \|/  /  |  |   |                   *)
(*         |(__/|__/   |_/ \_/|/|(__/|__/   |_/ \_/|/                  *)
(*                           /|                   /|                   *)
(*                           \|                   \|                   *)
(*                                                                     *)
(*      Enrico Bertolazzi                                              *)
(*      Dipartimento di Ingegneria Industriale                         *)
(*      Università degli Studi di Trento                               *)
(*      Via Sommarive 9, I-38123 Povo, Trento, Italy                   *)
(*      email: enrico.bertolazzi@unitn.it                              *)
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

  //! Class to manage AABB tree
  /*!
  Axis-Aligned Bouding Box tree.
  */
  class AABBtree
  {
  public:
#ifdef ACME_USE_CXX11
    typedef shared_ptr<box const> boxPtr; //!< Shared pointer to box;;
    typedef shared_ptr<AABBtree> PtrAABB; //!< Shared pointer to tree
#else
    typedef box const *boxPtr; //!< Pointer to box
    typedef AABBtree *PtrAABB; //!< Pointer to tree
#endif

    typedef std::pair<boxPtr, boxPtr> boxPtrPair;  //!< Pair of box
    typedef std::vector<boxPtr> boxPtrVec;         //!< Vector of pointers to box
    typedef std::vector<boxPtrPair> boxPtrPairVec; //!< Vector of pointers to pair of box

  private:
    boxPtr ptrbox; //!< Pointer to box of tree
    std::vector<PtrAABB> children;

    AABBtree(AABBtree const &tree);

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
        vec3 const &point,       //!< Input point
        real_type distance,      //!< Input distance
        AABBtree const &tree,    //!< Input tree
        boxPtrVec &candidateList //!< Output candidate list
    );

  public:
    //! Class destructor
    ~AABBtree();

    //! Class constructor
    AABBtree();

    //! Initialize tree
    void clear(void);

    //! Check if AABB tree is empty
    bool is_empty(void) const;

    //! Build AABB tree given a list of boxes
    void
    build(
        std::vector<boxPtr> const &boxes //!< List of boxes
    );

    //! Print AABB tree content
    void
    print(
        ostream_type &stream, //!< Output stream
        int level = 0         //!< Level to print
    ) const;

    //! Check if two AABB tree collide
    template <typename COLLISION_FUNCTION>
    bool
    collision(
        AABBtree const &tree,   //!< AABB tree used to check collision
        COLLISION_FUNCTION fun, //!< Function to check if the contents of two box collide
        bool swap_tree = false  //!< If true exchange the tree in computation
    ) const
    {

      // check box with
      if (!tree.ptrbox->collision(*ptrbox))
        return false;

      int icase = (children.empty() ? 0 : 1) +
                  (tree.children.empty() ? 0 : 2);

      switch (icase)
      {
      case 0: // both leaf, use GeomPrimitive intersection algorithm
        if (swap_tree)
          return fun(tree.ptrbox, ptrbox);
        else
          return fun(ptrbox, tree.ptrbox);
      case 1: // first is a tree, second is a leaf
      {
        typename std::vector<PtrAABB>::const_iterator it;
        for (it = children.begin(); it != children.end(); ++it)
          if (tree.collision(**it, fun, !swap_tree))
            return true;
      }
      break;
      case 2: // first leaf, second is a tree
      {
        typename std::vector<PtrAABB>::const_iterator it;
        for (it = tree.children.begin();
             it != tree.children.end(); ++it)
          if (this->collision(**it, fun, swap_tree))
            return true;
      }
      break;
      case 3: // first is a tree, second is a tree
      {
        typename std::vector<PtrAABB>::const_iterator it1;
        typename std::vector<PtrAABB>::const_iterator it2;
        for (it1 = children.begin(); it1 != children.end(); ++it1)
          for (it2 = tree.children.begin();
               it2 != tree.children.end(); ++it2)
            if ((*it1)->collision(**it2, fun, swap_tree))
              return true;
      }
      break;
      }
      return false;
    }

    //! Compute all the intersection of AABB trees
    void
    intersect(
        AABBtree const &tree,            //!< AABB tree used to check collision
        boxPtrPairVec &intersectionList, //!< List of pair box that overlaps
        bool swap_tree = false           //!< If true exchange the tree in computation
    ) const;

    //! Find the candidate at minimum distance from point
    void
    min_distance(
        vec3 const &point,       //!< Input point
        boxPtrVec &candidateList //!< Output candidate list
    ) const;

  }; // class AABBtree

} // namespace acme

///
/// eof: acme_AABBtree.hh
///