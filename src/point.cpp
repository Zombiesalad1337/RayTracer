#include "point.h"

namespace rt{

Point::Point(float x, float y, float z) : Tuple(x, y, z, 1.0f) {};
Point::Point(Tuple&& tup) : Tuple(tup) {};
}//namespace rt
