/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project                                                    *)
(*                                                                     *)
(* Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *)
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
/// file: acme_eigenextend.hh
///

#ifndef INCLUDE_ACME_EIGENEXTEND
#define INCLUDE_ACME_EIGENEXTEND

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "acme.hh"
#include "acme_math.hh"
#include "acme_entity.hh"

namespace acme
{

  /*\
   |                   _        _      
   |   _ __ ___   __ _| |_ _ __(_)_  __
   |  | '_ ` _ \ / _` | __| '__| \ \/ /
   |  | | | | | | (_| | |_| |  | |>  < 
   |  |_| |_| |_|\__,_|\__|_|  |_/_/\_\
   |                                   
  \*/

  //! Matrix class container
  /**
   * Extension of Eigen::Matrix class
   */
  template <typename T, int rows, int cols>
  class matrix : public Eigen::Matrix<T, rows, cols>, public entity
  {
  public:
    using Eigen::Matrix<T, rows, cols>::Matrix;

    // This constructor allows you to construct matrix from Eigen expressions
    template <typename derived>
    matrix(Eigen::MatrixBase<derived> const &other)
        : Eigen::Matrix<T, rows, cols>(other)
    {
    }

    // This method allows you to assign Eigen expressions to matrix
    template <typename derived>
    matrix &operator=(
        Eigen::MatrixBase<derived> const &other //!< Matrix
    )
    {
      this->Eigen::Matrix<T, rows, cols>::operator=(other);
      return *this;
    }

    //! Return object type as string
    size_t type(void) const override { return 1; }

    //! Check whether the object is a point
    bool isMatrix(void) const override { return true; }

    //! Check whether the object is a vector
    bool isVector(void) const override { return false; }

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

    //! Check whether the object is a box
    bool isBox(void) const override { return false; }

  }; // class matrix

  //! Vector class container
  /**
   * Specialization of matrix class
   */
  template <typename T, int rows>
  class vector : public Eigen::Matrix<T, rows, 1>, public entity
  {
  public:
    using Eigen::Matrix<T, rows, 1>::Matrix;

    // This constructor allows you to construct matrix from Eigen expressions
    template <typename derived>
    vector(Eigen::MatrixBase<derived> const &other)
        : Eigen::Matrix<T, rows, 1>(other)
    {
    }

    // This method allows you to assign Eigen expressions to matrix
    template <typename derived>
    vector &operator=(
        Eigen::MatrixBase<derived> const &other //!< Matrix
    )
    {
      this->Eigen::Matrix<T, rows, 1>::operator=(other);
      return *this;
    }

    //! Check if vectors are parallel
    bool
    isParallel(
        vector<T, rows> const &input, //!< Input vector
        T tolerance = Epsilon         //!< Tolerance
    )
        const
    {
      return acme::isApprox(this->cross(input).norm(), real_type(0.0), tolerance);
    }

    //! Check if vectors are orthogonal
    bool
    isOrthogonal(
        vector<T, rows> const &input, //!< Input vector
        T tolerance = Epsilon         //!< Tolerance
    )
        const
    {
      return acme::isApprox(this->dot(input), real_type(0.0), tolerance);
    }

    //! Return object type as string
    size_t type(void) const override { return 2; }

    //! Check whether the object is a point
    bool isMatrix(void) const override { return false; }

    //! Check whether the object is a vector
    bool isVector(void) const override { return true; }

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

    //! Check whether the object is a box
    bool isBox(void) const override { return false; }

  }; // class matrix

  /*\
   |   _____                     _       __     
   |  |_   _|   _ _ __   ___  __| | ___ / _|___ 
   |    | || | | | '_ \ / _ \/ _` |/ _ \ |_/ __|
   |    | || |_| | |_) |  __/ (_| |  __/  _\__ \
   |    |_| \__, | .__/ \___|\__,_|\___|_| |___/
   |        |___/|_|                            
  \*/

