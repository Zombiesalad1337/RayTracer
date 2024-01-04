#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "tuple.h"
#include "point.h"
#include "vec.h"
#include "matrix.h"
#include "sphere.h"
#include "intersection.h"
#include "canvas.h"
#include "material.h"
#include "point_light.h"
#include "lighting.h"


int main(){
    const int kWidth = 1080;
    const int kHeight = kWidth;
    const rt::Color hitColor(0, 1, 1);

    const float kWallSize = 8.0f;

    const float kWallZ = 10.0f;

    float pixelSize = kWallSize / kWidth;

    float half = kWallSize / 2.0f;
    
    rt::Point origin(0.0f, 0.0f, -10.0f);


    rt::Sphere sphere;
    rt::Shape& shape = sphere;
    rt::Material m;
    m.setColor(rt::Color(1, 0.2, 1));
    shape.setMaterial(m);

    // std::vector<rt::Matrix> transformations = {rt::Matrix::translation(5, 5, 5), rt::Matrix::scaling(2, 2, 2), rt::Matrix::scaling(2, 4, 2), rt::Matrix::shearing(3, 1, 0, 0, 0, 0)};
    // std::vector<std::string> names = {" translate555", " scale222", " scale242", " shear 3100000"};


    rt::Canvas canvas(kWidth, kHeight);
    // std::cout << "Processing " << names[i] << std::endl;
    // shape.setTransform(transformations[i]);
    int steps = 10;
    int count = 0;
    for (int i = -200; i <= 200; i += steps){
        rt::PointLight light(rt::Point(i, -i, -10), rt::Color(1, 1, 1));
        std::cout << count << std::endl;
        for (int y = 0; y < kHeight; ++y){
            
            float worldY = half - pixelSize * y;
             
            for (int x = 0; x < kWidth; ++x){

                float worldX = -half + pixelSize * x;
                rt::Point pointOnWall(worldX, worldY, kWallZ);
                rt::Vec directionToWall = pointOnWall - origin; 

                rt::Ray rayToPointOnWall(origin, directionToWall.norm());
                
                std::vector<rt::Intersection> intersections;

                std::optional<std::vector<rt::Intersection>> intersection = rt::Intersection::intersect(shape, rayToPointOnWall, intersections);
                
                std::optional<rt::Intersection> hit = rt::Intersection::hit(intersections);

                if (hit.has_value()){
                    rt::Point point = rayToPointOnWall.position(hit.value().t);
                    rt::Vec normal = hit.value().object->normalAt(point);
                    rt::Vec eye = -rayToPointOnWall.direction();
                    rt::Color color = rt::lighting(hit.value().object->material(), light, point, eye, normal);
                    canvas.setPixel(x, y, color);
                }

            }
        }
        canvas.writePPM("sphereHit" + std::to_string(++count));
    }
    return 0;
}


