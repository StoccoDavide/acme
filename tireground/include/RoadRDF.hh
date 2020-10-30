///
/// file: RoadRDF.hh
///

#pragma once

#include <AABBtree.hh>
#include "TireGround.hh"

// Print progress to console while loading (large models)
#define RDF_CONSOLE_OUTPUT

// Print rdf errors
#ifndef RDF_ERROR
  #define RDF_ERROR(MSG) {                 \
    std::ostringstream ost; ost << MSG;    \
    throw std::runtime_error( ost.str() ); \
  }
#endif

// Check for rdf errors
#ifndef RDF_ASSERT
  #define RDF_ASSERT(COND,MSG) \
    if ( !(COND) ) RDF_ERROR( MSG )
#endif

//! Tire computations routines
namespace TireGround {

  //! RDF mesh computations routines
  namespace RDF {

    class TriangleRoad;

    typedef std::shared_ptr<TriangleRoad> TriangleRoad_ptr;  //!< Shared pointer to TriangleRoad object
    typedef std::vector<TriangleRoad_ptr> TriangleRoad_list; //!< Vector of shared pointers to TriangleRoad objects 

    /*\
    |  ____  ____            ____  ____  
    | | __ )| __ )  _____  _|___ \|  _ \ 
    | |  _ \|  _ \ / _ \ \/ / __) | | | |
    | | |_) | |_) | (_) >  < / __/| |_| |
    | |____/|____/ \___/_/\_\_____|____/ 
    |                                    
    \*/

    //! 2D Bounding Box class
    class BBox2D {
    private:
      real_type Xmin; //!< \f$X_{min}\f$ shadow domain point
      real_type Ymin; //!< \f$Y_{min}\f$ shadow domain point
      real_type Xmax; //!< \f$X_{max}\f$ shadow domain point
      real_type Ymax; //!< \f$Y_{max}\f$ shadow domain point

    public:

      //! Default constructor
      BBox2D() {}

      //! Variable set constructor
      BBox2D(
        vec3 const Vertices[3] //!< Vertices reference vector
      ) {
        updateBBox2D( Vertices );
      }

      //! Set \f$X_{min}\f$ shadow domain
      void
      setXmin(real_type const _Xmin) { Xmin = _Xmin; }

      //! Set \f$Y_{min}\f$ shadow domain
      void
      setYmin(real_type const _Ymin) { Ymin = _Ymin; }

      //! Set \f$X_{max}\f$ shadow domain
      void
      setXmax(real_type const _Xmax) { Xmax = _Xmax; }

      //! Set \f$Y_{max}\f$ shadow domain
      void
      setYmax(real_type const _Ymax) { Ymax = _Ymax; }

      //! Get \f$X_{min}\f$ shadow domain
      real_type
      getXmin(void) const { return Xmin; }

      //! Get \f$Y_{min}\f$ shadow domain
      real_type
      getYmin(void) const { return Ymin; }

      //! Get \f$X_{max}\f$ shadow domain
      real_type
      getXmax(void) const { return Xmax; }

      //! Get \f$Y_{max}\f$ shadow domain
      real_type
      getYmax(void) const { return Ymax; }

      //! Clear the bounding box domain
      void clear(void);

      //! Print bounding box domain
      void
      print(
        ostream_type & stream //!< Output stream type
      ) const {
        stream
          << "BBOX (xmin,ymin,xmax,ymax) = ( " << Xmin << ", " << Ymin
          << ", " << Xmax << ", " << Ymax << " )\n";
      }

      //! Update the bounding box domain with three input vertices
      void
      updateBBox2D( 
        vec3 const Vertices[3] //!< Vertices reference vector
        );
    };

    /*\
    |   _____     _                   _      _____ ____  
    |  |_   _| __(_) __ _ _ __   __ _| | ___|___ /|  _ \ 
    |    | || '__| |/ _` | '_ \ / _` | |/ _ \ |_ \| | | |
    |    | || |  | | (_| | | | | (_| | |  __/___) | |_| |
    |    |_||_|  |_|\__,_|_| |_|\__, |_|\___|____/|____/ 
    |                           |___/                    
    \*/

    //! 3D triangle (pure geometrical description)
    class Triangle3D {
    protected:
      vec3   Vertices[3];  //!< Vertices reference vector
      vec3   Normal;       //!< Triangle normal versor
      BBox2D TriangleBBox; //!< Triangle 2D bounding box (\f$XY\f$ plane)

      Triangle3D( Triangle3D const & ) = delete;               //!< Deleted copy constructor
      Triangle3D & operator = ( Triangle3D const & ) = delete; //!< Deleted copy operator

    public:
      //! Variable set constructor
      Triangle3D() {
        Vertices[0] = vec3(0,0,0);
        Vertices[1] = vec3(0,0,0);
        Vertices[2] = vec3(0,0,0);
        Normal      = vec3(0,0,0);
        TriangleBBox.updateBBox2D(Vertices);
      }

