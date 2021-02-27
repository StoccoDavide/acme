#ifndef INCLUDE_ACME_UTILTIES
#define INCLUDE_ACME_UTILTIES

#include <iostream>
#include <iomanip>
#include <vector>

#include "acme.hh"

namespace acme
{

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,      //!< Output stream
      const point<T, 2> &obj //!< 2D point object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj[0] << "," << obj[1] << ")";
    return os;
  }

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,      //!< Output stream
      const point<T, 3> &obj //!< 3D point object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj[0] << "," << obj[1] << "," << obj[2] << ")";
    return os;
  }

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,       //!< Output stream
      const vector<T, 2> &obj //!< 2D vector object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj[0] << "," << obj[1] << ")";
    return os;
  }

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,       //!< Output stream
      const vector<T, 3> &obj //!< 3D vector object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj[0] << "," << obj[1] << "," << obj[2] << ")";
    return os;
  }

  //!< Stream out operator
  template <typename T, std::size_t D>
  inline std::ostream &operator<<(
      std::ostream &os,        //!< Output stream
      const segment<T, D> &obj //!< Segment object
  )
  {
    for (unsigned int i = 0; i < obj.size(); ++i)
    {
      os << obj[i];
    }
    return os;
  }

  //!< Stream out operator
  template <typename T, std::size_t D>
  inline std::ostream &operator<<(
      std::ostream &os,     //!< Output stream
      const line<T, D> &obj //!< Line object
  )
  {
    for (unsigned int i = 0; i < obj.size(); ++i)
    {
      os << obj[i];
    }
    return os;
  }

  //!< Stream out operator
  template <typename T, std::size_t D>
  inline std::ostream &operator<<(
      std::ostream &os,    //!< Output stream
      const box<T, D> &obj //!< Box object
  )
  {
    for (unsigned int i = 0; i < obj.size(); ++i)
    {
      os << obj[i];
    }
    return os;
  }

  //!< Stream out operator
  template <typename T, std::size_t D>
  inline std::ostream &operator<<(
      std::ostream &os,         //!< Output stream
      const triangle<T, D> &obj //!< Triangle object
  )
  {
    for (unsigned int i = 0; i < obj.size(); ++i)
    {
      os << obj[i];
    }
    return os;
  }

  //!< Stream out operator
  template <typename T, std::size_t D>
  inline std::ostream &operator<<(
      std::ostream &os,       //!< Output stream
      const quadix<T, D> &obj //!< Quadix object
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
      const ray<T, 2> &obj //!< 2D ray object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj.origin()[0] << "," << obj.origin()[1] << ","
       << obj.direction()[0] << "," << obj.direction()[1] << ")";
    return os;
  }

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,    //!< Output stream
      const ray<T, 3> &obj //!< 3D ray object
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
      std::ostream &os,      //!< Output stream
      const plane<T, 2> &obj //!< 2D plane object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj.origin()[0] << "," << obj.origin()[1] << ","
       << obj.normal()[0] << "," << obj.normal()[1] << ")";
    return os;
  }

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,      //!< Output stream
      const plane<T, 3> &obj //!< 3D plane object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj.origin()[0] << "," << obj.origin()[1] << "," << obj.origin()[2] << ","
       << obj.normal()[0] << "," << obj.normal()[1] << "," << obj.normal()[2] << ")";
    return os;
  }

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,       //!< Output stream
      const sphere<T, 2> &obj //!< 2D sphere object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj.point.origin()[0] << "," << obj.origin()[1]
       << "," << obj.ray() << ")";
    return os;
  }

  //!< Stream out operator
  template <typename T>
  inline std::ostream &operator<<(
      std::ostream &os,       //!< Output stream
      const sphere<T, 3> &obj //!< 3D sphere object
  )
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << obj.origin()[0] << "," << obj.origin()[1] << "," << obj.origin()[2]
       << "," << obj.ray() << ")";
    return os;
  }

  /*
   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const circle<T>& circle)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(10)
         << "(" << circle[0] << "," << circle[1] << "," << circle.radius << ")";

      return os;
   }
  */

} // namespace acme

#endif
