#include "menu.h"
#include "safeInput.h"
#include <iostream>
#include <string>
#include <format>

void inputCoefficients(C& eq) {
    int a = safeInputInt("Введите коэффициент a: ");
    int b = safeInputInt("Введите коэффициент b: ");
    int c = safeInputInt("Введите коэффициент c: ");
    eq.setA(a);
    eq.setB(b);
    eq.setC(c);
    std::cout << "Коэффициенты обновлены.\n";
}

void printEquation(const C& eq) {
    int a_val = eq.getA();
    int b_val = eq.getB();
    int c_val = eq.getC();

    std::string equationStr = std::format(
        "{}x^2 {} {}x {} {} = 0",
        a_val,
        (b_val >= 0 ? "+" : "-"),
        std::abs(b_val),
        (c_val >= 0 ? "+" : "-"),
        std::abs(c_val)
    );

    std::cout << "Полученное уравнение: " << equationStr << std::endl;
}

void solveAndPrint(C& eq) {
    eq.solve();
    eq.printRoots();
}

void runMenu(C& eq) {
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