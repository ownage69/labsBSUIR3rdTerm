#include "C.h"

C::C(int a_val, int b_val, int c_val)
    : B(a_val, b_val), c(c_val) {
}

C::C(const C& other)
    : B(other), c(other.c), numRoots(other.numRoots) {
    if (numRoots > 0) {
        roots = new double[numRoots];
        for (int i = 0; i < numRoots; ++i) {
            roots[i] = other.roots[i];
        }
    }
    else {
        roots = nullptr;
    }
}

C& C::operator=(const C& other) {
    if (this == &other) return *this;

    B::operator=(other);
    c = other.c;
    numRoots = other.numRoots;

    delete[] roots;
    if (numRoots > 0) {
        roots = new double[numRoots];
        for (int i = 0; i < numRoots; ++i) {
            roots[i] = other.roots[i];
        }
    }
    else {
        roots = nullptr;
    }

    return *this;
}

C::~C() {
    delete[] roots;
}

int C::getC() const {
    return c;
}

void C::setC(int c_val) {
    c = c_val;
}

void C::solve() {
    if (getA() == 0) {
        delete[] roots;
        roots = nullptr;
        numRoots = 0;
        return;
    }

    auto da = static_cast<double>(getA());
    auto db = static_cast<double>(getB());
    auto dc = static_cast<double>(c);

    double discriminant = db * db - 4 * da * dc;

    delete[] roots;
    roots = nullptr;
    numRoots = 0;

    if (discriminant > 0.0) {
        numRoots = 2;
        roots = new double[2];
        double sqrtDisc = std::sqrt(discriminant);
        roots[0] = (-db - sqrtDisc) / (2 * da);
        roots[1] = (-db + sqrtDisc) / (2 * da);
        if (roots[0] > roots[1]) {
            std::swap(roots[0], roots[1]);
        }
    }
    else if (discriminant == 0.0) {
        numRoots = 2; 
        roots = new double[2];
        double root = -db / (2 * da);
        roots[0] = root;
        roots[1] = root;
    }
    else {
        numRoots = 0;
    }
}

void C::printRoots() const {
    if (getA() == 0) {
        std::cout << "Ошибка: коэффициент a не может быть нулевым (не квадратное уравнение)." << std::endl;
        return;
    }

    if (numRoots > 0) {
        std::cout << "Первый корень x1: " << roots[0] << std::endl;
        if (numRoots == 2) {
            std::cout << "Второй корень x2: " << roots[1] << std::endl;
        }
    }
    else {
        std::cout << "Дискриминант отрицательный: нет корней." << std::endl;
    }
}