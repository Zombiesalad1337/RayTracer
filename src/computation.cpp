#include "computation.h"

namespace rt{


//TODO: rename object in intersection to shape
Computation::Computation(const Intersection& intersection, const Ray& ray) : t(intersection.t), shape(intersection.object), point(ray.position(t)), eyev(-ray.direction()), normalv(shape->normalAt(point)) {
   if (Vec::dot(normalv, eyev) < 0.0f){
        inside = true;
        normalv = -normalv;
    } 
    else{
        inside = false;
    }
}

}
