#include "acme_math.hh"

namespace acme
{

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T infinity()
  {
    return std::numeric_limits<T>::infinity();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T epsilon()
  {
    return static_cast<T>(Epsilon);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <>
  inline double epsilon<double>()
  {
    return static_cast<double>(Epsilon_Medium);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <>
  inline float epsilon<float>()
  {
    return static_cast<float>(Epsilon_Low);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T sqr(const T &value)
  {
    return value * value;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T cub(const T &value)
  {
    return value * value * value;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T sqrt(const T &value)
  {
    return std::sqrt(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T abs(const T &value)
  {
    return std::abs(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T max(const T &value1, const T &value2)
  {
    return std::max<T>(value1, value2);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T min(const T &value1, const T &value2)
  {
    return std::min<T>(value1, value2);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T max(const T &value1, const T &value2, const T &value3)
  {
    return max(value1, max(value2, value3));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T min(const T &value1, const T &value2, const T &value3)
  {
    return min(value1, min(value2, value3));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T sin(const T &value)
  {
    return std::sin(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T cos(const T &value)
  {
    return std::cos(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T tan(const T &value)
  {
    return std::tan(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T asin(const T &value)
  {
    return std::asin(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T acos(const T &value)
  {
    return std::acos(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T atan(const T &value)
  {
    return std::atan(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T clamp(
      const T &value,
      const T &low,
      const T &high)
  {
    if (value < low)
      return low;
    if (value > high)
      return high;

    return value;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme
