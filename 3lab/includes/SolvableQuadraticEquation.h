#pragma once

#include "QuadraticEquation.h"
#include <cmath> 
#include <iostream> 

class SolvableQuadraticEquation : public QuadraticEquation {
private:
    int c;
    double* roots; 
    int numRoots;  

public:
    explicit SolvableQuadraticEquation(int a_val = 0, int b_val = 0, int c_val = 0);
    SolvableQuadraticEquation(const SolvableQuadraticEquation& other); 
    SolvableQuadraticEquation& operator=(const SolvableQuadraticEquation& other);
    ~SolvableQuadraticEquation(); 

    int getC() const;
    void setC(int c_val);
    void solve();
    void printRoots() const;
};