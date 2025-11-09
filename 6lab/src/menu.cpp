#include "menu.h"
#include "safeInput.h"
#include "EmptyInputException.h"
#include "InvalidCharacterException.h"
#include "OutOfRangeException.h"
#include "InvalidFormatException.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

void inputCoefficients(C& eq) {
    try {
        int a = safeInputInt("Введите коэффициент a: ");
        int b = safeInputInt("Введите коэффициент b: ");
        int c = safeInputInt("Введите коэффициент c: ");
        eq.setA(a);
        eq.setB(b);
        eq.setC(c);
        std::cout << "Коэффициенты обновлены.\n";
    }
    catch (const EmptyInputException& ex) {
        std::cout << "Поймано исключение в вводе коэффициентов: " << ex.what() << std::endl;
    }
    catch (const InvalidCharacterException& ex) {
        std::cout << "Поймано исключение в вводе коэффициентов: " << ex.what() << std::endl;
    }
    catch (const OutOfRangeException& ex) {
        std::cout << "Ошибка диапазона: " << ex.what() << std::endl;
    }
    catch (const InvalidFormatException& ex) {
        std::cout << "Ошибка аргумента: " << ex.what() << std::endl;
    }
}

void printEquation(const C& eq) {
    int a_val = eq.getA();
    int b_val = eq.getB();
    int c_val = eq.getC();
    std::ostringstream equationStr;
    equationStr << a_val << "x^2 " << (b_val >= 0 ? "+" : "-") << " " << std::abs(b_val) << "x " << (c_val >= 0 ? "+" : "-") << " " << std::abs(c_val) << " = 0";
    std::cout << "Полученное уравнение: " << equationStr.str() << std::endl;
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
        try {
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
        catch (const EmptyInputException& ex) {
            std::cout << "Поймано исключение в выборе меню: " << ex.what() << std::endl;
        }
        catch (const InvalidCharacterException& ex) {
            std::cout << "Поймано исключение в выборе меню: " << ex.what() << std::endl;
        }
        catch (const OutOfRangeException& ex) {
            std::cout << "Ошибка диапазона: " << ex.what() << std::endl;
        }
        catch (const InvalidFormatException& ex) {
            std::cout << "Ошибка аргумента: " << ex.what() << std::endl;
        }
    }
}