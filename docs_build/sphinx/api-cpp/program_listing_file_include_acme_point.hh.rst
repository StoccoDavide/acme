
.. _program_listing_file_include_acme_point.hh:

Program Listing for File acme_point.hh
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_point.hh>` (``include/acme_point.hh``)

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
   
   
   #ifndef INCLUDE_ACME_POINT
   #define INCLUDE_ACME_POINT
   
   #include <Eigen/Core>
   #include <Eigen/Dense>
   #include <Eigen/Geometry>
   
   #include "acme.hh"
   #include "acme_entity.hh"
   #include "acme_math.hh"
   
   namespace acme
   {
   
     /*\
      |               _       _   
      |   _ __   ___ (_)_ __ | |_ 
      |  | '_ \ / _ \| | '_ \| __|
      |  | |_) | (_) | | | | | |_ 
      |  | .__/ \___/|_|_| |_|\__|
      |  |_|                      
     \*/
   
   
     class point : public Eigen::Matrix<real, 3, 1>, public entity
     {
     public:
       using Eigen::Matrix<acme::real, 3, 1>::Matrix;
   
       // This constructor allows you to construct matrix from Eigen expressions
       template <typename derived>
       point(Eigen::MatrixBase<derived> const &other)
           : Eigen::Matrix<acme::real, 3, 1>(other)
       {
       }
   
       // This method allows you to assign Eigen expressions to matrix
       template <typename derived>
       point &operator=(
           Eigen::MatrixBase<derived> const &other 
       )
       {
         this->Eigen::Matrix<acme::real, 3, 1>::operator=(other);
         return *this;
       }
   
       void
       translate(
           vec3 const &vector_in 
           ) override
       {
         *this += vector_in;
       }
   
       void
       transform(
           affine const &affine_in 
           ) override
       {
         *this = affine_in * *this;
       }
   
       bool isDegenerated(
           acme::real tolerance = EPSILON 
       )
           const override
       {
         return false;
       }
   
       integer level(void) const override { return 1; }
   
       std::string type(void) const override { return "point"; }
   
       bool isNone(void) const override { return false; }
   
       bool isPoint(void) const override { return true; }
   
       bool isLine(void) const override { return false; }
   
       bool isRay(void) const override { return false; }
   
       bool isPlane(void) const override { return false; }
   
       bool isSegment(void) const override { return false; }
   
       bool isTriangle(void) const override { return false; }
   
       bool isDisk(void) const override { return false; }
   
       bool isBall(void) const override { return false; }
   
       bool isClampable(void) const override { return true; }
   
       bool isNonClampable(void) const override { return false; }
   
       bool
       clamp(
           acme::vec3 &min, 
           acme::vec3 &max  
       ) const override;
   
       bool
       clamp(
           acme::real &min_x, 
           acme::real &min_y, 
           acme::real &min_z, 
           acme::real &max_x, 
           acme::real &max_y, 
           acme::real &max_z  
       ) const override;
   
     }; // class point
   
     static point const NAN_POINT = point::Constant(QUIET_NAN); 
     static point THROWAWAY_POINT = point(NAN_POINT);           
   
   } // namespace acme
   
   #endif
   
   ///
