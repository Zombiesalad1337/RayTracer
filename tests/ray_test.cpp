#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "../src/canvas.h"
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/color.h"
#include "../src/matrix.h"
#include "../src/ray.h"


TEST(Ray, creatingRay){
    rt::Point origin(1, 2, 3);
    rt::Vec direction(4, 5, 6);

    rt::Ray r(origin, direction);
    EXPECT_EQ(r.origin(), origin);
    EXPECT_EQ(r.direction(), direction);
}

TEST(Ray, position){
    rt::Ray r(rt::Point(2, 3, 4), rt::Vec(1, 0, 0));
    EXPECT_EQ(r.position(0), rt::Point(2, 3, 4));
    EXPECT_EQ(r.position(1), rt::Point(3, 3, 4));
    EXPECT_EQ(r.position(-1), rt::Point(1, 3, 4));
    EXPECT_EQ(r.position(2.5), rt::Point(4.5, 3, 4));
}

TEST(Ray, translate){
    rt::Ray r(rt::Point(1, 2, 3), rt::Vec(0, 1, 0));
    rt::Matrix m = rt::Matrix::translation(3, 4, 5);

    rt::Ray r2 = r.transform(m);

    EXPECT_EQ(r2.origin(), rt::Point(4, 6, 8));
    EXPECT_EQ(r2.direction(), rt::Vec(0, 1, 0));
}

TEST(Ray, scale){
    rt::Ray r(rt::Point(1, 2, 3), rt::Vec(0, 1, 0));
    rt::Matrix m = rt::Matrix::scaling(2, 3, 4);

    rt::Ray r2 = r.transform(m);

    EXPECT_EQ(r2.origin(), rt::Point(2, 6, 12));
    //direction left unnormalized. Essential as scaling stretches the vector, so it covers more distance per unit t
    EXPECT_EQ(r2.direction(), rt::Vec(0, 3, 0));
}
