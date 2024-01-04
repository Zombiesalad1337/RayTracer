#include "sphere.h"
#include <iostream>

namespace rt{

Sphere::Sphere() : Shape(SPHERE) {}

Vec Sphere::normalAt(const Point& worldPt) const {
    std::cout << "normalAt for sphere" << std::endl;
    Matrix inv = mTransform.inverse();
    Point objectPt = inv * worldPt;
    Vec objectNormal(objectPt.x, objectPt.y, objectPt.z);
    Vec worldNormal = inv.transpose() * objectNormal;
    worldNormal.w = 0.0f;
    return worldNormal.norm();
}

}
