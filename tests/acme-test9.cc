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
      << " GEOMETRY TEST 9 - BOX CLAMPING TEST" << std::endl;

  // Initialize vertices
  vec3 V1[3];
  V1[0] = vec3(1.0, 0.0, 0.0);
  V1[1] = vec3(0.0, 1.0, 1.0);
  V1[2] = vec3(-1.0, 0.0, 0.0);

  vec3 V2[3];
  V2[0] = vec3(-1.0, 0.0, 0.0);
  V2[1] = vec3(0.0, -1.0, -1.0);
  V2[2] = vec3(1.0, 0.0, 0.0);

  // Initialize triangle
  triangle Triangle1(V1);
  triangle Triangle2(V2);

  // Initialize boxes
  box Box1;
  box Box2;
  Box1.clamp(V1);
  Box2.clamp(V2);

  std::cout
      << std::endl
      << "Triangle 1 = " << Triangle1 << std::endl
      << "Triangle 2 = " << Triangle2 << std::endl
      << "Box 1 = " << Box1 << std::endl
      << "Box 2 = " << Box2 << std::endl
      << std::endl
      << "GEOMETRY TEST 9: Completed" << std::endl;

  // Exit the program
  return 0;
}
