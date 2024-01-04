#pragma once
#include "shape_types.h"
#include "matrix.h"
#include "vec.h"
#include "point.h"

namespace rt{

class Shape{
public:

    Shape(ShapeType type);

    int id() const;
    ShapeType type() const;
    //transform() has the semantic sense of doing some transformation, but essentially we are returning the member variable transform. Naming as getTransform instead.
    Matrix getTransform() const;
    void setTransform(const Matrix& mat);
    
    virtual Vec normalAt(const Point& worldPt) const = 0;

protected:
    Matrix mTransform = Matrix::identity();

private:

    static int mId;
    //type tagging. Violates the open/closed principle, but who gives a fuck.
    //doesn't seem too dangerous for my use case.
    ShapeType mType;

};

}
