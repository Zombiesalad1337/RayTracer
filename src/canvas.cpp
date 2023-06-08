#include <iostream>
#include <filesystem>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "canvas.h"


namespace rt{

Canvas::Canvas(int width, int height) : width(width), height(height), canvas(width){
    rt::Color black;
    for (int i = 0; i < width; ++i){
        canvas[i].reserve(height);
        //for(int j = 0; j < height; ++j){
            //canvas[i][j] = black;
        //}
    }
}

Color Canvas::getPixel(int x, int y) const{
    return canvas[x][y];
}

void Canvas::setPixel(int x, int y, const Color& c){
    canvas[x][y] = c;
}


std::vector<int> Canvas::scaleColor(const Color& c) const{
    int r_scaled = std::ceil(c.r()*255);
    int g_scaled = std::ceil(c.g()*255);
    int b_scaled = std::ceil(c.b()*255);
    
    int r_clamped = r_scaled < 0 ? 0 : (r_scaled > 255 ? 255 : r_scaled);
    int g_clamped = g_scaled < 0 ? 0 : (g_scaled > 255 ? 255 : g_scaled);
    int b_clamped = b_scaled < 0 ? 0 : (b_scaled > 255 ? 255 : b_scaled);

    return {r_clamped, g_clamped, b_clamped};
}

void Canvas::writePPM(const std::string& filename) const{
    std::filesystem::path cwd = std::filesystem::current_path();
    std::cout << cwd.string() << std::endl;
    std::string header = "P6 " + std::to_string(this->width) + ' ' + std::to_string(this->height) + std::string(" 255 ");

    std::ofstream out;
    out.open(filename + ".ppm", std::ios::out | std::ios::binary);
    out.write(header.c_str(), header.length());
    
    //70 chars/line limit? why the fuck would char limit matter in a binary file
    //SCANLINES WRITTEN IN ROW FIRST ORDER
    for (int j = 0; j < this->height; ++j){
        for (int i = 0; i < this->width; ++i){
            const rt::Color& c = this->canvas[i][j]; 
            std::vector<int> colors = this->scaleColor(c);
            for (int i : colors){
                out.write(reinterpret_cast<const char*>(&i), sizeof(char));   
            } 
        }
    }
    out.close();
}

void Canvas::writePNG(const std::string& filename) const{
    this->writePPM(filename);
    std::string command = "/usr/bin/bash -c 'convert " + filename + ".ppm " + filename + ".png'";
    const char* pwd = "pwd";
    std::cout << command << std::endl;
    int convertResult = std::system(command.c_str());
    if (convertResult != 0){
        std::cerr << "Failed to convert temporary ppm image." << std::endl;
    }
    try {
        if (!std::filesystem::remove(filename + ".ppm")){
            std::cerr << "Failed to delete temporary ppm file." << std::endl;
        }
    }
    catch (const std::filesystem::filesystem_error& err){
        std::cerr << "filesystem error: " <<  err.what() << std::endl;
    }
}

}//namespace rt
