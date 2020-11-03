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
  acme::pointnd<acme::Float, 3> A(1.0, 0.0, 0.0); 
  acme::point3d<> B;
  acme::pointnd<acme::Float, 3> C;
  C=B;
  B=C;

  //acme::segmentnd<acme::Float, 3> seg(C, B);

  // = acme::make_point<acme::Float>(1.0, 0.0, 0.0);
  //acme::point3d<acme::Float> B = acme::make_point<acme::Float>(0.0, 1.0, 0.0);
  //acme::point3d<acme::Float> C = acme::make_point<acme::Float>(0.0, 0.0, 1.0);
  //acme::point3d<acme::Float> D = acme::make_point<acme::Float>(1.0, 1.0, 1.0);
  /*std::cout << "POINT TESTS" << std::endl
            << "Point A = " << A << std::endl
            << "Point B = " << B << std::endl
            << "Point C = " << C << std::endl 
            << std::endl;*/
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
