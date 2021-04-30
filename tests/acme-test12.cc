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
      << " GEOMETRY TEST 12 - PLANE/TRIANGLE INTERSECTION ON TRIANGLE EDGE" << std::endl;

  entity::ptr line0 = std::make_shared<line>(vec3(0.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0));
  entity::ptr line1 = std::make_shared<line>(vec3(0.0, 0.0, 0.0), vec3(1.0, 0.0, 0.0));

  if (acme::isOrthogonal(line1, line0))
  {
    std::cout << "LINES ARE ORTHOGONAL!\n\n";
  }

  std::cout
      << std::endl
      << std::endl
      << "GEOMETRY TEST 12: Completed" << std::endl;

  // Exit the program
  return 0;
}
