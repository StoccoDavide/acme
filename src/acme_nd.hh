#ifndef INCLUDE_WYKOBI_ND
#define INCLUDE_WYKOBI_ND


#include <vector>
#include <limits>
#include <algorithm>
#include <cassert>

#include "acme.hh"
#include "acme_math.hh"


namespace acme
{
   template <typename T, std::size_t D>
   bool parallel(const line<T,D>& line1, const line<T,D>& line2);

   template <typename T, std::size_t D>
   bool parallel(const segment<T,D>& segment1, const segment<T,D>& segment2);

   template <typename T, std::size_t D>
   bool perpendicular(const line<T,D>& line1, const line<T,D>& line2);

   template <typename T, std::size_t D>
   bool perpendicular(const segment<T,D>& segment1, const segment<T,D>& segment2);

   template <typename T, std::size_t D>
   bool collinear(const pointnd<T,D>& point1, const pointnd<T,D>& point2, const pointnd<T,D>& point3);

   template <typename T, std::size_t D>
   bool robust_collinear(const pointnd<T,D>& point1, const pointnd<T,D>& point2, const pointnd<T,D>& point3);

   template <typename T, std::size_t D>
   bool is_point_collinear(const segment<T,D>& segment, const pointnd<T,D>& point, const bool robust = false);

   template <typename T, std::size_t D>
   bool intersect(const segment<T,D>& segment1, const segment<T,D>& segment2, const T& fuzzy = T(0.0));

   template <typename T, std::size_t D>
   bool intersect(const line<T,D>& line1, const line<T,D>& line2, const T& fuzzy = T(0.0));

   template <typename T, std::size_t D>
   pointnd<T,D> intersection_point(const segment<T,D>& segment1, const segment<T,D>& segment2, const T& fuzzy = T(0.0));

   template <typename T, std::size_t D>
   pointnd<T,D> intersection_point(const line<T,D>& line1, const line<T,D>& line2, const T& fuzzy = T(0.0));

