#include <gtest/gtest.h>
#include <cmath>

#include "../src/tuple.h"


TEST(Tuple, isPoint){
    rt::Tuple tup(4.3, -4.2, 3.1, 1.0); 
    //EXPECT_EQ handles floats well? need epsilon?
    EXPECT_NEAR(tup.x, 4.3, EPSILON);
    EXPECT_NEAR(tup.y, -4.2, EPSILON);
    EXPECT_NEAR(tup.z, 3.1, EPSILON);
    EXPECT_NEAR(tup.w, 1.0, EPSILON);
    EXPECT_EQ(tup.isPoint(), true);
    EXPECT_NE(tup.isVec(), true);
}

TEST(Tuple, isVec){
    rt::Tuple tup(4.3, -4.2, 3.1, 0.0); 
    EXPECT_NEAR(tup.x, 4.3, EPSILON);
    EXPECT_NEAR(tup.y, -4.2, EPSILON);
    EXPECT_NEAR(tup.z, 3.1, EPSILON);
    EXPECT_NEAR(tup.w, 0.0, EPSILON);
    EXPECT_EQ(tup.isVec(), true);
    EXPECT_NE(tup.isPoint(), true);
}

TEST(Tuple, point){
    rt::Tuple tup = rt::point(4, -4, 3);
    rt::Tuple pt(4, -4, 3, 1);
    EXPECT_EQ(tup.equals(pt), true);
    EXPECT_EQ(tup, pt);
}

TEST(Tuple, vec){
    rt::Tuple tup = rt::vec(4, -4, 3);
    rt::Tuple v(4, -4, 3, 0);
    EXPECT_EQ(tup.equals(v), true);
    EXPECT_EQ(tup, v);
}

TEST(Tuple, add){
    rt::Tuple a1 = rt::Tuple(3, -2, 5, 1);
    rt::Tuple a2 = rt::Tuple(-2, 3, 1, 0);
    rt::Tuple res = rt::Tuple(1, 1, 6, 1);
    rt::Tuple added = a1 + a2;
    EXPECT_EQ(res.equals(added), true);
    EXPECT_EQ(res, added);
}

TEST(Tuple, subPointFromPoint){
    rt::Tuple p1 = rt::point(3, 2, 1);
    rt::Tuple p2 = rt::point(5, 6, 7);
    rt::Tuple res = rt::vec(-2, -4, -6);
    rt::Tuple diff = p1 - p2;
    EXPECT_EQ(res.equals(diff), true);
    EXPECT_EQ(res == diff, true);
    EXPECT_NE(res != diff, true);
}

TEST(Tuple, subVecFromPoint){
    rt::Tuple p1 = rt::point(3, 2, 1);
    rt::Tuple p2 = rt::vec(5, 6, 7);
    rt::Tuple res = rt::point(-2, -4, -6);
    rt::Tuple diff = p1 - p2;
    EXPECT_EQ(res.equals(diff), true);
    EXPECT_EQ(res, diff);
}
TEST(Tuple, subVecFromVec){
    rt::Tuple p1 = rt::vec(3, 2, 1);
    rt::Tuple p2 = rt::vec(5, 6, 7);
    rt::Tuple res = rt::vec(-2, -4, -6);
    rt::Tuple diff = p1 - p2;
    EXPECT_EQ(res.equals(diff), true);
    EXPECT_EQ(res, diff);
}

TEST(Tuple, negateTuple){
    rt::Tuple a = rt::Tuple(1, -2, 3, -4);
    rt::Tuple aNegated = rt::Tuple(-1, 2, -3, 4);
    //EXPECT_EQ(a, b) ==> returns a == b. Now that I've defined == and != on tuples,
    //there's no need to do EXPECT_EQ(a == b, true);
    EXPECT_EQ(-a, aNegated);
}

TEST(Tuple, scalarMultiplication){
    rt::Tuple a = rt::Tuple(1, -2, 3, -4);
    rt::Tuple aScaled = rt::Tuple(3.5, -7, 10.5, -14);
    EXPECT_EQ(a * 3.5, aScaled);
}

TEST(Tuple, scalarDivision){
    rt::Tuple a = rt::Tuple(1, -2, 3, -4);
    rt::Tuple aScaled = rt::Tuple(0.5, -1, 1.5, -2);
    EXPECT_EQ(a / 2, aScaled);
}

TEST(Tuple, magnitude){
    rt::Tuple a = rt::vec(1, 0, 0);
    rt::Tuple b = rt::vec(0, 1, 0);
    rt::Tuple c = rt::vec(0, 0, 1);
    rt::Tuple d = rt::vec(1, 2, 3);
    rt::Tuple e = rt::vec(-1, -2, -3);

    EXPECT_NEAR(a.magnitude(), 1, EPSILON);
    EXPECT_NEAR(b.magnitude(), 1, EPSILON);
    EXPECT_NEAR(c.magnitude(), 1, EPSILON);
    EXPECT_NEAR(d.magnitude(), sqrt(14), EPSILON);
    EXPECT_NEAR(e.magnitude(), sqrt(14), EPSILON);
}

TEST(Tuple, normalize){
    rt::Tuple a = rt::vec(4, 0, 0);
    rt::Tuple aNorm = rt::vec(1, 0, 0);
    rt::Tuple b = rt::vec(1, 2, 3);
    rt::Tuple bNorm = rt::vec(1.0f / sqrt(14), 2.0f / sqrt(14), 3.0f / sqrt(14));

    EXPECT_EQ(a.norm(), aNorm);
    EXPECT_EQ(b.norm(), bNorm);
    EXPECT_NEAR(b.norm().magnitude(), 1, EPSILON);
}
