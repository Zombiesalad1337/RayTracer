#pragma once
#include "ray.h"

namespace rt{

class Camera{
public:
    Camera(int hsize, int vsize, float fov);
    Ray rayForPixel(int x, int y) const;

    void setTransform(const Matrix& transform);
    int hsize() const;
    int vsize() const;
    float fov() const;
    float halfWidth() const;
    float halfHeight() const;
    float pixelSize() const;
    Matrix transform() const;

private:
    int mHsize;
    int mVsize;
    float mFov;
    float mHalfWidth;
    float mHalfHeight;
    float mPixelSize;
    Matrix mTransform = Matrix::identity();
    //inverse of transform calculated for each ray to canvas. Instead saved it as member variable, updated when setTransform is called.
    Matrix mInverseTransform = Matrix::identity();
};

}
