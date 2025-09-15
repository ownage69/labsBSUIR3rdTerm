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
        cout << "\n===== ���� =====\n";
        cout << "1. ������ ������ ������\n";
        cout << "2. ������ ������ ������\n";
        cout << "3. �������� �������\n";
        cout << "4. ���������� ������� (c = a + b)\n";
        cout << "5. �������� ��������� �����������\n";
        cout << "6. �������� ��������� �����������\n";
        cout << "7. �����\n";
        cout << "��� �����: ";

        if (!(cin >> choice)) {
            cout << "�������� ����. ���������.\n";
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
            cout << "������ ������:  " << a << "\n";
            cout << "������ ������:  " << b << "\n";
            break;
        case 4:
            c = a + b;
            cout << "����������� ���������.\n";
            break;
        case 5:
            cout << "��������� (c): " << c << "\n";
            break;
        case 6:
            c = MyArray(); // ������� ���������
            cout << "��������� ������.\n";
            break;
        case 7:
            cout << "�����...\n";
            break;
        default:
            cout << "������������ �����. ������� ����� �� 1 �� 7.\n";
        }
    } while (choice != 7);
}
