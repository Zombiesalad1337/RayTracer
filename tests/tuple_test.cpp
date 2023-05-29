#include <gtest/gtest.h>

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
    EXPECT_EQ(tup == pt, true);
}

TEST(Tuple, vec){
    rt::Tuple tup = rt::vec(4, -4, 3);
    rt::Tuple v(4, -4, 3, 0);
    EXPECT_EQ(tup.equals(v), true);
    EXPECT_EQ(tup == v, true);
}

TEST(Tuple, add){
    rt::Tuple a1 = rt::Tuple(3, -2, 5, 1);
    rt::Tuple a2 = rt::Tuple(-2, 3, 1, 0);
    rt::Tuple res = rt::Tuple(1, 1, 6, 1);
    rt::Tuple added = a1 + a2;
    EXPECT_EQ(res.equals(added), true);
    EXPECT_EQ(res == added, true);
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
    EXPECT_EQ(res == diff, true);
}
TEST(Tuple, subVecFromVec){
    rt::Tuple p1 = rt::vec(3, 2, 1);
    rt::Tuple p2 = rt::vec(5, 6, 7);
    rt::Tuple res = rt::vec(-2, -4, -6);
    rt::Tuple diff = p1 - p2;
    EXPECT_EQ(res.equals(diff), true);
    EXPECT_EQ(res == diff, true);
}