  typedef acme::vector<real_type, Eigen::Dynamic> vecN;                 //!< Nx1 vector of real number type (column vector)
  typedef acme::matrix<real_type, Eigen::Dynamic, Eigen::Dynamic> matN; //!< NxN matrix of real number type

  typedef acme::vector<real_type, 2> vec2;                              //!< 2x1 vector type (column vector)
  typedef acme::matrix<real_type, 2, 2> mat2;                           //!< 2x2 matrix type
  typedef Eigen::Matrix<vec2, Eigen::Dynamic, 1> vec_vec2;              //!< Nx1 vector of 2x1 vector type (column vector)
  typedef Eigen::Matrix<mat2, Eigen::Dynamic, 1> vec_mat2;              //!< Nx1 vector of 2x2 matrix type
  typedef Eigen::Matrix<vec2, Eigen::Dynamic, Eigen::Dynamic> mat_vec2; //!< NxN matrix of 2x1 vector type (column vector)
  typedef Eigen::Matrix<mat2, Eigen::Dynamic, Eigen::Dynamic> mat_mat2; //!< NxN matrix of 2x2 matrix type

  typedef acme::vector<real_type, 3> vec3;                              //!< 3x1 vector type (column vector)
  typedef acme::matrix<real_type, 3, 3> mat3;                           //!< 3x3 matrix type
  typedef Eigen::Matrix<vec3, Eigen::Dynamic, 1> vec_vec3;              //!< Nx1 vector of 3x1 vector type (column vector)
  typedef Eigen::Matrix<mat3, Eigen::Dynamic, 1> vec_mat3;              //!< Nx1 vector of 3x3 matrix type
  typedef Eigen::Matrix<vec3, Eigen::Dynamic, Eigen::Dynamic> mat_vec3; //!< NxN matrix of 3x1 vector type (column vector)
  typedef Eigen::Matrix<mat3, Eigen::Dynamic, Eigen::Dynamic> mat_mat3; //!< NxN matrix of 3x3 matrix type

  typedef acme::vector<real_type, 4> vec4;                              //!< 4x1 vector type (column vector)
  typedef acme::matrix<real_type, 4, 4> mat4;                           //!< 4x4 matrix type
  typedef Eigen::Matrix<vec4, Eigen::Dynamic, 1> vec_vec4;              //!< Nx1 vector of 4x1 vector type (column vector)
  typedef Eigen::Matrix<mat4, Eigen::Dynamic, 1> vec_mat4;              //!< Nx1 vector of 4x4 matrix type
  typedef Eigen::Matrix<vec4, Eigen::Dynamic, Eigen::Dynamic> mat_vec4; //!< NxN matrix of 4x1 vector type (column vector)
  typedef Eigen::Matrix<mat4, Eigen::Dynamic, Eigen::Dynamic> mat_mat4; //!< NxN matrix of 4x4 matrix type

  typedef Eigen::DiagonalMatrix<real_type, 3> scale;                 //!< 3D scaling transformation type
  typedef Eigen::Translation<real_type, 3> translate;                //!< 3D translation transformation type
  typedef Eigen::AngleAxis<real_type> angleaxis;                     //!< 3D rotation transformation type
  typedef Eigen::Transform<real_type, 3, Eigen::Affine> affine;      //!< 3D affine transformation type
  typedef Eigen::Matrix<scale, Eigen::Dynamic, 1> vec_scale;         //!< Nx1 vector of 3D scaling transformation type
  typedef Eigen::Matrix<translate, Eigen::Dynamic, 1> vec_translate; //!< Nx1 vector of 3D translation transformation type
  typedef Eigen::Matrix<angleaxis, Eigen::Dynamic, 1> vec_angleaxis; //!< Nx1 vector of 3D rotation transformation type
  typedef Eigen::Matrix<affine, Eigen::Dynamic, 1> vec_affine;       //!< Nx1 vector of 3D affine transformation type

