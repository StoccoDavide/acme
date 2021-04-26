
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_ray.hh:

Program Listing for File acme_ray.hh
====================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_ray.hh>` (``/Users/davide/Documents/Git/acme/include/acme_ray.hh``)

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
   
   
   #ifndef INCLUDE_ACME_RAY
   #define INCLUDE_ACME_RAY
   
   #include "acme.hh"
   #include "acme_math.hh"
   
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
   
   
     class ray
     {
     public:
   #ifdef ACME_USE_CXX11
       typedef std::shared_ptr<ray const> ptr; 
   #else
       typedef ray const *ptr; 
   #endif
   
       typedef std::pair<ptr, ptr> pairptr;     
       typedef std::vector<ptr> vecptr;         
       typedef std::vector<pairptr> vecpairptr; 
   
     private:
       vec3 _origin;    
       vec3 _direction; 
   
     public:
       ~ray() {}
   
       ray() {}
   
       ray(ray const &) = default;
   
       ray(
           real_type ox, //<! Input x value of ray origin point
           real_type oy, //<! Input y value of ray origin point
           real_type oz, //<! Input z value of ray origin point
           real_type dx, //<! Input x value of ray direction
           real_type dy, //<! Input y value of ray direction
           real_type dz  //<! Input z value of ray direction
           ) : _origin(vec3(ox, oy, oz)),
               _direction(vec3(dx, dy, dz))
       {
       }
   
       ray(
           vec3 const &origin,   
           vec3 const &direction 
           ) : _origin(origin),
               _direction(direction)
       {
       }
   
       ray &
       operator=(
           ray const &input 
       );
   
       bool
       isApprox(
           ray const &input 
       ) const;
   
       bool
       isDegenerated(void) const;
   
       vec3 const &
       origin() const;
   
       vec3 const &
       direction() const;
   
       void
       origin(
           vec3 const &input 
       );
   
       void
       direction(
           vec3 const &input 
       );
   
       void
       normalize(void);
   
       vec3
       toVector(void) const;
   
       vec3
       toNormalizedVector(void) const;
   
       void
       translate(
           vec3 const &input 
       );
   
       void
       transform(
           affine const &matrix 
       );
   
       void
       reverse(void);
   
       // Check whether the point is inside the ray
       bool
       isInside(
           vec3 const &point 
       ) const;
   
     }; // class ray
   
     static ray const NaN_ray = ray(acme::NaN_vec3, acme::NaN_vec3); 
     static ray ray_goat = ray(NaN_ray);                             
   
   } // namespace acme
   
   #endif
   
   ///
