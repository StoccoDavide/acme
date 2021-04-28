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

///
/// file: acme_intersection.hh
///

#ifndef INCLUDE_ACME_INTERSECTION
#define INCLUDE_ACME_INTERSECTION

#include "acme.hh"
#include "acme_line.hh"
#include "acme_ray.hh"
#include "acme_plane.hh"
#include "acme_segment.hh"
#include "acme_triangle.hh"
#include "acme_box.hh"
#include "acme_circle.hh"

namespace acme
{

  /*\
   |   ___       _                          _   _             
   |  |_ _|_ __ | |_ ___ _ __ ___  ___  ___| |_(_) ___  _ __  
   |   | || '_ \| __/ _ \ '__/ __|/ _ \/ __| __| |/ _ \| '_ \ 
   |   | || | | | ||  __/ |  \__ \  __/ (__| |_| | (_) | | | |
   |  |___|_| |_|\__\___|_|  |___/\___|\___|\__|_|\___/|_| |_|
   |                                                          
  \*/

  //! Intersection between two geometrical entities \n
  //! WARNING: This function does not support parallel objects!
  bool
  intersection(
      entity const &entity0, //!< Input line 0
      entity const &entity1, //!< Input line 1
      vec3 &point            //!< Output point
  );

  //! Intersection between two lines \n
  //! WARNING: This function does not support parallel objects!
  bool
  intersection(
      line const &line0, //!< Input line 0
      line const &line1, //!< Input line 1
      vec3 &point        //!< Output point
  );

  //! Intersection between two rays \n
  //! WARNING: This function does not support parallel objects!
  bool
  intersection(
      ray const &ray0, //!< Input ray 0
      ray const &ray1, //!< Input ray 1
      vec3 &point      //!< Output point
  );

