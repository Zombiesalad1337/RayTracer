#pragma once
#include "color.h"
#include "point.h"

namespace rt{

class PointLight{
public:
    PointLight(const Point& position, const Color& intensity);
    Point position() const;
    Color intensity() const;

private:
    Point mPosition;
    Color mIntensity;
};

}

