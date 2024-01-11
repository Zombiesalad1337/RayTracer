#pragma once
#include <vector>
#include <optional>

namespace rt{
//
//FORWARD DECLARATION
class Shape;

class Intersection{
public:
    float t;
    const Shape* object;
    
    //TODO: Const pointer required here?
    Intersection(float t, const Shape* object);

    static std::optional<Intersection> hit(std::vector<Intersection>& intersections, bool alreadySorted = false);


    bool operator==(const Intersection& i) const;
    bool operator!=(const Intersection& i) const;

};

}
