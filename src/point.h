#pragma once
#include "tuple.h"


namespace rt{

class Point : public Tuple{
public:
    //TODO: Do I need a const ref tuple constructor here?
    explicit Point(float x, float y, float z);
    Point(const Tuple& tup);
    Point(Tuple&& tup);
    Point operator*(float) = delete;
    Point operator/(float) = delete;
};

} //namespace rt
