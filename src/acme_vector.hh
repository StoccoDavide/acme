#ifndef INCLUDE_ACME_VECTOR
#define INCLUDE_ACME_VECTOR

#include <Eigen/Dense>
#include "acme_point.hh"

namespace acme
{

  /*\
   |                  _             
   |  __   _____  ___| |_ ___  _ __ 
   |  \ \ / / _ \/ __| __/ _ \| '__|
   |   \ V /  __/ (__| || (_) | |   
   |    \_/ \___|\___|\__\___/|_|   
   |                                
  \*/

  //! ND vector class container
  template <typename T = Float, std::size_t D = 3>
  class vector : public point<T, D>
  {
  public:
    //! Copy constructor
    vector(const vector<T, D>&) = default;

    //! Class constructor
    vector() : point<T, D>()
    {
      this->clear();
    }

    //! Class constructor for 1D vector
    vector(
        const T &v0 //!< Input value 0
        ) : point<T, 1>(v0)
    {
    }

    //! Class constructor for 2D vector
    vector(
        const T &v0, //!< Input value 0
        const T &v1  //!< Input value 1
        ) : point<T, 2>(v0, v1)
    {
    }

    //! Class constructor for 3D vector
    vector(
        const T &v0, //!< Input value 0
        const T &v1, //!< Input value 1
        const T &v2  //!< Input value 2
        ) : point<T, 3>(v0, v1, v2)
    {
    }

    //! Class constructor for 4D vector
    vector(
        const T &v0, //!< Input value 0
        const T &v1, //!< Input value 1
        const T &v2, //!< Input value 2
        const T &v3  //!< Input value 3
        ) : point<T, 4>(v0, v1, v2, v3)
    {
    }

    //! Class constructor
    vector(
        const point <T, D> &point //!< Input ND point
        ) : point<T, D>(point)
    {
    }

    //! Equality operator
    inline vector<T, D> &operator=(
        const vector<T, D> &vector //!< Input ND point
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
    inline const vector<T,D> normalized()
    const
    {
      return this->data.normalized();
    }

  };

} // namespace acme

#endif