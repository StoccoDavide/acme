#ifndef INCLUDE_ACME_POINT
#define INCLUDE_ACME_POINT

#include "acme_math.hh"

namespace acme
{

  template <typename T, std::size_t D>
  class pointnd;

  template <typename T>
  class point2d;

  template <typename T>
  class point3d;

  /*\
   |               _       _   ____     _ 
   |   _ __   ___ (_)_ __ | |_|___ \ __| |
   |  | '_ \ / _ \| | '_ \| __| __) / _` |
   |  | |_) | (_) | | | | | |_ / __/ (_| |
   |  | .__/ \___/|_|_| |_|\__|_____\__,_|
   |  |_|                                 
  \*/

  template <typename T = Float>
  class point2d : public pointnd<T, 2>
  {
    point2d()
    {
      this->v[0] = T(0.0);
      this->v[1] = T(0.0);
    }

    point2d(const T &value0, const T &value1)
    {
      this->v[0] = value1;
      this->v[1] = value1;
    }

    point2d(const pointnd<T, 2> &point)
    {
      this->v = point.v;
    }

    ~point2d() {}

    inline const T &x() const { return this->v[0]; }
    inline const T &y() const { return this->v[1]; }

    inline void x(const T &x) { this->v[0] = x; }
    inline void y(const T &y) { this->v[1] = y; }

    inline point3d<T> &make3dX(const T &x) { return point3d<T>(x, this->v[0], this->v[1]); }
    inline point3d<T> &make3dY(const T &y) { return point3d<T>(this->v[0], y, this->v[1]); }
    inline point3d<T> &make3dZ(const T &z) { return point3d<T>(this->v[0], this->v[1], z); }
  };

  /*\
   |               _       _   _____     _ 
   |   _ __   ___ (_)_ __ | |_|___ /  __| |
   |  | '_ \ / _ \| | '_ \| __| |_ \ / _` |
   |  | |_) | (_) | | | | | |_ ___) | (_| |
   |  | .__/ \___/|_|_| |_|\__|____/ \__,_|
   |  |_|                                  
  \*/

  template <typename T = Float>
  class point3d : public pointnd<T, 3>
  {
    point3d()
    {
      this->v[0] = T(0.0);
      this->v[1] = T(0.0);
      this->v[2] = T(0.0);
    }

    point3d(const T &value0, const T &value1, const T &value2)
    {
      this->v[0] = value0;
      this->v[1] = value1;
      this->v[2] = value2;
    }

    point3d(const pointnd<T, 3> &point)
    {
      this->v = point.v;
    }

    ~point3d() {}

    inline const T &x() const { return this->v[0]; }
    inline const T &y() const { return this->v[1]; }
    inline const T &z() const { return this->v[2]; }

    inline void x(const T &x) { this->v[0] = x; }
    inline void y(const T &y) { this->v[1] = y; }
    inline void z(const T &z) { this->v[2] = z; }

    inline point2d<T> &make2dXZ(const std::size_t &index1, const std::size_t &index2)
    {
      return point2d<T>(this->v[index1], this->v[index2]);
    }
  };

  /*\
   |               _       _             _ 
   |   _ __   ___ (_)_ __ | |_ _ __   __| |
   |  | '_ \ / _ \| | '_ \| __| '_ \ / _` |
   |  | |_) | (_) | | | | | |_| | | | (_| |
   |  | .__/ \___/|_|_| |_|\__|_| |_|\__,_|
   |  |_|                                  
  \*/

  template <typename T, std::size_t D>
  class pointnd
  {
  protected:
    Eigen::Matrix<T, D, 1> v;

  public:
    pointnd() { clear(); }

    pointnd(const T &value0)
    {
      v.resize(1, 1);
      v[0] = value0;
    }
    pointnd(const T &value0, const T &value1)
    {
      v.resize(2, 1);
      v[0] = value0;
      v[1] = value1;
    }
    pointnd(const T &value0, const T &value1, const T &value2)
    {
      v.resize(3, 1);
      v[0] = value0;
      v[1] = value1;
      v[2] = value2;
    }
    pointnd(const T &value0, const T &value1, const T &value2, const T &value3)
    {
      v.resize(4, 1);
      v[0] = value0;
      v[1] = value1;
      v[2] = value2;
      v[3] = value3;
    }
    pointnd(const pointnd<T, D> &point)
    {
      this->v = point.v;
    }

    ~pointnd() {}

    void clear()
    {
      v.clear();
    }

    inline pointnd<T, D> &operator=(const pointnd<T, D> &point)
    {
      this->v = point.v;
    }

    inline T &operator[](const std::size_t &index) { return v[index]; }
    inline const T &operator[](const std::size_t &index) const { return v[index]; }
  };

} // namespace acme

#include "acme.inl"

#endif