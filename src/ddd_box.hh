///
/// file: ddd_box.hh
///

#ifndef INCLUDE_DDD_BOX
#define INCLUDE_DDD_BOX

#include "ddd_point.hh"

namespace ddd
{

  /*\
   |   _               
   |  | |__   _____  __
   |  | '_ \ / _ \ \/ /
   |  | |_) | (_) >  < 
   |  |_.__/ \___/_/\_\
   |                   
  \*/

  //! Box class container
  template <typename T = Float>
  class box
  {
  private:
    point<T> _point0; //!< Point 0
    point<T> _point1; //!< Point 1

  public:
    //! Class destructor
    ~box() {}

    //! Copy constructor
    box(const box<T> &) = default;

    //! Class constructor
    box() {}

    //! Class constructor
    box(
        const T &x0, //<! Input x value of first point
        const T &y0, //<! Input y value of first point
        const T &z0, //<! Input z value of first point
        const T &x1, //<! Input x value of second point
        const T &y1, //<! Input y value of second point
        const T &z1  //<! Input z value of second point
        ) : _point0(point<T>(x0, y0, z0)), _point1(point<T>(x1, y1, z1))
    {
    }

    //! Class constructor
    box(
        const point<T> &point0, //!< Input point object
        const point<T> &point1  //!< Input point object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Class constructor
    box(
        const Eigen::Matrix<T, 3, 1> &point0, //!< Input point object
        const Eigen::Matrix<T, 3, 1> &point1  //!< Input point object
        ) : _point0(point0), _point1(point1)
    {
    }

    //! Equality operator
    inline box<T> &operator=(
        const box<T> &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_point0(input._point0);
        this->_point1(input._point1);
        return *this;
      }
    }

    //! Check if two objects are (exactly) equal
    inline bool operator==(
        const box<T> &input //!< Input object
    )
    {
      return this->_point0 == input._point0 && this->_point1 == input._point1;
    }

    //! Check if two objects are (exactly) NOT equal
    inline bool operator!=(
        const box<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two objects are (almost) equal
    inline bool is_equal(
        const se<T> &input //!< Input object
    )
        const
    {
      return this->_point0.is_equal(input._point0) && this->_point1.is_equal(input._point1);
    }

    //! Check if box is degenerated
    inline bool is_degenerated(void)
        const
    {
      return ddd::is_equal(_point0.distance(_point1), T(0.0));
    }

    //! Get first point
    inline point<T> &point_1(void) const { return this->_point1; }

    //! Set first point
    inline void point_1(
        const point<T> &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Get second point
    inline point<T> &point_2(void) const { return this->_point2; }

    //! Set second point
    inline void point_2(
        const point<T> &input //!< Input object
    )
    {
      this->_point2 = input;
    }

    //! Translate line by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_point0.translate(input);
      this->_point1.translate(input);
    }

  };

} // namespace ddd

#endif

///
/// eof: ddd_box.hh
///