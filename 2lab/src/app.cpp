#include "app.h"
#include "safeinput.h"
#include <iostream>
#include <locale>
#include <string>
#include <format>

App::App() : hasArray(false) {}

void App::printMenu() {
    std::cout << "\n===����===\n";
    std::cout << "1. ������ ������ (��� ������������)\n";
    std::cout << "2. �������� ���������� ������\n";
    std::cout << "3. ���������� �������\n";
    std::cout << "4. �����\n";
}

void App::inputArray() {
    int n = safePositiveInputInt("������� ������ �������: ");
    Array tmp(n);
    for (int i = 0; i < n; ++i) {
        tmp[i] = safeInputInt(std::format("������� ������� ") + std::to_string(i + 1) + ": ");
    }
    arr = tmp;
    hasArray = true;
    std::cout << "������ �����.\n";
}

void App::showArray() {
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