      //! Variable set constructor
      Triangle3D(
        vec3 const _Vertices[3] //!< Vertices reference vector
      ) {
        Vertices[0] = _Vertices[0];
        Vertices[1] = _Vertices[1];
        Vertices[2] = _Vertices[2];
        TriangleBBox.updateBBox2D(Vertices);
        calcNormal();
      }

      //! Set new vertices and update bounding box domain
      void
      setVertices( 
        vec3 const _Vertices[3] //!< Vertices reference vector
      ) {
        Vertices[0] = _Vertices[0];
        Vertices[1] = _Vertices[1];
        Vertices[2] = _Vertices[2];
        TriangleBBox.updateBBox2D(Vertices);
        calcNormal();
      }

      //! Set new vertices then update bounding box domain and normal versor
      void
      setVertices(
        vec3 const & Vertex0, //!< Vertex 1
        vec3 const & Vertex1, //!< Vertex 2
        vec3 const & Vertex2  //!< Vertex 3
      ) {
        Vertices[0] = Vertex0;
        Vertices[1] = Vertex1;
        Vertices[2] = Vertex2;
        TriangleBBox.updateBBox2D(Vertices);
        calcNormal();
      }

      //! Get normal versor
      vec3 const &
      getNormal(void) const { return Normal; }

      //! Get i-th vertex
      vec3 const &
      getVertex( unsigned i ) const { return Vertices[i]; }

      //! Get Triangle3D bonding box BBox2D
      BBox2D const &
      getBBox(void) const { return TriangleBBox; }

      //! Print vertices data
      void
      print(
        ostream_type & stream //!< Output stream type
      ) const {
        stream
          << "V0:\t" << Vertices[0].x() << ", " << Vertices[0].y() << ", " << Vertices[0].z() << "\n"
          << "V0:\t" << Vertices[1].x() << ", " << Vertices[1].y() << ", " << Vertices[1].z() << "\n"
          << "V0:\t" << Vertices[2].x() << ", " << Vertices[2].y() << ", " << Vertices[2].z() << "\n";
      }

      //! Check if a ray hits a Triangle3D object through Möller-Trumbore
      //! intersection algorithm
      bool
      intersectRay(
        vec3 const & RayOrigin,    //!< Ray origin position
        vec3 const & RayDirection, //!< Ray direction vector
        vec3       & IntPt         //!< Intersection point
      ) const;

      //! Check if an edge of the Triangle3D object hits a and find the 
      //! intersection point
      int_type
      intersectEdgePlane(
        vec3     const & PlaneN, //!< Plane normal vector
        vec3     const & PlaneP, //!< Plane known point
        int_type const   Edge,   //!< Triangle edge number (0:2)
        vec3           & IntPt1, //!< Intersection point 1
        vec3           & IntPt2  //!< Intersection point 2
      ) const;

      //! Check if a plane intersects a Triangle3D object and find the
      //! intersection points
      bool
      intersectPlane(
        vec3        const & PlaneN, //!< Plane normal vector
        vec3        const & PlaneP, //!< Plane known point
        std::vector<vec3> & IntPts  //!< Intersection points
      ) const;

      private:

      //! Calculate Triangle3D object face normal versor
      void
      calcNormal(void) {
        Normal = ((Vertices[1] - Vertices[0]).cross(Vertices[2] - Vertices[0])).normalized();
        if (Normal.z() < 0) Normal *= -1;
      }

    };

    /*\
    |   _____     _                   _      ____                 _
    |  |_   _| __(_) __ _ _ __   __ _| | ___|  _ \ ___   __ _  __| |
    |    | || '__| |/ _` | '_ \ / _` | |/ _ \ |_) / _ \ / _` |/ _` |
    |    | || |  | | (_| | | | | (_| | |  __/  _ < (_) | (_| | (_| |
    |    |_||_|  |_|\__,_|_| |_|\__, |_|\___|_| \_\___/ \__,_|\__,_|
    |                           |___/
    \*/
    //! 3D triangles for road representation
    class TriangleRoad : public Triangle3D {
    private:
      real_type Friction; //!< Face friction coefficient

      TriangleRoad( TriangleRoad const & ) = delete;               //!< Deleted copy constructor
      TriangleRoad & operator = ( TriangleRoad const & ) = delete; //!< Deleted copy operator

    public:
      //! Default set constructor
      TriangleRoad() : Triangle3D()
      { Friction = 0.0; }

      //! Variable set constructor
      TriangleRoad(
        vec3 const _Vertices[3], //!< Vertices reference vector
        real_type  _Friction     //!< Friction coefficient
      ) : Triangle3D( _Vertices ) {
        Friction = _Friction;
      }

      //! Set friction coefficient
      void
      setFriction(
        real_type _Friction //!< New friction coefficient
      ) { Friction = _Friction; }

      //! Get friction coefficent on the face
      real_type
      getFriction(void) const { return Friction; }
    };

    /*\
    |         _                  _ _   _
    |    __ _| | __ _  ___  _ __(_) |_| |__  _ __ ___  ___
    |   / _` | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \/ __|
    |  | (_| | | (_| | (_) | |  | | |_| | | | | | | | \__ \
    |   \__,_|_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|___/
    |           |___/
    \*/

