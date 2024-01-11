#include <gtest/gtest.h>
#include <cmath>
#include <optional>
#include <vector>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/plane.h"


TEST(Plane, normal1){
    rt::Plane p;
    const rt::Shape& s = p;
    EXPECT_EQ(s.normalAt(rt::Point(0, 0, 0)), rt::Vec(0, 1, 0));
}

TEST(Plane, normal2){
    rt::Plane p;
    const rt::Shape& s = p;
    EXPECT_EQ(s.normalAt(rt::Point(10, 0, -10)), rt::Vec(0, 1, 0));
}

TEST(Plane, normal3){
    rt::Plane p;
    const rt::Shape& s = p;
    EXPECT_EQ(s.normalAt(rt::Point(5, 0, 150)), rt::Vec(0, 1, 0));
}

TEST(Plane, parallel){
    rt::Plane p;
    const rt::Shape& s = p;
    rt::Ray r(rt::Point(0, 10, 0), rt::Vec(0, 0, 1));
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections);
    EXPECT_FALSE(xs.has_value());
}

TEST(Plane, coplanar){
    rt::Plane p;
    const rt::Shape& s = p;
    rt::Ray r(rt::Point(0, 0, 0), rt::Vec(0, 0, 1));
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections);
    EXPECT_FALSE(xs.has_value());
}

TEST(Plane, originAbovePlane){
    rt::Plane p;
    const rt::Shape& s = p;
    rt::Ray r(rt::Point(0, 1, 0), rt::Vec(0, -1, 0));
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections);
    EXPECT_TRUE(xs.has_value());
    EXPECT_EQ(xs.value().size(), 1);
    EXPECT_NEAR(xs.value()[0].t, 1.0f, EPSILON);
    EXPECT_EQ(xs.value()[0].object, &p);
}

TEST(Plane, originBelowPlane){
    rt::Plane p;
    const rt::Shape& s = p;
    rt::Ray r(rt::Point(0, -1, 0), rt::Vec(0, 1, 0));
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections);
    EXPECT_TRUE(xs.has_value());
    EXPECT_EQ(xs.value().size(), 1);
    EXPECT_NEAR(xs.value()[0].t, 1.0f, EPSILON);
    EXPECT_EQ(xs.value()[0].object, &p);
}

