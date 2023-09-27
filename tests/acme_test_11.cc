/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                     *
 * The ACME project                                                    *
 *                                                                     *
 * Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *
 *                                                                     *
 * The ACME project and its components are supplied under the terms of *
 * the open source BSD 2-Clause License. The contents of the ACME      *
 * project and its components may not be copied or disclosed except in *
 * accordance with the terms of the BSD 2-Clause License.              *
 *                                                                     *
 * URL: https://opensource.org/licenses/BSD-2-Clause                   *
 *                                                                     *
 *    Davide Stocco                                                    *
 *    Department of Industrial Engineering                             *
 *    University of Trento                                             *
 *    e-mail: davide.stocco@unitn.it                                   *
 *                                                                     *
 *    Enrico Bertolazzi                                                *
 *    Department of Industrial Engineering                             *
 *    University of Trento                                             *
 *    e-mail: enrico.bertolazzi@unitn.it                               *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

///
/// file: test_11.cc
///

#include "acme.hh"

using namespace acme;

// Main function
int
main(void)
{
  // Try block
  try
  {

    // Print test main information
    std::cout
      << "---------------------------" << std::endl
      << "TEST 11 - PLANE/TRIANGLE INTERSECTION ON TRIANGLE EDGE" << std::endl
      << std::endl;

    point V1[3];
    V1[0] = point(1.0, 0.0, 0.0);
    V1[1] = point(0.0, 1.0, 0.0);
    V1[2] = point(-1.0, 0.0, 0.0);

    // Initialize triangle
    triangle Triangle1(V1);

    // Initialize triangle
    plane Plane1(vec3(0.0, 0.0, 0.0), vec3(1.0, 0.0, 0.0));

    // Initialize intersection point
    segment IntersectionSeg;
    bool IntersectionSegBool;

    IntersectionSegBool = Intersection(Plane1, Triangle1, IntersectionSeg);

    // ERROR if no one of the two triangles is hit
    if (!IntersectionSegBool)
    {
      std::cout << "Check coplanarity!" << std::endl;
    }

    // End of test
    std::cout
      << IntersectionSeg << std::endl
       << std::endl
      << "TEST 11: Completed" << std::endl
      << "---------------------------" << std::endl;

    // Exit the program
    return 0;
  }

  // Exception catch block
  catch (std::exception const &exc)
  {
    std::cerr << exc.what() << std::endl;
  }

  // Default catch block
  catch (...)
  {
    std::cerr
      << std::endl
      << "Aborted test: unknown error" << std::endl
      << "---------------------------" << std::endl;
  }
}

///
/// eof: test_11.cc
///
