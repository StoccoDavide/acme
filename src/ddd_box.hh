///
/// file: ddd_box.hh
///

#ifndef INCLUDE_DDD_BOX
#define INCLUDE_DDD_BOX

#include "ddd_point.hh"

namespace ddd
{

  /*\
   |   _               
   |  | |__   _____  __
   |  | '_ \ / _ \ \/ /
   |  | |_) | (_) >  < 
   |  |_.__/ \___/_/\_\
   |                   
  \*/

  //! ddd box class container
  template <typename T = Float>
  class box
  {
  private:
    const static std::size_t PointCount = 2; //!< Number of points in box
    point<T> data[PointCount];               //!< Box data

  public:
    //! Copy constructor
    box(const box<T> &) = default;

    //! Class constructor
    box()
    {
      (this->data[0]).clear();
      (this->data[1]).clear();
    }

    //! Class constructor
    box(
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
    box(
        const point<T> &point1, //!< Input point 1
        const point<T> &point2  //!< Input point 2
    )
    {
      this->data[0] = point1;
      this->data[1] = point2;
    }

    //! Class destructor
    ~box() {}

    //! Equality operator
    inline box<T> &operator=(
        const box<T> &box //!< Input box
    )
    {
      this->data = box.data;
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

    //! Return box entity size
    inline std::size_t size() const { return PointCount; }
  };

} // namespace ddd

#endif

///
/// eof: ddd_box.hh
///