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
/// file: acme_aabbTree.hh
///

#include "acme.hh"
#include "acme_aabb.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |               _     _   _____              
   |    __ _  __ _| |__ | |_|_   _| __ ___  ___ 
   |   / _` |/ _` | '_ \| '_ \| || '__/ _ \/ _ \
   |  | (_| | (_| | |_) | |_) | || | |  __/  __/
   |   \__,_|\__,_|_.__/|_.__/|_||_|  \___|\___|
   |                                            
  \*/

  //! Axis-aligned bouding tree class container
  /**
   * Axis-aligned bouding aabb tree.
  */
  class aabbTree
  {
public:
    typedef std::shared_ptr<aabbTree> ptr; //!< Shared pointer to AABB tree object

private:
    aabb::ptr _ptrbox; //!< Pointer to AABB tree aabb
    std::vector<aabbTree::ptr> _children;

    aabbTree(aabbTree const &tree);

public:
    //! AABB tree class destructor
    ~aabbTree();

    //! AABB tree class constructor
    aabbTree();

    //! Clear AABB tree data
    void
    clear(void);

    //! Check if AABB tree is empty
    bool
    isEmpty(void) const;

    //! Build AABB tree given a list of boxes
    void
    build(
        std::vector<aabb::ptr> const &boxes //!< List of boxes
    );

    //! Print AABB tree content
    void
    print(
        out_stream &stream, //!< Output stream
        int level = 0       //!< Level to print
    ) const;

    //! Check if two AABB tree collide
    template <typename collision>
    bool
    collision(
        aabbTree const &tree,  //!< AABB tree used to check collision
        collision function,    //!< Function to check if the contents of two aabb collide
        bool swap_tree = false //!< If true exchange the tree in computation
    ) const
    {

      // check aabb with
      if (!tree._ptrbox->intersects(*this->_ptrbox))
        return false;

      int icase = (this->_children.empty() ? 0 : 1) +
                  (tree._children.empty() ? 0 : 2);

      switch (icase)
      {
      case 0: // both leaf, use aabb intersection algorithm
        if (swap_tree)
          return function(tree._ptrbox, this->_ptrbox);
        else
          return function(this->_ptrbox, tree._ptrbox);
      case 1: // first is a tree, second is a leaf
      {
        typename std::vector<aabbTree::ptr>::const_iterator it;
        for (it = this->_children.begin(); it != this->_children.end(); ++it)
          if (tree.collision(**it, function, !swap_tree))
            return true;
      }
      break;
      case 2: // first leaf, second is a tree
      {
        typename std::vector<aabbTree::ptr>::const_iterator it;
        for (it = tree._children.begin();
             it != tree._children.end(); ++it)
          if (this->collision(**it, function, swap_tree))
            return true;
      }
      break;
      case 3: // first is a tree, second is a tree
      {
        typename std::vector<aabbTree::ptr>::const_iterator it1;
        typename std::vector<aabbTree::ptr>::const_iterator it2;
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
        aabbTree const &tree,               //!< AABB tree used to check collision
        aabb::vecpairptr &intersectionList, //!< List of pair aabb that overlaps
        bool swap_tree = false              //!< If true exchange the tree in computation
    ) const;

    //! Find the candidate at minimum distance from point
    void selectMinimumDistance(
        point const &query_point,   //!< Input point
        aabb::vecptr &candidateList //!< Output candidate list
    ) const;

private:
    //! Compute the minimum of the maximum distance between a point
    static real
    minimumExteriorDistance(
        point const &query_point, //!< Input point
        aabbTree const &tree,     //!< Input tree
        real distance             //!< Output distance
    );

    //! Select the candidate which aabb have distance less than distance
    static void
    selectLessThanDistance(
        point const &query_point,   //!< Input point
        real distance,              //!< Input distance
        aabbTree const &tree,       //!< Input tree
        aabb::vecptr &candidateList //!< Output candidate list
    );

  }; // class aabbTree

} // namespace acme

///
/// eof: acme_aabbTree.hh
///