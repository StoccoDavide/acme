///
/// file: acme_sphere.hh
///

#ifndef INCLUDE_ACME_SPHERE
#define INCLUDE_ACME_SPHERE

#include "acme_point.hh"

namespace acme
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
  template <typename T = Float, std::size_t D = 3>
  class sphere
  {
    point<T, D> o; //!< Sphere origin
    T r;           //!< Sphere ray

  public:
    //! Copy constructor
    sphere(const sphere<T, D> &) = default;

    //! Class constructor
    sphere() : o(point<T, D>()), r(T()) {}

    //! Return sphere point
    inline const point<T, D> &origin() const
    {
      return origin;
    }

    //! Return sphere ray
    inline const T &ray() const
    {
      return r;
    }
  };

} // namespace acme

#endif

///
/// eof: acme_sphere.hh
///