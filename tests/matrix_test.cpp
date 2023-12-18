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

TEST(Matrix, create){
    std::vector<std::vector<float>> vec = {{1, 2, 3, 4}, {5.5, 6.5, 7.5, 8.5}, {9, 10, 11, 12}, {13.5, 14.5, 15.5, 16.5}};
    rt::Matrix m(vec);
    EXPECT_NEAR(m.get(0, 0), 1, EPSILON);
    EXPECT_NEAR(m.get(0, 3), 4, EPSILON);
    EXPECT_NEAR(m.get(1, 0), 5.5, EPSILON);
    EXPECT_NEAR(m.get(1, 2), 7.5, EPSILON);
    EXPECT_NEAR(m.get(2, 2), 11, EPSILON);
    EXPECT_NEAR(m.get(3, 0), 13.5, EPSILON);
    EXPECT_NEAR(m.get(3, 2), 15.5, EPSILON);
}

TEST(Matrix, twoBytwoCreate){
    std::vector<std::vector<float>> vec = {{-3, 5}, {1, -2}};
    rt::Matrix m(vec);
    EXPECT_NEAR(m.get(0, 0), -3, EPSILON);
    EXPECT_NEAR(m.get(0, 1), 5, EPSILON);
    EXPECT_NEAR(m.get(1, 0), 1, EPSILON);
    EXPECT_NEAR(m.get(1, 1), -2, EPSILON);
}


TEST(Matrix, threeBythreeCreate){
    std::vector<std::vector<float>> vec = {{-3, 5, 0}, {1, -2, -7}, {0, 1, 1}};
    rt::Matrix m(vec);
    EXPECT_NEAR(m.get(0, 0), -3, EPSILON);
    EXPECT_NEAR(m.get(1, 1), -2, EPSILON);
    EXPECT_NEAR(m.get(2, 2), 1, EPSILON);
}

TEST(Matrix, comparison1){
    std::vector<std::vector<float>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
    rt::Matrix m(vec);
    rt::Matrix n(vec);
    EXPECT_TRUE(m == n);
}

TEST(Matrix, comparison2){
    std::vector<std::vector<float>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
    std::vector<std::vector<float>> vec2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {11, 8, 7, 6}, {5, 4, 3, 2}};
    rt::Matrix m(vec);
    rt::Matrix n(vec2);
    EXPECT_FALSE(m == n);
}




