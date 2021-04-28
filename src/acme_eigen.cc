/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project - Release Version 0.0.0                            *)
(*                                                                     *)
(* Copyright (c) 2020 Davide Stocco, All Rights Reserved.              *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 2-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 2-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
(*                                                                     *)
(*    Davide Stocco                                                    *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: davide.stocco@unitn.it                                   *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_eigen.cc
///

#include "acme_eigen.hh"

namespace acme
{

  /*\
   |   __  __       _   _     
   |  |  \/  | __ _| |_| |__  
   |  | |\/| |/ _` | __| '_ \ 
   |  | |  | | (_| | |_| | | |
   |  |_|  |_|\__,_|\__|_| |_|
   |                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  angleaxis
  rotate(
      real_type angle,
      vec3 const &axis)
  {
    return Eigen::AngleAxis<real_type>(angle, axis);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  angleaxis
  rotate(
      real_type angle,
      std::string const &axis)
  {
    if (axis == "X")
      return Eigen::AngleAxis<real_type>(angle, UnitX_vec3);
    else if (axis == "Y")
      return Eigen::AngleAxis<real_type>(angle, UnitY_vec3);
    else if (axis == "Z")
      return Eigen::AngleAxis<real_type>(angle, UnitZ_vec3);
    else
      ACME_ERROR("acme::rotate(): invalid axis string.")
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  angle(
      vec3 const &input0,
      vec3 const &input1)
  {
    return acme::acos(input0.dot(input1) / (input0.norm() * input1.norm()));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  eulerAngles(
      mat3 const &rotation,
      size_t i,
      size_t j,
      size_t k,
      vec3 &angles)
  {
    vec3 angles_tmp(rotation.eulerAngles(i, j, k));
    angles[i] = angles_tmp[0];
    angles[j] = angles_tmp[1];
    angles[k] = angles_tmp[2];
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

  void
  transformVector(
      vec3 &vector,
      affine const &matrix)
  {
    vector = matrix.linear() * vector;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  transformPoint(
      vec3 &point,
      affine const &matrix)
  {
    point = matrix * point;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /*\
   |   _____ _                          _   _ _ _ _   _           
   |  | ____(_) __ _  ___ _ __    _   _| |_(_) (_) |_(_) ___  ___ 
   |  |  _| | |/ _` |/ _ \ '_ \  | | | | __| | | | __| |/ _ \/ __|
   |  | |___| | (_| |  __/ | | | | |_| | |_| | | | |_| |  __/\__ \
   |  |_____|_|\__, |\___|_| |_|  \__,_|\__|_|_|_|\__|_|\___||___/
   |           |___/                                              
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  std::ostream &
  operator<<(
      std::ostream &os,
      acme::vec2 const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "[ " << obj[0] << ", " << obj[1] << " ]'";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  std::ostream &
  operator<<(
      std::ostream &os,
      acme::mat2 const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "["
       << "[ " << obj(0, 0) << ", " << obj(0, 1) << " ]"
       << "[ " << obj(1, 0) << ", " << obj(1, 1) << " ]"
       << "]";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  std::ostream &
  operator<<(
      std::ostream &os,
      acme::vec3 const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "[ " << obj[0] << ", " << obj[1] << ", " << obj[2] << " ]'";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  std::ostream &
  operator<<(
      std::ostream &os,
      acme::mat3 const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "["
       << "[ " << obj(0, 0) << ", " << obj(0, 1) << ", " << obj(0, 2) << " ]"
       << "[ " << obj(1, 0) << ", " << obj(1, 1) << ", " << obj(1, 2) << " ]"
       << "[ " << obj(2, 0) << ", " << obj(2, 1) << ", " << obj(2, 2) << " ]"
       << "]";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  std::ostream &
  operator<<(
      std::ostream &os,
      acme::vec4 const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "[ " << obj[0] << ", " << obj[1] << ", " << obj[2] << ", " << obj[3] << " ]'";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  std::ostream &
  operator<<(
      std::ostream &os,
      acme::mat4 const &obj)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "["
       << "[ " << obj(0, 0) << ", " << obj(0, 1) << ", " << obj(0, 2) << ", " << obj(0, 3) << " ]"
       << "[ " << obj(1, 0) << ", " << obj(1, 1) << ", " << obj(1, 2) << ", " << obj(1, 3) << " ]"
       << "[ " << obj(2, 0) << ", " << obj(2, 1) << ", " << obj(2, 2) << ", " << obj(2, 3) << " ]"
       << "[ " << obj(3, 0) << ", " << obj(3, 1) << ", " << obj(3, 2) << ", " << obj(3, 3) << " ]"
       << "]";
    return os;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_eigen.cc
///