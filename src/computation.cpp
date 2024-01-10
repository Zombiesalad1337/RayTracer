#include "computation.h"

namespace rt{


//TODO: rename object in intersection to shape
//TODO: create default constructor for vec and point, wasted computation for overPoint(t)
Computation::Computation(const Intersection& intersection, const Ray& ray) : t(intersection.t), shape(intersection.object), point(ray.position(t)), eyev(-ray.direction()), normalv(shape->normalAt(point)), overPoint(ray.position(t)) {
   if (Vec::dot(normalv, eyev) < 0.0f){
        inside = true;
        normalv = -normalv;
    } 
    else{
        inside = false;
    }
    overPoint = point + Point(normalv * 0.01);
}

}
