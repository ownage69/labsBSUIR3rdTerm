#include "menu.h"
#include "Human.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <vector>
#include <limits>
// ���������� ���� � ������������ ��������� ��������-����������� Mammal
void clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
}
void runMenu() {
	std::vector<Mammal*> items; // ����������� ����������� �������
	int choice = 0;
	do {
		std::cout << "===== ���� =====";
			std::cout << "1 - ������� �������";
			std::cout << "2 - ������� ������";
			std::cout << "3 - ������� ����";
			std::cout << "4 - �������� ��� ��������";
			std::cout << "5 - ������� ������ �� �������";
			std::cout << "0 - �����";
			std::cout << "�����: ";
		if (!(std::cin >> choice)) {
			clearCin();
			std::cout << "�������� ����, ���������.";
				continue;
		}
		if (choice == 1) {
			std::string name, prof;
			std::cout << "��� ��������: "; std::cin >> name;
			std::cout << "���������: "; std::cin >> prof;
			items.push_back(new Human(name, prof));
			std::cout << "������� ������.";
		}
		else if (choice == 2) {
			std::string name, breed; int age;
			std::cout << "��� ������: "; std::cin >> name;
			std::cout << "�������: "; std::cin >> age;
			std::cout << "������: "; std::cin >> breed;
			items.push_back(new Dog(name, age, breed));
			std::cout << "������ �������";
		}
		else if (choice == 3) {
			std::string name, color; int age;
			std::cout << "��� ����: "; std::cin >> name;
			std::cout << "�������: "; std::cin >> age;
			std::cout << "�����: "; std::cin >> color;
			items.push_back(new Cat(name, age, color));
			std::cout << "��� ������";
		}
		else if (choice == 4) {
			if (items.empty()) {
				std::cout << "������ ����.";
			}
			else {
				for (size_t i = 0; i < items.size(); ++i) {
					std::cout << i << ": ";
					items[i]->describe();
				}
			}
		}
		else if (choice == 5) {
			if (items.empty()) {
				std::cout << "������ ����."; continue;
			}
			size_t idx;
			std::cout << "������ ��� ��������: "; std::cin >> idx;
			if (idx >= items.size()) {
				std::cout << "�������� ������.";
			}
			else {
				delete items[idx];
				items.erase(items.begin() + idx);
				std::cout << "������ �����.";
			}
		}
	} while (choice != 0);
	// ����������� ������ ����� �������
	for (Mammal* p : items) delete p;
	items.clear();
	std::cout << "���������� ���������.";
}

