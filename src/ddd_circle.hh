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

  //! Sphere class container
  template <typename T = Float>
  class sphere
  {
    point<T> _center; //!< Sphere center
    T _radius;        //!< Sphere radius

  public:
    //! Copy constructor
    sphere(const sphere<T> &) = default;

    //! Class constructor
    sphere() : _center(point<T>()), _radius(T()) {}

    //! Return sphere point
    inline const point<T> &Center() const
    {
      return _center;
    }

    //! Return sphere radiuszz
    inline const T &Radius() const
    {
      return _radius;
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_sphere.hh
///