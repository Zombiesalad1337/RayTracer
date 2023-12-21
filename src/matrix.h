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
    bool invertible() const;
    Matrix inverse() const;
    void print() const;
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;
    friend void swap(Matrix& first, Matrix& second) noexcept;


private:
    int size; 
    float** data;
};

} //namespace rt
