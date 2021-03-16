///
/// file: ddd_matObject.hh
///

#ifndef INCLUDE_DDD_MATOBJECT
#define INCLUDE_DDD_MATOBJECT

#include "ddd_math.hh"

namespace ddd
{

  /*\
   |                   _    ___  _     _           _   
   |   _ __ ___   __ _| |_ / _ \| |__ (_) ___  ___| |_ 
   |  | '_ ` _ \ / _` | __| | | | '_ \| |/ _ \/ __| __|
   |  | | | | | | (_| | |_| |_| | |_) | |  __/ (__| |_ 
   |  |_| |_| |_|\__,_|\__|\___/|_.__// |\___|\___|\__|
   |                                |__/               
  \*/

  //! matObject class container
  /*!
  Base class constructed by a 3 by 3 Eigen matrix.
  */
  template <typename T = Float>
  class matObject
  {
  private:
    Eigen::Matrix<T, 3, 3> _data; //!< Data as Eigen 3 by 3 matrix

  protected:
    //! Class destructor
    ~matObject() {}

    //! Class constructor
    matObject() { this->clear(); }

  public:
    //! Clear data
    void clear()
    {
      for (std::size_t i = 0; i < 3; ++i)
      {
        for (std::size_t j = 0; j < 3; ++j)
        {
          this->_data[i, j] = T(0.0);
        }
      }
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
        const std::size_t &i, //!< Input index
        const std::size_t &j  //!< Input index
    )
    {
      return this->_data[i, j];
    }

    //! Indexing operator
    inline const T &operator[](
        const std::size_t &i, //!< Input index
        const std::size_t &j  //!< Input index
    )
        const
    {
      return this->_data[i, j];
    }

    //! Get x vector
    inline const T &x(void) const { return this->_data.col(0); }

    //! Get y vector
    inline const T &y(void) const { return this->_data.col(1); }

    //! Get z vector
    inline const T &z(void) const { return this->_data.col(2); }

    //! Get data
    inline const Eigen::Matrix<T, 3, 3> &data(void) const { return this->_data; }

    //! Set x vector
    inline void x(
        const vector<T> &input //!< Input vector
    )
    {
      this->_data.col(0) = input._data;
    }

    //! Set y vector
    inline void y(
        const vector<T> &input //!< Input vector
    )
    {
      this->_data.col(1) = input._data;
    }

    //! Set z vector
    inline void z(
        const vector<T> &input //!< Input vector
    )
    {
      this->_data.col(2) = input._data;
    }

    //! Set data
    inline void data(
        const Eigen::Matrix<T, 3, 3> &data //!< Input data
    )
    {
      this->_data = data;
    }

  }; // class matObject

} // namespace ddd

#endif

///
/// eof: ddd_matObject.hh
///