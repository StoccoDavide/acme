///
/// file: ddd_ray.hh
///

#ifndef INCLUDE_DDD_RAY
#define INCLUDE_DDD_RAY

#include "ddd_infiniteObject.hh"

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
  class ray : public infiniteObject<T>
  {

  public:
    //! Class destructor
    ~ray() {}

    //! Copy constructor
    ray(const ray<T> &) = default;

    //! Class constructor for ray
    ray(
        const T &ox, //<! Input x origin value
        const T &oy, //<! Input y origin value
        const T &oz, //<! Input z origin value
        const T &dx, //<! Input x direction value
        const T &dy, //<! Input y direction value
        const T &dz  //<! Input z direction value
    )
    {
      this->origin(point<T>(ox, oy, oz));
      this->direction(vector<T>(dx, dy, dz));
    }

    //! Class constructor
    ray(
        const point<T> &origin,    //!< Input origin point
        const vector<T> &direction //!< Input direction
    )
    {
      this->origin(origin);
      this->direction(direction);
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_ray.hh
///