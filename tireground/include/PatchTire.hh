///
/// file: PatchTire.hh
///

#pragma once

#include "RoadRDF.hh" // RDF file extention loader

//! Tire computations routines
namespace TireGround {

    /*\
   |         _                  _ _   _
   |    __ _| | __ _  ___  _ __(_) |_| |__  _ __ ___  ___
   |   / _` | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \/ __|
   |  | (_| | | (_| | (_) | |  | | |_| | | | | | | | \__ \
   |   \__,_|_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|___/
   |           |___/
  \*/

  //! Algorithms for tire computations routine
  namespace algorithms {

    //! Calculate arithmetic weighted mean for 3D vectors
    vec3
    mean(
      row_vec3 const & Values //!< Values (3D vectors)
    );

    //! Calculate arithmetic weighted mean for real numbers
    real_type
    weightedMean(
      row_vecN const & Values, //!< Values (real numbers)
      row_vecN const & Weights //!< Weights (real numbers)
    );

    //! Calculate arithmetic weighted mean for 3D vectors
    vec3
    weightedMean(
      row_vec3 const & Values, //!< Values (3D vectors)
      row_vecN const & Weights //!< Weights (real numbers)
    );

    //! Check if a point lays inside or outside a line segment \n
    //! Warning: The point query point must be on the same rect of the line segment!
    bool
    intersectPointSegment(
      vec2 const & Point1, //!< Line segment point 1
      vec2 const & Point2, //!< Line segment point 2
      vec2 const & PointQ  //!< Query point
    );

    //! Check if a segment hits a plane and find the intersection point
    bool 
    intersectRayPlane(
      vec3 const & planeN,        //!< Plane normal vector
      vec3 const & planeP,        //!< Plane known point
      vec3 const & RayPoint,      //!< Ray point
      vec3 const & RayDirection,  //!< Ray direction
      vec3       & IntersectionPt //!< Intersection point
    );

    //! Calculate minumum and maximum in \f$XY\f$ plane for 3D vectors
    void
    minmax_XY(
      row_vec3 const & Points, //!< 3D points vector
      vec2           & XYmin,  //!< Minimum (\f$X\f$,\f$Y\f$) values
      vec2           & XYmax   //!< Maximum (\f$X\f$,\f$Y\f$) values
    );

    //! Calculate minumum and maximum in \f$XY\f$ plane for 2D vectors
    void
    minmax_XY(
      row_vec2 const & Points, //!< 2D points vector
      vec2           & XYmin,  //!< Minimum (\f$X\f$,\f$Y\f$) values
      vec2           & XYmax   //!< Maximum (\f$X\f$,\f$Y\f$) values
    );

    //! Calculate area of a trapeziod [\f$m^2\f$]
    inline
    real_type
    trapezoidArea(
      real_type const Base2, //!< Base 1
      real_type const Base1, //!< Base 2
      real_type const Height //!< Heigth
    ) { 
      return (Base1 + Base2) * Height / 2.0;
    } 

  }  // namespace algorithms

  /*\
   |   ____  _     _
   |  |  _ \(_)___| | __
   |  | | | | / __| |/ /
   |  | |_| | \__ \   <
   |  |____/|_|___/_|\_\
   |
   |  ^ \f$Z\f$
   |  |     -----
   |  |   /       \
   |  |  |    O    |  O = OriginXZ
   |  |   \       /
   |  |     -----
   |  \f$Y\f$------------------> \f$X\f$
   |
   |  ISO Reference Frame
  \*/

  class ReferenceFrame;
  class ETRTO;

  //! Tire disk
  class Disk {
  private:
    vec2      OriginXZ; //!< \f$(X_0,Z_0)\f$ origin vector
    real_type OffsetY;  //!< \f$Y_0\f$ origin coordinate (offset from center)
    real_type Radius;   //!< Radius

    Disk( Disk const & ) = delete;                     //!< Deleted copy constructor
    Disk const & operator = ( Disk const & ) = delete; //!< Deleted copy operator

  public:
    //! Enable && operator
    Disk( Disk && ) = default; 

    //! Default constructor
    Disk()
    : OriginXZ( vec2(quietNaN, quietNaN) ) 
    , OffsetY( quietNaN )
    , Radius( quietNaN ) 
    {}

    //! Variable set constructor
    Disk(
      vec2 const & _OriginXZ, //!< \f$(X_0,Z_0)\f$ origin coordinate
      real_type    _OffsetY,  //!< \f$Y_0\f$ origin coordinate (offset from center)
      real_type    _Radius    //!< Radius
    ) {
      OriginXZ = _OriginXZ;
      OffsetY  = _OffsetY;
      Radius   = _Radius;
    }

    //! Copy the Disk object
    void
    set(
      Disk const & in //!< Disk object to be copied
    ) {
      this->OriginXZ = in.OriginXZ;
      this->OffsetY  = in.OffsetY;
      this->Radius   = in.Radius;
    }

    //! Set origin on \f$XZ\f$ plane
    void
    setOriginXZ(
      vec2 const & _OriginXZ //!< New origin on \f$XZ\f$ plane
    ) {
      OriginXZ = _OriginXZ;
    }

    //! Get origin vector \f$XZ\f$-axes coordinates
    vec2 const & getOriginXZ(void) const { return OriginXZ; }

    //! Get origin vector \f$XYZ\f$-axes coordinates
    vec3 getOriginXYZ(void) const
    { return vec3(OriginXZ.x(), OffsetY, OriginXZ.y()); }

    //! Get origin \f$Y\f$-axis coordinate
    real_type getOffsetY(void) const { return OffsetY; }

    //! Get Disk radius
    real_type getRadius(void) const { return Radius; }

    //! Get area weighted mean road normal versor, area weighted mean friction
    //! and contact area [\f$m^2\f$] inside the single Disk of segments described by
    //! the intersection of triangles on \f$XZ\f$-plane
    void
    contactTriangles(
      RDF::TriangleRoad_list const & TriList,  //!< Shadow / MeshSurface intersected triangles
      ReferenceFrame         const & RF,       //!< Tire ReferenceFrame
      vec3                         & Normal,   //!< Area weighted mean road normal versor
      real_type                    & Friction, //!< Area weighted mean contact friction
      real_type                    & Area      //!< Contact area [\f$m^2\f$]
    ) const;

    //! Get the contact area [\f$m^2\f$] inside the single Disk given a plane in 
    //! absolute reference frame
    void
    contactPlane( 
      vec3           const & Normal, //!< Plane normal in absolute reference frame
      vec3           const & Point,  //!< Plane point in absolute reference frame
      ReferenceFrame const & RF,     //!< Tire ReferenceFrame
      real_type            & Area    //!< Contact area [\f$m^2\f$]
    ) const;

    //! Get the points on Disk the circumference and on a given plane
    void
    pointOnDisk(
      vec3           const & Normal,
      ReferenceFrame const & RF,
      vec3                 & DiskPoint,
      vec3                 & NormalOnDisk
    ) const;

