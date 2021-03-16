///
/// file: ddd_instantiate.hh
///

#ifndef INCLUDE_DDD_INSTANTIATE
#define INCLUDE_DDD_INSTANTIATE

namespace ddd
{

  // Point base class
  template <typename T>
  class point;

  // Derived vector class
  template <typename T>
  class vector;

  
  // Virtual infinite object base class
  template <typename T>
  class infiniteObject;
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

  // Finite objects classes (4 points)
  template <typename T>
  class quadix;

  // Finite objects classes (1 point + real)
  template <typename T>
  class sphere;

  // Finite objects classes (1 point + real + vector)
  template <typename T>
  class circle;

} // namespace ddd

#endif

///
/// eof: ddd_instantiate.hh
///
