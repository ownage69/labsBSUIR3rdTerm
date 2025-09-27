#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(int a_val, int b_val) : EquationCoefficients(a_val), b(b_val) {}

int QuadraticEquation::getB() const {
    return b;
}

void QuadraticEquation::setB(int b_val) {
    b = b_val;
}