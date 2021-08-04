
.. _program_listing_file_include_acme_coplanar.hh:

Program Listing for File acme_coplanar.hh
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_coplanar.hh>` (``include/acme_coplanar.hh``)

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
   
   
   #ifndef INCLUDE_ACME_COPLANAR
   #define INCLUDE_ACME_COPLANAR
   
   #include "acme.hh"
   #include "acme_aabb.hh"
   #include "acme_disk.hh"
   #include "acme_line.hh"
   #include "acme_parallel.hh"
   #include "acme_plane.hh"
   #include "acme_ray.hh"
   #include "acme_segment.hh"
   #include "acme_triangle.hh"
   
   namespace acme
   {
   
     /*\
      |    ____            _                        
      |   / ___|___  _ __ | | __ _ _ __   __ _ _ __ 
      |  | |   / _ \| '_ \| |/ _` | '_ \ / _` | '__|
      |  | |__| (_) | |_) | | (_| | | | | (_| | |   
      |   \____\___/| .__/|_|\__,_|_| |_|\__,_|_|   
      |             |_|                             
     \*/
   
     bool
     isCoplanar(
         entity const *entity0_in, 
         entity const *entity1_in, 
         real tolerance = EPSILON  
     );
   
     bool
     isCoplanar(
         line const &line0_in,    
         line const &line1_in,    
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         ray const &ray0_in,      
         ray const &ray1_in,      
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         plane const &plane0_in,  
         plane const &plane1_in,  
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         segment const &segment0_in, 
         segment const &segment1_in, 
         real tolerance = EPSILON    
     );
   
     bool
     isCoplanar(
         triangle const &triangle0_in, 
         triangle const &triangle1_in, 
         real tolerance = EPSILON      
     );
   
     bool
     isCoplanar(
         disk const &disk0_in,    
         disk const &disk1_in,    
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         line const &line_in,     
         ray const &ray_in,       
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         line const &line_in,     
         plane const &plane_in,   
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         line const &line_in,       
         segment const &segment_in, 
         real tolerance = EPSILON   
     );
   
     bool
     isCoplanar(
         line const &line_in,         
         triangle const &triangle_in, 
         real tolerance = EPSILON     
     );
   
     bool
     isCoplanar(
         line const &line_in,     
         disk const &disk_in,     
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         ray const &ray_in,       
         plane const &plane_in,   
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         ray const &ray_in,         
         segment const &segment_in, 
         real tolerance = EPSILON   
     );
   
     bool
     isCoplanar(
         ray const &ray_in,           
         triangle const &triangle_in, 
         real tolerance = EPSILON     
     );
   
     bool
     isCoplanar(
         ray const &ray_in,       
         disk const &disk_in,     
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         plane const &plane_in,     
         segment const &segment_in, 
         real tolerance = EPSILON   
     );
   
     bool
     isCoplanar(
         plane const &plane_in,       
         triangle const &triangle_in, 
         real tolerance = EPSILON     
     );
   
     bool
     isCoplanar(
         plane const &plane_in,   
         disk const &disk_in,     
         real tolerance = EPSILON 
     );
   
     bool
     isCoplanar(
         segment const &segment_in,   
         triangle const &triangle_in, 
         real tolerance = EPSILON     
     );
   
     bool
     isCoplanar(
         segment const &segment_in, 
         disk const &disk_in,       
         real tolerance = EPSILON   
     );
   
     bool
     isCoplanar(
         triangle const &triangle_in, 
         disk const &disk_in,         
         real tolerance = EPSILON     
     );
   
   } // namespace acme
   
   #endif
   
   ///