   template <typename T, std::size_t D>
   T distance(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   T distance(const pointnd<T,D>& point, const segment<T,D>& segment);

   template <typename T, std::size_t D>
   T distance(const pointnd<T,D>& point, const line<T,D>& line);

   template <typename T, std::size_t D>
   T distance(const segment<T,D>& segment1, const segment<T,D>& segment2);

   template <typename T, std::size_t D>
   T distance(const line<T,D>& line1, const line<T,D>& line2);

   template <typename T, std::size_t D>
   T lay_distance(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   T lay_distance(const pointnd<T,D>& point, const segment<T,D>& segment);

   template <typename T, std::size_t D>
   T lay_distance(const pointnd<T,D>& point, const line<T,D>& line);

   template <typename T, std::size_t D>
   T lay_distance(const segment<T,D>& segment1, const segment<T,D>& segment2);

   template <typename T, std::size_t D>
   T lay_distance(const line<T,D>& line1, const line<T,D>& line2);

   template <typename T, std::size_t D>
   T manhattan_distance(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   T chebyshev_distance(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   T manhattan_distance(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   T inverse_chebyshev_distance(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   bool point_in_box(const pointnd<T,D>& point, const box<T,D>& box);

   template <typename T, std::size_t D>
   pointnd<T,D> closest_point_on_segment_from_point(const segment<T,D>& segment, const pointnd<T,D>& point);

   template <typename T, std::size_t D>
   pointnd<T,D> closest_point_on_line_from_point(const line<T,D>& segment, const pointnd<T,D>& point);

   template <typename T, std::size_t D>
   pointnd<T,D> closest_point_on_plane_from_point(const plane<T,D>& plane, const pointnd<T,D>& point);

   template <typename T, std::size_t D>
   pointnd<T,D> closest_point_on_box_from_point(const box<T,D>& box, const pointnd<T,D>& point);

   template <typename T, std::size_t D>
   pointnd<T,D> project_point_t(const pointnd<T,D>& source_point,
                                       const pointnd<T,D>& destination_point,
                                       const T& t);

   template <typename T, std::size_t D>
   pointnd<T,D> project_point(const pointnd<T,D>& source_point,
                                     const pointnd<T,D>& destination_point,
                                     const T& distance);

   template <typename T, std::size_t D>
   pointnd<T,D> mirror(const pointnd<T,D>& point, const line<T,D>& mirror_axis);

   template <typename T, std::size_t D>
   segment<T,D> mirror(const segment<T,D>& segment, const line<T,D>& mirror_axis);

   template <typename T, std::size_t D>
   line<T,D> mirror(const line<T,D>& line, const acme::line<T,D>& mirror_axis);

   template <typename T, std::size_t D>
   box<T,D> mirror(const box<T,D>& box, const line<T,D>& mirror_axis);

   template <typename T, std::size_t D>
   triangle<T,D> mirror(const triangle<T,D>& triangle, const line<T,D>& mirror_axis);

   template <typename T, std::size_t D>
   quadix<T,D> mirror(const quadix<T,D>& quadix, const line<T,D>& mirror_axis);

   template <typename T, std::size_t D>
   segment<T,D> project_onto_axis(const pointnd<T,D>& point, const line<T,D>& axis);

   template <typename T, std::size_t D>
   segment<T,D> project_onto_axis(const triangle<T,D>& triangle, const line<T,D>& axis);

   template <typename T, std::size_t D>
   segment<T,D> project_onto_axis(const box<T,D>& box, const line<T,D>& axis);

   template <typename T, std::size_t D>
   segment<T,D> project_onto_axis(const quadix<T,D>& quadix, const line<T,D>& axis);

   template <typename T, std::size_t D>
   T perimeter(const triangle<T,D>& triangle);

   template <typename T, std::size_t D>
   T perimeter(const quadix<T,D>& quadix);

   template <typename T, std::size_t D>
   pointnd<T,D> generate_random_point(const segment<T,D>& segment);

   template <typename T, std::size_t D>
   pointnd<T,D> generate_random_point(const triangle<T,D>& triangle);

   template <typename T, std::size_t D>
   pointnd<T,D> generate_random_point(const quadix<T,D>& quadix);

   template <typename T, std::size_t D>
   pointnd<T,D> generate_random_point(const box<T,D>& box);

   template <typename T, std::size_t D, typename OutputIterator>
   void generate_random_points(const box<T,D>& box, const std::size_t& point_count, OutputIterator out);

   template <typename T, std::size_t D, typename OutputIterator>
   void generate_random_points(const segment<T,D>& segment, const std::size_t& point_count, OutputIterator out);

   template <typename T, std::size_t D, typename OutputIterator>
   void generate_random_points(const triangle<T,D>& triangle, const std::size_t& point_count, OutputIterator out);

   template <typename T, std::size_t D, typename OutputIterator>
   void generate_random_points(const quadix<T,D>& quadix, const std::size_t& point_count, OutputIterator out);

   template <typename T, std::size_t D>
   T vector_norm(const vectornd<T,D>& v);

   template <typename T, std::size_t D>
   vectornd<T,D> normalize(const vectornd<T,D>& v);

   template <typename T, std::size_t D>
   vectornd<T,D> operator+(const vectornd<T,D>& v1, const vectornd<T,D>& v2);

   template <typename T, std::size_t D>
   vectornd<T,D> operator-(const vectornd<T,D>& v1, const vectornd<T,D>& v2);

   template <typename T, std::size_t D>
   T dot_product(const vectornd<T,D>& v1, const vectornd<T,D>& v2);

   template <typename T, std::size_t D>
   vectornd<T,D> operator*(const vectornd<T,D>& v1, const T& scale);

   template <typename T, std::size_t D>
   vectornd<T,D> operator*(const T& scale, const vectornd<T,D>& v1);

   template <typename T, std::size_t D>
   pointnd<T,D> operator*(const pointnd<T,D>& point, const T& scale);

   template <typename T, std::size_t D>
   pointnd<T,D> operator*(const T& scale, const pointnd<T,D>& point);

   template <typename T, std::size_t D>
   vectornd<T,D> operator/(const vectornd<T,D>& v1, const T& scale);

   template <typename T, std::size_t D>
   pointnd<T,D> operator/(const pointnd<T,D>& point, const T& scale);

   template <typename T, std::size_t D>
   pointnd<T,D> operator+(const pointnd<T,D>& point, const vectornd<T,D>& v);

   template <typename T, std::size_t D>
   pointnd<T,D> operator+(const vectornd<T,D>& v, const pointnd<T,D>& point);

   template <typename T, std::size_t D>
   vectornd<T,D> operator-(const pointnd<T,D>& p1, const pointnd<T,D>& p2);

   template <typename T, std::size_t D>
   pointnd<T,D> operator+(const pointnd<T,D>& p1, const pointnd<T,D>& p2);

   template <typename T>
   T operator*(const vectornd<T,2>& v1, const vectornd<T,2>& v2);

   template <typename T>
   vectornd<T,3> operator*(const vectornd<T,3>& v1, const vectornd<T,3>& v2);

   template <typename T, std::size_t D>
   bool operator < (const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   bool operator > (const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   bool operator == (const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   bool is_equal(const pointnd<T,D>& point1, const pointnd<T,D>& point2, const T& epsilon);

   template <typename T, std::size_t D>
   bool is_equal(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   bool not_equal(const pointnd<T,D>& point1, const pointnd<T,D>& point2, const T& epsilon);

   template <typename T, std::size_t D>
   bool not_equal(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   pointnd<T,D> degenerate_pointnd();

   template <typename T, std::size_t D>
   vectornd<T,D> degenerate_vectornd();

   template <typename T, std::size_t D>
   ray<T,D> degenerate_raynd();

   template <typename T, std::size_t D>
   line<T,D> degenerate_linend();

   template <typename T, std::size_t D>
   segment<T,D> degenerate_segmentnd();

   template <typename T, std::size_t D>
   triangle<T,D> degenerate_trianglend();

   template <typename T, std::size_t D>
   quadix<T,D> degenerate_quadixnd();

   template <typename T, std::size_t D>
   box<T,D> degenerate_box();

   template <typename T, std::size_t D>
   pointnd<T,D> positive_infinite_pointnd();

   template <typename T, std::size_t D>
   pointnd<T,D> negative_infinite_pointnd();

   template <typename T, std::size_t D>
   void swap(pointnd<T,D>& point1, pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   vectornd<T,D> make_vector(const pointnd<T,D>& point);

   template <typename T, std::size_t D>
   ray<T,D> make_ray(const pointnd<T,D>& origin, const vectornd<T,D>& direction);

   template <typename T, std::size_t D>
   segment<T,D> make_segment(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   line<T,D> make_line(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   box<T,D> make_box(const pointnd<T,D>& point1, const pointnd<T,D>& point2);

   template <typename T, std::size_t D>
   triangle<T,D> make_triangle(const pointnd<T,D>& point1, const pointnd<T,D>& point2, const pointnd<T,D>& point3);

   template <typename T, std::size_t D>
   quadix<T,D> make_quadix(const pointnd<T,D>& point1, const pointnd<T,D>& point2, const pointnd<T,D>& point3, const pointnd<T,D>& point4);

} // acme namespace

#endif
