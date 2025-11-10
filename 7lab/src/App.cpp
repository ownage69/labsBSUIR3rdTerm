#include "App.h"
#include "safeinput.h"
#include <iostream>
#include <format>
#include <stdexcept>
#include <ios>
#include <system_error>

void App::run() {
    bool running = true;
    while (running) {
        showMenu();
        int choice = safeInputInt("Enter choice: ");
        if (choice == 4) {
            std::cout << "Exiting...\n";
            running = false;
            continue;
        }
        try {
            handleChoice(choice);
        }
        catch (const std::invalid_argument& e) {
            std::cout << std::format("Invalid argument: {}\n", e.what());
        }
        catch (const std::out_of_range& e) {
            std::cout << std::format("Out of range: {}\n", e.what());
        }
        catch (const std::length_error& e) {
            std::cout << std::format("Length error: {}\n", e.what());
        }
        catch (const std::system_error& e) {
            std::cout << std::format("System error: {}\n", e.what());
        }
        catch (const std::ios_base::failure& e) {
            std::cout << std::format("IO error: {}\n", e.what());
        }
    }
}

void App::showMenu() const {
    std::cout << "\n=== Menu ===\n"
        << "1. Add car\n"
        << "2. Show all cars\n"
        << "3. Count cars by year\n"
        << "4. Exit\n";
}

void App::handleChoice(int choice) {
    if (!carFile_) {
        carFile_ = std::make_unique<CarFile>(filename_);
    }
    switch (choice) {
    case 1: addCar(); break;
    case 2: showAllCars(); break;
    case 3: countCarsByYear(); break;
    default: throw std::out_of_range("Invalid menu option");
    }
}

void App::addCar() {
    Car car;
    while (true) {
        car.number = safeInputInt("Enter number: ");
        if (car.number >= 1000 && car.number <= 9999) break;
        std::cout << "Error: Number must be exactly 4 digits (1000 to 9999).\n";
    }
    car.year = safeInputInt("Enter year: ");
    car.color = readLineTrimmed("Enter color: ");
    *carFile_ << car;
    std::cout << "Car added.\n";
}

void App::showAllCars() const {
    std::cout << "All cars:\n";
    carFile_->showAll();
}

void App::countCarsByYear() const {
    int y = safeInputInt("Enter year: ");
    std::cout << "Count: " << carFile_->countByYear(y) << std::endl;
}