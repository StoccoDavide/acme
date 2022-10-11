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
/// file: test_07.cc
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
      << "TEST 07 - RAY/DISK INTERSECTION" << std::endl
      << std::endl;

    // Initialize disk
    disk Disk(1.0, point(0.0, 0.0, 0.5), vec3(0.0, 0.0, 1.0));

    // Initialize segments
    ray In1(point(0.0, 0.0, 0.5), vec3(1.0, 0.0, 0.0));
    ray In2(point(-2.0, 0.0, 0.5), vec3(1.0, 0.0, 0.0));
    ray Out(point(1.0, 2.0, 0.5), vec3(1.0, 0.0, 0.0));
    ray Tan(point(1.0, 1.0, 0.5), vec3(-1.0, 0.0, 0.0));

    // Initialize intersection segments and output bools
    segment IntIn1, IntIn2, IntOut, IntTan;
    bool boolIn1, boolIn2, boolOut, boolTan;

    // Calculate intersections
    boolIn1 = Intersection(In1, Disk, IntIn1);
    boolIn2 = Intersection(In2, Disk, IntIn2);
    boolOut = Intersection(Out, Disk, IntOut);
    boolTan = Intersection(Tan, Disk, IntTan);

    // Display results
    std::cout
      << Disk
      << std::endl
      << "Ray 1 with two intersections: bool(" << boolIn1 << ") intersection found" << std::endl
      << In1
      << "Intersection point 0 = " << IntIn1.vertex(0)
      << "Intersection point 1 = " << IntIn1.vertex(1)
      << std::endl
      << "Ray 2 with two intersections: bool(" << boolIn2 << ") intersection found" << std::endl
      << In2
      << "Intersection point 0 = " << IntIn2.vertex(0)
      << "Intersection point 1 = " << IntIn2.vertex(1)
      << std::endl
      << "Ray with no intersections:  bool(" << boolOut << ") intersection found" << std::endl
      << Out
      << "Intersection point 0 = " << IntOut.vertex(0)
      << "Intersection point 1 = " << IntOut.vertex(1)
      << std::endl
      << "Ray with one intersection:  bool(" << boolTan << ") intersection found" << std::endl
      << Tan
      << "Intersection point 0 = " << IntTan.vertex(0)
      << "Intersection point 1 = " << IntTan.vertex(1)
      << std::endl
      << "Check the results...";

    // End of test
    std::cout
      << std::endl
      << "That's all Folks!" << std::endl
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
/// eof: test_07.cc
///
