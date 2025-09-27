#include "EquationCoefficients.h"

EquationCoefficients::EquationCoefficients(int a_val) : a(a_val) {}

int EquationCoefficients::getA() const {
    return a;
}

void EquationCoefficients::setA(int a_val) {
    a = a_val;
}