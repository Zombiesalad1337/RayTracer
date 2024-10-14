#include "point.h"
#include <utility>

namespace rt{

Point::Point(float x, float y, float z) : Tuple(x, y, z, 1.0f) {};
Point::Point(const Tuple& tup) : Tuple(tup) {};
Point::Point(Tuple&& tup) : Tuple(std::move(tup)) {};
}//namespace rt
