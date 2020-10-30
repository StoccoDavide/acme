#include <iostream>

#include "acme.hh"
#include "acme_matrix.hh"

int main(void)
{

  std::cout << "ACME MATHEMATICS TESTS"
            << std::endl
            << std::endl;

  // EPSILON TEST
  acme::Float Epsilon_machine = acme::Epsilon_Machine;
  float Epsilon_float = acme::epsilon<float>();
  double Epsilon_double = acme::epsilon<double>();
  acme::Float Epsilon_acme = acme::epsilon<acme::Float>();
  std::cout << "EPSILON TEST" << std::endl
            << "Epsilon (machine) = " << Epsilon_machine << std::endl
            << "Epsilon (float)   = " << Epsilon_float << std::endl
            << "Epsilon (double)  = " << Epsilon_double << std::endl
            << "Epsilon (acme)    = " << Epsilon_acme << std::endl
            << std::endl;

  // INFINITY TEST
  float Infinity_float = acme::infinity<float>();
  double Infinity_double = acme::infinity<double>();
  acme::Float Infinity_acme = acme::infinity<acme::Float>();
  std::cout << "INFINITY TEST" << std::endl
            << "Infinity (float)  = " << Infinity_float << std::endl
            << "Infinity (double) = " << Infinity_double << std::endl
            << "Infinity (acme)   = " << Infinity_acme << std::endl
            << std::endl;

  return 0;
}
