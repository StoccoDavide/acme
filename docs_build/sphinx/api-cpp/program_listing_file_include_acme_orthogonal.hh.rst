
.. _program_listing_file_include_acme_orthogonal.hh:

Program Listing for File acme_orthogonal.hh
===========================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_orthogonal.hh>` (``include/acme_orthogonal.hh``)

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
   
   
   #ifndef INCLUDE_ACME_ORTHOGONAL
   #define INCLUDE_ACME_ORTHOGONAL
   
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
      |    ___       _   _                                   _ 
      |   / _ \ _ __| |_| |__   ___   __ _  ___  _ __   __ _| |
      |  | | | | '__| __| '_ \ / _ \ / _` |/ _ \| '_ \ / _` | |
      |  | |_| | |  | |_| | | | (_) | (_| | (_) | | | | (_| | |
      |   \___/|_|   \__|_| |_|\___/ \__, |\___/|_| |_|\__,_|_|
      |                              |___/                     
     \*/
   
     bool
     isOrthogonal(
         entity const *entity0_in, 
         entity const *entity1_in, 
         real tolerance = EPSILON  
     );
   
     bool
     isOrthogonal(
         vec3 const &vector0_in,  
         vec3 const &vector1_in,  
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         vec3 const &vector_in,   
         line const &line_in,     
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         vec3 const &vector_in,   
         ray const &ray_in,       
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         vec3 const &vector_in,   
         plane const &plane_in,   
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         vec3 const &vector_in,     
         segment const &segment_in, 
         real tolerance = EPSILON   
     );
   
     bool
     isOrthogonal(
         vec3 const &vector_in,       
         triangle const &triangle_in, 
         real tolerance = EPSILON     
     );
   
     bool
     isOrthogonal(
         vec3 const &vector_in,   
         disk const &disk_in,     
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         line const &line0_in,    
         line const &line1_in,    
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         ray const &ray0_in,      
         ray const &ray1_in,      
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         plane const &plane0_in,  
         plane const &plane1_in,  
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         segment const &segment0_in, 
         segment const &segment1_in, 
         real tolerance = EPSILON    
     );
   
     bool
     isOrthogonal(
         triangle const &triangle0_in, 
         triangle const &triangle1_in, 
         real tolerance = EPSILON      
     );
   
     bool
     isOrthogonal(
         disk const &disk0_in,    
         disk const &disk1_in,    
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         line const &line_in,     
         ray const &ray_in,       
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         line const &line_in,     
         plane const &plane_in,   
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         line const &line_in,       
         segment const &segment_in, 
         real tolerance = EPSILON   
     );
   
     bool
     isOrthogonal(
         line const &line_in,         
         triangle const &triangle_in, 
         real tolerance = EPSILON     
     );
   
     bool
     isOrthogonal(
         line const &line_in,     
         disk const &disk_in,     
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         ray const &ray_in,       
         plane const &plane_in,   
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         ray const &ray_in,         
         segment const &segment_in, 
         real tolerance = EPSILON   
     );
   
     bool
     isOrthogonal(
         ray const &ray_in,           
         triangle const &triangle_in, 
         real tolerance = EPSILON     
     );
   
     bool
     isOrthogonal(
         ray const &ray_in,       
         disk const &disk_in,     
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         plane const &plane_in,     
         segment const &segment_in, 
         real tolerance = EPSILON   
     );
   
     bool
     isOrthogonal(
         plane const &plane_in,       
         triangle const &triangle_in, 
         real tolerance = EPSILON     
     );
   
     bool
     isOrthogonal(
         plane const &plane_in,   
         disk const &disk_in,     
         real tolerance = EPSILON 
     );
   
     bool
     isOrthogonal(
         segment const &segment_in,   
         triangle const &triangle_in, 
         real tolerance = EPSILON     
     );
   
     bool
     isOrthogonal(
         segment const &segment_in, 
         disk const &disk_in,       
         real tolerance = EPSILON   
     );
   
     bool
     isOrthogonal(
         triangle const &triangle_in, 
         disk const &disk_in,         
         real tolerance = EPSILON     
     );
   
   } // namespace acme
   
   #endif
   
   ///
