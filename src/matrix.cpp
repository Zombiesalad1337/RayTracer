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

//TODO: only handling for 4x4 now
//throw error if less than 4
Matrix Matrix::operator*(const Matrix& mat) const{
    Matrix m(this->size);
    for (int i = 0; i < this->size; ++i){
        for (int j = 0; j < this->size; ++j){
            m.data[i][j] = this->data[i][0] * mat.data[0][j] +  
                           this->data[i][1] * mat.data[1][j] +  
                           this->data[i][2] * mat.data[2][j] +  
                           this->data[i][3] * mat.data[3][j];
        }
    }
    return m;
}

Tuple Matrix::operator*(const Tuple& tup) const{
    float res[4];
    for (int i = 0; i < this->size; ++i){
        res[i] = this->data[i][0] * tup.x +  
                       this->data[i][1] * tup.y + 
                       this->data[i][2] * tup.z +  
                       this->data[i][3] * tup.w;
    }
    return Tuple(res[0], res[1], res[2], res[3]);
}
Matrix Matrix::transpose() const{
    Matrix m(this->size);
    for (int j = 0; j < this->size; ++j){
        for (int i = 0; i < this->size; ++i){
            m.data[j][i] = this->data[i][j];
        }
    }
    return m;
}

float Matrix::cofactor(int row, int col) const{
    float c = 0.0f;
    int matNum = 0;
    switch (this->size) {
        case 3:
            matNum = row * 3 + col; 
            switch (matNum){
                case 0:
                    c = this->data[1][1] * this->data[2][2] - this->data[1][2] * this->data[2][1]; 
                    break;
                case 1:
                    c = this->data[1][0] * this->data[2][2] - this->data[2][0] * this->data[1][2]; 
                    c = -c;
                    break;
                case 2:
                    c = this->data[1][0] * this->data[2][1] - this->data[2][0] * this->data[1][1]; 
                    break;
                case 3:
                    c = this->data[0][1] * this->data[2][2] - this->data[2][1] * this->data[0][2]; 
                    c = -c;
                    break;
                case 4:
                    c = this->data[0][0] * this->data[2][0] - this->data[1][2] * this->data[0][2]; 
                    break;
                case 5:
                    c = this->data[0][0] * this->data[2][1] - this->data[2][0] * this->data[0][1]; 
                    c = -c;
                    break;
                case 6:
                    c = this->data[0][1] * this->data[1][2] - this->data[1][1] * this->data[0][2]; 
                    break;
                case 7:
                    c = this->data[0][0] * this->data[1][2] - this->data[1][0] * this->data[0][2]; 
                    c = -c;
                    break;
                case 8:
                    c = this->data[0][0] * this->data[1][1] - this->data[1][0] * this->data[0][1]; 
                    break;
                default:
                    break;
            }
            break;

        case 4:
            matNum = row * 4 + col;
            switch (matNum) {
                case 0:
                    c = this->data[1][1] * (this->data[2][2] * this->data[3][3] - this->data[2][3] * this->data[3][2]) -
                        this->data[1][2] * (this->data[2][1] * this->data[3][3] - this->data[2][3] * this->data[3][1]) +
                        this->data[1][3] * (this->data[2][1] * this->data[3][2] - this->data[2][2] * this->data[3][1]);
                    break;
                case 1:
                    c = -this->data[1][0] * (this->data[2][2] * this->data[3][3] - this->data[2][3] * this->data[3][2]) +
                        this->data[1][2] * (this->data[2][0] * this->data[3][3] - this->data[2][3] * this->data[3][0]) -
                        this->data[1][3] * (this->data[2][0] * this->data[3][2] - this->data[2][2] * this->data[3][0]);
                    break;
                case 2:
                    c = this->data[1][0] * (this->data[2][1] * this->data[3][3] - this->data[2][3] * this->data[3][1]) -
                        this->data[1][1] * (this->data[2][0] * this->data[3][3] - this->data[2][3] * this->data[3][0]) +
                        this->data[1][3] * (this->data[2][0] * this->data[3][1] - this->data[2][1] * this->data[3][0]);
                    break;
                case 3:
                    c = -this->data[1][0] * (this->data[2][1] * this->data[3][2] - this->data[2][2] * this->data[3][1]) +
                        this->data[1][1] * (this->data[2][0] * this->data[3][2] - this->data[2][2] * this->data[3][0]) -
                        this->data[1][2] * (this->data[2][0] * this->data[3][1] - this->data[2][1] * this->data[3][0]);
                    break;
                case 4:
                    c = -this->data[0][1] * (this->data[2][2] * this->data[3][3] - this->data[2][3] * this->data[3][2]) +
                        this->data[0][2] * (this->data[2][1] * this->data[3][3] - this->data[2][3] * this->data[3][1]) -
                        this->data[0][3] * (this->data[2][1] * this->data[3][2] - this->data[2][2] * this->data[3][1]);
                    break;
                case 5:
                    c = this->data[0][0] * (this->data[2][2] * this->data[3][3] - this->data[2][3] * this->data[3][2]) -
                        this->data[0][2] * (this->data[2][0] * this->data[3][3] - this->data[2][3] * this->data[3][0]) +
                        this->data[0][3] * (this->data[2][0] * this->data[3][2] - this->data[2][2] * this->data[3][0]);
                    break;
                case 6:
                    c = -this->data[0][0] * (this->data[2][1] * this->data[3][3] - this->data[2][3] * this->data[3][1]) +
                        this->data[0][1] * (this->data[2][0] * this->data[3][3] - this->data[2][3] * this->data[3][0]) -
                        this->data[0][3] * (this->data[2][0] * this->data[3][1] - this->data[2][1] * this->data[3][0]);
                    break;
                case 7:
                    c = this->data[0][0] * (this->data[2][1] * this->data[3][2] - this->data[2][2] * this->data[3][1]) -
                        this->data[0][1] * (this->data[2][0] * this->data[3][2] - this->data[2][2] * this->data[3][0]) +
                        this->data[0][2] * (this->data[2][0] * this->data[3][1] - this->data[2][1] * this->data[3][0]);
                    break;
                case 8:
                    c = this->data[0][1] * (this->data[1][2] * this->data[3][3] - this->data[1][3] * this->data[3][2]) -
                        this->data[0][2] * (this->data[1][1] * this->data[3][3] - this->data[1][3] * this->data[3][1]) +
                        this->data[0][3] * (this->data[1][1] * this->data[3][2] - this->data[1][2] * this->data[3][1]);
                    break;
                case 9:
                    c = -this->data[0][0] * (this->data[1][2] * this->data[3][3] - this->data[1][3] * this->data[3][2]) +
                        this->data[0][2] * (this->data[1][0] * this->data[3][3] - this->data[1][3] * this->data[3][0]) -
                        this->data[0][3] * (this->data[1][0] * this->data[3][2] - this->data[1][2] * this->data[3][0]);
                    break;
                case 10:
                    c = this->data[0][0] * (this->data[1][1] * this->data[3][3] - this->data[1][3] * this->data[3][1]) -
                        this->data[0][1] * (this->data[1][0] * this->data[3][3] - this->data[1][3] * this->data[3][0]) +
                        this->data[0][3] * (this->data[1][0] * this->data[3][1] - this->data[1][1] * this->data[3][0]);
                    break;
                case 11:
                    c = -this->data[0][0] * (this->data[1][1] * this->data[3][2] - this->data[1][2] * this->data[3][1]) +
                        this->data[0][1] * (this->data[1][0] * this->data[3][2] - this->data[1][2] * this->data[3][0]) -
                        this->data[0][2] * (this->data[1][0] * this->data[3][1] - this->data[1][1] * this->data[3][0]);
                    break;
                case 12:
                    c = -this->data[0][1] * (this->data[1][2] * this->data[2][3] - this->data[1][3] * this->data[2][2]) +
                        this->data[0][2] * (this->data[1][1] * this->data[2][3] - this->data[1][3] * this->data[2][1]) -
                        this->data[0][3] * (this->data[1][1] * this->data[2][2] - this->data[1][2] * this->data[2][1]);
                    break;
                case 13:
                    c = this->data[0][0] * (this->data[1][2] * this->data[2][3] - this->data[1][3] * this->data[2][2]) -
                        this->data[0][2] * (this->data[1][0] * this->data[2][3] - this->data[1][3] * this->data[2][0]) +
                        this->data[0][3] * (this->data[1][0] * this->data[2][2] - this->data[1][2] * this->data[2][0]);
                    break;
                case 14:
                    c = -this->data[0][0] * (this->data[1][1] * this->data[2][3] - this->data[1][3] * this->data[2][1]) +
                        this->data[0][1] * (this->data[1][0] * this->data[2][3] - this->data[1][3] * this->data[2][0]) -
                        this->data[0][3] * (this->data[1][0] * this->data[2][1] - this->data[1][1] * this->data[2][0]);
                    break;
                case 15:
                    c = this->data[0][0] * (this->data[1][1] * this->data[2][2] - this->data[1][2] * this->data[2][1]) -
                        this->data[0][1] * (this->data[1][0] * this->data[2][2] - this->data[1][2] * this->data[2][0]) +
                        this->data[0][2] * (this->data[1][0] * this->data[2][1] - this->data[1][1] * this->data[2][0]);
                    break;
                default:
                    break;
            }
    }

    return c;
}
float Matrix::det() const{
    float det = 0.0f; 
    if (this->size == 2){
        det = this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
    }
    else{
        for (int j = 0; j < this->size; ++j){
            det += this->data[0][j] * cofactor(0, j);
        }
    }
    return det;
}

}
//namespace rt

