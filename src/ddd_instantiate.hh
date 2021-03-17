///
/// file: ddd_instantiate.hh
///

#ifndef INCLUDE_DDD_INSTANTIATE
#define INCLUDE_DDD_INSTANTIATE

namespace ddd
{

  // Eigen row vector (3 by 1 matrix) base classes
  // Point/vector base classes
  template <typename T>
  class point;
  template <typename T>
  class vector;

  // Eigen 3 by 3 matrix base classes
  // Rotation matrix class
  template <typename T>
  class rotation;

  // Coordinate frame class
  template <typename T>
  class frame;

  // Infinite objects classes (point/vector description)
  template <typename T>
  class line;
  template <typename T>
  class ray;
  template <typename T>
  class plane;

  // Finite objects classes (2 points)
  template <typename T>
  class segment;
  template <typename T>
  class box;

  // Finite objects classes (3 points)
  template <typename T>
  class triangle;

  // Finite objects classes (1 real + 1 plane (center + normal))
  template <typename T>
  class circle;

} // namespace ddd

#endif

///
/// eof: ddd_instantiate.hh
///
