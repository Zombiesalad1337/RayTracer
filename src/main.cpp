#include <iostream>
#include "tuple.h"
#include "point.h"
#include "vec.h"
#include "matrix.h"
#include "canvas.h"
#include <cmath>


int main(){
    const int kWidth = 1920;
    const int kHeight = 1080;
    rt::Canvas canvas(kWidth, kHeight);    
    rt::Color white(1, 1, 1);
    rt::Point baseRef(300, 0, 0);
    
    rt::Matrix bringToCenterOfCanvas = rt::Matrix::translation(kWidth / 2, kHeight / 2, 0);
    rt::Point threeOClock = bringToCenterOfCanvas * baseRef;
    canvas.setPixel(threeOClock.x, threeOClock.y, white);
    for (int i = 1; i < 12; ++i){
        rt::Point hand = bringToCenterOfCanvas * rt::Matrix::rotationZ((i * M_PI) / 6) * baseRef;
        std::cout << "i: " << i << std::endl;
        hand.print();
        canvas.setPixel(hand.x, hand.y, white);
    }
    canvas.writePNG("clockHands");

    return 0;
}


