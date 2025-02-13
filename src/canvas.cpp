#include <iostream>
#include <filesystem>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include "canvas.h"


namespace rt{

Canvas::Canvas(int width, int height) : width(width), height(height), canvas(width, std::vector<Color>(height, Color(0, 0, 0))) {}

Color Canvas::getPixel(int x, int y) const{
    //TODO: Do I need to handle such exception?
    //Not handling it atm since it would help discover underlying bugs
    //Future self: You shouldn't. Here accuracy matters more than uptime.
    //can lead to unauthorized access of memory
    // if (x >= width || y >= height){
    //     throw std::out_of_range("Canvas getPixel: indices out of range: width = " + std::to_string(width) + ", height = " + std::to_string(height) + ", x = " + std::to_string(x) + ", y = " + std::to_string(y));
    // }
    //changing to assertions instead following NASA's guidelines
    assert(x < width);
    assert(y < height);
    return canvas[x][y];
}

void Canvas::setPixel(int x, int y, const Color& c){
    // if (x >= width || y >= height){
    //     throw std::out_of_range("Canvas setPixel: indices out of range: width = " + std::to_string(width) + ", height = " + std::to_string(height) + ", x = " + std::to_string(x) + ", y = " + std::to_string(y));
    // }
    assert(x < width);
    assert(y < height);
    canvas[x][y] = c;
}

//colors represented as vectors, usually range from 0 to 1, but can exceed the limits (very dark, very high intensity)
//convert to screen space colors
std::vector<int> Canvas::scaleColor(const Color& c) const{
    int r_scaled = std::ceil(c.r() * 255);
    int g_scaled = std::ceil(c.g() * 255);
    int b_scaled = std::ceil(c.b() * 255);
    
    int r_clamped = r_scaled < 0 ? 0 : (r_scaled > 255 ? 255 : r_scaled);
    int g_clamped = g_scaled < 0 ? 0 : (g_scaled > 255 ? 255 : g_scaled);
    int b_clamped = b_scaled < 0 ? 0 : (b_scaled > 255 ? 255 : b_scaled);

    return {r_clamped, g_clamped, b_clamped};
}

void Canvas::writePPM(const std::string& filename) const{
    std::filesystem::path cwd = std::filesystem::current_path();
    std::cout << cwd.string() << std::endl;
    std::string header = "P6 " + std::to_string(this->width) + ' ' + std::to_string(this->height) + std::string(" 255 ");

    try {
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
                    //i ranges from 0-255, convert to binary byte
                    out.write(reinterpret_cast<const char*>(&i), sizeof(char));   
                } 
            }
        }
        //no need to close, ofstream's destructor will close the file when it goes out of scope - RAII 
        // out.close();
    }
    catch (const std::filesystem::filesystem_error& err){
        std::cerr << "filesystem error: " <<  err.what() << std::endl;
        //no need to close, ofstream's destructor will close the file when it goes out of scope - RAII 
    }
}

void Canvas::writePNG(const std::string& filename) const{
    this->writePPM(filename);
    std::string command = "/usr/bin/bash -c 'convert " + filename + ".ppm " + filename + ".png'";
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

int Canvas::getWidth() const{
    return width;
}

int Canvas::getHeight() const{
    return height;
}

}//namespace rt