  //! Intersection between two planes \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane0, //!< Input plane 0
      plane const &plane1, //!< Input plane 1
      line &line           //!< Output line
  );

  //! Intersection between three planes \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane0, //!< Input plane 0
      plane const &plane1, //!< Input plane 1
      plane const &plane2, //!< Input plane 1
      vec3 &point          //!< Output point
  );

  //! Intersection between two segments \n
  //! WARNING: This function does not support parallel objects!
  bool
  intersection(
      segment const &segment0, //!< Input segment 0
      segment const &segment1, //!< Input segment 1
      vec3 &point              //!< Output point
  );

  //! Intersection between two triangles \n
  //! WARNING: This function does not support parallel objects!
  bool
  intersection(
      triangle const &triangle0, //!< Input triangle 0
      triangle const &triangle1, //!< Input triangle 1
      segment &segment           //!< Output segment
  );

  //! Intersection between two circles \n
  //! WARNING: This function does not support parallel objects!
  bool
  intersection(
      circle const &circle0, //!< Input circle 0
      circle const &circle1, //!< Input circle 1
      segment &segment       //!< Output segment
  );

  //! Intersection between two boxes \n
  bool
  intersection(
      box const &box0, //!< Input box 0
      box const &box1, //!< Input box 1
      box &box         //!< Output box
  );

  //! Intersection line with ray \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line, //!< Input line
      ray const &ray,   //!< Input ray
      vec3 &point       //!< Output point
  );

  //! Intersection line with plane \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line,   //!< Input line
      plane const &plane, //!< Input plane
      vec3 &point         //!< Output point
  );

  //! Intersection line with segment  \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line,       //!< Input line
      segment const &segment, //!< Input segment
      vec3 &point             //!< Output point
  );

  //! Intersection line with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line,         //!< Input line
      triangle const &triangle, //!< Input triangle
      vec3 &point               //!< Output point
  );

  //! Intersection line and circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line,     //!< Input line
      circle const &circle, //!< Input circle
      vec3 &point           //!< Output point
  );

  //! Intersection ray with plane \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,     //!< Input ray
      plane const &plane, //!< Input plane
      vec3 &point         //!< Output point
  );

  //! Intersection ray with segment \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,         //!< Input ray
      segment const &segment, //!< Input segment
      vec3 &point             //!< Output point
  );

  //! Intersection ray with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,           //!< Input ray
      triangle const &triangle, //!< Input triangle
      vec3 &point               //!< Output point
  );

  //! Intersection ray with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,       //!< Input ray
      circle const &circle, //!< Input circle
      vec3 &point           //!< Output point
  );

  //! Intersection plane with segment \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane,     //!< Input plane
      segment const &segment, //!< Input segment
      vec3 &point             //!< Output point
  );

  //! Intersection plane with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane,       //!< Input plane
      triangle const &triangle, //!< Input triangle
      segment &segment          //!< Output segment
  );

  //! Intersection plane with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane,   //!< Input plane
      circle const &circle, //!< Input circle
      segment &segment      //!< Output segment
  );

  //! Intersection ray with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      segment const &segment,   //!< Input segment
      triangle const &triangle, //!< Input triangle
      vec3 &point               //!< Output point
  );

  //! Intersection segment with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      segment const &segment, //!< Input segment
      circle const &circle,   //!< Input circle
      vec3 &point             //!< Output point
  );

  //! Intersection triangle with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      triangle const &triangle, //!< Input triangle
      circle const &circle,     //!< Input circle
      segment &segment          //!< Output plane
  );

  /*\
   |    ____            _                        
   |   / ___|___  _ __ | | __ _ _ __   __ _ _ __ 
   |  | |   / _ \| '_ \| |/ _` | '_ \ / _` | '__|
   |  | |__| (_) | |_) | | (_| | | | | (_| | |   
   |   \____\___/| .__/|_|\__,_|_| |_|\__,_|_|   
   |             |_|                             
  \*/

  //! Intersection between two lines \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      line const &line0, //!< Input line 0
      line const &line1, //!< Input line 1
      line &line         //!< Output line
  );

  //! Intersection between two rays \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      ray const &ray0, //!< Input ray 0
      ray const &ray1, //!< Input ray 1
      ray &ray         //!< Output ray
  );

  //! Intersection between two planes \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      plane const &plane0, //!< Input plane 0
      plane const &plane1, //!< Input plane 1
      plane &plane         //!< Output plane
  );

  //! Intersection between two segments \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      segment const &segment0, //!< Input segment 0
      segment const &segment1, //!< Input segment 1
      segment &segment         //!< Output segment
  );

  //! Intersection between two triangles \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      triangle const &triangle0, //!< Input triangle 0
      triangle const &triangle1, //!< Input triangle 1
      triangle &triangle         //!< Output triangle
  );

  //! Intersection between line and ray \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      line const &line,  //!< Input line
      ray const &ray_in, //!< Input ray
      ray &ray_out       //!< Output ray
  );

  //! Intersection between line and plane \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      line const &line,      //!< Input line
      plane const &plane_in, //!< Input plane
      plane &plane_out       //!< Output plane
  );

  //! Intersection between line and segment \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      line const &line,          //!< Input line
      segment const &segment_in, //!< Input segment
      segment &segment_out       //!< Output segment
  );

  //! Intersection line with triangle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      line const &line,         //!< Input line
      triangle const &triangle, //!< Input triangle
      segment &segment          //!< Output segment
  );

  //! Intersection line with circle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      line const &line,     //!< Input line
      circle const &circle, //!< Input circle
      segment &segment      //!< Output segment
  );

  //! Intersection between ray and plane \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      ray const &ray_in,  //!< Input ray
      plane const &plane, //!< Input plane
      ray &ray_out        //!< Output ray
  );

  //! Intersection between ray and segment \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      ray const &ray,            //!< Input ray
      segment const &segment_in, //!< Input segment
      segment &segment_out       //!< Output segment
  );

  //! Intersection ray with triangle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      ray const &ray,           //!< Input ray
      triangle const &triangle, //!< Input triangle
      segment &segment          //!< Output segment
  );

  //! Intersection ray with circle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      ray const &ray,       //!< Input ray
      circle const &circle, //!< Input circle
      segment &segment      //!< Output segment
  );

  //! Intersection plane with segment \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      plane const &plane,        //!< Input plane
      segment const &segment_in, //!< Input segment
      segment &segment_out       //!< Output segment
  );

  //! Intersection plane with triangle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      plane const &plane,          //!< Input plane
      triangle const &triangle_in, //!< Input triangle
      triangle &triangle_out       //!< Output triangle
  );

  //! Intersection plane with circle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      plane const &plane,      //!< Input plane
      circle const &circle_in, //!< Input circle
      circle &circle_out       //!< Output circle
  );

  //! Intersection segment with triangle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      segment const &segment_in, //!< Input segment
      triangle const &triangle,  //!< Input triangle
      segment &segment_out       //!< Output segment
  );

  //! Intersection segment with circle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      segment const &segment_in, //!< Input segment
      circle const &circle,      //!< Input circle
      segment &segment_out       //!< Output segment
  );

  //! Intersection circle with triangle \n
  //! WARNING: This function only support coplanar objects!
  bool
  intersection(
      triangle const &triangle, //!< Input triangle
      circle const &circle,     //!< Input circle
      segment &segment          //!< Output segment
  );

} // namespace acme

#endif

///
/// eof: acme_intersection.hh
///