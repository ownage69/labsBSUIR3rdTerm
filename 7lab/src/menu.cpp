#include "menu.h"
#include "CarFile.h"
#include "safeinput.h"
#include <iostream>
#include <format>
#include <stdexcept>

void runMenu() {
    const std::string filename = "cars.bin";
    CarFile cf(filename);

    int choice;
    do {
        std::cout << "\n=== Menu ===\n"
            << "1. Add car\n"
            << "2. Show all cars\n"
            << "3. Count cars by year\n"
            << "4. Exit\n";

        choice = safeInputInt("Enter choice: ");

        try {
            switch (choice) {
            case 1: {
                Car car;
                while (true) {
                    car.number = safeInputInt("Enter number: ");
                    if (car.number >= 1000 && car.number <= 9999) break;
                    std::cout << "Error: Number must be exactly 4 digits (1000 to 9999).\n";
                }
                car.year = safeInputInt("Enter year: ");
                car.color = readLineTrimmed("Enter color: ");
                cf << car;
                std::cout << "Car added.\n";
                break;
            }
            case 2:
                std::cout << "All cars:\n";
                cf.showAll();
                break;
            case 3: {
                int y = safeInputInt("Enter year: ");
                std::cout << "Count: " << cf.countByYear(y) << std::endl;
                break;
            }
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                throw std::out_of_range("Invalid menu option");
            }
        }
        catch (const std::exception& e) {
            std::cout << std::format("Error: {}\n", e.what());
        }
    } while (choice != 4);
}