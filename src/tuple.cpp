#include "tuple.h"
#include <cmath>

namespace rt {


Tuple::Tuple(float x, float y, float z, float w){
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

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

Tuple point(float x, float y, float z){
    return Tuple(x, y, z , 1.0f);
}

Tuple vec(float x, float y, float z){
    return Tuple(x, y, z, 0.0f);
}

} //namespace rt


