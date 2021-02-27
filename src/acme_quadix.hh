///
/// file: acme_quadix.hh
///

#ifndef INCLUDE_ACME_QUADIX
#define INCLUDE_ACME_QUADIX

#include "acme_point.hh"

namespace acme
{

  /*\
   |                         _ _      
   |    __ _ _   _  __ _  __| (_)_  __
   |   / _` | | | |/ _` |/ _` | \ \/ /
   |  | (_| | |_| | (_| | (_| | |>  < 
   |   \__, |\__,_|\__,_|\__,_|_/_/\_\
   |      |_|                         
  \*/

  //! ND quadix class container
  template <typename T = Float, std::size_t D = 3>
  class quadix
  {
  private:
    const static std::size_t PointCount = 4; //!< Number of points in quadix
    point<T, D> data[PointCount]; //!< Quadix data

  public:
    //! Copy constructor
    quadix(const quadix<T, D>&) = default;

    //! Class constructor
    quadix() {
      (this->data[0]).clear();
      (this->data[1]).clear();
      (this->data[2]).clear();
      (this->data[3]).clear();
    }

    //! Class constructor for 2D quadix
    quadix(
        const T &x0, //<! Input x value for point 0
        const T &y0, //<! Input y value for point 0
        const T &x1, //<! Input x value for point 1
        const T &y1, //<! Input y value for point 1
        const T &x2, //<! Input x value for point 2
        const T &y2, //<! Input y value for point 2
        const T &x3, //<! Input x value for point 3
        const T &y3  //<! Input y value for point 3
    )
    {
      ACME_ASSERT(D == 2, "acme::segment::segment()\nDiscordant segment dimensions.")
      this->data[0] = point<T, 2>(x0, y0);
      this->data[1] = point<T, 2>(x1, y1);
      this->data[2] = point<T, 2>(x2, y2);
      this->data[3] = point<T, 2>(x3, y3);
    }

    //! Class constructor for 3D quadix
    quadix(
        const T &x0, //<! Input x value for point 0
        const T &y0, //<! Input y value for point 0
        const T &z0, //<! Input z value for point 0
        const T &x1, //<! Input x value for point 1
        const T &y1, //<! Input y value for point 1
        const T &z1, //<! Input z value for point 1
        const T &x2, //<! Input x value for point 2
        const T &y2, //<! Input y value for point 2
        const T &z2, //<! Input z value for point 2
        const T &x3, //<! Input x value for point 3
        const T &y3, //<! Input y value for point 3
        const T &z3  //<! Input z value for point 3
    )
    {
      ACME_ASSERT(D == 3, "acme::segment::segment()\nDiscordant segment dimensions.")
      this->data[0] = point<T, 3>(x0, y0, z0);
      this->data[1] = point<T, 3>(x1, y1, z1);
      this->data[2] = point<T, 3>(x2, y2, z2);
      this->data[3] = point<T, 3>(x3, y3, z3);
    }

    //! Class constructor
    quadix(
        const point<T, D> &point0, //!< Input ND point 0
        const point<T, D> &point1, //!< Input ND point 1
        const point<T, D> &point2, //!< Input ND point 2
        const point<T, D> &point3  //!< Input ND point 3
    )
    {
      this->data[0] = point0;
      this->data[1] = point1;
      this->data[2] = point2;
      this->data[3] = point3;
    }

    //! Class destructor
    ~quadix() {}

    //! Equality operator
    inline quadix<T, D> &operator=(
        const quadix<T, D> &quadix //!< Input ND quadix
    )
    {
      this->data = quadix.data;
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

    //! Return quadix entity size
    inline std::size_t size() const { return PointCount; }
  };

} // namespace acme

#endif

///
/// eof: acme_quadix.hh
///
