///
/// file: acme_box.hh
///

#ifndef INCLUDE_ACME_BOX
#define INCLUDE_ACME_BOX

#include "acme_point.hh"

namespace acme
{

  /*\
   |   _               
   |  | |__   _____  __
   |  | '_ \ / _ \ \/ /
   |  | |_) | (_) >  < 
   |  |_.__/ \___/_/\_\
   |                   
  \*/

  //! ND box class container
  template <typename T = Float, std::size_t D = 3>
  class box
  {
  private:
    const static std::size_t PointCount = 2; //!< Number of points in box
    point<T, D> data[PointCount];            //!< Box data

  public:
    //! Copy constructor
    box(const box<T, D> &) = default;

    //! Class constructor
    box()
    {
      (this->data[0]).clear();
      (this->data[1]).clear();
    }

    //! Class constructor for 1D box
    box(
        const T &x0, //<! Input x value for the first point
        const T &x1  //<! Input x value for the second point
    )
    {
      ACME_ASSERT(D == 1, "acme::box::box()\nDiscordant box dimensions.")
      this->data[0] = x0;
      this->data[1] = x1;
    }

    //! Class constructor for 2D box
    box(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1  //<! Input y value for the second point
    )
    {
      ACME_ASSERT(D == 2, "acme::box::box()\nDiscordant box dimensions.")
      this->data[0] = point<T, 2>(x0, y0);
      this->data[1] = point<T, 2>(x1, y1);
    }

    //! Class constructor for 3D box
    box(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &z0, //<! Input z value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1, //<! Input y value for the second point
        const T &z1  //<! Input z value for the second point
    )
    {
      ACME_ASSERT(D == 3, "acme::box::box()\nDiscordant box dimensions.")
      this->data[0] = point<T, 3>(x0, y0, z0);
      this->data[1] = point<T, 3>(x1, y1, z1);
    }

    //! Class constructor for 4D box
    box(
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
      ACME_ASSERT(D == 4, "acme::box::box()\nDiscordant box dimensions.")
      this->data[0] = point<T, 4>(x0, y0, z0, w0);
      this->data[1] = point<T, 4>(x1, y1, z1, w1);
    }

    //! Class constructor
    box(
        const point<T, D> &point0, //!< Input ND point
        const point<T, D> &point1  //!< Input ND point
    )
    {
      this->data[0] = point0;
      this->data[1] = point1;
    }

    //! Class destructor
    ~box() {}

    //! Equality operator
    inline box<T, D> &operator=(
        const box<T, D> &box //!< Input ND box
    )
    {
      this->data = box.data;
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

    //! Return box entity size
    inline std::size_t size() const { return PointCount; }
  };

} // namespace acme

#endif

///
/// eof: acme_box.hh
///