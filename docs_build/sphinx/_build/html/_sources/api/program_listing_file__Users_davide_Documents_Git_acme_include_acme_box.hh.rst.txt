
.. _program_listing_file__Users_davide_Documents_Git_acme_include_acme_box.hh:

Program Listing for File acme_box.hh
====================================

|exhale_lsh| :ref:`Return to documentation for file <file__Users_davide_Documents_Git_acme_include_acme_box.hh>` (``/Users/davide/Documents/Git/acme/include/acme_box.hh``)

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
   
   
   #ifndef INCLUDE_ACME_BOX
   #define INCLUDE_ACME_BOX
   
   #include "acme.hh"
   #include "acme_math.hh"
   
   namespace acme
   {
   
     /*\
      |   _               
      |  | |__   _____  _ 
      |  | '_ \ / _ \ \/ /
      |  | |_) | (_) >  < 
      |  |_.__/ \___/_/\_\
      |                   
     \*/
   
   
     class box
     {
     public:
   #ifdef ACME_USE_CXX11
       typedef std::shared_ptr<box const> ptr; 
   #else
       typedef box const *ptr; 
   #endif
   
       typedef std::pair<ptr, ptr> pairptr;     
       typedef std::vector<ptr> vecptr;         
       typedef std::vector<pairptr> vecpairptr; 
   
     private:
       vec3 _min; 
       vec3 _max; 
       int_type _id;    
       int_type _ipos;  
   
     public:
       ~box() {}
   
       box(const box &) = default;
   
       box() {}
   
       box(
           real_type minX, //<! Input x value of box minimum point
           real_type minY, //<! Input y value of box minimum point
           real_type minZ, //<! Input z value of box minimum point
           real_type maxX, //<! Input x value of box maximum point
           real_type maxY, //<! Input y value of box maximum point
           real_type maxZ, //<! Input z value of box maximum point
           int_type id,     //<! Input id value
           int_type ipos    //<! Input rank value
           ) : _min(vec3(minX, minY, minZ)),
               _max(vec3(maxX, maxY, maxZ)),
               _id(id),
               _ipos(ipos)
       {
         this->updateMaxMin();
       }
   
       box(
           vec3 const &min, 
           vec3 const &max, 
           int_type id,           //<! Input box id value
           int_type ipos          //<! Input box rank value
           ) : _min(min),
               _max(max),
               _id(id),
               _ipos(ipos)
       {
         this->updateMaxMin();
       }
   
       box(
           std::vector<box::ptr> const &boxes, 
           int_type id,                        //<! Input box id value
           int_type ipos                       //<! Input box rank value
           ) : _id(id),
               _ipos(ipos)
       {
         this->merged(boxes);
         this->updateMaxMin();
       }
   
       box &operator=(
           box const &input 
       );
   
       void
       clear(void);
   
       bool
       isApprox(
           box const &input 
       ) const;
   
       bool
       isDegenerated(void) const;
   
       bool
       checkMaxMin(void) const;
   
       bool
       updateMaxMin(void);
   
       vec3 const &
       min(void) const;
   
       real_type
       minX(void) const;
   
       real_type
       minY(void) const;
   
       real_type
       minZ(void) const;
   
       real_type
       min(
           size_t i 
       ) const;
   
       void
       min(
           vec3 const &input 
       );
   
       void
       min(
           real_type x, 
           real_type y, 
           real_type z  
       );
   
       void
       minX(
           real_type input 
       );
   
       void
       minY(
           real_type input 
       );
   
       void
       minZ(
           real_type input 
       );
   
       void
       min(
           size_t i,     
           real_type input 
       );
   
       vec3 const &
       max(void) const;
   
       real_type
       maxX(void) const;
   
       real_type
       maxY(void) const;
   
       real_type
       maxZ(void) const;
   
       real_type
       max(
           size_t i 
       ) const;
   
       void
       max(
           vec3 const &input 
       );
   
       void
       max(
           real_type x, 
           real_type y, 
           real_type z  
       );
   
       void
       maxX(
           real_type input 
       );
   
       void
       maxY(
           real_type input 
       );
   
       void
       maxZ(
           real_type input 
       );
   
       void
       max(
           size_t i,     
           real_type input 
       );
   
       void
       translate(
           vec3 const &input 
       );
   
       void
       transform(
           affine const &matrix 
       );
   
       bool
       intersects(
           box const &input 
       ) const;
   
       void
       merged(
           box::vecptr const &boxes 
       );
   
       real_type
       centerDistance(
           vec3 const &point 
       ) const;
   
       real_type
       exteriorDistance(
           vec3 const &point 
       ) const;
   
       void
       clamp(
           vec3 const &point0, 
           vec3 const &point1, 
           vec3 const &point2  
       );
   
       void
       clamp(
           vec3 const points[3] 
       );
   
       int_type const &
       id(void) const;
   
       int_type const &
       pos(void) const;
   
     }; //class box
   
     static box const NaN_box = box(acme::NaN_vec3, acme::NaN_vec3, 0, 0); 
     static box box_goat = box(NaN_box);                                   
   
   } // namespace acme
   
   #endif
   
   ///
