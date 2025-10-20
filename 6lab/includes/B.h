#pragma once

#include "A.h"

class B : public A {
    int b;

public:
    explicit B(int a_val = 0, int b_val = 0);
    int getB() const;
    void setB(int b_val);
};