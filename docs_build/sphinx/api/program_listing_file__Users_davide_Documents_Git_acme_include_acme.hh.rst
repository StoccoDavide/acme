
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme.hh:

Program Listing for File acme.hh
================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme.hh>` (``/Users/davide/Documents/Git/acme/include/acme.hh``)

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
   
   // Use CXX11 features
   #define ACME_USE_CXX11
   
   // Standard libraries
   #include <memory>
   #include <cstddef>
   #include <limits>
   #include <algorithm>
   #include <iterator>
   #include <iostream>
   #include <iomanip>
   #include <vector>
   #include <cassert>
   
   // Eigen libraries
   #include <Eigen/Dense>
   #include <Eigen/Geometry>
   
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
   
     typedef double real_type;          
     typedef int int_type;              
     typedef std::ostream ostream_type; 
   
     typedef Eigen::Matrix<real_type, Eigen::Dynamic, 1> vecN;              
     typedef Eigen::Matrix<real_type, Eigen::Dynamic, Eigen::Dynamic> matN; 
   
     typedef Eigen::Matrix<real_type, 2, 1> vec2;                          
     typedef Eigen::Matrix<real_type, 2, 2> mat2;                          
     typedef Eigen::Matrix<vec2, Eigen::Dynamic, 1> vec_vec2;              
     typedef Eigen::Matrix<mat2, Eigen::Dynamic, 1> vec_mat2;              
     typedef Eigen::Matrix<vec2, Eigen::Dynamic, Eigen::Dynamic> mat_vec2; 
     typedef Eigen::Matrix<mat2, Eigen::Dynamic, Eigen::Dynamic> mat_mat2; 
   
     typedef Eigen::Matrix<real_type, 3, 1> vec3;                          
     typedef Eigen::Matrix<real_type, 3, 3> mat3;                          
     typedef Eigen::Matrix<vec3, Eigen::Dynamic, 1> vec_vec3;              
     typedef Eigen::Matrix<mat3, Eigen::Dynamic, 1> vec_mat3;              
     typedef Eigen::Matrix<vec3, Eigen::Dynamic, Eigen::Dynamic> mat_vec3; 
     typedef Eigen::Matrix<mat3, Eigen::Dynamic, Eigen::Dynamic> mat_mat3; 
   
     typedef Eigen::Matrix<real_type, 4, 1> vec4;                          
     typedef Eigen::Matrix<real_type, 4, 4> mat4;                          
     typedef Eigen::Matrix<vec4, Eigen::Dynamic, 1> vec_vec4;              
     typedef Eigen::Matrix<mat4, Eigen::Dynamic, 1> vec_mat4;              
     typedef Eigen::Matrix<vec4, Eigen::Dynamic, Eigen::Dynamic> mat_vec4; 
     typedef Eigen::Matrix<mat4, Eigen::Dynamic, Eigen::Dynamic> mat_mat4; 
   
     typedef Eigen::DiagonalMatrix<real_type, 3> scale;                 
     typedef Eigen::Translation<real_type, 3> translate;                
     typedef Eigen::AngleAxis<real_type> angleaxis;                     
     typedef Eigen::Transform<real_type, 3, Eigen::Affine> affine;      
     typedef Eigen::Matrix<scale, Eigen::Dynamic, 1> vec_scale;         
     typedef Eigen::Matrix<translate, Eigen::Dynamic, 1> vec_translate; 
     typedef Eigen::Matrix<angleaxis, Eigen::Dynamic, 1> vec_angleaxis; 
     typedef Eigen::Matrix<affine, Eigen::Dynamic, 1> vec_affine;       
   
     /*\
      |    ____                _              _       
      |   / ___|___  _ __  ___| |_ __ _ _ __ | |_ ___ 
      |  | |   / _ \| '_ \/ __| __/ _` | '_ \| __/ __|¯
      |  | |__| (_) | | | \__ \ || (_| | | | | |_\__ \
      |   \____\___/|_| |_|___/\__\__,_|_| |_|\__|___/
      |                                               
     \*/
   
     static real_type const Epsilon_Machine = std::numeric_limits<real_type>::epsilon(); 
     static real_type const Epsilon_High = 1.0E-16;                                      
     static real_type const Epsilon_Medium = 1.0E-10;                                    
     static real_type const Epsilon_Low = 1.0E-07;                                       
     static real_type const Epsilon = Epsilon_Medium;                                    
     static real_type const Infinity = std::numeric_limits<real_type>::infinity();       
     static real_type const NaN = std::numeric_limits<real_type>::quiet_NaN();           
   
     static real_type const PI = real_type(3.141592653589793238462643383279500);         
     static real_type const PI2 = real_type(6.283185307179586476925286766559000);        
     static real_type const PIdiv180 = real_type(0.017453292519943295769236907684886);   
     static real_type const _180divPI = real_type(57.295779513082320876798154814105000); 
   
     static vec2 const UnitX_vec2 = vec2::UnitX();       
     static vec2 const UnitY_vec2 = vec2::UnitY();       
     static vec2 const NaN_vec2 = vec2::Constant(NaN);   
     static mat2 const NaN_mat2 = mat2::Constant(NaN);   
     static vec2 const Zeros_vect2 = vec2::Zero();       
     static mat2 const Zeros_mat2 = mat2::Zero();        
     static vec2 const Ones_vec2 = vec2::Constant(1.0);  
     static mat2 const Ones_mat2 = mat2::Constant(1.0);  
     static mat2 const Identity_mat2 = mat2::Identity(); 
   
     static vec3 const UnitX_vec3 = vec3::UnitX();       
     static vec3 const UnitY_vec3 = vec3::UnitY();       
     static vec3 const UnitZ_vec3 = vec3::UnitZ();       
     static vec3 const NaN_vec3 = vec3::Constant(NaN);   
     static mat3 const NaN_mat3 = mat3::Constant(NaN);   
     static vec3 const Zeros_vec3 = vec3::Zero();        
     static mat3 const Zeros_mat3 = mat3::Zero();        
     static vec3 const Ones_vec3 = vec3::Constant(1.0);  
     static mat3 const Ones_mat3 = mat3::Constant(1.0);  
     static mat3 const Identity_mat3 = mat3::Identity(); 
   
     static vec4 const UnitX_vec4 = vec4::UnitX();       
     static vec4 const UnitY_vec4 = vec4::UnitY();       
     static vec4 const UnitZ_vec4 = vec4::UnitZ();       
     static vec4 const UnitW_vec4 = vec4::UnitW();       
     static vec4 const NaN_vec4 = vec4::Constant(NaN);   
     static mat4 const NaN_mat4 = mat4::Constant(NaN);   
     static vec4 const Zeros_vec4 = vec4::Zero();        
     static mat4 const Zeros_mat4 = mat4::Zero();        
     static vec4 const Ones_vec4 = vec4::Constant(1.0);  
     static mat4 const Ones_mat4 = mat4::Constant(1.0);  
     static mat4 const Identity_mat4 = mat4::Identity(); 
   
     static vec2 vec2_goat = vec2(NaN_vec2); 
     static vec3 vec3_goat = vec3(NaN_vec3); 
     static vec4 vec4_goat = vec4(NaN_vec4); 
     static mat2 mat2_goat = mat2(NaN_mat2); 
     static mat3 mat3_goat = mat3(NaN_mat3); 
     static mat4 mat4_goat = mat4(NaN_mat4); 
   
   } // namespace acme
   
   std::ostream &
   operator<<(
       std::ostream &os,     
       acme::vec2 const &obj 
   );
   
   std::ostream &
   operator<<(
       std::ostream &os,     
       acme::mat2 const &obj 
   );
   
   std::ostream &
   operator<<(
       std::ostream &os,     
       acme::vec3 const &obj 
   );
   
   std::ostream &
   operator<<(
       std::ostream &os,     
       acme::mat3 const &obj 
   );
   
   std::ostream &
   operator<<(
       std::ostream &os,     
       acme::vec4 const &obj 
   );
   
   std::ostream &
   operator<<(
       std::ostream &os,     
       acme::mat4 const &obj 
   );
   
   #endif
   
