#ifndef INCLUDE_DDD_VECTOR
#define INCLUDE_DDD_VECTOR

#include "ddd_math.hh"

namespace ddd
{

  /*\
   |                  _             
   |  __   _____  ___| |_ ___  _ __ 
   |  \ \ / / _ \/ __| __/ _ \| '__|
   |   \ V /  __/ (__| || (_) | |   
   |    \_/ \___|\___|\__\___/|_|   
   |                                
  \*/

  //! Vector class container
  /*!
  Class representing a vector in 3D space. It is constructed by
  a 3 by 1 Eigen matrix.
  */
  template <typename T = Float>
  class vector : public rowObject<T>
  {
  public:
    //! Class destructor
    ~vector() {}

    //! Copy constructor
    vector(const vector<T> &) = default;

    //! Class constructor
    vector() { this->clear(); }

    //! Class constructor
    vector(
        const Eigen::Matrix<T, 3, 1> &data //!< Input data
    )
    {
      this->data(data);
    }

    //! Class constructor
    vector(
        const T &x, //!< Input x vector value
        const T &y, //!< Input y vector value
        const T &z  //!< Input z vector value
    )
    {
      this->x(x);
      this->y(y);
      this->z(z);
    }

    //! Class constructor
    vector(
        const point<T> &input //!< Input point
    )
    {
      this->data(input.data());
    };

    //! Equality operator
    inline vector<T> &operator=(
        const vector<T> &input //!< Input object
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

    //! Check if two vectors are (exactly) equal
    inline bool operator==(
        const vector<T> &input //!< Input object
    )
        const
    {
      return this->data() == input.data();
    }

    //! Check if two vectors are (exactly) equal
    inline bool operator!=(
        const vector<T> &input //!< Input object
    )
        const
    {
      return !(this == input);
    }

    //! Check if two vectors are (almost) equal
    inline bool is_equal(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return ddd::is_equal((this->data() - input.data()).norm(), T(0.0));
    }

    //! Check if two vectors are (almost) NOT equal
    inline bool is_notequal(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return !(this->is_equal(input));
    }

    //! Addition operator
    inline vector<T> operator+(
        const vector<T> &input //!< Input object
    )
        const
    {
      return vector<T>(this->data() + input.data());
    }

    //! Subtraction operator
    inline vector<T> operator-(
        const vector<T> &input //!< Input object
    )
        const
    {
      return vector<T>(this->data() - input.data());
    }

    //! Scalar product operator
    inline vector<T> operator*(
        const T &input //!< Input scalar
    )
    {
      return vector<T>(this->data() * input);
    }

    //! Scalar division operator
    inline vector<T> operator/(
        const T &input //!< Input scalar
    )
    {
      return vector<T>(this->data() / input);
    }

    //! Return normalized vector
    inline const vector<T> normalized()
        const
    {
      return this->_data.normalized();
    }

    //! Addition function
    inline void add(
        const vector<T> &input //!< Input object
    )
    {
      this->data(this->data() + input.data());
    }

    //! Subtraction function
    inline void subtract(
        const vector<T> &input //!< Input object
    )
    {
      this->data(this->data() - input.data());
    }

    //! Dot product function
    inline const vector<T> dot(
        const vector<T> &input //!< Input object
    )
    {
      return vector<T>(this.data()->dot(input.data()));
    }

    //! Cross product function
    inline const vector<T> cross(
        const vector<T> &input //!< Input object
    )
    {
      return vector<T>(this.data()->cross(input.data()));
    }

    //! Check if two vectors are parallel
    inline bool is_parallel(
        const vector<T> &input //!< Input object
    )
        const
    {
      return is_equal((this->normalized().cross(input.normalized())).norm(), 0.0);
    }

    //! Check if two vectors are NOT parallel
    inline bool is_notparallel(
        const vector<T> &input //!< Input object
    )
        const
    {
      return !(this.is_parallel(input));
    }

    //! Check if two vectors are orthogonal
    inline bool is_orthogonal(
        const vector<T> &input //!< Input object
    )
        const
    {
      return is_equal(abs(this->dot(input)) / (this->norm() * input.norm()), 0.0);
    }

    //! Check if two vectors are NOT orthogonal
    inline bool is_notorthogonal(
        const vector<T> &input //!< Input object
    )
        const
    {
      return !(this.is_orthogonal(input));
    }

    //! Check if vector has unitary norm
    inline bool is_unitary(void) const
    {
      return is_equal(this->norm() - 1.0, 0.0);
    }

    //! Check if vector has NOT unitary norm
    inline bool is_notunitary(void) const
    {
      return !(this.is_unitary());
    }

    //! Get an arbitrary vector, orthogonal to the current vector
    inline const vector<T> &orthogonalVector(void)
        const
    {
      if (abs(this->x()) <= abs(this->y()) && abs(this->x()) <= abs(this->z()))
      {
        return new vector<T>(0, this->z(), -this->y());
      }
      else if (abs(this->y()) <= abs(this->x()) && abs(this->y()) <= abs(this->z()))
      {
        return new vector<T>(this->z(), 0, -this->x());
      }
      else
      {
        return new vector<T>(this->y(), -this->x(), 0);
      }
    }

    //! Angle between two vectors [rad]
    inline const T &angle(
        const vector<T> &input //!< Input object
    )
        const
    {
      return acos(this->_data.dot(input) / (this->norm() * input.norm()));
    }

    //! Angle between vector and line [rad]
    inline const T &angle(
        const line<T> &input //!< Input object
    )
        const
    {
      return this->angle(input.direction());
    }

    //! Angle between vector and ray [rad]
    inline const T &angle(
        const ray<T> &input //!< Input object
    )
        const
    {
      return this->angle(input.direction());
    }

    //! Angle between vector and plane [rad]
    inline const T &angle(
        const plane<T> &input //!< Input object
    )
        const
    {
      return PI - this->angle(input.direction());
    }

    //! Angle between vector and segment [rad]
    inline const T &angle(
        const segment<T> &input //!< Input object
    )
        const
    {
      return this->angle(input.toVector());
    }

  }; // class vector

} // namespace ddd

#endif