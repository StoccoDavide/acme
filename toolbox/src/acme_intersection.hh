/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020-2021_in, Davide Stocco and Enrico Bertolazzi.       *)
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
#include "acme_aabb.hh"
#include "acme_circle.hh"
#include "acme_collinear.hh"
#include "acme_coplanar.hh"
#include "acme_line.hh"
#include "acme_none.hh"
#include "acme_plane.hh"
#include "acme_ray.hh"
#include "acme_segment.hh"
#include "acme_sphere.hh"
#include "acme_triangle.hh"

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
  entity *
  intersection(
      entity const *entity0_in, //!< Input entity 0
      entity const *entity1_in, //!< Input entity 1
      real tolerance = EPSILON  //!< Tolerance
  );

  /*\
   |   ____                   _               _ 
   |  |  _ \ _   _ _ __   ___| |_ _   _  __ _| |
   |  | |_) | | | | '_ \ / __| __| | | |/ _` | |
   |  |  __/| |_| | | | | (__| |_| |_| | (_| | |
   |  |_|    \__,_|_| |_|\___|\__|\__,_|\__,_|_| 
   |                                            
  \*/

  //! Intersection between two points
  bool
  intersection(
      point const &point0_in,             //!< Input point 0
      point const &point1_in,             //!< Input point 1
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection between point and line
  bool
  intersection(
      point const &point_in,              //!< Input point
      line const &line_in,                //!< Input line
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection between point and ray
  bool
  intersection(
      point const &point_in,              //!< Input point
      ray const &ray_in,                  //!< Input ray
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection between point and plane
  bool
  intersection(
      point const &point_in,              //!< Input point
      plane const &plane_in,              //!< Input plane
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection between point and segment
  bool
  intersection(
      point const &point_in,              //!< Input point
      segment const &segment,             //!< Input segment
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection between point and triangle
  bool
  intersection(
      point const &point_in,              //!< Input point
      triangle const &triangle_in,        //!< Input triangle
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection between point and circle
  bool
  intersection(
      point const &point_in,              //!< Input point
      circle const &circle_in,            //!< Input circle
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
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
      line const &line0_in,            //!< Input line 0
      line const &line1_in,            //!< Input line 1
      line &line_out = THROWAWAY_LINE, //!< Output line
      real tolerance = EPSILON         //!< Tolerance
  );

  //! Intersection between two rays \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      ray const &ray0_in,           //!< Input ray 0
      ray const &ray1_in,           //!< Input ray 1
      ray &ray_out = THROWAWAY_RAY, //!< Output ray
      real tolerance = EPSILON      //!< Tolerance
  );

  //! Intersection between two opposite rays \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      ray const &ray0_in,                       //!< Input ray 0
      ray const &ray1_in,                       //!< Input ray 1
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection between two segments \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      segment const &segment0_in,               //!< Input segment 0
      segment const &segment1_in,               //!< Input segment 1
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection between line and ray \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      line const &line_in,          //!< Input line
      ray const &ray_in,            //!< Input ray
      ray &ray_out = THROWAWAY_RAY, //!< Output ray
      real tolerance = EPSILON      //!< Tolerance
  );

  //! Intersection between line and segment \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      line const &line_in,                      //!< Input line
      segment const &segment_in,                //!< Input segment
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection between ray and segment \n
  //! WARNING: This function only support collinear objects!
  bool
  intersection(
      ray const &ray_in,                        //!< Input ray
      segment const &segment_in,                //!< Input segment
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
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
      line const &line0_in,               //!< Input line 0
      line const &line1_in,               //!< Input line 1
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection between two rays \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      ray const &ray0_in,                 //!< Input ray 0
      ray const &ray1_in,                 //!< Input ray 1
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection between two segments \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      segment const &segment0_in,         //!< Input segment 0
      segment const &segment1_in,         //!< Input segment 1
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection line with ray \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      line const &line_in,                //!< Input line
      ray const &ray_in,                  //!< Input ray
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection line with segment  \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      line const &line_in,                //!< Input line
      segment const &segment,             //!< Input segment
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection ray with segment \n
  //! WARNING: This function does not support collinear objects!
  bool
  intersection(
      ray const &ray_in,                  //!< Input ray
      segment const &segment,             //!< Input segment
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
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
      plane const &plane0_in,        //!< Input plane 0
      plane const &plane1_in,        //!< Input plane 1
      plane &plane_out = plane_goat, //!< Output plane
      real tolerance = EPSILON       //!< Tolerance
  );

  // //! Intersection triangle with circle \n
  // //! WARNING: This function does only support coplanar objects!
  // bool
  // intersection(
  //     triangle const &triangle_in, //!< Input triangle
  //     triangle const &triangle_in, //!< Input triangle
  //     ??????
  //     real tolerance = EPSILON     //!< Tolerance
  // );

  // //! Intersection triangle with circle \n
  // //! WARNING: This function does only support coplanar objects!
  // bool
  // intersection(
  //     circle const &circle_in, //!< Input circle
  //     circle const &circle_in, //!< Input circle
  //     ??????
  //     real tolerance = EPSILON     //!< Tolerance
  // );

  //! Intersection line with plane \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      line const &line_in,             //!< Input line
      plane const &plane_in,           //!< Input plane
      line &line_out = THROWAWAY_LINE, //!< Output line
      real tolerance = EPSILON         //!< Tolerance
  );

  //! Intersection line with triangle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      line const &line_in,                      //!< Input line
      triangle const &triangle_in,              //!< Input triangle
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection line with circle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      line const &line_in,                      //!< Input line
      circle const &circle_in,                  //!< Input circle
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection ray with plane \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      ray const &ray_in,            //!< Input ray
      plane const &plane_in,        //!< Input plane
      ray &ray_out = THROWAWAY_RAY, //!< Output ray
      real tolerance = EPSILON      //!< Tolerance
  );

  //! Intersection ray with triangle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      ray const &ray_in,                        //!< Input ray
      triangle const &triangle_in,              //!< Input triangle
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection ray with circle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      ray const &ray_in,                        //!< Input ray
      circle const &circle_in,                  //!< Input circle
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection ray with plane \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      plane const &plane_in,                    //!< Input plane
      segment const &segment_in,                //!< Input segment
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection plane with triangle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      plane const &plane_in,                       //!< Input plane
      triangle const &triangle_in,                 //!< Input triangle
      triangle &triangle_out = THROWAWAY_TRIANGLE, //!< Output triangle
      real tolerance = EPSILON                     //!< Tolerance
  );

  //! Intersection plane with circle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      plane const &plane_in,                 //!< Input plane
      circle const &circle_in,               //!< Input circle
      circle &circle_out = THROWAWAY_CIRCLE, //!< Output circle
      real tolerance = EPSILON               //!< Tolerance
  );

  //! Intersection segment with triangle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      segment const &segment_in,                //!< Input segment
      triangle const &triangle_in,              //!< Input triangle
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection segment with circle \n
  //! WARNING: This function does only support coplanar objects!
  bool
  intersection(
      segment const &segment_in,                //!< Input segment
      circle const &circle_in,                  //!< Input circle
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  // //! Intersection triangle with circle \n
  // //! WARNING: This function does only support coplanar objects!
  // bool
  // intersection(
  //     triangle const &triangle_in, //!< Input triangle
  //     circle const &circle_in,     //!< Input circle
  //     ??????
  //     real tolerance = EPSILON     //!< Tolerance
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
      plane const &plane0_in,          //!< Input plane 0
      plane const &plane1_in,          //!< Input plane 1
      line &line_out = THROWAWAY_LINE, //!< Output line
      real tolerance = EPSILON         //!< Tolerance
  );

  //! Intersection between three planes \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane0_in,             //!< Input plane 0
      plane const &plane1_in,             //!< Input plane 1
      plane const &plane2_in,             //!< Input plane 1
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection between triangles \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      triangle const &triangle0_in,             //!< Input triangle 0
      triangle const &triangle1_in,             //!< Input triangle 1
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection between circles \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      circle const &circle0_in,                 //!< Input circle 0
      circle const &circle1_in,                 //!< Input circle 1
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  // //! Intersection between spheres \n
  // //! WARNING: This function does not support coplanarity!
  // bool
  // intersection(
  //     sphere const &sphere0_in,                //!< Input sphere 0
  //     sphere const &sphere1_in,                //!< Input sphere 1
  //     ??????
  //     real tolerance = EPSILON              //!< Tolerance
  // );

  //! Intersection line with plane \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line_in,                //!< Input line
      plane const &plane_in,              //!< Input plane
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection line with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line_in,                //!< Input line
      triangle const &triangle_in,        //!< Input triangle
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection line and circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line_in,                //!< Input line
      circle const &circle_in,            //!< Input circle
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection line and sphere \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      line const &line_in,                      //!< Input line
      sphere const &sphere_in,                  //!< Input sphere
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection ray with plane \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray_in,                  //!< Input ray
      plane const &plane_in,              //!< Input plane
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection ray with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray_in,                  //!< Input ray
      triangle const &triangle_in,        //!< Input triangle
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection ray with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray_in,                  //!< Input ray
      circle const &circle_in,            //!< Input circle
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection ray and sphere \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      ray const &ray_in,                        //!< Input ray
      sphere const &sphere_in,                  //!< Input sphere
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection plane with segment \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane_in,              //!< Input plane
      segment const &segment,             //!< Input segment
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection plane with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane_in,                    //!< Input plane
      triangle const &triangle_in,              //!< Input triangle
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection plane with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane_in,                    //!< Input plane
      circle const &circle_in,                  //!< Input circle
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection plane and sphere \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      plane const &plane_in,                 //!< Input plane
      sphere const &sphere_in,               //!< Input sphere
      circle &circle_out = THROWAWAY_CIRCLE, //!< Output circle
      real tolerance = EPSILON               //!< Tolerance
  );

  //! Intersection ray with triangle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      segment const &segment_in,          //!< Input segment
      triangle const &triangle_in,        //!< Input triangle
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection segment with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      segment const &segment_in,          //!< Input segment
      circle const &circle_in,            //!< Input circle
      point &point_out = THROWAWAY_POINT, //!< Output point
      real tolerance = EPSILON            //!< Tolerance
  );

  //! Intersection segment and sphere \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      segment const &segment_in,                //!< Input segment
      sphere const &sphere_in,                  //!< Input sphere
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output segment
      real tolerance = EPSILON                  //!< Tolerance
  );

  //! Intersection triangle with circle \n
  //! WARNING: This function does not support coplanarity!
  bool
  intersection(
      triangle const &triangle_in,              //!< Input triangle
      circle const &circle_in,                  //!< Input circle
      segment &segment_out = THROWAWAY_SEGMENT, //!< Output plane
      real tolerance = EPSILON                  //!< Tolerance
  );

  // //! Intersection triangle and sphere \n
  // //! WARNING: This function does not support coplanarity!
  // bool
  // intersection(
  //     triangle const &triangle_in,           //!< Input triangle
  //     sphere const &sphere_in,               //!< Input sphere
  //     ??????
  //     real tolerance = EPSILON            //!< Tolerance
  // );

  // //! Intersection circle and sphere \n
  // //! WARNING: This function does not support coplanarity!
  // bool
  // intersection(
  //     circle const &circle_in,           //!< Input circle
  //     sphere const &sphere_in,               //!< Input sphere
  //     ??????
  //     real tolerance = EPSILON            //!< Tolerance
  // );

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
      aabb const &aabb0_in,            //!< Input aabb 0
      aabb const &aabb1_in,            //!< Input aabb 1
      aabb &aabb_out = THROWAWAY_AABB, //!< Output aabb
      real tolerance = EPSILON         //!< Tolerance
  );

} // namespace acme

#endif

///
/// eof: acme_intersection.hh
///