#pragma once

#include "B.h"
#include <cmath> 
#include <iostream> 

class C : public B {
private:
    int c;
    double* roots = nullptr; 
    int numRoots = 0;  

public:
    explicit C(int a_val = 0, int b_val = 0, int c_val = 0);
    C(const C& other); 
    C& operator=(const C& other);
    ~C(); 

    int getC() const;
    void setC(int c_val);
    void solve();
    void printRoots() const;
};