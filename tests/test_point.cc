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
  acme::point3<acme::Float> A(1.0, 0.0, 0.0);
  acme::point3<acme::Float> B(0.0, 1.0, 0.0);
  acme::point3<acme::Float> C(0.0, 0.0, 0.5);
  acme::point3<acme::Float> D;
  acme::point3<acme::Float> E;
  acme::point3<acme::Float> F;
  C = A + B;
  C.scale(1.1);
  D = A - B;
  D.distance(B);
  E = D.normalized();
  F = A;
  F.translate(B.toVector());

  std::cout << "POINT TESTS" << std::endl
            << "Point A = " << A << std::endl
            << "Point B = " << B << std::endl
            << "Point C = " << C << std::endl
            << "Point D = " << D << std::endl
            << "Point E = " << E << std::endl
            << "Point F = " << F << std::endl
            << "d(A,B)  = " << A.distance(B) << std::endl
            << std::endl;
  return 0;
}
