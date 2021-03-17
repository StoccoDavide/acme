#include <iostream>

#include "ddd.hh"
#include "ddd_utilities.hh"
#include "TicToc.hh"


int main(void)
{

  std::cout << "ACME GEOMETRICAL TESTS"
            << std::endl << std::endl;

  // Instantiate a TicToc object
  TicToc tictoc;

  // POINT TEST
  ddd::point<ddd::Float> A(1.0, 0.0, 0.0); 
  ddd::point<ddd::Float> B(1.0, 0.0, 0.0);
  ddd::point<ddd::Float> D(1.0, 0.0, 0.0);
  ddd::point<ddd::Float> C;
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

  ddd::vector<ddd::Float> vec1(1,0,0);
  ddd::vector<ddd::Float> vec2;
  std::cout << vec1 << std::endl  << std::endl;
  vec2 = vec1;
  vec1[1];
  std::cout << A[0] << std::endl  << std::endl;

  ddd::line<ddd::Float> l(0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
  ddd::line<ddd::Float> l1;
  std::cout << l1;
  l=l1;
  ddd::ray<ddd::Float> r(0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
  ddd::ray<ddd::Float> r1();
  //r=r1;
  if (l.is_equal(l1)) std::cout << "CAZZOOOOOO";
/*
  /*ddd::segment<> seg(A, B);
  std::cout << seg << std::endl << std::endl;

  ddd::ray<ddd::Float, 3> ray;
  std::cout << ray << std::endl << std::endl;
  
  //ddd::triangle<ddd::Float, 3> triangle;
  //std::cout << triangle;*/
/*
  Eigen::Matrix<ddd::Float, 3, 3> m;
  m << 1, 2, 3,
       4, 5, 6,
       7, 8, 9;
  ddd::point3d<ddd::Float> E = m*A;
  
  std::cout << "POINT TESTS" << std::endl
            //<< "Point A = " << m*A << std::endl
            //<< "Point B = " << m << std::endl
            //<< "Point C = " << m << std::endl 
            << std::endl;*/

  /*/ TRIANGLE TESTS
  ddd::triangle3d Triangle = ddd::make_triangle<ddd::Float>(A, B, C);
  std::cout << "TRIANGLE TESTS" << std::endl
            << "Triangle = " << Triangle << std::endl
            << std::endl;

  // VECTOR TESTS
  ddd::vector3d<ddd::Float> Vector = ddd::make_vector<ddd::Float>(-1.0, -1.0, -1.0);
  std::cout << "VECTOR TESTS" << std::endl
            << "Vector = " << Vector << std::endl
            << std::endl;
  
  // RAY TESTS
  ddd::ray3d Ray = ddd::make_ray<ddd::Float>(D, Vector);
  std::cout << "RAY TESTS" << std::endl
            << "Ray = " << Ray << std::endl
            << std::endl;

  // TRIANGLE-RAY TESTS
  ddd::point3d<ddd::Float> IntPt = ddd::intersection_point(Ray, Triangle);
  std::cout << "RAY TESTS" << std::endl
            << "Intersection point = " << IntPt << std::endl
            << std::endl;

  unsigned int N = 10000;
  std::vector<ddd::point3d<ddd::Float>> IntPtVec;
  IntPtVec.resize(N);
  // Perform timing
  tictoc.tic();
  for (unsigned int i = 0; i < N; i++) {
    IntPtVec[i] = ddd::intersection_point(Ray, Triangle);
  }
  tictoc.toc();
  std::cout << "Time tot = " << tictoc.elapsed_us() << "us" << std::endl
            << "Time avg = " << tictoc.elapsed_us()/N << "us" << std::endl;*/

  return 0;
}
