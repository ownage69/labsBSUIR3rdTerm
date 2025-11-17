#include "Car.h"
#include "safeinput.h" 
#include <iostream>

void Car::input() {
    regNumber = safeInputString("Enter vehicle registration number (e.g., 5678 BC-2): ");

    while (true) {
        yearOfRelease = safeInputInt("Enter the vehicle's production year (1888–2025): ");
        if (yearOfRelease >= 1888 && yearOfRelease <= 2025) break;
        std::cout << "Year must be between 1888 and 2025. Try again.\n";
    }

    bodyColor = safeInputString("Enter the body color (e.g., silver, blue, green): ");
}
