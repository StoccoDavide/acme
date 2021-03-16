///
/// file: ddd_plane.hh
///

#ifndef INCLUDE_DDD_PLANE
#define INCLUDE_DDD_PLANE

#include "ddd_infObject.hh"

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
  3D plane defined by arbitrary point on the plane and a normal vector.
  */
  template <typename T = Float>
  class plane : public infiniteObject<T>
  {
    //! Class destructor
    ~plane() {}

    //! Class constructor
    plane() {}

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

    //! Equality operator
    inline plane<T> &operator=(
        const plane<T> &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->origin(input.origin());
        this->direction(input.direction());
        return *this;
      }
    }

    //! Check if two planes are (exactly) equal
    inline bool operator==(
        const plane<T> &input //!< Input object
    )
    {
      return this->origin() == input.origin() && this->direction() == input.direction();
    }

    //! Check if two planes are (exactly) NOT equal
    inline bool operator!=(
        const plane<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two planes are (almost) equal
    inline bool is_equal(
        const plane<T> &input //!< Input object
    )
        const
    {
      return (this->origin().is_equal(input.origin()) && this->direction().is_equal(input.direction()));
    }

    //! Check if two planes are (almost) NOT equal
    inline bool is_notequal(
        const plane<T> &input //!< Input vector object
    )
        const
    {
      return !(this->is_equal(input));
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_plane.hh
///