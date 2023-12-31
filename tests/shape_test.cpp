#include <gtest/gtest.h>
#include <cmath>
#include <optional>
#include <vector>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/sphere.h"


TEST(Shape, defaultTransform){
    rt::Sphere sp;
    const rt::Shape& s = sp;

    EXPECT_EQ(s.getTransform(), rt::Matrix::identity());
}

TEST(Shape, changeTransform){
    rt::Sphere sp;
    rt::Shape& s = sp;

    rt::Matrix t = rt::Matrix::translation(2, 3, 4);
    
    s.setTransform(t);
    
    EXPECT_EQ(s.getTransform(), t);
}
