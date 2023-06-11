#include "point.h"

namespace rt{

Point::Point(float x, float y, float z) : Tuple(x, y, z, 1.0f) {};
//Point::Point(const Tuple& tup) : Tuple(tup) {};
Point::Point(Tuple&& tup) : Tuple(tup) {};
}//namespace rt
