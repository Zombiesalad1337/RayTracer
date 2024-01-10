#include "world.h"
#include <algorithm>

namespace rt{

World::~World(){
    //TODO: FIX, CRASHES HERE, SEQFAULT
    // for(auto& shape: mShapes){
    //     delete shape;
    // }
    // mShapes.clear();
}

void World::addShape(Shape* shape){
    mShapes.push_back(shape);
}

void World::addLight(const PointLight& light){
    mLights.push_back(light);
}

std::vector<PointLight> World::lights() const{
    return mLights;
}
std::vector<Shape*> World::shapes() const{
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

std::optional<std::vector<Intersection>> World::intersect(const Ray& ray) const{
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

Color World::shadeHit(const Computation&  comp) const{
    Color finalColor;
    //TODO: handle shadows in this case
    //TODO: rethink for multiple light sources. Count number of shadows then divide ambient by it?
    for (const PointLight& light : mLights){
        bool isShadow = isShadowed(light, comp.overPoint);
        finalColor = finalColor +  lighting(comp.shape->material(), light, comp.overPoint, comp.eyev, comp.normalv, isShadow);
    }
    return finalColor;
}

Color World::colorAt(const Ray& ray) const{
    std::optional<std::vector<Intersection>> intersections = intersect(ray);
    if (intersections.has_value()){
        std::optional<Intersection> hit = Intersection::hit(intersections.value(), true);
        if (hit.has_value()){
            Computation comp(hit.value(), ray);
            return shadeHit(comp);
        }
    } 
    //no hit, return black
    return Color();
}

Canvas World::render(const Camera& camera){
    Canvas image(camera.hsize(), camera.vsize());

    for (int y = 0; y < camera.vsize(); ++y){
        for (int x = 0; x < camera.hsize(); ++x){
            Ray ray = camera.rayForPixel(x, y);
            Color color = colorAt(ray);
            image.setPixel(x, y, color);
        }
    }
    return image;
}

bool World::isShadowed(const PointLight& light, const Point& point) const{
    Vec shadowVector = Vec(light.position() - point);
    float distance = shadowVector.magnitude();
    Vec direction = shadowVector.norm();

    Ray shadowRay(point, direction);
    std::optional<std::vector<Intersection>> intersections = intersect(shadowRay);

    if (intersections.has_value()){
        std::optional<Intersection> hit = Intersection::hit(intersections.value(), true);
        if (hit.has_value() && hit.value().t < distance){
            // std::cout << "Shadow true" << std::endl;
            return true;
        }
    }
    return false;
}

}

