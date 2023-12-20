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

TEST(Matrix, multiplyMat){
    std::vector<std::vector<float>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
    std::vector<std::vector<float>> vec2 = {{-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}};
    std::vector<std::vector<float>> vec3 = {{20, 22, 50, 48}, {44, 54, 114, 108}, {40, 58, 110, 102}, {16, 26, 46, 42}};
    rt::Matrix m(vec);
    rt::Matrix n(vec2);
    rt::Matrix expected(vec3);
    rt::Matrix result = m * n;

    EXPECT_TRUE(result == expected);
}

TEST(Matrix, multiplyTup){
    std::vector<std::vector<float>> vec = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
    rt::Matrix mat(vec);
    rt::Tuple tup(1.0f, 2.0f, 3.0f, 1.0f);
    rt::Tuple expected(18.0f, 24.0f, 33.0f, 1.0f);
    rt::Tuple result = mat * tup;

    EXPECT_TRUE(result == expected);

}
//TODO: DEBUG: passing for 24.5f
TEST(Matrix, multiplyTupSHOULDFAIL){
    std::vector<std::vector<float>> vec = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
    rt::Matrix mat(vec);
    rt::Tuple tup(1.0f, 2.0f, 3.0f, 1.0f);
    rt::Tuple expected(18.0f, 24.5f, 33.0f, 1.0f);
    rt::Tuple result = mat * tup;
    std::cout << "XXXXXXXXXx " << result.x << " " << result.y << " " << result.z << " " << result.w << std::endl;
 
    EXPECT_TRUE(result == expected);

}

TEST(Matrix, multiplyMatIdentity){
    std::vector<std::vector<float>> vec = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
    std::vector<std::vector<float>> vec2 = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    rt::Matrix mat(vec);
    rt::Matrix identity(vec2);
    rt::Matrix mul = mat * identity;

    EXPECT_EQ(mat, mul);
}

TEST(Matrix, multiplyTupIdentity){
    rt::Tuple tup(1.0f, 2.0f, 3.0f, 4.0f);
    std::vector<std::vector<float>> vec2 = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    rt::Matrix identity(vec2);
    rt::Tuple res = identity * tup;

    EXPECT_EQ(tup, res);
}


TEST(Matrix, transposeMat){
    std::vector<std::vector<float>> vec = {{0, 9, 3, 0}, {9, 8, 0, 8}, {1, 8, 5, 3}, {0, 0, 5, 8}};
    std::vector<std::vector<float>> vec2 = {{0, 9, 1, 0}, {9, 8, 8, 0}, {3, 0, 5, 5}, {0, 8, 3, 8}};
    rt::Matrix mat(vec);
    rt::Matrix expected(vec2);
    rt::Matrix result = mat.transpose(); 
    EXPECT_EQ(expected, result);
}

TEST(Matrix, transposeIdentity){
    std::vector<std::vector<float>> vec = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    rt::Matrix identity(vec);
    rt::Matrix transpose = identity.transpose(); 
    EXPECT_EQ(identity, transpose);
}

TEST(Matrix, cofactor3by3){
    std::vector<std::vector<float>> vec = {
        {3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}
    };
    rt::Matrix mat(vec);
    EXPECT_EQ(mat.cofactor(0, 0), -12);
    EXPECT_EQ(mat.cofactor(1, 0), -25);
}

TEST(Matrix, determinant3x3){
    std::vector<std::vector<float>> vec = {
        {1, 2, 6},
        {-5, 8, -4},
        {2, 6, 4}
    };
    rt::Matrix mat(vec);
    EXPECT_EQ(mat.cofactor(0, 0), 56);
    EXPECT_EQ(mat.cofactor(0, 1), 12);
    EXPECT_EQ(mat.cofactor(0, 2), -46);
    EXPECT_EQ(mat.det(), -196);
}

TEST(Matrix, determinant4x4){
    std::vector<std::vector<float>> vec = {
        {-2, -8, 3, 5},
        {-3, 1, 7, 3},
        {1, 2, -9, 6},
        {-6, 7, 7, -9}
    };
    rt::Matrix mat(vec);
    EXPECT_EQ(mat.cofactor(0, 0), 690);
    EXPECT_EQ(mat.cofactor(0, 1), 447);
    EXPECT_EQ(mat.cofactor(0, 2), 210);
    EXPECT_EQ(mat.cofactor(0, 3), 51);
    EXPECT_EQ(mat.det(), -4071);
}




