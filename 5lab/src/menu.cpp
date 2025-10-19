#include "menu.h"
#include "safeInput.h"
#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n===== ���� =====\n";
    cout << "1. ������� ������\n";
    cout << "2. ��������� ������\n";
    cout << "3. ������� ������\n";
    cout << "4. �������� ������� �� �������\n";
    cout << "5. ���������� ������\n";
    cout << "0. �����\n";
    cout << "================\n";
    cout << "��� �����: ";
}

void createArray(Array<int>& arr) {
    int n = safeNonNegativeInputInt("������� ������ �������: ");
    arr = Array<int>(n);
    cout << "������ ������.\n";
}

void fillArray(Array<int>& arr) {
    if (arr.getSize() <= 0) {
        cout << "������ �� ������!\n";
        return;
    }
    arr.fillArray();
}

void printArray(Array<int>& arr) {
    if (arr.getSize() <= 0) {
        cout << "������ �� ������!\n";
        return;
    }
    arr.printArray();
}

void changeElement(Array<int>& arr) {
    if (arr.getSize() <= 0) {
        cout << "������ �� ������!\n";
        return;
    }
    int index = safeNonNegativeInputInt("������� ������: ");
    int value = safeInputInt("������� ����� ��������: ");
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
        cout << "������ �� ������!\n";
        return;
    }
    Array<int> temp = arr;
    cout << "������ ����������.\n";
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
            cout << "����� �� ���������...\n";
            break;
        default:
            cout << "�������� �����!\n";
        }
    } while (choice != 0);
}