    //! Get the contact patch area under the intersection plane in 
    //! absolute reference frame [\f$m^2\f$]
    real_type
    segmentArea(
      real_type const Length //!< Chord length
    ) const {
      real_type c = 2.0 * std::asin( Length / (2.0*Radius) );
      return 0.5 * Radius*Radius * (c - std::sin(c));
    }

    //! Check if a point in Disk reference frame is inside or outside the Disk
    bool
    isPointInside(
      vec2 const & Point //!< Query point in Disk reference frame
    ) const;

    //! Evaluate \f$Y\f$ at a query \f$X\f$ value on the lower side Disk circumfererence
    real_type
    y(
      real_type const x //!< Query \f$X\f$ value
    ) const {
      return -std::sqrt(Radius*Radius - x*x);
    }

    //! Evaluate a generic segment length given 2 points on the Disk circumfererence
    real_type
    segmentLength(
      vec2 const Point1, //!< Point 1
      vec2 const Point2  //!< Point 2
    ) const {
      vec2 Point1_circ( Point1.x(), y(Point1.x()) );
      vec2 Point2_circ( Point2.x(), y(Point2.x()) );
      return (Point1_circ-Point2_circ).norm();
    }

    //! Find the intersection points between the Disk and a two points line segment
    //! in Disk reference frame (output integer gives number of intersection points)
    int_type
    intersectSegment(
      vec2 const & Point1,     //!< Line segment point 1 in Disk reference frame
      vec2 const & Point2,     //!< Line segment point 2 in Disk reference frame
      vec2       & Intersect1, //!< Intersection point 1 in Disk reference frame
      vec2       & Intersect2  //!< Intersection point 2 in Disk reference frame
    ) const;

    //! Check if two plane intersects and find the intersecting rect given two points 
    //! in Disk reference frame
    bool
    intersectPlane(
      vec3 const & Plane_Normal,   //!< Plane normal vector in Disk reference frame
      vec3 const & Plane_Point,    //!< Plane known point in Disk reference frame
      vec3       & Line_Direction, //!< Rect direction vector in Disk reference frame
      vec3       & Line_Point      //!< Plane known point in Disk reference frame
    ) const;

    //! Get a two points line segment area [\f$m^2\f$] (as ouput) inside the Disk
    real_type
    getLineArea(
      vec2      const & Point1_XZ, //!< Point 1 in Disk reference frame
      vec2      const & Point2_XZ  //!< Point 2 in Disk reference frame
    ) const;
  };

  /*\
   |   _____ _____ ____ _____ ___
   |  | ____|_   _|  _ \_   _/ _ \
   |  |  _|   | | | |_) || || | | |
   |  | |___  | | |  _ < | || |_| |
   |  |_____| |_| |_| \_\|_| \___/
  \*/

  //! Tire ETRTO denomination
  class ETRTO {
  private:
    real_type SectionWidth;   //!< Tire section width [\f$m\f$]
    real_type AspectRatio;    //!< Tire aspect ratio [\f$\%\f$]
    real_type RimDiameter;    //!< Rim diameter [\f$in\f$]
    real_type SidewallHeight; //!< Sidewall height [\f$m\f$]
    real_type TireDiameter;   //!< External diameter [\f$m\f$]

  public:
    //! Default constructor
    ETRTO() {}

    //! Variable set constructor
    ETRTO(
      real_type _SectionWidth, //!< Tire section width [\f$m\f$]
      real_type _AspectRatio,  //!< Tire aspect ratio [\f$\%\f$]
      real_type _RimDiameter   //!< Rim diameter [\f$in\f$]
    ) {
      SectionWidth = _SectionWidth;
      AspectRatio  = _AspectRatio;
      RimDiameter  = _RimDiameter;
      calcSidewallHeight();
      calcTireDiameter();
    }

    //! Get sidewall height [\f$m\f$]
    real_type getSidewallHeight(void) const { return SidewallHeight; }

    //! Get external tire diameter [\f$m\f$]
    real_type getTireDiameter(void) const { return TireDiameter; }

    //! Get external tire radius [\f$m\f$]
    real_type getTireRadius(void) const { return TireDiameter / 2.0; }

    //! Get section width [\f$m\f$]
    real_type getSectionWidth(void) const { return SectionWidth; }

    //! Display tire data
    void
    print(
      ostream_type & stream //!< Output stream type
    ) const {
      stream
        << "Current Tire Data:\n"
        << "\tSection width = " << SectionWidth << " m\n"
        << "\tAspect ratio  = " << AspectRatio << " %\n"
        << "\tRim diameter  = " << RimDiameter << " in\n"
        << "\tS.wall Height = " << getSidewallHeight() << " m\n"
        << "\tTire diameter = " << getTireDiameter() << " m\n\n";
    }

  private:
    //! Calculate sidewall height [\f$m\f$]
    void
    calcSidewallHeight(void)
    { SidewallHeight = SectionWidth * AspectRatio / 100; }

    //! Calculate external tire diameter [\f$m\f$]
    void
    calcTireDiameter(void)
    { TireDiameter = RimDiameter * 0.0254 + getSidewallHeight() * 2.0; }
  };

  /*\
   |   ____       __                              _____
   |  |  _ \ ___ / _| ___ _ __ ___ _ __   ___ ___|  ___| __ __ _ _ __ ___   ___
   |  | |_) / _ \ |_ / _ \ '__/ _ \ '_ \ / __/ _ \ |_ | '__/ _` | '_ ` _ \ / _ \
   |  |  _ <  __/  _|  __/ | |  __/ | | | (_|  __/  _|| | | (_| | | | | | |  __/
   |  |_| \_\___|_|  \___|_|  \___|_| |_|\___\___|_|  |_|  \__,_|_| |_| |_|\___|
   |
  \*/

  //! Reference frame
  class ReferenceFrame {
  private:
    vec3 Origin;         //!< Origin position
    mat3 RotationMatrix; //!< 3x3 rotation matrix

    ReferenceFrame( ReferenceFrame const & ) = delete;               //!< Deleted copy constructor
    ReferenceFrame & operator = ( ReferenceFrame const & ) = delete; //!< Deleted copy operator

  public:
    //! Default constructor
    ReferenceFrame()
    : Origin(vec3_NaN)
    , RotationMatrix(mat3_NaN)
    {}

    //! Variable set constructor
    ReferenceFrame(
      vec3 const & _Origin,        //!< Origin position
      mat3 const & _RotationMatrix //!< 3x3 rotation matrix
    )
    : Origin(_Origin)
    , RotationMatrix(_RotationMatrix)
    { }

    //! Check if ReferenceFrame object is empty
    bool
    isEmpty(void) {
      if ( Origin != Origin || RotationMatrix != RotationMatrix){
        return true;
      } else {
        return false;
      }
    }

    //! Get current 3x3 rotation matrix
    mat3 const & 
    getRotationMatrix(
      void
    ) const { 
      return RotationMatrix; 
    }

    //! Get current 3x3 rotation matrix inverse
    mat3 
    getRotationMatrixInverse(
      void
    ) const {
      return RotationMatrix.transpose();
    }

