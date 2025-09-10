#include "App.h"
#include "SafeInput.h"
#include <iostream>

using namespace std;

void App::showMenu() const {
    cout << "\n===== МЕНЮ =====\n";
    cout << "1. Создать матрицы\n";
    cout << "2. Ввести элементы матриц\n";
    cout << "3. Вывести матрицы A и B\n";
    cout << "4. Вычесть A - B и показать результат\n";
    cout << "5. Выход\n";
}

void App::createMatrices() {
    int r = safePositiveInputInt("Введите количество строк: ");
    int c = safePositiveInputInt("Введите количество столбцов: ");
    A.create(r, c);
    B.create(r, c);
    C.create(0, 0);
    matricesCreated = true;
    cout << "Матрицы A и B (" << r << "x" << c << ") созданы.\n";
}

void App::inputMatrices() {
    if (!matricesCreated) {
        cout << "Сначала создайте матрицы.\n";
        return;
    }
    cout << "\nМатрица A:\n";
    A.input();
    cout << "\nМатрица B:\n";
    B.input();
}

void App::displayMatrices() const {
    if (!matricesCreated) {
        cout << "Сначала создайте матрицы.\n";
        return;
    }
    cout << "\nМатрица A:\n";
    A.display();
    cout << "\nМатрица B:\n";
    B.display();
}

void App::subtractMatrices() {
    if (!matricesCreated) {
        cout << "Сначала создайте матрицы.\n";
        return;
    }
    A.subtract(B, C);
    cout << "\nРезультат (A - B):\n";
    C.display();
}

void App::run() {
    while (true) {
        showMenu();
        int choice = safeInputInt("Выбор: ");
        switch (choice) {
        case 1: createMatrices(); break;
        case 2: inputMatrices(); break;
        case 3: displayMatrices(); break;
        case 4: subtractMatrices(); break;
        case 5:
            cout << "Выход.\n";
            return;
        default:
            cout << "Некорректный пункт меню.\n";
        }
    }
}