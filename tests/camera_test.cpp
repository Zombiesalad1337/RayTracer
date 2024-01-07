#include <gtest/gtest.h>
#include <cmath>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/color.h"
#include "../src/material.h"
#include "../src/point_light.h"
#include "../src/lighting.h"
#include "../src/world.h"
#include "../src/computation.h"
#include "../src/camera.h"
    
using namespace rt;

TEST(Camera, constructing){
    int hsize = 160;
    int vsize = 120;
    int fov = M_PI / 2;
    Camera c(hsize, vsize, fov);
    EXPECT_EQ(c.hsize(), hsize);
    EXPECT_EQ(c.vsize(), vsize);
    EXPECT_NEAR(c.fov(), fov, EPSILON);
    EXPECT_EQ(c.transform(), Matrix::identity());
}

TEST(Camera, pixelSizeAspect){
    Camera c(200, 125, M_PI / 2);
    Camera c2(125, 200, M_PI / 2);
    EXPECT_NEAR(c.pixelSize(), 0.01, EPSILON);
    EXPECT_NEAR(c2.pixelSize(), 0.01, EPSILON);
}

TEST(Camera, rayForPixel1){
    Camera c(201, 101, M_PI / 2);
    Ray r = c.rayForPixel(100, 50);
    EXPECT_EQ(r.origin(), Point(0, 0, 0));
    EXPECT_EQ(r.direction(), Vec(0, 0, -1));
}

TEST(Camera, rayForPixel2){
    Camera c(201, 101, M_PI / 2);
    Ray r = c.rayForPixel(0, 0);
    EXPECT_EQ(r.origin(), Point(0, 0, 0));
    EXPECT_EQ(r.direction(), Vec(0.66519, 0.33259, -0.66851));
}

TEST(Camera, rayForPixel3){
    Camera c(201, 101, M_PI / 2);
    c.setTransform(Matrix::rotationY(M_PI / 4) * Matrix::translation(0, -2, 5));
    Ray r = c.rayForPixel(100, 50);
    EXPECT_EQ(r.origin(), Point(0, 2, -5));
    EXPECT_EQ(r.direction(), Vec(sqrtf(2) / 2, 0, -sqrtf(2) / 2));
}
