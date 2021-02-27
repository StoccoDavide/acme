///
/// file: acme_line.hh
///

#ifndef INCLUDE_ACME_LINE
#define INCLUDE_ACME_LINE

#include "acme_point.hh"

namespace acme
{

  /*\
   |   _ _            
   |  | (_)_ __   ___ 
   |  | | | '_ \ / _ \
   |  | | | | | |  __/
   |  |_|_|_| |_|\___|
   |                  
  \*/

  //! ND line class container
  template <typename T = Float, std::size_t D = 3>
  class line
  {
  private:
    const static std::size_t PointCount = 2; //!< Number of points in line
    point<T, D> data[PointCount];            //!< Line data

  public:
    //! Copy constructor
    line(const line<T, D> &) = default;

    //! Class constructor
    line()
    {
      (this->data[0]).clear();
      (this->data[1]).clear();
    }

    //! Class constructor for 1D line
    line(
        const T &x0, //<! Input x value for the first point
        const T &x1  //<! Input x value for the second point
    )
    {
      ACME_ASSERT(D == 1, "acme::line::line()\nDiscordant line dimensions.")
      this->data[0] = x0;
      this->data[1] = x1;
    }

    //! Class constructor for 2D line
    line(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1  //<! Input y value for the second point
    )
    {
      ACME_ASSERT(D == 2, "acme::line::line()\nDiscordant line dimensions.")
      this->data[0] = point<T, 2>(x0, y0);
      this->data[1] = point<T, 2>(x1, y1);
    }

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
      ACME_ASSERT(D == 3, "acme::line::line()\nDiscordant line dimensions.")
      this->data[0] = point<T, 3>(x0, y0, z0);
      this->data[1] = point<T, 3>(x1, y1, z1);
    }

    //! Class constructor for 4D line
    line(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &z0, //<! Input z value for the first point
        const T &w0, //<! Input w value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1, //<! Input y value for the second point
        const T &z1, //<! Input z value for the second point
        const T &w1  //<! Input w value for the second point
    )
    {
      ACME_ASSERT(D == 4, "acme::line::line()\nDiscordant line dimensions.")
      this->data[0] = point<T, 4>(x0, y0, z0, w0);
      this->data[1] = point<T, 4>(x1, y1, z1, w1);
    }

    //! Class constructor
    line(
        const point<T, D> &point0, //!< Input ND point
        const point<T, D> &point1  //!< Input ND point
    )
    {
      this->data[0] = point0;
      this->data[1] = point1;
    }

    //! Class destructor
    ~line() {}

    //! Equality operator
    inline line<T, D> &operator=(
        const line<T, D> &line //!< Input ND line
    )
    {
      this->data = line.data;
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

    //! Return line entity size
    inline std::size_t size() const { return PointCount; }
  };

} // namespace acme

#endif

///
/// eof: acme_line.hh
///