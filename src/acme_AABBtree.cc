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
/// file: acme_aabbTree.cc
///

#include "acme_aabbTree.hh"

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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  aabbTree::aabbTree()
  {
    this->_ptrbox.reset();
    this->_children.clear();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  aabbTree::~aabbTree()
  {
    this->_ptrbox.reset();
    this->_children.clear();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabbTree::clear()
  {
    this->_ptrbox.reset();
    this->_children.clear();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  aabbTree::isEmpty()
      const
  {
    return this->_children.empty() && !this->_ptrbox;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabbTree::build(
      std::vector<aabb::ptr> const &boxes)
  {
    clear();

    if (boxes.empty())
      return;

    integer size = boxes.size();

    if (size == 1)
    {
      this->_ptrbox = boxes.front();
      return;
    }

    this->_ptrbox = std::make_shared<aabb>(boxes, 0, 0);

    real xmin = this->_ptrbox->minX();
    real ymin = this->_ptrbox->minY();
    real zmin = this->_ptrbox->minZ();
    real xmax = this->_ptrbox->maxX();
    real ymax = this->_ptrbox->maxY();
    real zmax = this->_ptrbox->maxZ();

    std::vector<aabb::ptr> pos_boxes;
    std::vector<aabb::ptr> neg_boxes;

    if ((xmax - xmin) > (ymax - ymin) && (xmax - xmin) > (zmax - zmin))
    {
      real cut_pos = (xmax + xmin) / 2;
      std::vector<aabb::ptr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real xmid = ((*it)->minX() + (*it)->maxX()) / 2;
        if (xmid > cut_pos)
          pos_boxes.push_back(*it);
        else
          neg_boxes.push_back(*it);
      }
    }
    else if ((ymax - ymin) > (xmax - xmin) && (ymax - ymin) > (zmax - zmin))
    {
      real cut_pos = (ymax + ymin) / 2;
      std::vector<aabb::ptr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real ymid = ((*it)->minY() + (*it)->maxY()) / 2;
        if (ymid > cut_pos)
          pos_boxes.push_back(*it);
        else
          neg_boxes.push_back(*it);
      }
    }
    else
    {
      real cut_pos = (zmax + zmin) / 2;
      std::vector<aabb::ptr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real zmid = ((*it)->minZ() + (*it)->maxZ()) / 2;
        if (zmid > cut_pos)
          pos_boxes.push_back(*it);
        else
          neg_boxes.push_back(*it);
      }
    }

    if (neg_boxes.empty())
    {
      std::vector<aabb::ptr>::iterator mid_idx;
      mid_idx = pos_boxes.begin() + pos_boxes.size() / 2;
      neg_boxes.insert(neg_boxes.end(), mid_idx, pos_boxes.end());
      pos_boxes.erase(mid_idx, pos_boxes.end());
    }
    else if (pos_boxes.empty())
    {
      std::vector<aabb::ptr>::iterator mid_idx;
      mid_idx = neg_boxes.begin() + neg_boxes.size() / 2;
      pos_boxes.insert(pos_boxes.end(), mid_idx, neg_boxes.end());
      neg_boxes.erase(mid_idx, neg_boxes.end());
    }

    aabbTree::ptr neg = std::make_shared<aabbTree>();
    aabbTree::ptr pos = std::make_shared<aabbTree>();

    neg->build(neg_boxes);
    if (!neg->isEmpty())
      this->_children.push_back(neg);

    pos->build(pos_boxes);
    if (!pos->isEmpty())
      this->_children.push_back(pos);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabbTree::print(
      out_stream &os,
      integer level)
      const
  {
    if (this->isEmpty())
    {
      os << "[EMPTY AABB tree]" << std::endl;
    }
    else
    {
      os << std::scientific
         << std::showpoint
         << std::setprecision(10)
         << "Box =" << std::endl
         << "Minimum = [ " << this->_ptrbox->minX() << ", " << this->_ptrbox->minY() << ", " << this->_ptrbox->minZ() << " ]'" << std::endl
         << "Maximum = [ " << this->_ptrbox->maxX() << ", " << this->_ptrbox->maxY() << ", " << this->_ptrbox->maxZ() << " ]'" << std::endl
         << std::endl;
      std::vector<aabbTree::ptr>::const_iterator it;
      for (it = this->_children.begin(); it != this->_children.end(); ++it)
        (*it)->print(os, level + 1);
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabbTree::intersection(
      aabbTree const &tree,
      aabb::vecpairptr &intersection_list,
      bool swap_tree)
      const
  {
    // Check aabb with
    if (!tree._ptrbox->intersects(*this->_ptrbox))
      return;
    integer icase = (this->_children.empty() ? 0 : 1) +
                    (tree._children.empty() ? 0 : 2);
    switch (icase)
    {
    case 0: // Both are leafs
      if (swap_tree)
        intersection_list.push_back(aabb::pairptr(tree._ptrbox, this->_ptrbox));
      else
        intersection_list.push_back(aabb::pairptr(this->_ptrbox, tree._ptrbox));
      break;
    case 1: // First is a tree, second is a leaf
    {
      std::vector<aabbTree::ptr>::const_iterator it;
      for (it = this->_children.begin(); it != this->_children.end(); ++it)
        tree.intersection(**it, intersection_list, !swap_tree);
    }
    break;
    case 2: // First leaf, second is a tree
    {
      std::vector<aabbTree::ptr>::const_iterator it;
      for (it = tree._children.begin(); it != tree._children.end(); ++it)
        this->intersection(**it, intersection_list, swap_tree);
    }
    break;
    case 3: // First is a tree, second is a tree
    {
      std::vector<aabbTree::ptr>::const_iterator c1;
      std::vector<aabbTree::ptr>::const_iterator c2;
      for (c1 = this->_children.begin(); c1 != this->_children.end(); ++c1)
        for (c2 = tree._children.begin(); c2 != tree._children.end(); ++c2)
          (*c1)->intersection(**c2, intersection_list, swap_tree);
    }
    break;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real
  aabbTree::minimumExteriorDistance(
      point const &query_point,
      aabbTree const &tree,
      real distance)
  {
    std::vector<aabbTree::ptr> const &tree_children = tree._children;
    if (tree_children.empty())
    {
      real dst = tree._ptrbox->exteriorDistance(query_point);
      return acme::min(dst, distance);
    }
    real dmin = tree._ptrbox->centerDistance(query_point);
    if (dmin > distance)
      return distance;
    // check aabb with
    std::vector<aabbTree::ptr>::const_iterator it;
    for (it = tree_children.begin(); it != tree_children.end(); ++it)
      distance = minimumExteriorDistance(query_point, **it, distance);
    return distance;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabbTree::selectLessThanDistance(
      point const &query_point,
      real distance,
      aabbTree const &tree,
      aabb::vecptr &candidate_list)
  {
    std::vector<aabbTree::ptr> const &tree_children = tree._children;
    real dst = tree._ptrbox->centerDistance(query_point);
    if (dst <= distance)
    {
      if (tree_children.empty())
      {
        candidate_list.push_back(tree._ptrbox);
      }
      else
      {
        // check aabb with
        std::vector<aabbTree::ptr>::const_iterator it;
        for (it = tree_children.begin(); it != tree_children.end(); ++it)
          selectLessThanDistance(query_point, distance, **it, candidate_list);
      }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  aabbTree::selectMinimumDistance(
      point const &query_point,
      aabb::vecptr &candidate_list)
      const
  {
    real distance = this->minimumExteriorDistance(query_point, *this, acme::infinity());
    this->selectLessThanDistance(query_point, distance, *this, candidate_list);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_aabbTree.cc
///
