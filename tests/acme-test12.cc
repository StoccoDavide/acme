// GEOMETRY TEST 1 - RAY/TRIANGLE INTERSECTION ON TRIANGLE EDGE

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_eigen.hh"
#include "acme_line.hh"
#include "acme_orthogonal.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << " GEOMETRY TEST 11 - PLANE/TRIANGLE INTERSECTION ON TRIANGLE EDGE" << std::endl;

  entity *line0 = new line(vec3(0.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0));
  entity *line1 = new line(vec3(0.0, 0.0, 0.0), vec3(1.0, 0.0, 0.0));

  if (acme::isOrthogonal(line0, line1))
  {
    std::cout << "LINES ARE ORTHOGONAL!\n\n";
  }

  std::cout
      << std::endl
      << std::endl
      << "GEOMETRY TEST 1: Completed" << std::endl;

  // Exit the program
  return 0;
}
