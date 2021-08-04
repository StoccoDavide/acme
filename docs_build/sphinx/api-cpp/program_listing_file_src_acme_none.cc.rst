
.. _program_listing_file_src_acme_none.cc:

Program Listing for File acme_none.cc
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_acme_none.cc>` (``src/acme_none.cc``)

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
   
   
   #include "acme_none.hh"
   
   namespace acme
   {
   
     /*\
      |                          
      |   _ __   ___  _ __   ___ 
      |  | '_ \ / _ \| '_ \ / _ \
      |  | | | | (_) | | | |  __/
      |  |_| |_|\___/|_| |_|\___|
      |                          
     \*/
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     bool
     none::clamp(
         vec3 &min,
         vec3 &max)
         const
     {
       return this->isClampable();
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     bool
     none::clamp(
         real &min_x,
         real &min_y,
         real &min_z,
         real &max_x,
         real &max_y,
         real &max_z)
         const
     {
       return this->isClampable();
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
   } // namespace acme
   
   ///
