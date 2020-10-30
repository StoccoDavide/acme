///
/// file: TireGround.hh
///

#pragma once

#include <Eigen/Dense>  // Eigen linear algebra Library
#include <chrono>       // STD Time Measurement Library
#include <cmath>        // STD math Library
#include <fstream>      // STD File I/O Library
#include <iostream>     // STD I/O Library
#include <string>       // STD String Library
#include <vector>       // STD Vector/Array Library

//! Typedefs for tire computations routine
namespace TireGround {

  typedef double real_type; //!< Real number type
  typedef int    int_type;  //!< Integer number type

  typedef Eigen::Vector2i vec2_int; //!< 2D vector type of real integer type

  typedef Eigen::Vector2d vec2; //!< 2D vector type of real number type
  typedef Eigen::Vector3d vec3; //!< 3D vector type of real number type
  typedef Eigen::Vector4d vec4; //!< 4D vector type of real number type
  typedef Eigen::Matrix3d mat3; //!< 3x3 matrix type of real number type
  typedef Eigen::Matrix4d mat4; //!< 4x4 matrix type of real number type

  typedef Eigen::Matrix<real_type,1,Eigen::Dynamic>              row_vecN; //!< Row vector type real number type
  typedef Eigen::Matrix<real_type,Eigen::Dynamic,1>              col_vecN; //!< Column vector type real number type
  typedef Eigen::Matrix<real_type,Eigen::Dynamic,Eigen::Dynamic> matN;     //!< Matrix type of real number type

  typedef Eigen::Matrix<vec2,1,Eigen::Dynamic>              row_vec2; //!< Row vector type of 2D vector
  typedef Eigen::Matrix<vec2,Eigen::Dynamic,1>              col_vec2; //!< Column vector type of 2D vector
  typedef Eigen::Matrix<vec2,Eigen::Dynamic,Eigen::Dynamic> mat_vec2; //!< Matrix type of 2D vector

  typedef Eigen::Matrix<vec3,1,Eigen::Dynamic>              row_vec3; //!< Row vector type of 3D vector
  typedef Eigen::Matrix<vec3,Eigen::Dynamic,1>              col_vec3; //!< Column vector type of 3D vector
  typedef Eigen::Matrix<vec3,Eigen::Dynamic,Eigen::Dynamic> matN_vec3; //!< Matrix type of 3D vector

  typedef Eigen::Matrix<mat4,1,Eigen::Dynamic> row_mat4; //!<Matrix type of 4x4 matrix

  typedef std::basic_ostream<char> ostream_type; //!< Output stream type

  real_type const epsilon = std::numeric_limits<real_type>::epsilon(); //!< Epsilon type

  static real_type quietNaN = std::numeric_limits<real_type>::quiet_NaN(); //!< Not-a-Number type

  static vec3 vec3_NaN = vec3::Constant(quietNaN); //!< Not-a-Number 3D vector type
  static mat3 mat3_NaN = mat3::Constant(quietNaN); //!< Not-a-Number 3x3 matrix type

} // namespace TireGround

///
/// eof: TireGround.hh
///