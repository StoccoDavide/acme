#include <iostream>

#include "acme.hh"
#include "acme_utilities.hh"
#include "acme_intersect.hh"
#include "TicToc.hh"

int main(void)
{

  std::cout << "ACME GEOMETRICAL TESTS"
            << std::endl
            << std::endl;

  // Instantiate a TicToc object
  TicToc tictoc;

  // POINT TEST
  acme::vec3 A(1.0, 0.0, 0.0);
  acme::vec3 B(0.0, 1.0, 0.0);
  acme::vec3 C(0.0, 0.0, 1.0);

  acme::triangle Tri(A, B, C);

  acme::vec3 Vec(-1.0, -1.0, -1.0);
  acme::ray Ray(A + B + C, Vec);
  acme::ray Ray_rev(Ray);
  Ray_rev.reverse();
  acme::line Line(A + B + C, Vec);
  acme::line Line_rev(Line);
  Line_rev.reverse();

  acme::vec3 pt_Ray(acme::NaN_vec3);
  acme::vec3 pt_Ray_rev(acme::NaN_vec3);
  acme::vec3 pt_Line(acme::NaN_vec3);
  acme::vec3 pt_Line_rev(acme::NaN_vec3);

  tictoc.tic();
  acme::intersect(Tri, Ray, pt_Ray);
  acme::intersect(Tri, Ray_rev, pt_Ray_rev);
  acme::intersect(Tri, Line, pt_Line);
  acme::intersect(Tri, Line_rev, pt_Line_rev);
  tictoc.toc();

  std::cout
      << "POINT TESTS" << std::endl
      << "Point Tri = " << Tri << std::endl
      << "Point Ray = " << Ray << std::endl
      << "Pt (+Ray)  = " << pt_Ray << std::endl
      << "Pt (-Ray)  = " << pt_Ray_rev << std::endl
      << "Pt (+Line) = " << pt_Line << std::endl
      << "Pt (-Line) = " << pt_Line_rev << std::endl
      << "Time[us]  = " << tictoc.elapsed_ms() * 1e3 << std::endl
      << std::endl;
  return 0;
}
