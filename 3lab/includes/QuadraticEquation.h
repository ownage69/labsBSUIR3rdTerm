#pragma once

#include "EquationCoefficients.h"

class QuadraticEquation : public EquationCoefficients {
    int b;

public:
    explicit QuadraticEquation(int a_val = 0, int b_val = 0);
    int getB() const;
    void setB(int b_val);
};
