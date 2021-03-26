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
/// file: acme.cc
///

#include "acme.hh"

namespace acme
{

} // namespace acme

/*\
 |   _____ _                          _   _ _ _ _   _           
 |  | ____(_) __ _  ___ _ __    _   _| |_(_) (_) |_(_) ___  ___ 
 |  |  _| | |/ _` |/ _ \ '_ \  | | | | __| | | | __| |/ _ \/ __|
 |  | |___| | (_| |  __/ | | | | |_| | |_| | | | |_| |  __/\__ \
 |  |_____|_|\__, |\___|_| |_|  \__,_|\__|_|_|_|\__|_|\___||___/
 |           |___/                                              
\*/

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

std::ostream &operator<<(
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

std::ostream &operator<<(
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

std::ostream &operator<<(
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

std::ostream &operator<<(
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

std::ostream &operator<<(
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

std::ostream &operator<<(
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

///
/// eof: acme.cc
///
