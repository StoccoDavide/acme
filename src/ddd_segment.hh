///
/// file: ddd_segment.hh
///

#ifndef INCLUDE_DDD_SEGMENT
#define INCLUDE_DDD_SEGMENT

#include "ddd_point.hh"

namespace ddd
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
  template <typename T = Float>
  class segment
  {
  private:
    const static std::size_t PointCount = 2; //!< Number of points in segment
    point<T> data[PointCount];               //!< Segment data

  public:
    //! Copy constructor
    segment(const segment<T> &) = default;

    //! Class constructor
    segment()
    {
      (this->data[0]).clear();
      (this->data[1]).clear();
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
      this->data[0] = point<T>(x0, y0, z0);
      this->data[1] = point<T>(x1, y1, z1);
    }

    //! Class constructor
    segment(
        const point<T> &point0, //!< Input ND point
        const point<T> &point1  //!< Input ND point
    )
    {
      this->data[0] = point0;
      this->data[1] = point1;
    }

    //! Class destructor
    ~segment() {}

    //! Equality operator
    inline segment<T> &operator=(
        const segment<T> &segment //!< Input ND segment
    )
    {
      this->data = segment.data;
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

    //! Return segment entity size
    inline std::size_t size(void) const { return PointCount; }
  };

} // namespace ddd

#endif

///
/// eof: ddd_segment.hh
///