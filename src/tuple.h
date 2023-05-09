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
};

Tuple point(float x, float y, float z);
Tuple vec(float x, float y, float z);

}// namespace rt
