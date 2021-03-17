///
/// file: ddd_rotation.hh
///

#ifndef INCLUDE_DDD_ROTATION
#define INCLUDE_DDD_ROTATION

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
  class rotation final
  {
  private:
    Eigen::Matrix<T, 3, 3> _data; //!< Data as Eigen 3 by 3 matrix

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
      this->_data = data;
    }

    //! Class constructor
    rotation(
        const vector<T> &x, //!< Input x vector value
        const vector<T> &y, //!< Input y vector value
        const vector<T> &z  //!< Input z vector value
    )
    {
      this->_data[0] = x;
      this->_data[1] = y;
      this->_data[2] = z;
    }

  public:
    //! Clear data
    void clear()
    {
      for (std::size_t i = 0; i < 3; ++i)
      {
        for (std::size_t j = 0; j < 3; ++j)
        {
          this->_data[i, j] = T(0.0);
        }
      }
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

    //! Scale object
    inline void scale(
        const T &value //!< Scale value
    )
    {
      this->_data = this->_data * value;
    }

    //! Indexing operator
    inline T &operator[](
        const std::size_t &i, //!< Input index
        const std::size_t &j  //!< Input index
    )
    {
      return this->_data[i, j];
    }

    //! Indexing operator
    inline const T &operator[](
        const std::size_t &i, //!< Input index
        const std::size_t &j  //!< Input index
    )
        const
    {
      return this->_data[i, j];
    }

    //! Get x vector
    inline const T &x(void) const { return this->_data.col(0); }

    //! Get y vector
    inline const T &y(void) const { return this->_data.col(1); }

    //! Get z vector
    inline const T &z(void) const { return this->_data.col(2); }

    //! Get data
    inline const Eigen::Matrix<T, 3, 3> &data(void) const { return this->_data; }

    //! Set x vector
    inline void x(
        const vector<T> &input //!< Input vector
    )
    {
      this->_data.col(0) = input.data();
    }

    //! Set y vector
    inline void y(
        const vector<T> &input //!< Input vector
    )
    {
      this->_data.col(1) = input.data();
    }

    //! Set z vector
    inline void z(
        const vector<T> &input //!< Input vector
    )
    {
      this->_data.col(2) = input.data();
    }

    //! Set data
    inline void data(
        const Eigen::Matrix<T, 3, 3> &data //!< Input data
    )
    {
      this->_data = data;
    }

    //! Check if two rotation matrix is othonormal
    inline const bool is_othonormal(void) const
    {
      return (this->x().is_othogonal(this->y()) &&
              this->y().is_othogonal(this->z()) &&
              this->z().is_othogonal(this->x()) &&
              this->x().is_unitary() &&
              this->y().is_unitary() &&
              this->z().is_unitary());
    }

    //! Check if two rotation matrix is NOT othonormal
    inline const bool is_notothonormal(void) const
    {
      return !(this->is_othonormal());
    }

    //! Get transposed matrix
    inline Eigen::Matrix<T, 3, 3> transpose(void)
    {
      return this->_data.transpose();
    }

    //! Transpose matrix
    inline void transpose(void) const
    {
      this->_data = this->_data.transpose();
    }

    //! Get inverse rotation matrix (othonormality must be checked manually!)
    inline Eigen::Matrix<T, 3, 3> inverse(void)
    {
      return this->_data.transpose();
    }

    //! Inverse rotation matrix (othonormality must be checked manually!)
    inline void inverse(void) const
    {
      this->_data = this->_data.transpose();
    }

    //! Perform rotation on x-axis
    inline void rotate_x(
        const T &input //!< Input angle [rad]
    )
    {
      this->_data = this->_data * ddd::rotation_x(input);
    }

    //! Perform rotation on y-axis
    inline void rotate_y(
        const T &input //!< Input angle [rad]
    )
    {
      this->_data = this->_data * ddd::rotation_y(input);
    }

    //! Perform rotation on z-axis
    inline void rotate_z(
        const T &input //!< Input angle [rad]
    )
    {
      this->_data = this->_data * ddd::rotation_z(input);
    }

  }; // class rotation

} // namespace ddd

#endif

///
/// eof: ddd_rotation.hh
///