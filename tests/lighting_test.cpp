#include <gtest/gtest.h>
#include <cmath>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/color.h"
#include "../src/material.h"
#include "../src/point_light.h"
#include "../src/lighting.h"
    
TEST(Lighting, Lighting1){
    rt::Material m;
    rt::Point position(0, 0, 0);

    rt::Vec eyev(0, 0, -1);
    rt::Vec normalv(0, 0, -1);
    rt::PointLight light(rt::Point(0, 0, -10), rt::Color(1, 1, 1));
    rt::Color result = rt::lighting(m, light, position, eyev, normalv); 
    EXPECT_EQ(result, rt::Color(1.9, 1.9, 1.9));
    
}

TEST(Lighting, Lighting2){
    rt::Material m;
    rt::Point position(0, 0, 0);

    rt::Vec eyev(0.0f, sqrtf(2)/2, -sqrtf(2)/2);
    rt::Vec normalv(0.0f, 0.0f, -1.0f);
    rt::PointLight light(rt::Point(0, 0, -10.0f), rt::Color(1.0f, 1.0f, 1.0f));
    rt::Color result = rt::lighting(m, light, position, eyev, normalv); 
    EXPECT_EQ(result, rt::Color(1.0f, 1.0f, 1.0f));
}

TEST(Lighting, Lighting3){
    rt::Material m;
    rt::Point position(0, 0, 0);

    rt::Vec eyev(0.0f, 0, -1);
    rt::Vec normalv(0.0f, 0.0f, -1.0f);
    rt::PointLight light(rt::Point(0, 10, -10.0f), rt::Color(1.0f, 1.0f, 1.0f));
    rt::Color result = rt::lighting(m, light, position, eyev, normalv); 
    EXPECT_EQ(result, rt::Color(0.7364, 0.7364, 0.7364));
}

TEST(Lighting, Lighting4){
    rt::Material m;
    rt::Point position(0, 0, 0);

    rt::Vec eyev(0.0f, -sqrtf(2)/2, -sqrtf(2)/2);
    rt::Vec normalv(0.0f, 0.0f, -1.0f);
    rt::PointLight light(rt::Point(0, 10, -10.0f), rt::Color(1.0f, 1.0f, 1.0f));
    rt::Color result = rt::lighting(m, light, position, eyev, normalv); 
    std::cout << result.r() << " " << result.g() << " " << result.b() << std::endl;
    EXPECT_EQ(result, rt::Color(1.63639, 1.63639, 1.63639));
}

TEST(Lighting, Lighting5){
    rt::Material m;
    rt::Point position(0, 0, 0);

    rt::Vec eyev(0.0f, 0, -1);
    rt::Vec normalv(0.0f, 0.0f, -1.0f);
    rt::PointLight light(rt::Point(0, 0, 10.0f), rt::Color(1.0f, 1.0f, 1.0f));
    rt::Color result = rt::lighting(m, light, position, eyev, normalv); 
    EXPECT_EQ(result, rt::Color(0.1f, 0.1f, 0.1f));
}
