#include "app.h"
#include "array.h"
#include "SafeInput.h"
#include <iostream>
#include <locale.h>
#include <string>

static void printMenu() {
    std::cout << "\n===МЕНЮ===\n";
    std::cout << "1. Ввести массив (или перезаписать)\n";
    std::cout << "2. Показать массив\n";
    std::cout << "3. Объединить массивы\n";
    std::cout << "4. Выход\n";
}

void App::run() {
    setlocale(LC_ALL, "Russian");
    Array arr;
    bool hasArray = false;

    while (true) {
        printMenu();
        int choice = safeInputInt("Выберите пункт: ");

        if (choice == 4) {
            break;
        }
        else if (choice == 1) {
            int n = safePositiveInputInt("Введите размер массива (положительное число): ");
            Array tmp(n);
            for (int i = 0; i < n; ++i) {
                tmp[i] = safeInputInt(std::string("Введите элемент ") + std::to_string(i) + ": ");
            }
            arr = tmp;
            hasArray = true;
            std::cout << "Массив введён.\n";
        }
        else if (choice == 2) {
            if (!hasArray) {
                std::cout << "Массив пуст. Сначала введите массив.\n";
            }
            else {
                std::cout << "Текущий массив: " << arr << "\n";
            }
        }
        else if (choice == 3) {
            if (!hasArray) {
                std::cout << "Массив пуст. Сначала введите массив.\n";
            }
            else {
                arr = !arr;
                hasArray = (arr.getSize() > 0);
                std::cout << "Массив объединён с самим собой: " << arr << "\n";
            }
        }
        else {
            std::cout << "Неверный пункт меню.\n";
        }
    }

    std::cout << "Выход из программы.\n";
}
