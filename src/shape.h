#pragma once
#include "shape_types.h"
#include "matrix.h"

namespace rt{

class Shape{
public:
    static int id;
    ShapeType type;
    Matrix transform = Matrix::identity();

    Shape(ShapeType type);
};

}
