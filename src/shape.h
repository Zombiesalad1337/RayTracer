#pragma once
#include "matrix.h"
#include "vec.h"
#include "point.h"
#include "material.h"
#include "ray.h"
#include "intersection.h"
#include <vector>
#include <optional>

namespace rt{


class Shape{
public:

    Shape();
    virtual ~Shape() = default;

    int id() const;
    //transform() has the semantic sense of doing some transformation, but essentially we are returning the member variable transform. Naming as getTransform instead.
    Matrix getTransform() const;
    void setTransform(const Matrix& mat);
    Material material() const;
    void setMaterial(const Material& material);
    
    virtual Vec normalAt(const Point& worldPt) const = 0;

    std::optional<std::vector<Intersection>> intersect(const Ray& ray, std::vector<Intersection>& intersections) const;

    virtual std::optional<std::vector<Intersection>> localIntersect(const Ray& rayLocalSpace, std::vector<Intersection>& intersections) const  = 0;


protected:
    Matrix mTransform = Matrix::identity();
    static int mId;
    Material mMaterial = Material();

};

}
