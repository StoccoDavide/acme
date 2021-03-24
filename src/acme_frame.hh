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

///
/// file: acme_frame.hh
///

#ifndef INCLUDE_ACME_frame
#define INCLUDE_ACME_frame

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
  class frame
  {
  private:
    vec3 _origin;
    mat3 _rotation;

  public:
    //! Class destructor
    ~frame() {}

    //! Copy constructor
    frame(frame const &) = default;

    //! Class constructor
    frame() { this->clear(); }

    //! Class constructor
    frame(
        vec3 const &origin,  //!< Input origin
        mat3 const &rotation //!< Input rotation
        ) : _origin(origin), _rotation(rotation)
    {
    }

  public:
    //! Clear data
    void clear()
    {
      this->_origin = NaN_vec3;
      this->_rotation = NaN_mat3;
    }

    //! Equality operator
    frame &operator=(
        frame const &input //!< Input object
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
        frame const &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_origin, input._origin) &&
             acme::is_equal(this->_rotation, input._rotation);
    }

    //! Get x vector
    vec3 const x(void) const { return this->_rotation.col(0); }

    //! Get y vector
    vec3 const y(void) const { return this->_rotation.col(1); }

    //! Get z vector
    vec3 const z(void) const { return this->_rotation.col(2); }

    //! Set x vector
    void x(
        vec3 const &input //!< Input object
    )
    {
      this->_rotation.col(0) = input;
    }

    //! Set y vector
    void y(
        vec3 const &input //!< Input object
    )
    {
      this->_rotation.col(1) = input;
    }

    //! Set z vector
    void z(
        vec3 const &input //!< Input object
    )
    {
      this->_rotation.col(2) = input;
    }

    //! Get rotation
    mat3 const &rotation(void) const { return this->_rotation; }

    //! Set rotation
    void rotation(
        mat3 &input //!< Input
    )
    {
      this->_rotation = input;
    }

    //! Get origin
    vec3 const origin(void) const { return this->_origin; }

    //! Set rotation
    void origin(
        vec3 &input //!< Input
    )
    {
      this->_origin = input;
    }

    //! Check if rotation mat3 is othonormal
    bool is_ortonormal(void) const
    {
      return acme::is_ortonormal(this->_rotation);
    }

    //! Perform rotation on x-axis
    void rotate_x(
        real_type const input //!< Input angle [rad]
    )
    {
      this->_rotation *acme::rotate_x(input);
    }

    //! Perform rotation on y-axis
    void rotate_y(
        real_type const input //!< Input angle [rad]
    )
    {
      this->_rotation *acme::rotate_y(input);
    }

    //! Perform rotation on z-axis
    void rotate_z(
        real_type const input //!< Input angle [rad]
    )
    {
      this->_rotation *acme::rotate_y(input);
    }

    //! Set 4x4 affine transformation matrix
    void
    affine(
        mat4 const &input //!< Input 4x4 affine transformation matrix
    )
    {
      this->_origin = input.block<3, 1>(0, 3);
      this->_rotation = input.block<3, 3>(0, 0);
    }

    //! Get 4x4 affine transformation matrix
    mat4 affine(void) const
    {
      mat4 output;
      output << this->_rotation, this->_origin, vec4(0.0, 0.0, 0.0, 1.0).transpose();
      return output;
    }

  }; // class frame

} // namespace acme

#endif

///
/// eof: acme_frame.hh
///