///
/// file: acme_line.hh
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
    vector _origin;    //!< Origin (point)
    vector _direction; //!< Direction (vector)

  public:
    //! Class destructor
    ~line() {}

    //! Class constructor
    line() {}

    //! Copy constructor
    line(const line &) = default;

    //! Class constructor for line
    line(
        const real_type &ox, //<! Input x origin value
        const real_type &oy, //<! Input y origin value
        const real_type &oz, //<! Input z origin value
        const real_type &dx, //<! Input x direction value
        const real_type &dy, //<! Input y direction value
        const real_type &dz  //<! Input z direction value
        ) : _origin(vector(ox, oy, oz)), _direction(vector(dx, dy, dz))
    {
    }

    //! Class constructor
    line(
        const vector &origin,   //!< Input origin
        const vector &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Equality operator
    line &operator=(
        const line &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_origin = input._origin;
        this->_direction = input._direction;
        return *this;
      }
    }

    //! Check if objects are (almost) equal
    bool is_equal(
        const line &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_origin, input._origin) &&
             acme::is_equal(this->_direction, input._direction);
    }

    //! Check if line is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_degenerated(this->_direction);
    }

    //! Return origin
    const vector &origin() const
    {
      return this->_origin;
    }

    //! Return direction
    const vector &direction() const
    {
      return this->_direction;
    }

    //! Set origin
    void origin(
        const vector &input //!< input vector object
    )
    {
      this->_origin = input;
    }

    //! Set direction
    void direction(
        const vector &input //!< input vector object
    )
    {
      this->_direction = input;
    }

    //! Translate by vector
    void translate(
        const vector &input //!< Input
    )
    {
      this->_origin = input + this->_origin;
    }

    //! Rotate by matrix
    void rotate(
        const matrix &input //!< Input
    )
    {
      this->_origin = input * this->_origin;
      this->_direction = input * this->_direction;
    }

    //! Reverse direction
    void reverse(void) { this->_direction = -this->_direction; }

    
  };

} // namespace acme

#endif

///
/// eof: acme_line.hh
///