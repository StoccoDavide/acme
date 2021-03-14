///
/// file: ddd_point.hh
///

#ifndef INCLUDE_DDD_POINT
#define INCLUDE_DDD_POINT

#include "ddd_math.hh"

namespace ddd
{

  /*\
   |               _       _   
   |   _ __   ___ (_)_ __ | |_ 
   |  | '_ \ / _ \| | '_ \| __|
   |  | |_) | (_) | | | | | |_ 
   |  | .__/ \___/|_|_| |_|\__|
   |  |_|                      
  \*/

  //! ddd point class container
  template <typename T = Float>
  class point
  {
  protected:
    Eigen::Matrix<T, 3, 1> data; //!< Point data as Eigen 3x1 column vector

  public:
    //! Class destructor
    ~point() {}

    //! Class constructor
    point() { clear(); }

    //! Class constructor
    point(
        const T &x, //!< Input x value
        const T &y, //!< Input y value
        const T &z  //!< Input z value
    )
    {
      this->data[0] = x;
      this->data[1] = y;
      this->data[2] = z;
    }

    //! Clear vector data
    void clear()
    {
      for (std::size_t i = 0; i < 3; ++i) this->data[i] = T(0.0);
    }

    //! Equality operator
    inline point<T> &operator=(
        const point<T> &point //!< Input point
    )
    {
      this->data = point.data;
      return *this;
    }

    //! Indexing operator
    inline T &operator[](
        const std::size_t &index //!< Input index
    )
    {
      return data[index];
    }

    //! Indexing operator
    inline const T &operator[](
        const std::size_t &index //!< Input index
    )
        const
    {
      return data[index];
    }

    //! Get x coordinate
    inline const T &x(void)
        const
    {
      return data.x();
    }

    //! Get y coordinate
    inline const T &y(void)
        const
    {
      return data.y();
    }

    //! Get z coordinate
    inline const T &z(void)
        const
    {
      return data.z();
    }

  };

} // namespace ddd

#endif

///
/// eof: ddd_point.hh
///