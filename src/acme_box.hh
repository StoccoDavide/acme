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

///
/// file: acme_box.hh
///

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
  /*!
  Box in 3D space and defined by a "maximum" and a "minimum" point.
  */
  class box
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<box const> boxPtr; //!< Shared pointer to box
#else
    typedef box const *boxPtr; //!< Pointer to box
#endif

  private:
    vec3 _point_min; //!< Point min
    vec3 _point_max; //!< Point max
    int_type _id;    //!< Id of the box
    int_type _ipos;  //!< Rank of the bounding box (used in external algorithms)

  public:
    //! Class destructor
    ~box() {}

    //! Copy constructor
    box(box const &) = default;

    //! Class constructor
    box() {}

    //! Class constructor
    box(
        real_type const x_min,   //<! Input x value of minimum point
        real_type const y_min,   //<! Input y value of minimum point
        real_type const z_min,   //<! Input z value of minimum point
        real_type const x_max,   //<! Input x value of maximum point
        real_type const y_max,   //<! Input y value of maximum point
        real_type const z_max,   //<! Input z value of maximum point
        real_type const id = 0,  //<! Input y value of second point
        real_type const ipos = 0 //<! Input z value of second point
        ) : _point_min(vec3(x_min, y_min, z_min)), _point_max(vec3(x_max, y_max, z_max)), _id(id), _ipos(ipos)
    {
    }

    //! Class constructor
    box(
        vec3 const &point_min,   //!< Input minimum point
        vec3 const &point_max,   //!< Input maximum point
        real_type const id = 0,  //<! Input y value of second point
        real_type const ipos = 0 //<! Input z value of second point
        ) : _point_min(point_min), _point_max(point_max), _id(id), _ipos(ipos)
    {
    }

    //! Class constructor
    box(
        std::vector<boxPtr> const &boxes,
        int_type const id,
        int_type const ipos)
    {
      _id = id;
      _ipos = ipos;
      this->join(boxes);
    }

    //! Equality operator
    box &operator=(
        box const &input //!< Input
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
        box const &input //!< Input
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
    vec3 const &point_min(void) const { return this->_point_min; }

    //! Get min point x value
    real_type x_min(void) const { return this->_point_min.x(); }

    //! Get min point y value
    real_type y_min(void) const { return this->_point_min.y(); }

    //! Get min point z value
    real_type z_min(void) const { return this->_point_min.z(); }

    //! Set min point
    void point_min(
        vec3 const &input //!< Input
    )
    {
      this->_point_min = input;
    }

    //! Set min point x value
    void x_min(
        real_type const input //!<Input
    )
    {
      this->_point_min.x() = input;
    }

    //! Set min point y value
    void y_min(
        real_type const input //!<Input
    )
    {
      this->_point_min.y() = input;
    }

    //! Set min point z value
    void z_min(
        real_type const input //!<Input
    )
    {
      this->_point_min.z() = input;
    }

    //! Get max point
    vec3 const &point_max(void) const { return this->_point_max; }

    //! Get max point x value
    real_type x_max(void) const { return this->_point_max.x(); }

    //! Get max point y value
    real_type y_max(void) const { return this->_point_max.y(); }

    //! Get max point z value
    real_type z_max(void) const { return this->_point_max.z(); }

    //! Set max point
    void point_max(
        vec3 const &input //!< Input
    )
    {
      this->_point_max = input;
    }

    //! Set max point x value
    void x_max(
        real_type const input //!<Input
    )
    {
      this->_point_max.x() = input;
    }

    //! Set max point y value
    void y_max(
        real_type const input //!<Input
    )
    {
      this->_point_max.y() = input;
    }

    //! Set max point z value
    void z_max(
        real_type const input //!<Input
    )
    {
      this->_point_max.z() = input;
    }

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    )
    {
      this->_point_min = input + this->_point_min;
      this->_point_max = input + this->_point_max;
    }

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    )
    {
      this->_point_min = input * this->_point_min;
      this->_point_max = input * this->_point_max;
    }

    //! Detect if boxes collide
    bool collision(
        box const &input //!< Input
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
        this->_point_min = Zeros_vec3;
        this->_point_max = Zeros_vec3;
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
    real_type distance(
        vec3 const &point //!< Input
    )
        const
    {
      vec3 center((this->_point_max + this->_point_min) / 2);
      vec3 point_max_centered(this->_point_max - center);
      vec3 point_centered(point - center);

      real_type x_scale = acme::abs(1.0 / point_max_centered.x());
      real_type y_scale = acme::abs(1.0 / point_max_centered.y());
      real_type z_scale = acme::abs(1.0 / point_max_centered.z());

      real_type dx = acme::max(0.0, acme::abs(point_centered.x()) * x_scale - 1.0) / x_scale;
      real_type dy = acme::max(0.0, acme::abs(point_centered.y()) * y_scale - 1.0) / y_scale;
      real_type dz = acme::max(0.0, acme::abs(point_centered.z()) * z_scale - 1.0) / z_scale;

      return acme::sqrt(dx * dx + dy * dy + dz * dz);
    }

    //! Maximum distance of the point to the point of box
    real_type max_distance(
        vec3 const &point //!< Input
    ) const
    {
      real_type dx = acme::max(acme::abs(point.x() - this->_point_min.x()), acme::abs(point.x() - this->_point_max.x()));
      real_type dy = acme::max(acme::abs(point.y() - this->_point_min.y()), acme::abs(point.y() - this->_point_max.y()));
      real_type dz = acme::max(acme::abs(point.z() - this->_point_min.z()), acme::abs(point.z() - this->_point_max.z()));
      return sqrt(dx * dx + dy * dy + dz * dz);
    }

  }; //class box

} // namespace acme

#endif

///
/// eof: acme_box.hh
///