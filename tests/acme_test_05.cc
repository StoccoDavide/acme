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
/// file: test_05.cc
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
      << "TEST 05 - LINE/TRIANGLE INTERSECTION ON TRIANGLE EDGE" << std::endl
      << std::endl;

    std::cout
      << "Angle\tIntersections" << std::endl;

    point V1[3];
    V1[0] = point(1.0, 0.0, 0.0);
    V1[1] = point(0.0, 1.0, 0.0);
    V1[2] = point(-1.0, 0.0, 0.0);

    point V2[3];
    V2[0] = point(-1.0, 0.0, 0.0);
    V2[1] = point(0.0, -1.0, 0.0);
    V2[2] = point(1.0, 0.0, 0.0);

    // Initialize triangle
    triangle Triangle1(V1);
    triangle Triangle2(V2);
    triangle tmp_Triangle1(V1);
    triangle tmp_Triangle2(V2);

    // Initialize rotation matrix
    affine tmp_affine;
    tmp_affine = translate(0.0, 0.0, 0.0);

    // Initialize intersection point
    point IntersectionPointTri1, IntersectionPointTri2;
    bool IntersectionBoolTri1, IntersectionBoolTri2;

    // Initialize Ray
    point LineOrigin(1.0, 0.0, 2.0);
    vec3 LineDirection(0.0, 0.0, -1.0);
    line Line(LineOrigin, LineDirection);

    real step = PI / 360.0;
    // Perform intersection at 0.5° step
    for (real angle = -step;
        angle < PI;
        angle += step)
    {

      tmp_affine = angleaxis(angle, UNITX_VEC3);
      angle += step;

      tmp_Triangle1 = Triangle1;
      tmp_Triangle2 = Triangle2;
      tmp_Triangle1.transform(tmp_affine);
      tmp_Triangle2.transform(tmp_affine);

      IntersectionBoolTri1 = Intersection(Line, tmp_Triangle1, IntersectionPointTri1, EPSILON_ACME);
      IntersectionBoolTri2 = Intersection(Line, tmp_Triangle2, IntersectionPointTri2, EPSILON_ACME);

      std::cout
          << angle / PIDIV180 << "°\t"
          << "T1 -> " << IntersectionBoolTri1 << ", T2 -> " << IntersectionBoolTri2 << std::endl;

      // ERROR if no one of the two triangles is hit
      if (!IntersectionBoolTri1 && !IntersectionBoolTri2)
      {
        std::cout
          << "Check coplanarity!" << std::endl
          << std::endl
          << "TEST 05: Failed" << std::endl
          << "---------------------------" << std::endl;
      }
    }

    // Print triangle normal vector
    vec3 N1 = Triangle1.normal();
    vec3 N2 = Triangle2.normal();
    std::cout
        << std::endl
        << "Triangle 1 face normal = " << N1 << std::endl
        << "Triangle 2 face normal = " << N2 << std::endl;

    // End of test
    std::cout
      << std::endl
      << "TEST 05: Completed" << std::endl
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
/// eof: test_05.cc
///
