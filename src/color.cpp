#include "color.h"
#include <iostream>
#include <cmath>

namespace rt{

Color::Color() : Tuple(0.0f, 0.0f, 0.0f, 0.0f) {};
Color::Color(float r, float g, float b) : Tuple(r, g, b, 0.0f) {};
Color::Color(Tuple&& tup) : Tuple(std::move(tup)) {};

// Using c.x instead of c.r() for optimization
// user won't care about implementation details, just keep interface clean

//only specify override in class definition(header file)
Color Color::operator*(const Color& c) const{
    return Color(x * c.x, y * c.y, z * c.z);
}

float Color::r() const{ return x; }
float Color::g() const{ return y; }
float Color::b() const{ return z; }


}//namespace rt
