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
/// file: test_08.cc
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
      << "TEST 08 - POINT/VECTOR TRANSFORMATION" << std::endl
      << std::endl;

    // Initialize point and vector
    point point_tmp(0.0, 0.0, 1.0);
    vec3 vector_tmp(0.0, 0.0, 1.0);

    // Initialize rotation matrix
    affine transformation = translate(0.0, 0.0, -1.0) * angleaxis(PI / 2, UNITX_VEC3);

    // Transform objects
    point mov_point(point_tmp);
    vec3 mov_vector(vector_tmp);
    mov_point.transform(transformation);
    Transform(mov_vector, transformation);

    // Transform objects back
    point ground_point(mov_point);
    vec3 ground_vector(mov_vector);
    ground_point.transform(transformation.inverse());
    Transform(ground_vector, transformation.inverse());

    // Display results
    std::cout
      << "Point  (ground) = " << point_tmp
      << "Vector (ground) = " << vector_tmp
      << std::endl
      << "Point  (moving frame) = " << mov_point
      << "Vector (moving frame) = " << mov_vector
      << std::endl
      << "Point  (back to ground) = " << ground_point
      << "Vector (back to ground) = " << ground_vector
      << std::endl
      << "TEST 8: Completed" << std::endl;

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
/// eof: test_08.cc
///
