
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_intersection.hh:

Program Listing for File acme_intersection.hh
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_intersection.hh>` (``/Users/davide/Documents/Git/acme/include/acme_intersection.hh``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /*
   (***********************************************************************)
   (*                                                                     *)
   (* The ACME project - Release Version 0.0.0                            *)
   (*                                                                     *)
   (* Copyright (c) 2020 Davide Stocco, All Rights Reserved.              *)
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
   (***********************************************************************)
   */
   
   
   #ifndef INCLUDE_ACME_INTERSECTION
   #define INCLUDE_ACME_INTERSECTION
   
   #include "acme.hh"
   #include "acme_math.hh"
   #include "acme_line.hh"
   #include "acme_ray.hh"
   #include "acme_plane.hh"
   #include "acme_segment.hh"
   #include "acme_triangle.hh"
   #include "acme_box.hh"
   #include "acme_circle.hh"
   
   namespace acme
   {
   
     /*\
      |   ___       _                          _   _             
      |  |_ _|_ __ | |_ ___ _ __ ___  ___  ___| |_(_) ___  _ __  
      |   | || '_ \| __/ _ \ '__/ __|/ _ \/ __| __| |/ _ \| '_ \ 
      |   | || | | | ||  __/ |  \__ \  __/ (__| |_| | (_) | | | |
      |  |___|_| |_|\__\___|_|  |___/\___|\___|\__|_|\___/|_| |_|
      |                                                          
     \*/
   
     bool
     intersection(
         line const &line0, 
         line const &line1, 
         vec3 &point        
     );
   
     bool
     intersection(
         ray const &ray0, 
         ray const &ray1, 
         vec3 &point      
     );
   
     bool
     intersection(
         segment const &segment0, 
         segment const &segment1, 
         vec3 &point              
     );
   
     bool
     intersection(
         box const &box0, 
         box const &box1, 
         box &box         
     );
   
     bool
     intersection(
         plane const &plane0, 
         plane const &plane1, 
         plane const &plane2, 
         vec3 &point          
     );
   
     bool
     intersection(
         plane const &plane0, 
         plane const &plane1, 
         line &line           
     );
   
     bool
     intersection(
         ray const &ray,     
         plane const &plane, 
         vec3 &point         
     );
   
     bool intersection(
         line const &line,   
         plane const &plane, 
         vec3 &point         
     );
   
     bool
     intersection(
         segment const &segment, 
         plane const &plane,     
         vec3 &point             
     );
   
     bool
     intersection(
         ray const &ray,           
         triangle const &triangle, 
         vec3 &point               
     );
   
     bool
     intersection(
         line const &line,         
         triangle const &triangle, 
         vec3 &point               
     );
   
     bool
     intersection(
         plane const &plane,       
         triangle const &triangle, 
         segment &segment          
     );
   
     bool
     intersection(
         line const &line,     
         circle const &circle, 
         vec3 &point           
     );
   
     bool
     intersection(
         ray const &ray,       
         circle const &circle, 
         vec3 &point           
     );
   
     bool
     intersection(
         segment const &segment, 
         circle const &circle,   
         vec3 &point             
     );
   
     bool
     intersection(
         segment const &segment0, 
         segment const &segment1, 
         segment &segment         
     );
   
     bool
     intersection(
         line const &line,          
         segment const &segment_in, 
         segment &segment_out       
     );
   
     bool
     intersection(
         ray const &ray,            
         segment const &segment_in, 
         segment &segment_out       
     );
   
     bool
     intersection(
         line const &line,     
         circle const &circle, 
         segment &segment      
     );
   
     bool
     intersection(
         ray const &ray,       
         circle const &circle, 
         segment &segment      
     );
   
     bool
     intersection(
         plane const &plane,   
         circle const &circle, 
         segment &segment      
     );
   
     bool
     intersection(
         segment const &segment_in, 
         circle const &circle,      
         segment &segment_out       
     );
   
     bool
     intersection(
         circle const &circle,     
         triangle const &triangle, 
         segment &segment          
     );
   
   } // namespace acme
   
   #endif
   
   ///
