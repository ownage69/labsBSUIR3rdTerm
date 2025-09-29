#include "menu.h"
#include "safeinput.h"
#include "dog.h"
#include "cat.h"
#include "human.h"
#include <iostream>

void resize(Mammal**& mammals, int& capacity, int numMammals) {
    int newCapacity = capacity * 2 + 1;
    Mammal** newMammals = new Mammal * [newCapacity];
    for (int i = 0; i < numMammals; ++i) {
        newMammals[i] = mammals[i];
    }
    delete[] mammals;
    mammals = newMammals;
    capacity = newCapacity;
}

void createDog(Mammal**& mammals, int& capacity, int& numMammals) {
    if (numMammals == capacity) {
        resize(mammals, capacity, numMammals);
    }
    std::string name = getSafeString("Enter dog name: ");
    int age = getSafeInt("Enter dog age: ");
    std::string breed = getSafeString("Enter dog breed: ");
    mammals[numMammals++] = new Dog(name, age, breed);
    std::cout << "Dog created.\n";
}

void createCat(Mammal**& mammals, int& capacity, int& numMammals) {
    if (numMammals == capacity) {
        resize(mammals, capacity, numMammals);
    }
    std::string name = getSafeString("Enter cat name: ");
    int age = getSafeInt("Enter cat age: ");
    std::string color = getSafeString("Enter cat color: ");
    mammals[numMammals++] = new Cat(name, age, color);
    std::cout << "Cat created.\n";
}

void createHuman(Mammal**& mammals, int& capacity, int& numMammals) {
    if (numMammals == capacity) {
        resize(mammals, capacity, numMammals);
    }
    std::string name = getSafeString("Enter human name: ");
    int age = getSafeInt("Enter human age: ");
    std::string profession = getSafeString("Enter human profession: ");
    mammals[numMammals++] = new Human(name, age, profession);
    std::cout << "Human created.\n";
}

void describeAll(Mammal** mammals, int numMammals) {
    if (numMammals == 0) {
        std::cout << "No objects created yet.\n";
        return;
    }
    std::cout << "Describing all objects:\n";
    for (int i = 0; i < numMammals; ++i) {
        std::cout << "[" << (i + 1) << "]";
        mammals[i]->describe();
    }
}

void deleteByIndex(Mammal**& mammals, int& numMammals) {
    if (numMammals == 0) {
        std::cout << "No objects to delete.\n";
        return;
    }
    int index = getSafeInt("Enter index to delete (1-" + std::to_string(numMammals) + "): ");
    if (index < 1 || index > numMammals) {
        std::cout << "Invalid index.\n";
        return;
    }
    delete mammals[index - 1];
    for (int j = index - 1; j < numMammals - 1; ++j) {
        mammals[j] = mammals[j + 1];
    }
    --numMammals;
    std::cout << "Object deleted.\n";
}

void deleteAll(Mammal**& mammals, int& numMammals) {
    for (int i = 0; i < numMammals; ++i) {
        delete mammals[i];
    }
    delete[] mammals;
    mammals = nullptr;
    numMammals = 0;
}

void runMenu() {
    Mammal** mammals = nullptr;
    int capacity = 0;
    int numMammals = 0;
    int choice = 0;

    while (choice != 6) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Create Dog\n";
        std::cout << "2. Create Cat\n";
        std::cout << "3. Create Human\n";
        std::cout << "4. Describe all objects\n";
        std::cout << "5. Delete object by index\n";
        std::cout << "6. Exit\n";
        choice = getSafeInt("Enter your choice: ");

        switch (choice) {
        case 1:
            createDog(mammals, capacity, numMammals);
            break;
        case 2:
            createCat(mammals, capacity, numMammals);
            break;
        case 3:
            createHuman(mammals, capacity, numMammals);
            break;
        case 4:
            describeAll(mammals, numMammals);
            break;
        case 5:
            deleteByIndex(mammals, numMammals);
            break;
        case 6:
            deleteAll(mammals, numMammals);
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }
}
