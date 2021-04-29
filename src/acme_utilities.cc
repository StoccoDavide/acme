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
/// file: acme_utilities.cc
///

#include "acme_utilities.hh"

namespace acme
{
  /*\
   |         _   _ _ _ _   _           
   |   _   _| |_(_) (_) |_(_) ___  ___ 
   |  | | | | __| | | | __| |/ _ \/ __|
   |  | |_| | |_| | | | |_| |  __/\__ \
   |   \__,_|\__|_|_|_|\__|_|\___||___/
   |                                   
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &
  operator<<(
      ostream_type &os,
      line const &obj)
  {
    vec3 obj_origin(obj.origin());
    vec3 obj_direction(obj.direction());
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << std::endl
       << "Origin = "
       << "[ " << obj_origin[0] << ", " << obj_origin[1] << ", " << obj_origin[2] << " ]'"
       << std::endl
       << "Direction = "
       << "[ " << obj_direction[0] << ", " << obj_direction[2] << ", " << obj_direction[2] << " ]'";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &
  operator<<(
      ostream_type &os,
      ray const &obj)
  {
    vec3 obj_origin(obj.origin());
    vec3 obj_direction(obj.direction());
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << std::endl
       << "Origin = "
       << "[ " << obj_origin[0] << ", " << obj_origin[1] << ", " << obj_origin[2] << " ]'"
       << std::endl
       << "Direction = "
       << "[ " << obj_direction[0] << ", " << obj_direction[2] << ", " << obj_direction[2] << " ]'";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &
  operator<<(
      ostream_type &os,
      plane const &obj)
  {
    vec3 obj_origin(obj.origin());
    vec3 obj_normal(obj.normal());
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << std::endl
       << "Origin = "
       << "[ " << obj_origin[0] << ", " << obj_origin[1] << ", " << obj_origin[2] << " ]'"
       << std::endl
       << "Normal = "
       << "[ " << obj_normal[0] << ", " << obj_normal[1] << ", " << obj_normal[2] << " ]'";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &
  operator<<(
      ostream_type &os,
      segment const &obj)
  {
    vec3 obj_point_0(obj.point(0));
    vec3 obj_point_1(obj.point(1));
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << std::endl
       << "Point 0 = "
       << "[ " << obj_point_0[0] << ", " << obj_point_0[1] << ", " << obj_point_0[2] << " ]'"
       << std::endl
       << "Point 1 = "
       << "[ " << obj_point_1[0] << ", " << obj_point_1[1] << ", " << obj_point_1[2] << " ]'";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &
  operator<<(
      ostream_type &os,
      box const &obj)
  {
    vec3 obj_point_min(obj.min());
    vec3 obj_point_max(obj.max());
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << std::endl
       << "Point min = "
       << "[ " << obj_point_min[0] << ", " << obj_point_min[1] << ", " << obj_point_min[2] << " ]'"
       << std::endl
       << "Point max = "
       << "[ " << obj_point_max[0] << ", " << obj_point_max[1] << ", " << obj_point_max[2] << " ]'";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &
  operator<<(
      ostream_type &os,
      triangle const &obj)
  {
    vec3 obj_vertex_0(obj.vertex(0));
    vec3 obj_vertex_2(obj.vertex(1));
    vec3 obj_vertex_1(obj.vertex(2));
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << std::endl
       << "Vertex 0 = "
       << "[ " << obj_vertex_0[0] << ", " << obj_vertex_0[1] << ", " << obj_vertex_0[2] << " ]'" << std::endl
       << "Vertex 1 = "
       << "[ " << obj_vertex_1[0] << ", " << obj_vertex_1[1] << ", " << obj_vertex_1[2] << " ]'" << std::endl
       << "Vertex 2 = "
       << "[ " << obj_vertex_2[0] << ", " << obj_vertex_2[1] << ", " << obj_vertex_2[2] << " ]'";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &
  operator<<(
      ostream_type &os,
      circle const &obj)
  {
    vec3 obj_center(obj.center());
    vec3 obj_normal(obj.normal());
    os << std::scientific
       << std::showpoint
       << std::setprecision(10)
       << std::endl
       << "Center = "
       << "[ " << obj_center[0] << ", " << obj_center[1] << ", " << obj_center[2] << " ]'"
       << std::endl
       << "Normal = "
       << "[ " << obj_normal[0] << ", " << obj_normal[1] << ", " << obj_normal[2] << " ]'"
       << std::endl
       << "Radius = " << obj.radius();
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ostream_type &
  operator<<(
      ostream_type &os,
      affine const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(10)
       << std::endl
       << "Affine = "
       << "[ " << obj(0, 0) << ", " << obj(0, 1) << ", " << obj(0, 2) << ", " << obj(0, 3) << " ]"
       << "[ " << obj(1, 0) << ", " << obj(1, 1) << ", " << obj(1, 2) << ", " << obj(1, 3) << " ]"
       << "[ " << obj(2, 0) << ", " << obj(2, 1) << ", " << obj(2, 2) << ", " << obj(2, 3) << " ]"
       << "[ " << obj(3, 0) << ", " << obj(3, 1) << ", " << obj(3, 2) << ", " << obj(3, 3) << " ]";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_utilities.cc
///