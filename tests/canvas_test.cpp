#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include "../src/canvas.h"
#include "../src/tuple.h"
#include "../src/point.h"
#include "../src/vec.h"
#include "../src/color.h"

TEST(Canvas, create){
    rt::Canvas c(10, 20);
    EXPECT_EQ(c.getWidth(), 10);
    EXPECT_EQ(c.getHeight(), 20);
    rt::Color black;
    for (int i = 0; i < c.getWidth(); ++i){
        for (int j = 0; j < c.getHeight(); ++j){
            EXPECT_EQ(c.getPixel(i, j), black);
        }
    }
}

TEST(Canvas, write){
    rt::Canvas c(10, 20);
    rt::Color red(1, 0 ,0);
    c.setPixel(2, 3, red);
    EXPECT_EQ(c.getPixel(2, 3), red);
}


TEST(Canvas, writePPM){
    rt::Canvas c(1000,1000);
    for (int i = 0; i < c.getWidth(); ++i){
        for (int j = 0; j < c.getHeight(); ++j){
            rt::Color col(((float)i+j) * 0.3/ (c.getWidth()+c.getHeight()-2), ((float)i+j) * 0.5 / (c.getWidth()+c.getHeight()-2), ((float)i+j) * 0.7 / (c.getWidth()+c.getHeight()-2));
            c.setPixel(i, j, col);
        }
    }
    c.writePPM("testppm");
}

TEST(Canvas, writePNG){
    rt::Canvas c(1000,1000);
    for (int i = 0; i < c.getWidth(); ++i){
        for (int j = 0; j < c.getHeight(); ++j){
            rt::Color col(((float)i+j) * 0.7 / (c.getWidth()+c.getHeight()-2), ((float)i+j) * 0.3 / (c.getWidth()+c.getHeight()-2), ((float)i+j) * 0.4 / (c.getWidth()+c.getHeight()-2));
            c.setPixel(i, j, col);
        }
    }
    c.writePNG("testpng");
}
