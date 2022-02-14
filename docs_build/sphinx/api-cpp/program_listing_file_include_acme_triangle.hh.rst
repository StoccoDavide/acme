
.. _program_listing_file_include_acme_triangle.hh:

Program Listing for File acme_triangle.hh
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_triangle.hh>` (``include/acme_triangle.hh``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
   (***********************************************************************)
   (*                                                                     *)
   (* The ACME project                                                    *)
   (*                                                                     *)
   (* Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *)
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
   
   
   #pragma once
   
   #ifndef INCLUDE_ACME_TRIANGLE
   #define INCLUDE_ACME_TRIANGLE
   
   #include "acme.hh"
   #include "acme_aabb.hh"
   #include "acme_plane.hh"
   #include "acme_point.hh"
   #include "acme_segment.hh"
   
   namespace acme
   {
   
     /*\
      |   _        _                   _
      |  | |_ _ __(_) __ _ _ __   __ _| | ___
      |  | __| '__| |/ _` | '_ \ / _` | |/ _ \
      |  | |_| |  | | (_| | | | | (_| | |  __/
      |   \__|_|  |_|\__,_|_| |_|\__, |_|\___|
      |                          |___/
     \*/
   
   
     class triangle : public entity
     {
     private:
       point m_vertex[3] = {NAN_POINT, NAN_POINT, NAN_POINT}; 
   
     public:
       ~triangle(void);
   
       triangle(void);
   
       triangle(triangle const &) = default;
   
       triangle(triangle &&) = default;
   
       triangle(
         real vertex0_x, 
         real vertex0_y, 
         real vertex0_z, 
         real vertex1_x, 
         real vertex1_y, 
         real vertex1_z, 
         real vertex2_x, 
         real vertex2_y, 
         real vertex2_z  
       );
   
       triangle(
         point const &vertex0, 
         point const &vertex1, 
         point const &vertex2  
       );
   
       triangle(
         point const vertex[3] 
       );
   
       triangle &
       operator=(
         triangle const &triangle_in 
       );
   
       bool
       isApprox(
         triangle const &triangle_in,        
         real            tolerance = EPSILON 
       ) const;
   
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
   
       point
       centroid(void) const;
   
       segment
       edge(
         size_t i 
       ) const;
   
       vec3
       normal(void) const;
   
       void
       swap(
         size_t i, 
         size_t j  
       );
   
       real
       perimeter(void)
         const;
   
       real
       area(void) const;
   
       void
       barycentric(
         point const &point_in, 
         real        &u,        
         real        &v,        
         real        &w         
       ) const;
   
       plane
       layingPlane(void) const;
   
       void
       translate(
         vec3 const &vector_in 
         ) override;
   
       void
       transform(
         affine const &affine_in 
         ) override;
   
       bool
       isInside(
         point const &point_in,           
         real         tolerance = EPSILON 
       ) const;
   
       bool
       isDegenerated(
         real tolerance = EPSILON 
       ) const override;
   
       integer
       level(void) const override
       {
         return 7;
       }
   
       std::string
       type(void) const override
       {
         return "triangle";
       }
   
       bool
       isNone(void) const override
       {
         return false;
       }
   
       bool
       isPoint(void) const override
       {
         return false;
       }
   
       bool
       isLine(void) const override
       {
         return false;
       }
   
       bool
       isRay(void) const override
       {
         return false;
       }
   
       bool
       isPlane(void) const override
       {
         return false;
       }
   
       bool
       isSegment(void) const override
       {
         return false;
       }
   
       bool
       isTriangle(void) const override
       {
         return true;
       }
   
       bool
       isDisk(void) const override
       {
         return false;
       }
   
       bool
       isBall(void) const override
       {
         return false;
       }
   
       bool
       isClampable(void) const override
       {
         return true;
       }
   
       bool
       isNonClampable(void) const override
       {
         return false;
       }
   
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
   
     }; // class triangle
   
     static triangle const NAN_TRIANGLE       = triangle(NAN_POINT, NAN_POINT, NAN_POINT); 
     static triangle       THROWAWAY_TRIANGLE = triangle(NAN_TRIANGLE);                    
   
   } // namespace acme
   
   #endif
   
