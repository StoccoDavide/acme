
.. _program_listing_file_include_acme_math.hh:

Program Listing for File acme_math.hh
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_math.hh>` (``include/acme_math.hh``)

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
   
   
   #pragma once
   
   #ifndef INCLUDE_ACME_MATH
   #define INCLUDE_ACME_MATH
   
   #include <cmath>
   
   #include "acme.hh"
   
   namespace acme
   {
   
     /*\
      |   __  __       _   _
      |  |  \/  | __ _| |_| |__
      |  | |\/| |/ _` | __| '_ \
      |  | |  | | (_| | |_| | | |
      |  |_|  |_|\__,_|\__|_| |_|
      |
     \*/
   
     bool
     isApprox(
       real value0_in,          
       real value1_in,          
       real tolerance = EPSILON 
     );
   
     void
     transform(
       vec3         &vector, 
       affine const &matrix  
     );
   
     real
     angle(
       vec3 const vector0_in, 
       vec3 const vector1_in  
     );
   
   } // namespace acme
   
   #endif
   
