#include <iostream>
#include <vector>
#include "projectile.h"
#include "canvas.h"

int main(){
    //TODO: Add range checks to canvas write and read
    int width, height;
    rt::Color traceColor(0, 1, 1);
    width = 1920;
    height = 1080;
    Projectile p = Projectile(rt::Point(0,0,0), rt::Vec(30, 30, 0));
    Environment e = Environment(rt::Vec(0, -20, 0), rt::Vec(10, 0, 0));
    rt::Canvas canvas(width, height);

    std::vector<std::pair<float, float>> positions;
    float tick_interval = 0.001;
    float time = 0;
    while (p.position.y >= 0 && p.position.y < height){
        //std::cout << "x: " << p.position.x << ", y: " << p.position.y << ", time: " << time << std::endl;
        positions.emplace_back(std::make_pair(p.position.x, p.position.y));
        p = tick(p, e, tick_interval);
        time += tick_interval;
    }

    for (int i = 0; i < positions.size(); ++i){
        std::cout << "x: " << positions[i].first << ", y: " << positions[i].second << std::endl;
        int scaled_x = (int)(positions[i].first * 8);
        int scaled_y = (int)(positions[i].second * 8);
        std::cout << "Scaled_x : " << scaled_x << ", scaled_y: " << scaled_y << std::endl;
        //last check so it doesn't write to canvas[][width]
        //TODO: RANGE CHECK WITHIN CANVAS
        if (scaled_x < width && scaled_y < height && scaled_y > 0){
            std::cout << height - scaled_y<< std::endl;
            canvas.setPixel(scaled_x, height - scaled_y, traceColor);
        }
    }
    std::cout << "Writing to image" << std::endl;
    canvas.writePPM("projectile");
    return 0;
}


