#pragma once
#include "color.h"

namespace rt{
class Material{
public:
    Material();
    Material(const Color& color, float ambient, float diffuse, float specular, float shininess);
    Color color() const;
    float ambient() const;
    float diffuse() const;
    float specular() const;
    float shininess() const;

    void setColor(const Color& color);
    void setAmbient(float ambient);
    void setDiffuse(float diffuse);
    void setSpecular(float specular);
    void setShininess(float shininess);
    
    bool operator==(const Material& mat) const;

private:
    Color mColor = Color(1, 1, 1);
    float mAmbient = 0.1f;
    float mDiffuse = 0.9f;
    float mSpecular = 0.9f;
    float mShininess = 200.0f;
};

}
