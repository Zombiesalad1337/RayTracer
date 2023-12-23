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
