#include "acme.hh"
#include "acme_utilities.hh"

using namespace acme;

int main (void) {
	Float x = 100.0;
	Float y = 0.0;
	Float z = 0.0;
	point3d point1;
	point1.x =1;
	point3d<Float> point2;// = make_point<Float>( 0.0, 10.0,  0.0);
	point3d<Float> point3;// = make_point<Float>( 0.0,  0.0, 10.0);

	//triangle3d triangle = make_triangle<Float>(point1, point2, point3);

	//std::cout<<triangle;


	return 0;
}
