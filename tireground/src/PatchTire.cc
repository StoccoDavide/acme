#include "PatchTire.hh"


namespace TireGround {

  /*\
   |         _                  _ _   _
   |    __ _| | __ _  ___  _ __(_) |_| |__  _ __ ___  ___
   |   / _` | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \/ __|
   |  | (_| | | (_| | (_) | |  | | |_| | | | | | | | \__ \
   |   \__,_|_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|___/
   |           |___/
  \*/

  namespace algorithms {

    vec3
    mean(
      row_vec3 const & Values
    ) {
      vec3 Mean(0.0, 0.0, 0.0);
      for (unsigned i = 0; i < Values.size() ; ++i)
        Mean += Values[i];
      return Mean /= Values.size();
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    real_type
    weightedMean(
      row_vecN const & Values,
      row_vecN const & Weights
    ) {
      RDF_ASSERT(Values.size() == Weights.size(), "Values and Weights must be of the same size.")
      real_type Mean = 0.0;
      for (unsigned i = 0; i < Values.size() ; ++i)
      {
        Mean += Values[i] * Weights[i];
      }
      return Mean /= Weights.sum();
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    vec3
    weightedMean(
      row_vec3 const & Values,
      row_vecN const & Weights
    ) {
      RDF_ASSERT(Values.size() == Weights.size(), "Values and Weights must be of the same size.")
      vec3 Mean = vec3(0.0, 0.0, 0.0);
      for (unsigned i = 0; i < Values.size() ; ++i)
      {
        Mean += Values[i] * Weights[i];
      }
      return Mean /= Weights.sum();
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    bool
    intersectPointSegment(
      vec2 const & Point_1,
      vec2 const & Point_2,
      vec2 const & Point
    ) {
      // A and B are the extremities of the current segment C
      // is the point to check.
      // Create the vector AB
      vec2 AB( Point_2 - Point_1 );
      // Create the vector AC
      vec2 AC( Point - Point_1 );
      // Compute the cross product of AB and AC
      // Check if the three points are aligned (cross product is null)
      real_type z = AB.x() * AC.y() - AC.x() * AB.y();
      if (abs(z*z) > epsilon) {
        RDF_ERROR("Cannot handle point-segment intersection!");
        return false;
      }
      // Compute the dot product of vectors
      real_type KAC = AB.dot(AC);
      if ( KAC      < -epsilon ) return false;
      if ( abs(KAC) < epsilon  ) return true;
      // Compute the square of the segment length
      real_type KAB = AB.dot(AB);
      if ( KAC > KAB ) return false;
      if ( abs(KAC - KAB) < epsilon ) return true;
      // The point is on the segment
      return true;
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    bool 
    intersectRayPlane(vec3 const & planeN,
                      vec3 const & planeP,
                      vec3 const & RayPoint,
                      vec3 const & RayDirection,
                      vec3       & IntersectionPt
    ) {
      // Check if the segment lays on the plane
      RDF_ASSERT( std::abs(planeN.dot(RayDirection)) > epsilon &&
                  std::abs((planeP - RayPoint).dot(planeN)) > epsilon,
                  "Cannot find proper contact point (ray lays on the plane)." );
      real_type d = - planeP.dot(planeN);
      real_type t = -(RayPoint.dot(planeN) + d) / (RayDirection.dot(planeN));
      if (t >= 0) {
        IntersectionPt = RayPoint + t * RayDirection;
        return true;
      } else {
        IntersectionPt = vec3_NaN;
        return false;
      }
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void
    minmax_XY(
      row_vec3 const & Points,
      vec2           & XYmin,
      vec2           & XYmax
    ) {
      XYmin = vec2( Points[0].x(), Points[0].y() );
      XYmax = vec2( Points[0].x(), Points[0].y() );
      for (unsigned i = 1; i < Points.cols(); ++i)
      {
        // Analize x value
        if ( Points[i].x() < XYmin.x() ) XYmin.x() = Points[i].x();
        if ( Points[i].x() > XYmax.x() ) XYmax.x() = Points[i].x();
        // Analize y value
        if ( Points[i].y() < XYmin.y() ) XYmin.y() = Points[i].y();
        if ( Points[i].y() > XYmax.y() ) XYmax.y() = Points[i].y();
      }
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void
    minmax_XY(
      row_vec2 const & Points,
      vec2           & XYmin,
      vec2           & XYmax
    ) {
      XYmin = XYmax = Points[0];
      for (unsigned i = 1; i < Points.cols(); ++i)
      {
        // Analize x value
        if ( Points[i].x() < XYmin.x() ) XYmin.x() = Points[i].x();
        if ( Points[i].x() > XYmax.x() ) XYmax.x() = Points[i].x();
        // Analize y value
        if ( Points[i].y() < XYmin.y() ) XYmin.y() = Points[i].y();
        if ( Points[i].y() > XYmax.y() ) XYmax.y() = Points[i].y();
      }
    }

  }  // namespace algorithms

  /*\
   |   ____  _     _
   |  |  _ \(_)___| | __
   |  | | | | / __| |/ /
   |  | |_| | \__ \   <
   |  |____/|_|___/_|\_\
  \*/

  void
  Disk::contactTriangles(
    RDF::TriangleRoad_list const & TriList,
    ReferenceFrame         const & RF,
    vec3                         & Normal,
    real_type                    & Friction,
    real_type                    & Area
  ) const {
    // Disk point and vector in absolute reference frame
    vec3 Disk_Point( RF.getOrigin() + RF.getRotationMatrix()*getOriginXYZ() );
    vec3 Disk_Normal( RF.getY() );
    // Reset Variables
    Normal = vec3( 0.0, 0.0, 0.0 );
    Friction = 0.0;
    Area = 0.0;
    real_type iArea = 0.0;
    std::vector<vec3> IntersectionPts;
    for (unsigned i = 0; i < TriList.size(); ++i) {
      if ( (*TriList[i]).intersectPlane(Disk_Normal, Disk_Point, IntersectionPts) ) {
        // Transform in Disk reference frame
        vec3 P1_rel( RF.getRotationMatrixInverse()*(IntersectionPts[0] - RF.getOrigin()) );
        vec3 P2_rel( RF.getRotationMatrixInverse()*(IntersectionPts[1] - RF.getOrigin()) );
        // Transfer only the XZ part (Y part must be = to OffsetY, so useless)
        iArea = getLineArea( vec2(P1_rel.x(),P1_rel.z()), vec2(P2_rel.x(),P2_rel.z()) );
        Area     += iArea; 
        Normal   += iArea * (*TriList[i]).getNormal();
        Friction += iArea * (*TriList[i]).getFriction();                  
        //RDF_ASSERT( abs(P1_rel.y()-OffsetY) < 10e10*epsilon && abs(P2_rel.y()-OffsetY) < 10e10*epsilon,
        //            "No match between Disk and segment Y value.");
      }
    }
    // If the Tire does not touch the ground, then the normal il the ground Z-axis and friction is 0
    if (Area > epsilon) {
      Normal   /= Area;
      Friction /= Area;
    } else {
      Normal   = vec3( 0.0, 0.0, 1.0 );
      Friction = 0.0;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  Disk::contactPlane( 
    vec3           const & Normal,
    vec3           const & Point,
    ReferenceFrame const & RF,
    real_type            & Area
  ) const {
    // Change reference frame for local road plane
    vec3 Normal_rel( (RF.getRotationMatrixInverse()*Normal).normalized() ) ;
    vec3 Point_rel( RF.getRotationMatrixInverse()*(Point - RF.getOrigin()) );
    // Check if two plane intersects and find the intersecting rect.
    vec3 P, T;
    if( intersectPlane( Normal_rel, Point_rel, T, P) ) {
      // Make a segment on the intersection (on relative Disk rerence frame)
      vec3 P1( P - 200.0*Radius*T );
      vec3 P2( P + 200.0*Radius*T );
      Area = getLineArea( vec2(P1.x(),P1.z()), vec2(P2.x(),P2.z()) );
    } else {
      RDF_ERROR("Cannot handle planes intersection");
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  Disk::pointOnDisk(
    vec3           const & Normal,
    ReferenceFrame const & RF,
    vec3                 & DiskPoint,
    vec3                 & NormalOnDisk
  ) const { 
    // Calculate the normal direction on the disk
    vec3 NormalDiskRF( RF.getRotationMatrixInverse()*Normal );
    NormalOnDisk = (RF.getRotationMatrix()*vec3( NormalDiskRF.x(), 0.0, NormalDiskRF.z())).normalized();
    // Calculate contact point on Disk (for Magic Formula)
    DiskPoint = RF.getOrigin() - NormalOnDisk * Radius;
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  real_type
  Disk::getLineArea(
    vec2      const & Point1_XZ,
    vec2      const & Point2_XZ
  ) const {
    vec2 Intersection_1, Intersection_2;
    int_type Type = this->intersectSegment(
      Point1_XZ, Point2_XZ, Intersection_1, Intersection_2
    );
    if ( Type == 0 ) {
      // No contact points, the line segment is not into the Disk
      return 0.0;
    } else if (Type == 1) {
      // Tangent, no area
      return 0.0;
    } else if (Type == 2) {
      // Check whether the two segment points are into the circle
      bool Pose_pt1 = this->isPointInside( Point1_XZ );
      bool Pose_pt2 = this->isPointInside( Point2_XZ );
      // Check whether the two intersection points are onto the line segment
      bool Pose_int1 = algorithms::intersectPointSegment(Point1_XZ, Point2_XZ, Intersection_1);
      bool Pose_int2 = algorithms::intersectPointSegment(Point1_XZ, Point2_XZ, Intersection_2);
      // Cases Pose_pt1 Pose_pt2 Pose_int1 Pose_int2
      // 0 0 1 1
      if ( !Pose_pt1 && !Pose_pt2 && Pose_int1 && Pose_int2 ) {
        return segmentArea( segmentLength(Intersection_2, Intersection_1) );
      // 0 1 0 1
      } else if ( !Pose_pt1 && Pose_pt2 && !Pose_int1 &&  Pose_int2 ) {
        return algorithms::trapezoidArea( 0.0, 
                                          Point2_XZ.y() - y(Point2_XZ.x()),
                                          abs((Intersection_2 - Point2_XZ).x()) )
                  + segmentArea( segmentLength(Intersection_2, Point2_XZ) );
      // 0 1 1 0
      } else if ( !Pose_pt1 && Pose_pt2 && Pose_int1 && !Pose_int2 ) {
        return algorithms::trapezoidArea( 0.0, 
                                          Point2_XZ.y() - y(Point2_XZ.x()),
                                          abs((Intersection_1 - Point2_XZ).x()) )
                + segmentArea( segmentLength(Intersection_1, Point2_XZ) );
      // 0 1 1 1 
      } else if ( !Pose_pt1 && Pose_pt2 && Pose_int1 && Pose_int2 ) {
        return segmentArea( segmentLength(Intersection_2, Intersection_1) );
      // 1 0 0 1
      } else if (  Pose_pt1 && !Pose_pt2 && !Pose_int1 && Pose_int2 ) {
        return algorithms::trapezoidArea( 0.0, 
                                          Point1_XZ.y() - y(Point1_XZ.x()),
                                          abs((Intersection_2 - Point1_XZ).x()) )
                + segmentArea( segmentLength(Intersection_2, Point1_XZ) );
      // 1 0 1 0
      } else if ( Pose_pt1 && !Pose_pt2 && Pose_int1 && !Pose_int2 ) {
        return algorithms::trapezoidArea( 0.0, 
                                          Point1_XZ.y() - y(Point1_XZ.x()),
                                          abs((Intersection_1 - Point1_XZ).x()) )
                + segmentArea( segmentLength(Intersection_1, Point1_XZ) );
      // 1 0 1 1
      } else if ( Pose_pt1 && !Pose_pt2 && Pose_int1 && Pose_int2 ) {
        return segmentArea( segmentLength(Intersection_2, Intersection_1) );
      // 1 1 0 0 
      } else if ( Pose_pt1 && Pose_pt2 && !Pose_int1 && !Pose_int2 ) {
        return algorithms::trapezoidArea( Point1_XZ.y() - y(Point1_XZ.x()), 
                                          Point2_XZ.y() - y(Point2_XZ.x()),
                                          abs((Point2_XZ - Point1_XZ).x()) )
                + segmentArea( segmentLength(Point2_XZ, Point1_XZ) );
      // 1 1 0 1
      } else if ( Pose_pt1 && Pose_pt2 && !Pose_int1 && Pose_int2 ) {
        return algorithms::trapezoidArea( Point1_XZ.y() - y(Point1_XZ.x()), 
                                          Point2_XZ.y() - y(Point2_XZ.x()),
                                          abs((Point2_XZ - Point1_XZ).x()) )
                + segmentArea( segmentLength(Point2_XZ, Point1_XZ) );
      // 1 1 1 0
      } else if ( Pose_pt1 && Pose_pt2 && Pose_int1 && !Pose_int2 ) {
        return algorithms::trapezoidArea( Point1_XZ.y() - y(Point1_XZ.x()), 
                                          Point2_XZ.y() - y(Point2_XZ.x()),
                                          abs((Point2_XZ - Point1_XZ).x()) )
                + segmentArea( segmentLength(Point2_XZ, Point1_XZ) );
      // 1 1 1 1
      } else if ( Pose_pt1 && Pose_pt2 && Pose_int1 && Pose_int2 ) {
        return segmentArea( segmentLength(Intersection_2, Intersection_1) );
      // 0 0 0 0
      // 0 0 0 1
      // 0 0 1 0
      // 0 1 0 0
      // 1 0 0 0
      } else {
        return 0.0;
      }
    } else {
      RDF_ERROR("Not handled intersection on Disk::getLineArea");
      return 0.0;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  bool
  Disk::isPointInside(
    vec2 const & Point
  ) const {
    vec2 PO( Point - OriginXZ );
    return PO.dot(PO) <= Radius*Radius;
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  int_type
  Disk::intersectSegment(
    vec2      const & Point_1,
    vec2      const & Point_2,
    vec2            & Intersect_1,
    vec2            & Intersect_2
  ) const {
    real_type t_param;
    vec2      d( Point_2 - Point_1 );
    vec2      P1O( Point_1 - OriginXZ );
    real_type A   = d.dot(d);
    real_type B   = 2 * d.dot(P1O);
    real_type C   = P1O.dot(P1O) - Radius*Radius;
    real_type discriminant = B*B - 4 * A * C;
    if ( A <= epsilon || discriminant < 0 ) {
      // No real solutions
      Intersect_1 = vec2(quietNaN, quietNaN);
      Intersect_2 = vec2(quietNaN, quietNaN);
      return 0;
    } else if ( std::abs(discriminant) < epsilon ) {
      // One solution
      t_param     = -B / (2*A);
      Intersect_1 = Point_1 + t_param * d;
      Intersect_2 = vec2(quietNaN, quietNaN);
      return 1;
    } else {
      // Two solutions
      t_param = (-B + std::sqrt(discriminant)) / (2 * A);
      Intersect_1 = Point_1 + t_param * d;
      t_param = (-B - std::sqrt(discriminant)) / (2 * A);
      Intersect_2 = Point_1 + t_param * d;
      return 2;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  bool
  Disk::intersectPlane(
    vec3 const & Plane_Normal,
    vec3 const & Plane_Point,
    vec3       & Line_Direction,
    vec3       & Line_Point
  ) const {
    // Plane(Point,Normal) and Disk intersection -> Parametric rect
    vec3 Disk_Point( getOriginXYZ() );
    vec3 Disk_Normal( 0.0, 1.0, 0.0 );
    // Rect direction
    Line_Direction = Plane_Normal.cross(Disk_Normal);
    // If the two plane are parallel they do not intersects
    if ( Line_Direction.norm() > 0) {
      real_type d_Disk = - Disk_Point.dot(Disk_Normal);
      real_type d_Plane = - Plane_Point.dot(Plane_Normal);
      vec3 u1( d_Disk * Plane_Normal );
      vec3 u2( -d_Plane * Disk_Normal );
      Line_Point = (u1 + u2).cross(Line_Direction) / Line_Direction.dot(Line_Direction);
      return true; 
    } else {
      return false;
    }
  }

  /*\
   |   ____       __                              _____
   |  |  _ \ ___ / _| ___ _ __ ___ _ __   ___ ___|  ___| __ __ _ _ __ ___   ___
   |  | |_) / _ \ |_ / _ \ '__/ _ \ '_ \ / __/ _ \ |_ | '__/ _` | '_ ` _ \ / _ \
   |  |  _ <  __/  _|  __/ | |  __/ | | | (_|  __/  _|| | | (_| | | | | | |  __/
   |  |_| \_\___|_|  \___|_|  \___|_| |_|\___\___|_|  |_|  \__,_|_| |_| |_|\___|
   |
  \*/

  real_type
  ReferenceFrame::getEulerAngleX(
    void
  ) const {
    real_type r21 = RotationMatrix(2, 1);
    if (r21 < 1.0) {
      if (r21 > -1.0) {
        return std::asin(r21);
      } else {  // r21 == -1.0
        // Not a unique solution : thetaY - thetaZ = atan2( r02 , r00 )
        return -G2lib::m_pi / 2.0;
      }
    } else {  // r21 == 1.0
      // Not a unique solution : thetaY + thetaZ = atan2( r02 , r00 )
      return G2lib::m_pi / 2.0;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  real_type
  ReferenceFrame::getEulerAngleY(
    void
  ) const {
    real_type r20 = RotationMatrix(2, 0);
    real_type r21 = RotationMatrix(2, 1);
    real_type r22 = RotationMatrix(2, 2);
    if (r21 < 1.0) {
      if (r21 > -1.0) {
        return std::atan2(-r20, r22);
      } else {  // r21 == -1.0
        // Not a unique solution : thetaY - thetaZ = atan2( r02 , r00 )
        return 0.0;
      }
    } else {  // r21 == 1.0
      // Not a unique solution : thetaY + thetaZ = atan2( r02 , r00 )
      return 0.0;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  real_type 
  ReferenceFrame::getEulerAngleZ(
    void
  ) const {
    real_type r00 = RotationMatrix(0, 0);
    real_type r01 = RotationMatrix(0, 1);
    real_type r02 = RotationMatrix(0, 2);
    real_type r11 = RotationMatrix(1, 1);
    real_type r21 = RotationMatrix(2, 1);
    if (r21 < 1.0) {
      if (r21 > -1.0) {
        return std::atan2(-r01, r11);
      } else {  // r21 == -1.0
        // Not a unique solution : thetaY - thetaZ = atan2( r02 , r00 )
        return -std::atan2(r02, r00);
      }
    } else {  // r21 == 1.0
      // Not a unique solution : thetaY + thetaZ = atan2( r02 , r00 )
      return std::atan2(r02, r00);
    }
  }

  /*\
  |   ____  _               _
  |  / ___|| |__   __ _  __| | _____      __
  |  \___ \| '_ \ / _` |/ _` |/ _ \ \ /\ / /
  |   ___) | | | | (_| | (_| | (_) \ V  V /
  |  |____/|_| |_|\__,_|\__,_|\___/ \_/\_/
 \*/

  void 
  Shadow::update(
      ETRTO          const & TireGeometry,
      ReferenceFrame const & RF
  ) {
    // Initalize variables
    vec2 XYmin_U, XYmax_U, XYmin_L, XYmax_L, XYmin, XYmax;
    std::vector<G2lib::BBox::PtrBBox> BBoxPtr(1);
    // Domain points in absolute reference frame
    real_type R = TireGeometry.getTireRadius();
    real_type S = TireGeometry.getSectionWidth();
    vec3      O = RF.getOrigin();
    mat3      M = RF.getRotationMatrix();
    // Upper side points
    row_vec3 XYZ_U(4);
    XYZ_U[0] = O + M * vec3( R, S, R),
    XYZ_U[1] = O + M * vec3( R,-S, R),
    XYZ_U[2] = O + M * vec3(-R, S, R),
    XYZ_U[3] = O + M * vec3(-R,-S, R);
    algorithms::minmax_XY( XYZ_U, XYmin_U, XYmax_U );
    BBoxPtr[0] = G2lib::BBox::PtrBBox(
        new G2lib::BBox(XYmin_U.x(), XYmin_U.y(), XYmax_U.x(), XYmax_U.y(), 0, 0) );
    TreePtr_U->build(BBoxPtr);

    // Lower side points
    row_vec3 XYZ_L(4);
    XYZ_L[0] = O + M * vec3( R, S,-R),
    XYZ_L[1] = O + M * vec3( R,-S,-R),
    XYZ_L[2] = O + M * vec3(-R, S,-R),
    XYZ_L[3] = O + M * vec3(-R,-S,-R);
    algorithms::minmax_XY( XYZ_L, XYmin_L, XYmax_L );
    BBoxPtr[0] = G2lib::BBox::PtrBBox(
        new G2lib::BBox(XYmin_L.x(), XYmin_L.y(), XYmax_L.x(), XYmax_L.y(), 0, 0) );
    TreePtr_L->build(BBoxPtr);

    // Total upper and lower side points
    row_vec2 XYZ(4);
    XYZ[0] = XYmin_U;
    XYZ[1] = XYmax_U;
    XYZ[2] = XYmin_L;
    XYZ[3] = XYmax_L;
    algorithms::minmax_XY( XYZ, XYmin, XYmax );
    BBoxPtr[0] = G2lib::BBox::PtrBBox(
        new G2lib::BBox(XYmin_L.x(), XYmin_L.y(), XYmax_L.x(), XYmax_L.y(), 0, 0) );
    TreePtr->build(BBoxPtr);
  }

    /*\
   |   _____ _          
   |  |_   _(_)_ __ ___ 
   |    | | | | '__/ _ \
   |    | | | | | |  __/
   |    |_| |_|_|  \___|
   |                    
  \*/

  bool
  Tire::pointSampling(
    RDF::TriangleRoad_list const & TriList,
    vec3                   const & RayOrigin,
    vec3                   const & RayDirection,
    vec3                         & SampledPt,
    real_type                    & TriFriction,
    vec3                         & TriNormal
  ) const {
    vec3 IntersectionPoint;
    std::vector<vec3> IntersectionPointVec, TriNormalVec;
    std::vector<real_type> TriFrictionVec;
    bool IntersectBool = false;
    for (unsigned t = 0; t < TriList.size(); ++t) {
      if ( (*TriList[t]).intersectRay(
              RayOrigin, RayDirection, IntersectionPoint) ) {
        IntersectionPointVec.push_back(IntersectionPoint);
        TriFrictionVec.push_back((*TriList[t]).getFriction());
        TriNormalVec.push_back((*TriList[t]).getNormal());
        IntersectBool = true;
      }
    }
    // Select the highest intersection point
    if (IntersectionPointVec.size() == 1 && IntersectBool){
      SampledPt   = IntersectionPointVec[0];
      TriFriction = TriFrictionVec[0];
      TriNormal   = TriNormalVec[0];
      return true;
    } else if (IntersectionPointVec.size() > 1 && IntersectBool) {
      SampledPt   = IntersectionPointVec[0];
      TriFriction = TriFrictionVec[0];
      TriNormal   = TriNormalVec[0];
      for (unsigned j = 1; j < IntersectionPointVec.size(); ++j) {
        if (IntersectionPointVec[j][2] > SampledPt[2]) {
          SampledPt   = IntersectionPointVec[j];
          TriFriction = TriFrictionVec[j];
          TriNormal   = TriNormalVec[j];
        }
      }
      return true;
    } else if (TriList.size() > 0 && !IntersectBool) {
      // Flying over the mesh
      return false;
    } else if (TriList.size() == 0) {
      // Out of mesh
      return false;
    } else {
      RDF_ERROR("Not handled consition");
      return false;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  Tire::getRelativeCamber(
    real_type & RelativeCamber
  ) const {
    mat4 PointRF;
    getMFpointRF(PointRF);
    mat3 RF_pc_wh( PointRF.block(0,0,3,3).transpose()*RF.getRotationMatrix() );
    real_type r21 = RF_pc_wh(2, 1);
    std::cout << "\nr21 = " << r21;
    if (r21 < 1.0) {
      if (r21 > -1.0) {
        RelativeCamber =  std::asin(r21);
      } else {  // r21 == -1.0
        // Not a unique solution : thetaY - thetaZ = atan2( r02 , r00 )
        RelativeCamber =  -G2lib::m_pi / 2.0;
      }
    } else {  // r21 == 1.0
      // Not a unique solution : thetaY + thetaZ = atan2( r02 , r00 )
      RelativeCamber =  G2lib::m_pi / 2.0;
    }
  }

  /*\
   |   __  __             _      _____                          _
   |  |  \/  | __ _  __ _(_) ___|  ___|__  _ __ _ __ ___  _   _| | __ _
   |  | |\/| |/ _` |/ _` | |/ __| |_ / _ \| '__| '_ ` _ \| | | | |/ _` |
   |  | |  | | (_| | (_| | | (__|  _| (_) | |  | | | | | | |_| | | (_| |
   |  |_|  |_|\__,_|\__, |_|\___|_|  \___/|_|  |_| |_| |_|\__,_|_|\__,_|
   |                |___/
  \*/

  void
  MagicFormula::getMFpointRF(
    mat4 & PointRF
  ) const {
    vec3 X_versor = (RF.getY().cross(Normal)).normalized();
    vec3 Y_versor = (Normal.cross(X_versor)).normalized();
    PointRF << X_versor, Y_versor, Normal, MeshPoint,
        vec4(0.0, 0.0, 0.0, 1.0).transpose();
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  bool
  MagicFormula::setup(
    RDF::MeshSurface       & Mesh,
    mat4             const & TM
  ) {
    // Set the new reference frame
    RF.setTotalTransformationMatrix(TM);
    // Tire Shadow update
    TireShadow.update(TireGeometry, RF);
    // Local intersected triangles vector
    RDF::TriangleRoad_list TriList;
    Mesh.intersectAABBtree(TireShadow.getAABBtree(), TriList);
    // End setup if there are no intersections
    if (TriList.size() < 1) {
      std::cout << "Warning: No mesh detected under the tire.";
      return false;
    } else {
      // Update the intersection
      evaluateContact(TriList);
      return true;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MagicFormula::setup(
    vec3      const & Plane_Normal,
    vec3      const & Plane_Point,
    real_type const   Plane_Friction,
    mat4      const & TM
  ) {
    // Update the intersection
    vec3 NormalOnDisk, DiskOrigin;
    // Set the new reference frame
    RF.setTotalTransformationMatrix(TM);
    // Tire Shadow update
    TireShadow.update(TireGeometry, RF);
    // Local friction update
    Friction = Plane_Friction;
    // Local normal update
    Normal = Plane_Normal;
    // Local plane intersection
    SingleDisk.contactPlane( Plane_Normal, Plane_Point, RF, Area );
    // Calculate contact points on Disk (for Magic Formula)
    SingleDisk.pointOnDisk( Plane_Normal, RF, DiskPoint, NormalOnDisk ); 
    // Calculate contact points on MeshSurface (not for Magic Formula)
    algorithms::intersectRayPlane( Plane_Normal, Plane_Point, RF.getOrigin(), -NormalOnDisk, MeshPoint );
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MagicFormula::print(
    ostream_type & stream
  ) const {
    real_type Rho = 0.0;
    real_type RhoDot = 0.0;
    getRho(Rho, RhoDot, 0, 0.001);
    real_type Area = 0.0;
    getArea(Area);
    real_type newFriction = 0.0;
    getFriction(newFriction);
    real_type Volume = 0.0;
    getVolume(Volume);
    real_type RelativeCamber = 0.0;
    getRelativeCamber(RelativeCamber);
    mat4 PointRF;
    getMFpointRF(PointRF);
    stream << "MAGIC FORMULA CONTACT PARAMETERS\n"
           << "\tYaw angle\n"
           << "\tα = " << getEulerAngleZ() / G2lib::m_pi << "pi rad\n"
           << "\tRotation angle\n"
           << "\tß = " << getEulerAngleY() / G2lib::m_pi << "pi rad\n"
           << "\tCamber angle\n"
           << "\tΓ = " << getEulerAngleX() / G2lib::m_pi << "pi rad\n"
           << "\tNormal contact point vector of the local track plane "
             "(absolute reference frame)\n"
           << "\tN = [ " << Normal.x() << ", " << Normal.y()
           << ", " << Normal.z() << " ]\n"
           << "\tLocal contact point on mesh (absolute reference frame)\n"
           << "\tP = [ " << MeshPoint.x() << ", " << MeshPoint.y()
           << ", " << MeshPoint.z() << " ]\n"
           << "\tLocal contact point reference frame\n"
           << PointRF << "\n"
           << "\tRelative camber angle\n"
           << "\tß = " << RelativeCamber / G2lib::m_pi << "pi rad\n"
           << "\tLocal contact point friction\n"
           << "\tf = " << newFriction << "\n"
           << "\tLocal contact depth (on center point) Rho\n"
           << "\tD = " << Rho << " m\n"
           << "\tLocal contact depth time derivative (on center point)\n"
           << "\tD = " << RhoDot << " m/s\n"
           << "\tLocal approximated contact area\n"
           << "\tA = " << Area << " m^2\n"
           << "\tLocal approximated total contact volume\n"
           << "\tV = " << Volume << " m^3\n\n";
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MagicFormula::evaluateContact(
    RDF::TriangleRoad_list const & TriList
  ) {
    // Update the intersection
    vec3 NormalOnDisk;
    if (TriList.size() < Precision.getSwitchNumber()) {
      // With triangles intersection
      SingleDisk.contactTriangles( TriList, RF, Normal, Friction, Area );
      // Calculate contact points on Disk (not for Magic Formula)
      SingleDisk.pointOnDisk( Normal, RF, DiskPoint, NormalOnDisk ); 
      // Calculate contact points on MeshSurface (for Magic Formula)
      pointSampling( TriList, RF.getOrigin(), -NormalOnDisk, MeshPoint );
    } else {
      // With local plane intersection
      vec3 planePoint;
      fourPointsSampling(TriList, planePoint );
      SingleDisk.contactPlane( Normal, planePoint, RF, Area );
      // Calculate contact points on Disk (not for Magic Formula)
      SingleDisk.pointOnDisk( Normal, RF, DiskPoint, NormalOnDisk ); 
      // Calculate contact points on MeshSurface (for Magic Formula)
      algorithms::intersectRayPlane( Normal, planePoint, RF.getOrigin(), -NormalOnDisk, MeshPoint );
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MagicFormula::fourPointsSampling(
    RDF::TriangleRoad_list const & TriList,
    vec3                         & planePoint
  ) {
    // Calculate Delta_X and Delta_Y
    real_type Delta_X = 0.1 * TireGeometry.getTireRadius();
    real_type Delta_Y = 0.3 * TireGeometry.getSectionWidth();
    // Store the four sample positions
    row_vec3 Qpos(4);
    Qpos[0] = RF.getOrigin() + RF.getRotationMatrix() * vec3(Delta_X, 0.0, 0.0);
    Qpos[1] = RF.getOrigin() - RF.getRotationMatrix() * vec3(Delta_X, 0.0, 0.0);
    Qpos[2] = RF.getOrigin() + RF.getRotationMatrix() * vec3(0.0, Delta_Y, 0.0);
    Qpos[3] = RF.getOrigin() - RF.getRotationMatrix() * vec3(0.0, Delta_Y, 0.0);
    // Find intersection in the four positions
    real_type iFriction;
    Friction = 0.0;
    row_vec3 Qvec(4);
    for (unsigned i = 0; i < 4; ++i) {
      pointSampling(TriList, Qpos[i], -RF.getZ(), Qvec[i], iFriction);
      Friction += iFriction;
    }
    // Calculate the contact point friction
    Friction /= 4.0;
    // Calculate normal of the local track plane
    Normal = ((Qvec[0] - Qvec[1]).cross(Qvec[2] - Qvec[3])).normalized();
    // Calculate first guess of local contact point
    planePoint = vec3(0.0, 0.0, 0.0);
    for (unsigned i = 0; i < 4; ++i)
      planePoint += Qvec[i];
    planePoint /= 4.0;
  }

  void
  MagicFormula::getRho(
    real_type       & Rho,
    real_type       & RhoDot,
    real_type const   RhoOld,
    real_type const   Time
  ) const {
    Rho = TireGeometry.getTireRadius()-(RF.getOrigin()-MeshPoint).norm();
    if (Rho > 0) {
      RhoDot = (Rho - RhoOld) / Time;
    } else {
      Rho    = 0.0;
      RhoDot = 0.0;
    }
  }

  /*\
   |   __  __       _ _   _ ____  _     _    
   |  |  \/  |_   _| | |_(_)  _ \(_)___| | __
   |  | |\/| | | | | | __| | | | | / __| |/ /
   |  | |  | | |_| | | |_| | |_| | \__ \   < 
   |  |_|  |_|\__,_|_|\__|_|____/|_|___/_|\_\
   |                                         
  \*/

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  bool
  MultiDisk::setup(
    RDF::MeshSurface       & Mesh,
    mat4             const & TM
  ) {
    // Set the new reference frame
    RF.setTotalTransformationMatrix(TM);
    // Tire Shadow update
    TireShadow.update(TireGeometry, RF);
    // Local intersected triangles vector
    RDF::TriangleRoad_list TriList;
    Mesh.intersectAABBtree(TireShadow.getAABBtree(), TriList);
    // End setup if there are no intersections
    int_type TriSize = TriList.size();
    if (TriSize < 1) {
      std::cout << "Warning: No mesh detected under the tire.";
      return false;
    } else {
      // Update the intersection
      if (TriList.size() < 1) {
        std::cout << "Warning: No mesh detected under the tire.";
        return false;
      } else {
        // Update the intersection
        evaluateContact(TriList);
        return true;
      }
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::setup(
    vec3      const & Plane_Normal,
    vec3      const & Plane_Point,
    real_type const   Plane_Friction,
    mat4      const & TM
  ) {
    // Set the new reference frame
    RF.setTotalTransformationMatrix(TM);
    // Tire Shadow update
    TireShadow.update(TireGeometry, RF);
    // Update the intersection
    vec3 NormalOnDisk, DiskOrigin;
    for (unsigned i = 0; i < DiskVec.size(); ++i) {
      // Local friction update
      FrictionVec[i] = Plane_Friction;
      // Local normal update
      NormalVec[i] = Plane_Normal;
      // Local plane intersection
      DiskVec[i].contactPlane( NormalVec[i], Plane_Point, RF, AreaVec[i] );
      // Calculate contact points on Disk (not for Magic Formula)
      DiskVec[i].pointOnDisk( NormalVec[i], RF, DiskPointVec[i], NormalOnDisk ); 
      // Calculate contact points on MeshSurface (for Magic Formula)
      DiskOrigin = RF.getOrigin() + RF.getRotationMatrix()*DiskVec[i].getOriginXYZ();
      algorithms::intersectRayPlane( NormalVec[i], Plane_Point, DiskOrigin, -NormalOnDisk, MeshPointVec[i] );
    }
    // Update local plane normal point
    Normal = Plane_Normal;
    // Calculate MFpoint arm and effective radius
    real_type effectiveY, effectiveR;
    this->getMFeffectiveY(effectiveY);
    this->getMFeffectiveR(effectiveR);
    // Calculate contact points on Disk (not for Magic Formula)
    DiskPoint = RF.getOrigin() + RF.getRotationMatrix()*vec3(0,effectiveY,0) - NormalOnDisk*effectiveR;
    // Calculate effective contact point (for Magic Formula)
    real_type Rho = 0.0;
    real_type RhoDot = 0.0;
    this->getRho(Rho, RhoDot, 0.0, 0.1);
    MFpoint = RF.getOrigin() - NormalOnDisk * (TireGeometry.getTireRadius()-Rho);
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


  void
  MultiDisk::getFriction(
    real_type & _Friction //!< Area weighted mean contact friction
  ) const {
    if (AreaVec.sum() > epsilon) {
      _Friction = algorithms::weightedMean(FrictionVec, AreaVec);
    } else {
      _Friction = 0.0;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::getMFeffectiveRF(
    mat4 & PointRF //!< Magic Formula contact point reference frame
  ) const {
    vec3 X_versor = (RF.getY().cross(Normal)).normalized();
    vec3 Y_versor = (Normal.cross(X_versor)).normalized();
    PointRF << X_versor, Y_versor, Normal, DiskPoint,
               vec4(0.0, 0.0, 0.0, 1.0).transpose();
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::getMFpointRF(
    mat4 & PointRF
  ) const {
    vec3 X_versor = (RF.getY().cross(Normal)).normalized();
    vec3 Y_versor = (Normal.cross(X_versor)).normalized();
    PointRF << X_versor, Y_versor, Normal, MFpoint,
               vec4(0.0, 0.0, 0.0, 1.0).transpose();
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::getDiskMFpointRF(
    int_type const   i,
    mat4           & PointRF
  ) const {
    vec3 X_versor = (RF.getY().cross(NormalVec(i))).normalized();
    vec3 Y_versor = (NormalVec(i).cross(X_versor)).normalized();
    PointRF << X_versor, Y_versor, NormalVec(i), DiskPointVec(i),
               vec4(0.0, 0.0, 0.0, 1.0).transpose();
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::getRho(
    real_type       & Rho,
    real_type       & RhoDot,
    real_type const   RhoOld,
    real_type const   Time
  ) const {
    row_vecN RhoVec( Precision.getDisksNumber() );
    row_vecN RhoDotVec = row_vecN::Zero( Precision.getDisksNumber() );
    row_vecN RhoOldVec = row_vecN::Zero( Precision.getDisksNumber() );
    getRho(RhoVec, RhoDotVec, RhoOldVec, 0.1);
    Rho = algorithms::weightedMean(RhoVec, AreaVec);
    if ( AreaVec.sum() < 1e-6 ) {
      Rho    = 0.0;
      RhoDot = 0.0;
    } else {
      RhoDot = (Rho - RhoOld) / Time;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::getRho(
    row_vecN        & Rho,
    row_vecN        & RhoDot,
    row_vecN  const   RhoOld,
    real_type const   Time
  ) const {
    for (unsigned i = 0; i < DiskVec.size(); ++i)
      this->getDiskRho(i, Rho[i], RhoDot[i], RhoOld[i], Time);
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::getDiskRho(
    int_type  const   i,
    real_type       & Rho,
    real_type       & RhoDot,
    real_type const   RhoOld,
    real_type const   Time
  ) const {
    Rho = DiskVec[i].getRadius()
          - ((RF.getOrigin()+RF.getRotationMatrix()*DiskVec[i].getOriginXYZ())-MeshPointVec[i]).norm();
    if (Rho > 0) {
      RhoDot = (Rho - RhoOld) / Time;
    } else {
      Rho    = 0.0;
      RhoDot = 0.0;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::getMFeffectiveY(
    real_type & effectiveY
  ) const {
    row_vecN effectiveYVec( DiskVec.size() );
    for (unsigned i = 0; i < DiskVec.size(); ++i)
      effectiveYVec[i] = DiskVec[i].getOffsetY();
    effectiveY = algorithms::weightedMean(effectiveYVec, AreaVec);
    if ( std::isnan(effectiveY) ) {
      effectiveY = 0.0;
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::getMFeffectiveR(
    real_type & Radius
  ) const {
    row_vecN RadiusVec( DiskVec.size() );
    for (unsigned i = 0; i < DiskVec.size(); ++i)
      RadiusVec[i] = DiskVec[i].getRadius();
    Radius = algorithms::weightedMean(RadiusVec, AreaVec);
    if ( std::isnan(Radius) ) {
      Radius = TireGeometry.getTireRadius();
    }
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::print(
    ostream_type & stream
  ) const {
    real_type Rho = 0.0;
    real_type RhoDot = 0.0;
    getRho(Rho, RhoDot, 0, 0.001);
    row_vecN RhoVec( Precision.getDisksNumber() );
    row_vecN RhoDotVec = row_vecN::Zero( Precision.getDisksNumber() );
    row_vecN RhoOldVec = row_vecN::Zero( Precision.getDisksNumber() );
    getRho(RhoVec, RhoDotVec, RhoOldVec, 0.1);
    real_type newFriction = 0.0;
    getFriction(newFriction);
    row_vecN newFrictionVec( Precision.getDisksNumber() );
    getFriction(newFrictionVec);
    real_type Area = 0.0;
    getArea(Area);
    real_type Volume = 0.0;
    getVolume(Volume);
    row_vecN VolumeVec( Precision.getDisksNumber() );
    getVolume(VolumeVec);
    real_type RelativeCamber = 0.0;
    getRelativeCamber(RelativeCamber);
    mat4 PointRF;
    getMFpointRF(PointRF);
    real_type MFarm, MFradius;
    getMFeffectiveY(MFarm);
    getMFeffectiveR(MFradius);
    stream << "MULTIDISK CONTACT PARAMETERS\n"
           << "\tYaw angle\n"
           << "\tα = " << getEulerAngleZ() / G2lib::m_pi << "pi rad\n"
           << "\tRotation angle\n"
           << "\tß = " << getEulerAngleY() / G2lib::m_pi << "pi rad\n"
           << "\tCamber angle\n"
           << "\tΓ = " << getEulerAngleX() / G2lib::m_pi << "pi rad\n"
           << "\tNormal contact point vector of the local track plane (absolute reference frame)\n"
           << "\tN = [ " << Normal.x() << ", " << Normal.y()
           << ", " << Normal.z() << " ]\n"
           << "\tLocal contact point on mesh (absolute reference frame)\n"
           << "\tP = [ " << MFpoint.x() << ", " << MFpoint.y()
           << ", " << MFpoint.z() << " ]\n"
           << "\tLocal contact point reference frame\n"
           << PointRF << "\n"
           << "\tLocal contact point Y-axis coordinate\n"
           << "\tY = " << MFarm << " m\n"
           << "\tLocal contact point effecrive radius (from tire RF)\n"
           << "\tR = " << MFradius << " m\n"
           << "\tTire radius\n"
           << "\tR = " << TireGeometry.getTireRadius() << " m\n"
           << "\tRelative camber angle\n"
           << "\tß = " << RelativeCamber / G2lib::m_pi << "pi rad\n"
           << "\tLocal contact point friction\n"
           << "\tf = " << newFriction << "\n"
           << "\tLocal contact point friction vector\n"
           << "\tf = " << newFrictionVec << "\n"
           << "\tLocal contact depth (on center point)\n"
           << "\tD = " << Rho << " m\n"
           << "\tLocal contact depth time derivative (on center point)\n"
           << "\tD = " << RhoDot << " m/s\n"
           << "\tLocal contact depth vector\n"
           << "\tD = " << RhoVec << " m\n"
           << "\tLocal approximated mean contact area\n"
           << "\tA = " << Area << " m^2\n"
           << "\tLocal approximated contact area vector\n"
           << "\tA = " << AreaVec << " m^2\n"
           << "\tLocal approximated total contact volume\n"
           << "\tV = " << Volume << " m^3\n"
           << "\tLocal approximated contact volume vector\n"
           << "\tV = " << VolumeVec << " m^3\n\n";
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::evaluateContact(
    RDF::TriangleRoad_list const & TriList
  ) {
    // Update the intersection
    vec3 NormalOnDisk, DiskOrigin;
    if (TriList.size() < Precision.getSwitchNumber()) {
      for (unsigned i = 0; i < DiskVec.size(); ++i)
      {
        // With triangles intersection
        DiskVec[i].contactTriangles( TriList, RF, NormalVec[i], FrictionVec[i], AreaVec[i] );
        // Calculate contact points on Disk (for Magic Formula)
        DiskVec[i].pointOnDisk( NormalVec[i], RF, DiskPointVec[i], NormalOnDisk );
        // Calculate contact points on MeshSurface (not for Magic Formula)
        DiskOrigin = RF.getOrigin() + RF.getRotationMatrix()*DiskVec[i].getOriginXYZ();
        pointSampling( TriList, DiskOrigin, -NormalOnDisk, MeshPointVec[i] );

      }
    } else {
      row_vec3 planePointVec( Precision.getDisksNumber() );
      for (unsigned i = 0; i < DiskVec.size(); ++i)
      {
        // With local plane intersection
        gridSampling(TriList, planePointVec);
        DiskVec[i].contactPlane( NormalVec[i], planePointVec[i], RF, AreaVec[i] );
        // Calculate contact points on Disk (not for Magic Formula)
        DiskVec[i].pointOnDisk( NormalVec[i], RF, DiskPointVec[i], NormalOnDisk );
        // Calculate contact points on MeshSurface (for Magic Formula)
        DiskOrigin = RF.getOrigin() + RF.getRotationMatrix()*DiskVec[i].getOriginXYZ();
        algorithms::intersectRayPlane( NormalVec[i], planePointVec[i], DiskOrigin, -NormalOnDisk, MeshPointVec[i] );
      }
    }
    // If the Tire does not touch the ground then the normal il the ground Z-axis
    if (AreaVec.sum() > epsilon) {
      Normal = algorithms::weightedMean(NormalVec, AreaVec);
    } else {
      Normal = vec3( 0.0, 0.0, 1.0 );
    }
    // Calculate normal vector on Disk
    DiskVec[0].pointOnDisk( Normal, RF, DiskPointVec[0], NormalOnDisk ); 
    // Calculate MFpoint arm and effective radius
    real_type effectiveY, effectiveR;
    this->getMFeffectiveY(effectiveY);
    this->getMFeffectiveR(effectiveR);
    // Calculate contact point on Disk (not for Magic Formula)
    DiskPoint = RF.getOrigin() + RF.getRotationMatrix()*vec3(0,effectiveY,0) - NormalOnDisk*effectiveR;
    // Calculate effective contact point on Disk (for Magic Formula)
    real_type Rho = 0.0;
    real_type RhoDot = 0.0;
    this->getRho(Rho, RhoDot, 0.0, 0.1);
    MFpoint = RF.getOrigin() - NormalOnDisk * (TireGeometry.getTireRadius()-Rho);
  }

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  void
  MultiDisk::gridSampling(
    RDF::TriangleRoad_list const & TriList,
    row_vec3                     & planePointVec
   ) {
    // Initialize variables
    real_type iDiskFriction, DiskFriction;
    vec3 iDiskNormal, DiskNormal, iDiskPoint, DiskPoint;
    // Storing indexers
    unsigned i = 0;
    unsigned j = 0;
    real_type DiskStep = this->getDiskStep();
    real_type SectionWidth_2_DS = TireGeometry.getSectionWidth() / 2.0 - DiskStep / 2.0;
    real_type SectionWidth_2 = TireGeometry.getSectionWidth() / 2.0;
    real_type Radius = TireGeometry.getTireRadius();
    vec3 zAxis(-RF.getZ());
    // Sample on grid pattern
    for ( real_type y = -SectionWidth_2_DS;
            y <= SectionWidth_2;
            y += DiskStep, ++j ) {
      iDiskFriction = 0.0;
      DiskFriction  = 0.0;
      iDiskNormal   = vec3(0.0, 0.0, 0.0);
      DiskNormal    = vec3(0.0, 0.0, 0.0);
      iDiskNormal   = vec3(0.0, 0.0, 0.0);
      DiskNormal    = vec3(0.0, 0.0, 0.0);
      iDiskPoint    = vec3(0.0, 0.0, 0.0);
      DiskPoint     = vec3(0.0, 0.0, 0.0);
      for ( real_type x = -Radius;
              x <=  Radius;
              x += this->getPointstep(), ++i ) {
        // Find intersection and store results
        pointSampling( TriList,
                       RF.getOrigin() + RF.getRotationMatrix()*vec3(x,y,0),
                       zAxis,
                       iDiskPoint,
                       iDiskFriction,
                       iDiskNormal );
        DiskPoint    += iDiskPoint;
        DiskFriction += iDiskFriction;
        DiskNormal   += iDiskNormal;
      }
      // Store results
      NormalVec[j]     = DiskNormal / i;
      FrictionVec[j]   = DiskFriction / i;
      planePointVec[j] = DiskPoint / i;
      // Update indexer
      i = 0;
    }
  }

}  // namespace TireGround
