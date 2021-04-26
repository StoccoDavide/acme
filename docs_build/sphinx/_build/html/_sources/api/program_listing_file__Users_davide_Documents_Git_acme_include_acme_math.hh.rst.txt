
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_math.hh:

Program Listing for File acme_math.hh
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_math.hh>` (``/Users/davide/Documents/Git/acme/include/acme_math.hh``)

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
   
   
   #ifndef INCLUDE_ACME_MATH
   #define INCLUDE_ACME_MATH
   
   #include "acme.hh"
   
   #include <Eigen/Geometry>
   
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
   
     real_type
     infinity(void);
   
     real_type
     epsilon(void);
   
     real_type
     sqr(
         real_type input 
     );
   
     real_type
     cub(
         real_type input 
     );
   
     real_type
     sqrt(
         real_type input 
     );
   
     real_type
     pow(
         real_type base,    
         real_type exponent 
     );
   
     real_type
     abs(
         real_type input 
     );
   
     real_type
     max(
         real_type input0, 
         real_type input1  
     );
   
     real_type
     min(
         real_type input0, 
         real_type input1  
   
     );
   
     real_type
     max(
         real_type input0, 
         real_type input1, 
         real_type input2  
     );
   
     real_type
     min(
         real_type input0, 
         real_type input1, 
         real_type input2  
     );
   
     /*\
      |   _____     _                                        _              
      |  |_   _| __(_) __ _  ___  _ __   ___  _ __ ___   ___| |_ _ __ _   _ 
      |    | || '__| |/ _` |/ _ \| '_ \ / _ \| '_ ` _ \ / _ \ __| '__| | | |
      |    | || |  | | (_| | (_) | | | | (_) | | | | | |  __/ |_| |  | |_| |
      |    |_||_|  |_|\__, |\___/|_| |_|\___/|_| |_| |_|\___|\__|_|   \__, |
      |               |___/                                           |___/ 
     \*/
   
     real_type
     sin(
         real_type input 
     );
   
     real_type
     cos(
         real_type input 
     );
   
     real_type
     tan(
         real_type input 
     );
   
     real_type
     asin(
         real_type input 
     );
   
     real_type
     acos(
         real_type input 
     );
   
     real_type
     atan(
         real_type input 
     );
   
     real_type
     atan2(
         real_type input0, 
         real_type input1  
     );
   
     real_type
     clamp(
         real_type input, 
         real_type low,   
         real_type high   
     );
   
     bool
     isApprox(
         real_type input0,             
         real_type input1,             
         real_type tolerance = Epsilon 
     );
   
     bool
     isApprox(
         vec3 const &input0,           
         vec3 const &input1,           
         real_type tolerance = Epsilon 
     );
   
     bool
     isApprox(
         mat3 const &input0,           
         mat3 const &input1,           
         real_type tolerance = Epsilon 
     );
   
     bool
     isDegenerated(
         vec3 const &input,            
         real_type tolerance = Epsilon 
     );
   
     bool
     isParallel(
         vec3 const &input0,           
         vec3 const &input1,           
         real_type tolerance = Epsilon 
     );
   
     bool
     isOrthonormal(
         mat3 const &input,            
         real_type tolerance = Epsilon 
     );
   
     angleaxis
     rotate(
         real_type angle, 
         vec3 const &axis 
   
     );
   
     angleaxis
     rotate(
         real_type angle,        
         std::string const &axis 
     );
   
     real_type
     angle(
         vec3 const &input0, 
         vec3 const &input1  
     );
   
     void
     eulerAngles(
         mat3 const &rotation, 
         size_t i,             
         size_t j,             
         size_t k,             
         vec3 &angles          
     );
   
     /*\
      |   _____                     __                      
      |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
      |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
      |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
      |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
      |                                                     
     \*/
   
     void
     transformVector(
         vec3 &vector,        
         affine const &matrix 
     );
   
     void
     transformPoint(
         vec3 &vector,        
         affine const &matrix 
     );
   
   } // namespace acme
   
   #endif
   
