///
/// file: ddd_triangle.hh
///

#ifndef INCLUDE_DDD_TRIANGLE
#define INCLUDE_DDD_TRIANGLE

#include "ddd_point.hh"

namespace ddd
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
  template <typename T = Float>
  class triangle
  {
  private:
    const static std::size_t PointCount = 3; //!< Number of points in triangle
    point<T> data[PointCount]; //!< Triangle data

  public:
    //! Copy constructor
    triangle(const triangle<T>&) = default;

    //! Class constructor
    triangle(
        const T &x0, //<! Input x value for point 0
        const T &y0, //<! Input y value for point 0
        const T &z0, //<! Input z value for point 0
        const T &x1, //<! Input x value for point 1
        const T &y1, //<! Input y value for point 1
        const T &z1, //<! Input z value for point 1
        const T &x2, //<! Input x value for point 2
        const T &y2, //<! Input y value for point 2
        const T &z2  //<! Input z value for point 2
    )
    {
      this->data[0] = point<T>(x0, y0, z0);
      this->data[1] = point<T>(x1, y1, z1);
      this->data[2] = point<T>(x2, y2, z2);
    }

    //! Class constructor
    triangle(
        const point<T> &point0, //!< Input ND point 0
        const point<T> &point1, //!< Input ND point 1
        const point<T> &point2  //!< Input ND point 2
    )
    {
      this->data[0] = point0;
      this->data[1] = point1;
      this->data[2] = point2;
    }

    //! Class destructor
    ~triangle() {}

    //! Equality operator
    inline triangle<T> &operator=(
        const triangle<T> &triangle //!< Input ND triangle
    )
    {
      this->data = triangle.data;
      return *this;
    }

    //! Indexing operator
    inline point<T> &operator[](
        const std::size_t &index //!< Input index
    )
    {
      return this->data[index];
    }

    //! Indexing operator
    inline const point<T> &operator[](
        const std::size_t &index //!< Input index
    )
        const
    {
      return this->data[index];
    }

    //! Return triangle entity size
    inline std::size_t size() const { return PointCount; }
  };

} // namespace ddd

#endif

///
/// eof: ddd_triangle.hh
///
