#include "menu.h"
#include "CarFile.h"
#include <iostream>
#include <string>
#include <limits>

void runMenu() {
    const std::string filename = "cars.bin";
    CarFile cf(filename);

    int choice;
    do {
        std::cout << "1. Add car\n";
        std::cout << "2. Show all cars\n";
        std::cout << "3. Count cars by year\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            Car car;
            std::cout << "Enter number: ";
            std::cin >> car.number;
            std::cout << "Enter year: ";
            std::cin >> car.year;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Enter color: ";
            std::getline(std::cin, car.color);
            cf << car;
            std::cout << "Car added.\n";
            break;
        }
        case 2: {
            std::cout << "All cars:\n";
            cf.showAll();
            break;
        }
        case 3: {
            int y;
            std::cout << "Enter year: ";
            std::cin >> y;
            std::cout << "Count: " << cf.countByYear(y) << std::endl;
            break;
        }
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}