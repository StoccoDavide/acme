/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                     *
 * The ACME project                                                    *
 *                                                                     *
 * Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *
 *                                                                     *
 * The ACME project and its components are supplied under the terms of *
 * the open source BSD 2-Clause License. The contents of the ACME      *
 * project and its components may not be copied or disclosed except in *
 * accordance with the terms of the BSD 2-Clause License.              *
 *                                                                     *
 * URL: https://opensource.org/licenses/BSD-2-Clause                   *
 *                                                                     *
 *    Davide Stocco                                                    *
 *    Department of Industrial Engineering                             *
 *    University of Trento                                             *
 *    e-mail: davide.stocco@unitn.it                                   *
 *                                                                     *
 *    Enrico Bertolazzi                                                *
 *    Department of Industrial Engineering                             *
 *    University of Trento                                             *
 *    e-mail: enrico.bertolazzi@unitn.it                               *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

///
/// file: parallel.cc
///

#include "acme.hh"

namespace acme
{

  /*\
   |   ____                 _ _      _
   |  |  _ \ __ _ _ __ __ _| | | ___| |
   |  | |_) / _` | '__/ _` | | |/ _ \ |
   |  |  __/ (_| | | | (_| | | |  __/ |
   |  |_|   \__,_|_|  \__,_|_|_|\___|_|
   |
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    entity const * entity0_in,
    entity const * entity1_in,
    real           tolerance
  )
  {
    #define CMD "acme::IsParallel(entity, entity): "
    
    integer slide = entity0_in->level() * 100 + entity1_in->level();
    switch (slide)
    {

      // - - - - - - - - - - - - - - LINE - - - - - - - - - - - - - -

    case 303:
      return IsParallel(
        *dynamic_cast<line const *>(entity0_in),
        *dynamic_cast<line const *>(entity1_in),
        tolerance);
      break;

    case 304:
      return IsParallel(
        *dynamic_cast<line const *>(entity0_in),
        *dynamic_cast<ray const *>(entity1_in),
        tolerance);
      break;

    case 305:
      return IsParallel(
        *dynamic_cast<line const *>(entity0_in),
        *dynamic_cast<plane const *>(entity1_in),
        tolerance);
      break;

    case 306:
      return IsParallel(
        *dynamic_cast<line const *>(entity0_in),
        *dynamic_cast<segment const *>(entity1_in),
        tolerance);
      break;

    case 307:
      return IsParallel(
        *dynamic_cast<line const *>(entity0_in),
        *dynamic_cast<triangle const *>(entity1_in),
        tolerance);
      break;

    case 308:
      return IsParallel(
        *dynamic_cast<line const *>(entity0_in),
        *dynamic_cast<disk const *>(entity1_in),
        tolerance);
      break;

      // - - - - - - - - - - - - - - RAY - - - - - - - - - - - - - -

    case 403:
      return IsParallel(
        *dynamic_cast<line const *>(entity1_in),
        *dynamic_cast<ray const *>(entity0_in),
        tolerance);
      break;

    case 404:
      return IsParallel(
        *dynamic_cast<ray const *>(entity0_in),
        *dynamic_cast<ray const *>(entity1_in),
        tolerance);
      break;

    case 405:
      return IsParallel(
        *dynamic_cast<ray const *>(entity0_in),
        *dynamic_cast<plane const *>(entity1_in),
        tolerance);
      break;

    case 406:
      return IsParallel(
        *dynamic_cast<ray const *>(entity0_in),
        *dynamic_cast<segment const *>(entity1_in),
        tolerance);
      break;

    case 407:
      return IsParallel(
        *dynamic_cast<ray const *>(entity0_in),
        *dynamic_cast<triangle const *>(entity1_in),
        tolerance);
      break;

    case 408:
      return IsParallel(
        *dynamic_cast<ray const *>(entity0_in),
        *dynamic_cast<disk const *>(entity1_in),
        tolerance);
      break;

      // - - - - - - - - - - - - - - PLANE - - - - - - - - - - - - - -

    case 503:
      return IsParallel(
        *dynamic_cast<line const *>(entity1_in),
        *dynamic_cast<plane const *>(entity0_in),
        tolerance);
      break;

    case 504:
      return IsParallel(
        *dynamic_cast<ray const *>(entity1_in),
        *dynamic_cast<plane const *>(entity0_in),
        tolerance);
      break;

    case 505:
      return IsParallel(
        *dynamic_cast<plane const *>(entity0_in),
        *dynamic_cast<plane const *>(entity1_in),
        tolerance);
      break;

    case 506:
      return IsParallel(
        *dynamic_cast<plane const *>(entity0_in),
        *dynamic_cast<segment const *>(entity1_in),
        tolerance);
      break;

    case 507:
      return IsParallel(
        *dynamic_cast<plane const *>(entity0_in),
        *dynamic_cast<triangle const *>(entity1_in),
        tolerance);
      break;

    case 508:
      return IsParallel(
        *dynamic_cast<plane const *>(entity0_in),
        *dynamic_cast<disk const *>(entity1_in),
        tolerance);
      break;

      // - - - - - - - - - - - - - - SEGMENT - - - - - - - - - - - - - -

    case 603:
      return IsParallel(
        *dynamic_cast<line const *>(entity1_in),
        *dynamic_cast<segment const *>(entity0_in),
        tolerance);
      break;

    case 604:
      return IsParallel(
        *dynamic_cast<ray const *>(entity1_in),
        *dynamic_cast<segment const *>(entity0_in),
        tolerance);
      break;

    case 605:
      return IsParallel(
        *dynamic_cast<plane const *>(entity1_in),
        *dynamic_cast<segment const *>(entity0_in),
        tolerance);
      break;

    case 606:
      return IsParallel(
        *dynamic_cast<segment const *>(entity0_in),
        *dynamic_cast<segment const *>(entity1_in),
        tolerance);
      break;

    case 607:
      return IsParallel(
        *dynamic_cast<segment const *>(entity0_in),
        *dynamic_cast<triangle const *>(entity1_in),
        tolerance);
      break;

    case 608:
      return IsParallel(
        *dynamic_cast<segment const *>(entity0_in),
        *dynamic_cast<disk const *>(entity1_in),
        tolerance);
      break;

      // - - - - - - - - - - - - - - TRIANGLE - - - - - - - - - - - - - -

    case 703:
      return IsParallel(
        *dynamic_cast<line const *>(entity1_in),
        *dynamic_cast<triangle const *>(entity0_in),
        tolerance);
      break;

    case 704:
      return IsParallel(
        *dynamic_cast<ray const *>(entity1_in),
        *dynamic_cast<triangle const *>(entity0_in),
        tolerance);
      break;

    case 705:
      return IsParallel(
        *dynamic_cast<plane const *>(entity1_in),
        *dynamic_cast<triangle const *>(entity0_in),
        tolerance);
      break;

    case 706:
      return IsParallel(
        *dynamic_cast<segment const *>(entity1_in),
        *dynamic_cast<triangle const *>(entity0_in),
        tolerance);
      break;

    case 707:
      return IsParallel(
        *dynamic_cast<triangle const *>(entity0_in),
        *dynamic_cast<triangle const *>(entity1_in),
        tolerance);
      break;

    case 708:
      return IsParallel(
        *dynamic_cast<triangle const *>(entity0_in),
        *dynamic_cast<disk const *>(entity1_in),
        tolerance);
      break;

      // - - - - - - - - - - - - - - DISK - - - - - - - - - - - - - -

    case 803:
      return IsParallel(
        *dynamic_cast<line const *>(entity1_in),
        *dynamic_cast<disk const *>(entity0_in),
        tolerance);
      break;

    case 804:
      return IsParallel(
        *dynamic_cast<ray const *>(entity1_in),
        *dynamic_cast<disk const *>(entity0_in),
        tolerance);
      break;

    case 805:
      return IsParallel(
        *dynamic_cast<plane const *>(entity1_in),
        *dynamic_cast<disk const *>(entity0_in),
        tolerance);
      break;

    case 806:
      return IsParallel(
        *dynamic_cast<segment const *>(entity1_in),
        *dynamic_cast<disk const *>(entity0_in),
        tolerance);
      break;

    case 807:
      return IsParallel(
        *dynamic_cast<triangle const *>(entity1_in),
        *dynamic_cast<disk const *>(entity0_in),
        tolerance);
      break;

    case 808:
      return IsParallel(
        *dynamic_cast<disk const *>(entity0_in),
        *dynamic_cast<disk const *>(entity1_in),
        tolerance);
      break;

      // - - - - - - - - - - - - - - DEFAULT - - - - - - - - - - - - - -

    default:
      // ACME_ERROR(CMD "exception not handled.")
      return false;
      break;
    }

    #undef CMD
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    vec3 const & vector0_in,
    vec3 const & vector1_in,
    real         tolerance
  )
  {
    return IsApprox(vector0_in.cross(vector1_in).norm(), real(0.0), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    vec3 const & vector_in,
    line const & line_in,
    real         tolerance
  )
  {
    return IsParallel(vector_in, line_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    vec3 const & vector_in,
    ray  const & ray_in,
    real         tolerance
  )
  {
    return IsParallel(vector_in, ray_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    vec3  const & vector_in,
    plane const & plane_in,
    real          tolerance
  )
  {
    return IsOrthogonal(vector_in, plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    vec3    const & vector_in,
    segment const & segment_in,
    real            tolerance
  )
  {
    return IsParallel(vector_in, segment_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    vec3     const & vector_in,
    triangle const & triangle_in,
    real             tolerance
  )
  {
    return IsOrthogonal(vector_in, triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    vec3 const & vector_in,
    disk const & disk_in,
    real         tolerance
  )
  {
    return IsOrthogonal(vector_in, disk_in.normal(), tolerance);
  }

  bool
  IsParallel(
    line const & line0_in,
    line const & line1_in,
    real         tolerance
  )
  {
    return IsParallel(line0_in.direction(), line1_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    ray const & ray0_in,
    ray const & ray1_in,
    real        tolerance
  )
  {
    return IsParallel(ray0_in.direction(), ray1_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    plane const & plane0_in,
    plane const & plane1_in,
    real          tolerance
  )
  {
    return IsParallel(plane0_in.normal(), plane1_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    segment const & segment0_in,
    segment const & segment1_in,
    real            tolerance
  )
  {
    return IsParallel(segment0_in.toUnitVector(), segment1_in.toUnitVector(), tolerance);
  }
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    triangle const & triangle0_in,
    triangle const & triangle1_in,
    real             tolerance
  )
  {
    return IsParallel(triangle0_in.normal(), triangle1_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    disk const & disk0_in,
    disk const & disk1_in,
    real         tolerance
  )
  {
    return IsParallel(disk0_in.normal(), disk1_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    line const & line_in,
    ray  const & ray_in,
    real         tolerance
  )
  {
    return IsParallel(line_in.direction(), ray_in.direction(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    line  const & line_in,
    plane const & plane_in,
    real          tolerance
  )
  {
    return IsOrthogonal(line_in.direction(), plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    line    const & line_in,
    segment const & segment_in,
    real            tolerance
  )
  {
    return IsParallel(line_in.direction(), segment_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    line     const & line_in,
    triangle const & triangle_in,
    real             tolerance
  )
  {
    return IsOrthogonal(line_in.direction(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    line const & line_in,
    disk const & disk_in,
    real         tolerance
  )
  {
    return IsOrthogonal(line_in.direction(), disk_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    ray   const & ray_in,
    plane const & plane_in,
    real          tolerance
  )
  {
    return IsOrthogonal(ray_in.direction(), plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    ray     const & ray_in,
    segment const & segment_in,
    real            tolerance
  )
  {
    return IsParallel(ray_in.direction(), segment_in.toUnitVector(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    ray      const & ray_in,
    triangle const & triangle_in,
    real             tolerance
  )
  {
    return IsOrthogonal(ray_in.direction(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    ray  const & ray_in,
    disk const & disk_in,
    real         tolerance
  )
  {
    return IsOrthogonal(ray_in.direction(), disk_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    plane   const & plane_in,
    segment const & segment_in,
    real            tolerance
  )
  {
    return IsOrthogonal(segment_in.toUnitVector(), plane_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    plane    const & plane_in,
    triangle const & triangle_in,
    real             tolerance
  )
  {
    return IsParallel(plane_in.normal(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    plane const & plane_in,
    disk  const & disk_in,
    real          tolerance
  )
  {
    return IsParallel(plane_in.normal(), disk_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    segment  const & segment_in,
    triangle const & triangle_in,
    real             tolerance
  )
  {
    return IsOrthogonal(segment_in.toUnitVector(), triangle_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    segment const & segment_in,
    disk    const & disk_in,
    real            tolerance
  )
  {
    return IsOrthogonal(segment_in.toUnitVector(), disk_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  IsParallel(
    triangle const & triangle_in,
    disk     const & disk_in,
    real             tolerance
  )
  {
    return IsParallel(triangle_in.normal(), disk_in.normal(), tolerance);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: parallel.cc
///