///
/// file: ddd_plane.hh
///

#ifndef INCLUDE_DDD_PLANE
#define INCLUDE_DDD_PLANE

#include "ddd_infiniteObject.hh"

namespace ddd
{

  /*\
   |         _                  
   |   _ __ | | __ _ _ __   ___ 
   |  | '_ \| |/ _` | '_ \ / _ \
   |  | |_) | | (_| | | | |  __/
   |  | .__/|_|\__,_|_| |_|\___|
   |  |_|                       
  \*/

  //! Plane class container
  /*!
  3D plane defined by arbutrary point on the plane and a normal vector.
  */
  template <typename T = Float>
  class plane : public infiniteObject<T>
  {
    //! Class destructor
    ~plane()
    {
    }

    //! Copy constructor
    plane(const plane<T> &) = default;

    //! Class constructor for plane
    plane(
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
    plane(
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
/// eof: ddd_plane.hh
///