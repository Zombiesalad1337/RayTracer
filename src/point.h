#pragma once
#include "tuple.h"


namespace rt{

class Point : public Tuple{
public:
    Point(float x, float y, float z);
    Point(Tuple&& tup);
};

} //namespace rt
