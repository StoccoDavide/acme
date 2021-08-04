
.. _program_listing_file_include_acme_ball.hh:

Program Listing for File acme_ball.hh
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_acme_ball.hh>` (``include/acme_ball.hh``)

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
   
   
   #ifndef INCLUDE_ACME_BALL
   #define INCLUDE_ACME_BALL
   
   #include "acme.hh"
   #include "acme_aabb.hh"
   #include "acme_point.hh"
   
   namespace acme
   {
   
     /*\
      |             _                   
      |   ___ _ __ | |__   ___ _ __ ___ 
      |  / __| '_ \| '_ \ / _ \ '__/ _ \
      |  \__ \ |_) | | | |  __/ | |  __/
      |  |___/ .__/|_| |_|\___|_|  \___|
      |      |_|                        
     \*/
   
   
     class ball : public entity
     {
     private:
       real m_radius;  
       point m_center; 
   
     public:
       ~ball() {}
   
       ball() {}
   
       ball(ball const &) = default;
   
       ball(ball &&) = default;
   
       ball(
           real radius,   
           real center_x, 
           real center_y, 
           real center_z  
       );
   
       ball(
           real radius,        
           point const &center 
       );
   
       ball &
       operator=(
           ball const &ball_in 
       );
   
       bool
       isApprox(
           ball const &ball_in, 
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
   
       real
       area(void) const;
   
       real
       volume(void) const;
   
       void
       translate(
           vec3 const &vector_in 
           ) override;
   
       void
       transform(
           affine const &affine_in 
           ) override;
   
       // Check whether the point is inside the ball
       bool
       isInside(
           point const &point_in,   
           real tolerance = EPSILON 
       ) const;
   
       bool
       isDegenerated(
           real tolerance = EPSILON 
       ) const override;
   
       integer level(void) const override { return 9; }
   
       std::string type(void) const override { return "ball"; }
   
       bool isNone(void) const override { return false; }
   
       bool isPoint(void) const override { return false; }
   
       bool isLine(void) const override { return false; }
   
       bool isRay(void) const override { return false; }
   
       bool isPlane(void) const override { return false; }
   
       bool isSegment(void) const override { return false; }
   
       bool isTriangle(void) const override { return false; }
   
       bool isDisk(void) const override { return false; }
   
       bool isBall(void) const override { return true; }
   
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
   
     }; // class ball
   
     static ball const NAN_BALL = ball(QUIET_NAN, NAN_POINT); 
     static ball THROWAWAY_BALL = ball(NAN_BALL);           
   
   } // namespace acme
   
   #endif
   
   ///
