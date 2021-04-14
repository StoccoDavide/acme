// GEOMETRY TEST 6 - SEGMENT CIRCLE INTERSECTION

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
  // Initialize circle
  circle Circle(1.0, vec3(0.0, 0.0, 0.5), vec3(0.0, 0.0, 1.0));

  // Initialize segments
  line In1(vec3(0.0, 0.0, 0.5), vec3(1.0, 0.0, 0.0));
  line In2(vec3(-2.0, 0.0, 0.5), vec3(1.0, 0.0, 0.0));
  line Out(vec3(1.0, 2.0, 0.5), vec3(1.0, 0.0, 0.0));
  line Tan(vec3(1.0, 1.0, 0.5), vec3(1.0, 0.0, 0.0));

  // Initialize intersection segments and output bools
  segment IntIn1, IntIn2, IntOut, IntTan;
  bool boolIn1, boolIn2, boolOut, boolTan;

  // Calculate intersections
  boolIn1 = intersect(In1, Circle, IntIn1);
  boolIn2 = intersect(In2, Circle, IntIn2);
  boolOut = intersect(Out, Circle, IntOut);
  boolTan = intersect(Tan, Circle, IntTan);

  // Display results
  std::cout
      << std::endl
      << "GEOMETRY TEST 6 - LINE DISK INTERSECTION" << std::endl
      << std::endl
      << "Radius = " << Circle.radius() << std::endl
      << "Center = " << Circle.center() << std::endl
      << "Normal = " << Circle.normal() << std::endl
      << std::endl
      << "Line 1 with two intersections: bool(" << boolIn1 << ") intersection found" << std::endl
      << "Line origin   \t= " << In1.origin() << std::endl
      << "Line direction\t= " << In1.direction() << std::endl
      << "Intersection Point 0\t= " << IntIn1.point_0() << std::endl
      << "Intersection Point 1\t= " << IntIn1.point_1() << std::endl
      << std::endl
      << "Line 2 with two intersections: bool(" << boolIn2 << ") intersection found" << std::endl
      << "Line origin   \t= " << In2.origin() << std::endl
      << "Line direction\t= " << In2.direction() << std::endl
      << "Intersection Point 0\t= " << IntIn2.point_0() << std::endl
      << "Intersection Point 1\t= " << IntIn2.point_1() << std::endl
      << std::endl
      << "Line with no intersections:  bool(" << boolOut << ") intersection found" << std::endl
      << "Line origin   \t= " << Out.origin() << std::endl
      << "Line direction\t= " << Out.direction() << std::endl
      << "Intersection Point 0\t= " << IntOut.point_0() << std::endl
      << "Intersection Point 1\t= " << IntOut.point_1() << std::endl
      << std::endl
      << "Line with one intersection:  bool(" << boolTan << ") intersection found" << std::endl
      << "Line origin   \t= " << Tan.origin() << std::endl
      << "Line direction\t= " << Tan.direction() << std::endl
      << "Intersection Point 0\t= " << IntTan.point_0() << std::endl
      << "Intersection Point 1\t= " << IntTan.point_1() << std::endl
      << std::endl
      << "Check the results..." << std::endl
      << std::endl
      << "GEOMETRY TEST 6: Completed" << std::endl;

  // Exit the program
  return 0;
}
