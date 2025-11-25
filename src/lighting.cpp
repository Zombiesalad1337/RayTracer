#include "lighting.h"
#include <cmath>

namespace rt{

Color lighting(const Material& material, const PointLight& light, Point point, Vec eyev, Vec normalv, bool inShadow){
    Color ca(1, 1, 1);
    Color cb(144.0f / 255, 238.0f / 255, 144.0f / 255);
    Color matColor = ((int)(floorf(point.x) + floorf(point.y) + floorf(point.z))) % 2 ? ca : cb;
    Color effectiveColor = matColor * light.intensity();
    //checkboard pattern originates from here. Do a proper implementation.
    Vec lightv = Vec(light.position() - point).norm();
    
    Color ambient = effectiveColor * material.ambient();
    if (inShadow)
        return ambient;
    Color specular, diffuse;

    float lightDotNormal = Vec::dot(lightv, normalv);

    if (lightDotNormal >= 0){
        diffuse = effectiveColor * material.diffuse() * lightDotNormal;
        Vec reflectv = Vec(-lightv).reflect(normalv);
        float reflectDotEye = Vec::dot(reflectv, eyev);

        if (reflectDotEye > 0){
            float factor = powf(reflectDotEye, material.shininess());
            specular = light.intensity() * material.specular() * factor;
        }
    }
    return ambient + diffuse + specular;
}

}
