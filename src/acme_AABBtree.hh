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

  //! Class to manage AABB tree
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

    typedef std::pair<boxPtr, boxPtr> PairPtrBBox;
    typedef std::vector<boxPtr> VecPtrBBox;
    typedef std::vector<PairPtrBBox> VecPairPtrBBox;

  private:
    // bbox of the tree
    boxPtr pbox;
    std::vector<PtrAABB> children;

    AABBtree(AABBtree const &tree);

    //! Compute the minimum of the maximum distance between a point
    static real_type
    min_maxdist(
        real_type x,
        real_type y,
        AABBtree const &tree,
        real_type mmDist);

    //!  Select the candidate which box have distance less than mmDist
    static void
    min_maxdist_select(
        real_type x,
        real_type y,
        real_type mmDist,
        AABBtree const &tree,
        VecPtrBBox &candidateList);

  public:
    AABBtree();
    ~AABBtree();

    void clear(); //!< initialized AABB tree

    bool empty() const; //!< check if AABB tree is empty

    /*void
    bbox(
        real_type &xmin,
        real_type &ymin,
        real_type &xmax,
        real_type &ymax) const
    {
      xmin = pbox->m_xmin;
      ymin = pbox->m_ymin;
      xmax = pbox->m_xmax;
      ymax = pbox->m_ymax;
    }*/
    
    //! build AABB tree given a list of bbox
    void
    build(std::vector<boxPtr> const &bboxes);

    void
    print(std::ostream &stream, int level = 0) const;

    /*!
     * Check if two AABB tree collide
     *
     * \param[in] tree      an AABB tree that is used to check collision
     * \param[in] ifun      function the check if the contents of two bbox (curve) collide
     * \param[in] swap_tree if true exchange the tree in computation
     * \return true if the two tree collides
     *
     */
    template <typename COLLISION_fun>
    bool
    collision(
        AABBtree const &tree,
        COLLISION_fun ifun,
        bool swap_tree = false) const
    {

      // check bbox with
      if (!tree.pbox->collision(*pbox))
        return false;

      int icase = (children.empty() ? 0 : 1) +
                  (tree.children.empty() ? 0 : 2);

      switch (icase)
      {
      case 0: // both leaf, use GeomPrimitive intersection algorithm
        if (swap_tree)
          return ifun(tree.pbox, pbox);
        else
          return ifun(pbox, tree.pbox);
      case 1: // first is a tree, second is a leaf
      {
        typename std::vector<PtrAABB>::const_iterator it;
        for (it = children.begin(); it != children.end(); ++it)
          if (tree.collision(**it, ifun, !swap_tree))
            return true;
      }
      break;
      case 2: // first leaf, second is a tree
      {
        typename std::vector<PtrAABB>::const_iterator it;
        for (it = tree.children.begin();
             it != tree.children.end(); ++it)
          if (this->collision(**it, ifun, swap_tree))
            return true;
      }
      break;
      case 3: // first is a tree, second is a tree
      {
        typename std::vector<PtrAABB>::const_iterator c1;
        typename std::vector<PtrAABB>::const_iterator c2;
        for (c1 = children.begin(); c1 != children.end(); ++c1)
          for (c2 = tree.children.begin();
               c2 != tree.children.end(); ++c2)
            if ((*c1)->collision(**c2, ifun, swap_tree))
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
     * \param[out] intersectionList list of pair bbox that overlaps
     * \param[in]  swap_tree        if true exchange the tree in computation
     *
     */

    void
    intersect(
        AABBtree const &tree,
        VecPairPtrBBox &intersectionList,
        bool swap_tree = false) const;

    void
    min_distance(
        real_type x,
        real_type y,
        VecPtrBBox &candidateList) const;
  };
}

///
/// eof: acme_AABBtree.hh
///