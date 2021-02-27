///
/// file: acme_ray.hh
///

#ifndef INCLUDE_ACME_RAY
#define INCLUDE_ACME_RAY

#include "acme_point.hh"
#include "acme_vector.hh"

namespace acme
{

  /*\
   |                   
   |   _ __ __ _ _   _ 
   |  | '__/ _` | | | |
   |  | | | (_| | |_| |
   |  |_|  \__,_|\__, |
   |             |___/ 
  \*/

  //! ND ray class container
  template <typename T = Float, std::size_t D = 3>
  class ray
  {
    point<T, D> o;  //!< Ray origin
    vector<T, D> d; //!< Ray direction

  public:
    //! Copy constructor
    ray(const ray<T, D> &) = default;

    //! Class constructor
    ray() : o(point<T, D>()), d(vector<T, D>()) {}

    //! Return ray origin
    inline const point<T, D> &origin() const
    {
      return o;
    }

    //! Return ray direction
    inline const vector<T, D> &direction() const
    {
      return d;
    }
  };

} // namespace acme

#endif

///
/// eof: acme_ray.hh
///