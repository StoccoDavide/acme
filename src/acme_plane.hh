///
/// file: acme_plane.hh
///

#ifndef INCLUDE_ACME_PLANE
#define INCLUDE_ACME_PLANE

#include "acme_point.hh"
#include "acme_vector.hh"

namespace acme
{

  /*\
   |         _                  
   |   _ __ | | __ _ _ __   ___ 
   |  | '_ \| |/ _` | '_ \ / _ \
   |  | |_) | | (_| | | | |  __/
   |  | .__/|_|\__,_|_| |_|\___|
   |  |_|                       
  \*/

  //! ND plane class container
  template <typename T = Float, std::size_t D = 3>
  class plane
  {
    point<T, D> o;  //!< Plane origin
    vector<T, D> n; //!< Plane normal

  public:
    //! Copy constructor
    plane(const plane<T, D> &) = default;

    //! Class constructor
    plane() : o(point<T, D>()), n(vector<T, D>()) {}

    //! Return plane point
    inline const point<T, D> &origin() const
    {
      return o;
    }

    //! Return plane normal
    inline const vector<T, D> &normal() const
    {
      return n;
    }
  };

} // namespace acme

#endif

///
/// eof: acme_plane.hh
///