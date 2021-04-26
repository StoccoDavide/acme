
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_line.hh:

Program Listing for File acme_line.hh
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_line.hh>` (``/Users/davide/Documents/Git/acme/include/acme_line.hh``)

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
   
   
   #ifndef INCLUDE_ACME_LINE
   #define INCLUDE_ACME_LINE
   
   #include "acme.hh"
   #include "acme_math.hh"
   
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
   
   
     class line
     {
     public:
   #ifdef ACME_USE_CXX11
       typedef std::shared_ptr<line const> ptr; 
   #else
       typedef line const *ptr; 
   #endif
   
       typedef std::pair<ptr, ptr> pairptr;     
       typedef std::vector<ptr> vecptr;         
       typedef std::vector<pairptr> vecpairptr; 
   
     private:
       vec3 _origin;    
       vec3 _direction; 
   
     public:
       ~line() {}
   
       line() {}
   
       line(line const &) = default;
   
       line(
           real_type ox, //<! Input x value of line origin point
           real_type oy, //<! Input y value of line origin point
           real_type oz, //<! Input z value of line origin point
           real_type dx, //<! Input x value of line direction vector
           real_type dy, //<! Input y value of line direction vector
           real_type dz  //<! Input z value of line direction vector
           ) : _origin(vec3(ox, oy, oz)),
               _direction(vec3(dx, dy, dz))
       {
       }
   
       line(
           vec3 const &origin,   
           vec3 const &direction 
           ) : _origin(origin),
               _direction(direction)
       {
       }
   
       line &
       operator=(
           line const &input 
       );
   
       bool
       isApprox(
           line const &input 
       ) const;
   
       bool
       isDegenerated(void) const;
   
       vec3 const &
       origin(void) const;
   
       vec3 const &
       direction(void) const;
   
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
   
       // Check whether the point is inside the line
       bool
       isInside(
           vec3 const &point 
       ) const;
   
     }; // class line
   
     static line const NaN_line = line(acme::NaN_vec3, acme::NaN_vec3); 
     static line line_goat = line(NaN_line);                            
   
   } // namespace acme
   
   #endif
   
   ///
