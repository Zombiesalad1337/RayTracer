#include <iostream>
#include "tuple.h"
#include "point.h"
#include "vec.h"


int main(){
    std::cout << "Initial setup" << std::endl;
    rt::Vec v1(1,1,1);
    rt::Vec v2(2,2,2);
    rt::Point p1(1,1,1);
    rt::Vec v3 = v1 + v2;
    rt::Point p2 = v2 + p1;
    return 0;
}


