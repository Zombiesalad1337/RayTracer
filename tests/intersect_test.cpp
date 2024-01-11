#include <gtest/gtest.h>
#include <cmath>
#include <optional>
#include <vector>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/sphere.h"
#include "../src/intersection.h"


TEST(Intersection, raySphere2Pts){
    rt::Ray r(rt::Point(0, 0, -5), rt::Vec(0, 0, 1));
    rt::Sphere sp;
    const rt::Shape& s = sp;
    
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs =  s.intersect(r, intersections); 
    // std::cout << "has_value: " << xs.has_value() << std::endl;
    int size = xs.has_value() ? xs.value().size() : 0;

    EXPECT_EQ(size, 2);
    
    if (size == 2){
        EXPECT_NEAR(xs.value()[0].t, 4.0f, EPSILON);
        EXPECT_NEAR(xs.value()[1].t, 6.0f, EPSILON);
    }
}

TEST(Intersection, raySphereTangent){
    rt::Ray r(rt::Point(0, 1, -5), rt::Vec(0, 0, 1));
    rt::Sphere sp;
    const rt::Shape& s = sp;
    
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections); 
    // std::cout << "has_value: " << xs.has_value() << std::endl;
    int size = xs.has_value() ? xs.value().size() : 0;

    EXPECT_EQ(size, 2);
    
    if (size == 2){
        EXPECT_NEAR(xs.value()[0].t, 5.0f, EPSILON);
        EXPECT_NEAR(xs.value()[1].t, 5.0f, EPSILON);
    }
}

TEST(Intersection, raySphereMiss){
    rt::Ray r(rt::Point(0, 2, -5), rt::Vec(0, 0, 1));
    rt::Sphere sp;
    const rt::Shape& s = sp;
    
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections); 
    // std::cout << "has_value: " << xs.has_value() << std::endl;
    int size = xs.has_value() ? xs.value().size() : 0;

    EXPECT_EQ(size, 0);
    
    if (size == 2){
        EXPECT_NEAR(xs.value()[0].t, 5.0f, EPSILON);
        EXPECT_NEAR(xs.value()[1].t, 5.0f, EPSILON);
    }
}

TEST(Intersection, rayOriginatesInsideSphere){
    rt::Ray r(rt::Point(0, 0, 0), rt::Vec(0, 0, 1));
    rt::Sphere sp;
    const rt::Shape& s = sp;
    
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections); 
    // std::cout << "has_value: " << xs.has_value() << std::endl;
    int size = xs.has_value() ? xs.value().size() : 0;

    EXPECT_EQ(size, 2);
    
    if (size == 2){
        EXPECT_NEAR(xs.value()[0].t, -1.0f, EPSILON);
        EXPECT_NEAR(xs.value()[1].t, 1.0f, EPSILON);
    }
}

TEST(Intersection, rayOriginatesAfterSphere){
    rt::Ray r(rt::Point(0, 0, 5), rt::Vec(0, 0, 1));
    rt::Sphere sp;
    const rt::Shape& s = sp;
    
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections); 
    // std::cout << "has_value: " << xs.has_value() << std::endl;
    int size = xs.has_value() ? xs.value().size() : 0;

    EXPECT_EQ(size, 2);
    
    if (size == 2){
        EXPECT_NEAR(xs.value()[0].t, -6.0f, EPSILON);
        EXPECT_NEAR(xs.value()[1].t, -4.0f, EPSILON);
    }
}

TEST(Intersection, intersectionEncapsulate){
    rt::Sphere sp;
    const rt::Shape& s = sp;
    
    rt::Intersection i(3.5f, &s);

    EXPECT_NEAR(i.t, 3.5f, EPSILON);
    EXPECT_EQ(i.object, &s);
}

TEST(Intersection, intersectSetsTheObject){
    rt::Ray r(rt::Point(0, 0, -5), rt::Vec(0, 0, 1));
    
    //more efficient, no new object created
    rt::Sphere sp;
    const rt::Shape& s = sp;
    
    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections); 
    // std::cout << "has_value: " << xs.has_value() << std::endl;
    int size = xs.has_value() ? xs.value().size() : 0;

    EXPECT_EQ(size, 2);
    EXPECT_EQ(intersections.size(), 2);
    
    if (size == 2){
        EXPECT_EQ(xs.value()[0].object, &s);
        EXPECT_EQ(xs.value()[1].object, &s);
        if (intersections.size() == 2){
            EXPECT_EQ(intersections[0].object, &s);
            EXPECT_EQ(intersections[1].object, &s);

            EXPECT_EQ(intersections[0].object, xs.value()[0].object);
            EXPECT_EQ(intersections[1].object, xs.value()[1].object);

            EXPECT_NEAR(intersections[0].t, xs.value()[0].t, EPSILON);
            EXPECT_NEAR(intersections[1].t, xs.value()[1].t, EPSILON);
        }
    }
}

