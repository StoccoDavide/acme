///
/// file: ddd_line.hh
///

#ifndef INCLUDE_DDD_LINE
#define INCLUDE_DDD_LINE

#include "ddd_infiniteObject.hh"

namespace ddd
{

  /*\
   |   _ _            
   |  | (_)_ __   ___ 
   |  | | | '_ \ / _ \
   |  | | | | | |  __/
   |  |_|_|_| |_|\___|
   |                  
  \*/

  //! Line class container
  /*!
  Infinite line in 3D space and defined by any point lying on the line and a direction
  vector.
  */
  template <typename T = Float>
  class line : public infiniteObject<T>
  {
  public:
    //! Class destructor
    ~line() {}

    //! Copy constructor
    line(const line<T> &) = default;

    //! Class constructor for line
    line(
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
    line(
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
/// eof: ddd_line.hh
///