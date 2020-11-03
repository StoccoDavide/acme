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
  acme::point<acme::Float, 3> A(1.0, 0.0, 0.0); 
  acme::point<> B(1.0, 0.0, 0.0);
  acme::point<> D(1.0, 0.0, 0.0);
  acme::point<acme::Float, 3> C;
  C=B;
  B=D;

  std::cout << "POINT TESTS" << std::endl
            << "Point A = " << A << std::endl
            << "Point B = " << B << std::endl
            << "Point C = " << C << std::endl 
            << "Point D = " << D << std::endl 
            << std::endl;

  acme::vector<acme::Float, 3> vec1;
  acme::vector<acme::Float, 3> vec2(A);
  std::cout << vec1 << std::endl  << std::endl;
  vec1 = B;
  std::cout << vec1 << std::endl  << std::endl;
  

  acme::segment<> seg(A, B);
  std::cout << seg << std::endl << std::endl;

  acme::ray<acme::Float, 3> ray;
  std::cout << ray << std::endl << std::endl;
  
  //acme::triangle<acme::Float, 3> triangle;
  //std::cout << triangle;
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
