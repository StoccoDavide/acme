#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

#include <acme.hh>
#include <acme_intersection.hh>
#include <acme_math.hh>
#include <acme_segment.hh>
#include <acme_triangle.hh>

#include <CGAL/Cartesian.h>
#include <CGAL/Point_3.h>
#include <CGAL/Segment_3.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Triangle_3.h>
#include <CGAL/intersections.h>

#include "TicToc.hh"

using namespace acme;

typedef CGAL::Cartesian<real> Kernel;
typedef Kernel::Triangle_3 Triangle;
typedef Kernel::Segment_3 Segment;
typedef Kernel::Point_3 Point;

int main()
{
  std::cout << "CGAL VS ACME: SEGMENT-TRIANGLE" << std::endl
            << std::endl;

  // Instantiate TicToc objects
  TicToc tictoc_cgal;
  TicToc tictoc_acme;

  real lower_bound = -10.0;
  real upper_bound = +10.0;
  std::uniform_real_distribution<real> unif(lower_bound, upper_bound);
  std::default_random_engine re;

  int n_samples = 10000;
  acme::vecN time_vec_cgal(n_samples);
  acme::vecN time_vec_acme(n_samples);

  // Perform timing
  real p1x, p1y, p1z, p2x, p2y, p2z, p3x, p3y, p3z, p4x, p4y, p4z, p5x, p5y, p5z;
  for (unsigned int i = 0; i < n_samples; ++i)
  {
    p1x = unif(re);
    p1y = unif(re);
    p1z = unif(re);
    p2x = unif(re);
    p2y = unif(re);
    p2z = unif(re);
    p3x = unif(re);
    p3y = unif(re);
    p3z = unif(re);
    p4x = unif(re);
    p4y = unif(re);
    p4z = unif(re);
    p5x = unif(re);
    p5y = unif(re);
    p5z = unif(re);

    Triangle entity1_cgal(Point(p1x, p1y, p1z), Point(p2x, p2y, p2z), Point(p3x, p3y, p3z));
    Segment entity2_cgal(Point(p4x, p4y, p4z), Point(p5x, p5y, p5z));
    // Start chronometer
    tictoc_cgal.tic();
    auto result_cgal = intersection(entity1_cgal, entity2_cgal);
    // Stop chronometer
    tictoc_cgal.toc();
    // Update single disk timing
    time_vec_cgal[i] = tictoc_cgal.elapsed_ms();

    triangle *entity1_acme = new triangle(point(p1x, p1y, p1z), point(p2x, p2y, p2z), point(p3x, p3y, p3z));
    segment *entity2_acme = new segment(point(p4x, p4y, p4z), point(p5x, p5y, p5z));
    // Start chronometer
    tictoc_acme.tic();
    entity *result_acme = acme::intersection(entity1_acme, entity2_acme);
    // Stop chronometer
    tictoc_acme.toc();
    result_acme->type();
    // Update single disk timing
    time_vec_acme[i] = tictoc_acme.elapsed_ms();
    delete entity1_acme;
    delete entity2_acme;
  }

  real mean_cgal = time_vec_cgal.mean();
  real variance_cgal = 0.0;

  for (unsigned int i = 0; i < time_vec_cgal.size(); ++i)
    variance_cgal += (time_vec_cgal[i] - mean_cgal) * (time_vec_cgal[i] - mean_cgal);

  variance_cgal /= time_vec_cgal.size();
  real std_dev_cgal = std::sqrt(variance_cgal);

  // Output performance data
  std::cout << "CGAL DATA" << std::endl
            << "Total time    = " << time_vec_cgal.sum() << " ms" << std::endl
            << "Avg step time = " << mean_cgal << " ms" << std::endl
            << "Variance      = " << variance_cgal << " ms" << std::endl
            << "Std_dev       = " << std_dev_cgal << " ms" << std::endl
            << "Samples       = " << time_vec_cgal.size() << std::endl
            << std::endl;

real mean_acme = time_vec_acme.mean();
real variance_acme = 0.0;

for (unsigned int i = 0; i < time_vec_acme.size(); ++i)
  variance_acme += (time_vec_acme[i] - mean_acme) * (time_vec_acme[i] - mean_acme);

variance_acme /= time_vec_acme.size();
real std_dev_acme = std::sqrt(variance_acme);

// Output performance data
std::cout << "ACME DATA" << std::endl
          << "Total time    = " << time_vec_acme.sum() << " ms" << std::endl
          << "Avg step time = " << mean_acme << " ms" << std::endl
          << "Variance      = " << variance_acme << " ms" << std::endl
          << "Std_dev       = " << std_dev_acme << " ms" << std::endl
          << "Samples       = " << time_vec_acme.size() << std::endl
          << std::endl;

return 0;
}