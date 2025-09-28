#pragma once

class EquationCoefficients {
    int a;

public:
    explicit EquationCoefficients(int a_val = 0);
    int getA() const;
    void setA(int a_val);
};