///
/// file: ddd_infObject.hh
///

#ifndef INCLUDE_DDD_INFOBJECT
#define INCLUDE_DDD_INFOBJECT

#include "ddd_point.hh"
#include "ddd_vector.hh"

namespace ddd
{

  /*\
   |   _        __  ___  _     _           _   
   |  (_)_ __  / _|/ _ \| |__ (_) ___  ___| |_ 
   |  | | '_ \| |_| | | | '_ \| |/ _ \/ __| __|
   |  | | | | |  _| |_| | |_) | |  __/ (__| |_ 
   |  |_|_| |_|_|  \___/|_.__// |\___|\___|\__|
   |                        |__/               
  \*/

  //! Infinite object class container
  /*!
  Base class for infinite objects in 3D space.
  */
  template <typename T = Float>
  class infObject
  {
  private:
    point<T> _origin;     //!< Origin
    vector<T> _direction; //!< Direction/Normal to plane

  protected:
    //! Class destructor
    ~infObject() {}

    //! Class constructor
    infObject() {}

    //! Class constructor for 3D line
    infObject(
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
    infObject(
        const point<T> &origin,    //!< Input origin point
        const vector<T> &direction //!< Input direction
    )
    {
      this->_origin = origin;
      this->_direction = direction;
    }

  public:
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
        const infObject<T> &input //!< Input object
    )
        const
    {
      return this->_direction.is_equal(input._direction);
    }

    //! Check if two objects are NOT parallel
    inline bool is_notparallel(
        const infObject<T> &input //!< Input object
    )
        const
    {
      return !this.is_parallel(input);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const infObject<T> &input //!< Input vector object
    )
        const
    {
      return this->_direction.is_orthogonal(input._direction);
    }

    //! Check if two objects are NOT orthogonal
    inline bool is_notorthogonal(
        const infObject<T> &input //!< Input vector object
    )
        const
    {
      return !this.is_orthogonal(input);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const infObject<T> &input //!< Input object
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
/// eof: ddd_infObject.hh
///