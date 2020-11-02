#ifndef INCLUDE_ACME_VECTOR
#define INCLUDE_ACME_VECTOR

#include "acme_math.hh"
#include "acme_point.hh"

namespace acme
{

  template <typename T, std::size_t D>
  class vectornd;

  template <typename T>
  class vector2d;

  template <typename T>
  class vector3d;

  /*\
   |                  _            ____     _ 
   |  __   _____  ___| |_ ___  _ _|___ \ __| |
   |  \ \ / / _ \/ __| __/ _ \| '__|__) / _` |
   |   \ V /  __/ (__| || (_) | |  / __/ (_| |
   |    \_/ \___|\___|\__\___/|_| |_____\__,_|
   |                                          
  \*/

  template <typename T>
  class vector2d : public point2d<T>
  {
  public:
    vector2d(const T &value0 = T(0.0), const T &value1 = T(0.0))
    {
      this->v[0] = value0;
      this->v[1] = value1;
    }

    inline vector2d<T> &operator=(const vectornd<T, 2> &vector)
    {
      this->v[0] = vector[0];
      this->v[1] = vector[1];
      return *this;
    }
  };

  /*\
   |                _            _____     _ 
   |__   _____  ___| |_ ___  _ _|___ /  __| |
   |\ \ / / _ \/ __| __/ _ \| '__||_ \ / _` |
   | \ V /  __/ (__| || (_) | |  ___) | (_| |
   |  \_/ \___|\___|\__\___/|_| |____/ \__,_|
   |                                         
  \*/

  template <typename T>
  class vector3d : public point3d<T>
  {
  public:
    vector3d(const T &value0 = T(0.0), const T &value1 = T(0.0), const T &value2 = T(0.0))
    {
      this->v[0] = value0;
      this->v[1] = value1;
      this->v[2] = value2;
    }

    inline vector3d<T> &operator=(const vectornd<T, 3> &vector)
    {
      this->v[0] = vector[0];
      this->v[1] = vector[1];
      this->v[2] = vector[2];
      return *this;
    }
  };

  /*\
   |                  _                       _ 
   |  __   _____  ___| |_ ___  _ __ _ __   __| |
   |  \ \ / / _ \/ __| __/ _ \| '__| '_ \ / _` |
   |   \ V /  __/ (__| || (_) | |  | | | | (_| |
   |    \_/ \___|\___|\__\___/|_|  |_| |_|\__,_|
   |                                            
  \*/

  template <typename T, std::size_t D>
  class vectornd : public pointnd<T, D>
  {
  public:
    vectornd()
    {
      this->clear();
    }

    vectornd(const T &v0)
    {
      this->[0] = v0;
    }

    vectornd(const T &v0, const T &v1)
    {
      this->v[0] = v0;
      this->v[1] = v1;
    }

    vectornd(const T &v0, const T &v1, const T &v2)
    {
      this->v[0] = v0;
      this->v[1] = v1;
      this->v[2] = v2;
    }

    vectornd(const T &v0, const T &v1, const T &v2, const T &v3)
    {
      this->v[0] = v0;
      this->v[1] = v1;
      this->v[2] = v2;
      this->v[3] = v3;
    }

    vectornd(const vectornd<T, D> &vector)
        : pointnd<T, D>()
    {
      for (std::size_t i = 0; i < D; ++i)
        (this->v)[i] = vector[i];
    }
  };

} // namespace acme

#include "acme.inl"

#endif