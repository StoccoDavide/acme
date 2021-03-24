///
/// file: acme_box.hh
///

/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(*                                                                     *)
(* Release Version 0.0.0                                               *)
(*                                                                     *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The acme computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the acme computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

#ifndef INCLUDE_ACME_BOX
#define INCLUDE_ACME_BOX

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |   _               
   |  | |__   _____  _ 
   |  | '_ \ / _ \ \/ /
   |  | |_) | (_) >  < 
   |  |_.__/ \___/_/\_\
   |                   
  \*/

  //! Box class container
  class box
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<box const> boxPtr;
#else
    typedef box const *boxPtr;
#endif

  private:
    vector _point_min; //!< Point 0 (min)
    vector _point_max; //!< Point 1 (max)
    int_type _id;      //!< Id of the box
    int_type _ipos;    //!< Rank of the bounding box (used in external algorithms)

  public:
    //! Class destructor
    ~box() {}

    //! Copy constructor
    box(const box &) = default;

    //! Class constructor
    box() {}

    //! Class constructor
    box(
        const real_type x0,      //<! Input x value of first point
        const real_type y0,      //<! Input y value of first point
        const real_type z0,      //<! Input z value of first point
        const real_type x1,      //<! Input x value of second point
        const real_type y1,      //<! Input y value of second point
        const real_type z1,      //<! Input z value of second point
        const real_type id = 0,  //<! Input y value of second point
        const real_type ipos = 0 //<! Input z value of second point
        ) : _point_min(vector(x0, y0, z0)), _point_max(vector(x1, y1, z1)), _id(id), _ipos(ipos)
    {
    }

    //! Class constructor
    box(
        const vector &point_min, //!< Input
        const vector &point_max, //!< Input
        const real_type id = 0,  //<! Input y value of second point
        const real_type ipos = 0 //<! Input z value of second point
        ) : _point_min(point_min), _point_max(point_max), _id(id), _ipos(ipos)
    {
    }

    //! Class constructor
    box(
        std::vector<boxPtr> const &boxes,
        const int_type id,
        const int_type ipos)
    {
      _id = id;
      _ipos = ipos;
      this->join(boxes);
    }

    //! Equality operator
    box &operator=(
        const box &input //!< Input
    )
    {
      if (this == &input)
      {
        return *this;
      }
      else
      {
        this->_point_min = input._point_min;
        this->_point_max = input._point_max;
        this->_id = input._id;
        this->_ipos = input._ipos;
        return *this;
      }
    }

    //! Check if objects are (almost) equal
    bool is_equal(
        const box &input //!< Input
    )
        const
    {
      return acme::is_equal(this->_point_min, input._point_min) &&
             acme::is_equal(this->_point_max, input._point_max);
    }

    //! Check if box is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_equal((this->_point_min - this->_point_max).norm(), real_type(0.0));
    }

    //! Check box max and min points
    bool check_max_min(void)
        const
    {
      return this->_point_max.x() >= this->_point_min.x() &&
             this->_point_max.y() >= this->_point_min.y() &&
             this->_point_max.z() >= this->_point_min.z();
    }

    //! Update and check box max and min points
    bool update_max_min(void)
    {
      bool output = true;
      real_type point_max_tmp, point_min_tmp;
      for (size_t i = 0; i < 3; ++i)
      {
        point_max_tmp = this->_point_max[i];
        point_min_tmp = this->_point_min[i];
        if (point_max_tmp < point_min_tmp)
        {
          this->_point_max[i] = point_min_tmp;
          this->_point_min[i] = point_max_tmp;
          output = false;
        }
      }
      return output;
    }

    //! Get min point
    const vector &point_min(void) const { return this->_point_min; }

    //! Get min point x value
    real_type x_min(void) const { return this->_point_min.x(); }

    //! Get min point y value
    real_type y_min(void) const { return this->_point_min.y(); }

    //! Get min point z value
    real_type z_min(void) const { return this->_point_min.z(); }

    //! Set min point
    void point_min(
        const vector &input //!< Input
    )
    {
      this->_point_min = input;
    }

    //! Set min point x value
    void x_min(
        const real_type input //!<Input
    )
    {
      this->_point_min.x() = input;
    }

    //! Set min point y value
    void y_min(
        const real_type input //!<Input
    )
    {
      this->_point_min.y() = input;
    }

    //! Set min point z value
    void z_min(
        const real_type input //!<Input
    )
    {
      this->_point_min.z() = input;
    }

    //! Get max point
    const vector &point_max(void) const { return this->_point_max; }

    //! Get max point x value
    real_type x_max(void) const { return this->_point_max.x(); }

    //! Get max point y value
    real_type y_max(void) const { return this->_point_max.y(); }

    //! Get max point z value
    real_type z_max(void) const { return this->_point_max.z(); }

    //! Set max point
    void point_max(
        const vector &input //!< Input
    )
    {
      this->_point_max = input;
    }

    //! Set max point x value
    void x_max(
        const real_type input //!<Input
    )
    {
      this->_point_max.x() = input;
    }

    //! Set max point y value
    void y_max(
        const real_type input //!<Input
    )
    {
      this->_point_max.y() = input;
    }

    //! Set max point z value
    void z_max(
        const real_type input //!<Input
    )
    {
      this->_point_max.z() = input;
    }

    //! Translate by vector
    void translate(
        const vector &input //!< Input
    )
    {
      this->_point_min = input + this->_point_min;
      this->_point_max = input + this->_point_max;
    }

    //! Rotate by matrix
    void rotate(
        const matrix &input //!< Input
    )
    {
      this->_point_min = input * this->_point_min;
      this->_point_max = input * this->_point_max;
    }

    //! Detect if boxes collide
    bool collision(
        const box &input //!< Input
    )
        const
    {
      return (this->_point_min.x() <= input._point_max.x() && this->_point_max.x() >= input._point_min.x()) &&
             (this->_point_min.y() <= input._point_max.y() && this->_point_max.y() >= input._point_min.y()) &&
             (this->_point_min.z() <= input._point_max.z() && this->_point_max.z() >= input._point_min.z());
    }

    //! Build box wirh a list of boxes
    void
    join(
        std::vector<boxPtr> const &boxes //!< Input poiter to vector of boxes
    )
    {
      if (boxes.empty())
      {
        this->_point_min = Zeros_vector;
        this->_point_max = Zeros_vector;
      }
      else
      {
        std::vector<boxPtr>::const_iterator it = boxes.begin();

        this->_point_min = (*it)->_point_min;
        this->_point_max = (*it)->_point_max;

        for (++it; it != boxes.end(); ++it)
        {
          box const &curBox = **it;
          if (curBox._point_min.x() < _point_min.x())
            _point_min.x() = curBox._point_min.x();
          if (curBox._point_min.y() < _point_min.y())
            _point_min.y() = curBox._point_min.y();
          if (curBox._point_min.z() < _point_min.z())
            _point_min.z() = curBox._point_min.z();
          if (curBox._point_max.x() > _point_max.x())
            _point_max.x() = curBox._point_max.x();
          if (curBox._point_max.y() > _point_max.y())
            _point_max.y() = curBox._point_max.y();
          if (curBox._point_max.z() > _point_max.z())
            _point_max.z() = curBox._point_max.z();
        }
      }
    }

    //! Distance of the point to the box
    real_type
    distance(
        const vector &point //!< Input
    )
        const
    {
      vector center((this->_point_max + this->_point_min) / 2);
      vector point_max_centered(this->_point_max - center);
      vector point_centered(point - center);

      real_type x_scale = acme::abs(1.0 / point_max_centered.x());
      real_type y_scale = acme::abs(1.0 / point_max_centered.y());
      real_type z_scale = acme::abs(1.0 / point_max_centered.z());

      real_type dx = acme::max(0.0, acme::abs(point_centered.x()) * x_scale - 1.0) / x_scale;
      real_type dy = acme::max(0.0, acme::abs(point_centered.y()) * y_scale - 1.0) / y_scale;
      real_type dz = acme::max(0.0, acme::abs(point_centered.z()) * z_scale - 1.0) / z_scale;

      return acme::sqrt(dx * dx + dy * dy + dz * dz);
    }

    //! Maximum distance of the point to the point of box
    real_type
    max_distance(
        const vector &point //!< Input
    ) const
    {
      real_type dx = max(abs(point.x() - this->_point_min.x()), abs(point.x() - this->_point_max.x()));
      real_type dy = max(abs(point.y() - this->_point_min.y()), abs(point.y() - this->_point_max.y()));
      real_type dz = max(abs(point.z() - this->_point_min.z()), abs(point.z() - this->_point_max.z()));
      return sqrt(dx * dx + dy * dy + dz * dz);
    }
  };

} // namespace acme

#endif

///
/// eof: acme_box.hh
///