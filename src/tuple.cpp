#include "tuple.h"
#include <cmath>
#include <iostream>

namespace rt {


Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

bool Tuple::isVec() const{
    return this->w == 0;
}

bool Tuple::isPoint() const{
    return this->w == 1;
}
//TODO: move to utils.h as inline function
bool Tuple::equals(const Tuple& tup) const{
    return fabs(this->x - tup.x) < EPSILON 
        && fabs(this->y - tup.y) < EPSILON 
        && fabs(this->z - tup.z) < EPSILON 
        && fabs(this->w - tup.w) < EPSILON;
}

Tuple Tuple::operator-() const{
    return Tuple(-this->x, -this->y, -this->z, -this->w);
}

Tuple Tuple::operator*(float m) const{
    return Tuple(this->x * m, this->y * m, this->z * m, this->w * m);
}

Tuple Tuple::operator/(float d) const{
    return Tuple(this->x / d, this->y / d, this->z / d, this->w / d);
}

Tuple Tuple::operator+(const Tuple& tup) const{
    return Tuple(this->x + tup.x, 
                      this->y + tup.y, 
                      this->z + tup.z, 
                      this->w + tup.w);
}

Tuple Tuple::operator-(const Tuple& tup) const{
    return Tuple(this->x - tup.x, 
                      this->y - tup.y, 
                      this->z - tup.z, 
                      this->w - tup.w);
}
bool Tuple::operator==(const Tuple& tup) const{
    return fabs(this->x - tup.x) < EPSILON 
        && fabs(this->y - tup.y) < EPSILON 
        && fabs(this->z - tup.z) < EPSILON 
        && fabs(this->w - tup.w) < EPSILON;
}

bool Tuple::operator!=(const Tuple& tup) const{
    return !operator==(tup);
}

void Tuple::print() const{
    std::cout << "X: " << x << " Y:" << y << " Z:" << z << " W: " << w << std::endl;
}

} //namespace rt