    //! Get current \f$X\f$-axis versor
    vec3 getX(void) const { return RotationMatrix.col(0); }

    //! Get current \f$Y\f$-axis versor
    vec3 getY(void) const { return RotationMatrix.col(1); }

    //! Get current \f$Z\f$-axis versor
    vec3 getZ(void) const { return RotationMatrix.col(2); }

    //! Get origin position
    vec3 const & getOrigin(void) const { return Origin; }

    //! Set origin position
    void setOrigin(
      vec3 const & _Origin //!< Origin position
    ) { Origin = _Origin; }

    //! Set 3x3 rotation matrix
    void setRotationMatrix(
      mat3 const & _RotationMatrix //!< 3x3 rotation matrix
    ) { RotationMatrix = _RotationMatrix; }

    //! Set 4x4 total transformation matrix
    void
    setTotalTransformationMatrix(
      mat4 const & TM //!< 4x4 total transformation matrix
    ) {
      Origin         = TM.block<3,1>(0,3);
      RotationMatrix = TM.block<3,3>(0,0);
    }

    //! Get 4x4 total transformation matrix
    mat4
    getTotalTransformationMatrix(void) {
      mat4 out;
      out << RotationMatrix, Origin, vec4(0.0, 0.0, 0.0, 1.0).transpose();
      return out;
    }

    //! Copy the tire ReferenceFrame object \n
    //! Warning: Rotation matrix must be orthonormal!
    void
    set(
      ReferenceFrame const & in //!< ReferenceFrame object to be copied
    ) {
      this->Origin         = in.Origin;
      this->RotationMatrix = in.RotationMatrix;
    }

    //! Get current Euler angles [\f$rad\f$] for \f$X\f$-axis \n
    //! Warning: Factor as \f$[R_z][R_x][R_y]\f$!
    // https://www.geometrictools.com/Documentation/EulerAngles.pdf
    real_type getEulerAngleX(void) const;

    //! Get current Euler angles [\f$rad\f$] for \f$Y\f$-axis \n
    //! Warning: Factor as \f$[R_z][R_x][R_y]\f$!
    // https://www.geometrictools.com/Documentation/EulerAngles.pdf
    real_type getEulerAngleY(void) const;

    //! Get current Euler angles [\f$rad\f$] for \f$Z\f$-axis \n
    //! Warning: Factor as \f$[R_z][R_x][R_y]\f$!
    // https://www.geometrictools.com/Documentation/EulerAngles.pdf
    real_type getEulerAngleZ(void) const;

  };

  /*\
   |   ____  _               _               
   |  / ___|| |__   __ _  __| | _____      __
   |  \___ \| '_ \ / _` |/ _` |/ _ \ \ /\ / /
   |   ___) | | | | (_| | (_| | (_) \ V  V / 
   |  |____/|_| |_|\__,_|\__,_|\___/ \_/\_/  
  \*/

  //! 2D shadow (2D bounding box enhacement)
  class Shadow {
  private:
    G2lib::AABBtree::PtrAABB TreePtr
      = std::make_shared<G2lib::AABBtree>(); //!< Mesh AABBtree
    G2lib::AABBtree::PtrAABB TreePtr_U 
      = std::make_shared<G2lib::AABBtree>(); //!< Lower side Mesh AABBtree
    G2lib::AABBtree::PtrAABB TreePtr_L 
      = std::make_shared<G2lib::AABBtree>(); //!< Upper side Mesh AABBtree

    Shadow( Shadow const & ) = delete;                     //!< Deleted copy constructor
    Shadow const & operator = ( Shadow const & ) = delete; //!< Deleted copy operator

  public:
    //! Default constructor
    Shadow() {}

    //! Variable set constructor \n
    //! Warning: Rotation matrix must be orthonormal!
    Shadow(
      ETRTO          const & TireGeometry, //!< Tire ETRTO denomination 
      ReferenceFrame const & RF            //!< Tire ReferenceFrame 
    ) {
      update( TireGeometry, RF );
    }

    //! Update the 2D tire shadow domain \n
    //! Warning: Rotation matrix must be orthonormal!
    void
    update(
      ETRTO          const & TireGeometry, //!< Tire ETRTO denomination
      ReferenceFrame const & RF            //!< Tire ReferenceFrame
    );

    //! Get total Tire G2Lib::AABBtree (3D projection on ground)
    G2lib::AABBtree::PtrAABB const
    getAABBtree(
      void
    ) const {
      return TreePtr;
    }

    //! Get upper side Tire G2Lib:AABBtree (3D projection on ground)
    G2lib::AABBtree::PtrAABB const
    getUpperSideAABBtree(
      void
    ) const {
      return TreePtr_U;
    }

    //! Get lower side Tire G2Lib:AABBtree (3D projection on ground)
    G2lib::AABBtree::PtrAABB const
    getLowerSideAABBtree(
      void
    ) const {
      return TreePtr_L;
    }
    
  };

  /*\
   |   ____                        _ _              ____      _     _
   |  / ___|  __ _ _ __ ___  _ __ | (_)_ __   __ _ / ___|_ __(_) __| |
   |  \___ \ / _` | '_ ` _ \| '_ \| | | '_ \ / _` | |  _| '__| |/ _` |
   |   ___) | (_| | | | | | | |_) | | | | | | (_| | |_| | |  | | (_| |
   |  |____/ \__,_|_| |_| |_| .__/|_|_|_| |_|\__, |\____|_|  |_|\__,_|
   |                        |_|              |___/
  \*/

  //! Patch evaluation precision
  class SamplingGrid {
  private:
    int_type PointsN; //!< Sampling points for each Disk (divisions on \f$X\f$-axis)
    int_type DisksN;  //!< Number of Disks (divisions on \f$Y\f$-axis \f$ - 1\f$)
    int_type Switch;  //!< Maximum RoadTriangles in the Tire Shadow (switch to sampling)

    SamplingGrid( SamplingGrid const & ) = delete;               //!< Deleted copy constructor
    SamplingGrid & operator = ( SamplingGrid const & ) = delete; //!< Deleted copy operator

  public:
    //! Default constructor
    SamplingGrid()
    : PointsN(0)
    , DisksN(0)
    , Switch(10)
    {}

    //! Variable set constructor
    SamplingGrid(
      int_type _PointsN, //!< Sampling points for each Disk (divisions on \f$X\f$-axis)
      int_type _DisksN   //!< Number of Disks (divisions on \f$Y\f$-axis \f$ - 1\f$)
    )
    : PointsN(_PointsN)
    , DisksN(_DisksN)
    , Switch(10)
    {
      RDF_ASSERT( _PointsN > 0, "Sampling points for each disk cannot be less than 1.");
      RDF_ASSERT( _DisksN > 0, "Number of Disks cannot be less than 1.");
    }

