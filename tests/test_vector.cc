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
  acme::vector3<acme::Float> A(1.0, 0.0, 0.0);
  acme::vector3<acme::Float> B(0.0, 1.0, 0.0);
  acme::vector3<acme::Float> C(0.0, 0.0, 0.5);
  acme::vector3<acme::Float> D;
  acme::vector3<acme::Float> E;
  acme::vector3<acme::Float> F;
  C = A + B;
  C.scale(1.1);
  D = A - B;
  E = D.normalized();
  //Eigen::Matrix<T, 3, 1> aa(1.0, 0.0, 0.0);
  //Eigen::Matrix<T, 3, 1> ee(2.0, 0.0, 0.0);
  //F = aa.dot(ee);
  F.add(B);

  std::cout << "VECTOR TESTS" << std::endl
            << "Point A = " << A << std::endl
            << "Point B = " << B << std::endl
            << "Point C = " << C << std::endl
            << "Point D = " << D << std::endl
            << "Point E = " << E << std::endl
            << "Point F = " << F << std::endl
            << "a(A,B)  = " << A.angle(B) << std::endl
            << std::endl;
  return 0;
}
