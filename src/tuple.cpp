#include "tuple.h"
#include <cmath>

namespace rt {


Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

bool Tuple::isVec(){
    return this->w == 0;
}

bool Tuple::isPoint(){
    return this->w == 1;
}
//abs(x1 - x2) < EPSILON not a function due to additional overhead.
//TODO: make that inline
bool Tuple::equals(const Tuple& tup){
    return abs(this->x - tup.x) < EPSILON 
        && abs(this->y - tup.y) < EPSILON 
        && abs(this->z - tup.z) < EPSILON 
        && abs(this->w - tup.w) < EPSILON;
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

Tuple point(float x, float y, float z){
    return Tuple(x, y, z , 1.0f);
}

Tuple vec(float x, float y, float z){
    return Tuple(x, y, z, 0.0f);
}


} //namespace rt


