
.. _program_listing_file_include_acme_collection.hh:

Program Listing for File acme_collection.hh
===========================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_collection.hh>` (``include/acme_collection.hh``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

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
   
   
   #ifndef INCLUDE_ACME_COLLECTION
   #define INCLUDE_ACME_COLLECTION
   
   #include <map>
   
   #include "acme.hh"
   #include "acme_AABBtree.hh"
   #include "acme_entity.hh"
   #include "acme_intersection.hh"
   
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
   
   
     class collection
     {
     private:
       entity::vecptr m_entities; 
       AABBtree::ptr m_AABBtree;  
   
     public:
       ~collection(){};
   
       collection(collection const &) = default;
   
       collection(collection &&) = default;
   
       collection();
   
       collection(
           entity::vecptr &entities 
       );
   
       void clear(void);
   
       void
       resize(
           size_t size 
       );
   
       void
       push_back(
           entity::ptr entity 
       );
   
       entity::ptr &
       operator[](
           size_t i 
       );
   
       entity::ptr const &
       operator[](
           size_t i 
       ) const;
   
       void
       translate(
           vec3 const &input 
       );
   
       void
       rotate(
           real angle,      
           vec3 const &axis 
       );
   
       void
       rotate(
           real angle,             
           std::string const &axis 
       );
   
       void
       transform(
           affine const &matrix 
       );
   
       bool
       containNone(void) const;
   
       bool
       areNone(void) const;
   
       bool
       isNone(
           size_t i 
       ) const;
   
       void
       removeNone(void);
   
       integer
       countNone(void) const;
   
       bool
       containPoint(void) const;
   
       bool
       arePoint(void) const;
   
       bool
       isPoint(
           size_t i 
       ) const;
   
       void
       removePoint(void);
   
       integer
       countPoint(void) const;
   
       bool
       containLine(void) const;
   
       bool
       areLine(void) const;
   
       bool
       isLine(
           size_t i 
       ) const;
   
       void
       removeLine(void);
   
       integer
       countLine(void) const;
   
       bool
       containRay(void) const;
   
       bool
       areRay(void) const;
   
       bool
       isRay(
           size_t i 
       ) const;
   
       void
       removeRay(void);
   
       integer
       countRay(void) const;
   
       bool
       containPlane(void) const;
   
       bool
       arePlane(void) const;
   
       bool
       isPlane(
           size_t i 
       ) const;
   
       void
       removePlane(void);
   
       integer
       countPlane(void) const;
   
       bool
       containSegment(void) const;
   
       bool
       areSegment(void) const;
   
       bool
       isSegment(
           size_t i 
       ) const;
   
       void
       removeSegment(void);
   
       integer
       countSegment(void) const;
   
       bool
       containTriangle(void) const;
   
       bool
       areTriangle(void) const;
   
       bool
       isTriangle(
           size_t i 
       ) const;
   
       void
       removeTriangle(void);
   
       integer
       countTriangle(void) const;
   
       bool
       containDisk(void) const;
   
       bool
       areDisk(void) const;
   
       bool
       isDisk(
           size_t i 
       ) const;
   
       void
       removeDisk(void);
   
       integer
       countDisk(void) const;
   
       bool
       containBall(void) const;
   
       bool
       areBall(void) const;
   
       bool
       isBall(
           size_t i 
       ) const;
   
       void
       removeBall(void);
   
       integer
       countBall(void) const;
   
       bool
       containDegenerated(
           real tolerance = EPSILON 
       ) const;
   
       bool
       areDegenerated(
           real tolerance = EPSILON 
       ) const;
   
       bool
       isDegenerated(
           size_t i,                
           real tolerance = EPSILON 
       ) const;
   
       void
       removeDegenerated(
           real tolerance = EPSILON 
       );
   
       integer
       countDegenerated(
           real tolerance = EPSILON 
       ) const;
   
       bool
       containClampable(void) const;
   
       bool
       areClampable(void) const;
   
       bool
       isClampable(
           size_t i 
       ) const;
   
       void
       removeClampable(void);
   
       integer
       countClampable(void) const;
   
       bool
       containNonClampable(void) const;
   
       bool
       areNonClampable(void) const;
   
       bool
       isNonClampable(
           size_t i 
       ) const;
   
       void
       removeNonClampable(void);
   
       integer
       countNonClampable(void) const;
   
       integer
       size(void) const;
   
       std::map<std::string, integer>
       count(
           real tolerance = EPSILON 
       ) const;
   
       void
       clamp(
           aabb::vecptr &boxes 
       ) const;
   
       void buildAABBtree(void);
   
       AABBtree::ptr const &
       ptrAABBtree(void);
   
       bool
       intersection(
           collection &entities,  
           collection &candidates 
       ) const;
   
       bool intersection(
           AABBtree::ptr const &AABBtree, 
           collection &entities           
       ) const;
   
       bool
       intersection(
           aabb::vecptr const &boxes, 
           collection &entities       
       ) const;
   
       bool
       intersection(
           aabb::ptr const box, 
           collection &entities 
       ) const;
   
       void
       intersection(
           collection &entities,    
           real tolerance = EPSILON 
       ) const;
   
     }; // class collection
   
   } // namespace acme
   
   #endif
   
   ///
