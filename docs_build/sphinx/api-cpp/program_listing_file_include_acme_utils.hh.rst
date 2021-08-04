
.. _program_listing_file_include_acme_utils.hh:

Program Listing for File acme_utils.hh
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_utils.hh>` (``include/acme_utils.hh``)

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
   
   
   #ifndef INCLUDE_ACME_UTILS
   #define INCLUDE_ACME_UTILS
   
   #include "acme.hh"
   #include "acme_aabb.hh"
   #include "acme_disk.hh"
   #include "acme_line.hh"
   #include "acme_plane.hh"
   #include "acme_point.hh"
   #include "acme_ray.hh"
   #include "acme_segment.hh"
   #include "acme_ball.hh"
   #include "acme_triangle.hh"
   
   namespace acme
   {
     /*\
      |         _   _ _ _ _   _           
      |   _   _| |_(_) (_) |_(_) ___  ___ 
      |  | | | | __| | | | __| |/ _ \/ __|
      |  | |_| | |_| | | | |_| |  __/\__ \
      |   \__,_|\__|_|_|_|\__|_|\___||___/
      |                                   
     \*/
   
     out_stream &
     operator<<(
         out_stream &os, 
         vec3 const &obj 
     );
   
     out_stream &
     operator<<(
         out_stream &os,  
         point const &obj 
     );
   
     out_stream &
     operator<<(
         out_stream &os, 
         line const &obj 
     );
   
     out_stream &
     operator<<(
         out_stream &os, 
         ray const &obj  
     );
   
     out_stream &
     operator<<(
         out_stream &os,  
         plane const &obj 
     );
   
     out_stream &
     operator<<(
         out_stream &os,    
         segment const &obj 
     );
   
     out_stream &
     operator<<(
         out_stream &os, 
         aabb const &obj 
     );
   
     out_stream &
     operator<<(
         out_stream &os,     
         triangle const &obj 
     );
   
     out_stream &
     operator<<(
         out_stream &os, 
         disk const &obj 
     );
   
     out_stream &
     operator<<(
         out_stream &os,   
         ball const &obj 
     );
   
     out_stream &
     operator<<(
         out_stream &os,   
         affine const &obj 
     );
   
   } // namespace acme
   
   #endif
   
   ///
