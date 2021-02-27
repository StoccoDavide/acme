///
/// file: acme_point.hh
///

#ifndef INCLUDE_ACME_POINT
#define INCLUDE_ACME_POINT

#include "acme_math.hh"

namespace acme
{

  /*\
   |               _       _   
   |   _ __   ___ (_)_ __ | |_ 
   |  | '_ \ / _ \| | '_ \| __|
   |  | |_) | (_) | | | | | |_ 
   |  | .__/ \___/|_|_| |_|\__|
   |  |_|                      
  \*/

  //! ND point class container
  template <typename T = Float, std::size_t D = 3>
  class point
  {
  protected:
    Eigen::Matrix<T, D, 1> data; //!< Point data as Eigen column vector

  public:
    //! Class constructor
    point() { clear(); }

    //! Class constructor for 1D point
    point(
        const T &value0 //!< Input value 0
    )
    {
      ACME_ASSERT(D == 1, "acme::point::point()\nDiscordant point dimensions.")
      this->data[0] = value0;
    }

    //! Class constructor for 2D point
    point(
        const T &value0, //!< Input value 0
        const T &value1  //!< Input value 1
    )
    {
      ACME_ASSERT(D == 2, "acme::point::point()\nDiscordant point dimensions.")
      this->data[0] = value0;
      this->data[1] = value1;
    }

    //! Class constructor for 3D point
    point(
        const T &value0, //!< Input value 0
        const T &value1, //!< Input value 1
        const T &value2  //!< Input value 2
    )
    {
      ACME_ASSERT(D == 3, "acme::point::point()\nDiscordant point dimensions.")
      this->data[0] = value0;
      this->data[1] = value1;
      this->data[2] = value2;
    }

    //! Class constructor for 4D point
    point(
        const T &value0, //!< Input value 0
        const T &value1, //!< Input value 1
        const T &value2, //!< Input value 2
        const T &value3  //!< Input value 3
    )
    {
      ACME_ASSERT(D == 4, "acme::point::point()\nDiscordant point dimensions.")
      this->data[0] = value0;
      this->data[1] = value1;
      this->data[2] = value2;
      this->data[3] = value3;
    }

    //! Class destructor
    ~point() {}

    //! Clear vector data
    void clear()
    {
      for (std::size_t i = 0; i < D; ++i)
        this->data[i] = T(0.0);
    }

    //! Equality operator
    inline point<T, D> &operator=(
        const point<T, D> &point //!< Input ND point
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
  };

} // namespace acme

#endif

///
/// eof: acme_point.hh
///