
.. _program_listing_file_include_acme_segment.hh:

Program Listing for File acme_segment.hh
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_segment.hh>` (``include/acme_segment.hh``)

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
   
   
   #ifndef INCLUDE_ACME_SEGMENT
   #define INCLUDE_ACME_SEGMENT
   
   #include "acme.hh"
   #include "acme_aabb.hh"
   #include "acme_point.hh"
   
   namespace acme
   {
   
     /*\
      |                                       _   
      |   ___  ___  __ _ _ __ ___   ___ _ __ | |_ 
      |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __|
      |  \__ \  __/ (_| | | | | | |  __/ | | | |_ 
      |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|
      |            |___/                          
     \*/
   
   
     class segment : public entity
     {
     private:
       point m_vertex[2]; 
   
     public:
       ~segment() {}
   
       segment(segment const &) = default;
   
       segment(segment &&) = default;
   
       segment() {}
   
       segment(
           real vertex0_x, 
           real vertex0_y, 
           real vertex0_z, 
           real vertex1_x, 
           real vertex1_y, 
           real vertex1_z  
       );
   
       segment(
           point const &vertex0, 
           point const &vertex1  
       );
   
       segment(
           point const vertex[2] 
       );
   
       segment &
       operator=(
           segment const &segment_in 
       );
   
       bool
       isApprox(
           segment const &segment_in, 
           real tolerance = EPSILON   
       ) const;
   
       point
       centroid(void) const;
   
       point const &
       vertex(
           size_t i 
       ) const;
   
       point &
       vertex(
           size_t i 
       );
   
       point const &
       operator[](
           size_t i 
       ) const;
   
       point &
       operator[](
           size_t i 
       );
   
       vec3
       toVector(void) const;
   
       vec3
       toUnitVector(void) const;
   
       void
       swap(void);
   
       real
       length(void) const;
   
       void
       translate(
           vec3 const &vector_in 
           ) override;
   
       void
       transform(
           affine const &affine_in 
           ) override;
   
       // Check whether the point is inside the segment
       bool
       isInside(
           point const &point_in,   
           real tolerance = EPSILON 
       ) const;
   
       bool
       isDegenerated(
           real tolerance = EPSILON 
       ) const override;
   
       integer level(void) const override { return 6; }
   
       std::string type(void) const override { return "segment"; }
   
       bool isNone(void) const override { return false; }
   
       bool isPoint(void) const override { return false; }
   
       bool isLine(void) const override { return false; }
   
       bool isRay(void) const override { return false; }
   
       bool isPlane(void) const override { return false; }
   
       bool isSegment(void) const override { return true; }
   
       bool isTriangle(void) const override { return false; }
   
       bool isDisk(void) const override { return false; }
   
       bool isBall(void) const override { return false; }
   
       bool isClampable(void) const override { return true; }
   
       bool isNonClampable(void) const override { return false; }
   
       bool
       clamp(
           vec3 &min, 
           vec3 &max  
       ) const override;
   
       bool
       clamp(
           real &min_x, 
           real &min_y, 
           real &min_z, 
           real &max_x, 
           real &max_y, 
           real &max_z  
       ) const override;
   
     }; // class segment
   
     static segment const NAN_SEGMENT = segment(NAN_POINT, NAN_POINT); 
     static segment THROWAWAY_SEGMENT = segment(NAN_SEGMENT);          
   
   } // namespace acme
   
   #endif
   
   ///
