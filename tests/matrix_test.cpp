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

TEST(Matrix, invertibleYes){
    std::vector<std::vector<float>> vec = {
        {6, 4, 4, 4},
        {5, 5, 7, 6},
        {4, -9, 3, -7},
        {9, 1, 7, -6}
    };
    rt::Matrix mat(vec);
    EXPECT_TRUE(mat.invertible());
}

TEST(Matrix, invertibleNo){
    std::vector<std::vector<float>> vec = {
        {-4, 2, -2, -3},
        {9, 6, 2, 6},
        {0, -5, 1, -5},
        {0, 0, 0, 0}
    };
    rt::Matrix mat(vec);
    EXPECT_FALSE(mat.invertible());
}

TEST(Matrix, inverse3x3){

    std::vector<std::vector<float>> originalMatrix = {
        {2, 1, 4},
        {1, 3, 5},
        {6, 2, 1}
    };

    // Inverse matrix as a 2D vector
     std::vector<std::vector<float>> inverseMatrix = {
        {0.142857, -0.142857, 0.142857},
        {-0.591837, 0.163265, 0.122449},
        {0.326531, -0.0408163, -0.102041}
    };

    rt::Matrix og(originalMatrix);
    rt::Matrix inv(inverseMatrix);
    rt::Matrix m = og.inverse();
        
    EXPECT_EQ(m, inv);
    

}

TEST(Matrix, inverse4x4_1){
    std::vector<std::vector<float>> originalMatrix = {
        {8, -5, 9, 2},
        {7, 5, 6, 1},
        {-6, 0, 9, 6},
        {-3, 0, -9, -4}
    };

    // Inverse matrix as a 2D vector
    std::vector<std::vector<float>> inverseMatrix = {
        {-0.15385, -0.15385, -0.28205, -0.53846},
        {-0.07692, 0.12308, 0.02564, 0.03077},
        {0.35897, 0.35897, 0.43590, 0.92308},
        {-0.69231, -0.69231, -0.76923, -1.92308}
    };

    rt::Matrix og(originalMatrix);
    rt::Matrix inv(inverseMatrix);
    rt::Matrix m = og.inverse();
        
    EXPECT_EQ(m, inv);
    

}

TEST(Matrix, inverse4x4_2){
    std::vector<std::vector<float>> originalMatrix = {
            {-5, 2, 6, -8},
            {1, -5, 1, 8},
            {7, 7, -6, -7},
            {1, -3, 7, 4}
        };

    // Inverse matrix as a 2D vector
    std::vector<std::vector<float>> inverseMatrix = {
        {0.21805, 0.45113, 0.24060, -0.04511},
        {-0.80827, -1.45677, -0.44361, 0.52068},
        {-0.07895, -0.22368, -0.05263, 0.19737},
        {-0.52256, -0.81391, -0.30075, 0.30639}
    };

    rt::Matrix og(originalMatrix);
    rt::Matrix inv(inverseMatrix);
    rt::Matrix m = og.inverse();

    EXPECT_NEAR(og.det(), 532, EPSILON);
    EXPECT_NEAR(og.cofactor(2, 3), -160, EPSILON);
    EXPECT_NEAR(inv.get(3, 2), -160.0f/532.0f, EPSILON);
    EXPECT_NEAR(og.cofactor(3, 2), 105, EPSILON);
    EXPECT_NEAR(inv.get(2, 3), 105.0f/532.0f, EPSILON);
        
    EXPECT_EQ(m, inv);
    

}

TEST(Matrix, inverse4x4_3){
    std::vector<std::vector<float>> originalMatrix = {
        {8, -5, 9, 2},
        {7, 5, 6, 1},
        {-6, 0, 9, 6},
        {-3, 0, -9, -4}
    };

    // Inverse matrix as a 2D vector
    std::vector<std::vector<float>> inverseMatrix = {
        {-0.15385, -0.15385, -0.28205, -0.53846},
        {-0.07692, 0.12308, 0.02564, 0.03077},
        {0.35897, 0.35897, 0.43590, 0.92308},
        {-0.69231, -0.69231, -0.76923, -1.92308}
    };

    rt::Matrix og(originalMatrix);
    rt::Matrix inv(inverseMatrix);
    rt::Matrix m = og.inverse();

    EXPECT_EQ(m, inv);
}

