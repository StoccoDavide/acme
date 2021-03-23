#include <iostream>

#include "acme.hh"
#include "acme_utilities.hh"
#include "TicToc.hh"

int main(void)
{

  std::cout << "ACME GEOMETRICAL TESTS"
            << std::endl
            << std::endl;

  // Instantiate a TicToc object
  TicToc tictoc;

  // POINT TEST
  acme::vector3 A(1.0, 0.0, 0.0);
  acme::vector3 B(0.0, 1.0, 0.0);
  acme::vector3 C(0.0, 0.0, 0.5);

  std::cout << "VECTOR TESTS" << std::endl
            << "Vector A = " << A << std::endl
            << "Vector B = " << B << std::endl
            << "Vector C = " << C << std::endl
            << std::endl;
  return 0;
}
