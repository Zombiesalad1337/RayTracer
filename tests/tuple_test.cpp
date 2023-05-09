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
}

TEST(Tuple, vec){
    rt::Tuple tup = rt::vec(4, -4, 3);
    rt::Tuple v(4, -4, 3, 0);
    EXPECT_EQ(tup.equals(v), true);
}
