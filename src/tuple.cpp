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
//abs(x1 - x2) < EPSILON not a function due to additional overhead.
//TODO: make that inline
//I guess inline is not possible because of inheritance, both point and vec can call equals
bool Tuple::equals(const Tuple& tup) const{
    return fabs(this->x - tup.x) < EPSILON 
        && fabs(this->y - tup.y) < EPSILON 
        && fabs(this->z - tup.z) < EPSILON 
        && fabs(this->w - tup.w) < EPSILON;
}

Tuple Tuple::operator-() const{
    Tuple negated = Tuple(-this->x, -this->y, -this->z, -this->w);
    return negated;
}

//TODO: No point of w here as no point in multiplying a point by a scalar
//But tuple constructor needs 4 params
//For vector shouldn't be a problem since 0*m = 0
//For point, maybe a problem, but we aren't using runtime polymorphism, so we know
//the type when multiplying, and we know that there's no sense in multiplying a point
//by a scalar.
Tuple Tuple::operator*(float m) const{
    Tuple multiplied = Tuple(this->x * m, this->y * m, this->z * m, this->w * m);
    return multiplied;
}

//TODO: No point of w here as no point in dividing a point by a scalar
Tuple Tuple::operator/(float d) const{
    Tuple divided = Tuple(this->x / d, this->y / d, this->z / d, this->w / d);
    return divided;
}

Tuple Tuple::operator+(const Tuple& tup) const{
    Tuple sum = Tuple(this->x + tup.x, 
                      this->y + tup.y, 
                      this->z + tup.z, 
                      this->w + tup.w);
    return sum;
}

Tuple Tuple::operator-(const Tuple& tup) const{
    Tuple sum = Tuple(this->x - tup.x, 
                      this->y - tup.y, 
                      this->z - tup.z, 
                      this->w - tup.w);
    return sum;
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


