#pragma once

class EquationCoefficients {
protected:
    int a;

public:
    EquationCoefficients(int a_val = 0);
    int getA() const;
    void setA(int a_val);
};