    //! Variable set constructor
    SamplingGrid(
      int_type _PointsN, //!< Sampling points for each Disk (divisions on \f$X\f$-axis)
      int_type _DisksN,  //!< Number of Disks (divisions on \f$Y\f$-axis \f$ - 1\f$)
      int_type _Switch   //!< Maximum RoadTriangles in the Tire Shadow (switch to sampling)
    )
    : Switch(_Switch)
    {
      SamplingGrid(_PointsN,_DisksN);
    }

    //! Get number of sampling points for each Disk (divisions on \f$X\f$-axis)
    int_type getPointsNumber(void) const { return PointsN; }

    //! Get number of Disks (divisions on \f$Y\f$-axis \f$ - 1\f$)
    int_type getDisksNumber(void) const { return DisksN; }

    //! Get number of maximum RoadTriangles in the Tire Shadow (switch to sampling)
    unsigned getSwitchNumber(void) const { return Switch; }

    //! Set number of maximum RoadTriangles in the Tire Shadow (switch to sampling)
    void
    setSwitchNumber(
      int_type const _Switch //!< New switch number
    ) { 
      RDF_ASSERT( _Switch > -1, "Maximum RoadTriangles in the Tire Shadow cannot be negative." );
      Switch = _Switch;
    }

    //! Set number of divisions
    void
    set(
      int_type _PointsN, //!< Sampling points for each Disk (divisions on \f$X\f$-axis)
      int_type _DisksN,  //!< Number of Disks (divisions on \f$Y\f$-axis \f$ - 1\f$)
      int_type _Switch   //!< Maximum RoadTriangles in the Tire Shadow (switch to sampling)
    ) {
      PointsN = _PointsN;
      DisksN  = _DisksN;
      Switch  = _Switch;
      RDF_ASSERT( _PointsN > 0, "Sampling points for each disk cannot be less than 1.");
      RDF_ASSERT( _DisksN > 0, "Number of Disks cannot be less than 1.");
      RDF_ASSERT( _Switch > -1, "Maximum RoadTriangles in the Tire Shadow cannot be negative." );
    }

    //! Copy the SamplingGrid object
    void
    set(
      SamplingGrid const & in //!< SamplingGrid object to be copied
    ) {
      this->PointsN = in.PointsN;
      this->DisksN = in.DisksN;
      this->Switch = in.Switch;
      RDF_ASSERT( PointsN > 0, "Sampling points for each disk cannot be less than 1.");
      RDF_ASSERT( DisksN > 0, "Number of Disks cannot be less than 1.");
      RDF_ASSERT( Switch > -1, "Maximum RoadTriangles in the Tire Shadow cannot be negative." );
    }

  };

  /*\
   |   _____ _          
   |  |_   _(_)_ __ ___ 
   |    | | | | '__/ _ \
   |    | | | | | |  __/
   |    |_| |_|_|  \___|
   |                    
   |
   |          ^ \f$Z\f$
   |          |
   |        --|--
   |      /   |   \
   |     |  O=\f$Y\f$----|---> \f$X\f$
   |      \       /
   |        -----
   |
   |          ^ \f$Y\f$
   |          |
   |      ____|____
   |     |    |    |
   |     |  O=\f$Z\f$----|---> \f$X\f$
   |     |_________|
   |
   |  O = OriginXZ
   |  ISO Reference Frame!
  \*/

  //! Base class for Tire models
  class Tire {
  protected:
    SamplingGrid   Precision;    //!< Contacth patch evaluating precision
    ETRTO          TireGeometry; //!< Tire ETRTO denomination
    ReferenceFrame RF;           //!< ReferenceFrame
    Shadow         TireShadow;   //!< Tire shadow

    Tire( Tire const & ) = delete;                     //!< Deleted copy constructor
    Tire const & operator = ( Tire const & ) = delete; //!< Deleted copy operator

  public:
    //! Default destructor
    ~Tire() {};

    //! Variable set constructor
    Tire(
      real_type const SectionWidth, //!< Tire section width [\f$m\f$]
      real_type const AspectRatio,  //!< Tire aspect ratio [\f$\%\f$]
      real_type const RimDiameter,  //!< Rim diameter [\f$in\f$]
      int_type  const PointsN,      //!< Sampling points for each Disk (divisions on \f$X\f$-axis)
      int_type  const DisksN        //!< Number of Disks (divisions on \f$Y\f$-axis \f$ - 1\f$)
    )
    : Precision( PointsN, DisksN ),
      TireGeometry( SectionWidth, AspectRatio, RimDiameter ),
      RF()
    {}

    //! Display Tire ETRTO geometry data
    void
    printETRTOGeometry(
      ostream_type & stream //!< Output stream type
    ) const {
      TireGeometry.print( stream );
    }

    //! Get sidewall height [\f$m\f$]
    real_type 
    getSidewallHeight(void) const { return TireGeometry.getSidewallHeight(); }

    //! Get external tire diameter [\f$m\f$]
    real_type
    getTireDiameter(void) const { return TireGeometry.getTireDiameter(); }

    //! Get external tire radius [\f$m\f$]
    real_type
    getTireRadius(void) const { return TireGeometry.getTireRadius(); }

    //! Get section width [\f$m\f$]
    real_type
    getSectionWidth(void) const { return TireGeometry.getSectionWidth(); }

    //! Get total Tire Shadow G2Lib::AABBtree (3D projection on ground)
    G2lib::AABBtree::PtrAABB const
    getAABBtree(void) const { return TireShadow.getAABBtree(); }

    //! Get upper side Tire Shadow G2Lib:AABBtree (3D projection on ground)
    G2lib::AABBtree::PtrAABB const
    getUpperSideAABBtree(void) const { return TireShadow.getUpperSideAABBtree(); }

    //! Get lower side Tire Shadow G2Lib:AABBtree (3D projection on ground)
    G2lib::AABBtree::PtrAABB const
    getLowerSideAABBtree(void) const { return TireShadow.getLowerSideAABBtree(); }

    //! Copy the tire ReferenceFrame object \n
    //! Warning: Rotation matrix must be orthonormal!
    void
    setReferenceFrame(
      ReferenceFrame const & _RF //!< ReferenceFrame object to be copied
    ) { RF.set(_RF); }

    //! Get tire ReferenceFrame object
    ReferenceFrame const &
    getReferenceFrame(void) const
    { return RF; }

    //! Set a new tire origin
    void
    setOrigin(
      vec3 const & Origin //!< Tire origin
    ) { RF.setOrigin( Origin ); }

    //! Set a new 3x3 rotation matrix \n
    //! Warning: Rotation matrix must be orthonormal!
    void
    setRotationMatrix(
      mat3 const & RotationMatrix //!< Rotation matrix
      )
    { RF.setRotationMatrix( RotationMatrix ); }

    //! Set 4x4 total transformation matrix \n
    //! Warning: Rotation matrix must be orthonormal!
    void
    setTotalTransformationMatrix(
      mat4 const & TM //!< 4x4 total transformation matrix
    ) { RF.setTotalTransformationMatrix(TM); }

    //! Get current Euler angles [\f$rad\f$] for \f$X\f$-axis \n
    //! Warning: Factor as \f$[R_z][R_x][R_y]\f$!
    real_type getEulerAngleX(void) const { return RF.getEulerAngleX(); };