TEST(Matrix, inverse4x4_4){
    std::vector<std::vector<float>> originalMatrix = {
        {9, 3, 0, 9},
        {-5, -2, -6, -3},
        {-4, 9, 6, 4},
        {-7, 6, 6, 2}
    };

    // Inverse matrix as a 2D vector
    std::vector<std::vector<float>> inverseMatrix = {
        {-0.04074, -0.07778, 0.14444, -0.22222},
        {-0.07778, 0.03333, 0.36667, -0.33333},
        {-0.02901, -0.14630, -0.10926, 0.12963},
        {0.17778, 0.06667, -0.26667, 0.33333}
    };

    rt::Matrix og(originalMatrix);
    rt::Matrix inv(inverseMatrix);
    rt::Matrix m = og.inverse();

    EXPECT_EQ(m, inv);

}


TEST(Matrix, multiplyProductByInverse){
    std::vector<std::vector<float>> matrixA = {
        {3, -9, 7, 3},
        {3, -8, 2, -9},
        {-4, 4, 4, 1},
        {-6, 5, -1, 1}
    };

    std::vector<std::vector<float>> matrixB = {
        {8, 2, 2, 2},
        {3, -1, 7, 0},
        {7, 0, 5, 4},
        {6, -2, 0, 5}
    };

    rt::Matrix a(matrixA);
    rt::Matrix b(matrixB);

    rt::Matrix c = a * b;

    rt::Matrix binv = b.inverse();

    rt::Matrix cMulBinv = c * binv;

    EXPECT_EQ(cMulBinv, a);
    EXPECT_EQ(a * b * b.inverse(), a);
}

TEST(Matrix, translation){
    rt::Matrix transform = rt::Matrix::translation(5, -3, 2);
    rt::Point p(-3, 4, 5);
    rt::Point translated(2, 1, 7);
    EXPECT_EQ(transform * p, translated);
}

TEST(Matrix, translationInv){
    rt::Matrix transform = rt::Matrix::translation(5, -3, 2);
    rt::Matrix inv = transform.inverse();
    rt::Point p(-3, 4, 5);
    rt::Point translated(-8, 7, 3);
    EXPECT_EQ(inv * p, translated);
}

TEST(Matrix, translationVec){
    rt::Matrix transform = rt::Matrix::translation(5, -3, 2);
    rt::Vec v(-3, 4, 5);
    EXPECT_EQ(transform * v, v);
}

TEST(Matrix, scaling){
    rt::Matrix transform = rt::Matrix::scaling(2, 3, 4);
    rt::Point p(-4, 6, 8);
    rt::Point scaled(-8, 18, 32);
    EXPECT_EQ(transform * p, scaled);
}

TEST(Matrix, scalingVec){
    rt::Matrix transform = rt::Matrix::scaling(2, 3, 4);
    rt::Vec v(-4, 6, 8);
    rt::Vec scaled(-8, 18, 32);
    EXPECT_EQ(transform * v, scaled);
}

TEST(Matrix, scalingInv){
    rt::Matrix transform = rt::Matrix::scaling(2, 3, 4);
    rt::Matrix inv = transform.inverse();
    rt::Vec v(-4, 6, 8);
    rt::Vec scaled(-2, 2, 2);
    EXPECT_EQ(inv * v, scaled);
}

TEST(Matrix, reflectAcrossXAxis){
    rt::Matrix transform = rt::Matrix::scaling(-1, 1, 1);
    rt::Point p(2, 3, 4);
    rt::Point reflected(-2, 3, 4);
    EXPECT_EQ(transform * p, reflected);
}

TEST(Matrix, rotateX){
    rt::Matrix half_quarter = rt::Matrix::rotationX(M_PI / 4);
    rt::Matrix full_quarter = rt::Matrix::rotationX(M_PI / 2);
    rt::Point p(0, 1, 0);
    rt::Point half_rotated(0, std::sqrt(2) / 2, std::sqrt(2) / 2);
    rt::Point full_rotated(0, 0, 1);
    EXPECT_EQ(half_quarter * p, half_rotated);
    EXPECT_EQ(full_quarter * p, full_rotated);
}

