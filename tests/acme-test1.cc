// GEOMETRY TEST 1 - RAY/TRIANGLE INTERSECTION ON TRIANGLE EDGE

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_math.hh"
#include "acme_triangle.hh"
#include "acme_box.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << " GEOMETRY TEST 1 - RAY/TRIANGLE INTERSECTION ON TRIANGLE EDGE" << std::endl
      << "Angle\tIntersections" << std::endl;

  vec3 V1[3];
  V1[0] = vec3(1.0, 0.0, 0.0);
  V1[1] = vec3(0.0, 1.0, 0.0);
  V1[2] = vec3(-1.0, 0.0, 0.0);

  vec3 V2[3];
  V2[0] = vec3(-1.0, 0.0, 0.0);
  V2[1] = vec3(0.0, -1.0, 0.0);
  V2[2] = vec3(1.0, 0.0, 0.0);

  // Initialize triangle
  triangle Triangle1(V1);
  triangle Triangle2(V2);

  // Initialize rotation matrix
  mat3 Rot_X;

  // Initialize intersection point
  vec3 IntersectionPointTri1, IntersectionPointTri2;
  bool IntersectionBoolTri1, IntersectionBoolTri2;

  // Initialize Ray
  vec3 RayOrigin = vec3(0.0, 0.0, 0.0);
  vec3 RayDirection = vec3(0.0, 0.0, -1.0);
  ray Ray(RayOrigin, RayDirection);

  // Perform intersection at 0.5° step
  for (real_type angle = 0;
       angle < PI;
       angle += PI / 360.0)
  {

    Rot_X = rotate(angle, "X");

    // Initialize vertices
    vec3 VerticesTri1[3], VerticesTri2[3];

    VerticesTri1[0] = Rot_X * V1[0];
    VerticesTri1[1] = Rot_X * V1[1];
    VerticesTri1[2] = Rot_X * V1[2];

    VerticesTri2[0] = Rot_X * V2[0];
    VerticesTri2[1] = Rot_X * V2[1];
    VerticesTri2[2] = Rot_X * V2[2];

    Triangle1.vertices(VerticesTri1);
    Triangle2.vertices(VerticesTri2);

    IntersectionBoolTri1 = acme::intersection(Ray, Triangle1, IntersectionPointTri1);
    IntersectionBoolTri2 = acme::intersection(Ray, Triangle2, IntersectionPointTri2);

    std::cout
        << angle * 180.0 / PI << "°\t"
        << "T1 -> " << IntersectionBoolTri1 << ","
        << "T2 -> " << IntersectionBoolTri2 << std::endl;

    // ERROR if no one of the two triangles is hit
    if (!IntersectionBoolTri1 && !IntersectionBoolTri2)
    {
      std::cout << "Check coplanarity!" << std::endl;
    }
  }

  // Print triangle normal vector
  vec3 N1 = Triangle1.normal();
  vec3 N2 = Triangle2.normal();
  std::cout
      << std::endl
      << "Triangle 1 face normal = " << N1 << std::endl
      << "Triangle 2 face normal = " << N2 << std::endl
      << "Pow = " << acme::pow(2.0,2.0) << std::endl
      << std::endl
      << std::endl
      << "GEOMETRY TEST 1: Completed" << std::endl;

  // Exit the program
  return 0;
}