  /*\
   |    ____                _              _       
   |   / ___|___  _ __  ___| |_ __ _ _ __ | |_ ___ 
   |  | |   / _ \| '_ \/ __| __/ _` | '_ \| __/ __|
   |  | |__| (_) | | | \__ \ || (_| | | | | |_\__ \
   |   \____\___/|_| |_|___/\__\__,_|_| |_|\__|___/
   |                                               
  \*/

  static vec2 const UnitX_vec2 = vec2::UnitX();       //!< X axis unit vec2 type
  static vec2 const UnitY_vec2 = vec2::UnitY();       //!< Y axis unit vec2 type
  static vec2 const NaN_vec2 = vec2::Constant(NaN);   //!< Not-a-Number vec2 type
  static mat2 const NaN_mat2 = mat2::Constant(NaN);   //!< Not-a-Number mat2 type
  static vec2 const Zeros_vect2 = vec2::Zero();       //!< Zeros vec2 type
  static mat2 const Zeros_mat2 = mat2::Zero();        //!< Zeros mat2 type
  static vec2 const Ones_vec2 = vec2::Constant(1.0);  //!< Ones vec2 type
  static mat2 const Ones_mat2 = mat2::Constant(1.0);  //!< Ones mat2 type
  static mat2 const Identity_mat2 = mat2::Identity(); //!< Identity mat2 type

  static vec3 const UnitX_vec3 = vec3::UnitX();       //!< X axis unit vec3 type
  static vec3 const UnitY_vec3 = vec3::UnitY();       //!< Y axis unit vec3 type
  static vec3 const UnitZ_vec3 = vec3::UnitZ();       //!< Z axis unit vec3 type
  static vec3 const NaN_vec3 = vec3::Constant(NaN);   //!< Not-a-Number vec3 type
  static mat3 const NaN_mat3 = mat3::Constant(NaN);   //!< Not-a-Number mat3 type
  static vec3 const Zeros_vec3 = vec3::Zero();        //!< Zeros vec3 type
  static mat3 const Zeros_mat3 = mat3::Zero();        //!< Zeros mat3 type
  static vec3 const Ones_vec3 = vec3::Constant(1.0);  //!< Ones vec3 type
  static mat3 const Ones_mat3 = mat3::Constant(1.0);  //!< Ones mat3 type
  static mat3 const Identity_mat3 = mat3::Identity(); //!< Identity mat3 type

  static vec4 const UnitX_vec4 = vec4::UnitX();       //!< X axis unit vec4 type
  static vec4 const UnitY_vec4 = vec4::UnitY();       //!< Y axis unit vec4 type
  static vec4 const UnitZ_vec4 = vec4::UnitZ();       //!< Z axis unit vec4 type
  static vec4 const UnitW_vec4 = vec4::UnitW();       //!< W axis unit vec4 type
  static vec4 const NaN_vec4 = vec4::Constant(NaN);   //!< Not-a-Number vec4 type
  static mat4 const NaN_mat4 = mat4::Constant(NaN);   //!< Not-a-Number mat4 type
  static vec4 const Zeros_vec4 = vec4::Zero();        //!< Zeros vec4 type
  static mat4 const Zeros_mat4 = mat4::Zero();        //!< Zeros mat4 type
  static vec4 const Ones_vec4 = vec4::Constant(1.0);  //!< Ones vec4 type
  static mat4 const Ones_mat4 = mat4::Constant(1.0);  //!< Ones mat4 type
  static mat4 const Identity_mat4 = mat4::Identity(); //!< Identity mat4 type

  static vec2 vec2_goat = vec2(NaN_vec2); //!< Scapegoat vec2 type (throwaway non-const object)
  static vec3 vec3_goat = vec3(NaN_vec3); //!< Scapegoat vec3 type (throwaway non-const object)
  static vec4 vec4_goat = vec4(NaN_vec4); //!< Scapegoat vec4 type (throwaway non-const object)
  static mat2 mat2_goat = mat2(NaN_mat2); //!< Scapegoat mat2 type (throwaway non-const object)
  static mat3 mat3_goat = mat3(NaN_mat3); //!< Scapegoat mat3 type (throwaway non-const object)
  static mat4 mat4_goat = mat4(NaN_mat4); //!< Scapegoat mat4 type (throwaway non-const object)

