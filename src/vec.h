#pragma once
#include "tuple.h"


namespace rt{

class Vec : public Tuple{
public:
    explicit Vec(float x, float y, float z);
    //need to explicitly state that vec constructor can accept a tuple
    Vec(const Tuple& tup);
    Vec(Tuple&& tup);
    float magnitude() const;
    Vec norm() const;

    Vec reflect(const Vec& normal) const;

    static float dot(const Vec& a, const Vec& b);
    static Vec cross(const Vec& a, const Vec& b);
};


} //namespace rt
