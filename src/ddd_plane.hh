///
/// file: ddd_plane.hh
///

#ifndef INCLUDE_DDD_PLANE
#define INCLUDE_DDD_PLANE

#include "ddd_point.hh"
#include "ddd_vector.hh"

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
  template <typename T = Float>
  class plane
  {
    point<T> _point;   //!< Plane point
    vector<T> _normal; //!< Plane normal

  public:
    //! Class destructor
    ~plane() {}

    //! Copy constructor
    plane(const plane<T> &) = default;

    //! Class constructor
    plane() : _point(point<T>()), _normal(vector<T>()) {}

    //! Return plane point
    inline const point<T> &Point() const
    {
      return _point;
    }

    //! Return plane normal
    inline const vector<T> &Normal() const
    {
      return _normal;
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_plane.hh
///