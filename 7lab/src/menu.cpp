#include "menu.h"
#include "safeinput.h"
#include <iostream>

void Menu::printMenu() const {
    std::cout << "\nOptions:\n"
        << "1. Insert a new vehicle into the file\n"
        << "2. Display all vehicles from the file\n"
        << "3. Calculate vehicles by specific production year\n"
        << "4. Erase file data\n"
        << "5. Quit\n";
}

void Menu::insertCar() {
    Car newCar;
    newCar.input();
    file.writeObject(newCar);
}

void Menu::displayCars() {
    file.show();
}

void Menu::countByYear() {
    int findYear = safeInputInt("Specify the year to search: ");
    while (findYear < 1990 || findYear > 2025) {
        std::cout << "Year must be between 1990 and 2025. Try again.\n";
        findYear = safeInputInt("");
    }
    std::cout << "Number of vehicles produced in that year: "
        << file.findCarsByYear(findYear) << "\n";
}

void Menu::clearFile() {
    file.close();
    if (file.open(true))
        std::cout << "File cleared successfully.\n";
    else
        std::cout << "Error: Failed to clear file.\n";
}

void Menu::chooseOperation() {
    if (!file.open()) {
        std::cout << "Error: Failed to open file.\n";
        return;
    }

    while (true) {
        printMenu();
        int choice = safeInputInt("Select an option: ");

        switch (choice) {
        case 1: insertCar(); break;
        case 2: displayCars(); break;
        case 3: countByYear(); break;
        case 4: clearFile(); break;
        case 5: return;
        default:
            std::cout << "Invalid option. Please choose between 1 and 5.\n";
        }
    }
}

void Menu::start() {
    chooseOperation();
}
