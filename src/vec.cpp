#include "vec.h"
#include <cmath>

namespace rt{

Vec::Vec(float x, float y, float z) : Tuple(x, y, z, 0.0f) {};
//Vec::Vec(const Tuple& tup) : Tuple(tup) {};
Vec::Vec(Tuple&& tup) : Tuple(tup) {};

float Vec::magnitude() const{
    return sqrt(this->x * this->x + 
                this->y * this->y + 
                this->z * this->z);
}

//TODO: Handle for Zero Vector (magnitude 0)
Vec Vec::norm() const{
    return *this / this->magnitude();  
}

//TODO: w belongs in dot? no sense of w in dot
//
//TODO: can be a static func inside vec class
float Vec::dot(const Vec& a, const Vec& b){
    return a.x * b.x +
           a.y * b.y +
           a.z * b.z;
}

Vec Vec::cross(const Vec& a, const Vec& b){
    return Vec(a.y * b.z - a.z * b.y,
               a.z * b.x - a.x * b.z,
               a.x * b.y - a.y * b.x);
}



}//namespace rt
