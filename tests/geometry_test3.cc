// GEOMETRY TEST 3 - POINT INSIDE CIRCLE

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersect.hh"
#include "acme_triangle.hh"
#include "acme_box.hh"

using namespace acme;

// Main function
int main()
{
  // Initialize disk
  circle Circle(1.0, vec3(0.0, 0.0, 0.5), vec3(0.0, 0.0, 1.0));

  // Query points and intersection bools
  vec3 PointIn(0.0, 0.0, 0.5);
  vec3 PointOut(2.0, 0.0, 0.5);
  vec3 PointBorder(1.0, 0.0, 0.5);

  bool PtInBool, PtOutBool, PtBordBool;

  // Calculate intersection
  PtInBool = Circle.is_inside(PointIn);
  PtOutBool = Circle.is_inside(PointOut);
  PtBordBool = Circle.is_inside(PointBorder);

  std::cout
      << "GEOMETRY TEST 3 - POINT INSIDE DISK" << std::endl
      << std::endl
      << "Radius = " << Circle.radius() << std::endl
      << "Center = " << Circle.center() << std::endl
      << "Normal = " << Circle.normal() << std::endl
      << std::endl;

      // Show results
      if (PtInBool && !PtOutBool && PtBordBool)
  {
    std::cout
        << "Point inside    = " << PointIn << " -> Bool = " << PtInBool << std::endl
        << "Point outside   = " << PointOut << " -> Bool = " << PtOutBool << std::endl
        << "Point on border = " << PointBorder << " -> Bool = " << PtBordBool << std::endl
        << std::endl
        << "Check the results..." << std::endl
        << std::endl;
  }
  else
  {
    std::cout
        << "GEOMETRY TEST 3: Failed" << std::endl;
  }

  std::cout
      << "GEOMETRY TEST 3: Completed" << std::endl;

  // Exit the program
  return 0;
}
