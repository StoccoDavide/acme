///
/// file: acme_triangle.hh
///

#ifndef INCLUDE_ACME_TRIANGLE
#define INCLUDE_ACME_TRIANGLE

#include "acme_point.hh"

namespace acme
{

  /*\
   |   _        _                   _      
   |  | |_ _ __(_) __ _ _ __   __ _| | ___ 
   |  | __| '__| |/ _` | '_ \ / _` | |/ _ \
   |  | |_| |  | | (_| | | | | (_| | |  __/
   |   \__|_|  |_|\__,_|_| |_|\__, |_|\___|
   |                          |___/        
  \*/

  //! ND triangle class container
  template <typename T = Float, std::size_t D = 3>
  class triangle
  {
  private:
    const static std::size_t PointCount = 3;
    point<T, D> data[PointCount];

  public:
    //! Copy constructor
    triangle(const triangle<T, D>&) = default;

    //! Class constructor
    triangle() {
      (this->data[0]).clear();
      (this->data[1]).clear();
      (this->data[2]).clear();
    }

    //! Class constructor for 2D triangle
    triangle(
        const T &x0, //<! Input x value for point 0
        const T &y0, //<! Input y value for point 0
        const T &x1, //<! Input x value for point 1
        const T &y1, //<! Input y value for point 1
        const T &x2, //<! Input x value for point 2
        const T &y2  //<! Input y value for point 2
    )
    {
      ACME_ASSERT(D == 2, "acme::segment::segment()\nDiscordant segment dimensions.")
      this->data[0] = point<T, 2>(x0, y0);
      this->data[1] = point<T, 2>(x1, y1);
      this->data[2] = point<T, 2>(x2, y2);
    }

    //! Class constructor for 3D triangle
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
      ACME_ASSERT(D == 3, "acme::segment::segment()\nDiscordant segment dimensions.")
      this->data[0] = point<T, 3>(x0, y0, z0);
      this->data[1] = point<T, 3>(x1, y1, z1);
      this->data[2] = point<T, 3>(x2, y2, z2);
    }

    //! Class constructor
    triangle(
        const point<T, D> &point0, //!< Input ND point 0
        const point<T, D> &point1, //!< Input ND point 1
        const point<T, D> &point2  //!< Input ND point 2
    )
    {
      this->data[0] = point0;
      this->data[1] = point1;
      this->data[2] = point2;
    }

    //! Class destructor
    ~triangle() {}

    //! Equality operator
    inline triangle<T, D> &operator=(
        const triangle<T, D> &triangle //!< Input ND triangle
    )
    {
      this->data = triangle.data;
      return *this;
    }

    //! Indexing operator
    inline point<T, D> &operator[](
        const std::size_t &index //!< Input index
    )
    {
      return this->data[index];
    }

    //! Indexing operator
    inline const point<T, D> &operator[](
        const std::size_t &index //!< Input index
    )
        const
    {
      return this->data[index];
    }

    //! Return triangle entity size
    inline std::size_t size() const { return PointCount; }
  };

} // namespace acme

#endif

///
/// eof: acme_triangle.hh
///
