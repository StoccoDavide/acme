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
/// file: test_03.cc
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
      << "TEST 03 - POINT INSIDE DISK" << std::endl
      << std::endl;

    // Initialize disk
    disk Disk(1.0, point(0.0, 0.0, 0.5), vec3(0.0, 0.0, 1.0));

    // Query points and intersection bools
    point PointIn(0.0, 0.0, 0.5);
    point PointOut(2.0, 0.0, 0.5);
    point PointBorder(1.0, 0.0, 0.5);

    bool PtInBool, PtOutBool, PtBordBool;

    // Calculate intersection
    PtInBool = Disk.isInside(PointIn);
    PtOutBool = Disk.isInside(PointOut);
    PtBordBool = Disk.isInside(PointBorder);

    std::cout
        << Disk << std::endl
        << std::endl;

    // Show results
    if (PtInBool && !PtOutBool && PtBordBool)
    {
      std::cout
          << "Point inside    = " << PointIn     << " -> Bool = " << PtInBool   << std::endl
          << "Point outside   = " << PointOut    << " -> Bool = " << PtOutBool  << std::endl
          << "Point on border = " << PointBorder << " -> Bool = " << PtBordBool << std::endl
          << std::endl
          << "Check the results..." << std::endl;
    }
    else
    {
      std::cout
        << "TEST 03: Failed" << std::endl
        << "---------------------------" << std::endl;
    }

    // End of test
    std::cout
      << std::endl
      << "TEST 03: Completed" << std::endl
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
/// eof: test_03.cc
///