TEST(Matrix, rotateXInv){
    rt::Matrix half_quarter = rt::Matrix::rotationX(M_PI / 4);
    rt::Point p(0, 1, 0);
    rt::Matrix half_quarter_inv = half_quarter.inverse();
    rt::Point half_rotated_inv(0, std::sqrt(2) / 2, -std::sqrt(2) / 2);
    EXPECT_EQ(half_quarter_inv * p, half_rotated_inv);
}

TEST(Matrix, rotateY){
    rt::Matrix half_quarter = rt::Matrix::rotationY(M_PI / 4);
    rt::Matrix full_quarter = rt::Matrix::rotationY(M_PI / 2);
    rt::Point p(0, 0, 1);
    rt::Point half_rotated(std::sqrt(2) / 2, 0, std::sqrt(2) / 2);
    rt::Point full_rotated(1, 0, 0);
    EXPECT_EQ(half_quarter * p, half_rotated);
    EXPECT_EQ(full_quarter * p, full_rotated);
}

TEST(Matrix, rotateZ){
    rt::Matrix half_quarter = rt::Matrix::rotationZ(M_PI / 4);
    rt::Matrix full_quarter = rt::Matrix::rotationZ(M_PI / 2);
    rt::Point p(0, 1, 0);
    rt::Point half_rotated(-std::sqrt(2) / 2,  std::sqrt(2) / 2, 0);
    rt::Point full_rotated(-1, 0, 0);
    EXPECT_EQ(half_quarter * p, half_rotated);
    EXPECT_EQ(full_quarter * p, full_rotated);
}

TEST(Matrix, shearXY){
    rt::Matrix shearing = rt::Matrix::shearing(1, 0, 0, 0, 0, 0);
    rt::Point p(2, 3, 4);
    rt::Point sheared(5, 3, 4);
    EXPECT_EQ(shearing * p, sheared);
}

TEST(Matrix, shearXZ){
    rt::Matrix shearing = rt::Matrix::shearing(0, 1, 0, 0, 0, 0);
    rt::Point p(2, 3, 4);
    rt::Point sheared(6, 3, 4);
    EXPECT_EQ(shearing * p, sheared);
}

TEST(Matrix, shearYX){
    rt::Matrix shearing = rt::Matrix::shearing(0, 0, 1, 0, 0, 0);
    rt::Point p(2, 3, 4);
    rt::Point sheared(2, 5, 4);
    EXPECT_EQ(shearing * p, sheared);
}

TEST(Matrix, shearYZ){
    rt::Matrix shearing = rt::Matrix::shearing(0, 0, 0, 1, 0, 0);
    rt::Point p(2, 3, 4);
    rt::Point sheared(2, 7, 4);
    EXPECT_EQ(shearing * p, sheared);
}

TEST(Matrix, shearZX){
    rt::Matrix shearing = rt::Matrix::shearing(0, 0, 0, 0, 1, 0);
    rt::Point p(2, 3, 4);
    rt::Point sheared(2, 3, 6);
    EXPECT_EQ(shearing * p, sheared);
}

TEST(Matrix, shearZY){
    rt::Matrix shearing = rt::Matrix::shearing(0, 0, 0, 0, 0, 1);
    rt::Point p(2, 3, 4);
    rt::Point sheared(2, 3, 7);
    EXPECT_EQ(shearing * p, sheared);
}

TEST(Matrix, transformationsOneByOne){
    rt::Point p(1, 0, 1);
    rt::Matrix A = rt::Matrix::rotationX(M_PI / 2);
    rt::Matrix B = rt::Matrix::scaling(5, 5, 5);
    rt::Matrix C = rt::Matrix::translation(10, 5, 7);

    rt::Point p2 = A * p;
    EXPECT_EQ(p2, rt::Point(1, -1, 0));
    rt::Point p3 = B * p2;
    EXPECT_EQ(p3, rt::Point(5, -5, 0));
    rt::Point p4 = C * p3;
    EXPECT_EQ(p4, rt::Point(15, 0, 7));
}

TEST(Matrix, chainTransformation){
    rt::Point p(1, 0, 1);
    rt::Matrix A = rt::Matrix::rotationX(M_PI / 2);
    rt::Matrix B = rt::Matrix::scaling(5, 5, 5);
    rt::Matrix C = rt::Matrix::translation(10, 5, 7);

    rt::Matrix T = C * B * A;

    EXPECT_EQ(T * p, rt::Point(15, 0, 7));
    EXPECT_EQ(C * B * A * p, rt::Point(15, 0, 7));
}

