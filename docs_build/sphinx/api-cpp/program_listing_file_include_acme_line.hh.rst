
.. _program_listing_file_include_acme_line.hh:

Program Listing for File acme_line.hh
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_line.hh>` (``include/acme_line.hh``)

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
   
   
   #ifndef INCLUDE_ACME_LINE
   #define INCLUDE_ACME_LINE
   
   #include "acme.hh"
   #include "acme_point.hh"
   
   namespace acme
   {
   
     /*\
      |   _ _            
      |  | (_)_ __   ___ 
      |  | | | '_ \ / _ \
      |  | | | | | |  __/
      |  |_|_|_| |_|\___|
      |                  
     \*/
   
   
     class line : public entity
     {
     private:
       point m_origin;   
       vec3 m_direction; 
   
     public:
       ~line() {}
   
       line() {}
   
       line(line const &) = default;
   
       line(line &&) = default;
   
       line(
           real ox, 
           real oy, 
           real oz, 
           real dx, 
           real dy, 
           real dz  
       );
   
       line(
           point const &origin,  
           vec3 const &direction 
       );
   
       line &
       operator=(
           line const &line_in 
       );
   
       bool
       isApprox(
           line const &line_in,     
           real tolerance = EPSILON 
       ) const;
   
       point const &
       origin(void) const;
   
       point &
       origin(void);
   
       vec3 const &
       direction(void) const;
   
       vec3 &
       direction(void);
   
       void
       normalize(void);
   
       vec3
       toVector(void) const;
   
       vec3
       toUnitVector(void) const;
   
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
   
       // Check whether the point is inside the line
       bool
       isInside(
           point const &point_in,   
           real tolerance = EPSILON 
       ) const;
   
       bool
       isDegenerated(
           real tolerance = EPSILON 
       ) const override;
   
       integer level(void) const override { return 3; }
   
       std::string type(void) const override { return "line"; }
   
       bool isNone(void) const override { return false; }
   
       bool isPoint(void) const override { return false; }
   
       bool isLine(void) const override { return true; }
   
       bool isRay(void) const override { return false; }
   
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
   
     }; // class line
   
     static line const NAN_LINE = line(NAN_POINT, NAN_VEC3); 
     static line THROWAWAY_LINE = line(NAN_LINE);            
   
   } // namespace acme
   
   #endif
   
   ///
