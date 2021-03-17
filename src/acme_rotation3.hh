///
/// file: acme_rotation3.hh
///

/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The acme computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the acme computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

#ifndef INCLUDE_ACME_ROTATION3
#define INCLUDE_ACME_ROTATION3

#include "acme_math.hh"

namespace acme
{

  /*\
   |             _        _   _             _____ 
   |   _ __ ___ | |_ __ _| |_(_) ___  _ __ |___ / 
   |  | '__/ _ \| __/ _` | __| |/ _ \| '_ \  |_ \ 
   |  | | | (_) | || (_| | |_| | (_) | | | |___) |
   |  |_|  \___/ \__\__,_|\__|_|\___/|_| |_|____/ 
   |                                              
  \*/

  //! Rotation class container
  /*!
  Class representing a rotation3 in 3D space. It is constructed by
  a 3 by 3 Eigen matrix.
  */
  template <typename T = Float>
  class rotation3 final
  {
  private:
    Eigen::Matrix<T, 3, 3> _data; //!< Data as Eigen 3 by 3 matrix

  public:
    //! Class destructor
    ~rotation3() {}

    //! Copy constructor
    rotation3(const rotation3<T> &) = default;

    //! Class constructor
    rotation3() { this->clear(); }

    //! Class constructor
    rotation3(
        const Eigen::Matrix<T, 3, 3> &data //!< Input data
    )
    {
      this->_data = data;
    }

    //! Class constructor
    rotation3(
        const vector3<T> &x, //!< Input x value
        const vector3<T> &y, //!< Input y value
        const vector3<T> &z  //!< Input z value
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
    inline rotation3<T> &operator=(
        const rotation3<T> &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_data = input._data;
        return *this;
      }
    }

    //! Check if objects are (exactly) equal
    inline bool operator==(
        const rotation3<T> &input //!< Input object
    )
    {
      return this->data() == input.data();
    }

    //! Check if objects are (exactly) equal
    inline bool operator!=(
        const rotation3<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if objects are (almost) equal
    inline bool is_equal(
        const rotation3<T> &input //!< Input object
    )
        const
    {
      return acme::is_equal((this->data() - input.data()).norm(), T(0.0));
    }

    //! Scalar product operator
    inline rotation3<T> operator*(
        const T &input //!< Input scalar
    )
    {
      return rotation3<T>(this->data() * input);
    }

    //! Scalar division operator
    inline rotation3<T> operator/(
        const T &input //!< Input scalar
    )
    {
      return rotation3<T>(this->data() / input);
    }

    //! External product operator
    inline point3<T> operator*(
        const point3<T> &input //!< Input object
    )
    {
      return point3<T>(this->data() * input.data());
    }

    //! External product operator
    inline vector3<T> operator*(
        const vector3<T> &input //!< Input object
    )
    {
      return vector3<T>(this->data() * input.data());
    }

    //! Rotation product operator
    inline rotation3<T> operator*(
        const rotation3<T> &input //!< Input object
    )
        const
    {
      return rotation3<T>(this->data() * input.data());
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

    //! Get x vector3
    inline const T &x(void) const { return this->_data.col(0); }

    //! Get y vector3
    inline const T &y(void) const { return this->_data.col(1); }

    //! Get z vector3
    inline const T &z(void) const { return this->_data.col(2); }

    //! Get data
    inline const Eigen::Matrix<T, 3, 3> &data(void) const { return this->_data; }

    //! Set x vector3
    inline void x(
        const vector3<T> &input //!< Input object
    )
    {
      this->_data.col(0) = input.data();
    }

    //! Set y vector3
    inline void y(
        const vector3<T> &input //!< Input object
    )
    {
      this->_data.col(1) = input.data();
    }

    //! Set z vector3
    inline void z(
        const vector3<T> &input //!< Input object
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

    //! Check if rotation matrix is othonormal
    inline const bool is_othonormal(void) const
    {
      return (this->x().is_othogonal(this->y()) &&
              this->y().is_othogonal(this->z()) &&
              this->z().is_othogonal(this->x()) &&
              this->x().is_unitary() &&
              this->y().is_unitary() &&
              this->z().is_unitary());
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

    //! Get inverse rotation3 matrix (othonormality must be checked manually!)
    inline Eigen::Matrix<T, 3, 3> inverse(void)
    {
      return this->_data.transpose();
    }

    //! Inverse rotation3 matrix (othonormality must be checked manually!)
    inline void inverse(void) const
    {
      this->_data = this->_data.transpose();
    }

    //! Perform rotation3 on x-axis
    inline void rotate_x(
        const T &input //!< Input angle [rad]
    )
    {
      this->_data = this->_data * acme::rotation3_x(input);
    }

    //! Perform rotation3 on y-axis
    inline void rotate_y(
        const T &input //!< Input angle [rad]
    )
    {
      this->_data = this->_data * acme::rotation3_y(input);
    }

    //! Perform rotation3 on z-axis
    inline void rotate_z(
        const T &input //!< Input angle [rad]
    )
    {
      this->_data = this->_data * acme::rotation3_z(input);
    }

  }; // class rotation3

} // namespace acme

#endif

///
/// eof: acme_rotation3.hh
///