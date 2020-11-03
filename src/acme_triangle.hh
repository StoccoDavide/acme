#ifndef INCLUDE_ACME_TRIANGLE
#define INCLUDE_ACME_TRIANGLE

#include "acme_math.hh"
#include "acme_point.hh"

namespace acme
{

  template <typename T, std::size_t D>
  class trianglend;

  template <typename T>
  class triangle2d;

  template <typename T>
  class triangle3d;

  /*\
   |   _ _            ____     _ 
   |  | (_)_ __   ___|___ \ __| |
   |  | | | '_ \ / _ \ __) / _` |
   |  | | | | | |  __// __/ (_| |
   |  |_|_|_| |_|\___|_____\__,_|
   |                             
  \*/

  template <typename T = Float>
  class triangle2d : public trianglend<T, 2>
  {
  };

  /*\
   |   _ _            _____     _ 
   |  | (_)_ __   ___|___ /  __| |
   |  | | | '_ \ / _ \ |_ \ / _` |
   |  | | | | | |  __/___) | (_| |
   |  |_|_|_| |_|\___|____/ \__,_|
   |                              
  \*/

  template <typename T = Float>
  class triangle3d : public trianglend<T, 3>
  {
  };

  /*\
   |   _ _                      _ 
   |  | (_)_ __   ___ _ __   __| |
   |  | | | '_ \ / _ \ '_ \ / _` |
   |  | | | | | |  __/ | | | (_| |
   |  |_|_|_| |_|\___|_| |_|\__,_|
   |                              
  \*/

  template <typename T, std::size_t D>
  class triangle
  {
  private:
    const static std::size_t PointCount = 3;
    pointnd<T, N> data[PointCount];
  
  public:
    triangle() {}
    ~triangle() {}

    inline reference operator[](const std::size_t &index) { return data[index]; }
    inline const_reference operator[](const std::size_t &index) const { return data[index]; }
    inline std::size_t size() const { return PointCount; }
  };

} // namespace acme

#endif