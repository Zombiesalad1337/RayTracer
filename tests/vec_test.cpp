#include <gtest/gtest.h>
#include <cmath>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"

TEST(Vec, magnitude){
    rt::Vec a(1, 0, 0);
    rt::Vec b(0, 1, 0);
    rt::Vec c(0, 0, 1);
    rt::Vec d(1, 2, 3);
    rt::Vec e(-1, -2, -3);

    EXPECT_NEAR(a.magnitude(), 1, EPSILON);
    EXPECT_NEAR(b.magnitude(), 1, EPSILON);
    EXPECT_NEAR(c.magnitude(), 1, EPSILON);
    EXPECT_NEAR(d.magnitude(), sqrt(14), EPSILON);
    EXPECT_NEAR(e.magnitude(), sqrt(14), EPSILON);
}

TEST(Vec, normalize){
    rt::Vec a(4, 0, 0);
    rt::Vec aNorm(1, 0, 0);
    rt::Vec b(1, 2, 3);
    rt::Vec bNorm(1.0f / sqrt(14), 2.0f / sqrt(14), 3.0f / sqrt(14));

    EXPECT_EQ(a.norm(), aNorm);
    EXPECT_EQ(b.norm(), bNorm);
    EXPECT_NEAR(b.norm().magnitude(), 1, EPSILON);
}

TEST(Vec, dotProduct){
    rt::Vec a(1, 2, 3);
    rt::Vec b(2, 3, 4);
    EXPECT_EQ(dot(a, b), 20);
}

TEST(Vec, crossProduct){
    rt::Vec a(1, 2, 3);
    rt::Vec b(2, 3, 4);
    EXPECT_EQ(cross(a, b), rt::Vec(-1, 2, -1));
    EXPECT_EQ(cross(b, a), rt::Vec(1, -2, 1));
}
