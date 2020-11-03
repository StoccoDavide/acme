///
/// file: acme_point.hh
///

#ifndef INCLUDE_ACME_POINT
#define INCLUDE_ACME_POINT

#include "acme_math.hh"

namespace acme
{

  //! N-dimensional point class container
  template <typename T, std::size_t D>
  class pointnd;

  //! 2-dimensional point class container
  template <typename T>
  class point2d;

  //! 3-dimensional point class container
  template <typename T>
  class point3d;

  //! Template class for automatic N-dimesional point instatiation
  template <typename T, std::size_t D>
  class define_point_type
  {
  public:
    typedef pointnd<T, D> PointType;
  };

  //! Template class for automatic 2-dimesional point instatiation
  template <typename T>
  class define_point_type<T, 2>
  {
  public:
    typedef point2d<T> PointType;
  };

  //! Template class for automatic 3-dimesional point instatiation
  template <typename T>
  class define_point_type<T, 3>
  {
  public:
    typedef point3d<T> PointType;
  };

  /*\
   |               _       _             _ 
   |   _ __   ___ (_)_ __ | |_ _ __   __| |
   |  | '_ \ / _ \| | '_ \| __| '_ \ / _` |
   |  | |_) | (_) | | | | | |_| | | | (_| |
   |  | .__/ \___/|_|_| |_|\__|_| |_|\__,_|
   |  |_|                                  
  \*/

  //! N-dimensional point class container
  template <typename T, std::size_t D>
  class pointnd
  {
  protected:
    Eigen::Matrix<T, D, 1> data;

  public:
    //! Class constructor
    pointnd() { clear(); }

    //! Class constructor
    pointnd(
        const T &value0 //!< Input value 0
    )
    {
      ACME_ASSERT(D == 1, "acme::pointnd::pointnd()\nDiscordant point dimensions.")
      data[0] = value0;
    }

    //! Class constructor
    pointnd(
        const T &value0, //!< Input value 0
        const T &value1  //!< Input value 1
    )
    {
      ACME_ASSERT(D == 2, "acme::pointnd::pointnd()\nDiscordant point dimensions.")
      data[0] = value0;
      data[1] = value1;
    }

    //! Class constructor
    pointnd(
        const T &value0, //!< Input value 0
        const T &value1, //!< Input value 1
        const T &value2  //!< Input value 2
    )
    {
      ACME_ASSERT(D == 3, "acme::pointnd::pointnd()\nDiscordant point dimensions.")
      data[0] = value0;
      data[1] = value1;
      data[2] = value2;
    }

    //! Class constructor
    pointnd(
        const T &value0, //!< Input value 0
        const T &value1, //!< Input value 1
        const T &value2, //!< Input value 2
        const T &value3  //!< Input value 3
    )
    {
      ACME_ASSERT(D == 4, "acme::pointnd::pointnd()\nDiscordant point dimensions.")
      data[0] = value0;
      data[1] = value1;
      data[2] = value2;
      data[3] = value3;
    }

    //! Class constructor
    pointnd(
        const pointnd<T, D> &point //!< Input N-dimensional point
    )
    {
      data = point.data;
    }

    //! Class constructor
    pointnd(
        const point2d<T> &point //!< Input 2-dimensional point
    )
    {
      ACME_ASSERT(D == 2, "acme::pointnd::pointnd()\nDiscordant point dimensions.")
      data[0] = point[0];
      data[1] = point[1];
    }

    //! Class constructor
    pointnd(
        const point3d<T> &point //!< Input 3-dimensional point
    )
    {
      ACME_ASSERT(D == 3, "acme::pointnd::pointnd()\nDiscordant point dimensions.")
      data[0] = point[0];
      data[1] = point[1];
      data[2] = point[2];
    }

    //! Class destructor
    ~pointnd() {}

    //! Clear vector data
    void clear()
    {
      for (std::size_t i = 0; i < D; ++i)
        data[i] = T(0.0);
    }

    //! Equality operator
    inline pointnd<T, D> &operator=(
        const pointnd<T, D> &point //!< Input N-dimensional point
    )
    {
      if (this == &point)
      {
        return *this;
      }
      else
      {
        data = point.data;
        return *this;
      }
    }

    //! Equality operator
    inline pointnd<T, D> &operator=(
        const point2d<T> &point //!< Input 2-dimensional point
    )
    {
      ACME_ASSERT(D == 2, "acme::pointnd::operator=\nDiscordant points dimensions.")
      this->data[0] = point[0];
      this->data[1] = point[1];
      return *this;
    }

