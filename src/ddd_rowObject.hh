///
/// file: ddd_rowObject.hh
///

#ifndef INCLUDE_DDD_ROWOBJECT
#define INCLUDE_DDD_ROWOBJECT

#include "ddd_math.hh"

namespace ddd
{

  /*\
   |                      ___  _     _           _   
   |   _ __ _____      __/ _ \| |__ (_) ___  ___| |_ 
   |  | '__/ _ \ \ /\ / / | | | '_ \| |/ _ \/ __| __|
   |  | | | (_) \ V  V /| |_| | |_) | |  __/ (__| |_ 
   |  |_|  \___/ \_/\_/  \___/|_.__// |\___|\___|\__|
   |                              |__/               
  \*/

  //! rowObject class container
  /*!
  Base class constructed by a 3 by 1 Eigen matrix.
  */
  template <typename T = Float>
  class rowObject
  {
  private:
    Eigen::Matrix<T, 3, 1> _data; //!< Data as Eigen 3x1 column vector

  protected:
    //! Class destructor
    ~rowObject() {}

    //! Class constructor
    rowObject() { this->clear(); }

  public:
    //! Clear data
    void clear()
    {
      for (std::size_t i = 0; i < 3; ++i)
        this->_data[i] = T(0.0);
    }

    //! Scale object
    inline void scale(
        const T &value //!< Scale value
    )
    {
      this->_data = this->_data * value;
    }

    //! Indexing operator
    inline T &operator[](
        const std::size_t &i //!< Input index
    )
    {
      return this->_data[i];
    }

    //! Indexing operator
    inline const T &operator[](
        const std::size_t &i //!< Input index
    )
        const
    {
      return this->_data[i];
    }

    //! Convert to vector
    inline const vector<T> toVector(void)
    {
      return vector<T>(this);
    }

    //! Convert to point
    inline const point<T> toPoint(void)
    {
      return point<T>(this);
    }

    //! Get x coordinate
    inline const T &x(void) const { return this->_data.x(); }

    //! Get y coordinate
    inline const T &y(void) const { return this->_data.y(); }

    //! Get z coordinate
    inline const T &z(void) const { return this->_data.z(); }

    //! Get data
    inline const Eigen::Matrix<T, 3, 1> &data(void) const { return this->_data; }

    //! Set x coordinate
    inline void x(
        const T &input //!< Input value
    )
    {
      this->_data[0] = input;
    }

    //! Set y coordinate
    inline void y(
        const T &input //!< Input value
    )
    {
      this->_data[1] = input;
    }

    //! Set z coordinate
    inline void z(
        const T &input //!< Input value
    )
    {
      this->_data[2] = input;
    }

    //! Set data
    inline void data(
        const Eigen::Matrix<T, 3, 1> &data //!< Input data
    )
    {
      this->_data = data;
    }

    //! Normalize object
    inline void normalize()
    {
      this->_data.normalize();
    }

    //! Return object norm
    inline const T &norm()
    {
      return this->_data.norm();
    }

  }; // class rowObject

} // namespace ddd

#endif

///
/// eof: ddd_rowObject.hh
///