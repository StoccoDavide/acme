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

  AABBtree::AABBtree()
  {
    box::ptr.reset();
    children.clear();
  }

  AABBtree::~AABBtree()
  {
    box::ptr.reset();
    children.clear();
  }

  void
  AABBtree::clear()
  {
    box::ptr.reset();
    children.clear();
  }

  bool
  AABBtree::is_empty() const
  {
    return children.empty() && !box::ptr;
  }

#else

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

  bool
  AABBtree::is_empty() const
  {
    return children.empty() && ptrbox == nullptr;
  }

#endif

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::build(std::vector<box::ptr> const &boxes)
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
    box::ptr = shared_ptr<box>(new box(boxes, 0, 0));
#else
    if (ptrbox != nullptr)
    {
      delete ptrbox;
      ptrbox = nullptr;
    }
    ptrbox = new box(boxes, 0, 0);
#endif

    real_type xmin = ptrbox->x_min();
    real_type ymin = ptrbox->y_min();
    real_type zmin = ptrbox->z_min();
    real_type xmax = ptrbox->x_max();
    real_type ymax = ptrbox->y_max();
    real_type zmax = ptrbox->z_max();

    std::vector<box::ptr> pos_boxes;
    std::vector<box::ptr> neg_boxes;

    if ((xmax - xmin) > (ymax - ymin) && (xmax - xmin) > (zmax - zmin))
    {
      real_type cut_pos = (xmax + xmin) / 2;
      std::vector<box::ptr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real_type xmid = ((*it)->x_min() + (*it)->x_max()) / 2;
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
        real_type ymid = ((*it)->y_min() + (*it)->y_max()) / 2;
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
        real_type zmid = ((*it)->z_min() + (*it)->z_max()) / 2;
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
    AABBtree::ptr neg = make_shared<AABBtree>();
    AABBtree::ptr pos = make_shared<AABBtree>();
#else
    AABBtree::ptr neg = new AABBtree();
    AABBtree::ptr pos = new AABBtree();
#endif

    neg->build(neg_boxes);
    if (!neg->is_empty())
      children.push_back(neg);

    pos->build(pos_boxes);
    if (!pos->is_empty())
      children.push_back(pos);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::print(ostream_type &os, int_type level) const
  {
    if (this->is_empty())
    {
      os << "[EMPTY AABB tree]" << std::endl;
    }
    else
    {
      os << std::scientific
         << std::showpoint
         << std::setprecision(10)
         << "BOX xmin={" << ptrbox->x_min() << "} ymin={" << ptrbox->y_min() << "} zmin={" << ptrbox->z_min() << "}"
         << "    xmax={" << ptrbox->x_max() << "} ymax={" << ptrbox->x_max() << "} zmax={" << ptrbox->x_max() << "}"
         << std::endl;
      std::vector<AABBtree::ptr>::const_iterator it;
      for (it = children.begin(); it != children.end(); ++it)
        (*it)->print(os, level + 1);
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::intersect(
      AABBtree const &tree,
      box::ptrPairVec &intersection_list,
      bool swap_tree) const
  {

    // Check box with
    if (!tree.ptrbox->collision(*ptrbox))
      return;

    int icase = (children.empty() ? 0 : 1) +
                (tree.children.empty() ? 0 : 2);

    switch (icase)
    {
    case 0: // Both are leafs
      if (swap_tree)
        intersection_list.push_back(box::ptrPair(tree.ptrbox, ptrbox));
      else
        intersection_list.push_back(box::ptrPair(ptrbox, tree.ptrbox));
      break;
    case 1: // First is a tree, second is a leaf
    {
      std::vector<AABBtree::ptr>::const_iterator it;
      for (it = children.begin(); it != children.end(); ++it)
        tree.intersect(**it, intersection_list, !swap_tree);
    }
    break;
    case 2: // First leaf, second is a tree
    {
      std::vector<AABBtree::ptr>::const_iterator it;
      for (it = tree.children.begin(); it != tree.children.end(); ++it)
        this->intersect(**it, intersection_list, swap_tree);
    }
    break;
    case 3: // First is a tree, second is a tree
    {
      std::vector<AABBtree::ptr>::const_iterator c1;
      std::vector<AABBtree::ptr>::const_iterator c2;
      for (c1 = children.begin(); c1 != children.end(); ++c1)
        for (c2 = tree.children.begin(); c2 != tree.children.end(); ++c2)
          (*c1)->intersect(**c2, intersection_list, swap_tree);
    }
    break;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  AABBtree::min_maxdist(
      vec3 const &point,
      AABBtree const &tree,
      real_type distance)
  {

    std::vector<AABBtree::ptr> const &children = tree.children;

    if (children.empty())
    {
      real_type dst = tree.ptrbox->max_distance(point);
      return acme::min(dst, distance);
    }

    real_type dmin = tree.ptrbox->distance(point);
    if (dmin > distance)
      return distance;

    // check box with
    std::vector<AABBtree::ptr>::const_iterator it;
    for (it = children.begin(); it != children.end(); ++it)
      distance = min_maxdist(point, **it, distance);

    return distance;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::min_maxdist_select(
      vec3 const &point,
      real_type distance,
      AABBtree const &tree,
      box::ptrVec &candidate_list)
  {
    std::vector<AABBtree::ptr> const &children = tree.children;
    real_type dst = tree.ptrbox->distance(point);
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
          min_maxdist_select(point, distance, **it, candidate_list);
      }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::min_distance(
      vec3 const &point,
      box::ptrVec &candidate_list) const
  {
    real_type distance = this->min_maxdist(
        point, *this, acme::infinity());
    this->min_maxdist_select(point, distance, *this, candidate_list);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_AABBtree.cc
///
