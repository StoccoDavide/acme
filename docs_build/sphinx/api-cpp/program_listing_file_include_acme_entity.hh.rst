
.. _program_listing_file_include_acme_entity.hh:

Program Listing for File acme_entity.hh
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_entity.hh>` (``include/acme_entity.hh``)

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
   
   
   #ifndef INCLUDE_ACME_ENTITY
   #define INCLUDE_ACME_ENTITY
   
   #include "acme.hh"
   
   namespace acme
   {
   
     /*\
      |              _   _ _
      |    ___ _ __ | |_(_) |_ _   _
      |   / _ \ '_ \| __| | __| | | |
      |  |  __/ | | | |_| | |_| |_| |
      |   \___|_| |_|\__|_|\__|\__, |
      |                        |___/
     \*/
   
   
     class entity
     {
     public:
       typedef std::shared_ptr<entity> ptr; 
       typedef std::vector<ptr> vecptr;     
   
       virtual ~entity(){};
   
       entity(){};
   
       virtual void
       translate(
           vec3 const &input 
           ) = 0;
   
       virtual void
       transform(
           affine const &matrix 
           ) = 0;
   
       void
       rotate(
           real angle,      
           vec3 const &axis 
       );
   
       virtual bool isDegenerated(
           real tolerance = EPSILON 
       ) const = 0;
   
       virtual integer level(void) const = 0;
   
       virtual std::string type(void) const = 0;
   
       bool isEntity(void) const;
   
       virtual bool isNone(void) const = 0;
   
       virtual bool isPoint(void) const = 0;
   
       virtual bool isLine(void) const = 0;
   
       virtual bool isRay(void) const = 0;
   
       virtual bool isPlane(void) const = 0;
   
       virtual bool isSegment(void) const = 0;
   
       virtual bool isTriangle(void) const = 0;
   
       virtual bool isDisk(void) const = 0;
   
       virtual bool isBall(void) const = 0;
   
       virtual bool isClampable(void) const = 0;
   
       virtual bool isNonClampable(void) const = 0;
   
       virtual bool
       clamp(
           vec3 &min, 
           vec3 &max  
       ) const = 0;
   
       virtual bool
       clamp(
           real &min_x, 
           real &min_y, 
           real &min_z, 
           real &max_x, 
           real &max_y, 
           real &max_z  
       ) const = 0;
   
     }; // class entity
   
   } // namespace acme
   
   #endif
   
   ///
