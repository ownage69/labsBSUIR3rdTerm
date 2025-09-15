#include "App.h"
#include "Array.h"
#include <iostream>
#include <limits>
#include <locale.h>

using namespace std;

void App::run() {
    setlocale(LC_ALL, "Russian");

    MyArray a, b, c;
    int choice = 0;

    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Ввести первый массив\n";
        cout << "2. Ввести второй массив\n";
        cout << "3. Показать массивы\n";
        cout << "4. Объединить массивы (c = a + b)\n";
        cout << "5. Показать результат объединения\n";
        cout << "6. Очистить результат объединения\n";
        cout << "7. Выход\n";
        cout << "Ваш выбор: ";

        if (!(cin >> choice)) {
            cout << "Неверный ввод. Повторите.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            cin >> a;
            break;
        case 2:
            cin >> b;
            break;
        case 3:
            cout << "Первый массив:  " << a << "\n";
            cout << "Второй массив:  " << b << "\n";
            break;
        case 4:
            c = a + b;
            cout << "Объединение выполнено.\n";
            break;
        case 5:
            cout << "Результат (c): " << c << "\n";
            break;
        case 6:
            c = MyArray(); // очищаем результат
            cout << "Результат очищен.\n";
            break;
        case 7:
            cout << "Выход...\n";
            break;
        default:
            cout << "Некорректный выбор. Введите число от 1 до 7.\n";
        }
    } while (choice != 7);
}
