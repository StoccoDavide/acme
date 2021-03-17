#include <iostream>

#include "acme.hh"
#include "acme_utilities.hh"
#include "TicToc.hh"


int main(void)
{

  std::cout << "ACME GEOMETRICAL TESTS"
            << std::endl << std::endl;

  // Instantiate a TicToc object
  TicToc tictoc;

  // POINT TEST
  acme::point3<acme::Float> A(1.0, 0.0, 0.0); 
  acme::point3<acme::Float> B(1.0, 0.0, 0.0);
  acme::point3<acme::Float> D(1.0, 0.0, 0.0);
  acme::point3<acme::Float> C;
  C=B;
  B=D;
  C=A+B;
  C.scale(1.1);
  D=A-B;
  D.distance(B);
  D==C;
  C=A;
  std::cout << "POINT TESTS" << std::endl
            << "Point A = " << A << std::endl
            << "Point B = " << B << std::endl
            << "Point C = " << C << std::endl 
            << "Point D = " << D << std::endl 
            << std::endl;

  acme::vector3<acme::Float> vec1(1,0,0);
  acme::vector3<acme::Float> vec2;
  std::cout << vec1 << std::endl  << std::endl;
  vec2 = vec1;
  vec1[1];
  std::cout << A[0] << std::endl  << std::endl;

  acme::line3<acme::Float> l(0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
  acme::line3<acme::Float> l1;
  std::cout << l1;
  l=l1;
  acme::ray3<acme::Float> r(0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
  acme::ray3<acme::Float> r1();
  //r=r1;
  if (l.is_equal(l1)) std::cout << "CAZZOOOOOO";
/*
  /*acme::segment<> seg(A, B);
  std::cout << seg << std::endl << std::endl;

  acme::ray<acme::Float, 3> ray;
  std::cout << ray << std::endl << std::endl;
  
  //acme::triangle<acme::Float, 3> triangle;
  //std::cout << triangle;*/
/*
  Eigen::Matrix<acme::Float, 3, 3> m;
  m << 1, 2, 3,
       4, 5, 6,
       7, 8, 9;
  acme::point3d<acme::Float> E = m*A;
  
  std::cout << "POINT TESTS" << std::endl
            //<< "Point A = " << m*A << std::endl
            //<< "Point B = " << m << std::endl
            //<< "Point C = " << m << std::endl 
            << std::endl;*/

  /*/ TRIANGLE TESTS
  acme::triangle3d Triangle = acme::make_triangle<acme::Float>(A, B, C);
  std::cout << "TRIANGLE TESTS" << std::endl
            << "Triangle = " << Triangle << std::endl
            << std::endl;

  // VECTOR TESTS
  acme::vector3d<acme::Float> Vector = acme::make_vector<acme::Float>(-1.0, -1.0, -1.0);
  std::cout << "VECTOR TESTS" << std::endl
            << "Vector = " << Vector << std::endl
            << std::endl;
  
  // RAY TESTS
  acme::ray3d Ray = acme::make_ray<acme::Float>(D, Vector);
  std::cout << "RAY TESTS" << std::endl
            << "Ray = " << Ray << std::endl
            << std::endl;

  // TRIANGLE-RAY TESTS
  acme::point3d<acme::Float> IntPt = acme::intersection_point(Ray, Triangle);
  std::cout << "RAY TESTS" << std::endl
            << "Intersection point = " << IntPt << std::endl
            << std::endl;

  unsigned int N = 10000;
  std::vector<acme::point3d<acme::Float>> IntPtVec;
  IntPtVec.resize(N);
  // Perform timing
  tictoc.tic();
  for (unsigned int i = 0; i < N; i++) {
    IntPtVec[i] = acme::intersection_point(Ray, Triangle);
  }
  tictoc.toc();
  std::cout << "Time tot = " << tictoc.elapsed_us() << "us" << std::endl
            << "Time avg = " << tictoc.elapsed_us()/N << "us" << std::endl;*/

  return 0;
}
