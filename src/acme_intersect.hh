///
/// file: acme_intersect.hh
///

/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The acme computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the acme computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

#ifndef INCLUDE_ACME_INTERSECT
#define INCLUDE_ACME_INTERSECT

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |   ___       _                          _   
   |  |_ _|_ __ | |_ ___ _ __ ___  ___  ___| |_ 
   |   | || '_ \| __/ _ \ '__/ __|/ _ \/ __| __|
   |   | || | | | ||  __/ |  \__ \  __/ (__| |_ 
   |  |___|_| |_|\__\___|_|  |___/\___|\___|\__|
   |                                            
  \*/

  //! Intersect between three planes
  bool intersect(
      const plane &plane0, //!< Input plane 0
      const plane &plane1, //!< Input plane 1
      const plane &plane2, //!< Input plane 1
      vector &point        //!< Output point
  )
  {
    const vector normal0(plane0.normal());
    const vector normal1(plane1.normal());
    const vector normal2(plane2.normal());

    matrix Mat;
    Mat << normal0, normal1, normal2;
    real_type det = Mat.determinant();
    if (acme::is_equal(det, real_type(0.0)))
    {
      return false;
    }
    else
    {
      point = ((normal1.cross(normal2) * -plane0.d() +
                normal2.cross(normal0) * -plane1.d() +
                normal0.cross(normal1) * -plane2.d()) /
               det);
      return true;
    }
  }

  //! Intersect between two planes
  bool intersect(
      const plane &plane0, //!< Input plane 0
      const plane &plane1, //!< Input plane 1
      line &line           //!< Output line
  )
  {
    vector normal0 = plane0.normal();
    vector normal1 = plane1.normal();

    vector line_d = normal0.cross(normal1);
    real_type det = line_d.norm() * line_d.norm();
    if (acme::is_equal(det, real_type(0.0)))
    {
      return false;
    }
    else
    {
      line.origin((line_d.cross(normal1) * plane0.d()) +
                  (normal0.cross(line_d) * plane1.d()) / det);
      line.direction(line_d);
      return true;
    }
  }

  //! Intersect ray with plane
  bool intersect(
      const ray &ray,     //!< Input ray
      const plane &plane, //!< Input plane
      vector &point       //!< Output point
  )
  {
    real_type det = ray.direction().dot(plane.normal());
    if (det > acme::Epsilon)
    {
      real_type t = -(ray.origin() - plane.origin()).dot(plane.normal()) / det;
      if (t > acme::Epsilon)
      {
        point = ray.origin() + ray.direction() * t;
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  //! Intersect line with plane
  bool intersect(
      const line &line,   //!< Input line
      const plane &plane, //!< Input plane
      vector &point       //!< Output point
  )
  {
    real_type det = line.direction().dot(plane.normal());
    if (det > acme::Epsilon)
    {
      real_type t = -(line.origin() - plane.origin()).dot(plane.normal()) / det;
      point = line.origin() + line.direction() * t;
      return true;
    }
    else
    {
      return false;
    }
  }

  //! Intersect segment with plane
  bool intersect(
      const segment &segment, //!< Input segment
      const plane &plane,     //!< Input plane
      vector &point           //!< Output point
  )
  {
    real_type d0 = plane.distance(segment.point_0());
    real_type d1 = plane.distance(segment.point_1());
    if (d0 * d1 > 0)
    {
      return false;
    }
    else
    {
      real_type t = d0 / (d0 - d1);
      point = segment.point_0() + t * (segment.point_1() - segment.point_0());

      return true;
    }
  }

  //! Intersect triangle with plane
  bool intersect(
      const triangle &triangle, //!< Input triangle
      const plane &plane,       //!< Input plane
      segment &segment          //!< Input plane
  )
  {
    vector point0, point1, point2;
    bool bool0, bool1, bool2;
    bool0 = intersect(triangle.edge_0(), plane, point0);
    bool1 = intersect(triangle.edge_1(), plane, point1);
    bool2 = intersect(triangle.edge_2(), plane, point2);

    if (bool0 && bool1)
    {
      segment.points(point0, point1);
      return true;
    }
    else if (bool1 && bool2)
    {
      segment.points(point1, point2);
      return true;
    }
    else if (bool2 && bool0)
    {
      segment.points(point2, point0);
      return true;
    }
    else
    {
      return false;
    }
  }

  //! Intersect triangle with ray (no precalculated normal)
  bool intersect(
      const triangle &triangle, //!< Input triangle
      const ray &ray,           //!< Input plane
      vector &point             //!< Output point
  )
  {
    vector vertex0 = triangle.vertex_0();
    vector vertex1 = triangle.vertex_1();
    vector vertex2 = triangle.vertex_2();
    vector edge1 = vertex1 - vertex0;
    vector edge2 = vertex2 - vertex0;

    vector origin = ray.origin();
    vector direction = ray.direction();

    vector h, s, q;
    real_type a, f, u, v;
    h = direction.cross(edge2);
    a = edge1.dot(h);
    if (a > -acme::Epsilon && a < acme::Epsilon)
      return false;
    f = 1.0 / a;
    s = origin - vertex0;
    u = f * s.dot(h);
    if (u < 0.0 || u > 1.0)
      return false;
    q = s.cross(edge1);
    v = f * direction.dot(q);
    if (v < 0.0 || u + v > 1.0)
      return false;
    float t = f * edge2.dot(q);
    if (t > acme::Epsilon)
    {
      point = origin + direction * t;
      return true;
    }
    else
      return false;
  }

  //! Intersect triangle with line (no precalculated normal)
  bool intersect(
      const triangle &triangle, //!< Input triangle
      const line &line,           //!< Input plane
      vector &point             //!< Output point
  )
  {
    vector vertex0 = triangle.vertex_0();
    vector vertex1 = triangle.vertex_1();
    vector vertex2 = triangle.vertex_2();
    vector edge1 = vertex1 - vertex0;
    vector edge2 = vertex2 - vertex0;

    vector origin = line.origin();
    vector direction = line.direction();

    vector h, s, q;
    real_type a, f, u, v;
    h = direction.cross(edge2);
    a = edge1.dot(h);
    if (a > -acme::Epsilon && a < acme::Epsilon)
      return false;
    f = 1.0 / a;
    s = origin - vertex0;
    u = f * s.dot(h);
    if (u < 0.0 || u > 1.0)
      return false;
    q = s.cross(edge1);
    v = f * direction.dot(q);
    if (v < 0.0 || u + v > 1.0)
      return false;
    float t = f * edge2.dot(q);
    point = origin + direction * t;
    return true;
  }

} // namespace acme

#endif

///
/// eof: acme_intersect.hh
///