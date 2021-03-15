///
/// file: ddd_line.hh
///

#ifndef INCLUDE_DDD_LINE
#define INCLUDE_DDD_LINE

#include "ddd_point.hh"

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
  class line
  {
  private:
    point<T> _origin;     //!< Line origin
    vector<T> _direction; //!< Line direction

  public:
    //! Class destructor
    ~line() {}

    //! Copy constructor
    line(const line<T> &) = default;

    //! Class constructor for 3D line
    line(
        const T &ox, //<! Input x oringin value
        const T &oy, //<! Input y oringin value
        const T &oz, //<! Input z oringin value
        const T &dx, //<! Input x direction value
        const T &dy, //<! Input y direction value
        const T &dz  //<! Input z direction value
    )
    {
      this->_origin = point<T>(ox, oy, oz);
      this->_direction = vector<T>(dx, dy, dz);
    }

    //! Class constructor
    line(
        const point<T> &origin,    //!< Input origin point
        const vector<T> &direction //!< Input direction
    )
    {
      this->_origin = origin;
      this->_direction = direction;
    }

    //! Equality operator
    inline line<T> &operator=(
        const line<T> &input //!< Input line object
    )
    {
      this->_origin = input._origin;
      this->_direction = input._direction;
      return *this;
    }

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

    //! Convert to ray
    inline const ray<T> &toRay(void) const
    {
      return ray<T>(this);
    }

    //! Translate line by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_origin.translate(input);
    }

    //! Check if two lines are equal
    inline bool is_equal(
        const line<T> &input //!< Input vector object
    )
        const
    {
      return (is_equal(this->_origin.is_equal(input._origin), T(0.0)) &&
              is_equal(this->_direction.is_equal(input._direction), T(0.0)));
    }

    //! Check if two lines are parallel
    inline bool is_parallel(
        const line<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_equal(input._direction);
    }

    //! Check if two lines are NOT parallel
    inline bool is_notparallel(
        const line<T> &input //!< Input vector object
    )
        const
    {
      return !this.is_parallel(input);
    }

    //! Check if two lines are orthogonal
    inline bool is_orthogonal(
        const line<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_orthogonal(input._direction);
    }

    //! Check if two lines are NOT orthogonal
    inline bool is_notorthogonal(
        const line<T> &input //!< Input vector object
    )
        const
    {
      return !this.is_orthogonal(input);
    }

    //! Angle between line and vector [rad]
    inline const T &angle(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return input.angle(this->direction());
    }

    //! Angle between lines [rad]
    inline const T &angle(
        const line<T> &input //!< Input line object
    )
        const
    {
      return (this->direction()).angle(input.direction());
    }

    //! Angle between line and ray [rad]
    inline const T &angle(
        const ray<T> &input //!< Input ray object
    )
        const
    {
      return (this->direction()).angle(input.direction());
    }

    //! Angle between line and segment [rad]
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
/// eof: ddd_line.hh
///