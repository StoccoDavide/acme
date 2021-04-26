
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_circle.hh:

Program Listing for File acme_circle.hh
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_circle.hh>` (``/Users/davide/Documents/Git/acme/include/acme_circle.hh``)

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
   
   
   #ifndef INCLUDE_ACME_CIRCLE
   #define INCLUDE_ACME_CIRCLE
   
   #include "acme.hh"
   #include "acme_math.hh"
   #include "acme_plane.hh"
   
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
   
   
     class circle
     {
     public:
   #ifdef ACME_USE_CXX11
       typedef std::shared_ptr<circle const> ptr; 
   #else
       typedef circle const *ptr; 
   #endif
   
       typedef std::pair<ptr, ptr> pairptr;     
       typedef std::vector<ptr> vecptr;         
       typedef std::vector<pairptr> vecpairptr; 
   
     private:
       real_type _radius; 
       plane _plane;      
   
     public:
       ~circle() {}
   
       circle() {}
   
       circle(circle const &) = default;
   
       circle(
           real_type radius,  
           plane const &plane 
           ) : _radius(radius),
               _plane(plane)
       {
       }
   
       circle(
           real_type radius,   
           vec3 const &center, 
           vec3 const &normal  
           ) : _radius(radius),
               _plane(center, normal)
       {
       }
   
       circle &
       operator=(
           circle const &input 
       );
   
       bool
       isApprox(
           circle const &input 
       ) const;
   
       bool
       isDegenerated(void) const;
   
       real_type
       radius(void) const;
   
       vec3 const &
       center(void) const;
   
       vec3 const &
       normal(void) const;
   
       plane const &
       layingPlane(void) const;
   
       void
       radius(
           real_type input 
       );
   
       void
       center(
           vec3 const &input 
       );
   
       void
       normal(
           vec3 const &input 
       );
   
       void
       normalize(void);
   
       void
       layingPlane(
           plane const &input 
       );
   
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
   
       // Check whether the point is inside the circle
       bool
       isInside(
           vec3 const &point 
       ) const;
   
     }; // class circle
   
     //static circle const NaN_circle = circle(acme::NaN, acme::NaN_plane); //!< Not-a-Number triangle type
     //static circle circle_goat = circle(NaN_circle);                      //!< Scapegoat circle type (throwaway non-const object)
   
   } // namespace acme
   
   #endif
   
   ///
