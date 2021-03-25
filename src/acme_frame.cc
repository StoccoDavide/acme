/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(* Release Version 0.0.0                                               *)
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
/// file: acme_frame.cc
///

#include "acme_frame.hh"

namespace acme
{

  /*\
   |    __                          
   |   / _|_ __ __ _ _ __ ___   ___ 
   |  | |_| '__/ _` | '_ ` _ \ / _ \
   |  |  _| | | (_| | | | | | |  __/
   |  |_| |_|  \__,_|_| |_| |_|\___|
   |                                
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::clear(void)
  {
    this->_origin = acme::NaN_vec3;
    this->_rotation = acme::NaN_mat3;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  frame &frame::operator=(
      frame const &input)
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool frame::is_equal(
      frame const &input)
      const
  {
    return acme::is_equal(this->_origin, input._origin) &&
           acme::is_equal(this->_rotation, input._rotation);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const frame::x(void) const { return this->_rotation.col(0); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const frame::y(void) const { return this->_rotation.col(1); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const frame::z(void) const { return this->_rotation.col(2); }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::x(
      vec3 const &input)
  {
    this->_rotation.col(0) = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::y(
      vec3 const &input)
  {
    this->_rotation.col(1) = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::z(
      vec3 const &input)
  {
    this->_rotation.col(2) = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  mat3 const &frame::rotation(void) const { return this->_rotation; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::rotation(
      mat3 &input)
  {
    this->_rotation = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const frame::origin(void) const { return this->_origin; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::origin(
      vec3 &input)
  {
    this->_origin = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool frame::is_ortonormal(void) const
  {
    return acme::is_ortonormal(this->_rotation);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::rotate_x(
      real_type const input)
  {
    this->_rotation *acme::rotation_x(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::rotate_y(
      real_type const input)
  {
    this->_rotation *acme::rotation_y(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::rotate_z(
      real_type const input)
  {
    this->_rotation *acme::rotation_y(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void frame::affine(
      mat4 const &input)
  {
    this->_origin = input.block<3, 1>(0, 3);
    this->_rotation = input.block<3, 3>(0, 0);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  mat4 frame::affine(void) const
  {
    mat4 output;
    output << this->_rotation, this->_origin, vec4(0.0, 0.0, 0.0, 1.0).transpose();
    return output;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /*\
   |   _____                     __                      
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
   |                                                     
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 transform_vector(
      vec3 const &vector,
      frame const &frameA,
      frame const &frameB)
  {
    return frameB.rotation().transpose() * (frameA.rotation() * vector);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 transform_point(
      vec3 const &point,
      frame const &frameA,
      frame const &frameB)
  {
    return frameB.rotation().transpose() * (frameA.rotation() * point + frameA.origin() - frameB.origin());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_frame.cc
///