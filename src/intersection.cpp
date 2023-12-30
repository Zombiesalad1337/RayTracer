#include "intersection.h"
#include "vec.h"
#include <algorithm>
#include <cmath>

namespace rt{

Intersection::Intersection(float t, const Shape* object) : t(t), object(object) {}

std::optional<std::vector<Intersection>> Intersection::intersect(const Shape& shape, const Ray& ray, std::vector<Intersection>& intersections) {
    std::vector<Intersection> intersects;
    switch (shape.type) {
        case SPHERE:
            Vec sphereToRay = ray.origin() - Point(0, 0, 0);
            
            float a = Vec::dot(ray.direction(), ray.direction());
            float b = 2 * Vec::dot(ray.direction(), sphereToRay);
            float c = Vec::dot(sphereToRay, sphereToRay) - 1;

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
    return intersects;
}

std::optional<Intersection> Intersection::hit(std::vector<Intersection>& intersections){
    std::sort(intersections.begin(), intersections.end(), [](const Intersection& a, const Intersection& b){
        return a.t < b.t;
    });

    auto it = std::lower_bound(intersections.begin(), intersections.end(), 0.0f, [](const Intersection& a, float val){
                                                                                    return std::fabs(a.t - val) < EPSILON;
                                                                                    });

    if (it != intersections.end()){
        return *it;
    }
    return std::nullopt;
}

}
