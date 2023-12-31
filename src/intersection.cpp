#include "intersection.h"
#include "vec.h"
#include <algorithm>
#include <cmath>
#include <iostream>

namespace rt{

Intersection::Intersection(float t, const Shape* object) : t(t), object(object) {}

std::optional<std::vector<Intersection>> Intersection::intersect(const Shape& shape, const Ray& ray, std::vector<Intersection>& intersections) {
    rt::Ray rayObjectSpace = ray.transform(shape.getTransform().inverse());
    std::vector<Intersection> intersects;
    switch (shape.type()) {
        case SPHERE:
            // std::cout << "SPHERE\n";
            Vec sphereToRayObjectSpace = rayObjectSpace.origin() - Point(0, 0, 0);
            
            float a = Vec::dot(rayObjectSpace.direction(), rayObjectSpace.direction());
            float b = 2 * Vec::dot(rayObjectSpace.direction(), sphereToRayObjectSpace);
            float c = Vec::dot(sphereToRayObjectSpace, sphereToRayObjectSpace) - 1;

            float discriminant = b * b - 4 * a * c;

            if (discriminant >= 0){
                float t1 = (-b + sqrtf(discriminant)) / (2 * a);
                float t2 = (-b - sqrtf(discriminant)) / (2 * a);

                intersects.emplace_back(std::min(t1, t2), &shape);
                intersects.emplace_back(std::max(t1, t2), &shape);

                //TODO: Create new object or copy (push_back), which is faster?
                intersections.emplace_back(std::min(t1, t2), &shape);
                intersections.emplace_back(std::max(t1, t2), &shape);
                
                return intersects;
            }
    }
    return std::nullopt;
}

std::optional<Intersection> Intersection::hit(std::vector<Intersection>& intersections){
    std::sort(intersections.begin(), intersections.end(), [](const Intersection& a, const Intersection& b){
        return a.t < b.t;
    });

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
