#pragma once
#include "shape_types.h"
#include "matrix.h"

namespace rt{

class Shape{
public:
    static int id;
    //type tagging. Violates the open/closed principle, but who gives a fuck.
    //doesn't seem too dangerous for my use case.
    ShapeType type;
    Matrix transform = Matrix::identity();

    Shape(ShapeType type);
};

}
