#include "B.h"

B::B(int a_val, int b_val) : A(a_val), b(b_val) {}

int B::getB() const {
    return b;
}

void B::setB(int b_val) {
    b = b_val;
}