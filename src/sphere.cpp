#include "sphere.h"
#include <cmath>
#include <iostream>

namespace rt{

Sphere::Sphere() : Shape() {}

Vec Sphere::normalAt(const Point& worldPt) const {
    // std::cout << "normalAt for sphere" << std::endl;
    Matrix inv = mTransform.inverse();
    Point objectPt = inv * worldPt;
    Vec objectNormal(objectPt.x, objectPt.y, objectPt.z);
    Vec worldNormal = inv.transpose() * objectNormal;
    worldNormal.w = 0.0f;
    return worldNormal.norm();
}


std::optional<std::vector<Intersection>> Sphere::localIntersect(const Ray& rayLocalSpace, std::vector<Intersection>& intersections) const {
    std::vector<Intersection> intersects;
    Vec sphereToRayObjectSpace = rayLocalSpace.origin() - Point(0, 0, 0);
    
    float a = Vec::dot(rayLocalSpace.direction(), rayLocalSpace.direction());
    float b = 2 * Vec::dot(rayLocalSpace.direction(), sphereToRayObjectSpace);
    float c = Vec::dot(sphereToRayObjectSpace, sphereToRayObjectSpace) - 1;

    float discriminant = b * b - 4 * a * c;

    if (discriminant >= 0){
        float t1 = (-b + sqrtf(discriminant)) / (2 * a);
        float t2 = (-b - sqrtf(discriminant)) / (2 * a);

        intersects.emplace_back(std::min(t1, t2), this);
        intersects.emplace_back(std::max(t1, t2), this);

        //TODO: Create new object or copy (push_back), which is faster?
        intersections.emplace_back(std::min(t1, t2), this);
        intersections.emplace_back(std::max(t1, t2), this);
        
        return intersects;
    }
    return std::nullopt;
}

}
