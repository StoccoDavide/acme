
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_utilities.hh:

Program Listing for File acme_utilities.hh
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_utilities.hh>` (``/Users/davide/Documents/Git/acme/include/acme_utilities.hh``)

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
   
   
   #ifndef INCLUDE_ACME_UTILTIES
   #define INCLUDE_ACME_UTILTIES
   
   #include "acme.hh"
   #include "acme_math.hh"
   #include "acme_ray.hh"
   #include "acme_line.hh"
   #include "acme_plane.hh"
   #include "acme_segment.hh"
   #include "acme_triangle.hh"
   #include "acme_box.hh"
   #include "acme_circle.hh"
   
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
   
     ostream_type &
     operator<<(
         ostream_type &os, 
         line const &obj   
     );
   
     ostream_type &
     operator<<(
         ostream_type &os, 
         ray const &obj    
     );
   
     ostream_type &
     operator<<(
         ostream_type &os, 
         plane const &obj  
     );
   
     ostream_type &
     operator<<(
         ostream_type &os,  
         segment const &obj 
     );
   
     ostream_type &
     operator<<(
         ostream_type &os, 
         box const &obj    
     );
   
     ostream_type &
     operator<<(
         ostream_type &os,   
         triangle const &obj 
     );
   
     ostream_type &
     operator<<(
         ostream_type &os, 
         circle const &obj 
     );
   
   } // namespace acme
   
   #endif
   
   ///
