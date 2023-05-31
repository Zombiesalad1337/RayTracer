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

Tuple Tuple::operator-() const{
    Tuple negated = Tuple(-this->x, -this->y, -this->z, -this->w);
    return negated;
}

//TODO: No point of w here as no point in multiplying a point by a scalar
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
    return abs(this->x - tup.x) < EPSILON 
        && abs(this->y - tup.y) < EPSILON 
        && abs(this->z - tup.z) < EPSILON 
        && abs(this->w - tup.w) < EPSILON;
}

bool Tuple::operator!=(const Tuple& tup) const{
    return !operator==(tup);
}

float Tuple::magnitude() const{
    return sqrt(this->x * this->x + 
                this->y * this->y + 
                this->z * this->z);
}

//TODO: Handle for Zero Vector (magnitude 0)
Tuple Tuple::norm() const{
    return *this / this->magnitude();  
}


Tuple point(float x, float y, float z){
    return Tuple(x, y, z , 1.0f);
}

Tuple vec(float x, float y, float z){
    return Tuple(x, y, z, 0.0f);
}

//TODO: w belongs in dot? no sense of w in dot
float dot(const Tuple& a, const Tuple& b){
    return a.x * b.x +
           a.y * b.y +
           a.z * b.z;
}

Tuple cross(const Tuple& a, const Tuple& b){
    return vec(a.y * b.z - a.z * b.y,
               a.z * b.x - a.x * b.z,
               a.x * b.y - a.y * b.x);
}

} //namespace rt


