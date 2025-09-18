#include "app.h"
#include <iostream>
#include <cctype>
#include <format>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void createArray(Array& arr, const string& name) {
    cout << "Создание массива '" << name << "'.\n";
    int size = safePositiveInputInt("Введите размер массива: ");
    arr = Array(static_cast<size_t>(size)); 
    for (size_t i = 0; i < arr.getSize(); ++i) {
        string prompt = std::format("Введите элемент {} для {}: ", i + 1, name);
        arr[i] = safeInputInt(prompt);
    }
    cout << "Массив '" << name << "' создан.\n";
}

void printArray(const Array& arr, const string& name) {
    if (arr.getSize() == 0) {
        cout << "Массив '" << name << "' пуст.\n";
        return;
    }
    cout << "Массив '" << name << "': ";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        cout << arr[i];
        if (i < arr.getSize() - 1) cout << " ";
    }
    cout << endl;
}

void concatenateArrays(const Array& a, const Array& b) {
    if (a.getSize() == 0 && b.getSize() == 0) {
        cout << "Оба массива пусты. Нет чего объединять.\n";
        return;
    }
    Array result = a + b;
    cout << "Результат объединения массивов A и B: ";
    for (size_t i = 0; i < result.getSize(); ++i) {
        cout << result[i];
        if (i < result.getSize() - 1) cout << " ";
    }
    cout << endl;
}

void showMenu() {
    Array arr1;
    Array arr2;

    while (true) {
        cout << "\n=== Меню ===\n";
        cout << "1. Создать первый массив (A)\n";
        cout << "2. Создать второй массив (B)\n";
        cout << "3. Вывести массив A\n";
        cout << "4. Вывести массив B\n";
        cout << "5. Объединить A и B\n";
        cout << "6. Выход\n";

        string input = readLineTrimmed("Выберите опцию: ");
        if (input.empty()) {
            cout << "Пожалуйста, введите номер опции.\n";
            continue;
        }
        if (input.length() != 1 || !isdigit(static_cast<unsigned char>(input[0])) ||
            input[0] < '1' || input[0] > '6') {
            cout << "Неверный выбор. Попробуйте снова.\n";
            continue;
        }

        char choice = input[0];
        switch (choice) {
        case '1':
            createArray(arr1, "A");
            break;
        case '2':
            createArray(arr2, "B");
            break;
        case '3':
            printArray(arr1, "A");
            break;
        case '4':
            printArray(arr2, "B");
            break;
        case '5':
            concatenateArrays(arr1, arr2);
            break;
        case '6':
            cout << "Выход из программы.\n";
            return;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}