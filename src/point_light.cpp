#include "point_light.h"

namespace rt{

PointLight::PointLight(const Point& position, const Color& intensity): mPosition(position), mIntensity(intensity) {};

Point PointLight::position() const { return mPosition; }
Color PointLight::intensity() const { return mIntensity; }

}
