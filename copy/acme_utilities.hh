#ifndef INCLUDE_ACME_UTILTIIES
#define INCLUDE_ACME_UTILTIIES


#include <iostream>
#include <iomanip>
#include <vector>

#include "acme.hh"
//#include "acme_matrix.hh"


namespace acme
{
   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const point2d<T>& point)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(6)
         << "(" << point.x << "," << point.y << ")";

      return os;
   }

   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const point3d<T>& point)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(6)
         << "(" << point.x << "," << point.y << "," << point.z << ")";

      return os;
   }

   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const vector2d<T>& v)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(6)
         << "(" << v.x << "," << v.y << ")";

      return os;
   }

   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const vector3d<T>& v)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(6)
         << "(" << v.x << "," << v.y << "," << v.z << ")";

      return os;
   }

   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const ray<T,2>& ray)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(6)
         << "(" << ray.origin.x << "," << ray.origin.y << "," << ray.direction.x << "," << ray.direction.y << ")";

      return os;
   }

   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const ray<T,3>& ray)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(6)
         << "(" << ray.origin.x    << "," << ray.origin.y    << "," << ray.origin.z    << ","
                << ray.direction.x << "," << ray.direction.y << "," << ray.direction.z << ")";

      return os;
   }

   template <typename T, std::size_t Dimension>
   inline std::ostream& operator<<(std::ostream& os, const pointnd<T,Dimension>& point)
   {
      os << "(";

      for (std::size_t i = 0; i < Dimension - 1; ++i)
      {
         os << std::scientific
            << std::showpoint
            << std::setprecision(6)
            << point[i] << ",";
      }

      os << std::scientific
         << std::showpoint
         << std::setprecision(6)
         << point[Dimension - 1] << ")";

      return os;
   }

   template <typename T, std::size_t Dimension>
   inline std::ostream& operator<<(std::ostream& os, const segment<T,Dimension>& segment)
   {
      for (unsigned int i = 0; i < acme::segment<T,Dimension>::PointCount; ++i)
      {
         os << segment[i];
      }

      return os;
   }

   template <typename T, std::size_t Dimension>
   inline std::ostream& operator<<(std::ostream& os, const line<T,Dimension>& line)
   {
      for (unsigned int i = 0; i < acme::line<T,Dimension>::PointCount; ++i)
      {
         os << line[i];
      }

      return os;
   }

   template <typename T, std::size_t Dimension>
   inline std::ostream& operator<<(std::ostream& os, const triangle<T,Dimension>& triangle)
   {
      for (unsigned int i = 0; i < acme::triangle<T,Dimension>::PointCount; ++i)
      {
         os << triangle[i];
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

   template <typename T, std::size_t Dimension>
   inline std::ostream& operator<<(std::ostream& os, const box<T,Dimension>& box)
   {
      for (unsigned int i = 0; i < acme::box<T,Dimension>::PointCount; ++i)
      {
         os << box[i];
      }

      return os;
   }

   template <typename T, std::size_t Dimension>
   inline std::ostream& operator<<(std::ostream& os, const quadix<T,Dimension>& quadix)
   {
      for (unsigned int i = 0; i < acme::quadix<T,Dimension>::PointCount; ++i)
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
         << "(" << circle.x << "," << circle.y << "," << circle.radius << ")";

      return os;
   }

   template <typename T>
   inline std::ostream& operator<<(std::ostream& os, const sphere<T>& sphere)
   {
      os << std::scientific
         << std::showpoint
         << std::setprecision(6)
         << "(" << sphere.x << "," << sphere.y << "," << sphere.z << "," << sphere.radius << ")";

      return os;
   }

   /*template <typename T, std::size_t M, std::size_t N>
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
