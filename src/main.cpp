#include "plane.h"
#include "world.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace rt;

int main() {

    Material matFloor;
    matFloor.setSpecular(0);

    Material matSphere1;
    matSphere1.setSpecular(0.3);
    matSphere1.setDiffuse(0.7);

    Material matSphere2;
    matSphere2.setSpecular(0.3);
    matSphere2.setDiffuse(0.7);

    Material matSphere3;
    matSphere3.setSpecular(0.3);
    matSphere3.setDiffuse(0.7);

    matFloor.setColor(Color(0.72, 0.52, 0.39));
    matSphere1.setColor(Color(1.0, 0.82, 0.25));
    matSphere2.setColor(Color(0.55, 0.60, 0.25));
    matSphere3.setColor(Color(0.35, 0.70, 1.00));


    Plane floor;
    Sphere sphere1SP;
    Sphere sphere2SP;
    Sphere sphere3SP;

    Shape &sphere1 = sphere1SP;
    Shape &sphere2 = sphere2SP;
    Shape &sphere3 = sphere3SP;

    floor.setMaterial(matFloor);
    sphere1.setMaterial(matSphere1);
    sphere2.setMaterial(matSphere2);
    sphere3.setMaterial(matSphere3);

    sphere1.setTransform(Matrix::translation(-0.5, 1, 0.5));
    sphere2.setTransform(Matrix::translation(1.5, 0.5, -0.5) *
                        Matrix::scaling(0.5, 0.5, 0.5));
    sphere3.setTransform(Matrix::translation(-1.5, 0.33, -0.75) *
                        Matrix::scaling(0.33, 0.33, 0.33));
    int count = 0;
    for (int i = 0; i < 40; i++) {
      double t = (2.0 * M_PI) * (double(i) / 40.0);
      double x = 10.0 * std::cos(t);
      double z = 10.0 * std::sin(t);

      World w;
      w.addShape(&floor);
      w.addShape(&sphere1);
      w.addShape(&sphere2);
      w.addShape(&sphere3);

      w.addLight(PointLight(Point(x, 10, z), Color(1, 1, 1)));

      Camera c(1280, 720, M_PI / 3);
      c.setTransform(
          Matrix::viewTransform(Point(0, 1.5, -5), Point(0, 1, 0), Vec(0, 1, 0)));
      Canvas image = w.render(c);

      image.writePPM("render" + std::to_string(++count));
      std::cout << count << std::endl;
}


    return 0;
}
