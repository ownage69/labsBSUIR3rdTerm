#include "app.h"
#include "array.h"
#include "SafeInput.h"
#include <iostream>
#include <locale.h>
#include <string>

static void printMenu() {
    std::cout << "\n===����===\n";
    std::cout << "1. ������ ������ (��� ������������)\n";
    std::cout << "2. �������� ������\n";
    std::cout << "3. ���������� �������\n";
    std::cout << "4. �����\n";
}

void App::run() {
    setlocale(LC_ALL, "Russian");
    Array arr;
    bool hasArray = false;

    while (true) {
        printMenu();
        int choice = safeInputInt("�������� �����: ");

        if (choice == 4) {
            break;
        }
        else if (choice == 1) {
            int n = safePositiveInputInt("������� ������ ������� (������������� �����): ");
            Array tmp(n);
            for (int i = 0; i < n; ++i) {
                tmp[i] = safeInputInt(std::string("������� ������� ") + std::to_string(i) + ": ");
            }
            arr = tmp;
            hasArray = true;
            std::cout << "������ �����.\n";
        }
        else if (choice == 2) {
            if (!hasArray) {
                std::cout << "������ ����. ������� ������� ������.\n";
            }
            else {
                std::cout << "������� ������: " << arr << "\n";
            }
        }
        else if (choice == 3) {
            if (!hasArray) {
                std::cout << "������ ����. ������� ������� ������.\n";
            }
            else {
                arr = !arr;
                hasArray = (arr.getSize() > 0);
                std::cout << "������ �������� � ����� �����: " << arr << "\n";
            }
        }
        else {
            std::cout << "�������� ����� ����.\n";
        }
    }

    std::cout << "����� �� ���������.\n";
}
