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


TEST(PointLight, initialize){
    rt::Point position(0, 0, 0);
    rt::Color intensity(1, 1, 1);
    rt::PointLight light(position, intensity);
    EXPECT_EQ(light.position(), position);
    EXPECT_EQ(light.intensity(), intensity);
}
