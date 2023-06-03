#pragma once
#include <vector>
#include <string>
#include "color.h"


namespace rt{

class Canvas{
public:
   int width;
   int height;
   Canvas(int width, int height);

   Color getPixel(int x, int y) const;
   void setPixel(int x, int y, const Color& c);
   void writePPM(const std::string& filename) const;
   void writePNG(const std::string& filename) const;
private:
   std::vector<std::vector<Color>> canvas;
   std::vector<int> scaleColor(const Color& c) const;
};

} //namespace rt
