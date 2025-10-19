#include "menu.h"
#include "safeInput.h"
#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n===== МЕНЮ =====\n";
    cout << "1. Создать массив\n";
    cout << "2. Заполнить массив\n";
    cout << "3. Вывести массив\n";
    cout << "4. Изменить элемент по индексу\n";
    cout << "5. Копировать массив\n";
    cout << "0. Выход\n";
    cout << "================\n";
    cout << "Ваш выбор: ";
}

void createArray(Array<int>& arr) {
    int n = safeNonNegativeInputInt("Введите размер массива: ");
    arr = Array<int>(n);
    cout << "Массив создан.\n";
}

void fillArray(Array<int>& arr) {
    if (arr.getSize() <= 0) {
        cout << "Массив не создан!\n";
        return;
    }
    arr.fillArray();
}

void printArray(Array<int>& arr) {
    if (arr.getSize() <= 0) {
        cout << "Массив не создан!\n";
        return;
    }
    arr.printArray();
}

void changeElement(Array<int>& arr) {
    if (arr.getSize() <= 0) {
        cout << "Массив не создан!\n";
        return;
    }
    int index = safeNonNegativeInputInt("Введите индекс: ");
    int value = safeInputInt("Введите новое значение: ");
    try {
        arr[index] = value;
        arr.printArray();
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
}

void copyArray(Array<int>& arr) {
    if (arr.getSize() <= 0) {
        cout << "Массив не создан!\n";
        return;
    }
    Array<int> temp = arr;
    cout << "Массив скопирован.\n";
    temp.printArray();
}

void handleMenu() {
    Array<int> arr;
    int choice;

    do {
        showMenu();
        choice = safeNonNegativeInputInt("");
        switch (choice) {
        case 1:
            createArray(arr);
            break;
        case 2:
            fillArray(arr);
            break;
        case 3:
            printArray(arr);
            break;
        case 4:
            changeElement(arr);
            break;
        case 5:
            copyArray(arr);
            break;
        case 0:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);
}