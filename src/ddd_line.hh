///
/// file: ddd_line.hh
///

#ifndef INCLUDE_DDD_LINE
#define INCLUDE_DDD_LINE

#include "ddd_point.hh"

namespace ddd
{

  /*\
   |   _ _            
   |  | (_)_ __   ___ 
   |  | | | '_ \ / _ \
   |  | | | | | |  __/
   |  |_|_|_| |_|\___|
   |                  
  \*/

  //! Line class container
  template <typename T = Float>
  class line
  {
  private:
    const static std::size_t PointCount = 2; //!< Number of points in line
    point<T> data[PointCount];            //!< Line data

  public:
    //! Class destructor
    ~line() {}

    //! Copy constructor
    line(const line<T> &) = default;

    //! Class constructor for 3D line
    line(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &z0, //<! Input z value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1, //<! Input y value for the second point
        const T &z1  //<! Input z value for the second point
    )
    {
      this->data[0] = point<T>(x0, y0, z0);
      this->data[1] = point<T>(x1, y1, z1);
    }

    //! Class constructor
    line(
        const point<T> &point1, //!< Input point 1
        const point<T> &point2  //!< Input point 2
    )
    {
      this->data[0] = point1;
      this->data[1] = point2;
    }

    //! Equality operator
    inline line<T> &operator=(
        const line<T> &line //!< Input ND line
    )
    {
      this->data = line.data;
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

    //! Return line entity size
    inline std::size_t size() const { return PointCount; }
  };

} // namespace ddd

#endif

///
/// eof: ddd_line.hh
///