
.. _program_listing_file_include_acme_disk.hh:

Program Listing for File acme_disk.hh
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_disk.hh>` (``include/acme_disk.hh``)

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
   
   
   #ifndef INCLUDE_ACME_DISK
   #define INCLUDE_ACME_DISK
   
   #include "acme.hh"
   #include "acme_aabb.hh"
   #include "acme_plane.hh"
   #include "acme_point.hh"
   
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
   
   
     class disk : public entity
     {
     private:
       real m_radius; 
       plane m_plane; 
   
     public:
       ~disk() {}
   
       disk() {}
   
       disk(disk const &) = default;
   
       disk(disk &&) = default;
   
       disk(
           real radius,       
           plane const &plane 
       );
   
       disk(
           real radius,         
           point const &center, 
           vec3 const &normal   
       );
   
       disk(
           real radius,   
           real center_x, 
           real center_y, 
           real center_z, 
           real normal_x, 
           real normal_y, 
           real normal_z  
       );
   
       disk &
       operator=(
           disk const &disk_in 
       );
   
       bool
       isApprox(
           disk const &disk_in,     
           real tolerance = EPSILON 
       ) const;
   
       real const &
       radius(void) const;
   
       real &
       radius(void);
   
       point const &
       center(void) const;
   
       point &
       center(void);
   
       vec3 const &
       normal(void) const;
   
       vec3 &
       normal(void);
   
       plane const &
       layingPlane(void) const;
   
       plane &
       layingPlane(void);
   
       void
       normalize(void);
   
       void
       reverse(void);
   
       real
       perimeter(void)
           const;
   
       real
       area(void) const;
   
       void
       translate(
           vec3 const &vector_in 
           ) override;
   
       void
       transform(
           affine const &affine_in 
           ) override;
   
       // Check whether the point is inside the disk
       bool
       isInside(
           point const &point_in,   
           real tolerance = EPSILON 
       ) const;
   
       bool
       isDegenerated(
           real tolerance = EPSILON 
       ) const override;
   
       integer level(void) const override { return 8; }
   
       std::string type(void) const override { return "disk"; }
   
       bool isNone(void) const override { return false; }
   
       bool isPoint(void) const override { return false; }
   
       bool isLine(void) const override { return false; }
   
       bool isRay(void) const override { return false; }
   
       bool isPlane(void) const override { return false; }
   
       bool isSegment(void) const override { return false; }
   
       bool isTriangle(void) const override { return false; }
   
       bool isDisk(void) const override { return true; }
   
       bool isBall(void) const override { return false; }
   
       bool isClampable(void) const override { return true; }
   
       bool isNonClampable(void) const override { return false; }
   
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
   
     }; // class disk
   
     static disk const NAN_DISK = disk(QUIET_NAN, NAN_PLANE); 
     static disk THROWAWAY_DISK = disk(NAN_DISK);             
   
   } // namespace acme
   
   #endif
   
   ///
