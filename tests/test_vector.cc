#include <iostream>

#include "acme.hh"
#include "acme_utilities.hh"

int main(void)
{

  std::cout << "ACME GEOMETRICAL TESTS"
            << std::endl
            << std::endl;

  // POINT TEST
  acme::vec3 A(1.0, 0.0, 0.0);
  acme::vec3 B(0.0, 1.0, 0.0);
  acme::vec3 C(0.0, 0.0, 0.5);

  std::cout << "VECTOR TESTS" << std::endl
            << "Vector A = " << A << std::endl
            << "Vector B = " << B << std::endl
            << "Vector C = " << C << std::endl
            << "Matrix D = " << acme::mat3_goat << std::endl
            << std::endl;
  return 0;
}