    //! Get current Euler angles [\f$rad\f$] for \f$Y\f$-axis \n
    //! Warning: Factor as \f$[R_z][R_x][R_y]\f$!
    real_type getEulerAngleY(void) const { return RF.getEulerAngleY(); };

    //! Get current Euler angles [\f$rad\f$] for \f$Z\f$-axis \n
    //! Warning: Factor as \f$[R_z][R_x][R_y]\f$!
    real_type getEulerAngleZ(void) const { return RF.getEulerAngleZ(); };

    //! Get relative camber angle [\f$rad\f$]
    void
    getRelativeCamber(
      real_type & RelativeCamber //!< Relative camber angle
    ) const;

    //! Dimension of the contact points data structure (disks number)
    int_type
    getDisksNumber (
      void
    ) const {
      return Precision.getDisksNumber();
    };

    //! Get contact depth at center point [\f$m\f$] \n
    //! Warning: (if negative the tire does not touch the ground)!
    virtual
    void
    getRho(
      real_type       & Rho,    //!< Depth at center point [\f$m/s\f$]
      real_type       & RhoDot, //!< Contact depth derivative [\f$m/s\f$]
      real_type const   RhoOld, //!< Previous time step Rho [\f$m\f$]
      real_type const   Time    //!< Time step [\f$s\f$]
    ) const = 0;

    //! Get contact depth vector [\f$m\f$] and it time derivatives [\f$m/s\f$] \n
    //! Warning: (if negative the tire does not touch the ground)!
    virtual
    void
    getRho(
      row_vecN        & Rho,    //!< Depth matrix [\f$m/s\f$]
      row_vecN        & RhoDot, //!< Contact depth derivative matrix [\f$m/s\f$]
      row_vecN  const   RhoOld, //!< Previous time step Rho matrix [\f$m\f$]
      real_type const   Time    //!< Time step [\f$s\f$]
    ) const = 0;

    //! Get contact normal versor
    virtual
    void
    getNormal(
      vec3 & Normal //!< Contact point normal direction
    ) const = 0;

    //! Get contact normal versors vector
    virtual
    void
    getNormal(
      row_vec3 & Normal //!< Contact point normal direction vector
    ) const = 0;

    //! Get Magic Formula contact point
    virtual
    void
    getMFpoint(
      vec3 & Point //!< Magic Formula contact point
    ) const = 0;

     //! Get Magic Formula contact point vector
    virtual
    void
    getMFpoint(
      row_vec3 & Point //!< Magic Formula Contact point vector
    ) const = 0;

    //! Get contact point friction
    virtual
    void
    getFriction(
      real_type & Friction //!< Contact point friction
    ) const = 0;

    //! Get contact frictions vector
    virtual
    void
    getFriction(
      row_vecN & Friction //! Contact frictions vector
    ) const = 0;

    //! Get Magic Formula contact point reference frame with 4x4 transformation matrix
    virtual
    void
    getMFpointRF(
      mat4 & PointRF //!< Magic Formula contact point reference frame
    ) const = 0;

    //! Get Magic Formula contact point reference frame vector with 4x4 transformation matrix
    virtual
    void
    getMFpointRF(
      row_mat4 & PointRF //!< Magic Formula ontact point reference frames vector
    ) const = 0;

    //! Get approximated contact area on Disk plane [\f$m^2\f$]
    virtual
    void
    getArea(
      real_type & _Area //!< Contact area [\f$m^2\f$]
    ) const = 0;

    //! Get approximated contact areas vector on Disk plane [\f$m^2\f$]
    virtual
    void
    getArea(
      row_vecN & Area //!< Contact areas vector [\f$m^2\f$]
    ) const = 0;

    //! Get approximated contact volume [\f$m^3\f$]
    virtual
    void
    getVolume(
      real_type & Volume //!< Contact volume [\f$m^3\f$]
    ) const = 0;

    //! Get approximated contact volume [\f$m^3\f$]
    virtual
    void
    getVolume(
      row_vecN & _Volume //!< Contact volume vector [\f$m^3\f$]
    ) const = 0;

    //! Evaluate contact with RoadTriangles
    virtual
    void
    evaluateContact(
      RDF::TriangleRoad_list const & TriList //!< Shadow/MeshSurface intersected triangles
    ) = 0;

    //! Update current tire position and find contact parameters
    virtual
    bool
    setup(
      RDF::MeshSurface       & Mesh, //!< MeshSurface object (road)
      mat4             const & TM    //!< 4x4 total transformation matrix
    ) = 0;

    //! Update current tire position and find contact parameters with 
    //! external plane
    virtual
    void
    setup(
      vec3      const & Plane_Normal,   //!< Plane normal vector
      vec3      const & Plane_Point,    //!< Plane known point
      real_type const   Plane_Friction, //!< Friction on plane
      mat4      const & TM              //!< 4x4 total transformation matrix
    ) = 0;

    //! Print contact parameters
    virtual
    void
    print(
      ostream_type & stream //!< Output stream type
    ) const = 0;

  protected:
    //! Perform one point sampling (ray-triangle intersection)
    bool
    pointSampling(
      RDF::TriangleRoad_list const &
        TriList,                           //!< Shadow/MeshSurface intersected triangles
      vec3 const & RayOrigin,              //!< Ray origin
      vec3 const & RayDirection,           //!< Ray direction
      vec3       & SampledPt,              //!< Intersection point
      real_type  & TriFriction = quietNaN, //!< Intersected triangle friction
      vec3       & TriNormal = vec3_NaN    //!< Intersected triangle normal
    ) const;

  };

  /*\
   |   __  __             _      _____                          _
   |  |  \/  | __ _  __ _(_) ___|  ___|__  _ __ _ __ ___  _   _| | __ _
   |  | |\/| |/ _` |/ _` | |/ __| |_ / _ \| '__| '_ ` _ \| | | | |/ _` |
   |  | |  | | (_| | (_| | | (__|  _| (_) | |  | | | | | | |_| | | (_| |
   |  |_|  |_|\__,_|\__, |_|\___|_|  \___/|_|  |_| |_| |_|\__,_|_|\__,_|
   |                |___/
  \*/

  //! Pacejka MagicFormula contact model
  class MagicFormula : public Tire {
  protected:
    Disk      SingleDisk; //!< Single Disk
    vec3      Normal;     //!< Contact normal versor
    vec3      MeshPoint;  //!< Contact point on Mesh (for Magic Formula)
    vec3      DiskPoint;  //!< Contact point on undeformed Disk circumference (not for Magic Formula)
    real_type Friction;   //!< Contact friction
    real_type Area;       //!< Contact area [\f$m^2\f$]

    MagicFormula( MagicFormula const & ) = delete;                     //!< Deleted copy constructor
    MagicFormula const & operator = ( MagicFormula const & ) = delete; //!< Deleted copy operator

  public:
    //! Default destructor
    ~MagicFormula() {};

