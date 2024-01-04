#include <gtest/gtest.h>
#include <cmath>
#include <optional>
#include <vector>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/sphere.h"
#include "../src/intersection.h"
#include "../src/point_light.h"
#include "../src/color.h"
#include "../src/material.h"


TEST(Material, initialize){
    rt::Material m;
    EXPECT_EQ(m.color(), rt::Color(1, 1, 1));
    EXPECT_NEAR(m.ambient(), 0.1f, EPSILON);
    EXPECT_NEAR(m.diffuse(), 0.9f, EPSILON);
    EXPECT_NEAR(m.specular(), 0.9f, EPSILON);
    EXPECT_NEAR(m.shininess(), 200.0f, EPSILON);
}
