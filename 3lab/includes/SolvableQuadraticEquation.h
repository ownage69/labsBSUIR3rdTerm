#pragma once

#include "QuadraticEquation.h"
#include <cmath> 
#include <iostream> 

class SolvableQuadraticEquation : public QuadraticEquation {
private:
    int c;
    double x1;
    double x2;
    bool hasRealRoots; 

public:
    SolvableQuadraticEquation(int a_val = 0, int b_val = 0, int c_val = 0);
    int getC() const;
    void setC(int c_val);
    void solve();
    void printRoots() const;
};