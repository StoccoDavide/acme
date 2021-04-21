// GEOMETRY TEST 2 - SEGMENT CIRCLE INTERSECTION

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_triangle.hh"
#include "acme_box.hh"

using namespace acme;

// Main function
int main()
{
  // Initialize circle
  circle Circle(1.0, vec3(0.0, 0.0, 0.5), vec3(0.0, 0.0, 1.0));

  // Initialize segments
  segment In1(vec3(0.0, 0.0, 0.5), vec3(0.0, 1.0, 0.5));
  segment In2(vec3(-2.0, 0.0, 0.5), vec3(2.0, 0.0, 0.5));
  segment Out(vec3(1.0, 2.0, 0.5), vec3(-1.0, 2.0, 0.5));
  segment Tan(vec3(1.0, 1.0, 0.5), vec3(-1.0, 1.0, 0.5));

  // Initialize intersection segments and output bools
  segment IntIn1, IntIn2, IntOut, IntTan;
  bool boolIn1, boolIn2, boolOut, boolTan;

  // Calculate intersections
  boolIn1 = intersection(In1, Circle, IntIn1);
  boolIn2 = intersection(In2, Circle, IntIn2);
  boolOut = intersection(Out, Circle, IntOut);
  boolTan = intersection(Tan, Circle, IntTan);

  // Display results
  std::cout
      << std::endl
      << "GEOMETRY TEST 2 - SEGMENT DISK INTERSECTION" << std::endl
      << std::endl
      << "Radius = " << Circle.radius() << std::endl
      << "Center = " << Circle.center() << std::endl
      << "Normal = " << Circle.normal() << std::endl
      << std::endl
      << "Segment 1 with two intersections: bool(" << boolIn1 << ") intersection found" << std::endl
      << "Segment Point 0\t= " << In1.point(0) << std::endl
      << "Segment Point 1\t= " << In1.point(1) << std::endl
      << "Intersection Point 0\t= " << IntIn1.point(0) << std::endl
      << "Intersection Point 1\t= " << IntIn1.point(1) << std::endl
      << std::endl
      << "Segment 2 with two intersections: bool(" << boolIn2 << ") intersection found" << std::endl
      << "Segment Point 0\t= " << In2.point(0) << std::endl
      << "Segment Point 1\t= " << In2.point(1) << std::endl
      << "Intersection Point 0\t= " << IntIn2.point(0) << std::endl
      << "Intersection Point 1\t= " << IntIn2.point(1) << std::endl
      << std::endl
      << "Segment with no intersections:  bool(" << boolOut << ") intersection found" << std::endl
      << "Segment Point 0\t= " << Out.point(0) << std::endl
      << "Segment Point 1\t= " << Out.point(1) << std::endl
      << "Intersection Point 0\t= " << IntOut.point(0) << std::endl
      << "Intersection Point 1\t= " << IntOut.point(1) << std::endl
      << std::endl
      << "Segment with one intersection:  bool(" << boolTan << ") intersection found" << std::endl
      << "Segment Point 0\t= " << Tan.point(0) << std::endl
      << "Segment Point 1\t= " << Tan.point(1) << std::endl
      << "Intersection Point 0\t= " << IntTan.point(0) << std::endl
      << "Intersection Point 1\t= " << IntTan.point(1) << std::endl
      << std::endl
      << "Check the results..." << std::endl
      << std::endl
      << "GEOMETRY TEST 2: Completed" << std::endl;

  // Exit the program
  return 0;
}