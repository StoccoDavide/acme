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
/// file: test_00.cc
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
      << "TEST 00 - ACME NUMERIC LIMITS" << std::endl
      << std::endl;

    // Epsilon test
    std::cout << "Epsilon test" << std::endl
              << "Epsilon (machine) = " << EPSILON_MACHINE << std::endl
              << "Epsilon (acme)    = " << EPSILON << std::endl
              << std::endl;

    // Infinity test
    std::cout << "Infinity test" << std::endl
              << "Infinity (acme)   = " << INFTY << std::endl
              << std::endl;

    // Not-a-number test
    std::cout << "Not-a-number test" << std::endl
              << "Quiet NaN (acme)   = " << QUIET_NAN << std::endl
              << std::endl;
  
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
/// eof: test_00.cc
///
