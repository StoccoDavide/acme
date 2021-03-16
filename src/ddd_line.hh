///
/// file: ddd_line.hh
///

#ifndef INCLUDE_DDD_LINE
#define INCLUDE_DDD_LINE

#include "ddd_line.hh"

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
  class line : public infObject<T>
  {
  public:
    //! Class destructor
    ~line() {}

    //! Class constructor
    line() {}

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

    //! Equality operator
    inline line<T> &operator=(
        const line<T> &input //!< Input object
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

    //! Check if two lines are (exactly) equal
    inline bool operator==(
        const line<T> &input //!< Input object
    )
    {
      return this->origin() == input.origin() && this->direction() == input.direction();
    }

    //! Check if two lines are (exactly) NOT equal
    inline bool operator!=(
        const line<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two lines are (almost) equal
    inline bool is_equal(
        const line<T> &input //!< Input object
    )
        const
    {
      return (this->origin().is_equal(input.origin()) && this->direction().is_equal(input.direction()));
    }

    //! Check if two lines are (almost) NOT equal
    inline bool is_notequal(
        const line<T> &input //!< Input vector object
    )
        const
    {
      return !(this->is_equal(input));
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_line.hh
///