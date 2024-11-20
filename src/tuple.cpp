#include "tuple.h"
#include <cmath>
#include <iostream>

namespace rt {


Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

bool Tuple::isVec() const{
    return w == 0;
}

bool Tuple::isPoint() const{
    return w == 1;
}
//TODO: move to utils.h as inline function
bool Tuple::equals(const Tuple& tup) const{
    return fabs(x - tup.x) < EPSILON 
        && fabs(y - tup.y) < EPSILON 
        && fabs(z - tup.z) < EPSILON 
        && fabs(w - tup.w) < EPSILON;
}

Tuple Tuple::operator-() const{
    return Tuple(-x, -y, -z, -w);
}

Tuple Tuple::operator*(float m) const{
    return Tuple(x * m, y * m, z * m, w * m);
}

Tuple Tuple::operator/(float d) const{
    return Tuple(x / d, y / d, z / d, w / d);
}

Tuple Tuple::operator+(const Tuple& tup) const{
    return Tuple(x + tup.x, 
                    y + tup.y, 
                    z + tup.z, 
                    w + tup.w);
}

Tuple Tuple::operator-(const Tuple& tup) const{
    return Tuple(x - tup.x, 
                    y - tup.y, 
                    z - tup.z, 
                    w - tup.w);
}

bool Tuple::operator==(const Tuple& tup) const{
    return fabs(x - tup.x) < EPSILON 
        && fabs(y - tup.y) < EPSILON 
        && fabs(z - tup.z) < EPSILON 
        && fabs(w - tup.w) < EPSILON;
}

bool Tuple::operator!=(const Tuple& tup) const{
    //this is implicit, equivalent to !this->operator==(tup)
    return !operator==(tup);
}

void Tuple::print() const{
    std::cout << "X: " << x << " Y:" << y << " Z:" << z << " W: " << w << std::endl;
}

} //namespace rt