    //! Equality operator
    inline pointnd<T, D> &operator=(
        const point3d<T> &point //!< Input 3-dimensional point
    )
    {
      ACME_ASSERT(D == 3, "acme::pointnd::operator=\nDiscordant points dimensions.")
      this->data[0] = point[0];
      this->data[1] = point[1];
      this->data[2] = point[2];
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

  /*\
   |               _       _   ____     _ 
   |   _ __   ___ (_)_ __ | |_|___ \ __| |
   |  | '_ \ / _ \| | '_ \| __| __) / _` |
   |  | |_) | (_) | | | | | |_ / __/ (_| |
   |  | .__/ \___/|_|_| |_|\__|_____\__,_|
   |  |_|                                 
  \*/

  //! 2-dimensional point class container
  template <typename T = Float>
  class point2d : public pointnd<T, 2>
  {
  public:
    //! Class constructor
    point2d()
        : pointnd<T, 2>()
    {
    }

    //! Class constructor
    point2d(
        const T &value0, //!< Input value 0
        const T &value1  //!< Input value 1
        )
        : pointnd<T, 2>(value0, value1)
    {
    }

    //! Class constructor
    point2d(
        const pointnd<T, 2> &point //!< Input 2-dimensional point
        )
        : pointnd<T, 2>(point)
    {
    }

    //! Class constructor
    point2d(
        const point2d<T> &point //!< Input 2-dimensional point
        )
        : pointnd<T, 2>(point)
    {
    }

    //! Class destructor
    ~point2d() {}

    //! Equality operator
    inline point2d<T> &operator=(
        const pointnd<T, 2> &point //!< Input 2-dimensional point
    )
    {
      this->data[0] = point[0];
      this->data[1] = point[1];
      return *this;
    }

    //! Getter for point x value
    inline const T &x() const { return this->data[0]; }

    //! Getter for point y value
    inline const T &y() const { return this->data[1]; }

    //! Setter for point x value
    inline void x(
        const T &x //!< Input x value
    )
    {
      this->data[0] = x;
    }

    //! Setter for point y value
    inline void y(
        const T &y //!< Input y value
    )
    {
      this->data[1] = y;
    }

    //! Create a 3-dimensional point by addind x value
    inline point2d<T> &make3dX(
        const T &x //!< Input x value
    )
    {
      return point3d<T>(x, this->data[0], this->data[1]);
    }

    //! Create a 3-dimensional point by addind y value
    inline point2d<T> &make3dY(
        const T &y //!< Input y value
    )
    {
      return point3d<T>(this->data[0], y, this->data[1]);
    }

    //! Create a 3-dimensional point by addind z value
    inline point2d<T> &make3dZ(
        const T &z //!< Input z value
    )
    {
      return point3d<T>(this->data[0], this->data[1], z);
    }
  };

  /*\
   |               _       _   _____     _ 
   |   _ __   ___ (_)_ __ | |_|___ /  __| |
   |  | '_ \ / _ \| | '_ \| __| |_ \ / _` |
   |  | |_) | (_) | | | | | |_ ___) | (_| |
   |  | .__/ \___/|_|_| |_|\__|____/ \__,_|
   |  |_|                                  
  \*/

  //! 3-dimensional point class container
  template <typename T = Float>
  class point3d : public pointnd<T, 3>
  {
  public:
    //! Class constructor
    point3d()
        : pointnd<T, 3>()
    {
    }

    //! Class constructor
    point3d(
        const T &value0, //!< Input value 0
        const T &value1, //!< Input value 1
        const T &value2  //!< Input value 2
        )
        : pointnd<T, 3>(value0, value1, value2)
    {
    }

    //! Class constructor
    point3d(
        const pointnd<T, 3> &point //!< Input 3-dimensional point
        )
        : pointnd<T, 3>(point)
    {
    }

    //! Class constructor
    point3d(
        const point3d<T> &point //!< Input 3-dimensional point
        )
        : pointnd<T, 3>(point)
    {
    }

    //! Class destructor
    ~point3d() {}

    //! Equality operator
    inline point3d<T> &operator=(
        const pointnd<T, 3> &point //!< Input 3-dimensional point
    )
    {
      this->data[0] = point[0];
      this->data[1] = point[1];
      this->data[2] = point[2];
      return *this;
    }

    //! Getter for point x value
    inline const T &x() const { return this->data[0]; }

    //! Getter for point y value
    inline const T &y() const { return this->data[1]; }

    //! Getter for point z value
    inline const T &z() const { return this->data[2]; }

    //! Setter for point x value
    inline void x(
        const T &x //!< Input x value
    )
    {
      this->data[0] = x;
    }

    //! Setter for point y value
    inline void y(
        const T &y //!< Input y value
    )
    {
      this->data[1] = y;
    }

    //! Setter for point z value
    inline void z(
        const T &z //!< Input z value
    )
    {
      this->data[2] = z;
    }

    //! Create a 3-dimensional point by addind value on selected index value
    inline point2d<T> &make2d(
        const std::size_t &index1, //!< Inuput index 1
        const std::size_t &index2  //!< Inuput index 2
    )
    {
      ACME_ASSERT(index1 > -1 && index1 < 3 && index2 > -1 && index2 < 3,
                  "acme::pointnd::make2d()\nIndex must be inside the interval [0,2].")
      return point2d<T>(this->data[index1], this->data[index2]);
    }
  };

} // namespace acme

#endif

///
/// eof: acme_point.hh
///