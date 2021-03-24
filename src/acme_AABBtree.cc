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
    boxPtr.reset();
    children.clear();
  }

  AABBtree::~AABBtree()
  {
    boxPtr.reset();
    children.clear();
  }

  void
  AABBtree::clear()
  {
    boxPtr.reset();
    children.clear();
  }

  bool
  AABBtree::is_empty() const
  {
    return children.empty() && !boxPtr;
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
  AABBtree::build(std::vector<boxPtr> const &boxes)
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
    boxPtr = shared_ptr<box>(new box(boxes, 0, 0));
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

    std::vector<boxPtr> posBoxes;
    std::vector<boxPtr> negBoxes;

    if ((xmax - xmin) > (ymax - ymin) && (xmax - xmin) > (zmax - zmin))
    {
      real_type cutPos = (xmax + xmin) / 2;
      std::vector<boxPtr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real_type xmid = ((*it)->x_min() + (*it)->x_max()) / 2;
        if (xmid > cutPos)
          posBoxes.push_back(*it);
        else
          negBoxes.push_back(*it);
      }
    }
    else if ((ymax - ymin) > (xmax - xmin) && (ymax - ymin) > (zmax - zmin))
    {
      real_type cutPos = (ymax + ymin) / 2;
      std::vector<boxPtr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real_type ymid = ((*it)->y_min() + (*it)->y_max()) / 2;
        if (ymid > cutPos)
          posBoxes.push_back(*it);
        else
          negBoxes.push_back(*it);
      }
    }
    else
    {
      real_type cutPos = (zmax + zmin) / 2;
      std::vector<boxPtr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real_type zmid = ((*it)->z_min() + (*it)->z_max()) / 2;
        if (zmid > cutPos)
          posBoxes.push_back(*it);
        else
          negBoxes.push_back(*it);
      }
    }

    if (negBoxes.empty())
    {
      std::vector<boxPtr>::iterator midIdx;
      midIdx = posBoxes.begin() + posBoxes.size() / 2;
      negBoxes.insert(negBoxes.end(), midIdx, posBoxes.end());
      posBoxes.erase(midIdx, posBoxes.end());
    }
    else if (posBoxes.empty())
    {
      std::vector<boxPtr>::iterator midIdx;
      midIdx = negBoxes.begin() + negBoxes.size() / 2;
      posBoxes.insert(posBoxes.end(), midIdx, negBoxes.end());
      negBoxes.erase(midIdx, negBoxes.end());
    }

#ifdef ACME_USE_CXX11
    PtrAABB neg = make_shared<AABBtree>();
    PtrAABB pos = make_shared<AABBtree>();
#else
    PtrAABB neg = new AABBtree();
    PtrAABB pos = new AABBtree();
#endif

    neg->build(negBoxes);
    if (!neg->is_empty())
      children.push_back(neg);

    pos->build(posBoxes);
    if (!pos->is_empty())
      children.push_back(pos);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::print(ostream_type &stream, int_type level) const
  {
    if (this->is_empty())
    {
      stream << "[EMPTY AABB tree]\n";
    }
    else
    {
      /*fmt::print(stream,
                 "BOX xmin={:<12.4)} ymin={:<12.4)} zmin={:<12.4)} xmax={:<12.4)} ymax={:<12.4)} zmax={:<12.4)} level={}\n",
                 ptrbox->x_min(), ptrbox->y_min(), ptrbox->z_min(),
                 ptrbox->x_max(), ptrbox->y_max(), ptrbox->z_max());*/
      std::vector<PtrAABB>::const_iterator it;
      for (it = children.begin(); it != children.end(); ++it)
        (*it)->print(stream, level + 1);
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::intersect(
      AABBtree const &tree,
      boxPtrPairVec &intersectionList,
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
        intersectionList.push_back(boxPtrPair(tree.ptrbox, ptrbox));
      else
        intersectionList.push_back(boxPtrPair(ptrbox, tree.ptrbox));
      break;
    case 1: // First is a tree, second is a leaf
    {
      std::vector<PtrAABB>::const_iterator it;
      for (it = children.begin(); it != children.end(); ++it)
        tree.intersect(**it, intersectionList, !swap_tree);
    }
    break;
    case 2: // First leaf, second is a tree
    {
      std::vector<PtrAABB>::const_iterator it;
      for (it = tree.children.begin(); it != tree.children.end(); ++it)
        this->intersect(**it, intersectionList, swap_tree);
    }
    break;
    case 3: // First is a tree, second is a tree
    {
      std::vector<PtrAABB>::const_iterator c1;
      std::vector<PtrAABB>::const_iterator c2;
      for (c1 = children.begin(); c1 != children.end(); ++c1)
        for (c2 = tree.children.begin(); c2 != tree.children.end(); ++c2)
          (*c1)->intersect(**c2, intersectionList, swap_tree);
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

    std::vector<PtrAABB> const &children = tree.children;

    if (children.empty())
    {
      real_type dst = tree.ptrbox->max_distance(point);
      return acme::min(dst, distance);
    }

    real_type dmin = tree.ptrbox->distance(point);
    if (dmin > distance)
      return distance;

    // check box with
    std::vector<PtrAABB>::const_iterator it;
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
      boxPtrVec &candidateList)
  {
    std::vector<PtrAABB> const &children = tree.children;
    real_type dst = tree.ptrbox->distance(point);
    if (dst <= distance)
    {
      if (children.empty())
      {
        candidateList.push_back(tree.ptrbox);
      }
      else
      {
        // check box with
        std::vector<PtrAABB>::const_iterator it;
        for (it = children.begin(); it != children.end(); ++it)
          min_maxdist_select(point, distance, **it, candidateList);
      }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::min_distance(
      vec3 const &point,
      boxPtrVec &candidateList) const
  {
    real_type distance = this->min_maxdist(
        point, *this, acme::infinity());
    this->min_maxdist_select(point, distance, *this, candidateList);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_AABBtree.cc
///
