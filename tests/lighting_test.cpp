#include <gtest/gtest.h>
#include <cmath>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/color.h"
#include "../src/material.h"
#include "../src/point_light.h"
    
TEST(Lighting, Lighting1){
    rt::Material m;
    rt::Point position(0, 0, 0);

    rt::Vec eyev(0, 0, -1);
    rt::Vec normalv(0, 0, -1);
    rt::PointLight light(rt::Point(0, 0, -10), rt::Color(1, 1, 1));
    
}
