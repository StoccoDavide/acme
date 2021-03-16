///
/// file: ddd_infiniteObject.hh
///

#ifndef INCLUDE_DDD_INFINITEOBJECT
#define INCLUDE_DDD_INFINITEOBJECT

#include "ddd_point.hh"
#include "ddd_vector.hh"

namespace ddd
{

  /*\
   |   _        __ _       _ _        ___  _     _           _   
   |  (_)_ __  / _(_)_ __ (_) |_ ___ / _ \| |__ (_) ___  ___| |_ 
   |  | | '_ \| |_| | '_ \| | __/ _ \ | | | '_ \| |/ _ \/ __| __|
   |  | | | | |  _| | | | | | ||  __/ |_| | |_) | |  __/ (__| |_ 
   |  |_|_| |_|_| |_|_| |_|_|\__\___|\___/|_.__// |\___|\___|\__|
   |                                          |__/               
  \*/

  //! Infinite Object class container
  /*!
  Infinite line in 3D space and defined by any point lying on the line and a direction
  vector.
  */
  template <typename T = Float>
  class infiniteObject
  {
  private:
    point<T> _origin;     //!< Line origin
    vector<T> _direction; //!< Line direction

  protected:
    //! Class destructor
    ~infiniteObject() {}

    //! Class constructor
    infiniteObject() {}

    //! Class constructor for 3D line
    infiniteObject(
        const T &ox, //<! Input x origin value
        const T &oy, //<! Input y origin value
        const T &oz, //<! Input z origin value
        const T &dx, //<! Input x direction value
        const T &dy, //<! Input y direction value
        const T &dz  //<! Input z direction value
    )
    {
      this->_origin = point<T>(ox, oy, oz);
      this->_direction = vector<T>(dx, dy, dz);
    }

    //! Class constructor
    infiniteObject(
        const point<T> &origin,    //!< Input origin point
        const vector<T> &direction //!< Input direction
    )
    {
      this->_origin = origin;
      this->_direction = direction;
    }

  public:
    //! Equality operator
    inline infiniteObject<T> &operator=(
        const infiniteObject<T> &input //!< Input infiniteObject object
    )
    {
      this->_origin = input._origin;
      this->_direction = input._direction;
      return *this;
    }

    //! Check if two objects are equal
    inline bool is_equal(
        const infiniteObject<T> &input //!< Input object
    )
        const
    {
      return (this->_origin.is_equal(input._origin) && this->_direction.is_equal(input._direction));
    }

    //! Check if two objects are equal
    inline bool operator==(
        const infiniteObject<T> &input //!< Input infiniteObject object
    )
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

    //! Convert to vector
    inline const vector<T> &toVector(void) const
    {
      return vector<T>(this);
    }

    //! Convert to line
    inline const line<T> &toLine(void) const
    {
      return line<T>(this);
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

    //! Check if two objects are parallel
    inline bool is_parallel(
        const infiniteObject<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_equal(input._direction);
    }

    //! Check if two objects are NOT parallel
    inline bool is_notparallel(
        const infiniteObject<T> &input //!< Input object
    )
        const
    {
      return !this.is_parallel(input);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const infiniteObject<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_orthogonal(input._direction);
    }

    //! Check if two objects are NOT orthogonal
    inline bool is_notorthogonal(
        const infiniteObject<T> &input //!< Input vector object
    )
        const
    {
      return !this.is_orthogonal(input);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const infiniteObject<T> &input //!< Input object
    )
        const
    {
      return input.angle(this->direction());
    }

    //! Reverse direction
    inline void reverse(void) { this->_direction = -this->_direction; }
  };

} // namespace ddd

#endif

///
/// eof: ddd_infiniteObject.hh
///