#pragma once
#include "tuple.h"


namespace rt{

class Point : public Tuple{
public:
    explicit Point(float x, float y, float z);
    Point(const Tuple& tup);
    Point(Tuple&& tup);
    //no semantic sense in scaling a point
    Point operator*(float) = delete;
    Point operator/(float) = delete;
};

} //namespace rt
