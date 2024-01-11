#pragma once
#include "shape.h"
#include "vec.h"
#include "point.h"

namespace rt{

class Sphere : public Shape{
public:
    Sphere();
    Vec normalAt(const Point& worldPt) const override;
    virtual ~Sphere() = default;
    virtual std::optional<std::vector<Intersection>> localIntersect(const Ray& rayLocalSpace, std::vector<Intersection>& intersections) const override;
};

}
