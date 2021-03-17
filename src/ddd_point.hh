///
/// file: ddd_point.hh
///

/*
(***********************************************************************)
(*                                                                     *)
(* The ddd computational geometry library                              *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The ddd computational geometry library and its components are       *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the ddd computational geometry library and its      *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

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
  class point final
  {
  private:
    Eigen::Matrix<T, 3, 1> _data; //!< Data as Eigen 3x1 column vector

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
        ) : _data(data)
    {
    }

    //! Class constructor
    point(
        const T &x, //!< Input x point value
        const T &y, //!< Input y point value
        const T &z  //!< Input z point value
        ) : _data(Eigen::Matrix<T, 3, 1>(x, y, z))
    {
    }

    //! Class constructor
    point(
        const vector<T> &input //!< Input point
        ) : _data(input.data()){};

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

    //! Convert to vector
    inline const vector<T> toVector(void)
    {
      return vector<T>(this);
    }

    //! Get x coordinate
    inline const T &x(void) const { return this->_data[0]; }

    //! Get y coordinate
    inline const T &y(void) const { return this->_data[1]; }

    //! Get z coordinate
    inline const T &z(void) const { return this->_data[2]; }

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
        return (this->_data - input._data).norm();
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
        return (this->_data - input._data).squaredNorm();
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