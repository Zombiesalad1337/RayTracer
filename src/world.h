#pragma once
//TODO: remove sphere.h from here, move to .cpp
#include "sphere.h"
#include "point_light.h"
#include "intersection.h"
#include "computation.h"
#include "lighting.h"
#include "camera.h"
#include "canvas.h"
#include <vector>
#include <optional>


namespace rt{

class World{
public:
    World() = default;
    ~World();
    void addShape(Shape* shape);
    void addLight(const PointLight& light);
    std::vector<PointLight> lights() const;
    std::vector<Shape*> shapes() const;
    std::optional<std::vector<Intersection>> intersect(const Ray& ray) const; 
    Color shadeHit(const Computation&  comp) const;
    Color colorAt(const Ray& ray) const;
    Canvas render(const Camera& camera);
    bool isShadowed(const PointLight& light, const Point& point) const;


    static World defaultWorld();

private:
    std::vector<PointLight> mLights;
    std::vector<Shape*> mShapes;
};

}
