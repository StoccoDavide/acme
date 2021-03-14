#ifndef INCLUDE_DDD_VECTOR
#define INCLUDE_DDD_VECTOR

#include <Eigen/Dense>
#include "ddd_point.hh"

namespace ddd
{

  /*\
   |                  _             
   |  __   _____  ___| |_ ___  _ __ 
   |  \ \ / / _ \/ __| __/ _ \| '__|
   |   \ V /  __/ (__| || (_) | |   
   |    \_/ \___|\___|\__\___/|_|   
   |                                
  \*/

  //! DDD vector class container
  template <typename T = Float>
  class vector : public point<T>
  {
  public:
    //! Copy constructor
    vector(const vector<T>&) = default;

    //! Class constructor
    vector() : point<T>()
    {
      this->clear();
    }

    //! Class constructor for 3D vector
    vector(
        const T &v0, //!< Input value 0
        const T &v1, //!< Input value 1
        const T &v2  //!< Input value 2
        ) : point<T>(v0, v1, v2)
    {
    }

    //! Class constructor
    vector(
        const point <T> &point //!< Input ND point
        ) : point<T>(point)
    {
    }

    //! Equality operator
    inline vector<T> &operator=(
        const vector<T> &vector //!< Input ND point
    )
    {
      this->data = vector.data;
      return *this;
    }

    //! Normalize vector
    inline void normalize()
    {
      this->data.norm();
    }

    //! Return normalized vector
    inline const vector<T> normalized()
    const
    {
      return this->data.normalized();
    }

  };

} // namespace ddd

#endif