#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "tuple.h"
#include "vec.h"


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

    //TRANSFORMATIONS

    static Matrix translation(float x, float y, float z);
    static Matrix scaling(float x, float y, float z);
    static Matrix rotationX(float theta);
    static Matrix rotationY(float theta);
    static Matrix rotationZ(float theta);
    static Matrix shearing(float xy, float xz, float yx, float yz, float zx, float zy);
    
    static Matrix viewTransform(const Vec& from, const Vec& to, const Vec& up);

    static Matrix identity();
    


private:
    int size; 
    float** data;
};

} //namespace rt
