#pragma once
#include "shape.h"
#include "vec.h"
#include "point.h"

namespace rt{

class Plane : public Shape{
public:
    Plane();
    Vec normalAt(const Point& worldPt) const override;
    virtual ~Plane() = default;
    virtual std::optional<std::vector<Intersection>> localIntersect(const Ray& rayLocalSpace, std::vector<Intersection>& intersections) const override;
};

}
