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

  //! Point class container
  template <typename T = Float>
  class point
  {
  protected:
    Eigen::Matrix<T, 3, 1> _data; //!< Point data as Eigen 3x1 column vector

  public:
    //! Class destructor
    ~point() {}

    //! Copy constructor
    point(const point<T> &) = default;

    //! Class constructor
    point() { clear(); }

    //! Class constructor
    point(
        const Eigen::Matrix<T, 3, 1> &data //!< Input data
    )
    {
      this->_data = data;
    }

    //! Class constructor
    point(
        const T &x, //!< Input x value
        const T &y, //!< Input y value
        const T &z  //!< Input z value
    )
    {
      this->_data[0] = x;
      this->_data[1] = y;
      this->_data[2] = z;
    }

    //! Clear vector _data
    void clear()
    {
      for (std::size_t i = 0; i < 3; ++i)
        this->_data[i] = T(0.0);
    }

    //! Equality operator
    inline point<T> &operator=(
        const point<T> &point //!< Input point object
    )
    {
      this->_data = point._data;
      return *this;
    }

    //! Indexing operator
    inline T &operator[](
        const std::size_t &i //!< Input index
    )
    {
      return _data[i];
    }

    //! Indexing operator
    inline const T &operator[](
        const std::size_t &i //!< Input index
    )
        const
    {
      return _data[i];
    }

    //! Get x coordinate
    inline const T &x(void) const { return _data.x(); }

    //! Get y coordinate
    inline const T &y(void) const { return _data.y(); }

    //! Get z coordinate
    inline const T &z(void) const { return _data.z(); }

    //! Radius vector of point
    inline const vector<T> &ToVector(void)
    {
      return new vector<T>(this);
    }

    //! Addition operator
    inline point<T> operator+(
        const point<T> &input //!< Input point object
    )
        const
    {
      return point<T>(this->_data + input._data);
    }

    //! Subtraction operator
    inline point<T> operator-(
        const point<T> &input //!< Input point object
    )
        const
    {
      return point<T>(this->_data - input._data);
    }

    //! Addition function
    void add(
        const point<T> &input //!< Input point object
    )
    {
      this->_data = this->_data + input._data;
    }

    //! Subtraction function
    inline void subtract(
        const point<T> &input //!< Input point object
    )
    {
      this->_data = this->_data - input._data;
    }

    //! Scalar product function
    inline void scalar(
        const T &value //!< Scalar value
    )
    {
      this->_data = this->_data * value;
    }

    //! Translate point by vector
    inline void translate(
        const vector<T> &input //!< Input vector object
    )
    {
      this->_data = this->_data + input._data;
    }

    //! Normalize point
    inline void normalize()
    {
      this->_data.norm();
    }

    //! Return normalized point
    inline const point<T> normalized()
        const
    {
      return this->_data.normalized();
    }

    //! Check if point is equal
    inline bool is_equal(
        const point<T> &input //!< Input point object
    )
        const
    {
      return ddd::is_equal((this->_data - input._data).norm(), T(0.0));
    }

    //! Equality operator
    inline bool operator==(
        const point<T> &input //!< Input point object
    )
    {
      return this->is_equal(input);
    }

    //! Disequality operator
    inline bool operator!=(
        const point<T> &input //!< Input point object
    )
    {
      return !(this == input);
    }

    //! Distance between two points
    inline const T distance(
        const point<T> &input //!< Input point object
    )
        const
    {
      if (!this->is_equal(input))
      {
        return (this->_data - input._data).norm();
      }
      else
      {
        return T(0.0);
      }
    }

    //! Squared distance between two points
    inline const T distanceSquared(
        const point<T> &input //!< Input point object
    )
    {
      if (!this->is_equal(input))
      {
        return (this - input).squaredNorm();
      }
      else
      {
        return T(0.0);
      }
    }

    /*/! Shortest distance to a line
    inline const T distance(
        const line<T> &input //!< Input line object
    )
    {
      //vector<> v = new Vector3d(this, l._point);
      //return v.Cross(l._dir).Norm / l._dir.Norm;
    }*/

    /*/! Shortest distance to a plane
    inline const T distance(
        const plane<T> &input //!< Input plane object
    )
    {
      return T(0.0);
    }*/

  }; // class point

} // namespace ddd

#endif

///
/// eof: ddd_point.hh
///