#pragma once
#include "tuple.h"


namespace rt{

class Color : public Tuple{
public:
    using Tuple::x;
    using Tuple::y;
    using Tuple::z;
    
    float& r = x;
    float& g = y;
    float& b = z;

    Color(float r, float g, float b);
    Color(const Tuple&& tup);

    //TODO:NEED TO CAST COLOR TO BASE CLASS FOR * FOR WORK IN CASE OF SCALAR
    Color operator*(const Color& c) const;
};

} //namespace rt
#pragma once
#include "tuple.h"


namespace rt{

class Point : public Tuple{
public:
    Point(float x, float y, float z);
    Point(const Tuple&& tup);
};

} //namespace rt
#pragma once

#define EPSILON 0.00001F
namespace rt{

class Tuple{

public:
    float x;
    float y;
    float z;
    float w;

    Tuple(float x, float y, float z, float w);

    bool isVec();

    bool isPoint();
    
    bool equals(const Tuple& tup);

    Tuple operator-() const;

    Tuple operator+(const Tuple& tup) const;

    Tuple operator-(const Tuple& tup) const;

    Tuple operator*(float m) const;

    Tuple operator/(float d) const;

    bool operator==(const Tuple& tup) const;

    bool operator!=(const Tuple& tup) const;


};


}// namespace rt
#pragma once
#include "tuple.h"


namespace rt{

class Vec : public Tuple{
public:
    Vec(float x, float y, float z);
    Vec(const Tuple&& tup);
    float magnitude() const;
    Vec norm() const;
};

float dot(const Vec& a, const Vec& b);
Vec cross(const Vec& a, const Vec& b);

} //namespace rt
#include "color.h"

namespace rt{

Color::Color(float r, float g, float b) : Tuple(r, g, b, 0.0f) {};
Color::Color(const Tuple&& tup) : Tuple(tup) {};

//only specify override in class definition(header file)
Color Color::operator*(const Color& c) const{
    return Color(this->r * c.r, this->g * c.g, this->b * c.b);
}
}//namespace rt
#include <iostream>
#include "tuple.h"
#include "point.h"
#include "vec.h"


int main(){
    std::cout << "Initial setup" << std::endl;
    rt::Vec v1(1,1,1);
    rt::Vec v2(2,2,2);
    rt::Point p1(1,1,1);
    rt::Vec v3 = v1 + v2;
    rt::Point p2 = v2 + p1;
    return 0;
}


#include "point.h"

namespace rt{

Point::Point(float x, float y, float z) : Tuple(x, y, z, 1.0f) {};
Point::Point(const Tuple&& tup) : Tuple(tup) {};
}//namespace rt
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





} //namespace rt


#include "vec.h"
#include <cmath>

namespace rt{

Vec::Vec(float x, float y, float z) : Tuple(x, y, z, 0.0f) {};
Vec::Vec(const Tuple&& tup) : Tuple(tup) {};

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
float dot(const Vec& a, const Vec& b){
    return a.x * b.x +
           a.y * b.y +
           a.z * b.z;
}

Vec cross(const Vec& a, const Vec& b){
    return Vec(a.y * b.z - a.z * b.y,
               a.z * b.x - a.x * b.z,
               a.x * b.y - a.y * b.x);
}



}//namespace rt
