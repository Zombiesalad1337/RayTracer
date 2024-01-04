#include "shape.h"
#include <iostream>

namespace rt{

int Shape::mId = 0;

Shape::Shape(ShapeType type) : mType(type) { mId++; }

int Shape::id() const { return mId; }
ShapeType Shape::type() const { return mType; }
//transform() has the semantic sense of doing some transformation, but essentially we are returning the member variable transform. Naming as getTransform instead.
Matrix Shape::getTransform() const { return mTransform; }
void Shape::setTransform(const Matrix& mat) { mTransform = mat; }

}
