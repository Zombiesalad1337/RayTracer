#include "intersection.h"
#include "vec.h"
#include <algorithm>
#include <cmath>
#include <iostream>

namespace rt{

Intersection::Intersection(float t, const Shape* object) : t(t), object(object) {}


std::optional<Intersection> Intersection::hit(std::vector<Intersection>& intersections, bool alreadySorted){
    if (!alreadySorted){
        std::sort(intersections.begin(), intersections.end(), [](const Intersection& a, const Intersection& b){
            return a.t < b.t;
        });
    }

    // std::cout << "After sort: ";
    // for (auto i : intersections){
    //     std::cout << "i->t:  " << i.t;
    // }
    // std::cout << std::endl;cout
    
    //-EPSILON instead of 0.0f was identifying -EPSILON as a hit. Switched to 0.0f instead.
    //TODO: might break for values very very close to zero.
    auto it = std::lower_bound(intersections.begin(), intersections.end(), 0.0f, [](const Intersection& a, float val){
                            //a.t < -EPSILON
                            //true for negative values
                            return a.t < val;
                            });

    if (it != intersections.end()){
        // std::cout << "hit: " << it->t << std::endl;
        return *it;
    }
    return std::nullopt;
}

bool Intersection::operator==(const Intersection& i) const{
    return std::fabs(t - i.t) < EPSILON && object == i.object;
}

bool Intersection::operator!=(const Intersection& i) const{
    return !operator==(i);
}

}
