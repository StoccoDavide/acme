// GEOMETRY TEST 4 - POINT ON SEGMENT

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_segment.hh"

using namespace acme;

// Main function
int main()
{
  // Initialize segment points
  segment Segment(vec3(0.0, 0.0, 0.5), vec3(1.0, 1.0, 0.5));

  // Query points and intersection bools
  vec3 PointIn(0.5, 0.5, 0.5);
  vec3 PointOut(-1.0, -1.0, 0.5);
  vec3 PointBorder(1.0, 1.0, 0.5);

  // Calculate intersection
  bool PtInBool = Segment.isInside(PointIn);
  bool PtOutBool = Segment.isInside(PointOut);
  bool PtBordBool = Segment.isInside(PointBorder);

  std::cout
      << "GEOMETRY TEST 4 - POINT ON SEGMENT" << std::endl
      << std::endl
      << "Segment Point 0 = " << Segment.point(0) << std::endl
      << "Segment Point 1 = " << Segment.point(1) << std::endl
      << std::endl;

  // Show results
  if (PtInBool && !PtOutBool && PtBordBool)
  {
    std::cout
        << "Point inside    = " << PointIn << " -> Bool = " << PtInBool << std::endl
        << "Point outside   = " << PointOut << " -> Bool = " << PtOutBool << std::endl
        << "Point on border = " << PointBorder << " -> Bool = " << PtBordBool << std::endl
        << std::endl;
  }
  else
  {
    std::cout << "GEOMETRY TEST 4: Failed" << std::endl;
  }

  std::cout << "\nGEOMETRY TEST 4: Completed" << std::endl;

  // Exit the program
  return 0;
}
