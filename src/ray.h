#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "point.h"
#include "vec.h"
#include "matrix.h"

namespace rt{

class Ray{
public:
    Ray(const Point& origin, const Vec& direction);
    Ray(float ox, float oy, float oz, float dx, float dy, float dz);
    Ray(const Point& origin, float dx, float dy, float dz);
    Ray(float ox, float oy, float oz, const Vec& direction);

    Point origin() const;
    Vec direction() const;

    Point position(float t) const;

    Ray transform(const Matrix& mat) const;

private:
    //cant have variable and member function with same name in c++. Could've kept variable names origin, direction, but then needed to change method names to getOrigin, get direction. Added m instead here.
    Point mOrigin;
    Vec mDirection;
};

}
