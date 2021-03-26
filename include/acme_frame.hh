/*
(***********************************************************************)
(*                                                                     *)
(* The ACME computational geometry library                             *)
(* Release Version 0.0.0                                               *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The ACME computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the ACME computational geometry library and its     *)
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

#ifndef INCLUDE_ACME_FRAME
#define INCLUDE_ACME_FRAME

#include "acme.hh"
#include "acme_math.hh"

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
    void clear(void);

    //! Equality operator
    frame &operator=(
        frame const &input //!< Input object
    );

    //! Check if objects are (almost) equal
    bool is_equal(
        frame const &input //!< Input object
    ) const;

    //! Get x vector
    vec3 const x(void) const;

    //! Get y vector
    vec3 const y(void) const;

    //! Get z vector
    vec3 const z(void) const;

    //! Set x vector
    void x(
        vec3 const &input //!< Input object
    );

    //! Set y vector
    void y(
        vec3 const &input //!< Input object
    );

    //! Set z vector
    void z(
        vec3 const &input //!< Input object
    );

    //! Get rotation
    mat3 const &rotation(void) const;

    //! Set rotation
    void rotation(
        mat3 &input //!< Input
    );

    //! Get origin
    vec3 const origin(void) const;

    //! Set rotation
    void origin(
        vec3 &input //!< Input
    );

    //! Check if rotation mat3 is othonormal
    bool is_ortonormal(void) const;

    //! Perform rotation on x-axis
    void rotate_x(
        real_type const input //!< Input angle [rad]
    );

    //! Perform rotation on y-axis
    void rotate_y(
        real_type const input //!< Input angle [rad]
    );

    //! Perform rotation on z-axis
    void rotate_z(
        real_type const input //!< Input angle [rad]
    );

    //! Set 4x4 affine transformation matrix
    void
    affine(
        mat4 const &input //!< Input 4x4 affine transformation matrix
    );

    //! Get 4x4 affine transformation matrix
    mat4 affine(void) const;

  }; // class frame

  /*\
   |   _____                     __                      
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
   |                                                     
  \*/

  //! Tranform VECTOR from frameA to frameB
  vec3 transform_vector(
      vec3 const &vector,  //!< Input
      frame const &frameA, //!< Actual reference coordinate system
      frame const &frameB  //!< Future reference coordinate system
  );

  //! Tranform point from frameA to frameB
  vec3 transform_point(
      vec3 const &point,   //!< Input
      frame const &frameA, //!< Actual reference coordinate system
      frame const &frameB  //!< Future reference coordinate system
  );

  static frame const NaN_frame = frame(acme::NaN_vec3, acme::NaN_mat3); //!< Not-a-Number frame type
  static frame frame_goat = frame(NaN_frame);                           //!< Scapegoat frame type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_frame.hh
///