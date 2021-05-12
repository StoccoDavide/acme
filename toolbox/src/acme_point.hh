/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       *)
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
(*    Enrico Bertolazzi                                                *)
(*    Department of Industrial Engineering                             *)
(*    University of Trento                                             *)
(*    e-mail: enrico.bertolazzi@unitn.it                               *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_point.hh
///

#ifndef INCLUDE_ACME_POINT
#define INCLUDE_ACME_POINT

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "acme.hh"
#include "acme_entity.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |   ____       _       _  __  ___   
   |  |  _ \ ___ (_)_ __ | |_\ \/ / |_ 
   |  | |_) / _ \| | '_ \| __|\  /| __|
   |  |  __/ (_) | | | | | |_ /  \| |_ 
   |  |_|   \___/|_|_| |_|\__/_/\_\\__|
   |                                   
  \*/

  //! PointXt class container
  /**
   * Specialization of Eigen::Matrix class
   */
  template <typename t>
  class Point3t : public Eigen::Matrix<t, 3, 1>, public entity
  {
public:
    using Eigen::Matrix<t, 3, 1>::Matrix;

    // This constructor allows you to construct matrix from Eigen expressions
    template <typename derived>
    Point3t(Eigen::MatrixBase<derived> const &other)
        : Eigen::Matrix<t, 3, 1>(other)
    {
    }

    // This method allows you to assign Eigen expressions to matrix
    template <typename derived>
    Point3t &operator=(
        Eigen::MatrixBase<derived> const &other //!< Matrix
    )
    {
      this->Eigen::Matrix<t, 3, 1>::operator=(other);
      return *this;
    }

    //! Translate point by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
        ) override
    {
      *this += input;
    }

    //! Transform point with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
        ) override
    {
      *this = matrix * *this;
    }

    //! Check if entity is degenerated
    bool isDegenerated(void) const override { return false; }

    //! Return object hierarchical degree
    integer degree(void) const override { return 1; }

    //! Return object type as string
    std::string type(void) const override { return "point"; }

    //! Check whether the object is no entity
    bool isNone(void) const override { return false; }

    //! Check whether the object is a point
    bool isPoint(void) const override { return true; }

    //! Check whether the object is a line
    bool isLine(void) const override { return false; }

    //! Check whether the object is a ray
    bool isRay(void) const override { return false; }

    //! Check whether the object is a plane
    bool isPlane(void) const override { return false; }

    //! Check whether the object is a segment
    bool isSegment(void) const override { return false; }

    //! Check whether the object is a triangle
    bool isTriangle(void) const override { return false; }

    //! Check whether the object is a circle
    bool isCircle(void) const override { return false; }

    //! Check whether the object is a aabb
    bool isAabb(void) const override { return false; }

  }; // class point

  /*\
   |               _       _   
   |   _ __   ___ (_)_ __ | |_ 
   |  | '_ \ / _ \| | '_ \| __|
   |  | |_) | (_) | | | | | |_ 
   |  | .__/ \___/|_|_| |_|\__|
   |  |_|                      
  \*/

  typedef Point3t<real> point;                           //!< Point type
  static point const NaN_point = point::Constant(NaN);   //!< Not-a-Number point type
  static point const Zeros_point = point::Constant(0.0); //!< Zeros point type
  static point const Ones_point = point::Constant(1.0);  //!< Ones point type
  static point point_goat = point(NaN_point);            //!< Scapegoat point type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_point.hh
///