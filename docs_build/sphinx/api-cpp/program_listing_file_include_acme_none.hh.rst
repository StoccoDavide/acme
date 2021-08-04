
.. _program_listing_file_include_acme_none.hh:

Program Listing for File acme_none.hh
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_none.hh>` (``include/acme_none.hh``)

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
   
   
   #ifndef INCLUDE_ACME_NONE
   #define INCLUDE_ACME_NONE
   
   #include "acme.hh"
   #include "acme_point.hh"
   
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
   
   
     class none : public entity
     {
     public:
       ~none() {}
   
       none() {}
   
       void
       translate(
           vec3 const &vector_in 
           ) override{};
   
       void
       transform(
           affine const &affine_in 
           ) override{};
   
       bool isDegenerated(
           real tolerance = EPSILON 
       ) const override
       {
         return true;
       };
   
       integer level(void) const override { return 1; }
   
       std::string type(void) const override { return "none"; }
   
       bool isNone(void) const override { return true; }
   
       bool isPoint(void) const override { return false; }
   
       bool isLine(void) const override { return false; }
   
       bool isRay(void) const override { return false; }
   
       bool isPlane(void) const override { return false; }
   
       bool isSegment(void) const override { return false; }
   
       bool isTriangle(void) const override { return false; }
   
       bool isDisk(void) const override { return false; }
   
       bool isBall(void) const override { return false; }
   
       bool isClampable(void) const override { return false; }
   
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
   
     }; // class none
   
     static none THROWAWAY_NONE = none(); 
   
   } // namespace acme
   
   #endif
   
   ///
