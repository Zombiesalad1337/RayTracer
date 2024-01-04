#include <cmath>
#include "material.h"

namespace rt{


Material::Material() {};
Material::Material(const Color& color, float ambient, float diffuse, float specular, float shininess) : mColor(color), mAmbient(ambient), mDiffuse(diffuse), mSpecular(specular), mShininess(shininess) {};

Color Material::color() const { return mColor; }
float Material::ambient() const { return mAmbient; }
float Material::diffuse() const { return mDiffuse; }
float Material::specular() const { return mSpecular; }
float Material::shininess() const { return mShininess; }

void Material::setColor(const Color& color) { mColor = color;}
void Material::setAmbient(float ambient) {mAmbient = ambient;}
void Material::setDiffuse(float diffuse) {mDiffuse = diffuse;}
void Material::setSpecular(float specular) {mSpecular = specular;}
void Material::setShininess(float shininess) {mShininess = shininess;}

bool Material::operator==(const Material& mat) const {
    return mat.color() == mColor && fabs(mat.ambient() - mAmbient) < EPSILON
                                 && fabs(mat.diffuse() - mDiffuse) < EPSILON
                                 && fabs(mat.specular() - mSpecular) < EPSILON
                                 && fabs(mat.shininess() - mShininess) < EPSILON;
}

}
