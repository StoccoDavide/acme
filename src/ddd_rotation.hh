///
/// file: ddd_matObject.hh
///

#ifndef INCLUDE_DDD_MATOBJECT
#define INCLUDE_DDD_MATOBJECT

#include "ddd_math.hh"

namespace ddd
{

  /*\
   |             _        _   _             
   |   _ __ ___ | |_ __ _| |_(_) ___  _ __  
   |  | '__/ _ \| __/ _` | __| |/ _ \| '_ \ 
   |  | | | (_) | || (_| | |_| | (_) | | | |
   |  |_|  \___/ \__\__,_|\__|_|\___/|_| |_|
   |                                        
  \*/

  //! Rotation class container
  /*!
  Class representing a rotation in 3D space. It is constructed by
  a 3 by 3 Eigen matrix.
  */
  template <typename T = Float>
  class rotation : public matObject<T>
  {
  public:
    //! Class destructor
    ~rotation() {}

    //! Copy constructor
    rotation(const rotation<T> &) = default;

    //! Class constructor
    rotation() { this->clear(); }

    //! Class constructor
    rotation(
        const Eigen::Matrix<T, 3, 3> &data //!< Input data
    )
    {
      this->data(data);
    }

    //! Class constructor
    rotation(
        const vector<T> &x, //!< Input x vector value
        const vector<T> &y, //!< Input y vector value
        const vector<T> &z  //!< Input z vector value
    )
    {
      this->x(x);
      this->y(y);
      this->z(z);
    }

    //! Equality operator
    inline rotation<T> &operator=(
        const rotation<T> &input //!< Input object
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

    //! Check if two rotations are (exactly) equal
    inline bool operator==(
        const rotation<T> &input //!< Input object
    )
    {
      return this->data() == input.data();
    }

    //! Check if two rotations are (exactly) equal
    inline bool operator!=(
        const rotation<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two rotations are (almost) equal
    inline bool is_equal(
        const rotation<T> &input //!< Input rotation object
    )
        const
    {
      return ddd::is_equal((this->data() - input.data()).norm(), T(0.0));
    }

    //! Check if two rotations are (almost) NOT equal
    inline bool is_notequal(
        const rotation<T> &input //!< Input rotation object
    )
        const
    {
      return !(this->is_equal(input));
    }

    //! Scalar product operator
    inline rotation<T> operator*(
        const T &input //!< Input scalar
    )
    {
      return rotation<T>(this->data() * input);
    }

    //! Scalar division operator
    inline rotation<T> operator/(
        const T &input //!< Input scalar
    )
    {
      return rotation<T>(this->data() / input);
    }

    //! External product operator
    inline point<T> operator*(
        const point<T> &input //!< Input point
    )
    {
      return point<T>(this->data() * input.data());
    }

    //! External product operator
    inline vector<T> operator*(
        const vector<T> &input //!< Input vector
    )
    {
      return vector<T>(this->data() * input.data());
    }

    //! Rotation product operator
    inline rotation<T> operator*(
        const rotation<T> &input //!< Input vector
    )
        const
    {
      return rotation<T>(this->data() * input.data());
    }

    //! Check if two rotation is othonormal
    inline const bool is_othonormal(void) const
    {
      return (this->x().is_othogonal(this->y()) &&
              this->y().is_othogonal(this->z()) &&
              this->z().is_othogonal(this->x()) &&
              this->x().is_unitary() &&
              this->y().is_unitary() &&
              this->z().is_unitary());
    }

  }; // class matObject

} // namespace ddd

#endif

///
/// eof: ddd_matObject.hh
///