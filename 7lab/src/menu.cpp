#include "menu.h"
#include "CarFile.h"
#include "safeinput.h"
#include <iostream>
#include <format>

namespace {

    void add_car(CarFile& cf) {
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
    }

    void show_all(const CarFile& cf) {
        std::cout << "All cars:\n";
        cf.showAll();
    }

    void count_by_year(const CarFile& cf) {
        int y = safeInputInt("Enter year: ");
        std::cout << "Count: " << cf.countByYear(y) << std::endl;
    }

} 

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
            case 1: add_car(cf); break;
            case 2: show_all(cf); break;
            case 3: count_by_year(cf); break;
            case 4: std::cout << "Exiting...\n"; break;
            default: throw std::out_of_range("Invalid menu option");
            }
        }
        catch (const std::invalid_argument& e) {
            std::cout << std::format("Invalid argument: {}\n", e.what());
        }
        catch (const std::out_of_range& e) {
            std::cout << std::format("Out of range: {}\n", e.what());
        }
        catch (const std::system_error& e) {
            std::cout << std::format("System error: {}\n", e.what());
        }
        catch (const std::ios_base::failure& e) {
            std::cout << std::format("IO error: {}\n", e.what());
        }
        catch (const std::exception& e) {
            std::cout << std::format("Error: {}\n", e.what());
        }
    } while (choice != 4);
}