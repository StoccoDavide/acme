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
    vector _point0; //!< Point 0 (min)
    vector _point1; //!< Point 1 (max)
    int_type _id;   //!< Id of the box
    int_type _ipos; //!< Rank of the bounding box (used in external algorithms)

  public:
    //! Class destructor
    ~box() {}

    //! Copy constructor
    box(const box &) = default;

    //! Class constructor
    box() {}

    //! Class constructor
    box(
        const real_type &x0,      //<! Input x value of first point
        const real_type &y0,      //<! Input y value of first point
        const real_type &z0,      //<! Input z value of first point
        const real_type &x1,      //<! Input x value of second point
        const real_type &y1,      //<! Input y value of second point
        const real_type &z1,      //<! Input z value of second point
        const real_type id = 0,  //<! Input y value of second point
        const real_type ipos = 0 //<! Input z value of second point
        ) : _point0(vector(x0, y0, z0)), _point1(vector(x1, y1, z1)), _id(id), _ipos(ipos)
    {
    }

    //! Class constructor
    box(
        const vector &point0,     //!< Input
        const vector &point1,     //!< Input
        const real_type id = 0,  //<! Input y value of second point
        const real_type ipos = 0 //<! Input z value of second point
        ) : _point0(point0), _point1(point1), _id(id), _ipos(ipos)
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
        this->_point0 = input._point0;
        this->_point1 = input._point1;
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
      return acme::is_equal(this->_point0, input._point0) &&
             acme::is_equal(this->_point1, input._point1);
    }

    //! Check if box is degenerated
    bool is_degenerated(void)
        const
    {
      return acme::is_equal((this->_point0 - this->_point1).norm(), real_type(0.0));
    }

    //! Get first point
    const vector &point_0(void) const { return this->_point0; }

    //! Set first point
    void point_0(
        const vector &input //!< Input
    )
    {
      this->_point0 = input;
    }

    //! Get second point
    const vector &point_1(void) const { return this->_point1; }

    //! Set second point
    void point_1(
        const vector &input //!< Input
    )
    {
      this->_point1 = input;
    }

    //! Translate by vector
    void translate(
        const vector &input //!< Input
    )
    {
      this->_point0 = input + this->_point0;
      this->_point1 = input + this->_point1;
    }

    //! Rotate by matrix
    void rotate(
        const matrix &input //!< Input
    )
    {
      this->_point0 = input * this->_point0;
      this->_point1 = input * this->_point1;
    }

    //! Detect if boxes collide
    bool collision(
        const box &input //!< Input
    )
        const
    {
      return (this->_point0.x() <= input._point1.x() && this->_point1.x() >= input._point0.x()) &&
             (this->_point0.y() <= input._point1.y() && this->_point1.y() >= input._point0.y()) &&
             (this->_point0.z() <= input._point1.z() && this->_point1.z() >= input._point0.z());
    }

    //! Build box wirh a list of boxes
    void
    join(
        std::vector<boxPtr> const &boxes //!< Input poiter to vector of boxes
    )
    {
      if (boxes.empty())
      {
        this->_point0 = vector::Zero();
        this->_point1 = vector::Zero();
      }
      else
      {
        std::vector<boxPtr>::const_iterator it = boxes.begin();

        this->_point0 = (*it)->_point0;
        this->_point1 = (*it)->_point1;

        for (++it; it != boxes.end(); ++it)
        {
          box const &curBox = **it;
          if (curBox._point0.x() < _point0.x())
            _point0.x() = curBox._point0.x();
          if (curBox._point0.y() < _point0.y())
            _point0.y() = curBox._point0.y();
          if (curBox._point0.z() < _point0.z())
            _point0.z() = curBox._point0.z();
          if (curBox._point1.x() > _point1.x())
            _point1.x() = curBox._point1.x();
          if (curBox._point1.y() > _point1.y())
            _point1.y() = curBox._point1.y();
          if (curBox._point1.z() > _point1.z())
            _point1.z() = curBox._point1.z();
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
      vector center((this->_point1 + this->_point0) / 2);
      vector point1_centered(this->_point1 - center);
      vector point_centered(point - center);

      real_type x_scale = acme::abs(1.0 / point1_centered.x());
      real_type y_scale = acme::abs(1.0 / point1_centered.y());
      real_type z_scale = acme::abs(1.0 / point1_centered.z());

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
      real_type dx = max(abs(point.x() - this->_point0.x()), abs(point.x() - this->_point1.x()));
      real_type dy = max(abs(point.y() - this->_point0.y()), abs(point.y() - this->_point1.y()));
      real_type dz = max(abs(point.z() - this->_point0.z()), abs(point.z() - this->_point1.z()));
      return sqrt(dx * dx + dy * dy + dz * dz);
    }
  };

} // namespace acme

#endif

///
/// eof: acme_box.hh
///