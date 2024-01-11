#include "plane.h"
#include <cmath>
#include <iostream>

namespace rt{

Plane::Plane() : Shape() {}

Vec Plane::normalAt(const Point& worldPt) const {
    return Vec(0, 1, 0);
}


std::optional<std::vector<Intersection>> Plane::localIntersect(const Ray& rayLocalSpace, std::vector<Intersection>& intersections) const {
    std::vector<Intersection> intersects;

    //almost flat
    if (fabs(rayLocalSpace.direction().y) < EPSILON){
        return std::nullopt;
    }
    float t = -rayLocalSpace.origin().y / rayLocalSpace.direction().y;
    intersects.emplace_back(t, this);
    intersections.emplace_back(t, this);
    return intersects;
}

}
