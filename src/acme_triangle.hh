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
/// file: acme_triangle.hh
///

#ifndef INCLUDE_ACME_TRIANGLE
#define INCLUDE_ACME_TRIANGLE

#include "acme.hh"
#include "acme_math.hh"
#include "acme_box.hh"

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
  private:
  private:
    vec3 _point[3]; //!< Vertices as points

  public:
    //! Class destructor
    ~triangle() {}

    //! Copy constructor
    triangle(triangle const &) = default;

    //! Class constructor
    triangle() {}

    //! Class constructor
    triangle(
        real_type const x0, //<! Input x value of first point
        real_type const y0, //<! Input y value of first point
        real_type const z0, //<! Input z value of first point
        real_type const x1, //<! Input x value of second point
        real_type const y1, //<! Input y value of second point
        real_type const z1, //<! Input z value of second point
        real_type const x2, //<! Input x value of third point
        real_type const y2, //<! Input y value of third point
        real_type const z2  //<! Input z value of third point
    )
    {
      this->_point[0] = vec3(x0, y0, z0);
      this->_point[1] = vec3(x1, y1, z1);
      this->_point[2] = vec3(x2, y2, z2);
    }

    //! Class constructor
    triangle(
        vec3 const &point0, //!< Input object
        vec3 const &point1, //!< Input object
        vec3 const &point2  //!< Input object
    )
    {
      this->_point[0] = point0;
      this->_point[1] = point1;
      this->_point[2] = point2;
    }

    //! Equality operator
    triangle &operator=(
        triangle const &input //!< Input object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_point[0] = input._point[0];
        this->_point[1] = input._point[1];
        this->_point[2] = input._point[2];
        return *this;
      }
    }

    //! Check if objects are (almost) equal
    bool is_equal(
        triangle const &input //!< Input object
    )
        const
    {
      return acme::is_equal(this->_point[0], input._point[0]) &&
             acme::is_equal(this->_point[1], input._point[1]) &&
             acme::is_equal(this->_point[2], input._point[2]);
    }

    //! Check if triangle is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_equal((this->_point[0] - this->_point[1]).norm(), 0.0) ||
             acme::is_equal((this->_point[1] - this->_point[2]).norm(), 0.0) ||
             acme::is_equal((this->_point[2] - this->_point[0]).norm(), 0.0);
    }

    //! Get first point
    vec3 const &vertex_0(void) const { return this->_point[0]; }

    //! Set first vertex
    void vertex_0(
        vec3 const &input //!< Input object
    )
    {
      this->_point[0] = input;
    }

    //! Get second vertex
    vec3 const &vertex_1(void) const { return this->_point[1]; }

    //! Set second vertex
    void vertex_1(
        vec3 const &input //!< Input object
    )
    {
      this->_point[1] = input;
    }

    //! Get third vertex
    vec3 const &vertex_2(void) const { return this->_point[2]; }

    //! Set third vertex
    void vertex_2(
        vec3 const &input //!< Input object
    )
    {
      this->_point[2] = input;
    }

    //! Get i-th vertex
    vec3 const &vertex(
        int_type const &i //!< Intput i-th vertex
    ) const
    {
      return this->_point[i];
    }

    //! Set i-th vertex
    void vertex(
        int_type const &i, //!< Intput i-th vertex
        vec3 const &input  //!< Input
    )
    {
      this->_point[i] = input;
    }

    //! Set points
    void vertices(
        vec3 const &input0, //!< Input 0
        vec3 const &input1, //!< Input 1
        vec3 const &input2  //!< Input 2
    )
    {
      this->_point[0] = input0;
      this->_point[1] = input1;
      this->_point[2] = input2;
    }

    //! Get first edge
    segment const edge_0(void) const { return segment(this->_point[0], this->_point[1]); }

    //! Get second edge
    segment const edge_1(void) const { return segment(this->_point[1], this->_point[2]); }

    //! Get third edge
    segment const edge_2(void) const { return segment(this->_point[2], this->_point[0]); }

    //! Get face (normalized) normal
    vec3 const normal(void)
        const
    {
      return (this->_point[1] - this->_point[0]).cross(this->_point[2] - this->_point[0]).normalized();
    }

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    )
    {
      this->_point[0] = input + this->_point[0];
      this->_point[1] = input + this->_point[1];
      this->_point[2] = input + this->_point[2];
    }

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    )
    {
      this->_point[0] = input * this->_point[0];
      this->_point[1] = input * this->_point[1];
      this->_point[2] = input * this->_point[2];
    }

    //! Swap triangle points
    void swap(
        int_type const i, //!< Input i-th vertex
        int_type const j  //!< Input j-th vertex
    )
    {
      vec3 tmp_point_i(this->_point[i]);
      vec3 tmp_point_j(this->_point[j]);
      this->_point[i] = tmp_point_j;
      this->_point[j] = tmp_point_i;
    }

    //! Get minimum bounding box
    void min_box(
        box &input //!< Input
    )
    {
      input.x_min(acme::min(this->_point[0].x(), this->_point[1].x(), this->_point[2].x()));
      input.y_min(acme::min(this->_point[0].y(), this->_point[1].y(), this->_point[2].y()));
      input.z_min(acme::min(this->_point[0].z(), this->_point[1].z(), this->_point[2].z()));
      input.x_max(acme::max(this->_point[0].x(), this->_point[1].x(), this->_point[2].x()));
      input.y_max(acme::max(this->_point[0].y(), this->_point[1].y(), this->_point[2].y()));
      input.z_max(acme::max(this->_point[0].z(), this->_point[1].z(), this->_point[2].z()));
    }

    //! Calculate perimeter length
    real_type perimeter(void) const
    {
      return (this->_point[0] - this->_point[1]).norm() +
             (this->_point[1] - this->_point[2]).norm() +
             (this->_point[2] - this->_point[0]).norm();
    }

    //! Calculate area
    real_type area(void) const
    {
      return 0.5 * ((this->_point[1] - this->_point[0]).cross(this->_point[2] - this->_point[0])).norm();
    }

    //! Check if a point lays inside the triangle
    bool is_inside(
        vec3 const &point //!< Input
    )
    {
      real_type u, v, w;
      this->barycentric(point, u, v, w);
      if ((u >= 0.0 && u <= 1.0) &&
          (v >= 0.0 && v <= 1.0) &&
          (w >= 0.0 && w <= 1.0))
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    // Compute barycentric coordinates (u,v,w) for point
    void barycentric(
        vec3 const &point, //!< Input
        real_type &u,      //!< Output barycentric coordinate u
        real_type &v,      //!< Output barycentric coordinate v
        real_type &w       //!< Output barycentric coordinate w
    )
        const
    {
      vec3 v0(this->_point[1] - this->_point[0]);
      vec3 v1(this->_point[2] - this->_point[0]);
      vec3 v2(point - this->_point[0]);
      real_type d00 = v0.dot(v0);
      real_type d01 = v0.dot(v1);
      real_type d11 = v1.dot(v1);
      real_type d20 = v2.dot(v0);
      real_type d21 = v2.dot(v1);
      real_type denom = d00 * d11 - d01 * d01;
      v = (d11 * d20 - d01 * d21) / denom;
      w = (d00 * d21 - d01 * d20) / denom;
      u = 1.0 - v - w;
    }

  }; // class triangle

} // namespace acme

#endif

///
/// eof: acme_triangle.hh
///
