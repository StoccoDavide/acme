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
/// file: acme_vector_point.hh
///

#ifndef INCLUDE_ACME_VECTOR_POINT
#define INCLUDE_ACME_VECTOR_POINT

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "acme.hh"
#include "acme_entity.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |  __     __        _             
   |  \ \   / /__  ___| |_ ___  _ __ 
   |   \ \ / / _ \/ __| __/ _ \| '__|
   |    \ V /  __/ (__| || (_) | |   
   |     \_/ \___|\___|\__\___/|_|   
   |                                 
  \*/

  //! Vector class container
  /**
   * Specialization of Eigen::Matrix class
   */
  template <typename T, int rows>
  class Vector : public Eigen::Matrix<T, rows, 1>, public entity
  {
public:
    using Eigen::Matrix<T, rows, 1>::Matrix;

    // This constructor allows you to construct matrix from Eigen expressions
    template <typename derived>
    Vector(Eigen::MatrixBase<derived> const &other)
        : Eigen::Matrix<T, rows, 1>(other)
    {
    }

    // This method allows you to assign Eigen expressions to matrix
    template <typename derived>
    Vector &operator=(
        Eigen::MatrixBase<derived> const &other //!< Matrix
    )
    {
      this->Eigen::Matrix<T, rows, 1>::operator=(other);
      return *this;
    }

    //! Return object hierarchical degree
    integer degree(void) const override { return 1; }

    //! Return object type as string
    std::string type(void) const override { return "vector"; }

    //! Check whether the object is no entity
    bool isNone(void) const override { return false; }

    //! Check whether the object is a vector
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
    bool isBox(void) const override { return false; }

  }; // class Vector

  /*\
   |                   _             
   |   __   _____  ___| |_ ___  _ __ 
   |   \ \ / / _ \/ __| __/ _ \| '__|
   |    \ V /  __/ (__| || (_) | |   
   |     \_/ \___|\___|\__\___/|_|   
   |                                 
  \*/

  typedef acme::Vector<real, 3> vector;                        //!< Vector type (column vector)
  typedef Eigen::Matrix<vector, Eigen::Dynamic, 1> vec_vector; //!< Nx1 vector of 3D vector type
  typedef Eigen::Matrix<vector, Eigen::Dynamic, 1> vec_vector; //!< NxN matrix of 3D vector type

  static vector const NaN_vector = vector(NaN_vec3);     //!< Not-a-Number vector type
  static vector vector_goat = vector(NaN_vec3);          //!< Scapegoat vector type (throwaway non-const object)
  static vector const Zeros_vector = vector(Zeros_vec3); //!< Zeros vector type
  static vector const Ones_vector = vector(Ones_vec3);   //!< Ones vector type

  /*\
   |               _       _   
   |   _ __   ___ (_)_ __ | |_ 
   |  | '_ \ / _ \| | '_ \| __|
   |  | |_) | (_) | | | | | |_ 
   |  | .__/ \___/|_|_| |_|\__|
   |  |_|                      
  \*/

  typedef acme::Vector<real, 3> point;                       //!< Point type (column vector)
  typedef Eigen::Matrix<point, Eigen::Dynamic, 1> vec_point; //!< Nx1 vector of 3D point type
  typedef Eigen::Matrix<point, Eigen::Dynamic, 1> vec_point; //!< NxN matrix of 3D point type

  static point const NaN_point = point(NaN_vec3);     //!< Not-a-Number point type
  static point point_goat = point(NaN_vec3);          //!< Scapegoat point type (throwaway non-const object)
  static point const Zeros_point = point(Zeros_vec3); //!< Zeros point type
  static point const Ones_point = point(Ones_vec3);   //!< Ones point type

  /*\
   |   _____                     __                      
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
   |                                                     
  \*/

  //! Transform VECTOR with affine transformation matrix
  void
  transformVector(
      vector &vector,      //!< Input VECTOR
      affine const &matrix //!<4x4 transformation matrix
  );

  //! Transform POINT with affine transformation matrix
  void
  transformPoint(
      point &point,        //!< Input POINT
      affine const &matrix //!<4x4 transformation matrix
  );

} // namespace acme

#endif

///
/// eof: acme_vector_point.hh
///