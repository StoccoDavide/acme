
.. _program_listing_file_src_acme_entity.cc:

Program Listing for File acme_entity.cc
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_acme_entity.cc>` (``src/acme_entity.cc``)

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
   
   
   #include "acme_entity.hh"
   
   namespace acme
   {
   
     /*\
      |              _   _ _
      |    ___ _ __ | |_(_) |_ _   _
      |   / _ \ '_ \| __| | __| | | |
      |  |  __/ | | | |_| | |_| |_| |
      |   \___|_| |_|\__|_|\__|\__, |
      |                        |___/
     \*/
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     entity::rotate(
         real angle,
         vec3 const &axis)
     {
       affine tranformation(IDENTITY_MAT4);
       tranformation.rotate(angleaxis(angle, axis));
       this->transform(tranformation);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     bool
     entity::isEntity(void)
         const
     {
       return true;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
   } // namespace acme
   
   ///
