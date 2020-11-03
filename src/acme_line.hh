#ifndef INCLUDE_ACME_LINE
#define INCLUDE_ACME_LINE

#include "acme_math.hh"
#include "acme_point.hh"

namespace acme
{

  template <typename T, std::size_t D>
  class linend;

  template <typename T>
  class line2d;

  template <typename T>
  class line3d;

  /*\
   |   _ _            ____     _ 
   |  | (_)_ __   ___|___ \ __| |
   |  | | | '_ \ / _ \ __) / _` |
   |  | | | | | |  __// __/ (_| |
   |  |_|_|_| |_|\___|_____\__,_|
   |                             
  \*/

  template <typename T = Float>
  class line2d : public linend<T, 2>
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
  class line3d : public linend<T, 3>
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
  class linend
  {
  private:
    const static std::size_t PointCount = 2;
    pointnd<T, D> data[PointCount];

  public:
    linend() {}
    ~linend() {}

    inline pointnd<T, D> &operator[](const std::size_t &index) { return data[index]; }
    inline const pointnd<T, D> &operator[](const std::size_t &index) const { return data[index]; }
    inline std::size_t size() { return PointCount; }
  };

} // namespace acme

#endif