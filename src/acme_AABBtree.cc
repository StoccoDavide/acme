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
/// file: acme_AABBtree.cc
///

#include "acme_AABBtree.hh"

namespace acme
{

  /*\
   |      _        _    ____  ____  _
   |     / \      / \  | __ )| __ )| |_ _ __ ___  ___
   |    / _ \    / _ \ |  _ \|  _ \| __| '__/ _ \/ _ \
   |   / ___ \  / ___ \| |_) | |_) | |_| | |  __/  __/
   |  /_/   \_\/_/   \_\____/|____/ \__|_|  \___|\___|
  \*/

#ifdef ACME_USE_CXX11

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  AABBtree::AABBtree()
  {
    ptrbox.reset();
    children.clear();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  AABBtree::~AABBtree()
  {
    ptrbox.reset();
    children.clear();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::clear()
  {
    ptrbox.reset();
    children.clear();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  AABBtree::isEmpty()
      const
  {
    return children.empty() && !ptrbox;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#else

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  AABBtree::AABBtree()
      : ptrbox(nullptr)
  {
    children.clear();
  }

  AABBtree::~AABBtree()
  {
    if (ptrbox != nullptr)
    {
      delete ptrbox;
      ptrbox = nullptr;
    }
    children.clear();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::clear()
  {
    if (ptrbox != nullptr)
    {
      delete ptrbox;
      ptrbox = nullptr;
    }
    children.clear();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  AABBtree::isEmpty()
      const
  {
    return children.empty() && ptrbox == nullptr;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::build(
      std::vector<box::ptr> const &boxes)
  {
    clear();

    if (boxes.empty())
      return;

    size_t size = boxes.size();

    if (size == 1)
    {
      this->ptrbox = boxes.front();
      return;
    }

#ifdef ACME_USE_CXX11
    ptrbox = std::shared_ptr<box>(new box(boxes, 0, 0));
#else
    if (ptrbox != nullptr)
    {
      delete ptrbox;
      ptrbox = nullptr;
    }
    ptrbox = new box(boxes, 0, 0);
#endif

    real_type xmin = ptrbox->minX();
    real_type ymin = ptrbox->minY();
    real_type zmin = ptrbox->minZ();
    real_type xmax = ptrbox->maxX();
    real_type ymax = ptrbox->maxY();
    real_type zmax = ptrbox->maxZ();

    std::vector<box::ptr> pos_boxes;
    std::vector<box::ptr> neg_boxes;

    if ((xmax - xmin) > (ymax - ymin) && (xmax - xmin) > (zmax - zmin))
    {
      real_type cut_pos = (xmax + xmin) / 2;
      std::vector<box::ptr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real_type xmid = ((*it)->minX() + (*it)->maxX()) / 2;
        if (xmid > cut_pos)
          pos_boxes.push_back(*it);
        else
          neg_boxes.push_back(*it);
      }
    }
    else if ((ymax - ymin) > (xmax - xmin) && (ymax - ymin) > (zmax - zmin))
    {
      real_type cut_pos = (ymax + ymin) / 2;
      std::vector<box::ptr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real_type ymid = ((*it)->minY() + (*it)->maxY()) / 2;
        if (ymid > cut_pos)
          pos_boxes.push_back(*it);
        else
          neg_boxes.push_back(*it);
      }
    }
    else
    {
      real_type cut_pos = (zmax + zmin) / 2;
      std::vector<box::ptr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real_type zmid = ((*it)->minZ() + (*it)->maxZ()) / 2;
        if (zmid > cut_pos)
          pos_boxes.push_back(*it);
        else
          neg_boxes.push_back(*it);
      }
    }

    if (neg_boxes.empty())
    {
      std::vector<box::ptr>::iterator mid_idx;
      mid_idx = pos_boxes.begin() + pos_boxes.size() / 2;
      neg_boxes.insert(neg_boxes.end(), mid_idx, pos_boxes.end());
      pos_boxes.erase(mid_idx, pos_boxes.end());
    }
    else if (pos_boxes.empty())
    {
      std::vector<box::ptr>::iterator mid_idx;
      mid_idx = neg_boxes.begin() + neg_boxes.size() / 2;
      pos_boxes.insert(pos_boxes.end(), mid_idx, neg_boxes.end());
      neg_boxes.erase(mid_idx, neg_boxes.end());
    }

#ifdef ACME_USE_CXX11
    AABBtree::ptr neg = std::make_shared<AABBtree>();
    AABBtree::ptr pos = std::make_shared<AABBtree>();
#else
    AABBtree::ptr neg = new AABBtree();
    AABBtree::ptr pos = new AABBtree();
#endif

    neg->build(neg_boxes);
    if (!neg->isEmpty())
      children.push_back(neg);

    pos->build(pos_boxes);
    if (!pos->isEmpty())
      children.push_back(pos);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::print(
      ostream_type &os,
      int_type level)
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
         << "Minimum = [ " << ptrbox->minX() << ", " << ptrbox->minY() << ", " << ptrbox->minZ() << " ]'" << std::endl
         << "Maximum = [ " << ptrbox->maxX() << ", " << ptrbox->maxY() << ", " << ptrbox->maxZ() << " ]'" << std::endl
         << std::endl;
      std::vector<AABBtree::ptr>::const_iterator it;
      for (it = children.begin(); it != children.end(); ++it)
        (*it)->print(os, level + 1);
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::intersection(
      AABBtree const &tree,
      box::vecpairptr &intersection_list,
      bool swap_tree)
      const
  {
    // Check box with
    if (!tree.ptrbox->intersects(*ptrbox))
      return;
    int icase = (children.empty() ? 0 : 1) +
                (tree.children.empty() ? 0 : 2);
    switch (icase)
    {
    case 0: // Both are leafs
      if (swap_tree)
        intersection_list.push_back(box::pairptr(tree.ptrbox, ptrbox));
      else
        intersection_list.push_back(box::pairptr(ptrbox, tree.ptrbox));
      break;
    case 1: // First is a tree, second is a leaf
    {
      std::vector<AABBtree::ptr>::const_iterator it;
      for (it = children.begin(); it != children.end(); ++it)
        tree.intersection(**it, intersection_list, !swap_tree);
    }
    break;
    case 2: // First leaf, second is a tree
    {
      std::vector<AABBtree::ptr>::const_iterator it;
      for (it = tree.children.begin(); it != tree.children.end(); ++it)
        this->intersection(**it, intersection_list, swap_tree);
    }
    break;
    case 3: // First is a tree, second is a tree
    {
      std::vector<AABBtree::ptr>::const_iterator c1;
      std::vector<AABBtree::ptr>::const_iterator c2;
      for (c1 = children.begin(); c1 != children.end(); ++c1)
        for (c2 = tree.children.begin(); c2 != tree.children.end(); ++c2)
          (*c1)->intersection(**c2, intersection_list, swap_tree);
    }
    break;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  AABBtree::minimumExteriorDistance(
      vec3 const &point,
      AABBtree const &tree,
      real_type distance)
  {
    std::vector<AABBtree::ptr> const &children = tree.children;
    if (children.empty())
    {
      real_type dst = tree.ptrbox->exteriorDistance(point);
      return acme::min(dst, distance);
    }
    real_type dmin = tree.ptrbox->centerDistance(point);
    if (dmin > distance)
      return distance;
    // check box with
    std::vector<AABBtree::ptr>::const_iterator it;
    for (it = children.begin(); it != children.end(); ++it)
      distance = minimumExteriorDistance(point, **it, distance);
    return distance;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::selectLessThanDistance(
      vec3 const &point,
      real_type distance,
      AABBtree const &tree,
      box::vecptr &candidate_list)
  {
    std::vector<AABBtree::ptr> const &children = tree.children;
    real_type dst = tree.ptrbox->centerDistance(point);
    if (dst <= distance)
    {
      if (children.empty())
      {
        candidate_list.push_back(tree.ptrbox);
      }
      else
      {
        // check box with
        std::vector<AABBtree::ptr>::const_iterator it;
        for (it = children.begin(); it != children.end(); ++it)
          selectLessThanDistance(point, distance, **it, candidate_list);
      }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::selectMinimumDistance(
      vec3 const &point,
      box::vecptr &candidate_list)
      const
  {
    real_type distance = this->minimumExteriorDistance(point, *this, acme::infinity());
    this->selectLessThanDistance(point, distance, *this, candidate_list);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_AABBtree.cc
///
