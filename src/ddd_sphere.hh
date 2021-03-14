///
/// file: ddd_sphere.hh
///

#ifndef INCLUDE_ACME_SPHERE
#define INCLUDE_ACME_SPHERE

#include "ddd_point.hh"

namespace ddd
{

  /*\
   |             _                   
   |   ___ _ __ | |__   ___ _ __ ___ 
   |  / __| '_ \| '_ \ / _ \ '__/ _ \
   |  \__ \ |_) | | | |  __/ | |  __/
   |  |___/ .__/|_| |_|\___|_|  \___|
   |      |_|                        
  \*/

  //! ND sphere class container
  template <typename T = Float>
  class sphere
  {
    point<T> center; //!< Sphere center
    T radius;        //!< Sphere radius

  public:
    //! Copy constructor
    sphere(const sphere<T> &) = default;

    //! Class constructor
    sphere() : center(point<T>()), radius(T()) {}

    //! Return sphere point
    inline const point<T> &center() const
    {
      return center;
    }

    //! Return sphere radiuszz
    inline const T &radius() const
    {
      return radius;
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_sphere.hh
///