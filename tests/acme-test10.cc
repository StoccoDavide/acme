// GEOMETRY TEST 1 - RAY/TRIANGLE INTERSECTION ON TRIANGLE EDGE

#include <fstream>
#include <iostream>
#include <string>

#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_math.hh"
#include "acme_triangle.hh"
#include "acme_box.hh"
#include "acme_AABBtree.hh"
#include "acme_utilities.hh"

using namespace acme;

// Main function
int main()
{
  std::cout
      << " GEOMETRY TEST 10 - AABB TREE TEST" << std::endl;

  // Initialize vertices
  vec3 V1[3];
  V1[0] = vec3(1.0, 0.0, 0.0);
  V1[1] = vec3(0.0, 1.0, 1.0);
  V1[2] = vec3(-1.0, 0.0, 0.0);

  vec3 V2[3];
  V2[0] = vec3(-1.0, 0.0, 0.0);
  V2[1] = vec3(0.0, -1.0, -1.0);
  V2[2] = vec3(1.0, 0.0, 0.0);

  // Initialize triangle
  triangle Triangle1(V1);
  triangle Triangle2(V2);

  // Initialize boxes
  box Box1;
  box Box2;
  Box1.clamp(V1);
  Box2.clamp(V2);

  box::vecptr vecBox;
  vecBox.push_back(box::ptr(new box(Box1)));
  vecBox.push_back(box::ptr(new box(Box2)));

  AABBtree::ptr tree(new AABBtree());
  tree->build(vecBox);
  std::cout
      << "AABB tree 1" << std::endl;
  tree->print(std::cout);

  // Initialize a Boxes to check intersection
  box::vecptr vecBoxInt;
  vec3 min(0.0, 0.5, 0.5);
  vec3 max(0.0, 0.5, 0.5);
  vecBoxInt.push_back(box::ptr(new box(min, max, 0, 0)));

  AABBtree::ptr treeInt(new AABBtree());
  treeInt->build(vecBoxInt);
  std::cout
      << "AABB tree 2" << std::endl;
  treeInt->print(std::cout);

  // Perform intersection
  box::vecpairptr intBoxPair;
  tree->intersection(*treeInt, intBoxPair);

  for (size_t i = 0; i < intBoxPair.size(); ++i)
  {
    std::cout
        << "Intersection " << i << std::endl
        << "Box 1 = " << (*intBoxPair[i].first) << std::endl
        << "Box 2 = " << (*intBoxPair[i].second) << std::endl;
  }

  std::cout
      << std::endl
      << "Triangle 1 = " << Triangle1 << std::endl
      << "Triangle 2 = " << Triangle2 << std::endl
      << "Box 1 = " << Box1 << std::endl
      << "Box 2 = " << Box2 << std::endl
      << std::endl
      << "GEOMETRY TEST 10: Completed" << std::endl;

  // Exit the program
  return 0;
}
