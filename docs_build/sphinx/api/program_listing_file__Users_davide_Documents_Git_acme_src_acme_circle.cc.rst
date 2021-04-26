
.. _program_listing_file__Users_davide_Documents_Git_acme_src_acme_circle.cc:

Program Listing for File acme_circle.cc
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_src_acme_circle.cc>` (``/Users/davide/Documents/Git/acme/src/acme_circle.cc``)

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
   
   
   #include "acme_circle.hh"
   
   namespace acme
   {
   
     /*\
      |        _          _      
      |    ___(_)_ __ ___| | ___ 
      |   / __| | '__/ __| |/ _ \
      |  | (__| | | | (__| |  __/
      |   \___|_|_|  \___|_|\___|
      |                          
     \*/
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     circle &
     circle::operator=(
         circle const &input)
     {
       if (this == &input)
       {
         return *this;
       }
       else
       {
         this->_radius = input._radius;
         this->_plane = input._plane;
         return *this;
       }
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     bool
     circle::isApprox(
         circle const &input)
         const
     {
       return acme::isApprox(this->_radius, input._radius) &&
              this->_plane.origin().isApprox(input._plane.origin()) &&
              this->_plane.normal().isApprox(input._plane.normal());
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     bool
     circle::isDegenerated(void)
         const
     {
       return acme::isApprox(this->_radius, 0.0) && this->_plane.isDegenerated();
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     real_type
     circle::radius(void)
         const
     {
       return this->_radius;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     vec3 const &
     circle::center(void)
         const
     {
       return this->_plane.origin();
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     vec3 const &
     circle::normal(void)
         const
     {
       return this->_plane.normal();
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     plane const &
     circle::layingPlane(void)
         const
     {
       return this->_plane;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     circle::radius(
         real_type input)
     {
       this->_radius = input;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     circle::center(
         vec3 const &input)
     {
       this->_plane.origin(input);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     circle::normal(
         vec3 const &input)
     {
       this->_plane.normal(input);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     circle::normalize(void)
     {
       this->_plane.normalize();
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
     void
     circle::layingPlane(
         plane const &input)
     {
       this->_plane = input;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     circle::translate(
         vec3 const &input)
     {
       this->_plane.translate(input);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     circle::transform(
         affine const &matrix)
     {
       this->_plane.transform(matrix);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     circle::reverse(void)
     {
       this->_plane.reverse();
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     bool
     circle::isInside(
         vec3 const &point)
         const
     {
       return this->_plane.isInside(point) &&
              (this->_plane.origin() - point).norm() <= this->_radius;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
   } // namespace acme
   
   ///
