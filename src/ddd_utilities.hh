///
/// file: ddd_utilities.hh
///

/*
(***********************************************************************)
(*                                                                     *)
(* The ddd computational geometry library                              *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The ddd computational geometry library and its components are       *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the ddd computational geometry library and its      *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

#ifndef INCLUDE_DDD_UTILTIES
#define INCLUDE_DDD_UTILTIES

#include <iostream>
#include <iomanip>
#include <vector>

#include "ddd.hh"

namespace ddd
{
  //!< Stream out operator for point object
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,   //!< Output stream
      const point<T> &obj //!< Point object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj[0] << "," << obj[1] << "," << obj[2] << ")";
    return os;
  }

  //!< Stream out operator for vector object
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,    //!< Output stream
      const vector<T> &obj //!< Vector object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj[0] << "," << obj[1] << "," << obj[2] << ")";
    return os;
  }

  //!< Stream out operator for line object
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,  //!< Output stream
      const line<T> &obj //!< Line object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj.origin()[0] << "," << obj.origin()[1] << "," << obj.origin()[2] << ","
       << obj.direction()[0] << "," << obj.direction()[1] << "," << obj.direction()[2] << ")";
    return os;
  }

  //!< Stream out operator for ray object
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os, //!< Output stream
      const ray<T> &obj //!< Ray object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj.origin()[0] << "," << obj.origin()[1] << "," << obj.origin()[2] << ","
       << obj.direction()[0] << "," << obj.direction()[1] << "," << obj.direction()[2] << ")";
    return os;
  }

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,   //!< Output stream
      const plane<T> &obj //!< Plane object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj.origin()[0] << "," << obj.origin()[1] << "," << obj.origin()[2] << ","
       << obj.normal()[0] << "," << obj.normal()[1] << "," << obj.normal()[2] << ")";
    return os;
  }

  //!< Stream out operator for segment object
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,     //!< Output stream
      const segment<T> &obj //!< Segment object
  )
  {
    for (unsigned int i = 0; i < obj.size(); ++i)
    {
      os << obj[i];
    }
    return os;
  }

  //!< Stream out operator for box object
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os, //!< Output stream
      const box<T> &obj //!< Box object
  )
  {
    for (unsigned int i = 0; i < obj.size(); ++i)
    {
      os << obj[i];
    }
    return os;
  }

  //!< Stream out operator for triangle object
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,      //!< Output stream
      const triangle<T> &obj //!< Triangle object
  )
  {
    for (unsigned int i = 0; i < obj.size(); ++i)
    {
      os << obj[i];
    }
    return os;
  }

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,    //!< Output stream
      const quadix<T> &obj //!< Quadix object
  )
  {
    for (unsigned int i = 0; i < obj.size(); ++i)
    {
      os << obj[i];
    }
    return os;
  }

  /*
   template <typename T>
   inline std::ostream& operator<<(
     std::ostream& os,   //!< Output stream
     const circle<T>& circle //!< Circle object
     )
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(10)
         << "(" << circle[0] << "," << circle[1] << "," << circle.radius << ")";

      return os;
   }
  */

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,    //!< Output stream
      const sphere<T> &obj //!< Sphere object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj.origin()[0] << "," << obj.origin()[1] << "," << obj.origin()[2]
       << "," << obj.ray() << ")";
    return os;
  }

} // namespace ddd

#endif


///
/// eof: ddd_utilities.hh
///