#ifndef INCLUDE_ACME_UTILTIES
#define INCLUDE_ACME_UTILTIES

#include <iostream>
#include <iomanip>
#include <vector>

#include "acme.hh"

namespace acme
{

  template <typename T>
  inline std::ostream &operator<<(std::ostream &os, const point<T, 2> &point)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << point[0] << "," << point[1] << ")";
    return os;
  }

  template <typename T>
  inline std::ostream &operator<<(std::ostream &os, const point<T, 3> &point)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << point[0] << "," << point[1] << "," << point[2] << ")";
    return os;
  }

  template <typename T>
  inline std::ostream &operator<<(std::ostream &os, const vector<T, 2> &v)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << v[0] << "," << v[1] << ")";
    return os;
  }

  template <typename T>
  inline std::ostream &operator<<(std::ostream &os, const vector<T, 3> &v)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << v[0] << "," << v[1] << "," << v[2] << ")";
    return os;
  }

  template <typename T>
  inline std::ostream &operator<<(std::ostream &os, const ray<T, 2> &ray)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << ray.origin()[0] << "," << ray.origin()[1] << "," << ray.direction()[0] << "," << ray.direction()[1] << ")";
    return os;
  }

  template <typename T>
  inline std::ostream &operator<<(std::ostream &os, const ray<T, 3> &ray)
  {
    os << std::scientific
       << std::showpoint
       << std::setprecision(6)
       << "(" << ray.origin()[0] << "," << ray.origin()[1] << "," << ray.origin()[2] << ","
       << ray.direction()[0] << "," << ray.direction()[1] << "," << ray.direction()[2] << ")";
    return os;
  }

  template <typename T, std::size_t D>
  inline std::ostream &operator<<(std::ostream &os, const segment<T, D> &segment)
  {
    for (unsigned int i = 0; i < segment.size(); ++i)
    {
      os << segment[i];
    }
    return os;
  }

  template <typename T, std::size_t D>
  inline std::ostream &operator<<(std::ostream &os, const triangle<T, D> &triangle)
  {
    for (unsigned int i = 0; i < triangle.size(); ++i)
    {
      os << triangle[i];
    }

    return os;
  }
  /*
    template <typename T, std::size_t D>
  inline std::ostream &operator<<(std::ostream &os, const line<T, D> &line)
  {
    for (unsigned int i = 0; i < acme::line<T, D>::PointCount; ++i)
    {
      os << line[i];
    }

    return os;
  }

   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const rectangle<T>& rectangle)
   {
      for (unsigned int i = 0; i < acme::rectangle<T>::PointCount; ++i)
      {
         os << rectangle[i];
      }

      return os;
   }

   template <typename T, std::size_t D>
   inline std::ostream& operator<<(std::ostream& os, const box<T,D>& box)
   {
      for (unsigned int i = 0; i < acme::box<T,D>::PointCount; ++i)
      {
         os << box[i];
      }

      return os;
   }

   template <typename T, std::size_t D>
   inline std::ostream& operator<<(std::ostream& os, const quadix<T,D>& quadix)
   {
      for (unsigned int i = 0; i < acme::quadix<T,D>::PointCount; ++i)
      {
         os << quadix[i];
      }

      return os;
   }

   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const circle<T>& circle)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(10)
         << "(" << circle[0] << "," << circle[1] << "," << circle.radius << ")";

      return os;
   }

   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const sphere<T>& sphere)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(6)
         << "(" << sphere[0] << "," << sphere[1] << "," << sphere[2] << "," << sphere.radius << ")";

      return os;
   }

   template <typename T, std::size_t M, std::size_t N>
   inline std::ostream& operator<<(std::ostream& os, const matrix<T,M,N>& matrix)
   {
      for (std::size_t x = 0; x < M; x++)
      {
         for (std::size_t y = 0; y < N; y++)
         {
            os << matrix(x,y) << "\t";
         }

         os << std::endl;
      }

      return os;
   }*/

} // namespace acme

#endif
