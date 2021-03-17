///
/// file: acme_frame3.hh
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

#ifndef INCLUDE_ACME_FRAME3
#define INCLUDE_ACME_FRAME3

#include "acme_math.hh"

namespace acme
{

  /*\
   |    __                          _____ 
   |   / _|_ __ __ _ _ __ ___   ___|___ / 
   |  | |_| '__/ _` | '_ ` _ \ / _ \ |_ \ 
   |  |  _| | | (_| | | | | | |  __/___) |
   |  |_| |_|  \__,_|_| |_| |_|\___|____/ 
   |                                      
  \*/

  //! Rotation class container
  /*!
  Class representing a frame in 3D space. It is constructed by
  a origin and a rotation matrix.
  */
  template <typename T = Float>
  class frame3 final
  {
  private:
    point3<T> _origin;
    rotation3<T> _rotation;

  public:
    //! Class destructor
    ~frame3() {}

    //! Copy constructor
    frame3(const frame3<T> &) = default;

    //! Class constructor
    frame3() { this->clear(); }

    //! Class constructor
    frame3(
        const Eigen::Matrix<T, 3, 1> &origin,  //!< Input origin
        const Eigen::Matrix<T, 3, 3> &rotation //!< Input rotation
        ) : _origin(origin), _rotation(rotation)
    {
    }

    //! Class constructor
    frame3(
        const point3<T> &origin,     //!< Input origin
        const rotation3<T> &rotation //!< Input rotation
        ) : _origin(origin), _rotation(rotation)
    {
    }

  public:
    //! Clear data
    void clear()
    {
      this->_origin.clear();
      this->_rotation.clear()
    }

    //! Equality operator
    inline frame3<T> &operator=(
        const frame3<T> &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_origin = input._origin;
        this->_rotation = input._rotation;
        return *this;
      }
    }

    //! Check if objects are (exactly) equal
    inline bool operator==(
        const frame3<T> &input //!< Input object
    )
    {
      return this->_origin == input._origin && this->_rotation == input._rotation;
    }

    //! Check if objects are (exactly) equal
    inline bool operator!=(
        const frame3<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if objects are (almost) equal
    inline bool is_equal(
        const frame3<T> &input //!< Input object
    )
        const
    {
      return this->_origin.is_equal(input._origin) && this->_rotation.is_equal(input._rotation);
    }

    //! Get x vector
    inline const T &x(void) const { return this->_rotation.x(); }

    //! Get y vector
    inline const T &y(void) const { return this->_rotation.y(); }

    //! Get z vector
    inline const T &z(void) const { return this->_rotation.z(); }

    //! Get data
    inline const Eigen::Matrix<T, 3, 3> &data(void) const { return this->_data; }

    //! Set x vector
    inline void x(
        const vector3<T> &input //!< Input object
    )
    {
      this->_rotation.x() = input.data();
    }

    //! Set y vector
    inline void y(
        const vector3<T> &input //!< Input object
    )
    {
      this->_data.y() = input.data();
    }

    //! Set z vector
    inline void z(
        const vector3<T> &input //!< Input object
    )
    {
      this->_data.z() = input.data();
    }

    //! Get rotation
    inline rotation3<T> &rotation(void) const
    {
      return this->_rotation;
    }

    //! Get rotation
    inline Eigen::Matrix<T, 3, 3> &rotationEigen(void) const
    {
      return this->_rotation.data();
    }

    //! Set rotation
    inline void rotationEigen(
        const Eigen::Matrix<T, 3, 3> &data //!< Input data
    )
    {
      this->_rotation.data(data);
    }

    //! Get origin
    inline point3<T> &origin(void) const
    {
      return this->_origin;
    }

    //! Get origin
    inline Eigen::Matrix<T, 3, 1> &originEigen(void) const
    {
      return this->_origin.data();
    }

    //! Set origin
    inline void originEigen(
        const Eigen::Matrix<T, 3, 1> &data //!< Input data
    )
    {
      this->_origin.data(data);
    }

    //! Check if rotation matrix is othonormal
    inline const bool is_othonormal(void) const
    {
      return this->_rotation.is_othonormal();
    }

    //! Get inverse rotation matrix (othonormality must be checked manually!)
    inline Eigen::Matrix<T, 4, 4> inverse(void)
    {
      return this->_rotation.transpose();
    }

    //! Inverse rotation matrix (othonormality must be checked manually!)
    inline void inverse(void) const
    {
      this->_origin = -this->_rotation.transpose() * this->_origin;
      this->_rotation = this->_rotation.transpose();
    }

    //! Perform rotation on x-axis
    inline void rotate_x(
        const T &input //!< Input angle [rad]
    )
    {
      this->_rotation = this->_rotate_x(input);
    }

    //! Perform rotation on y-axis
    inline void rotate_y(
        const T &input //!< Input angle [rad]
    )
    {
      this->_rotation = this->_rotate_y(input);
    }

    //! Perform rotation on z-axis
    inline void rotate_z(
        const T &input //!< Input angle [rad]
    )
    {
      this->_rotation = this->_rotate_y(input);
    }

    //! Perform translation by vector
    inline void translate(
        const vector3<T> &input //!< Input object
    )
    {
      this->_origin = this->_origin.translate(input);
    }

  }; // class frame3

} // namespace acme

#endif

///
/// eof: acme_frame3.hh
///