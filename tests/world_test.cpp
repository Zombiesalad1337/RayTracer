#include <gtest/gtest.h>
#include <cmath>
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/color.h"
#include "../src/material.h"
#include "../src/point_light.h"
#include "../src/lighting.h"
#include "../src/world.h"
#include "../src/computation.h"
    
TEST(World, WorldEmpty){
    rt::World w;
    
    EXPECT_EQ(w.shapes().size(), 0);
    EXPECT_EQ(w.lights().size(), 0);
}

TEST(World, defaultWorld){

    rt::Material s1mat;
    s1mat.setColor(rt::Color(0.8f, 1.0f, 0.6f));
    s1mat.setDiffuse(0.7f);
    s1mat.setSpecular(0.2f);

    rt::World defaultWorld = rt::World::defaultWorld();

    EXPECT_EQ(defaultWorld.shapes().size(), 2);
    EXPECT_EQ(defaultWorld.lights().size(), 1);
    EXPECT_EQ(defaultWorld.shapes()[0]->material(), s1mat);
}

TEST(World, intersect){
    rt::World w = rt::World::defaultWorld();
    rt::Ray r(rt::Point(0, 0, -5), rt::Vec(0, 0, 1));
    
    std::optional<std::vector<rt::Intersection>> xs = w.intersect(r);

    EXPECT_TRUE(xs.has_value());
    EXPECT_NEAR(xs.value()[0].t, 4, EPSILON);
    EXPECT_NEAR(xs.value()[1].t, 4.5, EPSILON);
    EXPECT_NEAR(xs.value()[2].t, 5.5, EPSILON);
    EXPECT_NEAR(xs.value()[3].t, 6, EPSILON);
}

TEST(World, shadeHit){
    rt::World w = rt::World::defaultWorld();
    rt::Ray r(rt::Point(0, 0, -5), rt::Vec(0, 0, 1));
    
    const rt::Shape* shape = w.shapes()[0];
    rt::Intersection i(4, shape);
    rt::Computation comp(i, r);
    rt::Color shadeHit = w.shadeHit(comp);
    EXPECT_EQ(shadeHit, rt::Color(0.38066, 0.47583, 0.2855));
}

TEST(World, colorAtNoHit){
    rt::World w = rt::World::defaultWorld();
    rt::Ray r(rt::Point(0, 0, -5), rt::Vec(0, 1, 0));
    rt::Color c = w.colorAt(r);
    EXPECT_EQ(c, rt::Color(0, 0, 0));
    
}

TEST(World, colorAtOuterSphere){
    rt::World w = rt::World::defaultWorld();
    rt::Ray r(rt::Point(0, 0, -5), rt::Vec(0, 0, 1));
    rt::Color c = w.colorAt(r);
    EXPECT_EQ(c, rt::Color(0.38066, 0.47583, 0.2855));
}

TEST(World, colorAtInnerSphere){
    rt::World w = rt::World::defaultWorld();
    rt::Shape* outer = w.shapes()[0];
    rt::Shape* inner = w.shapes()[1];
    outer->material().setAmbient(1);
    inner->material().setAmbient(1);
    rt::Material newMat = outer->material();
    newMat.setAmbient(1);
    //TODO: unable to setAmbient, doesn't update, due to const?
    // std::cout << w.shapes()[1]->material().ambient() << std::endl;
    // w.shapes()[1]->material().setAmbient(1);
    // std::cout << w.shapes()[1]->material().ambient() << std::endl;
    // std::cout << newMat.ambient() << std::endl;
    outer->setMaterial(newMat);
    inner->setMaterial(newMat);
    // std::cout << w.shapes()[1]->material().ambient() << std::endl;
    rt::Ray r(rt::Point(0, 0, 0.75), rt::Vec(0, 0, -1));
    rt::Color c = w.colorAt(r);
    EXPECT_EQ(c, inner->material().color());
}
