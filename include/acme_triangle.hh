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
/// file: acme_triangle.hh
///

#ifndef INCLUDE_ACME_TRIANGLE
#define INCLUDE_ACME_TRIANGLE

#include "acme.hh"
#include "acme_math.hh"
#include "acme_box.hh"
#include "acme_segment.hh"
#include "acme_frame.hh"

namespace acme
{

  /*\
   |   _        _                   _      
   |  | |_ _ __(_) __ _ _ __   __ _| | ___ 
   |  | __| '__| |/ _` | '_ \ / _` | |/ _ \
   |  | |_| |  | | (_| | | | | (_| | |  __/
   |   \__|_|  |_|\__,_|_| |_|\__, |_|\___|
   |                          |___/        
  \*/

  //! Triangle class container
  /*!
  Triangle in 3D space. It is defined by three arbitrary points.
  */
  class triangle
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<triangle const> ptr; //!< Shared pointer to triangle
#else
    typedef triangle const *ptr; //!< Pointer to triangle
#endif

    typedef std::vector<ptr> ptrVec; //!< Vector of pointers to triangle

  private:
    vec3 _vertex[3]; //!< Vertices as points

  public:
    //! Class destructor
    ~triangle() {}

    //! Copy constructor
    triangle(triangle const &) = default;

    //! Class constructor
    triangle() {}

    //! Class constructor
    triangle(
        real_type x0, //<! Input x value of first point
        real_type y0, //<! Input y value of first point
        real_type z0, //<! Input z value of first point
        real_type x1, //<! Input x value of second point
        real_type y1, //<! Input y value of second point
        real_type z1, //<! Input z value of second point
        real_type x2, //<! Input x value of third point
        real_type y2, //<! Input y value of third point
        real_type z2  //<! Input z value of third point
    );

    //! Class constructor
    triangle(
        vec3 const &point0, //!< Input
        vec3 const &point1, //!< Input
        vec3 const &point2  //!< Input
    );

    //! Class constructor
    triangle(
        vec3 const point[3] //!< Input points
    );

    //! Equality operator
    triangle &operator=(
        triangle const &input //!< Input object
    );

    //! Check if objects are (almost) equal
    bool is_equal(
        triangle const &input //!< Input object
    ) const;

    //! Check if triangle is degenerated
    bool is_degenerated(void) const;

    //! Get first point
    vec3 const &vertex_0(void) const;

    //! Set first vertex
    void vertex_0(
        vec3 const &input //!< Input object
    );

    //! Get second vertex
    vec3 const &vertex_1(void) const;

    //! Set second vertex
    void vertex_1(
        vec3 const &input //!< Input object
    );

    //! Get third vertex
    vec3 const &vertex_2(void) const;

    //! Set third vertex
    void vertex_2(
        vec3 const &input //!< Input object
    );

    //! Get i-th vertex
    vec3 const &vertex(
        unsigned i //!< Intput i-th vertex
    ) const;

    //! Set i-th vertex
    void vertex(
        unsigned i,       //!< Intput i-th vertex
        vec3 const &input //!< Input
    );

    //! Set vertices points
    void vertices(
        vec3 const &vertex0, //!< Input 0
        vec3 const &vertex1, //!< Input 1
        vec3 const &vertex2  //!< Input 2
    );

    //! Set vertices points
    void vertices(
        vec3 const vertex[3] //!< Input
    );

    //! Get first edge
    segment const edge_0(void) const;

    //! Get second edge
    segment const edge_1(void) const;

    //! Get third edge
    segment const edge_2(void) const;

    //! Get face (normalized) normal
    vec3 const normal(void) const;

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    );

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    );

    //! Tranform triangle from frameA to frameB
    triangle transform(
        frame const &frameA, //!< Actual reference coordinate system
        frame const &frameB  //!< Future reference coordinate system
    ) const;

    //! Swap triangle points
    void swap(
        unsigned i, //!< Input i-th vertex
        unsigned j  //!< Input j-th vertex
    );

    //! Get minimum bounding box
    void min_box(
        box &input //!< Input
    ) const;

    //! Calculate perimeter length
    real_type perimeter(void) const;

    //! Calculate area
    real_type area(void) const;

    //! Check if a point lays inside the triangle
    bool is_inside(
        vec3 const &point //!< Input
    ) const;

    // Compute barycentric coordinates (u,v,w) for point
    void barycentric(
        vec3 const &point, //!< Input
        real_type &u,      //!< Output barycentric coordinate u
        real_type &v,      //!< Output barycentric coordinate v
        real_type &w       //!< Output barycentric coordinate w
    ) const;

  }; // class triangle

  static triangle const NaN_triangle = triangle(acme::NaN_vec3, acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number triangle type
  static triangle triangle_goat = triangle(NaN_triangle);                                        //!< Scapegoat triangle type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_triangle.hh
///
