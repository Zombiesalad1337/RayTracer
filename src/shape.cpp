#include "shape.h"
#include <iostream>

namespace rt{

int Shape::mId = 0;

Shape::Shape() { mId++; }

int Shape::id() const { return mId; }
//transform() has the semantic sense of doing some transformation, but essentially we are returning the member variable transform. Naming as getTransform instead.
Matrix Shape::getTransform() const { return mTransform; }
void Shape::setTransform(const Matrix& mat) { mTransform = mat; }

Material Shape::material() const { return mMaterial; }
void Shape::setMaterial(const Material& material) { mMaterial = material; }

std::optional<std::vector<Intersection>> Shape::intersect(const Ray& ray, std::vector<Intersection>& intersections) const{
    Ray rayLocalSpace = ray.transform(getTransform().inverse());
    return localIntersect(rayLocalSpace, intersections);
}

}