    //! Variable set constructor
    MagicFormula(
      real_type const SectionWidth, //!< Tire section width [\f$m\f$]
      real_type const AspectRatio,  //!< Tire aspect ratio [\f$\%\f$]
      real_type const RimDiameter,  //!< Rim diameter [\f$in\f$]
      int_type  const SwitchN       //!< Maximum RoadTriangles in the Tire Shadow (switch to sampling)
    ) 
    : Tire( SectionWidth, AspectRatio, RimDiameter, 1, 1 )
    {
      // Update switch number
      Precision.setSwitchNumber(SwitchN);
      // Locate the Disk
      SingleDisk.set( Disk( vec2(0.0, 0.0), 0.0, TireGeometry.getTireRadius() ) );
    }

    //! Get contact normal versor
    void
    getNormal(
      vec3 & _Normal //!< Contact point normal versor
    ) const override { 
      _Normal = Normal;
    }

    //! Get contact normal versors vector
    void
    getNormal(
      row_vec3 & _Normal //!< Contact point normal direction vector
    ) const override {
      _Normal(0) = Normal;
    }

    //! Get Magic Formula contact point
    void
    getMFpoint(
      vec3 & _DiskPoint //!< Magic Formula contact point
    ) const override {
      _DiskPoint = DiskPoint;
    }

    //! Get Magic Formula contact point vector
    void
    getMFpoint(
      row_vec3 & _DiskPoint //!< Contact point vector on Disk
    ) const override {
      _DiskPoint(0) = DiskPoint;
    }

    //! Get contact point friction
    void
    getFriction(
      real_type & _Friction //!< Contact point friction
    ) const override {
      _Friction = Friction;
    }

    //! Get contact point friction vector
    void
    getFriction(
      row_vecN & _Friction //!< Contact point friction vector
    ) const override {
      _Friction(0) = Friction;
    }

    //! Get Magic Formula  contact point reference frame with 4x4 transformation matrix
    void
    getMFpointRF(
      mat4 & PointRF //!< Magic Formula contact point reference frame
    ) const override;

    //! Get Magic Formula contact point reference frame vector with 4x4 transformation matrix
    void
    getMFpointRF(
      row_mat4 & _MFpointRF //!< Magic Formula ontact point reference frames vector
    ) const override {
      mat4 MFpointRF;
      getMFpointRF(MFpointRF);
      _MFpointRF(0) = MFpointRF;
    };

    //! Get contact depth at center point [\f$m\f$] and it time derivative [\f$m/s\f$]\n
    //! Warning: (if negative the tire does not touch the ground)!
    void
    getRho(
      real_type       & Rho,    //!< Depth at center point [\f$m/s\f$]
      real_type       & RhoDot, //!< Contact depth derivative [\f$m/s\f$]
      real_type const   RhoOld, //!< Previous time step Rho [\f$m\f$]
      real_type const   Time    //!< Time step [\f$s\f$]
    ) const override;

    //! Get contact depth matrix [\f$m\f$] and it time derivatives [\f$m/s\f$]\n
    //! Warning: (if negative the tire does not touch the ground)!
    void
    getRho(
      row_vecN        & Rho,    //!< Depth matrix [\f$m/s\f$]
      row_vecN        & RhoDot, //!< Contact depth derivative matrix [\f$m/s\f$]
      row_vecN  const   RhoOld, //!< Previous time step Rho matrix [\f$m\f$]
      real_type const   Time    //!< Time step [\f$s\f$]
    ) const override {
      this->getRho( Rho[0], RhoDot[0], RhoOld[0], Time );
    };

    //! Get approximated contact area on Disk plane [\f$m^2\f$]
    void
    getArea(
      real_type & _Area //!< Contact area [\f$m^2\f$]
    ) const override {
      _Area = Area;
    }

    //! Get approximated contact area  vector on Disk plane [\f$m^2\f$]
    void
    getArea(
      row_vecN & _Area //!< Contact area vector [\f$m^2\f$]
    ) const override {
      _Area(0) = Area;
    }

    //! Get approximated contact volume [\f$m^3\f$]
    void
    getVolume(
      real_type & _Volume //!< Contact volume [\f$m^3\f$]
    ) const override {
      _Volume = Area * TireGeometry.getSectionWidth();
    }

    //! Get approximated contact volume vector [\f$m^3\f$]
    void
    getVolume(
      row_vecN & Volume //!< Contact volume vector [\f$m^3\f$]
    ) const override {
      Volume(0) = Area * TireGeometry.getSectionWidth();
    }

    //! Update current tire position and find contact parameters
    bool
    setup(
      RDF::MeshSurface       & Mesh, //!< MeshSurface object (road)
      mat4             const & TM    //!< 4x4 total transformation matrix
    ) override;

    //! Update current tire position and find contact parameters with 
    //! external plane
    void
    setup(
      vec3      const & Plane_Normal,   //!< Plane normal vector
      vec3      const & Plane_Point,    //!< Plane known point
      real_type const   Plane_Friction, //!< Friction on plane
      mat4      const & TM              //!< 4x4 total transformation matrix
    ) override;

    //! Print contact parameters
    void
    print(
      ostream_type & stream //!< Output stream type
    ) const override;

  protected:
    //! Evaluate contact with RoadTriangles
    void
    evaluateContact(
      RDF::TriangleRoad_list const & TriList //!< Shadow/MeshSurface intersected triangles
    ) override;

    //! Perform triangles sampling on 4 points at ±0.1*R along \f$X\f$ and ±0.3*W along \f$Y\f$
    void
    fourPointsSampling(
      RDF::TriangleRoad_list const & TriList, //!< Shadow/MeshSurface intersected triangles
      vec3                         & P_star
    );

  };

  /*\
   |   __  __       _ _   _ ____  _     _    
   |  |  \/  |_   _| | |_(_)  _ \(_)___| | __
   |  | |\/| | | | | | __| | | | | / __| |/ /
   |  | |  | | |_| | | |_| | |_| | \__ \   < 
   |  |_|  |_|\__,_|_|\__|_|____/|_|___/_|\_\
   |                                         
  \*/

  //! Multi-disk tire contact model
  class MultiDisk : public Tire {
  private:
    std::vector<Disk> DiskVec;      //!< Disks vector
    row_vec3          NormalVec;    //!< Contact normal versors vector
    row_vec3          MeshPointVec; //!< Contact points vector on MeshSurface
    row_vec3          DiskPointVec; //!< Contact points vector on undeformed Disk circumference
    row_vecN          FrictionVec;  //!< Contact friction
    row_vecN          AreaVec;      //!< Contact area vector [\f$m^2\f$]
    vec3              Normal;       //!< Contact normal versor
    vec3              DiskPoint;    //!< Contact point on undeformed Disk circumference (not for Magic Formula)
    vec3              MFpoint;      //!< Contact point (for Magic Formula)

    MultiDisk( MultiDisk const & ) = delete;                     //!< Deleted copy constructor
    MultiDisk const & operator = ( MultiDisk const & ) = delete; //!< Deleted copy operator

