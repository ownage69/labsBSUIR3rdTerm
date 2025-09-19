#include "app.h"
#include "safeinput.h"
#include <iostream>
#include <locale>
#include <string>
#include <format>

App::App() {}

void App::printMenu() const {
    std::cout << "\n===����===\n";
    std::cout << "1. ������ ������ (��� ������������)\n";
    std::cout << "2. �������� ������\n";
    std::cout << "3. ���������� �������\n";
    std::cout << "4. �����\n";
}

void App::inputArray() {
    int n = safePositiveInputInt("������� ������ �������: ");
    Array tmp(n);
    for (int i = 0; i < n; ++i) {
        tmp[i] = safeInputInt(std::format("������� ������� {}: ", i + 1));
    }
    arr = tmp;
    hasArray = true;
    std::cout << "������ �����.\n";
}

void App::showArray() const {
    if (!hasArray) {
        std::cout << "������ ����. ������� ������� ������.\n";
    }
    else {
        std::cout << "������� ������: " << arr << "\n";
    }
}

void App::duplicateArray() {
    if (!hasArray) {
        std::cout << "������ ����. ������� ������� ������.\n";
    }
    else {
        arr = !arr;
        hasArray = (arr.getSize() > 0);
        std::cout << "����������� ��������: " << arr << "\n";
    }
}

void App::run() {
    setlocale(LC_ALL, "Russian");
    bool exit = false;

    while (!exit) {
        printMenu();
        int choice = safeInputInt("�������� �����: ");

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
            std::cout << "�������� ����� ����.\n";
            break;
        }
    }

    std::cout << "����� �� ���������.\n";
}