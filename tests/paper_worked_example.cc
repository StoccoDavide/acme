#include "acme.hh"
#include "acme_intersection.hh"
#include "acme_disk.hh"
#include "acme_utils.hh"

using namespace acme;

int main()
{
  entity *d1 = new disk(2, point(0, 0, 0), vec3(0, 1, 0));
  entity *d2 = new disk(1, point(0, 0, 0), vec3(1, 1, 0));

  entity *e1 = acme::intersection(d1, d2);

  std::cout << "Ouput entity is of type: "
            << e1->type() << "\n";

  return 0;
}