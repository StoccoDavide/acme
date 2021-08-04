
.. _program_listing_file_include_acme.hh:

Program Listing for File acme.hh
================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme.hh>` (``include/acme.hh``)

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
   
   
   #ifndef INCLUDE_ACME
   #define INCLUDE_ACME
   
   // Print acme errors
   #ifndef ACME_ERROR
   #define ACME_ERROR(MSG)                  \
     {                                      \
       std::ostringstream ost;              \
       ost << MSG;                          \
       throw std::runtime_error(ost.str()); \
     }
   #endif
   
   // Check for acme errors
   #ifndef ACME_ASSERT
   #define ACME_ASSERT(COND, MSG) \
     if (!(COND))                 \
     ACME_ERROR(MSG)
   #endif
   
   // Standard libraries
   #include <algorithm>
   #include <cassert>
   #include <cstddef>
   #include <iomanip>
   #include <iostream>
   #include <iterator>
   #include <limits>
   #include <memory>
   #include <vector>
   
   // Eigen libraries
   #include <Eigen/Dense>
   
   namespace acme
   {
   
     /*\
      |   _____                     _       __     
      |  |_   _|   _ _ __   ___  __| | ___ / _|___ 
      |    | || | | | '_ \ / _ \/ _` |/ _ \ |_/ __|
      |    | || |_| | |_) |  __/ (_| |  __/  _\__ \
      |    |_| \__, | .__/ \___|\__,_|\___|_| |___/
      |        |___/|_|                            
     \*/
   
     typedef double real;             
     typedef int integer;             
     typedef std::ostream out_stream; 
   
     typedef Eigen::Matrix<real, 2, 1> vec2;                           
     typedef Eigen::Matrix<real, 2, 2> mat2;                           
     typedef Eigen::Matrix<real, 3, 1> vec3;                           
     typedef Eigen::Matrix<real, 3, 3> mat3;                           
     typedef Eigen::Matrix<real, 4, 1> vec4;                           
     typedef Eigen::Matrix<real, 4, 4> mat4;                           
     typedef Eigen::Matrix<real, Eigen::Dynamic, 1> vecN;              
     typedef Eigen::Matrix<real, Eigen::Dynamic, Eigen::Dynamic> matN; 
   
     typedef Eigen::DiagonalMatrix<real, 3> scale;            
     typedef Eigen::Translation<real, 3> translate;           
     typedef Eigen::AngleAxis<real> angleaxis;                
     typedef Eigen::Transform<real, 3, Eigen::Affine> affine; 
   
     /*\
      |    ____                _              _       
      |   / ___|___  _ __  ___| |_ __ _ _ __ | |_ ___ 
      |  | |   / _ \| '_ \/ __| __/ _` | '_ \| __/ __|
      |  | |__| (_) | | | \__ \ || (_| | | | | |_\__ \
      |   \____\___/|_| |_|___/\__\__,_|_| |_|\__|___/
      |                                               
     \*/
   
     static real const EPSILON_MACHINE = std::numeric_limits<real>::epsilon(); 
     static real const EPSILON_HIGH = 1.0E-16;                                 
     static real const EPSILON_MEDIUM = 1.0E-10;                               
     static real const EPSILON_LOW = 1.0E-07;                                  
     static real const EPSILON = EPSILON_MEDIUM;                               
     static real const INFTY = std::numeric_limits<real>::infinity();          
     static real const QUIET_NAN = std::numeric_limits<real>::quiet_NaN();     
     static real const PI = real(3.141592653589793238462643383279500);         
     static real const PIDIV180 = real(0.017453292519943295769236907684886);   
   
     static vec2 const UNITX_VEC2 = vec2::UnitX();           
     static vec2 const UNITY_VEC2 = vec2::UnitY();           
     static vec2 const NAN_VEC2 = vec2::Constant(QUIET_NAN); 
     static mat2 const NAN_MAT2 = mat2::Constant(QUIET_NAN); 
     static vec2 const ZEROS_VEC2 = vec2::Constant(0.0);     
     static mat2 const ZEROS_MAT2 = mat2::Constant(0.0);     
     static vec2 const ONES_VEC2 = vec2::Constant(1.0);      
     static mat2 const ONES_MAT2 = mat2::Constant(1.0);      
     static mat2 const IDENTITY_MAT2 = mat2::Identity();     
   
     static vec3 const UNITX_VEC3 = vec3::UnitX();           
     static vec3 const UNITY_VEC3 = vec3::UnitY();           
     static vec3 const UNITZ_VEC3 = vec3::UnitZ();           
     static vec3 const NAN_VEC3 = vec3::Constant(QUIET_NAN); 
     static mat3 const NAN_MAT3 = mat3::Constant(QUIET_NAN); 
     static vec3 const ZEROS_VEC3 = vec3::Constant(0.0);     
     static mat3 const ZEROS_MAT3 = mat3::Constant(0.0);     
     static vec3 const ONES_VEC3 = vec3::Constant(1.0);      
     static mat3 const ONES_MAT3 = mat3::Constant(1.0);      
     static mat3 const IDENTITY_MAT3 = mat3::Identity();     
   
     static vec4 const UNITX_VEC4 = vec4::UnitX();           
     static vec4 const UNITY_VEC4 = vec4::UnitY();           
     static vec4 const UNITZ_VEC4 = vec4::UnitZ();           
     static vec4 const UNITW_VEC4 = vec4::UnitW();           
     static vec4 const NAN_VEC4 = vec4::Constant(QUIET_NAN); 
     static mat4 const NAN_MAT4 = mat4::Constant(QUIET_NAN); 
     static vec4 const ZEROS_VEC4 = vec4::Constant(0.0);     
     static mat4 const ZEROS_MAT4 = mat4::Constant(0.0);     
     static vec4 const ONES_VEC4 = vec4::Constant(1.0);      
     static mat4 const ONES_MAT4 = mat4::Constant(1.0);      
     static mat4 const IDENTITY_MAT4 = mat4::Identity();     
   
     static vec2 THROWAWAY_VEC2 = vec2(NAN_VEC2); 
     static vec3 THROWAWAY_VEC3 = vec3(NAN_VEC3); 
     static vec4 THROWAWAY_VEC4 = vec4(NAN_VEC4); 
     static mat2 THROWAWAY_MAT2 = mat2(NAN_MAT2); 
     static mat3 THROWAWAY_MAT3 = mat3(NAN_MAT3); 
     static mat4 THROWAWAY_MAT4 = mat4(NAN_MAT4); 
   
   } // namespace acme
   
   #endif
   
