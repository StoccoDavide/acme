
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_plane.hh:

Program Listing for File acme_plane.hh
======================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_plane.hh>` (``/Users/davide/Documents/Git/acme/include/acme_plane.hh``)

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
   
   
   #ifndef INCLUDE_ACME_PLANE
   #define INCLUDE_ACME_PLANE
   
   #include "acme.hh"
   #include "acme_math.hh"
   
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
   
   
     class plane
     {
     public:
   #ifdef ACME_USE_CXX11
       typedef std::shared_ptr<plane const> ptr; 
   #else
       typedef plane const *ptr; 
   #endif
   
       typedef std::pair<ptr, ptr> pairptr;     
       typedef std::vector<ptr> vecptr;         
       typedef std::vector<pairptr> vecpairptr; 
   
     private:
       vec3 _origin; 
       vec3 _normal; 
   
     public:
       ~plane() {}
   
       plane() {}
   
       plane(plane const &) = default;
   
       plane(
           real_type ox, //<! Input x value of plane origin point
           real_type oy, //<! Input y value of plane origin point
           real_type oz, //<! Input z value of plane origin point
           real_type dx, //<! Input x value of plane normal vector
           real_type dy, //<! Input y value of plane normal vector
           real_type dz  //<! Input z value of plane normal vector
           ) : _origin(vec3(ox, oy, oz)),
               _normal(vec3(dx, dy, dz))
       {
       }
   
       plane(
           vec3 const &origin, 
           vec3 const &normal  
           ) : _origin(origin),
               _normal(normal)
       {
       }
   
       plane &
       operator=(
           plane const &input 
       );
   
       bool
       isApprox(
           plane const &input 
       ) const;
   
       bool
       isDegenerated(void) const;
   
       vec3 const &
       origin(void) const;
   
       vec3 const &
       normal(void) const;
   
       void
       normalize(void);
   
       void
       origin(
           vec3 const &input 
       );
   
       void
       normal(
           vec3 const &input 
       );
   
       void
       translate(
           vec3 const &input 
       );
   
       void
       rotate(
           mat3 const &input 
       );
   
       void
       transform(
           affine const &matrix 
       );
   
       void
       reverse(void);
   
       real_type
       d(void) const;
   
       real_type
       distance(
           vec3 const &input 
       ) const;
   
       real_type
       squaredDistance(
           vec3 const &input 
       ) const;
   
       real_type
       signedDistance(
           vec3 const &input 
       ) const;
   
       // Check whether a point lays on the plane
       bool
       isInside(
           vec3 const &point 
       ) const;
   
     }; // class plane
   
     static plane const NaN_plane = plane(acme::NaN_vec3, acme::NaN_vec3); 
     static plane const plane_goat = plane(NaN_plane);                     
   
   } // namespace acme
   
   #endif
   
   ///
