#include "menu.h"
#include "safeInput.h"
#include <iostream>

void Menu::printMenu() const {
    std::cout << "\nOptions:\n";
    std::cout << "1. Insert a new vehicle into the file\n";
    std::cout << "2. Display all vehicles from the file\n";
    std::cout << "3. Calculate vehicles by specific production year\n";
    std::cout << "4. Erase file data\n";
    std::cout << "5. Quit\n";
}
void Menu::chooseOperation() {
    if (!file.open()) {
        std::cout << "Error: Failed to open file.\n";
        return;
    }
    while (true) {
        printMenu();
        int choice = safeInputInt("Select an option: ");
        if (choice < 1 || choice > 5) {
            std::cout << "Invalid option. Please choose between 1 and 5.\n";
            continue;
        }
        switch (choice) {
        case 1: {
            Car newCar;
            newCar.input();
            file.writeObject(newCar);
            break;
        }
        case 2: {
            file.show();
            break;
        }
        case 3: {
            std::cout << "Specify the year to search: ";
            int findYear;
            while (true) {
                findYear = safeInputInt("");
                if (findYear >= 1888 && findYear <= 2025) {
                    break;
                }
                std::cout << "Year must be between 1888 and 2025. Try again.\n";
            }
            std::cout << "Number of vehicles produced in that year: " << file.findCarsByYear(findYear) << std::endl;
            break;
        }
        case 4: {
            file.close();
            if (file.open(true)) {
                std::cout << "File cleared successfully.\n";
            }
            else {
                std::cout << "Error: Failed to clear file.\n";
            }
            break;
        }
        case 5:
            return;
        }
    }
}
void Menu::start() {
    chooseOperation();
}