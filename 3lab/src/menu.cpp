#include "menu.h"
#include "safeInput.h"
#include <iostream>
#include <string>

void inputCoefficients(SolvableQuadraticEquation& eq) {
    int a = safeInputInt("Введите коэффициент a: ");
    int b = safeInputInt("Введите коэффициент b: ");
    int c = safeInputInt("Введите коэффициент c: ");
    eq.setA(a);
    eq.setB(b);
    eq.setC(c);
    std::cout << "Коэффициенты обновлены.\n";
}

void printEquation(const SolvableQuadraticEquation& eq) {
    std::string equationStr = std::to_string(eq.getA()) + "x^2";
    int b_val = eq.getB();
    if (b_val >= 0) {
        equationStr += " + " + std::to_string(b_val) + "x";
    }
    else {
        equationStr += " - " + std::to_string(-b_val) + "x";
    }
    int c_val = eq.getC();
    if (c_val >= 0) {
        equationStr += " + " + std::to_string(c_val);
    }
    else {
        equationStr += " - " + std::to_string(-c_val);
    }
    equationStr += " = 0";
    std::cout << "Полученное уравнение: " << equationStr << std::endl;
}

void solveAndPrint(SolvableQuadraticEquation& eq) {
    eq.solve();
    eq.printRoots();
}

void runMenu(SolvableQuadraticEquation& eq) {
    while (true) {
        std::cout << "\n=====МЕНЮ=====\n";
        std::cout << "1. Ввести коэффициенты (a, b, c)\n";
        std::cout << "2. Вывести полученное квадратное уравнение\n";
        std::cout << "3. Решить уравнение\n";
        std::cout << "4. Выход\n";

        int choice = safeInputInt("Выберите опцию: ");

        switch (choice) {
        case 1:
            inputCoefficients(eq);
            break;
        case 2:
            printEquation(eq);
            break;
        case 3:
            solveAndPrint(eq);
            break;
        case 4:
            std::cout << "Выход из программы.\n";
            return;
        default:
            std::cout << "Неверная опция. Попробуйте снова.\n";
            break;
        }
    }
}