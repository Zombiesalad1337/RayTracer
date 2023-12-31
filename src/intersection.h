#pragma once
#include "shape.h"
#include "ray.h"
#include <vector>
#include <optional>

namespace rt{

class Intersection{
public:
    float t;
    const Shape* object;
    
    //TODO: Const pointer required here?
    Intersection(float t, const Shape* object);

    static std::optional<Intersection> hit(std::vector<Intersection>& intersections);

    //Accumulate intersections for all intersects in the Intersections* vector
    static std::optional<std::vector<Intersection>> intersect(const Shape& shape, const Ray& ray, std::vector<Intersection>& intersections);

    bool operator==(const Intersection& i) const;
    bool operator!=(const Intersection& i) const;

};

}
