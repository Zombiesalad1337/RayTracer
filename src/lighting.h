#pragma once
#include "color.h"
#include "point_light.h"
#include "material.h"
#include "vec.h"
#include "point.h"

namespace rt{

Color lighting(const Material& material, const PointLight& light, Point point, Vec eyev, Vec normalv);

}
