/*
(***********************************************************************)
(*                                                                     *)
(* The ACME computational geometry library                             *)
(* Release Version 0.0.0                                               *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The ACME computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the ACME computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_intersect.cc
///

#include "acme_intersect.hh"

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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      line const &line0,
      line const &line1,
      vec3 &point)
  {
    vec3 p(line0.origin());
    vec3 v(line0.direction());
    vec3 q(line1.origin());
    vec3 u(line1.direction());
    // find a = v x u
    vec3 a(v.cross(u));
    // find dot product = (v x u).(v x u)
    real_type dot = a.dot(a);
    // if v and u are parallel (v x u = 0), then no intersection
    ACME_ASSERT(acme::is_equal(dot, 0.0),
                "acme::intersect(line|ray|segment, line|ray|segment -> point): Parallel ojects.");
    // find b = (Q1-P1) x u
    vec3 b((q - p).cross(u));
    // find t = (b.a)/(a.a) = ((Q1-P1) x u).(v x u) / (v x u).(v x u)
    real_type t = b.dot(a) / dot;
    // find intersection point
    point = p + (t * v);
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      ray const &ray0,
      ray const &ray1,
      vec3 &point)
  {
    if (acme::intersect(line(ray0.origin(), ray0.direction()),
                        line(ray1.origin(), ray1.direction()),
                        point))
      return ray0.is_inside(point) && ray1.is_inside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      segment const &segment0,
      segment const &segment1,
      vec3 &point)
  {
    if (acme::intersect(line(segment0.point_0(), segment0.to_normalized_vector()),
                        line(segment1.point_0(), segment1.to_normalized_vector()),
                        point))
      return (segment0.is_inside(point) && segment1.is_inside(point));
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      box const &box0,
      box const &box1,
      box &box)
  {
    if (!(box0.collision(box1)))
      return false;

    for (int i = 0; i < 3; ++i)
    {
      if (box0.max(i) <= box1.max(i))
        box.max(i, box0.max(i));
      else
        box.max(i, box1.max(i));

      if (box0.min(i) <= box1.min(i))
        box.min(i, box1.min(i));
      else
        box.min(i, box0.min(i));
    }
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      plane const &plane0,
      plane const &plane1,
      plane const &plane2,
      vec3 &point)
  {
    vec3 const normal0(plane0.normal());
    vec3 const normal1(plane1.normal());
    vec3 const normal2(plane2.normal());

    mat3 Mat;
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      plane const &plane0,
      plane const &plane1,
      line &line)
  {
    vec3 normal0 = plane0.normal();
    vec3 normal1 = plane1.normal();

    vec3 line_d = normal0.cross(normal1);
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      ray const &ray,
      plane const &plane,
      vec3 &point)
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      line const &line,
      plane const &plane,
      vec3 &point)
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      segment const &segment,
      plane const &plane,
      vec3 &point)
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      ray const &ray,
      triangle const &triangle,
      vec3 &point)
  {
    vec3 vertex0(triangle.vertex_0());
    vec3 vertex1(triangle.vertex_1());
    vec3 vertex2(triangle.vertex_2());
    vec3 edge1(vertex1 - vertex0);
    vec3 edge2(vertex2 - vertex0);

    vec3 origin(ray.origin());
    vec3 direction(ray.direction());

    vec3 h, s, q;
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
    if (t >= 0.0)
    {
      point = origin + direction * t;
      return true;
    }
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      line const &line,
      triangle const &triangle,
      vec3 &point)
  {
    vec3 vertex0 = triangle.vertex_0();
    vec3 vertex1 = triangle.vertex_1();
    vec3 vertex2 = triangle.vertex_2();
    vec3 edge1 = vertex1 - vertex0;
    vec3 edge2 = vertex2 - vertex0;

    vec3 origin = line.origin();
    vec3 direction = line.direction();

    vec3 h, s, q;
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      plane const &plane,
      triangle const &triangle,
      segment &segment)
  {
    vec3 point0, point1, point2;
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      line const &line,
      circle const &circle,
      vec3 &point)
  {
    if (acme::intersect(line, circle.laying_plane(), point))
    {
      if ((circle.center() - point).norm() <= circle.radius())
        return true;
      else
        return false;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      ray const &ray,
      circle const &circle,
      vec3 &point)
  {
    if (acme::intersect(line(ray.origin(), ray.direction()), circle.laying_plane(), point))
      return ray.is_inside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      segment const &segment,
      circle const &circle,
      vec3 &point)
  {
    if (acme::intersect(line(segment.point_0(), segment.to_normalized_vector()), circle.laying_plane(), point))
      return segment.is_inside(point);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      segment const &segment0,
      segment const &segment1,
      segment &segment)
  {
    //
    //   p0       p1   p0       p1
    //   o---s0---o    o---s1---o
    //
    vec3 s0_p0(segment0.point_0());
    vec3 s0_p1(segment0.point_1());
    vec3 s1_p0(segment1.point_0());
    vec3 s1_p1(segment1.point_1());
    bool s1_p0_in_s0 = segment0.is_inside(s0_p0);
    bool s1_p1_in_s0 = segment0.is_inside(s0_p1);
    bool s0_p0_in_s1 = segment1.is_inside(s1_p0);
    bool s0_p1_in_s1 = segment1.is_inside(s1_p1);

    //                    Segments coincides
    // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
    // |      1      |      1      |      1      |      1      |
    if (s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
    {
      segment.points(s0_p0, s0_p1);
      return true;
    }
    //                       An extrema coincides
    //     | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
    //     |      0      |      1      |      1      |      1      |
    //     |      1      |      0      |      1      |      1      |
    //     |      1      |      1      |      0      |      1      |
    //     |      1      |      1      |      1      |      0      |
    else if (!s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
    {
      segment.points(s1_p0, s1_p1);
      return true;
    }
    else if (s0_p0_in_s1 && !s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
    {
      segment.points(s1_p0, s1_p1);
      return true;
    }
    else if (s0_p0_in_s1 && s0_p1_in_s1 && !s1_p0_in_s0 && s1_p1_in_s0)
    {
      segment.points(s0_p0, s0_p1);
      return true;
    }
    else if (s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && !s1_p1_in_s0)
    {
      segment.points(s0_p0, s0_p1);
      return true;
    }
    //                      Partial overlap
    // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
    // |      0      |      1      |      0      |      1      |
    // |      0      |      1      |      1      |      0      |
    // |      1      |      0      |      0      |      1      |
    // |      1      |      0      |      1      |      0      |
    else if (!s0_p0_in_s1 && s0_p1_in_s1 && !s1_p0_in_s0 && s1_p1_in_s0)
    {
      segment.points(s0_p1, s1_p1);
      return true;
    }
    else if (!s0_p0_in_s1 && s0_p1_in_s1 && s1_p0_in_s0 && !s1_p1_in_s0)
    {
      segment.points(s0_p1, s1_p0);
      return true;
    }
    else if (s0_p0_in_s1 && !s0_p1_in_s1 && !s1_p0_in_s0 && s1_p1_in_s0)
    {
      segment.points(s0_p0, s1_p1);
      return true;
    }
    else if (s0_p0_in_s1 && !s0_p1_in_s1 && s1_p0_in_s0 && !s1_p1_in_s0)
    {
      segment.points(s0_p0, s1_p0);
      return true;
    }
    //                 One segment is inside
    // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
    // |      1      |      1      |      0      |      0      |
    // |      0      |      0      |      1      |      1      |
    else if (s0_p0_in_s1 && s0_p1_in_s1 && !s1_p0_in_s0 && !s1_p1_in_s0)
    {
      segment.points(s0_p0, s0_p1);
      return true;
    }
    else if (!s0_p0_in_s1 && !s0_p1_in_s1 && s1_p0_in_s0 && s1_p1_in_s0)
    {
      segment.points(s1_p0, s1_p1);
      return true;
    }
    //                   No intersection case
    // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
    // |      0      |      0      |      0      |      0      |
    else if (!s0_p0_in_s1 && !s0_p1_in_s1 && !s1_p0_in_s0 && !s1_p1_in_s0)
    {
      return false;
    }
    //                  Exception not handled
    // | s0_p0_in_s1 | s0_p1_in_s1 | s1_p0_in_s0 | s1_p1_in_s0 |
    // |      0      |      0      |      0      |      1      |
    // |      0      |      0      |      1      |      0      |
    // |      0      |      1      |      0      |      0      |
    // |      1      |      0      |      0      |      0      |
    else
    {
      ACME_ERROR("acme::intersect(segment, segment, segment): Cannot handle exception.")
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      line const &line,
      segment const &segment_in,
      segment &segment_out)
  {
    if (line.is_inside(segment_in.point_0()) && line.is_inside(segment_in.point_1()))
    {
      segment_out = segment_in;
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      ray const &ray,
      segment const &segment_in,
      segment &segment_out)
  {
    vec3 point_0(segment_in.point_0());
    vec3 point_1(segment_in.point_1());

    if (ray.is_inside(point_0) && ray.is_inside(point_1))
    {
      segment_out = segment_in;
      return true;
    }
    else if (ray.is_inside(point_0) && !ray.is_inside(point_1))
    {
      segment_out.points(ray.origin(), point_0);
      return true;
    }
    else if (!ray.is_inside(point_0) && ray.is_inside(point_1))
    {
      segment_out.points(point_1, ray.origin());
      return true;
    }
    else
    {
      return false;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      line const &line,
      circle const &circle,
      segment &segment)
  {
    // Locate one or two points that are on the circle and line.
    // If the line is t*D+P, the circle center is C, and the circle radius is r, then
    // r^2 = |t*D+P-C|^2 = |D|^2*t^2 + 2*Dot(D,P-C)*t + |P-C|^2
    // This is a quadratic equation of the form
    // a2*t^2 + 2*a1*t + a0 = 0.
    real_type circle_radius = circle.radius();
    vec3 circle_center(circle.center());
    vec3 line_origin(line.origin());
    vec3 line_direction(line.direction());
    vec3 diff(line_origin - circle_center);

    real_type a2 = line_direction.dot(line_direction);
    real_type a1 = diff.dot(line_direction);
    real_type a0 = diff.dot(diff) - circle_radius * circle_radius;

    real_type discriminant = a1 * a1 - a0 * a2;
    // No real roots, the circle does not intersect the plane
    if (discriminant <= -acme::Epsilon)
      return false;

    real_type inv = 1 / a2;
    // One repeated root, the circle just touches the plane
    if (acme::abs(discriminant) < acme::Epsilon)
    {
      vec3 int_point(line_origin - (a1 * inv) * line_direction);
      segment.points(int_point, int_point);
      return true;
    }

    // Two distinct, real-valued roots, the circle intersects the plane in two points
    real_type root = std::sqrt(discriminant);
    segment.point_0(line_origin - ((a1 + root) * inv) * line_direction);
    segment.point_1(line_origin - ((a1 - root) * inv) * line_direction);
    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      ray const &ray,
      circle const &circle,
      segment &segment_out)
  {
    // Transform ray to line
    line tmp_line(ray.origin(), ray.direction());
    // Compute the intersection of resulting line with the circle
    segment tmp_segment;
    if (acme::intersect(tmp_line, circle, tmp_segment))
      return acme::intersect(ray, tmp_segment, segment_out);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      plane const &plane,
      circle const &circle,
      segment &segment)
  {
    // Compute the intersection of circle plane with the input plane
    line int_line;
    // Compute the intersection of resulting line with the circle
    if(acme::intersect(circle.laying_plane(), plane, int_line))
      return acme::intersect(int_line, circle, segment);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      segment const &segment_in,
      circle const &circle,
      segment &segment_out)
  {
    // Transform segment to line
    line tmp_line(segment_in.point_0(), segment_in.to_normalized_vector());
    // Compute the intersection of resulting line with the circle
    segment tmp_segment;
    if (acme::intersect(tmp_line, circle, tmp_segment))
      return acme::intersect(segment_in, tmp_segment, segment_out);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool intersect(
      circle const &circle,
      triangle const &triangle,
      segment &segment_out)
  {
    segment tmp_segment;
    if (acme::intersect(circle.laying_plane(), triangle, tmp_segment))
      return acme::intersect(tmp_segment, circle, segment_out);
    else
      return false;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_intersect.cc
///