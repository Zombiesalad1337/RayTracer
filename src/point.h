#pragma once
#include "tuple.h"


namespace rt{

class Point : public Tuple{
public:
    explicit Point(float x, float y, float z);
    //need to explicitly state that point constructor can accept a tuple
    Point(const Tuple& tup);
    Point(Tuple&& tup);
    //no semantic sense in scaling a point
    Point operator*(float) = delete;
    Point operator/(float) = delete;
};

} //namespace rt
