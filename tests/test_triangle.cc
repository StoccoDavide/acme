#include <iostream>

#include "acme.hh"
#include "acme_utilities.hh"
#include "acme_intersect3.hh"
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
  acme::vector3 C(0.0, 0.0, 1.0);

  acme::triangle3 Tri(A, B, C);

  acme::vector3 Vec(-1.0, -1.0, -1.0);
  acme::ray3 Ray(A + B + C, Vec);

  acme::vector3 Pt;

  tictoc.tic();
  acme::intersect(Tri, Ray, Pt);
  tictoc.toc();

  std::cout
      << "POINT TESTS" << std::endl
      << "Point Tri = " << Tri << std::endl
      << "Point Ray = " << Ray << std::endl
      << "Point Pt  = " << Pt << std::endl
      << "Time[us]  = " << tictoc.elapsed_ms()*1e3 << std::endl
      << std::endl;
  return 0;
}
