#pragma once
#include <vector>
#include <string>
#include "color.h"


namespace rt{

class Canvas{
public:
   Canvas(int width, int height);

   Color getPixel(int x, int y) const;
   void setPixel(int x, int y, const Color& c);
   void writePPM(const std::string& filename) const;
   void writePNG(const std::string& filename) const;

   int getWidth() const;
   int getHeight() const;
private:
   std::vector<std::vector<Color>> canvas;
   std::vector<int> scaleColor(const Color& c) const;
   int width;
   int height;
};

} //namespace rt
