///
/// file: ddd_ray.hh
///

#ifndef INCLUDE_DDD_RAY
#define INCLUDE_DDD_RAY

#include "ddd_infObject.hh"

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
  class ray : public infObject<T>
  {

  public:
    //! Class destructor
    ~ray() {}

    //! Class constructor
    ray() {}

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

    //! Equality operator
    inline ray<T> &operator=(
        const ray<T> &input //!< Input object
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

    //! Check if two rays are (exactly) equal
    inline bool operator==(
        const ray<T> &input //!< Input object
    )
    {
      return this->origin() == input.origin() && this->direction() == input.direction();
    }

    //! Check if two rays are (exactly) NOT equal
    inline bool operator!=(
        const ray<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two rays are (almost) equal
    inline bool is_equal(
        const ray<T> &input //!< Input object
    )
        const
    {
      return (this->origin().is_equal(input.origin()) && this->direction().is_equal(input.direction()));
    }

    //! Check if two rays are (almost) NOT equal
    inline bool is_notequal(
        const ray<T> &input //!< Input vector object
    )
        const
    {
      return !(this->is_equal(input));
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_ray.hh
///