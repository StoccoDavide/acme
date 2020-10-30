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
  inline T sqr(
      const T &value)
  {
    return value * value;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T sqrt(
      const T &value)
  {
    return std::sqrt(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T abs(
      const T &value)
  {
    return std::abs(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T max(
      const T &value1,
      const T &value2)
  {
    return std::max<T>(value1, value2);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T min(
      const T &value1,
      const T &value2)
  {
    return std::min<T>(value1, value2);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T max(
      const T &value1,
      const T &value2,
      const T &value3)
  {
    return max(value1, max(value2, value3));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T min(
      const T &value1,
      const T &value2,
      const T &value3)
  {
    return min(value1, min(value2, value3));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T sin(
      const T &value)
  {
    return std::sin(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T cos(
      const T &value)
  {
    return std::cos(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T tan(
      const T &value)
  {
    return std::tan(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T asin(
      const T &value)
  {
    return std::asin(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T acos(
      const T &value)
  {
    return std::acos(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T atan(
      const T &value)
  {
    return std::atan(value);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T approx_sin(
      T value)
  {
    T final_sign = T(1.0);

    if ((value <= T(180.0)) && (value > 90.0))
    {
      value = T(180.0) - value;
      final_sign = T(1.0);
    }
    else if ((value <= T(270.0)) && (value > T(180.0)))
    {
      value = value - T(180.0);
      final_sign = T(-1.0);
    }
    else if ((value <= T(360.0)) && (value > T(270.0)))
    {
      value = T(360.0) - value;
      final_sign = T(-1.0);
    }

    value *= T(PI / 180.0);
    T asqr = value * value;
    T result = T(-2.39e-08);
    result *= asqr;
    result += T(2.7526e-06);
    result *= asqr;
    result -= T(1.98409e-04);
    result *= asqr;
    result += T(8.3333315e-03);
    result *= asqr;
    result -= T(1.666666664e-01);
    result *= asqr;
    result += T(1.0);
    result *= value;

    return result * final_sign;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T approx_cos(
      T value)
  {
    T final_sign = T(1.0);

    if ((value <= T(180.0)) && (value > 90.0))
    {
      value = T(180.0) - value;
      final_sign = T(-1.0);
    }
    else if ((value <= T(270.0)) && (value > T(180.0)))
    {
      value = value - T(180.0);
      final_sign = T(-1.0);
    }
    else if ((value <= T(360.0)) && (value > T(270.0)))
    {
      value = T(360.0) - value;
      final_sign = T(1.0);
    }

    value *= T(PI / 180.0);
    T asqr = value * value;
    T result = T(-2.605e-07);
    result *= asqr;
    result += T(2.47609e-05);
    result *= asqr;
    result -= T(1.3888397e-03);
    result *= asqr;
    result += T(4.16666418e-02);
    result *= asqr;
    result -= T(4.999999963e-01);
    result *= asqr;
    result += T(1.0);

    return result * final_sign;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  template <typename T>
  inline T approx_tan(
      T value)
  {
    T final_sign = T(1.0);

    if ((value <= T(180.0)) && (value > 90.0))
    {
      value = T(180.0) - value;
      final_sign = T(-1.0);
    }
    else if ((value <= T(270.0)) && (value > T(180.0)))
    {
      value = value - T(180.0);
      final_sign = T(1.0);
    }
    else if ((value <= T(360.0)) && (value > T(270.0)))
    {
      value = T(360.0) - value;
      final_sign = T(-1.0);
    }

    value *= T(PI / 180.0);
    T asqr = value * value;
    T result = T(9.5168091e-03);
    result *= asqr;
    result += T(2.900525e-03);
    result *= asqr;
    result += T(2.45650893e-02);
    result *= asqr;
    result += T(5.33740603e-02);
    result *= asqr;
    result += T(1.333923995e-01);
    result *= asqr;
    result += T(3.333314036e-01);
    result *= asqr;
    result += T(1.0);
    result *= value;

    return result * final_sign;
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
