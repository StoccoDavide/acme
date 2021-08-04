
.. _program_listing_file_include_acme_collinear.hh:

Program Listing for File acme_collinear.hh
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_collinear.hh>` (``include/acme_collinear.hh``)

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
   
   
   #ifndef INCLUDE_ACME_COLLINEAR
   #define INCLUDE_ACME_COLLINEAR
   
   #include "acme.hh"
   #include "acme_line.hh"
   #include "acme_parallel.hh"
   #include "acme_ray.hh"
   #include "acme_segment.hh"
   
   namespace acme
   {
   
     /*\
      |    ____      _ _ _                       
      |   / ___|___ | | (_)_ __   ___  __ _ _ __ 
      |  | |   / _ \| | | | '_ \ / _ \/ _` | '__|
      |  | |__| (_) | | | | | | |  __/ (_| | |   
      |   \____\___/|_|_|_|_| |_|\___|\__,_|_|   
      |                                          
     \*/
   
     bool
     isCollinear(
         entity const *entity0_in, 
         entity const *entity1_in, 
         real tolerance = EPSILON  
     );
   
     bool
     isCollinear(
         line const &line0_in,    
         line const &line1_in,    
         real tolerance = EPSILON 
     );
   
     bool
     isCollinear(
         ray const &ray0_in,      
         ray const &ray1_in,      
         real tolerance = EPSILON 
     );
   
     bool
     isCollinear(
         segment const &segment0_in, 
         segment const &segment1_in, 
         real tolerance = EPSILON    
     );
   
     bool
     isCollinear(
         line const &line_in,     
         ray const &ray_in,       
         real tolerance = EPSILON 
     );
   
     bool
     isCollinear(
         line const &line_in,       
         segment const &segment_in, 
         real tolerance = EPSILON   
     );
   
     bool
     isCollinear(
         ray const &ray_in,         
         segment const &segment_in, 
         real tolerance = EPSILON   
     );
   
   } // namespace acme
   
   #endif
   
   ///
