#pragma once
#include "vec.h"
#include "point.h"


namespace rt{
class Color : public Tuple{
public:
    //https://stackoverflow.com/questions/5679073/overloading-operators-in-derived-class
    //for Color * scalar: operation not defined error
    using Tuple::operator*;

    //for 0,0,0 color
    Color();
    Color(float r, float g, float b);
    //need to explicitly state that color constructor can accept a tuple
    Color(Tuple&& tup);
    Color(const Color& c) = default;
    Color(Color&& c) = default;
    Color& operator=(const Color& c);
    Color& operator=(Color&& c) = default;

    Color operator*(const Color& c) const;



    float r() const;
    float g() const;
    float b() const;





};

} //namespace rt
