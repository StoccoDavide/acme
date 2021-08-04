
.. _program_listing_file_include_acme_plane.hh:

Program Listing for File acme_plane.hh
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_plane.hh>` (``include/acme_plane.hh``)

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
   
   
   #ifndef INCLUDE_ACME_PLANE
   #define INCLUDE_ACME_PLANE
   
   #include "acme.hh"
   #include "acme_point.hh"
   
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
   
   
     class plane : public entity
     {
     private:
       point m_origin; 
       vec3 m_normal;  
   
     public:
       ~plane() {}
   
       plane() {}
   
       plane(plane const &) = default;
   
       plane(plane &&) = default;
   
       plane(
           real origin_x, 
           real origin_y, 
           real origin_z, 
           real normal_x, 
           real normal_y, 
           real normal_z  
       );
   
       plane(
           point const &origin, 
           vec3 const &normal   
       );
   
       plane &
       operator=(
           plane const &plane_in 
       );
   
       bool
       isApprox(
           plane const &plane_in,   
           real tolerance = EPSILON 
       ) const;
   
       point const &
       origin(void) const;
   
       point &
       origin(void);
   
       vec3 const &
       normal(void) const;
   
       vec3 &
       normal(void);
   
       vec3
       unitNormal(void) const;
   
       void
       normalize(void);
   
       real
       d(void) const;
   
       real
       distance(
           point const &point_in 
       ) const;
   
       real
       squaredDistance(
           point const &point_in 
       ) const;
   
       real
       signedDistance(
           point const &point_in 
       ) const;
   
       void
       reverse(void);
   
       void
       translate(
           vec3 const &vector_in 
           ) override;
   
       void
       transform(
           affine const &affine_in 
           ) override;
   
       // Check whether a point lays on the plane
       bool
       isInside(
           point const &point_in,   
           real tolerance = EPSILON 
       ) const;
   
       bool
       isDegenerated(
           real tolerance = EPSILON 
       ) const override;
   
       integer level(void) const override { return 5; }
   
       std::string type(void) const override { return "plane"; }
   
       bool isNone(void) const override { return false; }
   
       bool isPoint(void) const override { return false; }
   
       bool isLine(void) const override { return false; }
   
       bool isRay(void) const override { return false; }
   
       bool isPlane(void) const override { return true; }
   
       bool isSegment(void) const override { return false; }
   
       bool isTriangle(void) const override { return false; }
   
       bool isDisk(void) const override { return false; }
   
       bool isBall(void) const override { return false; }
   
       bool isClampable(void) const override { return false; }
   
       bool isNonClampable(void) const override { return true; }
   
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
   
     }; // class plane
   
     static plane const NAN_PLANE = plane(NAN_POINT, NAN_VEC3); 
     static plane plane_goat = plane(NAN_PLANE);                
   
   } // namespace acme
   
   #endif
   
   ///
