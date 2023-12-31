#include "ray.h"

namespace rt{

Ray::Ray(const Point& origin, const Vec& direction) : mOrigin(origin), mDirection(direction) {}

Ray::Ray(float ox, float oy, float oz, float dx, float dy, float dz) : mOrigin(Point(ox, oy, oz)), mDirection(Vec(dx, dy, dz)) {}

Ray::Ray(const Point& origin, float dx, float dy, float dz) : mOrigin(origin), mDirection(Vec(dx, dy, dz)) {}

Ray::Ray(float ox, float oy, float oz, const Vec& direction) : mOrigin(Point(ox, oy, oz)), mDirection(direction) {}

Point Ray::origin() const { return mOrigin; }
Vec Ray::direction() const { return mDirection; }

Point Ray::position(float t) const{
    return Point(mOrigin + mDirection * t);
}

Ray Ray::transform(const Matrix& mat) const{
    return Ray(mat * origin(), mat * direction());    
}

} //namespace rt
