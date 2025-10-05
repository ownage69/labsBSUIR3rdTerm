#pragma once

class A {
    int a;

public:
    explicit A(int a_val = 0);
    int getA() const;
    void setA(int a_val);
};