#include "world.h"
#include <algorithm>

namespace rt{

World::~World(){
    for(auto& shape: mShapes){
        delete shape;
    }
    mShapes.clear();
}

void World::addShape(Shape* shape){
    mShapes.push_back(shape);
}

void World::addLight(const PointLight& light){
    mLights.push_back(light);
}

std::vector<PointLight> World::lights(){
    return mLights;
}
std::vector<Shape*> World::shapes(){
    return mShapes;
}

World World::defaultWorld(){
    World w;
    PointLight light(Point(-10, 10, -10), Color(1, 1, 1));
    Sphere* s1 = new Sphere();
    Material s1mat;
    s1mat.setColor(Color(0.8f, 1.0f, 0.6f));
    s1mat.setDiffuse(0.7f);
    s1mat.setSpecular(0.2f);
    s1->setMaterial(s1mat);

    Sphere* s2 = new Sphere();
    s2->setTransform(rt::Matrix::scaling(0.5, 0.5, 0.5));

    w.addShape(s1);
    w.addShape(s2);
    w.addLight(light);
    
    return w;
}

std::optional<std::vector<Intersection>> World::intersect(const Ray& ray){
    std::vector<Intersection> intersections;
    for (Shape* shape : mShapes){
        Intersection::intersect(*shape, ray, intersections);
    }
    if (intersections.size()){
        std::sort(intersections.begin(), intersections.end(), [](const Intersection& a, const Intersection& b){
            return a.t < b.t;
        });
        return intersections;
    }
    return std::nullopt;
} 

}