  public:
    //! Default destructor
    ~MultiDisk() {};

    //! Variable set constructor
    MultiDisk(
      real_type const SectionWidth, //!< Tire section width [\f$m\f$]
      real_type const AspectRatio,  //!< Tire aspect ratio [\f$\%\f$]
      real_type const RimDiameter,  //!< Rim diameter [\f$in\f$]
      int_type  const PointsN,      //!< Sampling points for each Disk (divisions on \f$X\f$-axis)
      int_type  const DisksN,       //!< Number of Disks (divisions on \f$Y\f$-axis \f$ - 1\f$)
      int_type  const SwitchN       //!< Maximum RoadTriangles in the Tire Shadow (switch to sampling)
    ) : Tire( SectionWidth, AspectRatio, RimDiameter, PointsN, DisksN ) 
    {
      // Resize the contact point, friction and normal matrices
      NormalVec.resize( DisksN );
      MeshPointVec.resize( DisksN );
      DiskPointVec.resize( DisksN );
      FrictionVec.resize( DisksN );
      AreaVec.resize( DisksN );
      // Update switch number
      Precision.setSwitchNumber( SwitchN );
      // Locate the disks
      real_type OffsetY;
      for (int_type i = 0; i < DisksN; ++i) {
        OffsetY = -TireGeometry.getSectionWidth()/2.0 +
                  this->getDiskStep()/2.0 + i*this->getDiskStep();
        DiskVec.push_back( Disk( vec2(0, 0), OffsetY, TireGeometry.getTireRadius() ) );
      }
    }

    //! Variable set constructor
    MultiDisk(
      real_type const SectionWidth, //!< Tire section width [\f$m\f$]
      real_type const AspectRatio,  //!< Tire aspect ratio [\f$\%\f$]
      real_type const RimDiameter,  //!< Rim diameter [\f$in\f$]
      real_type const SideRadius,   //!< Sidewall radius [\f$m\f$]
      int_type  const PointsN,      //!< Sampling points for each Disk (divisions on \f$X\f$-axis)
      int_type  const DisksN,       //!< Number of Disks (divisions on \f$Y\f$-axis \f$ - 1\f$)
      int_type  const SwitchN       //!< Maximum RoadTriangles in the Tire Shadow (switch to sampling)
    ) : Tire( SectionWidth, AspectRatio, RimDiameter, PointsN, DisksN ) 
    {
      // Check if the radius is smaller than a half of SectionWidth
      RDF_ASSERT( SideRadius < SectionWidth/2.0, "Radius must be maller than a half of SectionWidth.");
      // Resize the contact point, friction and normal matrices
      NormalVec.resize( DisksN );
      MeshPointVec.resize( DisksN );
      DiskPointVec.resize( DisksN );
      FrictionVec.resize( DisksN );
      AreaVec.resize( DisksN );
      // Update switch number
      Precision.setSwitchNumber( SwitchN );
      // Locate the disks
      real_type OffsetY, Radius, x;
      for (int_type i = 0; i < DisksN; ++i) {
        OffsetY = -TireGeometry.getSectionWidth()/2.0 +
                  this->getDiskStep()/2.0 + i*this->getDiskStep();
        // Calculate radius
        x = SideRadius - SectionWidth/2.0 + abs(OffsetY);
        if( x < 0.0 ) {
          Radius = TireGeometry.getTireRadius();
        } else if( x > 0.0) {
          Radius = TireGeometry.getTireRadius() - SideRadius + std::sqrt(SideRadius*SideRadius - x*x);
        } else {
          RDF_ERROR("Not handled Disk radius calculation")
        }
        DiskVec.push_back( Disk( vec2(0, 0), OffsetY, Radius ) );
      }
    }

    //! Variable set constructor
    MultiDisk(
      real_type const SectionWidth, //!< Tire section width [\f$m\f$]
      real_type const AspectRatio,  //!< Tire aspect ratio [\f$\%\f$]
      real_type const RimDiameter,  //!< Rim diameter [\f$in\f$]
      row_vecN  const DisksRadius,  //!< Disks radius vector [\f$m\f$]
      int_type  const PointsN,      //!< Sampling points for each Disk (divisions on \f$X\f$-axis)
      int_type  const SwitchN       //!< Maximum RoadTriangles in the Tire Shadow (switch to sampling)
    ) : Tire( SectionWidth, AspectRatio, RimDiameter, PointsN, DisksRadius.size() ) 
    {
      // Resize the contact point, friction and normal matrices
      int_type disksNumber = DisksRadius.size();
      NormalVec.resize( disksNumber );
      MeshPointVec.resize( disksNumber );
      DiskPointVec.resize( disksNumber );
      FrictionVec.resize( disksNumber );
      AreaVec.resize( disksNumber );
      // Update switch number
      Precision.setSwitchNumber( SwitchN );
      // Locate the disks
      real_type OffsetY;
      for (int_type i = 0; i < disksNumber; ++i) {
        OffsetY = -TireGeometry.getSectionWidth()/2.0 +
                  this->getDiskStep()/2.0 + i*this->getDiskStep();
        DiskVec.push_back( Disk( vec2(0, 0), OffsetY, DisksRadius[i] ) );
      }
    }

    //! Get grid step on \f$X\f$-axis between sampling points [\f$m\f$]
    real_type
    getPointstep(void) const
    { return TireGeometry.getTireDiameter() / (Precision.getPointsNumber() - 1); }

    //! Get step on \f$Y\f$-axis between disks [\f$m\f$]
    real_type
    getDiskStep(void) const
    { return TireGeometry.getSectionWidth() / Precision.getDisksNumber(); }

    //! Get contact normal mean versor
    void
    getNormal(
      vec3 & _Normal //!< Contact normal mean versor
    ) const override {
      _Normal = Normal;
    }

    //! Get disks origin \f$(X,Y,Z)\f$ 
    void
    getDiskOriginXYZ(
      row_vec3 & Origin //!< Disks origin
    ) const {
      for (unsigned i = 0; i < DiskVec.size(); ++i)
        Origin[i] = DiskVec[i].getOriginXYZ();
    }

    //! Get \f$i\f$-th Disk origin \f$(X,Y,Z)\f$ 
    void
    getDiskOriginXYZ(
      int_type const   i,     //!< \f$i\f$-th Disk
      vec3           & Origin //!< Disks origin
    ) const {
        Origin = DiskVec[i].getOriginXYZ();
    }

    //! Set disks origin \f$(X,Y,Z)\f$ 
    void
    setDiskOriginXZ(
      row_vec2 & Origin //!< New Disks origin vector
    ) {
      for (unsigned i = 0; i < DiskVec.size(); ++i)
        DiskVec[i].setOriginXZ(Origin[i]);
    }

    //! Set \f$i\f$-th Disk origin \f$(X,Y,Z)\f$ 
    void
    setDiskOriginXZ(
      int_type const   i,     //!< \f$i\f$-th Disk
      vec2           & Origin //!< New Disks origin vector
    ) {
      DiskVec[i].setOriginXZ(Origin);
    }

