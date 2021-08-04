
.. _program_listing_file_include_acme_aabb.hh:

Program Listing for File acme_aabb.hh
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_aabb.hh>` (``include/acme_aabb.hh``)

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
   
   
   #ifndef INCLUDE_ACME_AABB
   #define INCLUDE_ACME_AABB
   
   #include "acme.hh"
   #include "acme_point.hh"
   
   namespace acme
   {
   
     /*\
      |               _     _     
      |    __ _  __ _| |__ | |_   
      |   / _` |/ _` | '_ \| '_ \ 
      |  | (_| | (_| | |_) | |_) |
      |   \__,_|\__,_|_.__/|_.__/ 
      |                           
     \*/
   
   
     class aabb
     {
     public:
       typedef std::shared_ptr<aabb const> ptr; 
       typedef std::pair<ptr, ptr> pairptr;     
       typedef std::vector<ptr> vecptr;         
       typedef std::vector<pairptr> vecpairptr; 
   
     private:
       point m_min;   
       point m_max;   
       integer m_id;  
       integer m_pos; 
   
     public:
       ~aabb() {}
   
       aabb(const aabb &) = default;
   
       aabb(aabb &&) = default;
   
       aabb();
   
       aabb(
           real min_x,      
           real min_y,      
           real min_z,      
           real max_x,      
           real max_y,      
           real max_z,      
           integer id = 0,  
           integer ipos = 0 
       );
   
       aabb(
           point const &min, 
           point const &max, 
           integer id = 0,   
           integer ipos = 0  
       );
   
       aabb(
           std::vector<aabb::ptr> const &boxes, 
           integer id = 0,                      
           integer ipos = 0                     
       );
   
       aabb &operator=(
           aabb const &aabb_in 
       );
   
       void
       clear(void);
   
       bool
       isApprox(
           aabb const &aabb_in,     
           real tolerance = EPSILON 
       ) const;
   
       bool
       checkMaxMin(void) const;
   
       bool
       updateMaxMin(void);
   
       point const &
       min(void) const;
   
       point &
       min(void);
   
       real const &
       min(
           size_t i 
       ) const;
   
       real &
       min(
           size_t i 
       );
   
       void
       min(
           real x, 
           real y, 
           real z  
       );
   
       point const &
       max(void) const;
   
       point &
       max(void);
   
       real const &
       max(
           size_t i 
       ) const;
   
       real &
       max(
           size_t i 
       );
   
       void
       max(
           real x, 
           real y, 
           real z  
       );
   
       bool
       intersects(
           aabb const &aabb_in 
       ) const;
   
       void
       merged(
           aabb::vecptr const &boxes 
       );
   
       real
       centerDistance(
           point const &point_in 
       ) const;
   
       real
       exteriorDistance(
           point const &point_in 
       ) const;
   
       void
       clamp(
           point const &point0_in, 
           point const &point1_in, 
           point const &point2_in  
       );
   
       void
       clamp(
           point const point_in[3] 
       );
   
       integer const &
       id(void) const;
   
       integer &
       id(void);
   
       integer const &
       pos(void) const;
   
       integer &
       pos(void);
   
       void
       translate(
           point const &vector_in 
       );
   
       // Check whether the point is inside the aabb
       bool
       isInside(
           point const &point_in,   
           real tolerance = EPSILON 
       ) const;
   
       bool
       isDegenerated(
           real tolerance = EPSILON 
       ) const;
   
     }; //class aabb
   
     static aabb const NAN_AABB = aabb(NAN_POINT, NAN_POINT, 0, 0); 
     static aabb THROWAWAY_AABB = aabb(NAN_AABB);                   
   
   } // namespace acme
   
   #endif
   
   ///
