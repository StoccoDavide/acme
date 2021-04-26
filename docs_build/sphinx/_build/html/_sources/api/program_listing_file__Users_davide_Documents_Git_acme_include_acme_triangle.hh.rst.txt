
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_triangle.hh:

Program Listing for File acme_triangle.hh
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_triangle.hh>` (``/Users/davide/Documents/Git/acme/include/acme_triangle.hh``)

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
   
   
   #ifndef INCLUDE_ACME_TRIANGLE
   #define INCLUDE_ACME_TRIANGLE
   
   #include "acme.hh"
   #include "acme_math.hh"
   #include "acme_segment.hh"
   #include "acme_box.hh"
   
   namespace acme
   {
   
     /*\
      |   _        _                   _      
      |  | |_ _ __(_) __ _ _ __   __ _| | ___ 
      |  | __| '__| |/ _` | '_ \ / _` | |/ _ \
      |  | |_| |  | | (_| | | | | (_| | |  __/
      |   \__|_|  |_|\__,_|_| |_|\__, |_|\___|
      |                          |___/        
     \*/
   
   
     class triangle
     {
     public:
   #ifdef ACME_USE_CXX11
       typedef std::shared_ptr<triangle const> ptr; 
   #else
       typedef triangle const *ptr; 
   #endif
   
       typedef std::pair<ptr, ptr> pairptr;     
       typedef std::vector<ptr> vecptr;         
       typedef std::vector<pairptr> vecpairptr; 
   
     private:
       vec3 _vertex[3]; 
   
     public:
       //~triangle() {}
   
       triangle(triangle const &) = default;
   
       triangle() {}
   
       triangle(
           real_type x0, //<! Input x value of first triangle vertex
           real_type y0, //<! Input y value of first triangle vertex
           real_type z0, //<! Input z value of first triangle vertex
           real_type x1, //<! Input x value of second triangle vertex
           real_type y1, //<! Input y value of second triangle vertex
           real_type z1, //<! Input z value of second triangle vertex
           real_type x2, //<! Input x value of third triangle vertex
           real_type y2, //<! Input y value of third triangle vertex
           real_type z2  //<! Input z value of third triangle vertex
       );
   
       triangle(
           vec3 const &point0, 
           vec3 const &point1, 
           vec3 const &point2  
       );
   
       triangle(
           vec3 const point[3] 
       );
   
       triangle &
       operator=(
           triangle const &input 
       );
   
       bool
       isApprox(
           triangle const &input 
       ) const;
   
       bool
       isDegenerated(void) const;
   
       vec3 const &
       vertex(
           size_t i 
       ) const;
   
       vec3 &
       vertex(
           size_t i 
       );
   
       void
       vertices(
           vec3 const &vertex0, 
           vec3 const &vertex1, 
           vec3 const &vertex2  
       );
   
       void
       vertices(
           vec3 const vertex[3] 
       );
   
       segment
       edge(
           size_t i, 
           size_t j  
       ) const;
   
       vec3
       normal(void) const;
   
       void
       translate(
           vec3 const &input 
       );
   
       void
       transform(
           affine const &matrix 
       );
   
       void
       swap(
           size_t i, 
           size_t j  
       );
   
       void
       clamp(
           box &input 
       ) const;
   
       real_type
       perimeter(void)
           const;
   
       real_type
       area(void)
           const;
   
       bool
       isInside(
           vec3 const &point 
       ) const;
   
       void
       barycentric(
           vec3 const &point, 
           real_type &u,      
           real_type &v,      
           real_type &w       
       ) const;
   
     }; // class triangle
   
     static triangle const NaN_triangle = triangle(acme::NaN_vec3, acme::NaN_vec3, acme::NaN_vec3); 
     static triangle triangle_goat = triangle(NaN_triangle);                                        
   
   } // namespace acme
   
   #endif
   
