#include "SolvableQuadraticEquation.h"

SolvableQuadraticEquation::SolvableQuadraticEquation(int a_val, int b_val, int c_val)
    : QuadraticEquation(a_val, b_val), c(c_val), x1(0.0), x2(0.0), hasRealRoots(false) {
}

int SolvableQuadraticEquation::getC() const {
    return c;
}

void SolvableQuadraticEquation::setC(int c_val) {
    c = c_val;
}

void SolvableQuadraticEquation::solve() {
    if (a == 0) {
        hasRealRoots = false;
        return;
    }

    double da = static_cast<double>(a);
    double db = static_cast<double>(b);
    double dc = static_cast<double>(c);

    double discriminant = db * db - 4 * da * dc;

    if (discriminant > 0.0) {
        double sqrtDisc = std::sqrt(discriminant);
        x1 = (-db - sqrtDisc) / (2 * da);
        x2 = (-db + sqrtDisc) / (2 * da);
        if (x1 > x2) {
            std::swap(x1, x2);
        }
        hasRealRoots = true;
    }
    else if (discriminant == 0.0) {
        x1 = x2 = -db / (2 * da);
        hasRealRoots = true;
    }
    else {
        hasRealRoots = false;
    }
}

void SolvableQuadraticEquation::printRoots() const {
    if (a == 0) {
        std::cout << "Ошибка: коэффициент a не может быть нулевым (не квадратное уравнение)." << std::endl;
        return;
    }

    if (hasRealRoots) {
        std::cout << "Первый корень x1: " << x1 << std::endl;
        std::cout << "Второй корень x2: " << x2 << std::endl;
    }
    else {
        std::cout << "Дискриминант отрицательный: нет реальных корней." << std::endl;
    }
}