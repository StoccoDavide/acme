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

  //! Segment class container
  template <typename T = Float>
  class segment
  {
  private:
    const static std::size_t PointCount = 2; //!< Number of points in segment
    point<T> data[PointCount];               //!< Segment data

  public:
    //! Class destructor
    ~segment() {}

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
        const T &x0, //<! Input x value of point0
        const T &y0, //<! Input y value of point0
        const T &z0, //<! Input z value of point0
        const T &x1, //<! Input x value of point1
        const T &y1, //<! Input y value of point1
        const T &z1  //<! Input z value of point1
    )
    {
      this->data[0] = point<T>(x0, y0, z0);
      this->data[1] = point<T>(x1, y1, z1);
    }

    //! Class constructor
    segment(
        const point<T> &point0, //!< Input point object
        const point<T> &point1  //!< Input point object
    )
    {
      this->data[0] = point0;
      this->data[1] = point1;
    }

    //! Equality operator
    inline segment<T> &operator=(
        const segment<T> &segment //!< Input segment object
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

    //! Convert to vector
    inline const vector<T> &toVector(void) const
    {
      return vector<T>(this->_data[0], this->_data[1]);
    }

    //! Convert to ray
    inline const ray<T> &toRay(void) const
    {
      return ray<T>(point<T>(this->_data[0]), vector<T>(this->_data[0], this->_data[1]));
    }

    //! Convert to line
    inline const line<T> &toLine(void) const
    {
      return line<T>(point<T>(this->_data[0]), vector<T>(this->_data[0], this->_data[1]));
    }

    //! Angle between segment and vector [rad]
    inline const T &angle(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return input.angle(input.toVector());
    }

    //! Angle between segment and line [rad]
    inline const T &angle(
        const line<T> &input //!< Input line object
    )
        const
    {
      return input.angle(input.toVector());
    }

    //! Angle between segment and ray [rad]
    inline const T &angle(
        const ray<T> &input //!< Input ray object
    )
        const
    {
      return input.angle(input.toVector());
    }

    //! Angle between segments [rad]
    inline const T &angle(
        const segment<T> &input //!< Input segment object
    )
        const
    {
      return input.angle(input.toVector());
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_segment.hh
///