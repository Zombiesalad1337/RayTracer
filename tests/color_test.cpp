#include <gtest/gtest.h>
#include <cmath>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/color.h"

TEST(Color, create){
    rt::Color c(-0.5, 0.4, 1.7);
    EXPECT_NEAR(c.r(), -0.5, EPSILON);
    EXPECT_NEAR(c.g(), 0.4, EPSILON);
    EXPECT_NEAR(c.b(), 1.7, EPSILON);
}

TEST(Color, add){
    rt::Color c1(0.9, 0.6, 0.75);
    rt::Color c2(0.7, 0.1, 0.25);
    EXPECT_EQ(c1 + c2, rt::Color(1.6, 0.7, 1.0));
}

TEST(Color, subtract){
    rt::Color c1(0.9, 0.6, 0.75);
    rt::Color c2(0.7, 0.1, 0.25);
    EXPECT_EQ(c1 - c2, rt::Color(0.2, 0.5, 0.5));
}

TEST(Color, multiplyByScaler){
    rt::Color c(0.2, 0.3, 0.4);
    EXPECT_EQ(c * 2.0f, rt::Color(0.4, 0.6, 0.8));
}

TEST(Color, HadamardProduct){
    rt::Color c1(1, 0.2, 0.4);
    rt::Color c2(0.9, 1, 0.1);
    EXPECT_EQ(c1 * c2, rt::Color(0.9, 0.2, 0.04));
}

