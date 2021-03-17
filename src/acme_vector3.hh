///
/// file: acme_vector3.hh
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

#ifndef INCLUDE_ACME_VECTOR3
#define INCLUDE_ACME_VECTOR3

#include "acme_math.hh"

namespace acme
{

  /*\
   |                 _            _____ 
   | __   _____  ___| |_ ___  _ _|___ / 
   | \ \ / / _ \/ __| __/ _ \| '__||_ \ 
   |  \ V /  __/ (__| || (_) | |  ___) |
   |   \_/ \___|\___|\__\___/|_| |____/ 
   |                                    
  \*/

  //! Vector class container
  /*!
  Class representing a vector3 in 3D space. It is constructed by
  a 3 by 1 Eigen matrix.
  */
  template <typename T = Float>
  class vector3 final
  {
  private:
    Eigen::Matrix<T, 3, 1> _data; //!< Data as Eigen 3x1 column vector3

  public:
    //! Class destructor
    ~vector3() {}

    //! Copy constructor
    vector3(const vector3<T> &) = default;

    //! Class constructor
    vector3() { this->clear(); }

    //! Class constructor
    vector3(
        const Eigen::Matrix<T, 3, 1> &data //!< Input data
        ) : _data(data)
    {
    }

    //! Class constructor
    vector3(
        const T &x, //!< Input x value
        const T &y, //!< Input y value
        const T &z  //!< Input z value
        ) : _data(Eigen::Matrix<T, 3, 1>(x, y, z))
    {
    }

    //! Class constructor
    vector3(
        const point3<T> &input //!< Input object
        ) : _data(input.data()){};

    //! Equality operator
    inline vector3<T> &operator=(
        const vector3<T> &input //!< Input object
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
        const vector3<T> &input //!< Input object
    )
        const
    {
      return this->_data == input._data;
    }

    //! Check if objects are (exactly) equal
    inline bool operator!=(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return !(this == input);
    }

    //! Check if objects are (almost) equal
    inline bool is_equal(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return acme::is_equal((this->_data - input._data).norm(), T(0.0));
    }

    //! Check if vector is degenerated
    inline bool is_degenerated(void)
        const
    {
      return acme::is_equal((this->_data).norm(), T(0.0));
    }

    //! Addition operator
    inline vector3<T> operator+(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return vector3<T>(this->_data + input._data);
    }

    //! Subtraction operator
    inline vector3<T> operator-(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return vector3<T>(this->_data - input._data);
    }

    //! Scalar product operator
    inline vector3<T> operator*(
        const T &input //!< Input scalar
    )
    {
      return vector3<T>(this->_data * input);
    }

    //! Scalar division operator
    inline vector3<T> operator/(
        const T &input //!< Input scalar
    )
    {
      return vector3<T>(this->_data / input);
    }

    //! Clear data
    void clear()
    {
      for (std::size_t i = 0; i < 3; ++i)
        this->_data[i] = T(0.0);
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

    //! Convert to point
    inline const point3<T> toPoint3(void)
    {
      return point3<T>(this);
    }

    //! Get x coordinate
    inline const T &x(void) const { return this->_data.x(); }

    //! Get y coordinate
    inline const T &y(void) const { return this->_data.y(); }

    //! Get z coordinate
    inline const T &z(void) const { return this->_data.z(); }

    //! Get data
    inline const Eigen::Matrix<T, 3, 1> &data(void) const { return this->_data; }

    //! Set x coordinate
    inline void x(
        const T &input //!< Input value
    )
    {
      this->_data[0] = input;
    }

    //! Set y coordinate
    inline void y(
        const T &input //!< Input value
    )
    {
      this->_data[1] = input;
    }

    //! Set z coordinate
    inline void z(
        const T &input //!< Input value
    )
    {
      this->_data[2] = input;
    }

    //! Set data
    inline void data(
        const Eigen::Matrix<T, 3, 1> &data //!< Input data
    )
    {
      this->_data = data;
    }

    //! Normalize object
    inline void normalize()
    {
      this->_data.normalize();
    }

    //! Return object norm
    inline const T &norm()
    {
      return this->_data.norm();
    }

    //! Return normalized vector
    inline const vector3<T> normalized()
        const
    {
      return this->_data.normalized();
    }

    //! Addition function
    inline void add(
        const vector3<T> &input //!< Input object
    )
    {
      this->data(this->_data + input._data);
    }

    //! Subtraction function
    inline void subtract(
        const vector3<T> &input //!< Input object
    )
    {
      this->data(this->_data - input._data);
    }

    //! Dot product function
    inline const vector3<T> dot(
        const vector3<T> &input //!< Input object
    )
    {
      return vector3<T>(this->_data->dot(input._data));
    }

    //! Cross product function
    inline const vector3<T> cross(
        const vector3<T> &input //!< Input object
    )
    {
      return vector3<T>(this->_data->cross(input._data));
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return acme::is_equal((this->normalized().cross(input.normalized())).norm(), 0.0);
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const line3<T> &input //!< Input object
    )
        const
    {
      return this->is_parallel(input.direction());
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return this->is_parallel(input.direction());
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return this->is_orthogonal(input.normal());
    }

    //! Check if objects are parallel
    inline bool is_parallel(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return this->is_parallel(input.toVector());
    }

    //! Check if objects are orthogonal
    inline bool is_orthogonal(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return acme::is_equal(abs(this->dot(input)) / (this->norm() * input.norm()), 0.0);
    }

    //! Check if objects are parallel
    inline bool is_orthogonal(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return this->is_orthogonal(input.direction());
    }

    //! Check if objects are parallel
    inline bool is_orthogonal(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return this->is_parallel(input.normal());
    }

    //! Check if objects are parallel
    inline bool is_orthogonal(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return this->is_orthogonal(input.toVector());
    }

    //! Check if vector has unitary norm
    inline bool is_unitary(void) const
    {
      return is_equal(this->norm() - 1.0, 0.0);
    }

    //! Get an arbitrary vector orthogonal to the current vector
    inline const vector3<T> &orthogonalVector(void)
        const
    {
      if (abs(this->x()) <= abs(this->y()) && abs(this->x()) <= abs(this->z()))
      {
        return new vector3<T>(0, this->z(), -this->y());
      }
      else if (abs(this->y()) <= abs(this->x()) && abs(this->y()) <= abs(this->z()))
      {
        return new vector3<T>(this->z(), 0, -this->x());
      }
      else
      {
        return new vector3<T>(this->y(), -this->x(), 0);
      }
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const vector3<T> &input //!< Input object
    )
        const
    {
      return acme::acos(this->_data.dot(input) / (this->norm() * input.norm()));
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const line3<T> &input //!< Input object
    )
        const
    {
      return this->angle(input.direction());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const ray3<T> &input //!< Input object
    )
        const
    {
      return this->angle(input.direction());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const plane3<T> &input //!< Input object
    )
        const
    {
      return this->angle(input.direction()) - PI / 2.0;
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const segment3<T> &input //!< Input object
    )
        const
    {
      return this->angle(input.toVector());
    }

    //! Tranform vector from frameA to frameB
    inline const vector3<T> &transform(
        const coord3<T> &frameA, //!< Actual reference coordinate system
        const coord3<T> &frameB  //!< Future reference coordinate system
    )
        const
    {
      return this->angle(input.toVector());
    }

  }; // class vector3

} // namespace acme

#endif

///
/// eof: acme_vector3.hh
///