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
/// file: test_18.cc
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
      << "TEST 18 - DISKPLANE//TRIANGLE INTERSECTION" << std::endl
      << std::endl;

    disk Disk(0.3, point(0.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0));
    plane Plane(point(0.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0));

    // Initialize triangle
    triangle Triangle(vec3(0.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 1.0, 1.0));

    // Initialize intersection point
    segment IntersectionSeg, IntersectionSeg1;
    bool IntersectionPtBool;

    //IntersectionPtBool = Intersection(Triangle, Disk, IntersectionSeg);
    IntersectionPtBool = Intersection(Plane, Triangle, IntersectionSeg1);
    IntersectionPtBool = Intersection(IntersectionSeg1, Disk, IntersectionSeg);

    // ERROR if no one of the two triangles is hit
    if (!IntersectionPtBool)
    {
      std::cout << "Check coplanarity!" << std::endl;
    }

    std::cout
      << std::endl
      << "Intersection segment: " << real(IntersectionPtBool) << std::endl
      << IntersectionSeg << std::endl;

    // End of test
    std::cout
      << std::endl
      << "TEST 18: Completed" << std::endl
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
/// eof: test_18.cc
///
