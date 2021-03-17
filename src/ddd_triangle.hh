///
/// file: ddd_triangle.hh
///

#ifndef INCLUDE_DDD_TRIANGLE
#define INCLUDE_DDD_TRIANGLE

#include "ddd_point.hh"

namespace ddd
{

  /*\
   |   _        _                   _      
   |  | |_ _ __(_) __ _ _ __   __ _| | ___ 
   |  | __| '__| |/ _` | '_ \ / _` | |/ _ \
   |  | |_| |  | | (_| | | | | (_| | |  __/
   |   \__|_|  |_|\__,_|_| |_|\__, |_|\___|
   |                          |___/        
  \*/

  //! Triangle class container
  template <typename T = Float>
  class triangle
  {
  private:
  private:
    point<T> _point0; //!< Point 0
    point<T> _point1; //!< Point 1
    point<T> _point2; //!< Point 2

  public:
    //! Class destructor
    ~triangle() {}

    //! Copy constructor
    triangle(const triangle<T> &) = default;

    //! Class constructor
    triangle() {}

    //! Class constructor
    triangle(
        const T &x0, //<! Input x value of first point
        const T &y0, //<! Input y value of first point
        const T &z0, //<! Input z value of first point
        const T &x1, //<! Input x value of second point
        const T &y1, //<! Input y value of second point
        const T &z1, //<! Input z value of second point
        const T &x2, //<! Input x value of third point
        const T &y2, //<! Input y value of third point
        const T &z2  //<! Input z value of third point
        ) : _point0(point<T>(x0, y0, z0)), _point1(point<T>(x1, y1, z1)), _point2(point<T>(x2, y2, z2))
    {
    }

    //! Class constructor
    triangle(
        const point<T> &point0, //!< Input point object
        const point<T> &point1, //!< Input point object
        const point<T> &point2  //!< Input point object
        ) : _point0(point0), _point1(point1), _point2(point2)
    {
    }

    //! Class constructor
    triangle(
        const Eigen::Matrix<T, 3, 1> &point0, //!< Input point object
        const Eigen::Matrix<T, 3, 1> &point1, //!< Input point object
        const Eigen::Matrix<T, 3, 1> &point2  //!< Input point object
        ) : _point0(point0), _point1(point1), _point2(point2)
    {
    }

    //! Equality operator
    inline triangle<T> &operator=(
        const triangle<T> &input //!< Input segment object
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_point0(input._point0);
        this->_point1(input._point1);
        this->_point2(input._point2);
        return *this;
      }
    }

    //! Check if two rays are (exactly) equal
    inline bool operator==(
        const segment<T> &input //!< Input object
    )
    {
      return this->_point0 == input._point0 && this->_point1 == input._point1 && this->_point2 == input._point2;
    }

    //! Check if two rays are (exactly) NOT equal
    inline bool operator!=(
        const segment<T> &input //!< Input object
    )
    {
      return !(this == input);
    }

    //! Check if two rays are (almost) equal
    inline bool is_equal(
        const segment<T> &input //!< Input object
    )
        const
    {
      return this->_point0.is_equal(input._point0) && this->_point1.is_equal(input._point1) && this->_point2.is_equal(input._point2);
    }

    //! Check if triangle is degenerated
    inline bool is_degenerated(void)
        const
    {
      return this->direction().is_degenerated();
    }

    //! Get first point
    inline point<T> &point_1(void) const { return this->_point1; }

    //! Set first point
    inline void point_1(
        const point<T> &input //!< Input object
    )
    {
      this->_point1 = input;
    }

    //! Get second point
    inline point<T> &point_2(void) const { return this->_point2; }

    //! Set second point
    inline void point_2(
        const point<T> &input //!< Input object
    )
    {
      this->_point2 = input;
    }

    //! Get third point
    inline point<T> &point_3(void) const { return this->_point3; }

    //! Set third point
    inline void point_3(
        const point<T> &input //!< Input object
    )
    {
      this->_point3 = input;
    }

    //! Get first edge
    inline segment<T> &edge_1(void) const { return segment<T>(this->_point0, this->_point1); }

    //! Get second edge
    inline segment<T> &edge_2(void) const { return segment<T>(this->_point1, this->_point2); }

    //! Get third edge
    inline segment<T> &edge_3(void) const { return segment<T>(this->_point2, this->_point0); }

    //! Get triangle normal
    inline vector<T> &normal(void)
        const
    {
      return vector<T>((this->_point1.data() - this->_point0.data()).cross(this->_point2.data() - this->_point0.data()));
    }

    //! Get triangle normal
    inline Eigen::Matrix<T, 3, 1> &normalEigen(void)
        const
    {
      return (this->_point1.data() - this->_point0.data()).cross(this->_point2.data() - this->_point0.data());
    }

    //! Translate line by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_point0.translate(input);
      this->_point1.translate(input);
      this->_point2.translate(input);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const vector<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const line<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const ray<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const plane<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input);
    }

    //! Check if two objects are parallel
    inline bool is_parallel(
        const segment<T> &input //!< Input object
    )
        const
    {
      return (this->normal()).is_orthogonal(input.toVector());
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const vector<T> &input //!< Input vector object
    )
        const
    {
      return (this->normal()).is_parallel(input);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const line<T> &input //!< Input vector object
    )
        const
    {
      return (this->normal()).is_parallel(input);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const ray<T> &input //!< Input vector object
    )
        const
    {
      return (this->normal()).is_parallel(input);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const plane<T> &input //!< Input vector object
    )
        const
    {
      return(this->normal()).is_parallel(input);
    }

    //! Check if two objects are orthogonal
    inline bool is_orthogonal(
        const segment<T> &input //!< Input vector object
    )
        const
    {
      return (this->normal()).is_parallel(input.toVector());
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const vector<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const line<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const ray<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const plane<T> &input //!< Input object
    )
        const
    {
      return input.angle(this);
    }

    //! Angle between objects [rad]
    inline const T &angle(
        const segment<T> &input //!< Input object
    )
        const
    {
      return (this->toVector()).angle(input.toVector());
    }
  };

} // namespace ddd

#endif

///
/// eof: ddd_triangle.hh
///
