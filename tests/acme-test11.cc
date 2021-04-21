// GEOMETRY TEST 1 - RAY/TRIANGLE INTERSECTION ON TRIANGLE EDGE

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_math.hh"
#include "acme_triangle.hh"
#include "acme_box.hh"
#include "acme_utilities.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << " GEOMETRY TEST 11 - PLANE/TRIANGLE INTERSECTION ON TRIANGLE EDGE" << std::endl;

  vec3 V1[3];
  V1[0] = vec3(1.0, 0.0, 0.0);
  V1[1] = vec3(0.0, 1.0, 0.0);
  V1[2] = vec3(-1.0, 0.0, 0.0);

  // Initialize triangle
  triangle Triangle1(V1);

  // Initialize triangle
  plane Plane1(vec3(0.0, 0.0, 0.0),
               vec3(1.0, 0.0, 0.0));

  // Initialize rotation matrix
  //affine tmp_affine;
  //tmp_affine = translate(0.0, 0.0, 0.0) * rotate(0.0, "X");
  //Triangle1.transform(tmp_affine);

  // Initialize intersection point
  segment IntersectionSeg;
  bool IntersectionSegBool;

  IntersectionSegBool = acme::intersection(Plane1, Triangle1, IntersectionSeg);

  // ERROR if no one of the two triangles is hit
  if (!IntersectionSegBool)
  {
    std::cout << "Check coplanarity!" << std::endl;
  }

  std::cout
      << std::endl
      << std::endl
      << IntersectionSeg << std::endl
      << "GEOMETRY TEST 1: Completed" << std::endl;

  // Exit the program
  return 0;
}
