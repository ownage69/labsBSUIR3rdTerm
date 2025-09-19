#include "app.h"
#include "safeinput.h"
#include <iostream>
#include <locale>
#include <string>
#include <format>

App::App() {}

void App::printMenu() const {
    std::cout << "\n===МЕНЮ===\n";
    std::cout << "1. Ввести массив (или перезаписать)\n";
    std::cout << "2. Показать массив\n";
    std::cout << "3. Объединить массивы\n";
    std::cout << "4. Выход\n";
}

void App::inputArray() {
    int n = safePositiveInputInt("Введите размер массива: ");
    Array tmp(n);
    for (int i = 0; i < n; ++i) {
        tmp[i] = safeInputInt(std::format("Введите элемент {}: ", i + 1));
    }
    arr = tmp;
    hasArray = true;
    std::cout << "Массив введён.\n";
}

void App::showArray() const {
    if (!hasArray) {
        std::cout << "Массив пуст. Сначала введите массив.\n";
    }
    else {
        std::cout << "Текущий массив: " << arr << "\n";
    }
}

void App::duplicateArray() {
    if (!hasArray) {
        std::cout << "Массив пуст. Сначала введите массив.\n";
    }
    else {
        arr = !arr;
        hasArray = (arr.getSize() > 0);
        std::cout << "Объединение массивов: " << arr << "\n";
    }
}

void App::run() {
    setlocale(LC_ALL, "Russian");
    bool exit = false;

    while (!exit) {
        printMenu();
        int choice = safeInputInt("Выберите пункт: ");

        switch (choice) {
        case 1:
            inputArray();
            break;
        case 2:
            showArray();
            break;
        case 3:
            duplicateArray();
            break;
        case 4:
            exit = true;
            break;
        default:
            std::cout << "Неверный пункт меню.\n";
            break;
        }
    }

    std::cout << "Выход из программы.\n";
}