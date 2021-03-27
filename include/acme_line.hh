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
/// file: acme_line.hh
///

#ifndef INCLUDE_ACME_LINE
#define INCLUDE_ACME_LINE

#include "acme.hh"
#include "acme_math.hh"
#include "acme_frame.hh"

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
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<line const> ptr; //!< Shared pointer to line
#else
    typedef line const *ptr; //!< Pointer to line
#endif

    typedef std::vector<ptr> ptrVec; //!< Vector of pointers to line

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
        real_type ox, //<! Input x origin value
        real_type oy, //<! Input y origin value
        real_type oz, //<! Input z origin value
        real_type dx, //<! Input x direction value
        real_type dy, //<! Input y direction value
        real_type dz  //<! Input z direction value
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

    //! Tranform line from frameA to frameB
    line transform(
        frame const &frameA, //!< Actual reference coordinate system
        frame const &frameB  //!< Future reference coordinate system
    ) const;

    //! Reverse direction
    void reverse(void);

    //! Get reversed line
    line reversed(void) const;

    // Check whether the point is inside the line
    bool is_inside(
        vec3 const &point //!< Input
    ) const;

  }; // class line

  static line const NaN_line = line(acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number line type
  static line line_goat = line(NaN_line);                            //!< Scapegoat line type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_line.hh
///