    //! Get contact normal versors vector
    void
    getNormal(
      row_vec3 & _NormalVec //!< Contact normal versors vector
    ) const override {
      _NormalVec = NormalVec;
    }

    //! Get \f$i\f$-th Disk contact normal versor
    void
    getDiskNormal(
      int_type const   i,      //!< \f$i\f$-th Disk
      vec3           & _Normal //!< Contact normal versor
    ) const {
      _Normal = NormalVec[i];
    }

    //! Get Magic Formula contact point
    void
    getMFpoint(
      vec3 & _DiskPoint //!< Magic Formula contact point
    ) const override {
      _DiskPoint = DiskPoint;
    }

    //! Get Magic Formula contact points vector
    void
    getMFpoint(
      row_vec3 & _DiskPointVec //!< Magic Formula contact points vector
    ) const override {
      _DiskPointVec = DiskPointVec;
    }

    //! Get \f$i\f$-th Disk Magic Formula contact point
    void
    getDiskMFpoint(
      int_type const   i,         //!< \f$i\f$-th Disk
      vec3           & _DiskPoint //!< Disk Magic Formula contact point
    ) const {
      _DiskPoint = DiskPointVec[i];
    }
    
    //! Get area weighted mean contact friction
    void
    getFriction(
      real_type & _Friction //!< Area weighted mean contact friction
    ) const override;

    //! Get contact frictions vector
    void
    getFriction(
      row_vecN & _Friction //!< Contact frictions vector
    ) const override {
      _Friction = FrictionVec;
    }

    //! Get \f$i\f$-th Disk contact friction
    void
    getDiskFriction(
      int_type  const   i,        //!< \f$i\f$-th Disk
      real_type       & _Friction //!< Disk contact friction
    ) const {
      _Friction = FrictionVec[i];
    }

    //! Get effective contact point reference frame with 4x4 transformation matrix
    void
    getMFeffectiveRF(
      mat4 & PointRF //!< Magic Formula contact point reference frame
    ) const;

    //! Get Magic Formula contact point reference frame with 4x4 transformation matrix
    void
    getMFpointRF(
      mat4 & PointRF //!< Magic Formula contact point reference frame
    ) const override;

    //! Get Magic Formula contact point reference frames vector with 4x4 transformation matrix
    void
    getMFpointRF(
      row_mat4 & PointRF //!< Magic Formula contact point reference frames vector
    ) const override {
    for (unsigned i = 0; i < DiskVec.size(); ++i)
      this->getDiskMFpointRF(i,PointRF[i]);
    }

    //! Get Disk Magic Formula contact point reference frame with 4x4 transformation matrix
    void
    getDiskMFpointRF(
      int_type const   i,      //!< \f$i\f$-th Disk
      mat4           & PointRF //!< Magic Formula contact point reference frame
    ) const;

    //! Get contact depth at center point [\f$m\f$] and it time derivative [\f$m/s\f$] \n
    //! Warning: (if negative the tire does not touch the ground)!
    void
    getRho(
      real_type       & Rho,    //!< Depth at center point [\f$m/s\f$]
      real_type       & RhoDot, //!< Contact depth derivative [\f$m/s\f$]
      real_type const   RhoOld, //!< Previous time step Rho [\f$m\f$]
      real_type const   Time    //!< Time step [\f$s\f$]
    ) const override;

    //! Get contact depths vector [\f$m\f$] and it time derivatives [\f$m/s\f$] \n
    //! Warning: (if negative the tire does not touch the ground)!
    void
    getRho(
      row_vecN        & Rho,    //!< Depth matrix [\f$m/s\f$]
      row_vecN        & RhoDot, //!< Contact depth derivative matrix [\f$m/s\f$]
      row_vecN  const   RhoOld, //!< Previous time step Rho matrix [\f$m\f$]
      real_type const   Time    //!< Time step [\f$s\f$]
    ) const override;

    //! Get \f$i\f$-th Disk contact depth [\f$m\f$] and it time derivative [\f$m/s\f$] \n
    //! Warning: (if negative the tire does not touch the ground)!
    void
    getDiskRho(
      int_type  const   i,      //!< \f$i\f$-th Disk
      real_type       & Rho,    //!< Disk contact depth
      real_type       & RhoDot, //!< Contact depth derivative [\f$m/s\f$]
      real_type const   RhoOld, //!< Previous time step Rho [\f$m\f$]
      real_type const   Time    //!< Time step [\f$s\f$]
    ) const;

    //! Get approximated mean contact area on Disk plane [\f$m^2\f$]
    void
    getArea(
      real_type & _Area //!< Contact area [\f$m^2\f$]
    ) const override {
      _Area = AreaVec.mean();
    }

    //! Get approximated contact areas vector on Disk plane [\f$m^2\f$]
    void
    getArea(
      row_vecN & _AreaVec //!< Contact areas vector [\f$m^2\f$]
    ) const override {
      _AreaVec = AreaVec;
    }

    //! Get approximated contact volume [\f$m^3\f$]
    void
    getVolume(
      real_type & Volume //!< Contact volume [\f$m^3\f$]
    ) const override {
      Volume = AreaVec.sum() * this->getDiskStep();
    }

    //! Get approximated contact volumes vector [\f$m^3\f$]
    void
    getVolume(
      row_vecN & Volume //!< Contact volumes vector [\f$m^3\f$]
    ) const override {
      Volume = AreaVec * this->getDiskStep();
    }

    //! Get effective \f$Y\f$-axis coordinate of contact point [\f$m\f$]
    void
    getMFeffectiveY(
      real_type & effectiveY //!< Effective \f$Y\f$-axis coordinate of contact point [\f$m\f$]
    ) const;

    //! Get effective radius of contact point [\f$m\f$]
    void
    getMFeffectiveR(
      real_type & Radius //!< Effective radius of contact point [\f$m\f$]
    ) const;

    //! Update current tire position and find contact parameters
    bool
    setup( 
      RDF::MeshSurface       & Mesh, //!< MeshSurface object (road)
      mat4             const & TM    //!< 4x4 total transformation matrix
    ) override;

    //! Update current tire position and find contact parameters with 
    //! external plane
    void
    setup(
      vec3      const & Plane_Normal,   //!< Plane normal vector
      vec3      const & Plane_Point,    //!< Plane known point
      real_type const   Plane_Friction, //!< Friction on plane
      mat4      const & TM              //!< 4x4 total transformation matrix
    ) override;

    //! Print contact parameters
    void
    print(
      ostream_type & stream //!< Output stream type
    ) const override;

  private:
    //! Evaluate contact with RoadTriangles
    void
    evaluateContact(
      RDF::TriangleRoad_list const & TriList //!< Shadow/MeshSurface intersected triangles
    ) override;

    //! Perform grid sampling
    void
    gridSampling(
      RDF::TriangleRoad_list const & TriList, //!< Shadow/MeshSurface intersected triangles
      row_vec3                     & planePointVec
    );

  };

}  // namespace TireGround

///
/// eof: PatchTire.hh
///
