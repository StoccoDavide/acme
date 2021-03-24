///
/// file: acme_AABBtree.hh
///

/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
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
*/

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


  //! Most part of the code is inspired from: \n
  //! Source: G1 and G2 fitting with clothoids, spline of clothods, circle arc and biarc. \n
  //! GitHub: https://github.com/ebertolazzi/Clothoids\n
  //! Authors: Paolo Bevilacqua & Enrico Bertolazzi & Marco Frego (University of Trento) \n

  //! Class to manage AABB tree.
  class AABBtree
  {
  public:
#ifdef ACME_USE_CXX11
    typedef shared_ptr<box const> boxPtr;
    typedef shared_ptr<AABBtree> PtrAABB;
#else
    typedef box const *boxPtr;
    typedef AABBtree *PtrAABB;
#endif

    typedef std::pair<boxPtr, boxPtr> boxPtrPair;
    typedef std::vector<boxPtr> boxPtrVec;
    typedef std::vector<boxPtrPair> boxPtrPairVec;

  private:
    // box of the tree
    boxPtr ptrbox;
    std::vector<PtrAABB> children;

    AABBtree(AABBtree const &tree);

    //! Compute the minimum of the maximum distance between a point
    static real_type
    min_maxdist(
        const vector &point,
        AABBtree const &tree,
        real_type mmDist);

    //!  Select the candidate which box have distance less than mmDist
    static void
    min_maxdist_select(
        const vector &point,
        real_type mmDist,
        AABBtree const &tree,
        boxPtrVec &candidateList);

  public:
    AABBtree();
    ~AABBtree();

    void clear(); //!< initialized AABB tree

    bool empty() const; //!< check if AABB tree is empty

    //! build AABB tree given a list of box
    void
    build(std::vector<boxPtr> const &boxes);

    void
    print(std::ostream &stream, int level = 0) const;

    /*!
     * Check if two AABB tree collide
     *
     * \param[in] tree      an AABB tree that is used to check collision
     * \param[in] fun      function the check if the contents of two box (curve) collide
     * \param[in] swap_tree if true exchange the tree in computation
     * \return true if the two tree collides
     *
     */
    template <typename COLLISION_FUNCTION>
    bool
    collision(
        AABBtree const &tree,
        COLLISION_FUNCTION fun,
        bool swap_tree = false) const
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

    /*!
     * Compute all the intersection of AABB trees
     *
     * \param[in]  tree             an AABB tree that is used to check collision
     * \param[out] intersectionList list of pair box that overlaps
     * \param[in]  swap_tree        if true exchange the tree in computation
     *
     */

    void
    intersect(
        AABBtree const &tree,
        boxPtrPairVec &intersectionList,
        bool swap_tree = false) const;

    void
    min_distance(
        const vector &point,
        boxPtrVec &candidateList) const;
  };
}

///
/// eof: acme_AABBtree.hh
///