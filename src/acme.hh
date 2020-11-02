#ifndef INCLUDE_ACME
#define INCLUDE_ACME


#include <Eigen/Dense>
#include <cstddef>
#include <limits>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cassert>


#include "acme_math.hh"
#include "acme_point.hh"


namespace acme
{

  template <typename T, std::size_t D>
  class point;

  template <typename T>
  inline point2d<T> make_point(const T &x, const T &y);


} // namespace acme

#include "acme.inl"

#endif
