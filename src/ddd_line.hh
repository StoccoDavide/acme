///
/// file: ddd_line.hh
///

#ifndef INCLUDE_DDD_LINE
#define INCLUDE_DDD_LINE

#include "ddd.hh"

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
  class line final
  {
  private:
    point<T> _origin;     //!< Origin point
    vector<T> _direction; //!< Direction vector

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
        ) : _origin(point<T>(ox, oy, oz)), _direction(vector<T>(dx, dy, dz))
    {
    }

    //! Class constructor
    line(
        const point<T> &origin,    //!< Input origin point
        const vector<T> &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Class constructor
    line(
        const Eigen::Matrix<T, 3, 1> &origin,   //!< Input origin point
        const Eigen::Matrix<T, 3, 1> &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
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
        this->_origin = input._origin;
        this->_direction = input._direction;
        return *this;
      }
    }

    //! Check if two lines are (exactly) equal
    inline bool operator==(
        const line<T> &input //!< Input object
    )
    {
      return this->_origin == input._origin && this->_direction == input._direction;
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
      return this->_origin.is_equal(input._origin) && this->_direction.is_equal(input._direction);
    }

    //! Return origin
    inline const point<T> &origin() const
    {
      return this->_origin;
    }

    //! Return direction
    inline const vector<T> &direction() const
    {
      return this->_direction;
    }

    //! Set origin
    inline void origin(
        const point<T> &input //!< input point object
    )
    {
      this->_origin = input;
    }

    //! Set direction
    inline void direction(
        const vector<T> &input //!< input vector object
    )
    {
      this->_direction = input;
    }

    //! Convert to ray
    inline const ray<T> &toRay(void) const
    {
      return ray<T>(this);
    }

    //! Convert to plane
    inline const plane<T> &toPlane(void) const
    {
      return plane<T>(this);
    }

    //! Translate line by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_origin.translate(input);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const vector<T> &input //!< Input object
    )
        const
    {
      return input.is_parallel(this);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const line<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_equal(input._direction);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const ray<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_parallel(input.direction());
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const plane<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_orthogonal(input.normal());
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const segment<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_parallel(input.toVector());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return input.is_orthogonal(this);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const line<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_orthogonal(input._direction);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const ray<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_orthogonal(input.direction());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const plane<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_parallel(input.normal());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const segment<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_orthogonal(input.toVector());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const vector<T> &input //!< Input object
    )
        const
    {
      return input.angle(this));
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const line<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input._direction);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const ray<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.direction());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const plane<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.normal()) - PI / 2.0;
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const segment<T> &input //!< Input object
    )
        const
    {
      return (this->_direction).angle(input.toVector());
    }

    //! Reverse direction
    inline void reverse(void) { this->_direction = -this->_direction; }
  };

} // namespace ddd

#endif

///
/// eof: ddd_line.hh
///