TEST(Intersection, hit1){
    rt::Sphere sp;
    const rt::Shape& s = sp;

    std::vector<rt::Intersection> intersections;
    
    rt::Intersection i1(1.0f, &s);
    rt::Intersection i2(2.0f, &s);

    intersections.push_back(i1);
    intersections.push_back(i2);

    std::optional<rt::Intersection> i = rt::Intersection::hit(intersections);

    EXPECT_TRUE(i.has_value());

    EXPECT_EQ(i.value(), i1);
    EXPECT_NE(i.value(), i2);
}

TEST(Intersection, hit2){
    rt::Sphere sp;
    const rt::Shape& s = sp;

    std::vector<rt::Intersection> intersections;
    
    rt::Intersection i1(-1.0f, &s);
    rt::Intersection i2(1.0f, &s);

    intersections.push_back(i2);
    intersections.push_back(i1);

    std::optional<rt::Intersection> i = rt::Intersection::hit(intersections);

    EXPECT_TRUE(i.has_value());

    // std::cout << "t: " << i.value().t << std::endl;
    EXPECT_EQ(i.value(), i2);
}

TEST(Intersection, hit3){
    rt::Sphere sp;
    const rt::Shape& s = sp;

    std::vector<rt::Intersection> intersections;
    
    rt::Intersection i1(-2.0f, &s);
    rt::Intersection i2(-1.0f, &s);

    intersections.push_back(i2);
    intersections.push_back(i1);

    std::optional<rt::Intersection> i = rt::Intersection::hit(intersections);

    EXPECT_FALSE(i.has_value());
}

TEST(Intersection, hit4){
    rt::Sphere sp;
    const rt::Shape& s = sp;

    std::vector<rt::Intersection> intersections;
    
    rt::Intersection i1(5.0f, &s);
    rt::Intersection i2(7.0f, &s);
    rt::Intersection i3(-3.0f, &s);
    rt::Intersection i4(2.0f, &s);

    intersections.push_back(i1);
    intersections.push_back(i2);
    intersections.push_back(i3);
    intersections.push_back(i4);

    std::optional<rt::Intersection> i = rt::Intersection::hit(intersections);

    EXPECT_TRUE(i.has_value());

    // std::cout << "t: " << i.value().t << std::endl;
    EXPECT_EQ(i.value(), i4);
}

TEST(Intersection, hitVeryClosetoZero){
    rt::Sphere sp;
    const rt::Shape& s = sp;

    std::vector<rt::Intersection> intersections;
    
    rt::Intersection i1(0.00001f, &s);
    rt::Intersection i2(-0.00001f, &s);
    rt::Intersection i3(0.0f, &s);
    rt::Intersection i4(-0.00024f, &s);
    rt::Intersection i5(0.00024f, &s);

    intersections.push_back(i1);
    intersections.push_back(i2);
    intersections.push_back(i3);
    intersections.push_back(i4);
    intersections.push_back(i5);

    std::optional<rt::Intersection> i = rt::Intersection::hit(intersections);

    EXPECT_TRUE(i.has_value());

    // std::cout << "t: " << i.value().t << std::endl;
    EXPECT_EQ(i.value(), i3);
}

TEST(Intersection, scaledSphere){
    rt::Ray r(rt::Point(0, 0, -5), rt::Vec(0, 0, 1));
    rt::Sphere sp;
    rt::Shape& s = sp;
    
    s.setTransform(rt::Matrix::scaling(2, 2, 2));

    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections); 
    // std::cout << "has_value: " << xs.has_value() << std::endl;
    int size = xs.has_value() ? xs.value().size() : 0;

    EXPECT_EQ(size, 2);
    
    if (size == 2){
        EXPECT_NEAR(xs.value()[0].t, 3.0f, EPSILON);
        EXPECT_NEAR(xs.value()[1].t, 7.0f, EPSILON);
    }
}

TEST(Intersection, translatedSphere){
    rt::Ray r(rt::Point(0, 0, -5), rt::Vec(0, 0, 1));
    rt::Sphere sp;
    rt::Shape& s = sp;
    
    s.setTransform(rt::Matrix::translation(5, 0, 0));

    std::vector<rt::Intersection> intersections;
    std::optional<std::vector<rt::Intersection>> xs = s.intersect(r, intersections); 
    // std::cout << "has_value: " << xs.has_value() << std::endl;
    
    EXPECT_FALSE(xs.has_value());

    
}
