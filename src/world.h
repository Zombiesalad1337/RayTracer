#pragma once
#include "sphere.h"
#include "point_light.h"
#include "intersection.h"
#include <vector>
#include <optional>


namespace rt{

class World{
public:
    World() = default;
    ~World();
    void addShape(Shape* shape);
    void addLight(const PointLight& light);
    std::vector<PointLight> lights();
    std::vector<Shape*> shapes();
    std::optional<std::vector<Intersection>> intersect(const Ray& ray); 

    static World defaultWorld();

private:
    std::vector<PointLight> mLights;
    std::vector<Shape*> mShapes;
};

}
