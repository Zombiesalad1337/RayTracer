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

    void print() const;


};


}// namespace rt
