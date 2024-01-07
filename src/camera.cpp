#include "camera.h"
#include <cmath>

namespace rt{


Camera::Camera(int hsize, int vsize, float fov) : mHsize(hsize), mVsize(vsize), mFov(fov) {
    float halfView = tanf(fov / 2);
    float aspect = (float) hsize / vsize;
    
    if (aspect >= 1){
        mHalfWidth = halfView;
        mHalfHeight = halfView / aspect;
    }
    else{
        mHalfWidth = halfView * aspect;
        mHalfHeight = halfView;
    }
    mPixelSize = (mHalfWidth * 2) / hsize;
}

Ray Camera::rayForPixel(int x, int y) const{
    //cast ray to center of pixel
    float xOffset = (x + 0.5) * mPixelSize;
    float yOffset = (y + 0.5) * mPixelSize;

    //camera looks towards -z, +x is to the left
    float worldX = mHalfWidth - xOffset;
    float worldY = mHalfHeight - yOffset;

    // Matrix invTransform = mTransform.inverse();
    //canvas 1 unit away
    
    Point pixel = mInverseTransform * Point(worldX, worldY, -1);
    //TODO: why move origin, isnt ray cast from center of camera to canvas? we moved canvas (pixel), but origin should be 0,0,0?
    Point origin = mInverseTransform * Point(0, 0, 0);

    Vec direction = Vec(pixel - origin).norm();

    return Ray(origin, direction);
}

void Camera::setTransform(const Matrix& transform) { 
    mTransform = transform; 
    mInverseTransform = transform.inverse();
}

int Camera::hsize() const { return mHsize; }
int Camera::vsize() const { return mVsize; }
float Camera::fov() const { return mFov; }
float Camera::halfWidth() const { return mHalfWidth; }
float Camera::halfHeight() const { return mHalfHeight; }
float Camera::pixelSize() const { return mPixelSize; }
Matrix Camera::transform() const { return mTransform; }


}
