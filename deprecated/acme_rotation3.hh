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
  template <typename real_type = Float>
  class rotation3 final
  {
  private:
    Eigen::Matrix<real_type, 3, 3> _data; //!< Data as Eigen 3 by 3 matrix

  public:
    //! Class destructor
    ~rotation3() {}

    //! Copy constructor
    rotation3(const rotation3 &) = default;

    //! Class constructor
    rotation3() { this->clear(); }

    //! Class constructor
    rotation3(
        const Eigen::Matrix<real_type, 3, 3> &data //!< Input data
    )
    {
      this->_data = data;
    }

    //! Class constructor
    rotation3(
        const vector3 &x, //!< Input x value
        const vector3 &y, //!< Input y value
        const vector3 &z  //!< Input z value
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
          this->_data[i, j] = real_type(0.0);
        }
      }
    }

    //! Equality operator
    rotation3 &operator=(
        const rotation3 &input //!< Input object
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
    bool operator==(
        const rotation3 &input //!< Input object
    )
    {
      return this->data() == input.data();
    }

    //! Check if objects are (exactly) equal
    bool operator!=(
        const rotation3 &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if objects are (almost) equal
    bool is_equal(
        const rotation3 &input //!< Input object
    )
        const
    {
      return acme::is_equal((this->data() - input.data()).norm(), real_type(0.0));
    }

    //! Scalar product operator
    rotation3 operator*(
        const real_type &input //!< Input scalar
    )
    {
      return rotation3(this->data() * input);
    }

    //! Scalar division operator
    rotation3 operator/(
        const real_type &input //!< Input scalar
    )
    {
      return rotation3(this->data() / input);
    }

    //! External product operator
    vector3 operator*(
        const vector3 &input //!< Input object
    )
    {
      return vector3(this->data() * input.data());
    }

    //! External product operator
    vector3 operator*(
        const vector3 &input //!< Input object
    )
    {
      return vector3(this->data() * input.data());
    }

    //! Rotation product operator
    rotation3 operator*(
        const rotation3 &input //!< Input object
    )
        const
    {
      return rotation3(this->data() * input.data());
    }

    //! Scale object
    void scale(
        const real_type &value //!< Scale value
    )
    {
      this->_data = this->_data * value;
    }

    //! Indexing operator
    real_type &operator[](
        const std::size_t &i, //!< Input index
        const std::size_t &j  //!< Input index
    )
    {
      return this->_data[i, j];
    }

    //! Indexing operator
    const real_type &operator[](
        const std::size_t &i, //!< Input index
        const std::size_t &j  //!< Input index
    )
        const
    {
      return this->_data[i, j];
    }

    //! Get x vector3
    const real_type &x(void) const { return this->_data.col(0); }

    //! Get y vector3
    const real_type &y(void) const { return this->_data.col(1); }

    //! Get z vector3
    const real_type &z(void) const { return this->_data.col(2); }

    //! Get data
    const Eigen::Matrix<real_type, 3, 3> &data(void) const { return this->_data; }

    //! Set x vector3
    void x(
        const vector3 &input //!< Input object
    )
    {
      this->_data.col(0) = input.data();
    }

    //! Set y vector3
    void y(
        const vector3 &input //!< Input object
    )
    {
      this->_data.col(1) = input.data();
    }

    //! Set z vector3
    void z(
        const vector3 &input //!< Input object
    )
    {
      this->_data.col(2) = input.data();
    }

    //! Set data
    void data(
        const Eigen::Matrix<real_type, 3, 3> &data //!< Input data
    )
    {
      this->_data = data;
    }

    //! Check if rotation matrix is othonormal
    const bool is_othonormal(void) const
    {
      return (this->x().is_othogonal(this->y()) &&
              this->y().is_othogonal(this->z()) &&
              this->z().is_othogonal(this->x()) &&
              this->x().is_unitary() &&
              this->y().is_unitary() &&
              this->z().is_unitary());
    }
    //! Get transposed matrix
    Eigen::Matrix<real_type, 3, 3> transpose(void)
    {
      return this->_data.transpose();
    }

    //! Transpose matrix
    void transpose(void) const
    {
      this->_data = this->_data.transpose();
    }

    //! Get inverse rotation3 matrix (othonormality must be checked manually!)
    Eigen::Matrix<real_type, 3, 3> inverse(void)
    {
      return this->_data.transpose();
    }

    //! Inverse rotation3 matrix (othonormality must be checked manually!)
    void inverse(void) const
    {
      this->_data = this->_data.transpose();
    }

    //! Perform rotation3 on x-axis
    void rotate_x(
        const real_type &input //!< Input angle [rad]
    )
    {
      this->_data = this->_data * acme::rotation3_x(input);
    }

    //! Perform rotation3 on y-axis
    void rotate_y(
        const real_type &input //!< Input angle [rad]
    )
    {
      this->_data = this->_data * acme::rotation3_y(input);
    }

    //! Perform rotation3 on z-axis
    void rotate_z(
        const real_type &input //!< Input angle [rad]
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