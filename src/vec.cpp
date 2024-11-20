#include "vec.h"
#include <cmath>

namespace rt{

Vec::Vec(float x, float y, float z) : Tuple(x, y, z, 0.0f) {};
Vec::Vec(const Tuple& tup) : Tuple(tup) {};
// std::move is needed because a named rvalue reference (like 'tup') is treated as an lvalue, 
//requiring a cast to rvalue for the move constructor.
//A named rvalue reference behaves as an lvalue because it now has an identity (its name) 
//and can be referred to multiple times.

//Example:
// Tuple tup;
// Vec(std::move(tup))
// if inside Vec constructor:
// 1. Tuple(tup) is called -> Ownership of tup transfers from global scope to Vec, but is not transferred furthur 
//      to the Tuple constructor. A new copy of tup will be created inside Tuple constructor, and the Vec will retain ownership
//      of tup.
// 2. Tuple(std::move(tup)) is called -> Ownership of tup is transferred from global scope to Vec to Tuple.
Vec::Vec(Tuple&& tup) : Tuple(std::move(tup)) {};

float Vec::magnitude() const{
    return sqrt(x * x + y * y + z * z);
}

Vec Vec::norm() const{
    float mag = magnitude();
    if (std::fabs(mag - 0.0f) < EPSILON){
        return Vec(0, 0, 0);
    }
    return *this / mag;
}

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

//TODO:is the reflected vec normalized?
//Is it normalized only when both in and normal vectors are normalized
Vec Vec::reflect(const Vec& normal) const{
    return *this - normal * 2 * dot(*this, normal);
}


}//namespace rt
