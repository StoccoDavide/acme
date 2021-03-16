///
/// file: ddd_point.hh
///

#ifndef INCLUDE_DDD_POINT
#define INCLUDE_DDD_POINT

#include "ddd_math.hh"

namespace ddd
{

  /*\
   |               _       _   
   |   _ __   ___ (_)_ __ | |_ 
   |  | '_ \ / _ \| | '_ \| __|
   |  | |_) | (_) | | | | | |_ 
   |  | .__/ \___/|_|_| |_|\__|
   |  |_|                      
  \*/

  //! Point class container
  /*!
  Class representing a point in 3D space. It is constructed by
  a 3 by 1 Eigen matrix.
  */
  template <typename T = Float>
  class point : public rowObject<T>
  {
  public:
    //! Class destructor
    ~point() {}

    //! Copy constructor
    point(const point<T> &) = default;

    //! Class constructor
    point() { this->clear(); }

    //! Class constructor
    point(
        const Eigen::Matrix<T, 3, 1> &data //!< Input data
    )
    {
      this->data(data);
    }

    //! Class constructor
    point(
        const T &x, //!< Input x point value
        const T &y, //!< Input y point value
        const T &z  //!< Input z point value
    )
    {
      this->x(x);
      this->y(y);
      this->z(z);
    }

    //! Equality operator
    inline point<T> &operator=(
        const point<T> &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->data(input.data());
        return *this;
      }
    }

    //! Check if two points are (exactly) equal
    inline bool operator==(
        const point<T> &input //!< Input object
    )
    {
      return this->data() == input.data();
    }

    //! Check if two points are (exactly) equal
    inline bool operator!=(
        const point<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two points are (almost) equal
    inline bool is_equal(
        const point<T> &input //!< Input point object
    )
        const
    {
      return ddd::is_equal((this->data() - input.data()).norm(), T(0.0));
    }

    //! Check if two points are (almost) NOT equal
    inline bool is_notequal(
        const point<T> &input //!< Input point object
    )
        const
    {
      return !(this->is_equal(input));
    }

    //! Addition operator
    inline point<T> operator+(
        const point<T> &input //!< Input object
    )
        const
    {
      return point<T>(this->data() + input.data());
    }

    //! Subtraction operator
    inline point<T> operator-(
        const point<T> &input //!< Input object
    )
        const
    {
      return point<T>(this->data() - input.data());
    }

    //! Scalar product operator
    inline point<T> operator*(
        const T &input //!< Input scalar
    )
    {
      return point<T>(this->data() * input);
    }

    //! Scalar division operator
    inline point<T> operator/(
        const T &input //!< Input scalar
    )
    {
      return point<T>(this->data() / input);
    }


    //! Translate rowObject by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->data(this->data() + input.data());
    }

    //! Distance between points
    inline const T distance(
        const point<T> &input //!< Input object
    )
        const
    {
      if (!this->is_equal(input))
      {
        return (this->data() - input.data()).norm();
      }
      else
      {
        return T(0.0);
      }
    }

    //! Squared distance between two points
    inline const T distanceSquared(
        const point<T> &input //!< Input point object
    )
    {
      if (!this->is_equal(input))
      {
        return (this->data() - input.data()).squaredNorm();
      }
      else
      {
        return T(0.0);
      }
    }

    //! Return normalized point
    inline const point<T> normalized()
        const
    {
      return this->_data.normalized();
    }

  }; // class point

} // namespace ddd

#endif

///
/// eof: ddd_point.hh
///