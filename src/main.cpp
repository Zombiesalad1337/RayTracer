#include <iostream>
#include "tuple.h"
#include "point.h"
#include "vec.h"
#include "matrix.h"


int main(){
    std::cout << "Initial setup" << std::endl;
    std::vector<std::vector<float>> originalMatrix = {
        {2, 1, 4},
        {1, 3, 5},
        {6, 2, 1}
    };
    std::vector<std::vector<float>> inverseMatrix = {
        {-1.5, 1, -2.5},
        {0.5, 0, 0.5},
        {1, -2, 1}
    };

    rt::Matrix og(originalMatrix);
    rt::Matrix inv(inverseMatrix);
    std::cout <<"here2" << std::endl;
    og.print();
    inv.print();
    std::cout <<"here2" << std::endl;
    rt::Matrix m = og.inverse();
    return 0;
}


