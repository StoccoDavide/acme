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
*/

///
/// file: acme_collection.cc
///

#include "acme_collection.hh"

namespace acme
{

  /*\
   |             _ _           _   _              
   |    ___ ___ | | | ___  ___| |_(_) ___  _ __  
   |   / __/ _ \| | |/ _ \/ __| __| |/ _ \| '_ \ 
   |  | (_| (_) | | |  __/ (__| |_| | (_) | | | |
   |   \___\___/|_|_|\___|\___|\__|_|\___/|_| |_|
   |                                             
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  collection::collection()
      : m_AABBtree(std::make_shared<AABBtree>())
  {
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  collection::collection(
      entity::vecptr &entities)
      : collection()
  {
    this->m_entities = entities;
  };

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::clear(void)
  {
    this->m_entities.clear();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::resize(
      size_t size)
  {
    this->m_entities.resize(size);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  //void
  //collection::push_back(
  //    entity const &entity_in)
  //{
  //  this->m_entities.push_back(std::move(std::shared_ptr<entity>(entity_in)));
  //}

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::push_back(
      entity::ptr entity_in)
  {
    this->m_entities.push_back(entity_in);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  entity::ptr &collection::operator[](
      size_t i)
  {
    return this->m_entities[i];
  };

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  entity::ptr const &
  collection::operator[](
      size_t i)
      const
  {
    return this->m_entities[i];
  };

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::translate(
      vec3 const &input)
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
      this->m_entities[i]->translate(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::rotate(
      real angle,
      vec3 const &axis)
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
      this->m_entities[i]->rotate(angle, axis);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::transform(
      affine const &matrix)
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
      this->m_entities[i]->transform(matrix);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containNone(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isNone())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areNone(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isNone())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isNone(
      size_t i)
      const
  {
    return this->m_entities[i]->isNone();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeNone(void)
  {
    //remove_if(
    //    this->m_entities.begin(),
    //    this->m_entities.end(),
    //    [this](entity::ptr &entity)
    //    { return this->isNone(); });
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countNone(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isNone())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containPoint(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isPoint())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::arePoint(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isPoint())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isPoint(
      size_t i)
      const
  {
    return this->m_entities[i]->isPoint();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removePoint(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isPoint);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countPoint(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isPoint())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containLine(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isLine())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areLine(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isLine())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isLine(
      size_t i)
      const
  {
    return this->m_entities[i]->isLine();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeLine(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isLine);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countLine(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isLine())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containRay(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isRay())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areRay(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isRay())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isRay(
      size_t i)
      const
  {
    return this->m_entities[i]->isRay();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeRay(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isRay);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countRay(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isRay())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containPlane(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isPlane())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::arePlane(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isPlane())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isPlane(
      size_t i)
      const
  {
    return this->m_entities[i]->isPlane();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removePlane(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isPlane);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countPlane(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isPlane())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containSegment(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isSegment())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areSegment(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isSphere())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isSegment(
      size_t i)
      const
  {
    return this->m_entities[i]->isSegment();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeSegment(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isSegment);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countSegment(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isSegment())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containTriangle(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isTriangle())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areTriangle(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isTriangle())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isTriangle(
      size_t i)
      const
  {
    return this->m_entities[i]->isTriangle();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeTriangle(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isTriangle);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countTriangle(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isTriangle())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containCircle(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isCircle())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areCircle(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isCircle())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isCircle(
      size_t i)
      const
  {
    return this->m_entities[i]->isCircle();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeCircle(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isCircle);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countCircle(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isCircle())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containSphere(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isSphere())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areSphere(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isSphere())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isSphere(
      size_t i)
      const
  {
    return this->m_entities[i]->isSphere();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeSphere(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isSphere);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countSphere(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isSphere())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containDegenerated(
      real tolerance)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isDegenerated(tolerance))
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areDegenerated(
      real tolerance)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isDegenerated(tolerance))
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isDegenerated(
      size_t i,
      real tolerance)
      const
  {
    return this->m_entities[i]->isDegenerated(tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeDegenerated(
      real tolerance)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isDegenerated(tolerance));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countDegenerated(
      real tolerance)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isDegenerated(tolerance))
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containClampable(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isClampable())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areClampable(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isClampable())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isClampable(
      size_t i)
      const
  {
    return this->m_entities[i]->isClampable();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeClampable(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isClampable);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countClampable(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isClampable())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::containNonClampable(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (this->m_entities[i]->isNonClampable())
        return true;
    }
    return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::areNonClampable(void)
      const
  {
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isNonClampable())
        return false;
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::isNonClampable(
      size_t i)
      const
  {
    return this->m_entities[i]->isNonClampable();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::removeNonClampable(void)
  {
    //entity::vecptr::iterator it;
    //it = remove_if(this->m_entities.begin(), this->m_entities.end(), isNonClampable);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::countNonClampable(void)
      const
  {
    integer count = 0;
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      if (!this->m_entities[i]->isNonClampable())
        ++count;
    }
    return count;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  integer
  collection::size(void)
      const
  {
    return this->m_entities.size();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  std::map<std::string, integer>
  collection::count(
      real tolerance)
      const
  {
    return {{"none", this->countNone()},
            {"point", this->countPoint()},
            {"line", this->countLine()},
            {"ray", this->countRay()},
            {"plane", this->countPlane()},
            {"segment", this->countSegment()},
            {"triangle", this->countTriangle()},
            {"circle", this->countCircle()},
            {"sphere", this->countSphere()},
            {"degenerated", this->countDegenerated(tolerance)},
            {"clampable", this->countClampable()},
            {"non-clampable", this->countNonClampable()}};
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::clamp(
      std::vector<std::shared_ptr<aabb>> &boxes)
      const
  {
    boxes.clear();
    boxes.resize(this->m_entities.size());
    for (size_t i = 0; i < this->m_entities.size(); ++i)
    {
      //if (this->m_entities[i]->isClampable())
      //  this->m_entities[i]->clamp(*boxes[i], i, 0);
      //else
      //  ACME_ERROR("acme::collection::clamp(): non-clampable object detected.");
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  collection::buildAABBtree(void)
      const
  {
    std::vector<std::shared_ptr<aabb>> ptrVecbox;
    this->clamp(ptrVecbox);
    //this->m_AABBtree->build(std::const_pointer_cast<aabb::ptr>(ptrVecbox));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  AABBtree::ptr const &
  collection::ptrAABBtree(void)
  {
    return this->m_AABBtree;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::intersection(
      collection &entities,
      collection &candidates)
      const
  {
    candidates.clear();
    aabb::vecpairptr intersection_list;
    this->m_AABBtree->intersection(*entities.ptrAABBtree(), intersection_list);
    for (size_t i = 0; i < intersection_list.size(); ++i)
    {
      candidates.push_back(this->m_entities[(intersection_list[i].first)->id()]);
      candidates.push_back(entities[(intersection_list[i].second)->id()]);
    }
    return candidates.size() > 0;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::intersection(
      AABBtree::ptr const &ptrAABBtree,
      collection &candidates)
      const
  {
    candidates.clear();
    aabb::vecpairptr intersection_list;
    this->m_AABBtree->intersection(*ptrAABBtree, intersection_list);
    for (size_t i = 0; i < intersection_list.size(); ++i)
      candidates.push_back(this->m_entities[(intersection_list[i].first)->id()]);
    return candidates.size() > 0;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::intersection(
      aabb::vecptr const &ptrVecbox,
      collection &candidates)
      const
  {
    AABBtree::ptr ptrAABBtree(std::make_shared<AABBtree>());
    ptrAABBtree->build(ptrVecbox);
    return this->intersection(ptrAABBtree, candidates);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  collection::intersection(
      aabb::ptr const ptrbox,
      collection &candidates)
      const
  {
    aabb::vecptr ptrVecbox;
    ptrVecbox.push_back(ptrbox);
    return this->intersection(ptrVecbox, candidates);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_collection.cc
///