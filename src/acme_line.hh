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
/// file: acme_line.hh
///

#ifndef INCLUDE_ACME_LINE
#define INCLUDE_ACME_LINE

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |   _ _            
   |  | (_)_ __   ___ 
   |  | | | '_ \ / _ \
   |  | | | | | |  __/
   |  |_|_|_| |_|\___|
   |                  
  \*/

  //! Line class container
  /*!
  Infinite line in 3D space and defined by any point lying on the line and a direction
  vector.
  */
  class line
  {
  private:
    vec3 _origin;    //!< Origin (point)
    vec3 _direction; //!< Direction (vector)

  public:
    //! Class destructor
    ~line() {}

    //! Class constructor
    line() {}

    //! Copy constructor
    line(line const &) = default;

    //! Class constructor for line
    line(
        real_type const ox, //<! Input x origin value
        real_type const oy, //<! Input y origin value
        real_type const oz, //<! Input z origin value
        real_type const dx, //<! Input x direction value
        real_type const dy, //<! Input y direction value
        real_type const dz  //<! Input z direction value
        ) : _origin(vec3(ox, oy, oz)), _direction(vec3(dx, dy, dz))
    {
    }

    //! Class constructor
    line(
        vec3 const &origin,   //!< Input origin
        vec3 const &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Equality operator
    line &operator=(
        line const &input //!< Input object
    );

    //! Check if objects are (almost) equal
    bool is_equal(
        line const &input //!< Input object
    ) const;

    //! Check if line is degenerated
    bool is_degenerated(void) const;

    //! Return origin
    vec3 const &origin() const;

    //! Return direction
    vec3 const &direction() const;

    //! Set origin
    void origin(
        vec3 const &input //!< input vec3 object
    );

    //! Set direction
    void direction(
        vec3 const &input //!< input vec3 object
    );

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    );

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    );

    //! Reverse direction
    void reverse(void);

    //! Get reversed line
    line reversed(void) const;

  }; // class line

} // namespace acme

#endif

///
/// eof: acme_line.hh
///