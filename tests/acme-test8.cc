// GEOMETRY TEST 8 - POINT/VECTOR TRANSFORMATION

#include <fstream>
#include <iostream>
#include <string>

#include <Eigen/Geometry>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_triangle.hh"
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
  affine transformation = translate(0.0, 0.0, -1.0) * rotate(PI / 4, "X");

  // Transform objects
  vec3 mov_point(point);
  vec3 mov_vector(vector);
  acme::transformPoint(mov_point, transformation);
  acme::transformVector(mov_vector, transformation);

  // Transform objects back
  vec3 ground_point(mov_point);
  vec3 ground_vector(mov_vector);
  acme::transformPoint(ground_point, transformation.inverse());
  acme::transformVector(ground_vector, transformation.inverse());

  // Display results
  std::cout
      << std::endl
      << "GEOMETRY TEST 8 - POINT/VECTOR TRANSFORMATION" << std::endl
      << std::endl
      << "Point  (ground) = " << point << std::endl
      << "Vector (ground) = " << vector << std::endl
      << std::endl
      << "Point  (moving frame) = " << mov_point << std::endl
      << "Vector (moving frame) = " << mov_vector << std::endl
      << std::endl
      << "Point  (back to ground) = " << ground_point << std::endl
      << "Vector (back to ground) = " << ground_vector << std::endl
      << std::endl
      << "GEOMETRY TEST 8: Completed" << std::endl;

  // Exit the program
  return 0;
}
