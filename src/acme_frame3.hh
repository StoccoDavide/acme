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

#include "acme.hh"
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
  class frame3
  {
  private:
    vector3 _origin;
    matrix3 _rotation;

  public:
    //! Class destructor
    ~frame3() {}

    //! Copy constructor
    frame3(const frame3 &) = default;

    //! Class constructor
    frame3() { this->clear(); }

    //! Class constructor
    frame3(
        const vector3 &origin,    //!< Input origin
        const matrix3 &rotation //!< Input rotation
        ) : _origin(origin), _rotation(rotation)
    {
    }

  public:
    //! Clear data
    void clear()
    {
      this->_origin = vector3::Zero();
      this->_rotation = matrix3::Zero();
    }

    //! Equality operator
    frame3 &operator=(
        const frame3 &input //!< Input object
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

    //! Check if objects are (almost) equal
    bool is_equal(
        const frame3 &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_origin, input._origin) &&
             acme::is_equal(this->_rotation, input._rotation);
    }

    //! Get x vector
    const vector3 x(void) const { return this->_rotation.col(0); }

    //! Get y vector
    const vector3 y(void) const { return this->_rotation.col(1); }

    //! Get z vector
    const vector3 z(void) const { return this->_rotation.col(2); }

    //! Set x vector
    void x(
        const vector3 &input //!< Input object
    )
    {
      this->_rotation.col(0) = input;
    }

    //! Set y vector
    void y(
        const vector3 &input //!< Input object
    )
    {
      this->_rotation.col(1) = input;
    }

    //! Set z vector
    void z(
        const vector3 &input //!< Input object
    )
    {
      this->_rotation.col(2) = input;
    }

    //! Get rotation
    const matrix3 &rotation(void) const { return this->_rotation; }

    //! Set rotation
    void rotation(
        matrix3 &input //!< Input
    )
    {
      this->_rotation = input;
    }

    //! Get origin
    const vector3 origin(void) const { return this->_origin; }

    //! Set rotation
    void origin(
        vector3 &input //!< Input
    )
    {
      this->_origin = input;
    }

    //! Check if rotation matrix is othonormal
    bool is_ortonormal(void) const
    {
      return acme::is_ortonormal(this->_rotation);
    }

    //! Perform rotation on x-axis
    void rotate_x(
        const real_type &input //!< Input angle [rad]
    )
    {
      this->_rotation * acme::rotate_x(input);
    }

    //! Perform rotation on y-axis
    void rotate_y(
        const real_type &input //!< Input angle [rad]
    )
    {
      this->_rotation * acme::rotate_y(input);
    }

    //! Perform rotation on z-axis
    void rotate_z(
        const real_type &input //!< Input angle [rad]
    )
    {
      this->_rotation * acme::rotate_y(input);
    }

  }; // class frame3

} // namespace acme

#endif

///
/// eof: acme_frame3.hh
///