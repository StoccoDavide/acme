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
/// file: test_13.cc
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
      << "TEST 13 - ENTITIES INTERSECTION" << std::endl
      << std::endl;

    ray *ray0 = new ray(point(0.0,  0.0, 0.0), vec3(0.0, -1.0, 0.0));
    ray *ray1 = new ray(point(0.0, -1.0, 0.0), vec3(0.0,  1.0, 0.0));

    entity *entity_out0 = Intersection(ray0, ray1);
    std::cout << "Exit type: "
              << entity_out0->type() << std::endl;

    if (dynamic_cast<segment *>(entity_out0)) // IF!!!!!
    {
      segment *segment_ptr0 = dynamic_cast<segment *>(entity_out0);
      std::cout << "Segment:" << std::endl
                << *segment_ptr0;
    }

    std::cout << std::endl;
    
    disk *disk0 = new disk(2.0, point(0.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0));
    disk *disk1 = new disk(2.0, point(0.0, 0.0, 0.1), vec3(1.0, -1.0, 0.0));

    entity *entity_out1 = Intersection(disk0, disk1);
    std::cout << "Exit type:"
              << entity_out1->type() << std::endl;

    if (dynamic_cast<segment *>(entity_out1)) // IF!!!!!
    {
      segment *segment_ptr1 = dynamic_cast<segment *>(entity_out1);
      std::cout << "Segment:" << std::endl
                << *segment_ptr1;
    }

    delete entity_out0;
    delete entity_out1;

    std::cout
      << std::endl
      << "TEST 13: Completed" << std::endl;

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
/// eof: test_13.cc
///
