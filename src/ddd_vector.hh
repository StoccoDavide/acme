#ifndef INCLUDE_DDD_VECTOR
#define INCLUDE_DDD_VECTOR

#include <Eigen/Dense>
#include "ddd_vector.hh"

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
  Base class representing a vector in 3D space. Constructed by three components
  (X, Y and Z). Additionally, can be constructed by point, representing radius
  vector of that point, or by two points, representing vector from first point
  to another.
  */
  template <typename T = Float>
  class vector : public point<T>
  {
  public:
    //! Class destructor
    ~vector() {}

    //! Copy constructor
    vector(const vector<T> &) = default;

    //! Class constructor
    vector() : point<T>() {}

    //! Class constructor
    vector(
        const Eigen::Matrix<T, 3, 1> &data //!< Input data
    )
    {
      this->_data = data;
    }

    //! Class constructor
    vector(
        const T &x, //!< Input x value
        const T &y, //!< Input y value
        const T &z  //!< Input z value
        ) : vector<T>(x, y, z)
    {
    }

    //! Class constructor
    vector(
        const point<T> &input //!< Input point object
        ) : point<T>(input)
    {
    }

    //! Equality operator
    inline vector<T> &operator=(
        const vector<T> &vector //!< Input vector object
    )
    {
      this->_data = vector._data;
      return *this;
    }

    //! Indexing operator
    inline T &operator[](
        const std::size_t &i //!< Input index
    )
    {
      return this->_data[i];
    }

    //! Indexing operator
    inline const T &operator[](
        const std::size_t &i //!< Input index
    )
        const
    {
      return this->_data[i];
    }

    //! Get x coordinate
    inline const T &x(void) const { return this->_data.x(); }

    //! Get y coordinate
    inline const T &y(void) const { return this->_data.y(); }

    //! Get z coordinate
    inline const T &z(void) const { return this->_data.z(); }

    //! Convert to point
    inline const point<T> &toPoint(void)
    {
      return point<T>(this);
    }

    //! Addition operator
    inline const vector<T> operator+(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return vector<T>(this->_data + input._data);
    }

    //! Subtraction operator
    inline const vector<T> operator-(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return vector<T>(this->_data - input._data);
    }

    //! Addition function
    inline void add(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_data = this->_data + input._data;
    }

    //! Subtraction function
    inline void subtract(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_data = this->_data - input._data;
    }

    //! Dot product function
    inline const vector<T> dot(
        const vector<T> &input //!< Input vector object
    )
    {
      return this->dot(input);
    }

    //! Cross product function
    inline const vector<T> cross(
        const vector<T> &input //!< Input vector object
    )
    {
      return this->cross(input);
    }

    //! Scalar product function
    inline void scalar(
        const T &value //!< Scalar value
    )
    {
      this->_data = this->_data * value;
    }

    //! Translate vector by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_data = this->_data + input._data;
    }

    //! Normalize vector
    inline void normalize(void)
    {
      this->_data.normalize();
    }

    //! Return vector norm
    inline const T &norm(void) const
    {
      return this->_data.norm();
    }

    //! Return normalized vector
    inline const vector<T> &normalized(void) const
    {
      return this->_data.normalized();
    }

    //! Check if vector is equal
    inline bool is_equal(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return ddd::is_equal((this->_data - input._data).norm(), T(0.0));
    }

    //! Check if two vectors are parallel
    inline bool is_parallel(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return is_equal((this->normalized().cross(input.normalized())).norm(), 0.0);
    }

    //! Check if two vectors are NOT parallel
    inline bool is_notparallel(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return !this.is_parallel(input);
    }

    //! Check if two vectors are orthogonal
    inline bool is_orthogonal(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return is_equal(abs(this->dot(input)) / (this->norm() * input.norm()), 0.0);
    }

    //! Check if two vectors are NOT orthogonal
    inline bool is_notorthogonal(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return !this.is_orthogonal(input);
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

    //! Equality operator
    inline bool operator==(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return this.is_equal(input);
    }

    //! Disequality operator
    inline bool operator!=(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return !(this == input);
    }

    //! Angle between two vectors [rad]
    inline const T &angle(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return acos(this->_data.dot(input) / (this->norm() * input.norm()));
    }

    //! Angle between vector and line [rad]
    inline const T &angle(
        const line<T> &input //!< Input line object
    )
        const
    {
      return this->angle(input.direction());
    }

    //! Angle between vector and ray [rad]
    inline const T &angle(
        const ray<T> &input //!< Input vector object
    )
        const
    {
      return this->angle(input.direction());
    }

    //! Angle between vector and segment [rad]
    inline const T &angle(
        const segment<T> &input //!< Input vector object
    )
        const
    {
      return this->angle(input.toVector());
    }

  }; // class vector

} // namespace ddd

#endif