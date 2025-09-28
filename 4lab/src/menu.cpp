#include "menu.h"
#include "Human.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <vector>
#include <limits>
// Простейшее меню с динамическим созданием объектов-наследников Mammal
void clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
}
void runMenu() {
	std::vector<Mammal*> items; // динамически создаваемые объекты
	int choice = 0;
	do {
		std::cout << "===== МЕНЮ =====";
			std::cout << "1 - Создать человек";
			std::cout << "2 - Создать собаку";
			std::cout << "3 - Создать кота";
			std::cout << "4 - Показать все описания";
			std::cout << "5 - Удалить объект по индексу";
			std::cout << "0 - Выход";
			std::cout << "Выбор: ";
		if (!(std::cin >> choice)) {
			clearCin();
			std::cout << "Неверный ввод, повторите.";
				continue;
		}
		if (choice == 1) {
			std::string name, prof;
			std::cout << "Имя человека: "; std::cin >> name;
			std::cout << "Профессия: "; std::cin >> prof;
			items.push_back(new Human(name, prof));
			std::cout << "Человек создан.";
		}
		else if (choice == 2) {
			std::string name, breed; int age;
			std::cout << "Имя собаки: "; std::cin >> name;
			std::cout << "Возраст: "; std::cin >> age;
			std::cout << "Порода: "; std::cin >> breed;
			items.push_back(new Dog(name, age, breed));
			std::cout << "Собака создана";
		}
		else if (choice == 3) {
			std::string name, color; int age;
			std::cout << "Имя кота: "; std::cin >> name;
			std::cout << "Возраст: "; std::cin >> age;
			std::cout << "Окрас: "; std::cin >> color;
			items.push_back(new Cat(name, age, color));
			std::cout << "Кот создан";
		}
		else if (choice == 4) {
			if (items.empty()) {
				std::cout << "Список пуст.";
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
				std::cout << "Список пуст."; continue;
			}
			size_t idx;
			std::cout << "Индекс для удаления: "; std::cin >> idx;
			if (idx >= items.size()) {
				std::cout << "Неверный индекс.";
			}
			else {
				delete items[idx];
				items.erase(items.begin() + idx);
				std::cout << "Объект удалён.";
			}
		}
	} while (choice != 0);
	// Освобождаем память перед выходом
	for (Mammal* p : items) delete p;
	items.clear();
	std::cout << "Завершение программы.";
}

