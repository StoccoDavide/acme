///
/// file: ddd_quadix.hh
///

#ifndef INCLUDE_DDD_QUADIX
#define INCLUDE_DDD_QUADIX

#include "ddd_point.hh"

namespace ddd
{

  /*\
   |                         _ _      
   |    __ _ _   _  __ _  __| (_)_  __
   |   / _` | | | |/ _` |/ _` | \ \/ /
   |  | (_| | |_| | (_| | (_| | |>  < 
   |   \__, |\__,_|\__,_|\__,_|_/_/\_\
   |      |_|                         
  \*/

  //! Quadix class container
  template <typename T = Float>
  class quadix
  {
  private:
    const static std::size_t PointCount = 4; //!< Number of points in quadix
    point<T> data[PointCount];               //!< Quadix data

  public:
    //! Class destructor
    ~quadix() {}

    //! Copy constructor
    quadix(const quadix<T> &) = default;

    //! Class constructor
    quadix()
    {
      (this->data[0]).clear();
      (this->data[1]).clear();
      (this->data[2]).clear();
      (this->data[3]).clear();
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
      this->data[0] = point<T>(x0, y0, z0);
      this->data[1] = point<T>(x1, y1, z1);
      this->data[2] = point<T>(x2, y2, z2);
      this->data[3] = point<T>(x3, y3, z3);
    }

    //! Class constructor
    quadix(
        const point<T> &point0, //!< Input point 0
        const point<T> &point1, //!< Input point 1
        const point<T> &point2, //!< Input point 2
        const point<T> &point3  //!< Input point 3
    )
    {
      this->data[0] = point0;
      this->data[1] = point1;
      this->data[2] = point2;
      this->data[3] = point3;
    }

    //! Equality operator
    inline quadix<T> &operator=(
        const quadix<T> &quadix //!< Input ND quadix
    )
    {
      this->data = quadix.data;
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

    //! Return quadix entity size
    inline std::size_t size() const { return PointCount; }
  };

} // namespace ddd

#endif

///
/// eof: ddd_quadix.hh
///
