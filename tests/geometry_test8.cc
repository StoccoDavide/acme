// GEOMETRY TEST 8 - POINT/VECTOR TRANSFORMATION

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersect.hh"
#include "acme_triangle.hh"
#include "acme_frame.hh"
#include "acme_box.hh"
#include "acme_utilities.hh"

using namespace acme;

// Main function
int main()
{
  // Initialize point and vector
  vec3 point(0.0, 0.0, 1.0);
  vec3 vector(0.0, 0.0, 1.0);

  // Initialize rotation matrix
  vec3 origin(0.0, 0.0, -1.0);
  mat3 rotation(rotation_x(PI / 4));
  frame mov_frame(origin, rotation);

  // Transform objects
  vec3 mov_point(acme::transform_point(point, ground, mov_frame));
  vec3 mov_vector(acme::transform_vector(vector, ground, mov_frame));

  // Transform objects back
  vec3 ground_point(acme::transform_point(mov_point, mov_frame, ground));
  vec3 ground_vector(acme::transform_vector(mov_vector, mov_frame, ground));

  // Display results
  std::cout
      << std::endl
      << "GEOMETRY TEST 8 - POINT/VECTOR TRANSFORMATION" << std::endl
      << std::endl
      << "Ground = " << ground << std::endl
      << std::endl
      << "Moving Frame = " << mov_frame << std::endl
      << std::endl
      << "Point  (ground) = " << point << std::endl
      << "Vector (ground) = " << vector << std::endl
      << std::endl
      << "Point  (mov. frame) = " << mov_point << std::endl
      << "Vector (mov. frame) = " << mov_vector << std::endl
      << std::endl
      << "Point  (back to ground) = " << ground_point << std::endl
      << "Vector (back to ground) = " << ground_vector << std::endl
      << std::endl
      << "GEOMETRY TEST 8: Completed" << std::endl;

  // Exit the program
  return 0;
}
