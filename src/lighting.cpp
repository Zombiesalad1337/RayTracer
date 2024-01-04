#include "lighting.h"
#include <cmath>

namespace rt{

Color lighting(const Material& material, const PointLight& light, Point point, Vec eyev, Vec normalv){
    Color effectiveColor = material.color() * light.intensity();
    Vec lightv = Vec(light.position() - point).norm();
    
    Color ambient = effectiveColor * material.ambient();
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
