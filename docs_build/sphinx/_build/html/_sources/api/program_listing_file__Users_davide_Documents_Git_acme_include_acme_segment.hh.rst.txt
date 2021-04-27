
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_segment.hh:

Program Listing for File acme_segment.hh
========================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_segment.hh>` (``/Users/davide/Documents/Git/acme/include/acme_segment.hh``)

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
   
   
   #ifndef INCLUDE_ACME_SEGMENT
   #define INCLUDE_ACME_SEGMENT
   
   #include "acme.hh"
   #include "acme_math.hh"
   #include "acme_box.hh"
   
   namespace acme
   {
   
     /*\
      |                                       _   
      |   ___  ___  __ _ _ __ ___   ___ _ __ | |_ 
      |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __|
      |  \__ \  __/ (_| | | | | | |  __/ | | | |_ 
      |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|
      |            |___/                          
     \*/
   
   
     class segment
     {
     public:
   #ifdef ACME_USE_CXX11
       typedef std::shared_ptr<segment const> ptr; 
   #else
       typedef segment const *ptr; 
   #endif
   
       typedef std::pair<ptr, ptr> pairptr;     
       typedef std::vector<ptr> vecptr;         
       typedef std::vector<pairptr> vecpairptr; 
   
     private:
       vec3 _point[2]; 
   
     public:
       ~segment() {}
   
       segment(segment const &) = default;
   
       segment() {}
   
       segment(
           real_type x0, //<! Input x value of first segment point
           real_type y0, //<! Input y value of first segment point
           real_type z0, //<! Input z value of first segment point
           real_type x1, //<! Input x value of second segment point
           real_type y1, //<! Input y value of second segment point
           real_type z1  //<! Input z value of second segment point
       );
   
       segment(
           vec3 const &point0, 
           vec3 const &point1  
       );
   
       segment(
           vec3 const point[2] 
       );
   
       segment &
       operator=(
           segment const &input 
       );
   
       bool
       isApprox(
           segment const &input 
       ) const;
   
       bool
       isDegenerated(void) const;
   
       vec3
       pointMiddle(void) const;
   
       vec3 const &
       point(
           size_t i 
       ) const;
   
       vec3 &
       point(
           size_t i 
       );
   
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
       swap(void);
   
       void
       clamp(
           box &input 
       ) const;
   
       real_type
       length(void) const;
   
       // Check whether the point is inside the segment
       bool
       isInside(
           vec3 const &point 
       ) const;
   
     }; // class segment
   
     static segment const NaN_segment = segment(acme::NaN_vec3, acme::NaN_vec3); 
     static segment segment_goat = segment(NaN_segment);                         
   
   } // namespace acme
   
   #endif
   
   ///
