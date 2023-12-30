#include "shape.h"

namespace rt{

int Shape::id = 0;

Shape::Shape(ShapeType type) : type(type) { id++; }

}
