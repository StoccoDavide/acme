
.. _program_listing_file__Users_davide_Documents_Git_acme_src_acme_plane.cc:

Program Listing for File acme_plane.cc
======================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_src_acme_plane.cc>` (``/Users/davide/Documents/Git/acme/src/acme_plane.cc``)

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
   
   
   #include "acme_plane.hh"
   
   namespace acme
   {
   
     /*\
      |         _                  
      |   _ __ | | __ _ _ __   ___ 
      |  | '_ \| |/ _` | '_ \ / _ \
      |  | |_) | | (_| | | | |  __/
      |  | .__/|_|\__,_|_| |_|\___|
      |  |_|                       
     \*/
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     plane &
     plane::operator=(
         plane const &input)
     {
       if (this == &input)
       {
         return *this;
       }
       else
       {
         this->_origin = input._origin;
         this->_normal = input._normal;
         return *this;
       }
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     bool
     plane::isApprox(
         plane const &input)
         const
     {
       return this->_origin.isApprox(input._origin) &&
              this->_normal.isApprox(input._normal);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     bool
     plane::isDegenerated(void)
         const
     {
       return acme::isDegenerated(this->_normal);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     vec3 const &
     plane::origin() const
     {
       return this->_origin;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     vec3 const &
     plane::normal() const
     {
       return this->_normal;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     plane::origin(
         vec3 const &input)
     {
       this->_origin = input;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     plane::normal(
         vec3 const &input)
     {
       this->_normal = input;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     plane::normalize(void)
     {
       this->_normal.normalize();
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     plane::translate(
         vec3 const &input)
     {
       this->_origin = input + this->_origin;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     plane::transform(
         affine const &matrix)
     {
       acme::transformPoint(this->_origin, matrix);
       acme::transformVector(this->_normal, matrix);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     void
     plane::reverse(void)
     {
       this->_normal = -this->_normal;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     real_type
     plane::d(void)
         const
     {
       return -this->_origin.dot(this->_normal);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     real_type
     plane::distance(
         vec3 const &input)
         const
     {
       return acme::abs(this->signedDistance(input));
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     real_type
     plane::squaredDistance(
         vec3 const &input)
         const
     {
       return acme::sqr(this->signedDistance(input));
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     real_type
     plane::signedDistance(
         vec3 const &input)
         const
     {
       return (input - this->_origin).dot(this->_normal);
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
     bool
     plane::isInside(
         vec3 const &point)
         const
     {
       return this->signedDistance(point) < acme::Epsilon;
     }
   
     // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   
   } // namespace acme
   
   ///
