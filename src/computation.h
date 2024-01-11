#pragma once
#include "ray.h"
#include "shape.h"

namespace rt{

class Computation{
public:
    
    Computation(const Intersection& intersection, const Ray& ray);

    float t;
    const Shape* shape;
    Point point;
    Vec eyev;
    Vec normalv;
    bool inside;
    Point overPoint;

};

}

