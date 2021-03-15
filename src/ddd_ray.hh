///
/// file: ddd_ray.hh
///

#ifndef INCLUDE_DDD_RAY
#define INCLUDE_DDD_RAY

#include "ddd_point.hh"
#include "ddd_vector.hh"

namespace ddd
{

  /*\
   |                   
   |   _ __ __ _ _   _ 
   |  | '__/ _` | | | |
   |  | | | (_| | |_| |
   |  |_|  \__,_|\__, |
   |             |___/ 
  \*/

  //! Ray class container
  template <typename T = Float>
  class ray
  {
    point<T> _origin;     //!< Ray origin
    vector<T> _direction; //!< Ray direction

  public:
    //! Copy constructor
    ray(const ray<T> &) = default;

    //! Class constructor
    ray() : _origin(point<T>()), _direction(vector<T>()) {}

    //! Return ray origin
    inline const point<T> &origin() const
    {
      return _origin;
    }

    //! Return ray direction
    inline const vector<T> &direction() const
    {
      return _direction;
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_ray.hh
///