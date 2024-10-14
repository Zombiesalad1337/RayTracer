#pragma once

#include <cmath>

constexpr float EPSILON = 0.00001F;

inline bool floatEquals(float a, float b) {
    return fabs(a - b) < EPSILON;
}
