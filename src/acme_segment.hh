///
/// file: acme_segment.hh
///

#ifndef INCLUDE_ACME_SEGMENT
#define INCLUDE_ACME_SEGMENT

#include "acme_math.hh"
#include "acme_point.hh"

namespace acme
{

  template <typename T, std::size_t D>
  class segmentnd;

  template <typename T>
  class segment2d;

  template <typename T>
  class segment3d;

  //! Template class for automatic N-dimesional segment instatiation
  template <typename T, std::size_t D>
  class define_segment_type
  {
  public:
    typedef segmentnd<T, D> SegmentType;
  };

  //! Template class for automatic 2-dimesional segment instatiation
  template <typename T>
  class define_segment_type<T, 2>
  {
  public:
    typedef segment2d<T> SegmentType;
  };

  //! Template class for automatic 3-dimesional segment instatiation
  template <typename T>
  class define_segment_type<T, 3>
  {
  public:
    typedef segment3d<T> SegmentType;
  };

  /*\
   |                                       _             _ 
   |   ___  ___  __ _ _ __ ___   ___ _ __ | |_ _ __   __| |
   |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __| '_ \ / _` |
   |  \__ \  __/ (_| | | | | | |  __/ | | | |_| | | | (_| |
   |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|_| |_|\__,_|
   |            |___/                                      
  \*/

  template <typename T, std::size_t D>
  class segmentnd
  {
  private:
    typedef typename define_point_type<T, D>::PointType PointType;
    const static std::size_t PointCount = 2;

    PointType data[PointCount];

  public:
    //! Class constructor
    segmentnd() {}

    //! Class constructor
    segmentnd(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1  //<! Input y value for the second point
    )
    {
      ACME_ASSERT(D == 2, "acme::segmentnd::segmentnd()\nDiscordant segment dimensions.")
      data[0] = point2d<T>(x0, y0);
      data[1] = point2d<T>(x1, y1);
    }

    //! Class constructor
    segmentnd(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &z0, //<! Input z value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1, //<! Input y value for the second point
        const T &z1  //<! Input z value for the second point
    )
    {
      ACME_ASSERT(D == 3, "acme::segmentnd::segmentnd()\nDiscordant segment dimensions.")
      data[0] = point3d<T>(x0, y0, z0);
      data[1] = point3d<T>(x1, y1, z1);
    }

    //! Class constructor
    segmentnd(
        const point2d<T> &point0, //!< Input 2-dimensional point
        const point2d<T> &point1  //!< Input 2-dimensional point
    )
    {
      ACME_ASSERT(D == 2, "acme::segmentnd::segmentnd()\nDiscordant segment dimensions.")
      data[0] = point0;
      data[1] = point1;
    };

    //! Class constructor
    segmentnd(
        const point3d<T> &point0, //!< Input 3-dimensional point
        const point3d<T> &point1  //!< Input 3-dimensional point
    )
    {
      ACME_ASSERT(D == 3, "acme::segmentnd::segmentnd()\nDiscordant segment dimensions.")
      data[0] = point0;
      data[1] = point1;
    }

    //! Class constructor
    segmentnd(
        const pointnd<T, D> &point0, //!< Input N-dimensional point
        const pointnd<T, D> &point1  //!< Input N-dimensional point
    )
    {
      data[0] = point0;
      data[1] = point1;
    }

    //! Class constructor
    segmentnd(
        const segmentnd<T, D> &segment //!< Input N-dimensional segment
    )
    {
      data = segment;
    }

    //! Class constructor
    segmentnd(
        const segment2d<T> &segment //!< Input 2-dimensional segment
    )
    {
      ACME_ASSERT(D == 2, "acme::segmentnd::segmentnd()\nDiscordant segment dimensions.")
      data = segment;
    }

    //! Class constructor
    segmentnd(
        const segment3d<T> &segment //!< Input 3-dimensional segment
    )
    {
      ACME_ASSERT(D == 3, "acme::segmentnd::segmentnd()\nDiscordant segment dimensions.")
      data = segment;
    }

