#include "menu.h"
#include "safeInput.h"
#include <iostream>
#include <string>

void inputCoefficients(SolvableQuadraticEquation& eq) {
    int a = safeInputInt("������� ����������� a: ");
    int b = safeInputInt("������� ����������� b: ");
    int c = safeInputInt("������� ����������� c: ");
    eq.setA(a);
    eq.setB(b);
    eq.setC(c);
    std::cout << "������������ ���������.\n";
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
    std::cout << "���������� ���������: " << equationStr << std::endl;
}

void solveAndPrint(SolvableQuadraticEquation& eq) {
    eq.solve();
    eq.printRoots();
}

void runMenu(SolvableQuadraticEquation& eq) {
    while (true) {
        std::cout << "\n=====����=====\n";
        std::cout << "1. ������ ������������ (a, b, c)\n";
        std::cout << "2. ������� ���������� ���������� ���������\n";
        std::cout << "3. ������ ���������\n";
        std::cout << "4. �����\n";

        int choice = safeInputInt("�������� �����: ");

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
            std::cout << "����� �� ���������.\n";
            return;
        default:
            std::cout << "�������� �����. ���������� �����.\n";
            break;
        }
    }
}