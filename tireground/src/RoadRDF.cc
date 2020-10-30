#include "RoadRDF.hh" 

namespace TireGround {

  namespace RDF {

    /*\
    |  ____  ____            ____  ____  
    | | __ )| __ )  _____  _|___ \|  _ \ 
    | |  _ \|  _ \ / _ \ \/ / __) | | | |
    | | |_) | |_) | (_) >  < / __/| |_| |
    | |____/|____/ \___/_/\_\_____|____/ 
    |                                    
    \*/

    void
    BBox2D::clear(
      void
    ) {
      Xmin = std::numeric_limits<real_type>::quiet_NaN();
      Ymin = std::numeric_limits<real_type>::quiet_NaN();
      Xmax = std::numeric_limits<real_type>::quiet_NaN();
      Ymax = std::numeric_limits<real_type>::quiet_NaN();
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void
    BBox2D::updateBBox2D(
      vec3 const Vertices[3]
    ) {
      G2lib::minmax3( Vertices[0].x(), Vertices[1].x(), Vertices[2].x(), Xmin, Xmax );
      G2lib::minmax3( Vertices[0].y(), Vertices[1].y(), Vertices[2].y(), Ymin, Ymax );
    }

    /*\
    |   _____     _                   _      _____ ____  
    |  |_   _| __(_) __ _ _ __   __ _| | ___|___ /|  _ \ 
    |    | || '__| |/ _` | '_ \ / _` | |/ _ \ |_ \| | | |
    |    | || |  | | (_| | | | | (_| | |  __/___) | |_| |
    |    |_||_|  |_|\__,_|_| |_|\__, |_|\___|____/|____/ 
    |                           |___/                    
    \*/

    bool
    Triangle3D::intersectRay(
      vec3 const & RayOrigin,
      vec3 const & RayDirection,
      vec3       & IntPt
    ) const {
      vec3 E1(Vertices[1] - Vertices[0]);
      vec3 E2(Vertices[2] - Vertices[0]);
      vec3 A(RayDirection.cross(E2));
      real_type det = A.dot(E1);
      real_type t_param;

      if ( det > epsilon ) {
        vec3 T(RayOrigin - Vertices[0]);
        real_type u = A.dot(T);
        if ( u < 0.0 || u > det ) return false;
        vec3 B(T.cross(E1));
        real_type v = B.dot(RayDirection);
        if ( v < 0.0 || u + v > det ) return false;
        t_param = (B.dot(E2)) / det;
      } else if (det < -epsilon) {
        vec3 T(RayOrigin - Vertices[0]);
        real_type u = A.dot(T);
        if ( u > 0.0 || u < det ) return false;
        vec3 B(T.cross(E1));
        real_type v = B.dot(RayDirection);
        if ( v > 0.0 || u + v < det ) return false;
        t_param = (B.dot(E2)) / det;
      } else {
        return false;
      }
      // At this stage we can compute t to find out where the intersection
      // point is on the line
      if ( t_param >= 0 ) {  // ray intersection
        IntPt = RayOrigin + RayDirection * t_param;
        return true;
      } else {
        // This means that there is a line intersection on negative side
        return false;
      }
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    int_type
    Triangle3D::intersectEdgePlane(
      vec3     const & PlaneN,
      vec3     const & PlaneP,
      int_type const   Edge,
      vec3           & IntPt_1,
      vec3           & IntPt_2
    ) const {
      // Check that edge number is between 0 and 2
      RDF_ASSERT( (Edge >=0 && Edge <= 2) , "Side number must be between 0 and 2.")
      // If it does not lays 
      vec3 const & PointA = Vertices[Edge];
      vec3 const & PointB = Vertices[(Edge+1) % 3]; // Operatore modulo 
      vec3 Direction(PointB - PointA);

      // Check if the segment lays on the plane
      if ( (PlaneN - Normal).norm() < epsilon &&
          Direction.dot(PlaneN) < epsilon ) {
        IntPt_1 = PointA;
        IntPt_2 = PointB;
        return 2;
      }
      // If it does not lay on the plane, then find the single point
      real_type d = -PlaneP.dot(PlaneN);
      real_type t = -(PointA.dot(PlaneN) + d) / (Direction.dot(PlaneN));
      if ( t >= 0 && t <= 1 ) {
        IntPt_1 = PointA + Direction * t;
        return 1;
      } else {
        return 0;
      }
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    bool
    Triangle3D::intersectPlane(
      vec3        const & PlaneN,
      vec3        const & PlaneP,
      std::vector<vec3> & IntPts
    ) const {
      // Clear intersection points vector
      IntPts.clear();
      // Check if the triangle lays on the plane
      if ( (Normal-PlaneN).norm() < epsilon &&
          (Vertices[0]-PlaneP).dot(PlaneN) < epsilon ) { 
        IntPts.push_back(Vertices[0]);
        IntPts.push_back(Vertices[1]);
        IntPts.push_back(Vertices[2]);
        return true; 
      } else {
        int_type number;
        vec3 IntPt1, IntPt2;
        // Fill intersection points vector and check the results (there must be only 2 intersection points)
        for (int_type i = 0; i < 3; i++)
        {
          number = intersectEdgePlane( PlaneN, PlaneP, i, IntPt1, IntPt2 );
          switch (number) {
          case 0:
            break;
          case 1:
            IntPts.push_back(IntPt1);
            break;
          case 2:
            IntPts.push_back(IntPt1);
            IntPts.push_back(IntPt2);
            break;
          default:
            RDF_ERROR("\nTriangle-Plane intersection not handled.")
            break;
          }
        }
        if ( IntPts.size() == 2 ) { 
          return true;
        } else if ( IntPts.size() == 0 ) {
          return false;
        } else {
          RDF_ERROR(
            "\nTriangle-Plane intersection not handled. There are " <<
            IntPts.size() << " intersections."
          );
          return false; 
        }
      }
    }

    /*\
    |         _                  _ _   _                   
    |    __ _| | __ _  ___  _ __(_) |_| |__  _ __ ___  ___ 
    |   / _` | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \/ __|
    |  | (_| | | (_| | (_) | |  | | |_| | | | | | | | \__ \
    |   \__,_|_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|___/
    |           |___/                                      
    \*/

    namespace algorithms {

      void
      split(
        std::string const        & in,
        std::vector<std::string> & out,
        std::string const        & token
      ) {
        out.clear();
        std::string temp;

        for ( int i = 0; i < int(in.size()); ++i ) {
          std::string test = in.substr(i, token.size());
          if (test == token) {
            if (!temp.empty()) {
              out.push_back(temp);
              temp.clear();
              i += (int)token.size() - 1;
            } else {
              out.push_back("");
            }
          } else if (i + token.size() >= in.size()) {
            temp += in.substr(i, token.size());
            out.push_back(temp);
            break;
          } else {
            temp += in[i];
          }
        }
      }

      // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

      std::string
      tail(
        std::string const & in
      ) {
        size_t token_start = in.find_first_not_of(" \t");
        size_t space_start = in.find_first_of(" \t", token_start);
        size_t tail_start  = in.find_first_not_of(" \t", space_start);
        size_t tail_end    = in.find_last_not_of(" \t");
        if (tail_start != std::string::npos && tail_end != std::string::npos) {
          return in.substr(tail_start, tail_end - tail_start + 1);
        } else if (tail_start != std::string::npos) {
          return in.substr(tail_start);
        }
        return "";
      }

      // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

      std::string
      firstToken(
        std::string const & in
      ) {
        if (!in.empty()) {
          size_t token_start = in.find_first_not_of(" \t\r\n");
          if (token_start != std::string::npos) {
            size_t token_end = in.find_first_of(" \t\r\n", token_start);
            if (token_end != std::string::npos) {
              return in.substr(token_start, token_end - token_start);
            } else {
              return in.substr(token_start);
            }
          }
        }
        return "";
      }

      // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

      template<typename T>
      T const &
      getElement(
        std::vector<T> const & elements,
        std::string    const & index
      ) {
        int_type id = std::stoi(index);
        if ( id < 0 ) std::cerr << "ELEMENTS indexes cannot be negative\n";
        return elements[id - 1];
      }

    }  // namespace algorithms

    /*\
    |   __  __           _     ____              __                
    |  |  \/  | ___  ___| |__ / ___| _   _ _ __ / _| __ _  ___ ___ 
    |  | |\/| |/ _ \/ __| '_ \\___ \| | | | '__| |_ / _` |/ __/ _ \
    |  | |  | |  __/\__ \ | | |___) | |_| | |  |  _| (_| | (_|  __/
    |  |_|  |_|\___||___/_| |_|____/ \__,_|_|  |_|  \__,_|\___\___|
    |                                                              
    \*/

    void
    MeshSurface::printData(
      std::string const & FileName
    ) const {
      // Create Out.txt
      std::ofstream file(FileName);
      // Print introduction
      file
        << "LOADED RDF MESH DATA\n\n"
        << "Legend:\n"
        << "\tVi: i-th vertex\n"
        << "\t N: normal to the face\n"
        << "\t F: friction coefficient\n\n";
      for ( unsigned i = 0; i < PtrTriangleVec.size(); ++i ) {
        TriangleRoad const & Ti = *PtrTriangleVec[i];
        vec3 const & V0 = Ti.getVertex(0);
        vec3 const & V1 = Ti.getVertex(1);
        vec3 const & V2 = Ti.getVertex(2);
        vec3 const &  N = Ti.getNormal();
        // Print vertices, normal and friction
        file
          << "TRIANGLE " << i
          << "\n\tV0:\t" << V0.x() << ", " << V0.y() << ", " << V0.z()
          << "\n\tV1:\t" << V1.x() << ", " << V1.y() << ", " << V1.z()
          << "\n\tV2:\t" << V2.x() << ", " << V2.y() << ", " << V2.z()
          << "\n\t N:\t" << N.x()  << ", " << N.y()  << ", " << N.z()
          << "\n\t F:\t" << Ti.getFriction()
          << "\n\n";
      }
      // Close File
      file.close();
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void
    MeshSurface::updatePtrBBox(
      void
    ) {
      PtrBBoxVec.clear();
      RDF::BBox2D iBBox;
      for (unsigned id = 0; id < PtrTriangleVec.size(); ++id) {
        iBBox = (*PtrTriangleVec[id]).getBBox();
        PtrBBoxVec.push_back(G2lib::BBox::PtrBBox(
          new G2lib::BBox(
            iBBox.getXmin(),
            iBBox.getYmin(),
            iBBox.getXmax(),
            iBBox.getYmax(),
            id, 0
          )
        ));
        iBBox.clear();
      }
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    bool
    MeshSurface::LoadFile(
      std::string const & Path
    ) {
      // Check if the file is an ".rdf" file, if not return false
      if (Path.substr(Path.size() - 4, 4) != ".rdf") {
        std::cerr << "Not a RDF file\n";
        return false;
      }
      // Check if the file had been correctly open, if not return false
      std::ifstream file(Path);
      if (!file.is_open()) {
        std::cerr << "RDF file not opened\n";
        return false;
      }
      // Vector for nodes coordinates
      std::vector<vec3> Nodes;
      bool nodes_parse    = false;
      bool elements_parse = false;

  #ifdef RDF_CONSOLE_OUTPUT
      int_type const outputEveryNth = 5000;
      int_type outputIndicator      = outputEveryNth;
  #endif
      std::string curline;
      while (std::getline(file, curline)) {
  #ifdef RDF_CONSOLE_OUTPUT
        if ((outputIndicator = ((outputIndicator + 1) % outputEveryNth)) == 1) {
          std::cout
            << "\r- "
            << "Loading mesh..."
            << "\t triangles > "
            << PtrTriangleVec.size() << std::endl;
        }
  #endif
        std::string token = algorithms::firstToken(curline);
        if ( token == "[NODES]" || token == "NODES" ) {
          nodes_parse    = true;
          elements_parse = false;
          continue;
        } else if (token == "[ELEMENTS]" || token == "ELEMENTS") {
          nodes_parse    = false;
          elements_parse = true;
          continue;
        } else if (token[0] == '{') {
          // commento multiriga, continua a leggere fino a che trovo '}'
          continue;
        } else if (token[0] == '%' || token[0] == '#' || token[0] == '\r') {
          // Check comments or empty lines
          continue;
        }
        // Generate a vertex position
        if (nodes_parse) {
          std::vector<std::string> spos;
          vec3 vpos;
          algorithms::split(algorithms::tail(curline), spos, " ");
          vpos[0] = std::stod(spos[0]);
          vpos[1] = std::stod(spos[1]);
          vpos[2] = std::stod(spos[2]);
          Nodes.push_back(vpos);
        }
        // Generate a face (vertices & indices)
        if (elements_parse) {
          // Generate the triangle vertices from the elements
          vec3 iVerts[3];
          GenVerticesFromRawRDF( Nodes, curline, iVerts );
          // Get the triangle friction from current line
          std::vector<std::string> curlinevec;
          algorithms::split(curline, curlinevec, " ");
          real_type iFriction = std::stod(curlinevec[4]);
          // Create a shared pointer for the last triangle and push it in the pointer vector
          PtrTriangleVec.push_back(TriangleRoad_ptr(new TriangleRoad(iVerts,iFriction)));
        }
      }
  #ifdef RDF_CONSOLE_OUTPUT
      std::cout << std::endl;
  #endif
      file.close();
      if (PtrTriangleVec.empty()) {
        perror("Loaded mesh is empty");
        return false;
      } else {
        // Update the local intersected triangles list
  #ifdef RDF_CONSOLE_OUTPUT
      std::cout << std::endl << "Building AABB tree... ";
  #endif
        updatePtrBBox();
        PtrTree->build(PtrBBoxVec);
  #ifdef RDF_CONSOLE_OUTPUT
      std::cout << "Done" << std::endl << std::endl;
  #endif
        return true;
      }
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void
    MeshSurface::GenVerticesFromRawRDF(
      std::vector<vec3> const & iNodes,
      std::string       const & icurline,
      vec3                      oVerts[3]
    ) {
      std::vector<std::string> svert;
      vec3                     vVert;
      algorithms::split( icurline, svert, " " );

      int_type control_size = int(svert.size() - 4);
      for ( int i = 1; i < int(svert.size() - control_size); ++i ) {
        // Calculate and store the vertex
        vVert = algorithms::getElement(iNodes, svert[i]);
        oVerts[i-1] = vVert;
      }
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    bool
    MeshSurface::intersectAABBtree(
      G2lib::AABBtree::PtrAABB const & AABBTreePtr,
      RDF::TriangleRoad_list         & TrianglesList
    ) const {
      TrianglesList.clear();
      G2lib::AABBtree::VecPairPtrBBox intersectionList;
      PtrTree->intersect(*AABBTreePtr, intersectionList);
      for (unsigned i = 0; i < intersectionList.size(); ++i)
        TrianglesList.push_back( getTriangle((*intersectionList[i].first).Id()) );
      if (TrianglesList.size() > 0) {
        return true;
      } else {
        return false;
      }
    }

    // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    bool
    MeshSurface::intersectBBox(
        std::vector<G2lib::BBox::PtrBBox> const & BBoxPtr,
        RDF::TriangleRoad_list                  & TrianglesList
    ) const {
      TrianglesList.clear();
      G2lib::AABBtree::PtrAABB AABBTreePtr;
      AABBTreePtr->build(BBoxPtr);
      G2lib::AABBtree::VecPairPtrBBox intersectionList;
      PtrTree->intersect(*AABBTreePtr, intersectionList);
      for (unsigned i = 0; i < intersectionList.size(); ++i)
        TrianglesList.push_back( getTriangle((*intersectionList[i].first).Id()) );
      if (TrianglesList.size() > 0) {
        return true;
      } else {
        return false;
      }
    }

  }  // namespace RDF

}  // namespace TireGround