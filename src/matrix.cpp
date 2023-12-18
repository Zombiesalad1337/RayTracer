#include <iostream>
#include "matrix.h"


namespace rt{

Matrix::Matrix(int size){
    this->size = size;
    data = new float*[size];    
    for (int i = 0; i < size; ++i){
        data[i] = new float[size];
    }
}
Matrix::Matrix(const std::vector<std::vector<float>>& vec){
    size = vec.size();
    if (vec.size() != vec[0].size()){
        //TODO: THROW EXCEPTION instead of returning 0
        std::cerr << "Vec is not square" << std::endl; 
        return;
    }
    data = new float*[vec.size()];
    for (int i = 0; i < vec.size(); ++i){
        data[i] = new float[vec.size()];
        for (int j = 0; j < vec.size(); ++j){
            data[i][j] = vec[i][j];
        }
    }
}

Matrix::~Matrix(){
    for (int i = 0; i < size; ++i){
        delete[] data[i];
    }
    delete[] data;
}
float Matrix::get(int x, int y){
    if (x >= size || y >= size || x < 0 || y < 0){
        std::cerr << "Index out of bounds: " << x << " " << y << std::endl;
        //TODO: THROW EXCEPTION instead of returning 0
        return 0;
    }
    return data[x][y];
}

void Matrix::set(int x, int y, float z){
    if (x >= size || y >= size || x < 0 || y < 0){
        std::cerr << "Index out of bounds: " << x << " " << y << std::endl;
        //TODO: THROW EXCEPTION instead of returning 0
        return ;
    }
    data[x][y] = z;
}

bool Matrix::operator==(const Matrix& mat) const{
    if (size != mat.size){
        return false;
    }
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            if (abs(data[i][j] - mat.data[i][j]) > EPSILON){
                return false;
            }
        }
    }
    return true;
}



}//namespace rt