  /*\
   |   __  __       _   _     
   |  |  \/  | __ _| |_| |__  
   |  | |\/| |/ _` | __| '_ \ 
   |  | |  | | (_| | |_| | | |
   |  |_|  |_|\__,_|\__|_| |_|
   |                          
  \*/

  //! Returns a rotation as a rotation angle around an arbitrary axis
  angleaxis
  rotate(
      real_type angle, //!< Input angle [rad]
      vec3 const &axis //!< Input axis
  );

  //! Returns a rotation as a rotation angle around an arbitrary axis
  angleaxis
  rotate(
      real_type angle,        //!< Input angle [rad]
      std::string const &axis //!< Input axis
  );

  //! Angle between vectors [rad]
  real_type
  angle(
      vec3 const &input0, //!< Input vector 0
      vec3 const &input1  //!< Input vector 1
  );

  //! Calculate Euler angles [rad]
  void
  eulerAngles(
      mat3 const &rotation, //!< 3x3 rotation matrix
      size_t i,             //!< Rotation index
      size_t j,             //!< Rotation index
      size_t k,             //!< Rotation index
      vec3 &angles          //!< Output euler angles [rad]
  );

  /*\
   |   _____                     __                      
   |  |_   _| __ __ _ _ __  ___ / _| ___  _ __ _ __ ___  
   |    | || '__/ _` | '_ \/ __| |_ / _ \| '__| '_ ` _ \ 
   |    | || | | (_| | | | \__ \  _| (_) | |  | | | | | |
   |    |_||_|  \__,_|_| |_|___/_|  \___/|_|  |_| |_| |_|
   |                                                     
  \*/

  //!
  //! Transform VECTOR with affine transformation matrix
  //!
  //! \param vector Input point
  //! \param matrix 4x4 transformation matrix
  //!
  void
  transformVector(
      vec3 &vector,
      affine const &matrix);

  //! Transform POINT with affine transformation matrix
  //!
  //! \param vector Input point
  //! \param matrix 4x4 transformation matrix
  //!
  void
  transformPoint(
      vec3 &vector,
      affine const &matrix);

  /*\
 |   _____ _                          _   _ _ _ _   _           
 |  | ____(_) __ _  ___ _ __    _   _| |_(_) (_) |_(_) ___  ___ 
 |  |  _| | |/ _` |/ _ \ '_ \  | | | | __| | | | __| |/ _ \/ __|
 |  | |___| | (_| |  __/ | | | | |_| | |_| | | | |_| |  __/\__ \
 |  |_____|_|\__, |\___|_| |_|  \__,_|\__|_|_|_|\__|_|\___||___/
 |           |___/                                              
\*/

  //! Overload stream out operator for acme::vec2 object
  std::ostream &
  operator<<(
      std::ostream &os,     //!< Output stream
      acme::vec2 const &obj //!< Vector object
  );

  //! Overload stream out operator for acme::mat2 object
  std::ostream &
  operator<<(
      std::ostream &os,     //!< Output stream
      acme::mat2 const &obj //!< Vector object
  );

  //! Overload stream out operator for acme::vec3 object
  std::ostream &
  operator<<(
      std::ostream &os,     //!< Output stream
      acme::vec3 const &obj //!< Vector object
  );

  //! Overload stream out operator for acme::mat3 object
  std::ostream &
  operator<<(
      std::ostream &os,     //!< Output stream
      acme::mat3 const &obj //!< Vector object
  );

  //! Overload stream out operator for acme::vec4 object
  std::ostream &
  operator<<(
      std::ostream &os,     //!< Output stream
      acme::vec4 const &obj //!< Vector object
  );

  //! Overload stream out operator for acme::mat4 object
  std::ostream &
  operator<<(
      std::ostream &os,     //!< Output stream
      acme::mat4 const &obj //!< Vector object
  );

} // namespace acme

#endif

///
/// eof: acme_eigenextend.hh
///