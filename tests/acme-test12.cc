// GEOMETRY TEST 1 - RAY/TRIANGLE INTERSECTION ON TRIANGLE EDGE

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_eigen.hh"
#include "acme_line.hh"
#include "acme_orthogonal.hh"
#include "acme_parallel.hh"
#include "acme_intersection.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << " GEOMETRY TEST 12 - PLANE/TRIANGLE INTERSECTION ON TRIANGLE EDGE" << std::endl;

  entity *line0 = new line(vec3(0.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0));
  entity *line1 = new line(vec3(0.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0));
  entity *entity_out = acme::intersection(line0, line1);
  //if (acme::intersection(line0, line1))
  //{
    std::cout << "LINES INTERSECTS in: " << entity_out->isVector() << "\n";
  //}

  std::cout
      << std::endl
      << std::endl
      << "GEOMETRY TEST 12: Completed" << std::endl;

  // Exit the program
  return 0;
}
