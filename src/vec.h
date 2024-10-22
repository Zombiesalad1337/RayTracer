#pragma once
#include "tuple.h"


namespace rt{

class Vec : public Tuple{
public:
    Vec(float x, float y, float z);
    Vec(const Tuple& tup);
    Vec(Tuple&& tup);
    float magnitude() const;
    Vec norm() const;

    Vec reflect(const Vec& normal) const;

    static float dot(const Vec& a, const Vec& b);
    static Vec cross(const Vec& a, const Vec& b);
};


} //namespace rt
