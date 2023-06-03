#pragma once
#include "tuple.h"


namespace rt{

class Vec : public Tuple{
public:
    Vec(float x, float y, float z);
    Vec(Tuple&& tup);
    float magnitude() const;
    Vec norm() const;
};

float dot(const Vec& a, const Vec& b);
Vec cross(const Vec& a, const Vec& b);

} //namespace rt
