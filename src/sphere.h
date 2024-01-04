#pragma once
#include "shape.h"
#include "vec.h"
#include "point.h"

namespace rt{

class Sphere : public Shape{
public:
    Sphere();
    Vec normalAt(const Point& worldPt) const override;
};

}
