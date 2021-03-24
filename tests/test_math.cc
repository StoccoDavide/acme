#include <iostream>

#include "acme_math.hh"

int main(void)
{

  std::cout << "ACME MATHEMATICS TESTS"
            << std::endl
            << std::endl;

  // EPSILON TEST
  acme::real_type Epsilon_machine = acme::Epsilon_Machine;
  acme::real_type Epsilon_acme = acme::epsilon();
  std::cout << "EPSILON TEST" << std::endl
            << "Epsilon (machine) = " << Epsilon_machine << std::endl
            << "Epsilon (acme)    = " << Epsilon_acme << std::endl
            << std::endl;

  // INFINITY TEST
  acme::real_type Infinity_acme = acme::infinity();
  std::cout << "INFINITY TEST" << std::endl
            << "Infinity (acme)   = " << Infinity_acme << std::endl
            << std::endl;

  // SINE TEST
  double value = acme::PI;
  std::cout << "SINE TEST" << std::endl
            << "Sin(PI) = " << acme::sin(value) << std::endl
            << "Cos(PI) = " << acme::cos(value) << std::endl
            << "Tan(PI) = " << acme::tan(value) << std::endl;

  return 0;
}
