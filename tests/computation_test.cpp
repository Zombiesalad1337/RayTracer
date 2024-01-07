#include <gtest/gtest.h>
#include <cmath>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/color.h"
#include "../src/material.h"
#include "../src/point_light.h"
#include "../src/sphere.h"
#include "../src/lighting.h"
#include "../src/computation.h"
    
using namespace rt;

TEST(Computation, Computation){
    Ray r(Point(0, 0, -5), Vec(0, 0, 1));
    Sphere sp;
    const Shape& s = sp;
    Intersection i(4, &s);

    Computation comp(i, r);

    EXPECT_FALSE(comp.inside);
    EXPECT_NEAR(comp.t, i.t, EPSILON);
    EXPECT_EQ(comp.shape, i.object);
    EXPECT_EQ(comp.point, Point(0, 0, -1));
    EXPECT_EQ(comp.eyev, Vec(0, 0, -1));
    EXPECT_EQ(comp.normalv, Vec(0, 0, -1));
}

TEST(Computation, HitInside){
    Ray r(Point(0, 0, 0), Vec(0, 0, 1));
    Sphere sp;
    const Shape& s = sp;
    Intersection i(1, &s);

    Computation comp(i, r);

    EXPECT_EQ(comp.point, Point(0, 0, 1));
    EXPECT_EQ(comp.eyev, Vec(0, 0, -1));
    EXPECT_EQ(comp.normalv, Vec(0, 0, -1));
    EXPECT_TRUE(comp.inside);

}