    //! Algorithms for RDF mesh computations routine
    namespace algorithms {

      //! Split a string into a string array at a given token
      void
      split(
        std::string              const & in,   //!< Input string
        std::vector<std::string>       & out,  //!< Output string vector
        std::string              const & token //!< Token
      );

      //! Get tail of string after first token and possibly following spaces
      std::string
      tail(
        std::string const & in //!< Input string
      );

      //! Get first token of string
      std::string
      firstToken(
        std::string const & in //!< Input string
      );

      //! Get element at given index position
      template<typename T>
      T const &
      getElement(
        std::vector<T> const & elements, //!< Elements vector
        std::string    const & index     //!< Index position
      );
    }  // namespace algorithms

    /*\
    |   __  __           _     ____              __                
    |  |  \/  | ___  ___| |__ / ___| _   _ _ __ / _| __ _  ___ ___ 
    |  | |\/| |/ _ \/ __| '_ \\___ \| | | | '__| |_ / _` |/ __/ _ \
    |  | |  | |  __/\__ \ | | |___) | |_| | |  |  _| (_| | (_|  __/
    |  |_|  |_|\___||___/_| |_|____/ \__,_|_|  |_|  \__,_|\___\___|
    |                                                              
    \*/

    //! Mesh surface
    class MeshSurface {
    private:
      TriangleRoad_list                 PtrTriangleVec; //!< Road triangles pointer vector
      std::vector<G2lib::BBox::PtrBBox> PtrBBoxVec;     //!< Bounding boxes pointers
      G2lib::AABBtree::PtrAABB          PtrTree;        //!< Mesh tree pointer

      MeshSurface( MeshSurface const & ) = delete;               //!< Deleted copy constructor
      MeshSurface & operator = ( MeshSurface const & ) = delete; //!< Deleted copy operator

    public:
      //! Default set constructor
      MeshSurface()
      : PtrTree( std::make_shared<G2lib::AABBtree>() )
      {};

      //! Variable set constructor
      MeshSurface(
        TriangleRoad_list const & _PtrTriangleVec //!< Road triangles pointer vector list
      ) : MeshSurface() {
        this->PtrTriangleVec = _PtrTriangleVec;
        updatePtrBBox();
        PtrTree->build(PtrBBoxVec);
      };

      //! Variable set constructor
      MeshSurface(
        std::string const & Path //!< Path to the RDF file
      ) : MeshSurface() {
        bool load = LoadFile(Path);
        RDF_ASSERT( load, "Error while reading file" );
      }

      //! Get all triangles inside the mesh as a vector
      TriangleRoad_list const &
      getTrianglesList(void) const
      { return PtrTriangleVec; }

      //! Get i-th TriangleRoad
      TriangleRoad_ptr const
      getTriangle( unsigned i ) const
      { return PtrTriangleVec[i]; }

      //! Get AABBtree object
      G2lib::AABBtree::PtrAABB const
      getAABBPtr(void) const
      { return PtrTree; }

      //! Print data in file
      void 
      printData(
        std::string const & FileName //!< File name in which print data
      ) const;

      //! Get the mesh G2lib bounding boxes pointers vector
      std::vector<G2lib::BBox::PtrBBox> const &
      getPtrBBoxList() const
      { return PtrBBoxVec; }

      //! Copy the MeshSurface object
      void
      set(
        MeshSurface const & in //!< MeshSurface object to be copied
      ) {
        this->PtrTriangleVec = in.PtrTriangleVec;
        this->PtrBBoxVec     = in.PtrBBoxVec;
        this->PtrTree        = in.PtrTree;
      }

      //! Load the RDF model and print information on a file
      bool
      LoadFile(
        std::string const & Path //!< Path to the RDF file
      );

      //! Intersect the mesh AABB tree with an external AABB tree
      bool
      intersectAABBtree(
        G2lib::AABBtree::PtrAABB const & AABBTreePtr,  //!< External AABBtree object pointer
        RDF::TriangleRoad_list         & TrianglesList //!< Intersected TriangleRoad vector list
      ) const;

      //! Update the mesh AABBtree with an external G2lib::BBox object pointer vector
      bool
      intersectBBox(
        std::vector<G2lib::BBox::PtrBBox> const & BBoxPtr,      //!< External G2lib::BBox object pointer vector
        RDF::TriangleRoad_list                  & TrianglesList //!< Intersected TriangleRoad vector list
      ) const;

    private:
      //! Update the mesh G2lib bounding boxes pointers
      void updatePtrBBox(void);

      //! Generate vertices
      void
      GenVerticesFromRawRDF(
        std::vector<vec3> const & iNodes,   //!< Nodes list
        std::string       const & icurline, //!< Current line
        vec3                      oVerts[3] //!< Vertex
      );
    };

  }  // namespace RDF

} // namespace TireGround

///
/// eof: RoadRDF.hh
///