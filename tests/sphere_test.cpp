#include <gtest/gtest.h>
#include <cmath>
#include <optional>
#include <vector>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/sphere.h"


TEST(Sphere, normal1){
    rt::Sphere sp;
    const rt::Shape& s = sp;
    EXPECT_EQ(s.normalAt(rt::Point(1, 0, 0)), rt::Vec(1, 0, 0));
}

TEST(Sphere, normal2){
    rt::Sphere sp;
    const rt::Shape& s = sp;
    EXPECT_EQ(s.normalAt(rt::Point(0, 1, 0)), rt::Vec(0, 1, 0));
}

TEST(Sphere, normal3){
    rt::Sphere sp;
    const rt::Shape& s = sp;
    EXPECT_EQ(s.normalAt(rt::Point(0, 0, 1)), rt::Vec(0, 0, 1));
}

TEST(Sphere, normal4){
    rt::Sphere sp;
    const rt::Shape& s = sp;
    EXPECT_EQ(s.normalAt(rt::Point(sqrtf(3)/3, sqrtf(3)/3, sqrtf(3)/3)), rt::Vec(sqrtf(3)/3, sqrtf(3)/3, sqrtf(3)/3));
}

TEST(Sphere, normalIsNorm){
    rt::Sphere sp;
    const rt::Shape& s = sp;
    rt::Vec n = s.normalAt(rt::Point(sqrtf(3)/3, sqrtf(3)/3, sqrtf(3)/3)); 
    EXPECT_EQ(n, n.norm());
}

TEST(Sphere, normalTransformed){
    rt::Sphere sp;
    rt::Shape& s = sp;
    s.setTransform(rt::Matrix::scaling(1, 0.5, 1) * rt::Matrix::rotationZ(M_PI / 5));
    rt::Vec n = s.normalAt(rt::Point(0, sqrtf(2)/2, -sqrtf(2)/2)); 
    EXPECT_EQ(n, rt::Vec(0, 0.97014, -0.24254));
}

TEST(Sphere, normalTranslated){
    rt::Sphere sp;
    rt::Shape& s = sp;
    s.setTransform(rt::Matrix::translation(0, 1, 0));
    rt::Vec n = s.normalAt(rt::Point(0, 1.70711, -0.70711)); 
    EXPECT_EQ(n, rt::Vec(0, 0.70711, -0.70711));
}

TEST(Sphere, defaultMaterial){
    rt::Sphere sp;
    rt::Shape& s = sp;
    EXPECT_EQ(s.material(), rt::Material());
}

TEST(Sphere, setMaterial){
    rt::Sphere sp;
    rt::Shape& s = sp;
    rt::Material m;
    m.setAmbient(1.0f);
    s.setMaterial(m);
    EXPECT_EQ(s.material(), m);
    EXPECT_NEAR(s.material().ambient(), 1.0f, EPSILON);
}
