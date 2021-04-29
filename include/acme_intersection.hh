/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *)
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
#include "acme_collinear.hh"
#include "acme_coplanar.hh"

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

  //! Intersection between two geometrical entities
  bool
  intersection(
      entity const *entity0,           //!< Input entity 0
      entity const *entity1,           //!< Input entity 1
      entity *entity_out = entity_goat //!< Output entity
  );

  /*\
   |    ____      _ _ _                       
   |   / ___|___ | | (_)_ __   ___  __ _ _ __ 
   |  | |   / _ \| | | | '_ \ / _ \/ _` | '__|
   |  | |__| (_) | | | | | | |  __/ (_| | |   
   |   \____\___/|_|_|_|_| |_|\___|\__,_|_|   
   |                                          
  \*/

  //! Intersection between two lines \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      line const &line0,         //!< Input line 0
      line const &line1,         //!< Input line 1
      line &line_out = line_goat //!< Output line
  );

  //! Intersection between two rays \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      ray const &ray0,        //!< Input ray 0
      ray const &ray1,        //!< Input ray 1
      ray &ray_out = ray_goat //!< Output ray
  );

  //! Intersection between two segments \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      segment const &segment0,            //!< Input segment 0
      segment const &segment1,            //!< Input segment 1
      segment &segment_out = segment_goat //!< Output segment
  );

  //! Intersection between line and ray \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      line const &line,       //!< Input line
      ray const &ray_in,      //!< Input ray
      ray &ray_out = ray_goat //!< Output ray
  );

  //! Intersection between line and segment \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      line const &line,                   //!< Input line
      segment const &segment_in,          //!< Input segment
      segment &segment_out = segment_goat //!< Output segment
  );

  //! Intersection between ray and segment \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      ray const &ray,                     //!< Input ray
      segment const &segment_in,          //!< Input segment
      segment &segment_out = segment_goat //!< Output segment
  );

  /*\
   |    ____                      _      
   |   / ___| ___ _ __   ___ _ __(_) ___ 
   |  | |  _ / _ \ '_ \ / _ \ '__| |/ __|
   |  | |_| |  __/ | | |  __/ |  | | (__ 
   |   \____|\___|_| |_|\___|_|  |_|\___|
   |                                     
  \*/

  //! Intersection between two lines \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      line const &line0,      //!< Input line 0
      line const &line1,      //!< Input line 1
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection between two rays \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      ray const &ray0,        //!< Input ray 0
      ray const &ray1,        //!< Input ray 1
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection between two segments \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      segment const &segment0, //!< Input segment 0
      segment const &segment1, //!< Input segment 1
      vec3 &point = vec3_goat  //!< Output point
  );

  //! Intersection line with ray \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      line const &line,       //!< Input line
      ray const &ray,         //!< Input ray
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection line with segment  \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      line const &line,       //!< Input line
      segment const &segment, //!< Input segment
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection ray with segment \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      ray const &ray,         //!< Input ray
      segment const &segment, //!< Input segment
      vec3 &point = vec3_goat //!< Output point
  );

  /*\
   |    ____            _                        
   |   / ___|___  _ __ | | __ _ _ __   __ _ _ __ 
   |  | |   / _ \| '_ \| |/ _` | '_ \ / _` | '__|
   |  | |__| (_) | |_) | | (_| | | | | (_| | |   
   |   \____\___/| .__/|_|\__,_|_| |_|\__,_|_|   
   |             |_|                             
  \*/

  //! Intersection between planes \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      plane const &plane0,          //!< Input plane 0
      plane const &plane1,          //!< Input plane 1
      plane &plane_out = plane_goat //!< Output plane
  );

  // //! Intersection triangle with circle \n
  // //! WARNING: This function does only support coplanar objects!
  // bool
  // intersection(
  //     triangle const &triangle, //!< Input triangle
  //     triangle const &triangle, //!< Input triangle
  //     ?????????
  // );

  // //! Intersection triangle with circle \n
  // //! WARNING: This function does only support coplanar objects!
  // bool
  // intersection(
  //     circle const &circle, //!< Input circle
  //     circle const &circle, //!< Input circle
  //     ?????????
  // );

  //! Intersection line with plane \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      line const &line_in,       //!< Input line
      plane const &plane,        //!< Input plane
      line &line_out = line_goat //!< Output line
  );

  //! Intersection line with triangle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      line const &line,               //!< Input line
      triangle const &triangle,       //!< Input triangle
      segment &segment = segment_goat //!< Output segment
  );

  //! Intersection line with circle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      line const &line,               //!< Input line
      circle const &circle,           //!< Input circle
      segment &segment = segment_goat //!< Output segment
  );

  //! Intersection ray with plane \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      ray const &ray_in,      //!< Input ray
      plane const &plane,     //!< Input plane
      ray &ray_out = ray_goat //!< Output ray
  );

  //! Intersection ray with triangle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      ray const &ray,                 //!< Input ray
      triangle const &triangle,       //!< Input triangle
      segment &segment = segment_goat //!< Output segment
  );

  //! Intersection ray with circle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      ray const &ray,                 //!< Input ray
      circle const &circle,           //!< Input circle
      segment &segment = segment_goat //!< Output segment
  );

  //! Intersection ray with plane \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      plane const &plane,                 //!< Input plane
      segment const &segment_in,          //!< Input segment
      segment &segment_out = segment_goat //!< Output segment
  );

  //! Intersection plane with triangle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      plane const &plane,                    //!< Input plane
      triangle const &triangle_in,           //!< Input triangle
      triangle &triangle_out = triangle_goat //!< Output triangle
  );

  //! Intersection plane with circle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      plane const &plane,              //!< Input plane
      circle const &circle_in,         //!< Input circle
      circle &circle_out = circle_goat //!< Output circle
  );

  //! Intersection segment with triangle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      segment const &segment_in,          //!< Input segment
      triangle const &triangle,           //!< Input triangle
      segment &segment_out = segment_goat //!< Output segment
  );

  //! Intersection segment with circle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      segment const &segment_in,          //!< Input segment
      circle const &circle_in,            //!< Input circle
      segment &segment_out = segment_goat //!< Output segment
  );

  // //! Intersection triangle with circle \n
  // //! WARNING: This function does only support coplanar objects!
  // bool
  // intersection(
  //     triangle const &triangle, //!< Input triangle
  //     circle const &circle,     //!< Input circle
  //     ?????????
  // );

  /*\
   |   _   _              ____            _                        
   |  | \ | | ___  _ __  / ___|___  _ __ | | __ _ _ __   __ _ _ __ 
   |  |  \| |/ _ \| '_ \| |   / _ \| '_ \| |/ _` | '_ \ / _` | '__|
   |  | |\  | (_) | | | | |__| (_) | |_) | | (_| | | | | (_| | |   
   |  |_| \_|\___/|_| |_|\____\___/| .__/|_|\__,_|_| |_|\__,_|_|   
   |                               |_|                             
  \*/

  //! Intersection between two planes \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane0,   //!< Input plane 0
      plane const &plane1,   //!< Input plane 1
      line &line = line_goat //!< Output line
  );

  //! Intersection between three planes \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane0,    //!< Input plane 0
      plane const &plane1,    //!< Input plane 1
      plane const &plane2,    //!< Input plane 1
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection between triangles \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      triangle const &triangle0,      //!< Input triangle 0
      triangle const &triangle1,      //!< Input triangle 1
      segment &segment = segment_goat //!< Output segment
  );

  //! Intersection between circles \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      circle const &circle0,          //!< Input circle 0
      circle const &circle1,          //!< Input circle 1
      segment &segment = segment_goat //!< Output segment
  );

  //! Intersection line with plane \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line,       //!< Input line
      plane const &plane,     //!< Input plane
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection line with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line,         //!< Input line
      triangle const &triangle, //!< Input triangle
      vec3 &point = vec3_goat   //!< Output point
  );

  //! Intersection line and circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line,       //!< Input line
      circle const &circle,   //!< Input circle
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection ray with plane \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,         //!< Input ray
      plane const &plane,     //!< Input plane
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection ray with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,           //!< Input ray
      triangle const &triangle, //!< Input triangle
      vec3 &point = vec3_goat   //!< Output point
  );

  //! Intersection ray with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray,         //!< Input ray
      circle const &circle,   //!< Input circle
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection plane with segment \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane,     //!< Input plane
      segment const &segment, //!< Input segment
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection plane with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane,             //!< Input plane
      triangle const &triangle,       //!< Input triangle
      segment &segment = segment_goat //!< Output segment
  );

  //! Intersection plane with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane,             //!< Input plane
      circle const &circle,           //!< Input circle
      segment &segment = segment_goat //!< Output segment
  );

  //! Intersection ray with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      segment const &segment,   //!< Input segment
      triangle const &triangle, //!< Input triangle
      vec3 &point = vec3_goat   //!< Output point
  );

  //! Intersection segment with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      segment const &segment, //!< Input segment
      circle const &circle,   //!< Input circle
      vec3 &point = vec3_goat //!< Output point
  );

  //! Intersection triangle with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      triangle const &triangle,       //!< Input triangle
      circle const &circle,           //!< Input circle
      segment &segment = segment_goat //!< Output plane
  );

  /*\
   |   __  __ _              _ _                                  
   |  |  \/  (_)___  ___ ___| | | __ _ _ __   ___  ___  _   _ ___ 
   |  | |\/| | / __|/ __/ _ \ | |/ _` | '_ \ / _ \/ _ \| | | / __|
   |  | |  | | \__ \ (_|  __/ | | (_| | | | |  __/ (_) | |_| \__ \
   |  |_|  |_|_|___/\___\___|_|_|\__,_|_| |_|\___|\___/ \__,_|___/
   |                                                              
  \*/

  //! Intersection between two axis aligned boxes
  bool
  intersection(
      box const &box0,    //!< Input box 0
      box const &box1,    //!< Input box 1
      box &box = box_goat //!< Output box
  );

} // namespace acme

#endif

///
/// eof: acme_intersection.hh
///