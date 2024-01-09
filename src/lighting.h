#pragma once
#include "point_light.h"
#include "material.h"

namespace rt{

Color lighting(const Material& material, const PointLight& light, Point point, Vec eyev, Vec normalv, bool inShadow);

}
