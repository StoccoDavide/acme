///
/// file: acme_intersect3.hh
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

#ifndef INCLUDE_ACME_INTERSECT3
#define INCLUDE_ACME_INTERSECT3

#include "acme.hh"

namespace acme
{

  /*\
   |   ___       _                          _   _____ 
   |  |_ _|_ __ | |_ ___ _ __ ___  ___  ___| |_|___ / 
   |   | || '_ \| __/ _ \ '__/ __|/ _ \/ __| __| |_ \ 
   |   | || | | | ||  __/ |  \__ \  __/ (__| |_ ___) |
   |  |___|_| |_|\__\___|_|  |___/\___|\___|\__|____/ 
   |                                                   
  \*/

  //! Intersect between three planes
  template <typename T>
  inline bool intersect(
      const plane3<T> &plane0, //!< Input plane 0
      const plane3<T> &plane1, //!< Input plane 1
      const plane3<T> &plane2, //!< Input plane 1
      point3<T> &point         //!< Output point
  )
  {
    vector3<T> normal0 = plane0.normal();
    vector3<T> normal1 = plane1.normal();
    vector3<T> normal2 = plane2.normal();

    T det = Eigen::Matrix<T, 3, 3>::det(normal0, normal1, normal2);
    if (acme::is_equal(det, T(0.0)))
    {
      return false;
    }
    else
    {
      point.data((normal1.cross(normal2) * -plane0.d() +
                  normal2.cross(normal0) * -plane1.d() +
                  normal0.cross(normal1) * -plane2.d()) /
                 det);
      return true;
    }
  }

  //! Intersect between two planes
  template <typename T>
  inline bool intersect(
      const plane3<T> &plane0, //!< Input plane 0
      const plane3<T> &plane1, //!< Input plane 1
      line3<T> &line           //!< Output line
  )
  {
    vector3<T> normal0 = plane0.normal();
    vector3<T> normal1 = plane1.normal();

    vector3<T> line_d = normal0.cross(normal1);
    T det = line_d.norm() * line_d.norm();
    if (acme::is_equal(det, T(0.0)))
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
  template <typename T>
  inline bool intersect(
      const ray3<T> &ray,     //!< Input ray
      const plane3<T> &plane, //!< Input plane
      point3<T> &point        //!< Output point
  )
  {
    T det = dotProduct(ray.direction(), plane.normal());
    if (det > acme::Epsilon)
    {
      T t = -(ray.origin() - plane.origin()).dot(plane.normal()) / det;
      if (t > acme::Epsilon)
      {
        point.data(ray.origin() + ray.direction() * t);
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
  template <typename T>
  inline bool intersect(
      const line3<T> &line,   //!< Input line
      const plane3<T> &plane, //!< Input plane
      point3<T> &point        //!< Output point
  )
  {
    T det = dotProduct(line.direction(), plane.normal());
    if (det > acme::Epsilon)
    {
      T t = -(line.origin() - plane.origin()).dot(plane.normal()) / det;
      point.data(line.origin() + line.direction() * t);
      return true;
    }
    else
    {
      return false;
    }
  }

  //! Intersect segment with plane
  template <typename T>
  inline bool intersect(
      const segment3<T> &segment, //!< Input segment
      const plane3<T> &plane,     //!< Input plane
      point3<T> &point            //!< Output point
  )
  {
    T d0 = distance(segment.point_0());
    T d1 = distance(segment.point_1());
    if (d0 * d1 > 0)
    {
      return false;
    }
    else
    {
      T t = d0 / (d0 - d1);
      point = segment.point_0() + t * (segment.point_1() - segment.point_0());

      return true;
    }
  }

  //! Intersect triangle with plane
  template <typename T>
  inline bool intersect(
      const triangle3<T> &triangle, //!< Input triangle
      const plane3<T> &plane,       //!< Input plane
      segment3<T> &segment          //!< Input plane
  )
  {
    point3<T> point0, point1, point2;
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

  //! Intersect triangle with ray
  template <typename T>
  inline bool intersect(
      const triangle3<T> &triangle, //!< Input triangle
      const ray3<T> &ray,           //!< Input plane
      point3<T> &point              //!< Output point
  )
  {
    vector3<T> vertex0 = triangle.point_0();
    vector3<T> vertex1 = triangle.point_1();
    vector3<T> vertex2 = triangle.point_2();
    vector3<T> edge1 = vertex1 - vertex0;
    vector3<T> edge2 = vertex2 - vertex0;

    vector3<T> origin = ray.origin().toVector();
    vector3<T> direction = ray.direction();

    vector3<T> h, s, q;
    T a, f, u, v;
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
    float t = f * edge2.dotProduct(q);
    if (t > acme::Epsilon)
    {
      point = origin + direction * t;
      return true;
    }
    else
      return false;
  }

} // namespace acme

#endif

///
/// eof: acme_istersect3.hh
///