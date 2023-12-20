#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "tuple.h"


namespace rt{

class Matrix{
public:
    Matrix(int size);
    Matrix(const std::vector<std::vector<float>>& vec);
    ~Matrix();
    float get(int x, int y);
    void set(int x, int y, float z);
    bool operator==(const Matrix& mat) const;
    Matrix operator*(const Matrix& mat) const;
    Tuple operator*(const Tuple& tup) const;
    Matrix transpose() const;
    float cofactor(int row, int col) const;
    float det() const;


private:
    int size; 
    float** data;
};

} //namespace rt
