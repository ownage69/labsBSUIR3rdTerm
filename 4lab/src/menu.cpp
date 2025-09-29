#include "menu.h"
#include "safeInput.h"
#include "Human.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <algorithm>
#include <span>

Mammal* createHuman() {
    std::string name = safeInputString("Human name: ");
    int age = safeNonNegativeInputInt("Age: ");
    std::string prof = safeInputString("Profession: ");
    return new Human(name, age, prof);
}

Mammal* createDog() {
    std::string name = safeInputString("Dog name: ");
    int age = safeNonNegativeInputInt("Age: ");
    std::string breed = safeInputString("Breed: ");
    return new Dog(name, age, breed);
}

Mammal* createCat() {
    std::string name = safeInputString("Cat name: ");
    int age = safeNonNegativeInputInt("Age: ");
    std::string color = safeInputString("Color: ");
    return new Cat(name, age, color);
}

void addItem(Mammal**& items, size_t& capacity, size_t& count, Mammal* new_mammal) {
    if (count == capacity) {
        auto new_cap = capacity ? capacity * 2 : 1;
        auto** new_items = new Mammal * [new_cap];
        std::copy(items, items + count, new_items);
        delete[] items;
        items = new_items;
        capacity = new_cap;
    }
    items[count++] = new_mammal;
}

void displayItems(std::span<Mammal*> items) {
    if (items.empty()) {
        std::cout << "List is empty.\n";
        return;
    }
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << (i + 1) << ": ";
        items[i]->describe();
    }
}

void deleteItem(Mammal**& items, size_t& count) {
    if (count == 0) {
        std::cout << "List is empty.\n";
        return;
    }
    int idx_int = safePositiveInputInt("Index to delete: ");
    auto idx = static_cast<size_t>(idx_int - 1);
    if (idx >= count) {
        std::cout << "Invalid index.\n";
        return;
    }
    delete items[idx];
    for (size_t i = idx; i < count - 1; ++i) {
        items[i] = items[i + 1];
    }
    --count;
    std::cout << "Object deleted.\n";
}

void runMenu() {
    Mammal** items = nullptr;
    size_t capacity = 0;
    size_t count = 0;
    int choice = 0;
    do {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1 - Create human\n";
        std::cout << "2 - Create dog\n";
        std::cout << "3 - Create cat\n";
        std::cout << "4 - Show all descriptions\n";
        std::cout << "5 - Delete object by index\n";
        std::cout << "0 - Exit\n";
        choice = safeInputInt("Choice: ");
        switch (choice) {
        case 1:
            addItem(items, capacity, count, createHuman());
            std::cout << "Human created.\n";
            break;
        case 2:
            addItem(items, capacity, count, createDog());
            std::cout << "Dog created.\n";
            break;
        case 3:
            addItem(items, capacity, count, createCat());
            std::cout << "Cat created.\n";
            break;
        case 4:
            displayItems({ items, count });
            break;
        case 5:
            deleteItem(items, count);
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    } while (choice != 0);
    for (size_t i = 0; i < count; ++i) delete items[i];
    delete[] items;
    std::cout << "Program termination.\n";
}