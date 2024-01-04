#include "color.h"
#include <iostream>
#include <cmath>

namespace rt{

Color::Color() : Tuple(0.0f, 0.0f, 0.0f, 0.0f) {};
Color::Color(float r, float g, float b) : Tuple(r, g, b, 0.0f) {};
Color::Color(Tuple&& tup) : Tuple(tup) {};


// Using c.x instead of c.r() for optimization
// user won't care about implementation details, just keep interface clean
Color& Color::operator=(const Color& c){
    this->x = c.x;
    this->y = c.y;
    this->z = c.z;
    return *this;
}

//only specify override in class definition(header file)
Color Color::operator*(const Color& c) const{
    return Color(this->x * c.x, this->y * c.y, this->z * c.z);
}
float Color::r() const{ return this->x; }
float Color::g() const{ return this->y; }
float Color::b() const{ return this->z; }


}//namespace rt
