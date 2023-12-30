#pragma once
#include "tuple.h"


namespace rt{

class Vec : public Tuple{
public:
    Vec(float x, float y, float z);
//TODO: check performance difference between reference and move constructors
    //Vec(const Tuple& tup);
    Vec(Tuple&& tup);
    float magnitude() const;
    Vec norm() const;

    static float dot(const Vec& a, const Vec& b);
    static Vec cross(const Vec& a, const Vec& b);
};


} //namespace rt
