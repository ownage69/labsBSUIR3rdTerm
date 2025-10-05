#include "A.h"

A::A(int a_val) : a(a_val) {}

int A::getA() const {
    return a;
}

void A::setA(int a_val) {
    a = a_val;
}