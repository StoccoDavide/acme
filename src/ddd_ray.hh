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
  class ray : public line<T>
  {

  public:
    //! Class destructor
    ~ray() {}

    //! Copy constructor
    ray(const ray<T> &) = default;

    //! Class constructor
    ray() : line<T>() {}

    //! Return ray origin
    inline const point<T> &origin() const
    {
      return this->_origin;
    }

    //! Return ray direction
    inline const vector<T> &direction() const
    {
      return this->_direction;
    }

    //! Equality operator
    inline ray<T> &operator=(
        const ray<T> &input //!< Input line object
    )
    {
      this->_origin = input._origin;
      this->_direction = input._direction;
      return *this;
    }

    //! Convert to line
    inline const line<T> &toLine(void)
    {
      return line<T>(this);
    }

    //! Translate ray by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_origin.translate(input);
    }

    //! Check if two rays are equal
    inline bool is_equal(
        const ray<T> &input //!< Input ray object
    )
        const
    {
      return (is_equal(this->_origin.is_equal(input._origin), T(0.0)) &&
              is_equal(this->_direction.is_equal(input._direction), T(0.0)));
    }

    //! Check if two rays are parallel
    inline bool is_parallel(
        const ray<T> &input //!< Input ray object
    )
        const
    {
      return this->_direction.is_equal(input._direction);
    }

    //! Check if two rays are NOT parallel
    inline bool is_notparallel(
        const ray<T> &input //!< Input ray object
    )
        const
    {
      return !this->is_parallel(input);
    }

    //! Check if two rays are orthogonal
    inline bool is_orthogonal(
        const ray<T> &input //!< Input ray object
    )
        const
    {
      return this->_direction.is_orthogonal(input._direction);
    }

    //! Check if two rays are NOT orthogonal
    inline bool is_notorthogonal(
        const ray<T> &input //!< Input ray object
    )
        const
    {
      return !this->is_orthogonal(input);
    }

    //! Reverse ray direction
    inline void reverse(void) { this->_direction = -this->_direction; }

    //! Angle between ray and vector [rad]
    inline const T &angle(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return input.angle(this->direction());
    }

    //! Angle between ray and line [rad]
    inline const T &angle(
        const line<T> &input //!< Input line object
    )
        const
    {
      return input.angle(this->direction());
    }

    //! Angle between rays [rad]
    inline const T &angle(
        const ray<T> &input //!< Input ray object
    )
        const
    {
      return (this->direction()).angle(input.direction());
    }

    //! Angle between ray and segment [rad]
    inline const T &angle(
        const segment<T> &input //!< Input segment object
    )
        const
    {
      return (this->direction()).angle(input.toVector());
    }

  };

} // namespace ddd

#endif

///
/// eof: ddd_ray.hh
///