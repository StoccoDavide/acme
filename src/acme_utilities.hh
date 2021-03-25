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
/// file: acme_utilities.hh
///

#ifndef INCLUDE_ACME_UTILTIES
#define INCLUDE_ACME_UTILTIES

#include "acme.hh"

#include "acme_ray.hh"
#include "acme_line.hh"
#include "acme_plane.hh"
#include "acme_segment.hh"
#include "acme_box.hh"
#include "acme_triangle.hh"
#include "acme_circle.hh"

#include "acme_intersect.hh"

namespace acme
{
  /*\
   |         _   _ _ _ _   _           
   |   _   _| |_(_) (_) |_(_) ___  ___ 
   |  | | | | __| | | | __| |/ _ \/ __|
   |  | |_| | |_| | | | |_| |  __/\__ \
   |   \__,_|\__|_|_|_|\__|_|\___||___/
   |                                   
  \*/

  //!< Stream out operator for vec3 object
  ostream_type &operator<<(
      ostream_type &os, //!< Output stream
      vec3 const &obj   //!< Vector object
  );

  //!< Stream out operator for line object
  ostream_type &operator<<(
      ostream_type &os, //!< Output stream
      line const &obj   //!< Line object
  );

  //!< Stream out operator for ray object
  ostream_type &operator<<(
      ostream_type &os, //!< Output stream
      ray const &obj    //!< Ray object
  );

  //!< Stream out operator
  ostream_type &operator<<(
      ostream_type &os, //!< Output stream
      plane const &obj  //!< Plane object
  );

  //!< Stream out operator for segment object
  ostream_type &operator<<(
      ostream_type &os,  //!< Output stream
      segment const &obj //!< Segment object
  );

  //!< Stream out operator for box object
  ostream_type &operator<<(
      ostream_type &os, //!< Output stream
      box const &obj    //!< Box object
  );

  //!< Stream out operator for triangle object
  ostream_type &operator<<(
      ostream_type &os,   //!< Output stream
      triangle const &obj //!< Triangle object
  );

  ostream_type &operator<<(
      ostream_type &os, //!< Output stream
      circle const &obj //!< Object
  );

  ostream_type &operator<<(
      ostream_type &os, //!< Output stream
      frame const &obj  //!< Object
  );

} // namespace acme

#endif

///
/// eof: acme_utilities.hh
///