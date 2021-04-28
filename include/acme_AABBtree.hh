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
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: davide.stocco@unitn.it                                   *)
(*                                                                     *)
(***********************************************************************)
(*                                                                     *)
(*  Reference:                                                         *)
(*  Efficient intersection between splines of clothoids.               *)
(*  Enrico Bertolazzi, Paolo Bevilacqua, Marco Frego                   *)
(*  October 2019 - Mathematics and Computers in Simulation 176         *)
(*  DOI: 10.1016/j.matcom.2019.10.001                                  *)
(*                                                                     *)
(*  URL: https://github.com/ebertolazzi/Clothoids                      *)
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

  //! AABB tree class container
  /**
   * Axis-Aligned Bouding Box tree.
  */
  class AABBtree
  {
  public:
    typedef std::shared_ptr<AABBtree> ptr; //!< Shared pointer to AABB tree object

  private:
    box::ptr _ptrbox; //!< Pointer to AABB tree box
    std::vector<AABBtree::ptr> _children;

    AABBtree(AABBtree const &tree);

  public:
    //! AABB tree class destructor
    ~AABBtree();

    //! AABB tree class constructor
    AABBtree();

    //! Clear AABB tree data
    void
    clear(void);

    //! Check if AABB tree is empty
    bool
    isEmpty(void) const;

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
      if (!tree._ptrbox->intersects(*this->_ptrbox))
        return false;

      int icase = (this->_children.empty() ? 0 : 1) +
                  (tree._children.empty() ? 0 : 2);

      switch (icase)
      {
      case 0: // both leaf, use box intersection algorithm
        if (swap_tree)
          return function(tree._ptrbox, this->_ptrbox);
        else
          return function(this->_ptrbox, tree._ptrbox);
      case 1: // first is a tree, second is a leaf
      {
        typename std::vector<AABBtree::ptr>::const_iterator it;
        for (it = this->_children.begin(); it != this->_children.end(); ++it)
          if (tree.collision(**it, function, !swap_tree))
            return true;
      }
      break;
      case 2: // first leaf, second is a tree
      {
        typename std::vector<AABBtree::ptr>::const_iterator it;
        for (it = tree._children.begin();
             it != tree._children.end(); ++it)
          if (this->collision(**it, function, swap_tree))
            return true;
      }
      break;
      case 3: // first is a tree, second is a tree
      {
        typename std::vector<AABBtree::ptr>::const_iterator it1;
        typename std::vector<AABBtree::ptr>::const_iterator it2;
        for (it1 = this->_children.begin(); it1 != this->_children.end(); ++it1)
          for (it2 = tree._children.begin();
               it2 != tree._children.end(); ++it2)
            if ((*it1)->collision(**it2, function, swap_tree))
              return true;
      }
      break;
      }
      return false;
    }

    //! Compute all the intersection of AABB trees
    void
    intersection(
        AABBtree const &tree,              //!< AABB tree used to check collision
        box::vecpairptr &intersectionList, //!< List of pair box that overlaps
        bool swap_tree = false             //!< If true exchange the tree in computation
    ) const;

    //! Find the candidate at minimum distance from point
    void selectMinimumDistance(
        vec3 const &point,         //!< Input point
        box::vecptr &candidateList //!< Output candidate list
    ) const;

  private:
    //! Compute the minimum of the maximum distance between a point
    static real_type
    minimumExteriorDistance(
        vec3 const &point,    //!< Input point
        AABBtree const &tree, //!< Input tree
        real_type distance    //!< Output distance
    );

    //! Select the candidate which box have distance less than distance
    static void
    selectLessThanDistance(
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