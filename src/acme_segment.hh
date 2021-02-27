///
/// file: acme_segment.hh
///

#ifndef INCLUDE_ACME_SEGMENT
#define INCLUDE_ACME_SEGMENT

#include "acme_point.hh"

namespace acme
{

  /*\
   |                                       _   
   |   ___  ___  __ _ _ __ ___   ___ _ __ | |_ 
   |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __|
   |  \__ \  __/ (_| | | | | | |  __/ | | | |_ 
   |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|
   |            |___/                          
  \*/

  //! ND segment class container
  template <typename T = Float, std::size_t D = 3>
  class segment
  {
  private:
    const static std::size_t PointCount = 2; //!< Number of points in segment
    point<T, D> data[PointCount]; //!< Segment data

  public:
    //! Copy constructor
    segment(const segment<T, D>&) = default;

    //! Class constructor
    segment()
    {
      (this->data[0]).clear();
      (this->data[1]).clear();
    }

    //! Class constructor for 1D segment
    segment(
        const T &x0, //<! Input x value for the first point
        const T &x1  //<! Input x value for the second point
    )
    {
      ACME_ASSERT(D == 1, "acme::segment::segment()\nDiscordant segment dimensions.")
      this->data[0] = x0;
      this->data[1] = x1;
    }

    //! Class constructor for 2D segment
    segment(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1  //<! Input y value for the second point
    )
    {
      ACME_ASSERT(D == 2, "acme::segment::segment()\nDiscordant segment dimensions.")
      this->data[0] = point<T, 2>(x0, y0);
      this->data[1] = point<T, 2>(x1, y1);
    }

    //! Class constructor for 3D segment
    segment(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &z0, //<! Input z value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1, //<! Input y value for the second point
        const T &z1  //<! Input z value for the second point
    )
    {
      ACME_ASSERT(D == 3, "acme::segment::segment()\nDiscordant segment dimensions.")
      this->data[0] = point<T, 3>(x0, y0, z0);
      this->data[1] = point<T, 3>(x1, y1, z1);
    }

    //! Class constructor for 4D segment
    segment(
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
      ACME_ASSERT(D == 4, "acme::segment::segment()\nDiscordant segment dimensions.")
      this->data[0] = point<T, 4>(x0, y0, z0, w0);
      this->data[1] = point<T, 4>(x1, y1, z1, w1);
    }

    //! Class constructor
    segment(
        const point<T, D> &point0, //!< Input ND point
        const point<T, D> &point1  //!< Input ND point
    )
    {
      this->data[0] = point0;
      this->data[1] = point1;
    }

    //! Class destructor
    ~segment() {}

    //! Equality operator
    inline segment<T, D> &operator=(
        const segment<T, D> &segment //!< Input ND segment
    )
    {
      this->data = segment.data;
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
    
    //! Return segment entity size
    inline std::size_t size() const { return PointCount; }
  };

} // namespace acme

#endif

///
/// eof: acme_segment.hh
///