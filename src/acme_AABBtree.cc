///
/// file: acme_AABBtree.cc
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
  AABBtree::empty() const
  {
    return children.empty() && !boxPtr;
  }

#else

  AABBtree::AABBtree()
      : pbox(nullptr)
  {
    children.clear();
  }

  AABBtree::~AABBtree()
  {
    if (pbox != nullptr)
    {
      delete pbox;
      pbox = nullptr;
    }
    children.clear();
  }

  void
  AABBtree::clear()
  {
    if (pbox != nullptr)
    {
      delete pbox;
      pbox = nullptr;
    }
    children.clear();
  }

  bool
  AABBtree::empty() const
  {
    return children.empty() && pbox == nullptr;
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
      this->pbox = boxes.front();
      return;
    }

#ifdef ACME_USE_CXX11
    boxPtr = shared_ptr<box>(new box(boxes, 0, 0));
#else
    if (pbox != nullptr)
    {
      delete pbox;
      pbox = nullptr;
    }
    pbox = new box(boxes, 0, 0);
#endif

    real_type xmin = pbox->point_0().x();
    real_type ymin = pbox->point_0().y();
    real_type zmin = pbox->point_0().z();
    real_type xmax = pbox->point_1().x();
    real_type ymax = pbox->point_1().y();
    real_type zmax = pbox->point_1().z();

    std::vector<boxPtr> posBoxes;
    std::vector<boxPtr> negBoxes;

    if ((ymax - ymin) > (xmax - xmin))
    {
      real_type cutPos = (ymax + ymin) / 2;
      std::vector<boxPtr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real_type ymid = ((*it)->Ymin() + (*it)->Ymax()) / 2;
        if (ymid > cutPos)
          posBoxes.push_back(*it);
        else
          negBoxes.push_back(*it);
      }
    }
    else
    {
      real_type cutPos = (xmax + xmin) / 2;
      std::vector<boxPtr>::const_iterator it;
      for (it = boxes.begin(); it != boxes.end(); ++it)
      {
        real_type xmid = ((*it)->Xmin() + (*it)->Xmax()) / 2;
        if (xmid > cutPos)
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

#ifdef G2LIB_USE_CXX11
    PtrAABB neg = make_shared<AABBtree>();
    PtrAABB pos = make_shared<AABBtree>();
#else
    PtrAABB neg = new AABBtree();
    PtrAABB pos = new AABBtree();
#endif

    neg->build(negBoxes);
    if (!neg->empty())
      children.push_back(neg);

    pos->build(posBoxes);
    if (!pos->empty())
      children.push_back(pos);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::print(std::ostream &stream, int_type level) const
  {
    if (empty())
    {
      stream << "[EMPTY AABB tree]\n";
    }
    else
    {
      fmt::print(stream,
                 "BBOX xmin={:<12.4)} ymin={:<12.4)} xmax={:<12.4)} ymax={:<12.4)} level={}\n",
                 pbox->m_xmin, pbox->m_ymin, pbox->m_xmax, pbox->m_ymax);
      std::vector<PtrAABB>::const_iterator it;
      for (it = children.begin(); it != children.end(); ++it)
        (*it)->print(stream, level + 1);
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::intersect(
      AABBtree const &tree,
      VecPairPtrBBox &intersectionList,
      bool swap_tree) const
  {

    // check bbox with
    if (!tree.boxPtr->collision(*boxPtr))
      return;

    int icase = (children.empty() ? 0 : 1) +
                (tree.children.empty() ? 0 : 2);

    switch (icase)
    {
    case 0: // both leaf
      if (swap_tree)
        intersectionList.push_back(PairPtrBBox(tree.pbox, pbox));
      else
        intersectionList.push_back(PairPtrBBox(pbox, tree.pbox));
      break;
    case 1: // first is a tree, second is a leaf
    {
      std::vector<PtrAABB>::const_iterator it;
      for (it = children.begin(); it != children.end(); ++it)
        tree.intersect(**it, intersectionList, !swap_tree);
    }
    break;
    case 2: // first leaf, second is a tree
    {
      std::vector<PtrAABB>::const_iterator it;
      for (it = tree.children.begin(); it != tree.children.end(); ++it)
        this->intersect(**it, intersectionList, swap_tree);
    }
    break;
    case 3: // first is a tree, second is a tree
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
      real_type x,
      real_type y,
      AABBtree const &tree,
      real_type mmDist)
  {

    std::vector<PtrAABB> const &children = tree.children;

    if (children.empty())
    {
      real_type dst = tree.pbox->maxDistance(x, y);
      return min(dst, mmDist);
    }

    real_type dmin = tree.pbox->distance(x, y);
    if (dmin > mmDist)
      return mmDist;

    // check box with
    std::vector<PtrAABB>::const_iterator it;
    for (it = children.begin(); it != children.end(); ++it)
      mmDist = min_maxdist(x, y, **it, mmDist);

    return mmDist;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::min_maxdist_select(
      real_type x,
      real_type y,
      real_type mmDist,
      AABBtree const &tree,
      VecPtrBBox &candidateList)
  {
    std::vector<PtrAABB> const &children = tree.children;
    real_type dst = tree.pbox->distance(x, y);
    if (dst <= mmDist)
    {
      if (children.empty())
      {
        candidateList.push_back(tree.pbox);
      }
      else
      {
        // check bbox with
        std::vector<PtrAABB>::const_iterator it;
        for (it = children.begin(); it != children.end(); ++it)
          min_maxdist_select(x, y, mmDist, **it, candidateList);
      }
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  AABBtree::min_distance(
      real_type x,
      real_type y,
      VecPtrBBox &candidateList) const
  {
    real_type mmDist = min_maxdist(
        x, y, *this, acme::infinity());
    min_maxdist_select(x, y, mmDist, *this, candidateList);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_AABBtree.cc
///
