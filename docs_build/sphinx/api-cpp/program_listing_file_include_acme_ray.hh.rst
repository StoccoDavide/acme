
.. _program_listing_file_include_acme_ray.hh:

Program Listing for File acme_ray.hh
====================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_ray.hh>` (``include/acme_ray.hh``)

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
   
   
   #ifndef INCLUDE_ACME_RAY
   #define INCLUDE_ACME_RAY
   
   #include "acme.hh"
   #include "acme_point.hh"
   
   namespace acme
   {
   
     /*\
      |
      |   _ __ __ _ _   _
      |  | '__/ _` | | | |
      |  | | | (_| | |_| |
      |  |_|  \__,_|\__, |
      |             |___/
     \*/
   
   
     class ray : public entity
     {
     private:
       point m_origin;   
       vec3 m_direction; 
   
     public:
       ~ray() {}
   
       ray() {}
   
       ray(ray const &) = default;
   
       ray(ray &&) = default;
   
       ray(
           real origin_x,    
           real origin_y,    
           real origin_z,    
           real direction_x, 
           real direction_y, 
           real direction_z  
       );
   
       ray(
           point const &origin,  
           vec3 const &direction 
       );
   
       ray &
       operator=(
           ray const &ray_in 
       );
   
       bool
       isApprox(
           ray const &ray_in,       
           real tolerance = EPSILON 
       ) const;
   
       point const &
       origin(void)
           const;
   
       vec3 const &
       direction(void)
           const;
   
       point &
       origin(void);
   
       vec3 &
       direction(void);
   
       void
       normalize(void);
   
       vec3
       toVector(void)
           const;
   
       vec3
       toUnitVector(void)
           const;
   
       void
       reverse(void);
   
       void
       translate(
           vec3 const &vector 
           ) override;
   
       void
       transform(
           affine const &affine_in 
           ) override;
   
       // Check whether the point is inside the ray
       bool
       isInside(
           point const &point_in,   
           real tolerance = EPSILON 
       ) const;
   
       bool
       isDegenerated(
           real tolerance = EPSILON 
       ) const override;
   
       integer level(void) const override { return 4; }
   
       std::string type(void) const override { return "ray"; }
   
       bool isNone(void) const override { return false; }
   
       bool isPoint(void) const override { return false; }
   
       bool isLine(void) const override { return false; }
   
       bool isRay(void) const override { return true; }
   
       bool isPlane(void) const override { return false; }
   
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
   
     }; // class ray
   
     static ray const NAN_RAY = ray(NAN_POINT, NAN_VEC3); 
     static ray THROWAWAY_RAY = ray(NAN_RAY);             
   
   } // namespace acme
   
   #endif
   
   ///
