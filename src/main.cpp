#include <iostream>
#include <string>
#include <cmath>
#include "world.h"

using namespace rt;

int main(){
    Material matFloor;
    matFloor.setColor(Color(1, 0.9, 0.9));
    matFloor.setSpecular(0);

    Material matSphere1;
    matSphere1.setColor(Color(0.1, 1, 0.5));
    matSphere1.setSpecular(0.3);
    matSphere1.setDiffuse(0.7);

    Material matSphere2;
    matSphere2.setColor(Color(0.5, 1, 0.1));
    matSphere2.setSpecular(0.3);
    matSphere2.setDiffuse(0.7);

    Material matSphere3;
    matSphere3.setColor(Color(1, 0.8, 0.1));
    matSphere3.setSpecular(0.3);
    matSphere3.setDiffuse(0.7);

    Sphere floorSP;
    Sphere leftWallSP;
    Sphere rightWallSP;
    Sphere sphere1SP;
    Sphere sphere2SP;
    Sphere sphere3SP;

    Shape& floor = floorSP;
    Shape& leftWall = leftWallSP;
    Shape& rightWall = rightWallSP;
    Shape& sphere1 = sphere1SP;
    Shape& sphere2 = sphere2SP;
    Shape& sphere3 = sphere3SP;
    
    floor.setMaterial(matFloor);
    leftWall.setMaterial(matFloor);
    rightWall.setMaterial(matFloor);
    sphere1.setMaterial(matSphere1);
    sphere2.setMaterial(matSphere2);
    sphere3.setMaterial(matSphere3);

    floor.setTransform(Matrix::scaling(10, 0.01, 10));
    leftWall.setTransform(Matrix::translation(0, 0, 5) * Matrix::rotationY(-M_PI / 4) * Matrix::rotationX(M_PI / 2) * Matrix::scaling(10, 0.01, 10));
    rightWall.setTransform(Matrix::translation(0, 0, 5) * Matrix::rotationY(M_PI / 4) * Matrix::rotationX(M_PI / 2) * Matrix::scaling(10, 0.01, 10));

    sphere1.setTransform(Matrix::translation(-0.5, 1, 0.5));
    sphere2.setTransform(Matrix::translation(1.5, 0.5, -0.5) * Matrix::scaling(0.5, 0.5, 0.5));
    sphere3.setTransform(Matrix::translation(-1.5, 0.33, -0.75) * Matrix::scaling(0.33, 0.33, 0.33));
    int count = 0;
    for (int left = -20; left <= 20; left += 2){
        std::cout << left << std::endl;
        World w;
        w.addShape(&floor);
        w.addShape(&leftWall);
        w.addShape(&rightWall);
        w.addShape(&sphere1);
        w.addShape(&sphere2);
        w.addShape(&sphere3);

        w.addLight(PointLight(Point(left, 10, -10), Color(1, 1, 1)));

        Camera c(640, 480, M_PI / 3);
        c.setTransform(Matrix::viewTransform(Point(0, 1.5, -5), Point(0, 1, 0), Vec(0, 1, 0)));
        Canvas image = w.render(c);

        image.writePPM("worldRenderTwo" + std::to_string(++count));
    }

    return 0;
}