    //! Class destructor
    ~segmentnd() {}

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
    inline segmentnd<T, D> &operator=(
        const segment2d<T> &point //!< Input 2-dimensional point
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

    inline pointnd<T, D> &operator[](const std::size_t &index) { return data[index]; }
    inline const pointnd<T, D> &operator[](const std::size_t &index) const { return data[index]; }
    inline std::size_t size() { return PointCount; }
  };

  /*\
   |                                       _   ____     _ 
   |   ___  ___  __ _ _ __ ___   ___ _ __ | |_|___ \ __| |
   |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __| __) / _` |
   |  \__ \  __/ (_| | | | | | |  __/ | | | |_ / __/ (_| |
   |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|_____\__,_|
   |            |___/                                     
  \*/

  template <typename T = Float>
  class segment2d : public segmentnd<T, 2>
  {
    //! Class constructor
    segment2d() : segmentnd<T, 2>() {}

    //! Class constructor
    segment2d(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1  //<! Input y value for the second point
        ) : segmentnd<T, 2>(x0, y0, x1, y1)
    {
    }

    //! Class constructor
    segment2d(
        const point2d<T> &point0, //!< Input 2-dimensional point
        const point2d<T> &point1  //!< Input 2-dimensional point
        ) : segmentnd<T, 2>(point0, point1)
    {
    }

    //! Class constructor
    segment2d(
        const pointnd<T, 2> &point0, //!< Input N-dimensional point
        const pointnd<T, 2> &point1  //!< Input N-dimensional point
        ) : segmentnd<T, 2>(point0, point1)
    {
    }

    //! Class constructor
    segment2d(
        const segmentnd<T, 2> &segment //!< Input N-dimensional segment
        ) : segmentnd<T, 2>(segment)
    {
    }

    //! Class constructor
    segment2d(
        const segment2d<T> &segment //!< Input 2-dimensional segment
        ) : segmentnd<T, 2>(segment)
    {
    }

    //! Class destructor
    ~segment2d() {}
  };

  /*\
   |                                       _   _____     _ 
   |   ___  ___  __ _ _ __ ___   ___ _ __ | |_|___ /  __| |
   |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __| |_ \ / _` |
   |  \__ \  __/ (_| | | | | | |  __/ | | | |_ ___) | (_| |
   |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|____/ \__,_|
   |            |___/                                      
  \*/

  template <typename T = Float>
  class segment3d : public segmentnd<T, 3>
  {
  public:
    //! Class constructor
    segment3d() : segmentnd<T, 3>() {}

    //! Class constructor
    segment3d(
        const T &x0, //<! Input x value for the first point
        const T &y0, //<! Input y value for the first point
        const T &z0, //<! Input z value for the first point
        const T &x1, //<! Input x value for the second point
        const T &y1, //<! Input y value for the second point
        const T &z1  //<! Input z value for the second point
        ) : segmentnd<T, 3>(x0, y0, z0, x1, y1, z1)
    {
    }

    //! Class constructor
    segment3d(
        const point3d<T> &point0, //!< Input 3-dimensional point
        const point3d<T> &point1  //!< Input 3-dimensional point
        ) : segmentnd<T, 3>(point0, point1)
    {
    }

    //! Class constructor
    segment3d(
        const pointnd<T, 3> &point0, //!< Input N-dimensional point
        const pointnd<T, 3> &point1  //!< Input N-dimensional point
        ) : segmentnd<T, 3>(point0, point1)
    {
    }

    //! Class constructor
    segment3d(
        const segmentnd<T, 3> &segment //!< Input N-dimensional segment
        ) : segmentnd<T, 3>(segment)
    {
    }

    //! Class constructor
    segment3d(
        const segment3d<T> &segment //!< Input 3-dimensional segment
        ) : segmentnd<T, 3>(segment)
    {
    }

    //! Class destructor
    ~segment3d() {}
  };

} // namespace acme

#endif

///
/// eof: acme_segment.hh
///