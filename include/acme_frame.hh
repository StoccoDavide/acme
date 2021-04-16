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

  //! Reference frame class container
  /**!
   *Class representing a frame in 3D space. It is constructed by
   *a origin and a rotation matrix.
  */
  class frame
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<frame const> ptr; //!< Shared pointer to frame
#else
    typedef frame const *ptr; //!< Pointer to frame
#endif

    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to frame objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to frame objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to frame objects

  private:
    vec3 _origin;   //!< Frame origin point
    mat3 _rotation; //!< Frame rotation matrix

  public:
    //! Frame class destructor
    ~frame() {}

    //! Frame copy constructor
    frame(frame const &) = default;

    //! Frame class constructor
    frame()
    {
      this->clear();
    }

    //! Frame class constructor
    frame(
        vec3 const &origin,  //!< Input frame origin point
        mat3 const &rotation //!< Input frame rotation matrix
        ) : _origin(origin),
            _rotation(rotation)
    {
    }

    //! Frame class constructor
    frame(
        mat4 const &affine //!< 4x4 affine transformation matrix
        ) : _origin(affine.block<3, 1>(0, 3)),
            _rotation(affine.block<3, 3>(0, 0))
    {
    }

    //! Clear frame origin point and rotation matrix (set to Not-a-Number)
    void
    clear(void);

    //! Equality operator
    frame &
    operator=(
        frame const &input //!< Input frame object
    );

    //! Check if frames are (almost) equal
    bool
    is_equal(
        frame const &input //!< Input frame object
    ) const;

    //! Get x direction vector
    vec3
    x(void) const;

    //! Get y direction vector
    vec3
    y(void) const;

    //! Get z direction vector
    vec3
    z(void) const;

    //! Set x direction vector
    void
    x(
        vec3 const &input //!< Input x direction vector
    );

    //! Set y direction vector
    void
    y(
        vec3 const &input //!< Input y direction vector
    );

    //! Set z direction vector
    void
    z(
        vec3 const &input //!< Input z direction vector
    );

    //! Get rotation matrix
    mat3 const &
    rotation(void) const;

    //! Set rotation matrix
    void
    rotation(
        mat3 const &input //!< Input
    );

    //! Get frame origin point
    vec3 const &
    origin(void) const;

    //! Set frame origin point
    void
    origin(
        vec3 const &input //!< Input
    );

    //! Check if rotation matrix is othonormal
    bool
    is_ortonormal(void) const;

    //! Perform rotation on x axis
    void
    rotate_x(
        real_type input //!< Input angle [rad]
    );

    //! Perform rotation on y axis
    void
    rotate_y(
        real_type input //!< Input angle [rad]
    );

    //! Perform rotation on z axis
    void
    rotate_z(
        real_type input //!< Input angle [rad]
    );

    //! Set 4x4 affine transformation matrix
    void
    affine(
        mat4 const &input //!< Input 4x4 affine transformation matrix
    );

    //! Get 4x4 affine transformation matrix
    mat4
    affine(void) const;

    //! Get current Euler angle [rad] for x axis \n
    //! WARNING: Factor as [Rz][Rx][Ry]!
    // https://www.geometrictools.com/Documentation/EulerAngles.pdf
    real_type
    euler_angle_x(void) const;

    //! Get current Euler angle [rad] for y axis \n
    //! WARNING: Factor as [Rz][Rx][Ry]!
    // https://www.geometrictools.com/Documentation/EulerAngles.pdf
    real_type
    euler_angle_y(void) const;

    //! Get current Euler angle [rad] for z axis \n
    //! WARNING: Factor as [Rz][Rx][Ry]!
    // https://www.geometrictools.com/Documentation/EulerAngles.pdf
    real_type
    euler_angle_z(void) const;

  }; // class frame

  /*\
   |   _____                     __                      
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
   |                                                     
  \*/

  //! Tranform VECTOR from two coordinate frames
  vec3
  transform_vector(
      vec3 const &vector,      //!< Input vector
      frame const &from_frame, //!< Actual reference coordinate system
      frame const &to_frame    //!< Future reference coordinate system
  );

  //! Tranform POINT from two coordinate frames
  vec3
  transform_point(
      vec3 const &point,       //!< Input point
      frame const &from_frame, //!< Actual reference coordinate system
      frame const &to_frame    //!< Future reference coordinate system
  );

  static frame const ground = frame(acme::Zeros_vec3, acme::Identity_mat3); //!< Ground reference frame
  static frame const NaN_frame = frame(acme::NaN_vec3, acme::NaN_mat3);     //!< Not-a-Number frame type
  static frame frame_goat = frame(NaN_frame);                               //!< Scapegoat frame type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_frame.hh
///